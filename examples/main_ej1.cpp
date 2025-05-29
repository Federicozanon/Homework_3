#include "../include/ej1.hpp"

int main(){
    Posicion posicion1(-34.6f, -58.4f, 950.0f, 5.3f); 
    Presion presion1(101.3f, 5.8f, 6.1f);
    SaveFlightData datos_vuelo1(posicion1, presion1);
    ofstream archivo_entrada("example_ej1.txt", ios::binary);
    if(archivo_entrada.is_open()){
        datos_vuelo1.serializar(archivo_entrada);
        archivo_entrada.close();
    }
    else {
    cerr << "Error al abrir archivo para escritura.\n";
    }
    SaveFlightData datos_vuelo2;
    ifstream archivo_salida("example_ej1.txt", ios::binary);
    if(archivo_salida.is_open()){
        datos_vuelo2.deserializar(archivo_salida);
        archivo_salida.close();
    }
    else {
    cerr << "Error al abrir archivo para lectura.\n";
    }
    datos_vuelo2.imprimir();
    return 0;
}