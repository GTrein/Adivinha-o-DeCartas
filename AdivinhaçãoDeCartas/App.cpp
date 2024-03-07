#include "App.h"
#include <ctime>
#include <iomanip>
App::App()
{

}

void App::imprimir(int cartas[3][10]) {
    cout << endl;
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 10; c++) {
            cout << cartas[l][c] << " ";
        }
        cout << endl;
    }

}

int App::acertos(int cartas[3][10])
{
    int acertos = 0;
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 10; c++) {
            
            if (cartas[l][c] == 3)
            {
                acertos++;
            }
        }

    }
    return acertos;
}


int App::cartasRestantes(int cartas[3][10])
{
    int cartasResto = 0;
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 10; c++) {

            if (cartas[l][c] == 0)
            {
                cartasResto++;
            }
        }

    }
    return cartasResto;
}

int App::numeroDeChutes(int cartas[3][10])
{
    int numeroChutes = 0;
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 10; c++) {

            if (cartas[l][c] == 2|| cartas[l][c] == 3)
            {
                numeroChutes++;
            }
        }

    }
    return numeroChutes;
}

int App::chuteCor()
{

    int cor;
    int opcao = 0;


    bool escolha = true;

    while (escolha) {
        escolha = false;
        system("CLS");
        cout << "Adivinhar as cartas.\n";
        cout << "\n";
        cout << "Escolha uma cor.\n";
        cout << "1 - Azul\n";
        cout << "2 - Preto\n";
        cout << "3 - Vermelho\n";
        cin >> opcao;
        switch (opcao) {
        case 1:
            cor = 0;
            break;
        case 2:
            cor = 1;
            break;
        case 3:
            cor = 2;
            break;
        
        default:
            cout << "\nOpção inválida.";
            Sleep(1000);
            escolha = true;
        }

    }
    return cor;

}

int App::chuteNumero() {
    bool escolha = true;
    int numero;
    while (escolha) {
        escolha = false;
        system("CLS");
        cout << "Adivinhar as cartas.\n";
        cout << "\n";
        cout << "Escolha um número entre 1 e 10\n";
        cin >> numero;
        if (numero <= 0 || numero > 10) {
            cout << "\nOpção inválida.";
            Sleep(1000);
            escolha = true;
        }
        else {
            escolha = false;
            numero = numero - 1;
        }
    }
    return numero;
}




int App::gerarCarta(int cartas[3][10], int numeroDeSorteios)
{

    int cor;
    int numero;
    for (int i = 0; i < numeroDeSorteios; i++) {
    cor = rand() % 3;
    numero = rand() % 10;
    if (cartas[cor][numero] == 1) {
        i--;
        continue;
    }
    cartas[cor][numero] = 1;
}
    return 0;
}

void App::cartasSorteadas(int cartas[3][10])
{
    
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 10; c++) {

            if (cartas[l][c] == 3|| cartas[l][c] == 1)
            {
                if (l == 0) {
                    cout << c+1 << " azul\n";
                }
                else if (l == 1) {
                    cout << c + 1 << " preto\n";
                }
                else if (l == 2) {
                    cout << c + 1 << " vermelho\n";
                };
            }
        }

    }

}


void App::Jogo()
{   
    int cor, numero, pontos = 0;
    int numeroDeSorteios = 0;
    int opcao = 0;
    bool escolha = true;
    int todasCartas[3][10]
    { {0,0,0,0,0,0,0,0,0,0}
    , {0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0} };

    while (escolha) {
        escolha = false;
       system("CLS");
       cout << "\nVocê deseja adivinhar 5 ou 10 cartas?";
       cout << "\nPressione 1 para adivinhar 5.";
       cout << "\nPressione 2 para adivinhar 10.\n\n";
       cin >> opcao;
       switch (opcao) {
       case 1:
           //5 cartas
           
               gerarCarta(todasCartas,5);
               numeroDeSorteios = 5;
               



           break;
       case 2:
           //10 cartas
           
               gerarCarta(todasCartas,10);
               numeroDeSorteios = 10;

               

           imprimir(todasCartas);
           break;
       default:
           cout << "\nOpção inválida.";
           Sleep(1000);
           escolha = true;

       }

    }
    int certas;
    bool rodando = true;
    while(rodando){
        

        cor = chuteCor();
        numero = chuteNumero();
        if (todasCartas[cor][numero] == 0) {
            todasCartas[cor][numero] = 2;
            cout << "\nVocê errou. Menos 1 ponto.";
            pontos = pontos -1;
            cout << "\nVocê tem " << pontos << " pontos.";
        }
        else if (todasCartas[cor][numero] == 1) {
            todasCartas[cor][numero] = 3;
            cout << "\nVocê acertou. Ganhou 5 pontos.";
            pontos = pontos + 5;
            cout << "\nVocê tem " << pontos << " pontos.";
        }
        else if (todasCartas[cor][numero] == 2 || todasCartas[cor][numero] == 3) {
            cout << "\nVocê já tinha chutado essa carta, tente outra!!";
        }
        certas = acertos(todasCartas);
        if (certas == 1) {
            cout << endl << "Você já acertou " << certas << " carta!" << endl;
        }
        else {
            cout << endl << "Você já acertou " << certas << " cartas" << endl;
        }
        if (certas == numeroDeSorteios) {
            rodando = false;
        }
        char mostrarMatriz;
        mostrarMatriz = 'n';
        cout << "\nPressione enter para continuar...\n";
        mostrarMatriz = getchar();
        mostrarMatriz = getchar();


        if (mostrarMatriz == 'm') {
            imprimir(todasCartas);
            system("pause");

        }
        

    }
    int numeroChutes = numeroDeChutes(todasCartas);
    int restoCartas = cartasRestantes(todasCartas);
    cout << "Fim de jogo!\n\n";
    cout << "A sua pontuação foi de " << pontos << " pontos.\n\n";

    cout << "Você tentou adivinhar " << numeroChutes << " cartas e sobraram " << restoCartas << " no baralho.\n";
    cout << "As cartas sorteadas foram essas:\n";
    cartasSorteadas(todasCartas);

    system("pause");
}


int App::MenuPrincipal()
{
    bool emLoop = true;
    int opcao = 0;


    while (emLoop) {
        emLoop = false;
        system("CLS");
        cout << "=== Menu principal ===" << endl;
        cout << "\n1 - Começar Jogo";
        cout << "\n2 - Regras";
        cout << "\n3 - Sair\n\n";
        cin >> opcao;
        switch (opcao) {
        case 1:
            //começar jogo
            Jogo();
            break;
        case 2:
            //regras
            cout << "\nVocê pode escolher adivinhar 5 ou 10 cartas, acertar uma carta te dá 5 pontos e se errar perde 1.";
            cout << "\nAs cartas vão de 1 a 10 e tem 3 cores que são azul, vermelho e preto." ;
            cout << "\nO jogo acaba quando você acerta todas as cartas." << endl;
            emLoop = true;
            system("pause");
            break;
        case 3:
            //sair
            cout << "Fechando app...";
            break;
        default:
            cout << "\nOpção inválida.";
            Sleep(1000);
            emLoop = true;
        }
        
    }

    return 0;
}