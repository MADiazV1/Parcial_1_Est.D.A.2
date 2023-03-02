#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

// Clase Deuda y sus metodos
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

// Clase Persona y sus metodos
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


// Funcionalidad del programa

vector<Persona*> creacion_data_dummy(int cantidadDatos){
    vector<Persona*> todasLasPersonas;
    int contador = 0;
    while(contador < cantidadDatos){
        srand(time(NULL));
        random_device rd;
        uniform_int_distribution<int> randNombre(0,19);
        // Creacion del ID
        string idCliente = "";
        for(int i=0;i<4;i++){
            idCliente += to_string(rand()%10);
        }

        // Creacion del nombre completo
        string nombre[20] = {"Bruno","Dante","Hugo","Miguel","Samuel","Jose","Daniel","Grabriel","Sofia","Santiago","Julian","Mariana","Valeria","Ana","Valentina","Daniela","Laura","Tomas","Jacobo","Sebastian"};

        string apellido[20] = {"Diaz","Ramirez","Aguilar","Gomez","Valencia","Villada","Gonzales","Zamudio","Restrepo","Escobar","Rodriguez","Moreno","Palacio","Chaverra","Ruiz","Barrera","Giraldo","Gutierrez","Salazar","Betancur"};

        int variableNombre = randNombre(rd);
        int variableApellido = randNombre(rd);
        int variableSegundoApellido = randNombre(rd);
        string nombreCompleto = nombre[variableNombre] + " " + apellido[variableApellido] + " " + apellido[variableSegundoApellido];

        // Creacion del celular
        string numeroTelefono = "+";
        for(int k=0;k<2;k++){
            numeroTelefono+= to_string(rand()%10);
        }
        numeroTelefono += " ";
        for (int j = 0; j < 10; j++) {
            numeroTelefono += to_string(rand() % 10);
        }

        // Creacion de las deudas
        uniform_int_distribution<int> randDeudas(1,15);
        uniform_int_distribution<int> randCapital(100, 10000);
        uniform_real_distribution<float> randTasa(1,2);
        uniform_int_distribution<int> randCuotas(1, 36);
        vector<Deuda*> deudasCliente;
        for(int i=0;i<randDeudas(rd);i++){
            float capital = randCapital(rd);
            float tasa = randTasa(rd);
            int cuota = randCuotas(rd);

            Deuda* d = new Deuda(capital, tasa, cuota);
            deudasCliente.push_back(d);
        }
        contador++;
        // Creacion de los objetos
        Persona* person = new Persona(idCliente, nombreCompleto, numeroTelefono, deudasCliente);
        todasLasPersonas.push_back(person);
    }

    return todasLasPersonas;
}

void imprimir(){

}

int main(){
    int personas = 30;
    vector<Persona*> v = creacion_data_dummy(personas);
    for(int i=0;i<v.size();i++){
        cout << v[i]->getNombreCliente() << endl;
    }
    

    cout << "Funciona" << endl;

    return 0;
}