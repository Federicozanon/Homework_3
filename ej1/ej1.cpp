#include "ej1.hpp"

MedicionBase::MedicionBase(float t_medicion) : tiempoMedicion(make_unique<float>(t_medicion)) {};

float MedicionBase::getTiempo(){
    return *tiempoMedicion;
}

Presion::Presion(float p, float q, float t) : presionEstatica(p), presionDinamica(q), MedicionBase(t) {};

void Presion::imprimir(){
    cout<<"Datos de la presion en tiempo "<<getTiempo()<<"segundos: \n";
    cout<<"Presion dinamica: "<<presionDinamica<<"\nPresion estatica: "<<presionEstatica<<"\n";
}
void Presion::serializar(ofstream& out){
    out.write(reinterpret_cast<char*>(&presionEstatica), sizeof(float));
    out.write(reinterpret_cast<char*>(&presionDinamica), sizeof(float));
    float t = getTiempo();
    out.write(reinterpret_cast<char*>(&t), sizeof(float));
}
void Presion::deserializar(ifstream& in){
    float t;
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(float));
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(float));
    in.read(reinterpret_cast<char*>(&t), sizeof(float));
    tiempoMedicion = make_unique<float>(t);

}
unique_ptr<MedicionBase> Presion::copiar() const{
    return make_unique<Presion>(*this);
}

Posicion::Posicion(float lat, float lon, float alt, float t) : latitud(lat), longitud(lon), altitud(alt), MedicionBase(t) {}; 

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
unique_ptr<MedicionBase> Posicion::copiar() const{
    return make_unique<Posicion>(*this);
}

SaveFlightData::SaveFlightData(const Posicion& p, const Presion& q) : posicion(dynamic_cast<Posicion*>(p.copiar().release())), presion(dynamic_cast<Presion*>(q.copiar().release())) {}

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