#include <stdio.h>
#include <winsock.h>

#pragma comment(lib, "Ws2_32.lib")

#define REPLY_HOST_ADDR "127.0.0.1"
#define SERV_UDP_PORT 5001
#define MY_UDP_PORT 6000
#define BUFFERSIZE     4096

void Abort(char* msg);

/*________________________________ main ________________________________________
*/

int main(int argc, char* argv[])
{
	SOCKET sockfd;
	int iResult, nbytes, msg_len, length_addr, length_addr2, nbytes2;
	struct sockaddr_in serv_addr, cli_addr, c_addr, serv_addr2;
	char buffer[BUFFERSIZE], msg[BUFFERSIZE];
	WSADATA wsaData;

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		getchar();
		exit(1);
	}

	/*============ CRIA O SOCKET PARA RECEPCAO/ENVIO DE DATAGRAMAS UDP ============*/

	if ((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
		Abort("Impossibilidade de abrir socket");

	/*=============== ASSOCIA O SOCKET AO  ENDERECO DE ESCUTA ===============*/

	memset((char*)&c_addr, 0, sizeof(c_addr));
	c_addr.sin_family = AF_INET; /*Address Family: Internet*/
	c_addr.sin_addr.s_addr = htonl(INADDR_ANY);  /*Host TO Network Long*/
	c_addr.sin_port = htons(MY_UDP_PORT);  /*Host TO Network Short*/

	/*=============== ASSOCIA O SOCKET AO  Servidor ===============*/

	memset((char*)&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET; /*Address Family: Internet*/
	serv_addr.sin_addr.s_addr = inet_addr(REPLY_HOST_ADDR);  /*Host TO Network Long*/
	serv_addr.sin_port = htons(SERV_UDP_PORT);  /*Host TO Network Short*/

	if (bind(sockfd, (struct sockaddr*)&c_addr, sizeof(c_addr)) == SOCKET_ERROR)
		Abort("Impossibilidade de registar-se para escuta");

	/*================ PASSA A ATENDER CLIENTES INTERACTIVAMENTE =============*/

	while (1) {

		fprintf(stderr, "<SER1>Sou o REPLY estou esperando datagrama...\n");

		length_addr = sizeof(cli_addr);
		nbytes = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&cli_addr, &length_addr);

		if (nbytes == SOCKET_ERROR)
			Abort("Erro na recepcao de datagrams");
		printf("Mensagem recebida do ChatInput vou enviar para o ChatServer");

		buffer[nbytes] = '\0';


		/*====================== ENVIA MENSAGEM AO CHATSERVER==================*/

		if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR)
			Abort("O subsistema de comunicacao nao conseguiu aceitar o datagrama");

		length_addr2 = sizeof(serv_addr2);
		nbytes2 = recvfrom(sockfd, msg, sizeof(msg), 0, (struct sockaddr*)&serv_addr2, &length_addr2);

		msg[nbytes2] = '\0';

		printf("\n<SER> Mensagem recebida do ChatServer {%s} \n", msg);

	}

}

/*________________________________ Abort________________________________________
  Mostra uma mensagem de erro e o código associado ao ultimo erro com Winsocks.
  Termina a aplicacao com "exit status" a 1 (constante EXIT_FAILURE)
________________________________________________________________________________*/

void Abort(char* msg)
{
	fprintf(stderr, "<SERV>Erro fatal: <%s> (%d)\n", msg, WSAGetLastError());
	exit(EXIT_FAILURE);
}
