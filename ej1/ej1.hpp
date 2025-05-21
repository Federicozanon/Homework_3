using namespace std;
#include <iostream>
#include <fstream> //chequar si es necesario
#include <memory>

class IMediciones {
    public:
        virtual void serializar(ofstream&) = 0;
        virtual void deserializar(ifstream&) = 0; //deberia estar con ifstream y no con ofstream como esta en el enunciado
};

class MedicionBase : public IMediciones {
    protected:
        unique_ptr<float> tiempoMedicion; //t
    public:
        MedicionBase(float t_medicion);// : tiempoMedicion(make_unique<float>(t_medicion)) {};
        float getTiempo();
        virtual void imprimir() = 0;

        virtual unique_ptr<MedicionBase> copiar() const = 0;
};
class Presion : public MedicionBase {
    public:
        float presionEstatica; //p
        float presionDinamica; //q
        Presion(float p, float q, float t);// : presionEstatica(p), presionDinamica(q), MedicionBase(&t) {};
        void imprimir() override;
        void serializar(ofstream&) override;
        void deserializar(ifstream&) override;

        unique_ptr<MedicionBase> copiar() const override;
};
class Posicion : public MedicionBase{
    public:
        float latitud;
        float longitud;
        float altitud;
        Posicion(float lat, float lon, float alt, float t);// : latitud(lat), longitud(lon), altitud(alt), MedicionBase(&t) {};   
        void imprimir() override;
        void serializar(ofstream&) override;
        void deserializar(ifstream&) override;     

        unique_ptr<MedicionBase> copiar() const override;
};
class SaveFlightData : public IMediciones{
    public:
        Posicion posicion; //puntero a objeto?
        Presion presion; //puntero a objeto?
        SaveFlightData(const Posicion& p, const Presion& q);//: posicion(p), presion(q) {};
        void imprimir();
        void serializar(ofstream&) override;
        void deserializar(ifstream&) override;
};