#include <iostream>
using namespace std;

//Funciones Estructura M
void mostrarM(int** matriz,int tamaño);
int** crearM(int num);
int** rotarM(int** matriz,int tamaño, int modo);
void liberarM(int** matriz, int longitud);
int mayorModo(int coorX, int coorY, int tamaño);

//Funciones de Modulo clave
int* agregarDato(int dato, int* arreglo, int longitud); //Esta funcion es necesaria para pedirClave()
int* pedirClave(int& tamaño);
int caso1(int valor,int& casillaModo, int tamañoPre, int coorX, int coorY);



int main()
{
    //Lo primero que vamos a hacer es solicitar la clave
    //La funcion de pedirClave nos entregara un arreglo dinamico con los parametros de la clave
    //Le pasaremos un parametro por referencia que nos va ayudar a determinar el tamaño del arreglo dinamico

    int tamaño=0;   //tamaño del arreglo de la clave

    int* clave = pedirClave(tamaño);    //Almacenamos aca los parametros de la calve
    int* cerradura = new int[tamaño-1]; //Arreglo que almacenara los tamaños de las matrices
    int* modos = new int[tamaño-1]; //Nos aguardara los modos en los que necesitamos cada matriz

    bool ban = true;

     //Seran la posicion de los arreglos de la clave y de la cerradura
    int posClave=2; //Inicia desde 2 para que comience recorriendo las condiciones
    int posCerra=0; //Podemos usar esta variable tanto para la cerradura como para el arreglo de modos


    //Cordenadas
    int posX= clave[0];
    int posY= clave[1];
    int coorMayor =0;
    if (posX>posY){
        coorMayor=posX;
    }else{
        coorMayor=posY;
    }


    int tamañoPre=tamaño+coorMayor;
    if(tamañoPre%2==0){    //Tamaño prederterminado que le queremos dar a las matrices
        //Si es par le restamos 1, recordemos que las dimensiones de las matrices siempre es impar
        tamañoPre=tamañoPre-1;
    }

    //La primera matriz de la cerradura tendra un tamaño=tamaño+la coordenada mayor para abarcar mas facil el caso K(n1,n2,1,1,1,...)
    int** matrizU = crearM(tamañoPre);
    cerradura[posCerra]=tamañoPre;
    modos[posCerra]=0;  //La matriz base siempre va a estar en modo 0

    while(ban){
        posCerra++;
        int valor=matrizU[posX][posY];
        if(clave[posClave]==1){ //Caso (1) A>B
            int sigMat=caso1(valor,modos[posCerra],tamañoPre,posX,posY);
            cerradura[posCerra]=sigMat; //Agregamos al arreglo el tamaño de la matriz, el modo se agregara automaticamente por referencia
        }


        if(posClave==tamaño-1){ //Condicion de terminacion, termino de recorrer la clave
            ban=false;
        }
        posClave++;
    }

    for(int i=0;i<tamaño-1;i++){
        cout<<cerradura[i]<<" ";
    }


    return 0;
}
