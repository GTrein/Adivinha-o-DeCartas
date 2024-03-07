
#include <iostream>
#include <locale.h> 
#include<windows.h> 
#include <cstdlib>
#include "App.cpp"
#include <conio.h>
using namespace std;




int main()
{
    srand(time(NULL));
    int cor = 0, numero = 0;
    

    //código em português.
    setlocale(LC_ALL, "portuguese");
    App App;
    //App.gerarCarta(todasCartas[cor][numero]);
    App.MenuPrincipal();
}

