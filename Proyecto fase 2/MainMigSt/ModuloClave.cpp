#include <iostream>
using namespace std;
int** crearM(int num);
void liberarM(int**& matriz, int longitud);
int** rotarM(int** matriz,int tamaño, int modo);
void mostrarM(int** matriz,int tamaño);

int* agregarDato(int dato, int* arreglo, int longitud){   //Esta funcion va a alargar el arreglo una posicion y luego le va a agregar el dato que necesitamos
    int* nuevoArreglo = new int[longitud+1];
    for(int i=0; i<=longitud;i++){
        if(i<longitud){
            nuevoArreglo[i]=arreglo[i];
        }
        else{
            nuevoArreglo[i]=dato;
        }
    }
    delete[] arreglo;
    return nuevoArreglo;
}

int* pedirClave(int& tamaño){
    cout << "INGRESE NUMERO POR NUMERO LA CLAVE A LA CUAL DESEA ENCONTRAR LA CERRADURA: " << endl << "PARA TERMINAR INGRESE (-2). " << endl;
int* arreglo = new int[1];
int cont=0;
int numero=0;
bool ban = true;
while(ban){

    cout<<"Ingresa el parametro numero "<<cont+1<<":";
        cin>>numero;


    if(cont==0 || cont==1){       //Esta ingresando las coordenandas de la matriz

        if(numero<1){     //Ingreso un numero no valido
            cout<<"No puede ingresar cero o un numero negativo porfavor ingresa uno diferente: "<<endl;
        }
        else{
            if(cont==0){  //Para poder ingresar el primer valor
                arreglo[0]=numero;
                cont++;
            }
            else{ //Es el segundo dato
                arreglo = agregarDato(numero,arreglo,cont);
                cont++;
            }
        }
    }
    else{
        if(numero!=0 && numero!=1 && numero!=-1 && numero != -2){   //Caso en que escriba un numero no valido
            cout<<"Solo puedes ingresar (1) (-1) (0) (-2) porfavor intentalo nuevamente: "<<endl;
        }
        else{   //Escribio un numero valido

            if(numero!=-2){
                arreglo= agregarDato(numero,arreglo,cont);
                cont++;
            }
            else{   //Escribio -2
                if(cont<=2){
                    cout<<"Tienes que escribir como minimo tres parametros, intentalo nuevamente: "<<endl;
                }
                else{//Condicion de terminacion
                    ban=false;
                }
            }

        }
    }

}   //Fin while

tamaño = cont;
    return arreglo;
}


int caso1(int valor,int& casillaModo, int tamañoPre, int coorX, int coorY,int&casillaValor){ //actual > nueva
    // (1) La siguiente matriz debe ser menor en las coordenadas
    //Retornara la siguiente matriz
    int coorMayor = 0;
    if(coorX>coorY){
        coorMayor = coorX;
    }
    else{
        coorMayor = coorY;
    }

    int tamaño = tamañoPre;
    int** matriz = crearM(tamañoPre);
    int modo = 0;
    //Nos servira para saber si ya ha rotado todas las veces y no sirve
    bool ban = true;

        //revisa si encontramos el valor.
        if(matriz[coorX][coorY] < valor){ //Encotramos la matriz que era
             casillaValor=matriz[coorX][coorY];
            casillaModo = modo;
            liberarM(matriz,tamaño);
            return tamaño;
        }
        else{
            while(ban){
                //revisa el tamaño para saber si podemos reducir la matriz.
                 if (tamaño < 3 || tamaño < coorMayor){   //No es posible realizar una cerradura;
                    liberarM(matriz,tamaño);

                    return -1;
                    break;
                }

                //No nos sirve la matriz creada anteriormente
                else{
                    bool ban2 = true;
                    while(ban2){        //Ciclo para las rotaciones de las matrices
                        liberarM(matriz,tamaño);
                        matriz = crearM(tamaño);
                        int** nuevaMat = rotarM(matriz,tamaño, modo);

                        if(nuevaMat[coorX][coorY] >= valor && modo < 4){  //No cumple
                            modo++;
                            liberarM(nuevaMat,tamaño);  //Instruccion dañinaaaaa
                        }
                        else if (modo == 4){ //Ya las roto de todas las formas

                            ban2 = false;
                            liberarM(nuevaMat,tamaño);
                            modo = 0;
                            tamaño = tamaño - 2;
                            coorX = coorX - 1;        //Aumentamos los tamaños de las coordenadas para que se adapten a la nueva matriz
                            coorY = coorY - 1;

                            if(coorX<0 || coorY < 0){   //Las coordenadas se vuelven negativas por ende no existe cerradura
                                return -1;
                            }


                        }
                        else if (nuevaMat[coorX][coorY] < valor && modo < 4){   //Condicion ideal de retorno, donde se cumple la condicion y el modo es posible
                            casillaValor=nuevaMat[coorX][coorY];
                            casillaModo = modo;
                            liberarM(nuevaMat,tamaño);
                            return tamaño;
                        }
                    }
                }
            }
        }


    return tamaño;
}



int caso2(int valor,int& casillaModo, int tamañoPre, int coorX, int coorY,int& casillaValor){ // actual < nueva
    // (-1) La siguiente matriz debe ser menor en las coordenadas
    //Retornara la siguiente matriz


    int tamaño = tamañoPre;
    int** matriz = crearM(tamañoPre);
    int modo = 0;
    //Nos servira para saber si ya roto todas las veces y no sirve
    bool ban = true;


        if(matriz[coorX][coorY] > valor){ //Encotramos la matriz que era
            casillaModo = modo;
            casillaValor=matriz[coorX][coorY];
            liberarM(matriz,tamaño);

            return tamaño;
        }
        else{      //No nos sirve la matriz creada anteriormente
            while(ban){
            bool ban2 = true;
            while(ban2){        //Ciclo para las rotaciones
                liberarM(matriz,tamaño-2);
                matriz = crearM(tamaño);
                int** nuevaMat = rotarM(matriz,tamaño, modo);
               // mostrarM(nuevaMat,tamaño);
                if(nuevaMat[coorX][coorY] <= valor && modo < 4){  //No cumple
                    modo++;
                    liberarM(nuevaMat,tamaño);  //Instruccion dañinaaaaa
                }
                else if (modo == 4){ //Ya las roto de todas las formas, entonces aumentamos el tamaño y intentamos con todos los modos de nueva
                    ban2 = false;
                    modo = 0;
                    liberarM(nuevaMat,tamaño);  //Instruccion que nos esta dando el error
                    tamaño = tamaño + 2;
                    coorX++;        //Aumentamos los tamaños de las coordenadas para que se adapten a la nueva matriz
                    coorY++;
                }


                else if (nuevaMat[coorX][coorY] > valor && modo < 4){
                    casillaValor=nuevaMat[coorX][coorY];
                    casillaModo = modo;   //Mandamos el valor por referencia
                    liberarM(nuevaMat,tamaño);
                    return tamaño;

                }
            }
            }
        }
    return tamaño;  //Retornamos el valor para poder abarcar todos los casos de retorno para el compilador
}
