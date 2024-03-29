#include<iostream>
using namespace std;
int** crearM(int num){  //Funcion que nos crea la estructura planteada en el problema

    //Solo recibe numeros enteros impares
    int vacio= int(num/2);


    int** matriz = new int*[num];   //Creamos el tamaño de la estrucutura M
    for (int i=0; i<num;i++){
        matriz[i]= new int[num];
    }

    int cont=1;
    for(int i=0;i<num;i++){
        for(int j=0; j<num;j++){

            if(!(i==vacio  && j==vacio)){      //Si no es el centro de la matriz
                matriz[i][j]=cont;
                cont++;
            }
            else{
                matriz[i][j]=0;
            }
        }
    }
    return matriz;
}



void mostrarM(int** matriz,int tamaño){    //Nos muestra la matriz en consola, el segundo parametro...

    for(int i=0;i<tamaño;i++){            //...es una dimension de la amtriz la cual debe tener las mismas dimensiones
        for(int j=0; j<tamaño;j++){
            std:: cout<<matriz[i][j];
            std:: cout<<" ";
        }
        cout<<endl;
    }
}


int** rotarM(int** matriz,int tamaño, int modo){   //Funcion de rotacion de matrices dependiendo del modo

    //Creamos una matriz auxiliar
    int** matrizAux = new int*[tamaño];
    for(int i=0; i<tamaño;i++){
        matrizAux[i]= new int[tamaño];
    }

    //La inicializacion de la matriz auxiliar sera la matriz rotada como tal

    int posX=0;
    int posY=0;

    switch (modo){  //Dependiendo el modo va a rotar la matriz de cierta manera

    case 1:
        posX=0;
        posY=0;
        for (int i =0;i<tamaño;i++){
            posX=0;
            for(int j=tamaño-1;j>=0;j--){           //I y J recorren la matriz 1 con normalidad de abajo hacia arriba
                matrizAux[posX][posY]=matriz[i][j];
                posX++;
            }
            posY++;
        }
        return matrizAux;
        break;

    case 2:
        posX=tamaño-1;
        posY=tamaño-1;
        for (int i =0;i<tamaño;i++){
            posY=tamaño-1;
            for(int j=0;j<tamaño;j++){           //I y J recorren la matriz 1 con normalidad de abajo hacia arriba
                matrizAux[posX][posY]=matriz[i][j];
                posY--;
            }
            posX--;
        }
        return matrizAux;
        break;


    case 3:
        posX=0;
        posY=0;
        for (int i =tamaño-1;i>=0;i--){
            posX=0;
            for(int j=0;j<tamaño;j++){           //I y J recorren la matriz 1 con normalidad de abajo hacia arriba
                matrizAux[posX][posY]=matriz[i][j];
                posX++;
            }
            posY++;
        }
        return matrizAux;
        break;


    default:
        std::cout<<"No se puede rotar ";
        return matriz;
        break;
    }
}



void liberarM(int** matriz,int longitud)
{   //Funcion que liberas posiciones de memoria dinamica de la matriz

    for(int i=0;i<longitud;i++){
        delete[] matriz[i];
    }
    delete[] matriz;
}
