#include "ej1.hpp"

MedicionBase::MedicionBase(float t_medicion) : tiempoMedicion(make_unique<float>(t_medicion)) {};

MedicionBase::MedicionBase(const MedicionBase& other) : tiempoMedicion(make_unique<float>(*other.tiempoMedicion)) {};

float MedicionBase::getTiempo(){
    return *tiempoMedicion;
}

Presion::Presion(float p, float q, float t) : MedicionBase(t) ,presionEstatica(p), presionDinamica(q) {};

Presion::Presion(const Presion& other) : MedicionBase(other), presionEstatica(other.presionEstatica), presionDinamica(other.presionDinamica) {};

void Presion::imprimir(){
    cout<<"Datos de la presion en tiempo "<<getTiempo()<<"segundos: \n";
    cout<<"Presion estatica: "<<presionEstatica<<"\nPresion dinamica: "<<presionDinamica<<"\n";
}
void Presion::serializar(ofstream& out){
    out.write(reinterpret_cast<char*>(&presionEstatica), sizeof(float));
    out.write(reinterpret_cast<char*>(&presionDinamica), sizeof(float));
    float t = getTiempo();
    out.write(reinterpret_cast<char*>(&t), sizeof(float));
}
void Presion::deserializar(ifstream& in){
    float t;
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(float));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(float));
    in.read(reinterpret_cast<char*>(&t), sizeof(float));
    tiempoMedicion = make_unique<float>(t);

}

Posicion::Posicion(float lat, float lon, float alt, float t) : MedicionBase(t), latitud(lat), longitud(lon), altitud(alt) {}; 

Posicion::Posicion(const Posicion& other) : MedicionBase(other), latitud(other.latitud), longitud(other.longitud), altitud(other.altitud) {};

void Posicion::imprimir(){

}
void Posicion::serializar(ofstream& out){
    out.write(reinterpret_cast<char*>(&latitud), sizeof(float));
    out.write(reinterpret_cast<char*>(&longitud), sizeof(float));
    out.write(reinterpret_cast<char*>(&altitud), sizeof(float));
    float t = getTiempo();
    out.write(reinterpret_cast<char*>(&t), sizeof(float));
}
void Posicion::deserializar(ifstream& in){
    float t;
    in.read(reinterpret_cast<char*>(&latitud), sizeof(float));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(float));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(float));
    in.read(reinterpret_cast<char*>(&t), sizeof(float));
    tiempoMedicion = make_unique<float>(t);

}
SaveFlightData::SaveFlightData(const Posicion& p, const Presion& q) : posicion(make_unique<Posicion>(p)), presion(make_unique<Presion>(q)) {}

void SaveFlightData::imprimir(){

}
void SaveFlightData::serializar(ofstream& out){
    presion->serializar(out);
    posicion->serializar(out);
}
void SaveFlightData::deserializar(ifstream& in){
    presion->deserializar(in);
    posicion->deserializar(in);
}