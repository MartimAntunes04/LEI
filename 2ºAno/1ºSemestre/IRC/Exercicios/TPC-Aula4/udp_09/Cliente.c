#include <winsock.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#pragma comment(lib, "Ws2_32.lib")

#define SERV_HOST_ADDR "127.0.0.1"
#define SERV_UDP_PORT  6000
#define BUFFERSIZE     4096
#define TIMEOUT		   10000 //ms

void Abort(char* msg);

int main(int argc, char* argv[])
{
	SOCKET sockfd;
	int msg_len, iResult;
	struct sockaddr_in serv_addr, local_addr, check, rec_serv_addr;
	WSADATA wsaData;
	int nbytes;
	char buffer[BUFFERSIZE];
	int localPort, check_len = sizeof(check);

	/*========================= TESTA A SINTAXE =========================*/

	if (argc != 7) {
		fprintf(stderr, "Sintaxe: %s -msg frase_a_enviar -ip ipdestino -port localport\n", argv[0]);
		exit(EXIT_FAILURE);
	}


	/*============================= TRATA OS ARGUMENTOS =========================*/

	int ip_idx, port_idx, msg_idx;
	for (int i = 0; i < 7; i++) {

		if (strcmp(argv[i], "-ip") == 0) {
			ip_idx = i + 1;
		}
		if (strcmp(argv[i], "-port") == 0) {
			port_idx = i + 1;
		}
		if (strcmp(argv[i], "-msg") == 0) {
			msg_idx = i + 1;
		}
	}


	/*=============== INICIA OS WINSOCKS ==============*/

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		getchar();
		exit(1);
	}
	/*=============== CRIA SOCKET PARA ENVIO/RECEPCAO DE DATAGRAMAS ==============*/
	sockfd = socket(PF_INET, SOCK_DGRAM, 0);
	if (sockfd == INVALID_SOCKET)
		Abort("Impossibilidade de criar socket");



	/*================Atribui um timeout ao socket =====================*/

	struct timeval timeout = { TIMEOUT,0 };
	if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout)) == -1)
		Abort("Impossibilidade de estabelecer timeout!");



	/*================= PREENCHE ENDERECO DO SERVIDOR ====================*/

	memset((char*)&serv_addr, 0, sizeof(serv_addr)); /*Coloca a zero todos os bytes*/
	serv_addr.sin_family = AF_INET; /*Address Family: Internet*/
	serv_addr.sin_addr.s_addr = inet_addr(argv[ip_idx]); /* Converte IP para formato "dotted decimal" de 32 bits */
	serv_addr.sin_port = htons(atoi(argv[port_idx])); /* Converte Porta para Network Short */

	/*====================== ENVIA MENSAGEM AO SERVIDOR ==================*/
	msg_len = strlen(argv[msg_idx]);

	if (sendto(sockfd, argv[msg_idx], msg_len, 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR)
		Abort("O subsistema de comunicacao nao conseguiu aceitar o datagrama");

	printf("<CLI1>Mensagem enviada ... a entrega nao e' confirmada.\n");

	/*========================= Obtem porto socket ===========================*/

	int localAddrLen = sizeof(local_addr);
	if (getsockname(sockfd, (struct sockaddr*)&local_addr, &localAddrLen) == SOCKET_ERROR) {
		Abort("Erro ao obter o endereço do socket local");
	}
	localPort = ntohs(local_addr.sin_port);

	printf("<CLI1>Porto local atribuido automaticamente: %d\n", localPort);

	/*========================= RECEBER MENSAGEM ===========================*/

	
	nbytes = recvfrom(sockfd, (char*)&buffer, sizeof(buffer), 0, (struct sockaddr*)&check, &check_len);

	if (nbytes == SOCKET_ERROR)
		if (WSAGetLastError() == WSAETIMEDOUT) // Se o erro for causado pelo timeout
			Abort("Timeout");
		else
			Abort("Erro inesperado na leitura");

	buffer[nbytes] = '\0'; /*Termina a cadeia de caracteres recebidos com '\0'*/

	printf("\n<CLI>Mensagem recebida {%s}\n", buffer);
	if (check.sin_port == serv_addr.sin_port && strcmp(inet_ntoa(check.sin_addr), inet_ntoa(serv_addr.sin_addr)) == 0) {
		printf("\nMensagem {%s} recebida do servidor\n",buffer);
	}
	else {
		printf("\nMensagem {%s} recebida de um impostor com IP: {%s} e Port: {%s}.\n",buffer,inet_ntoa(check.sin_addr),ntohs(check.sin_port));
	}
	/*========================= FECHA O SOCKET ===========================*/

	closesocket(sockfd);

	printf("\n");
	exit(EXIT_SUCCESS);
}

/*________________________________ Abort________________________________________
Mostra uma mensagem de erro e o código associado ao ultimo erro com Winsocks.
Termina a aplicacao com "exit status" a 1 (constante EXIT_FAILURE)
________________________________________________________________________________*/

void Abort(char* msg)
{
	fprintf(stderr, "<CLI1>Erro fatal: <%s> (%d)\n", msg, WSAGetLastError());
	exit(EXIT_FAILURE);
}