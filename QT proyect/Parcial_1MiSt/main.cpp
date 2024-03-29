#include <iostream>
using namespace std;

void mostrarM(int** matriz,int tamaño);
int** crearM(int num);
int** rotarM(int** matriz,int tamaño, int modo);
void liberarM(int** matriz, int longitud);


int main()
{

    int modo=3;
    int tamaño=3;
    int** matrizPrueba = crearM(tamaño);
    mostrarM(matrizPrueba, tamaño);

    cout<<"MODO "<<modo<<" --------------------"<<endl;

    mostrarM(rotarM(matrizPrueba,tamaño,modo),tamaño);


    return 0;
}
