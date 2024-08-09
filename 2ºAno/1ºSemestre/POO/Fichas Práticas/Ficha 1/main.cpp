#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;
int main_2_a(){

char nome[100];
int idade;
printf("Nome:");
scanf("%s",nome);
printf("Idade: ");
scanf("%d",&idade);
}




int main_2_b_c() {

    char nome[30];
    int idade;
    cout << "Nome:";
    cin.getline(nome, 29);

    do {
        cout << "Idade:";
        cin >> idade;
        if (cin.fail()) {
            cout << "*\n";
            idade = -1;
            cin.clear();
            //cin.ignore(): consome e deita fora apenas um caracter
            cin.ignore();
        }
    } while (idade <= 0);
    cout << "Nome:" << nome << ",idade: " << idade;
    return 0;
}



int main_2_d_e() {
        string nome;
        int idade;
        do {
            cout << "Nome:";
            getline(cin, nome);
            if (cin.fail()) {
                cout << "*\n";
                idade = -1;
                cin.clear();
                //cin.ignore(): consome e deita fora apenas um caracter
                cin.ignore();
            }
        } while (idade <= 0);

        cout << "Nome" << nome << ",idade: " << idade;
        cout << "Nome tem" << nome.length() << "letras";
        for (int i = 0; i < nome.length(); ++i) {
            cout << nome[i] << '\n';
            cout << "--\n";
            for (char c: nome)
                cout << c << '\n';
        }


        return 0;
    }


int main_3(){
using namespace std;

    string nomecompleto;
    string nome;
    cout << "Nome completo: ";
    getline(cin,nomecompleto);
    istringstream iss(nomecompleto);

    while(iss>>nome) {

        cout <<nome;
        if (nome == "Fernado") {
            cout << "\nConheco esse nome";
        }
        cout << endl;
    }
    return 0;
}

int main_4() {
    using namespace std;
    string palavra;

    while (true) {
        cout << "Digite uma palavra (ou 'fim' para sair): ";
        cin >> palavra;

        if (palavra == "fim") {
            cout << "Programa encerrado." << endl;
            break;
        }
        bool palindromo = true;
        int tamanho = palavra.length();
        for (int i = 0; i < tamanho / 2; i++) {
            if (palavra[i] != palavra[tamanho - 1 - i]) {
                palindromo = false;
                break;
            }
        }
        cout << "Palavra ao contrario:";
        for (int i = tamanho - 1; i >= 0; i--) {
            cout << palavra[i];
        }
        if (palindromo) {
            cout << "-palindromo";
        }
        cout << endl;
        // Aguardar pressionar Enter
        cout << "Carregue em Enter para prosseguir...";
        cin.ignore(); // Limpa o buffer de entrada
        cin.get();    // Espera pelo Enter
    }

}


int main_5(){
    using namespace std;
    string texto;
    int valor;
    string nomes[10]={"um","dois","tres","quatro","cinco","seis","sete","oito","nove","dez"};
    while(texto!="fim") {
        cout << "Introduza numero ou texto: ";
        if (cin >> valor) {
            if (valor > 0 && valor <= 10)
                cout << nomes[valor - 1];
        }
            //por extenso
        else {
            cin.clear();//limpar o estado;
            cin >> texto;
            for (int i = 0; i < 10; i++) {
                if (nomes[i] == texto)
                    cout << i + 1;
            }
        }

        cout << endl;
        cout << "Pressione Enter para prosseguir...";
        cin.ignore(1000, '\n');
        cin.get();

    }

}


int main_6(){
    using namespace std;
    string texto,nome_ficheiro;
    int valor;
    string nomes[10]={"um","dois","três","quatro","cinco","seis","sete","oito","nove","dez"};
    cout << "Nome do ficheiro: ";
    cin >> nome_ficheiro;
    ifstream ficheiro(nome_ficheiro);
    if(!ficheiro){
        cerr << "Ficheiro nao encontrado";
        return -1;
    }
    while(texto!="fim") {
        cout << "Introduza numero ou texto: ";
        if (ficheiro >> valor) {
            if (valor > 0 && valor <= 10)
                cout << nomes[valor - 1];
        }
            //por extenso
        else {
            ficheiro.clear();//limpar o estado;
            ficheiro >> texto;
            for (int i = 0; i < 10; i++) {
                if (nomes[i] == texto)
                    cout << i + 1;
            }
        }
        cout << endl;
       // cout << endl;
        //cout << "Pressione Enter para prosseguir...";
        //cin.ignore(1000, '\n');
        //cin.get();

    }

}
//TRABALHO PRATICO
//string comando;
//int agr1,agr2;
//while(getline(ficheiro,linha));
//istringstream buffer (linha);
//if(buffer >> comando) && ...



int main(){
    //main_2_a();
    //main_2_b_c();
    //main_2_d_e();
    //main_3();
   //main_4();
   //main_5();
    main_6();
}


