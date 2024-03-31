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




int mayorModo(int coorX, int coorY, int tamaño){
    //Funcion que nos haya el modo donde las coordenadas ingresadas son las mayores

    int** matriz0 = crearM(tamaño);
    int** matriz1= rotarM(matriz0, tamaño, 1);
    int** matriz2= rotarM(matriz0, tamaño, 2);
    int** matriz3= rotarM(matriz0, tamaño, 3);
    //  Creamos las matrices en los tres modos y en los tre s
    int num0 = matriz0[coorX][coorY];
    int num1 = matriz1[coorX][coorY];
    int num2 = matriz2[coorX][coorY];
    int num3 = matriz3[coorX][coorY];

    int mayor=0;

    if(num0>=num1 && num0>=num2 && num0>=num3){
        mayor=0;
    }else if(num1>=num0 && num1>=num2 && num1>=num3){
        mayor=1;
    } else if (num2>=num1 && num2>=num0 && num2>=num3){
        mayor=2;
    }else if (num3>=num1 && num3>=num2 && num3>=num0){
        mayor= 3;
    }

    liberarM(matriz0,tamaño);
    liberarM(matriz1,tamaño);
    liberarM(matriz2,tamaño);
    liberarM(matriz3,tamaño);

    return mayor;
}









