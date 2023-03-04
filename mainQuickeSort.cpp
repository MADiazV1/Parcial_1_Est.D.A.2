#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

// Clase Deuda y sus metodos
class Deuda{
    private:
        float capitalDeuda;
        float tasaDeuda;
        int numeroCuotasDeuda;
        float valorDeInteres;
    public:
        Deuda(float, float, int);
        float getCapitalDeuda();
        float getTasaDeuda();
        int getNumeroCuotasDeuda();
        float getValorDeInteres();
};

Deuda::Deuda(float _capitalDeuda, float _tasaDeuda, int _numeroCuotasDeuda){
    capitalDeuda = _capitalDeuda;
    tasaDeuda = _tasaDeuda;
    numeroCuotasDeuda = _numeroCuotasDeuda;
}

float Deuda::getCapitalDeuda(){
    return this->capitalDeuda;
}

float Deuda::getTasaDeuda(){
    return this->tasaDeuda;
}

int Deuda::getNumeroCuotasDeuda(){
    return this->numeroCuotasDeuda;
}

float Deuda::getValorDeInteres(){
    return this->capitalDeuda * this->tasaDeuda;
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
        string getIdCliente();
        string getTelefonoCliente();
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

string Persona::getIdCliente(){
    return this->idCliente;
}

string Persona::getTelefonoCliente(){
    return this->telefonoCliente;
}

// Funcionalidad del programa

vector<Persona*> creacion_data_dummy(int cantidadDatos){
    vector<Persona*> todasLasPersonas;
    int contador = 0;
    while(contador < cantidadDatos){
        srand(time(NULL));
        random_device rd;
        // Creacion del ID
        uniform_int_distribution<int> randIdCliente(0,9);
        string idCliente = "";
        for(int i=0;i<4;i++){
            idCliente += to_string(randIdCliente(rd));
        }

        // Creacion del nombre completo
        uniform_int_distribution<int> randNombre(0,19);
        string nombre[20] = {"Bruno","Dante","Hugo","Miguel","Samuel","Jose","Daniel","Grabriel","Sofia","Santiago","Julian","Mariana","Valeria","Ana","Valentina","Daniela","Laura","Tomas","Jacobo","Sebastian"};

        string apellido[20] = {"Diaz","Ramirez","Aguilar","Gomez","Valencia","Villada","Gonzales","Zamudio","Restrepo","Escobar","Rodriguez","Moreno","Palacio","Chaverra","Ruiz","Barrera","Giraldo","Gutierrez","Salazar","Betancur"};

        int variableNombre = randNombre(rd);
        int variableApellido = randNombre(rd);
        int variableSegundoApellido = randNombre(rd);
        string nombreCompleto = nombre[variableNombre] + " " + apellido[variableApellido] + " " + apellido[variableSegundoApellido];

        // Creacion del celular
        uniform_int_distribution<int> randTelefono(0,9);
        string numeroTelefono = "+";
        for(int k=0;k<2;k++){
            numeroTelefono+= to_string(randTelefono(rd));
        }
        numeroTelefono += " ";
        for (int j = 0; j < 10; j++) {
            numeroTelefono += to_string(randTelefono(rd));
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

vector<Deuda*> organizador_Deudas(vector<Deuda*> p){
   for (int i = 0; i < p.size(); i++){
        for (int j = 0; j < p.size() - i - 1; j++){
            if (p[j]->getValorDeInteres() < p[j + 1]->getValorDeInteres()){
                Deuda* temp;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    return p; 
}

//----------- QuickSort valor de interes -------------------
void quickSort_valor_de_interes(vector<Persona*> p, int left, int right) {
    int i = left;
    int j = right;
    Persona* tmp;
    float pivot = p[left]->deudasCliente[0]->getValorDeInteres();
    while (i <= j) {
        while (p[i]->deudasCliente[0]->getValorDeInteres() < pivot) {
            i++;
        }
        while (p[j]->deudasCliente[0]->getValorDeInteres() > pivot) {
            j--;
        }
        if (i <= j) {  
            cout << "Cambio" << endl;
            tmp = p[i];
            p[i] = p[j];
            p[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j) {
        quickSort_valor_de_interes(p, left, j);
    }
    if (i < right) {
        quickSort_valor_de_interes(p, i, right);
    }
}

void imprimir_Informacion_Completa(vector<Persona*> p){
    for(int i=0;i<p.size();i++){
        p[i]->deudasCliente = organizador_Deudas(p[i]->deudasCliente);
        cout << i+1 << ". " << p[i]->getNombreCliente() << " ID: " << p[i]->getIdCliente() << " Nro: " << p[i]->getTelefonoCliente() << endl;
        cout << "   Capital actual / " << "Tasa de interes mensual / " << "Cuotas / " << "Valor de interes" << endl;
        for(int j=0;j<p[i]->deudasCliente.size();j++){
            cout << "   " << j+1 << ". $" << p[i]->deudasCliente[j]->getCapitalDeuda() << " - %" << p[i]->deudasCliente[j]->getTasaDeuda() << " - " << p[i]->deudasCliente[j]->getNumeroCuotasDeuda() << " mes(es) - $" << p[i]->deudasCliente[j]->getValorDeInteres() << endl; 
        }
       cout << endl;
    }
}

// ---------------------------------

vector<Deuda*> quickSort_Deuda_Critica(vector<Deuda*> p){
    for (int i = 0; i < p.size(); i++){
        for (int j = 0; j < p.size() - i - 1; j++){
            if (p[j]->getNumeroCuotasDeuda() > p[j + 1]->getNumeroCuotasDeuda()){
                Deuda* temp;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    return p; 
}

void imprimir_Informacion_Deuda_Critica(vector<Persona*> p){
    for(int i=0;i<p.size();i++){
        p[i]->deudasCliente = quickSort_Deuda_Critica(p[i]->deudasCliente);
        cout << i+1 << ". " << p[i]->getNombreCliente() << " ID: " << p[i]->getIdCliente() << endl;
        cout << "   Capital actual / " << "Tasa de interes mensual / " << "Cuotas / " << endl;
        cout << "   " << "Deuda critica: $" << p[i]->deudasCliente[0]->getCapitalDeuda() << " - %" << p[i]->deudasCliente[0]->getTasaDeuda() << " - " << p[i]->deudasCliente[0]->getNumeroCuotasDeuda() << " mes(es)"<< endl; 
        cout << endl;
    }
}

int main(){
    srand(time(NULL));
    random_device rd;
    uniform_int_distribution<int> dist(10,1000); //En esta linea puede modificar rango de la cantidad de peronas para hacer la comprobacion
    vector<Persona*> p = creacion_data_dummy(dist(rd));
    
    bool modo = true;
    while(modo){
        int valor;
        cout << "1. Imprimir la lista Random." << endl;
        cout << "2. Imprimir la lista de deuda mas critica." << endl;
        cout << "3. Imprimir la lista ordenada por el valor de interes." << endl;
        cout << "0. Cerrar" << endl;
        cout << "Ingrese un valor: ";
        cin >> valor;
        cout << endl;
        switch(valor){
            case 0:{
                modo = false;
                cout << "Adios..." << endl;
                break;
            }
            case 1:{
                imprimir_Informacion_Completa(p);
                cout << "=====================================================================" << endl;
                cout << endl;
                break;
            }
            case 2:{
                imprimir_Informacion_Deuda_Critica(p);
                cout << "=====================================================================" << endl;
                cout << endl;
                break;
            }
            case 3:{
                quickSort_valor_de_interes(p, 0, p.size()-1);
                imprimir_Informacion_Completa(p);
                cout << "=====================================================================" << endl;
                cout << endl;
                break;
            }
            default:{
                cout << "Valor erroneo" << endl;
                break;
            }
        }
    }  
    return 0;
}