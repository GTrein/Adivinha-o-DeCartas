#ifndef APP_H
#define APP_H


#include <iostream>
#include <Windows.h>
using namespace std;


class App
{
public:

	App();
	int gerarCarta(int todasCartas[3][10], int numeroDeSorteios);
	int MenuPrincipal();
	void Jogo();
	int chuteCor();
	int chuteNumero();
	int acertos(int cartas[3][10]);
	void imprimir(int cartas[3][10]);
	int cartasRestantes(int cartas[3][10]);
	int numeroDeChutes(int cartas[3][10]);
	void cartasSorteadas(int cartas[3][10]);
private:
	


};
#endif