#include "../include/ej2.hpp"

point::point(double x, double y) : x_cord(x), y_cord(y) {}
double point::get_x() const{ 
    return x_cord; 
}
double point::get_y() const{
    return y_cord; 
}
void point::set_coords(double x, double y){
    x_cord = x; y_cord = y; 
}
circle::circle(double x, double y, double r) : point(x,y), r(r) {}
double circle::get_radius() const{
    return r;
}
void circle::set_radius(double r1){
    r=r1; 
}
ellipse::ellipse(double x, double y, double r_max, double r_min) : point(x,y), max_radius(r_max), min_radius(r_min) {}
double ellipse::get_r_max() const{
    return max_radius; 
}
double ellipse::get_r_min() const{
     return min_radius;
}
void ellipse::set_radius(double r_max, double r_min){
    max_radius=r_max; min_radius=r_min; 
}
rectangle::rectangle(double x, double y, double b, double h) : point(x,y), base(b), height(h) {}
double rectangle::get_base() const{
    return base; 
}
double rectangle::get_height() const{
    return height; 
}
void rectangle::set_lengths(double b, double h) {
    base = b; 
    height = h; 
}
template<>
double ProcesadorFigura<circle>::funcion_area(const circle& c){
    double r = c.get_radius();
    return pi*r*r;
}
template<>
double ProcesadorFigura<ellipse>::funcion_area(const ellipse& e){
    return pi*e.get_r_max()*e.get_r_min();
}
template<>
double ProcesadorFigura<rectangle>::funcion_area(const rectangle& r){
    return r.get_base()*r.get_height();
}