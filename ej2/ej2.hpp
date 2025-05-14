using namespace std;
#include <utility>
//SE PUEDE USAR PAIR?
//IMPLEMENTACION DE POINT EN LAS CLASES SIGUIENTES
class point {
    private:
        pair<double, double> coords;
    public:
        point(double x, double y) : coords(x,y) {}
        pair<double, double> get_coords() { return coords; }
        ~point() {}
};
class circle: public point {
    private:
        double r;
    public:
        circle(double x, double y, double r) : point(x,y), r(r) {}
        pair<double, double> get_coords() { get_coords(); }
        double get_radius() { return r; }
        ~circle() {}
};
class ellipse : public point{
    private:
        pair<double, double> r_maxmin;
    public:
        ellipse(double x, double y, double r_max, double r_min) : point(x,y), r_maxmin(r_max, r_min) {}
        pair<double, double> get_coords() { get_coords(); }
        pair<double, double> get_radiuss() {return r_maxmin; }
        ~ellipse() {}

};
class rectangle : public point{
    private:
        pair<double, double> base_height;
    public:
        rectangle(double x, double y, double base, double height) : point(x,y), base_height(base, height) {}
        pair<double, double> get_corner() { get_coords(); }
        pair<double, double> get_base_height() {return base_height; }
};
class ProcesadorFigura {

};