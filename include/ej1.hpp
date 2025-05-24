using namespace std;
#include <iostream>
#include <fstream> //chequar si es necesario
#include <memory>

class IMediciones {
    public:
        virtual void serializar(ofstream&) = 0;
        virtual void deserializar(ifstream&) = 0;
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
        //prototype interface metodo virtual de copiar
        //virtual unique_ptr<MedicionBase> copiar() const = 0;
        ~MedicionBase() = default;
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
        //concrete prototype. son los objetos a los que se les provee un metodo para copiar
        //unique_ptr<MedicionBase> copiar() const override;
        ~Presion() = default;
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
        //concrete prototype
        //unique_ptr<MedicionBase> copiar() const override;
        ~Posicion() = default;
};
class SaveFlightData : public IMediciones{
    public:
        unique_ptr<Posicion> posicion;
        unique_ptr<Presion> presion;
        SaveFlightData(const Posicion& p, const Presion& q);
        void imprimir();
        void serializar(ofstream&) override;
        void deserializar(ifstream&) override;
        ~SaveFlightData() = default;
};