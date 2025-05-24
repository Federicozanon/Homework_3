using namespace std;
#include <iostream>
#include <fstream> 
#include <memory>

class IMediciones {
    public:
        virtual void serializar(ofstream&) = 0;
        virtual void deserializar(ifstream&) = 0;
        virtual ~IMediciones() = default;
};
//HACE FALTA CONSTRUCTORES Y DESTRUCTORES VIRTUALES?
class MedicionBase : public IMediciones {
    protected:
        unique_ptr<float> tiempoMedicion; //t
    public:
        MedicionBase(float t_medicion);
        MedicionBase(const MedicionBase& other);
        float getTiempo();
        virtual void imprimir() = 0;
};
class Presion : public MedicionBase {
    public:
        float presionEstatica; //p
        float presionDinamica; //q
        Presion(float p, float q, float t);
        Presion(const Presion& other);
        void imprimir() override;
        void serializar(ofstream&) override;
        void deserializar(ifstream&) override;
};
class Posicion : public MedicionBase{
    public:
        float latitud;
        float longitud;
        float altitud;
        Posicion(float lat, float lon, float alt, float t);
        Posicion(const Posicion& other);
        void imprimir() override;
        void serializar(ofstream&) override;
        void deserializar(ifstream&) override;     
};
class SaveFlightData : public IMediciones{
    public:
        unique_ptr<Posicion> posicion;
        unique_ptr<Presion> presion;
        SaveFlightData();
        SaveFlightData(const Posicion& p, const Presion& q);
        void imprimir();
        void serializar(ofstream&) override;
        void deserializar(ifstream&) override;
};