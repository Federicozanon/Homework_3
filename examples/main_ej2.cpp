#include "../include/ej2.hpp"
int main(){
    point punto(4.5,-2.4);
    circle circulo(punto.get_x(), punto.get_y(), 2);
    punto.set_coords(0, 5);
    ellipse elipse(punto.get_x(), punto.get_y(), 4, 2.0);
    punto.set_coords(-2, 0.4);
    rectangle rectangulo(punto.get_x(), punto.get_y(), 5, 10.2);
    cout<<"Area circulo: "<<ProcesadorFigura<circle>::funcion_area(circulo)<<"\n";
    cout<<"Area elipse: "<<ProcesadorFigura<ellipse>::funcion_area(elipse)<<"\n";
    cout<<"Area rectangulo: "<<ProcesadorFigura<rectangle>::funcion_area(rectangulo)<<"\n";
    //hace falta probar los setters de las clases
}