#include <iostream>
using namespace std;

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

int* pedirClave(){
    cout<<"Ingresa numero por numero la clave a la cual le gustaria encontrar su cerradura, cuanto termine ingrese porfavor (-2) "<<endl;
    int* arreglo = new int[1];
    int cont=0;
    int numero=0;
    bool ban = true;
    while(ban){
        cout<<"Ingresa el parametro numero "<<cont+1<<":";
        cin>>numero;
        if(cont==0 || cont==1){       //Esta ingresando las coordenandas de la matriz
            if(numero<=1){     //Ingreso un numero no valido
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

    for (int i=0; i<cont;i++){
        cout<<arreglo[i];
        cout<<" ";
    }
    return arreglo;
}
