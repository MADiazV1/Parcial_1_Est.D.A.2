#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void creacion_nombre_completo(int cantidad){
    random_device rd;
    uniform_int_distribution<int> dist(0,19);

    string nombre[20] = {"Bruno","Dante","Hugo","Miguel","Samuel","Jose","Daniel","Grabriel","Sofia","Santiago","Julian","Mariana","Valeria","Ana","Valentina","Daniela","Laura","Tomas","Jacobo","Sebastian"};

    string apellido[20] = {"Diaz","Ramirez","Aguilar","Gomez","Valencia","Villada","Gonzales","Zamudio","Restrepo","Escobar","Rodriguez","Moreno","Palacio","Chaverra","Ruiz","Barrera","Giraldo","Gutierrez","Salazar","Betancur"};
    
    for(int i=0;i<cantidad;i++){
        int x = dist(rd);
        int y = dist(rd);
        int z = dist(rd);
        string nombreCompleto = nombre[x] + " " + apellido[y] + " " + apellido[z];

        //Insertar el nombre de la persona en el objeto

        cout << nombreCompleto << endl;
    }
}

void creacion_telefono(int cantidad){
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        string numero = "";
        for (int j = 0; j < 10; j++) {
            numero += to_string(rand() % 10);
        }
        cout << numero << endl;
    }
}

int main(){

    int cantidad = 10;
    creacion_nombre_completo(cantidad);
    cout << endl;
    creacion_telefono(cantidad);

    return 0;
}