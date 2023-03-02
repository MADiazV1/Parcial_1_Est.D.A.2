#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Deuda{
    private:
        float capitalDeuda;
        float tasaDeuda;
        int numeroCuotasDeuda;
    public:
        Deuda(float, float, int);
        float getCapitalDeuda();
};

float Deuda::getCapitalDeuda(){
    return this->capitalDeuda;
}

Deuda::Deuda(float _capitalDeuda, float _tasaDeuda, int _numeroCuotasDeuda){
    capitalDeuda = _capitalDeuda;
    tasaDeuda = _tasaDeuda;
    numeroCuotasDeuda = _numeroCuotasDeuda;
}

class Persona{
    private:
        string idCliente;
        string nombreCliente;
        string telefonoCliente;
    public:
        vector<Deuda*> deudasCliente;
        Persona(string, string, string, vector<Deuda*>);
        string getNombreCliente();

};

Persona::Persona(string _idCliente, string _nombreCliente, string _telefonoCliente, vector<Deuda*> _deudasCliente){
    idCliente = _idCliente;
    nombreCliente = _nombreCliente;
    telefonoCliente = _telefonoCliente;
    deudasCliente = _deudasCliente;
}

string Persona::getNombreCliente(){
    return this->nombreCliente;
}

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


void creacion_data_dummy(){}

int main(){

    Deuda* deuda = new Deuda(1000.0, 1.3, 12);

    vector<Deuda*> deudas;
    deudas.push_back(deuda);

    Persona* persona = new Persona("1234","Miguel Angel Diaz","+32 23242342", deudas);
    cout << persona->getNombreCliente() << endl;
    cout << persona->deudasCliente[0]->getCapitalDeuda() << endl;
    return 0;
}