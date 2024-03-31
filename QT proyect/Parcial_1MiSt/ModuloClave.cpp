#include <iostream>
using namespace std;
int** crearM(int num);
void liberarM(int** matriz, int longitud);
int** rotarM(int** matriz,int tamaño, int modo);


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
    cout<<"Ingresa numero por numero la clave a la cual le gustaria encontrar su cerradura, cuanto termine ingrese porfavor (-2) "<<endl;
    int* arreglo = new int[1];
    int cont=0;
    int numero=0;
    bool ban = true;
    while(ban){
        cout<<"Ingresa el parametro numero "<<cont+1<<":";
        cin>>numero;
        if(cont==0 || cont==1){       //Esta ingresando las coordenandas de la matriz
            if(numero<1){     //Ingreso un numero no valido
                cout<<"No puede ingresar un numero negativo porfavor ingresa uno diferente: "<<endl;
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


int caso1(int valor,int& casillaModo, int tamañoPre, int coorX, int coorY){
    // (1) La siguiente matriz debe ser menor en las coordenadas
   //Retornara la siguiente matriz

    int tamaño= tamañoPre;
    int** matriz = crearM(tamañoPre);
    int modo=0;
       //Nos servira para saber si ya roto todas las veces y no sirve
    bool ban=true;
    while(ban){
        if(matriz[coorX][coorY]<valor){ //Encotramos la matriz que era
            liberarM(matriz,tamaño);
            casillaModo=modo;
            return tamaño;
        }
        else if (tamaño==3){   //No es posible realizar una cerradura;
            return -1;

        }else{      //No nos sirve la matriz creada anteriormente
            bool ban2=true;
            while(ban2){        //Ciclo para las rotaciones
                 int** nuevaMat = rotarM(matriz,tamaño, modo);
                if(nuevaMat[coorX][coorY]>=valor && modo<4){  //No cumple
                    modo++;
                    liberarM(nuevaMat,tamaño);

                }else if (modo==4){ //Ya las roto de todas las formas
                    ban2=false;
                    modo=0;
                    tamaño=tamaño-2;
                }else{
                    ban2=false;

                }
            }
        }
    }
    return tamaño;
}
