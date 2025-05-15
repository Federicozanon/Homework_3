using namespace std;
#include <utility> //para pair
static constexpr double pi = 3.14159265358979323846;
#include <type_traits>
//SE PUEDE USAR PAIR?
//IMPLEMENTACION DE POINT EN LAS CLASES SIGUIENTES
//IMPLEMENTACION DE OTRAS CLASES EN SUBCLASES
class point {
    private:
        pair<double, double> coords;
    public:
        point(double x, double y) : coords(x,y) {}
        const pair<double, double>  &get_coords() const { return coords; }
        void set_coords(double x1, double y1){ coords.first=x1; coords.second=y1; }
};
class circle: public point {
    private:
        double r;
    public:
        circle(double x, double y, double r) : point(x,y), r(r) {}
        const double &get_radius() const { return r; }
        void set_radius(double r1) { r=r1; }
};
class ellipse : public point{
    private:
        pair<double, double> r_maxmin;
    public:
        ellipse(double x, double y, double r_max, double r_min) : point(x,y), r_maxmin(r_max, r_min) {}
        const pair<double, double> &get_radiuss() const {return r_maxmin; }
        void set_radius(double r_max, double r_min) { r_maxmin.first=r_max; r_maxmin.second=r_min; }
};
class rectangle : public point{
    private:
        pair<double, double> base_height;
    public:
        rectangle(double x, double y, double base, double height) : point(x,y), base_height(base, height) {}
        const pair<double, double> &get_base_height() const {return base_height; }
        void set_lengths(double r_max, double r_min) { base_height.first=r_max; base_height.second=r_min; }
};
template<typename T>
class ProcesadorFigura {
    public:
    double funcion_area(const T& t){
        if constexpr(is_same_v(T, circle)){
            double r = t.get_radius();
            return pi*r*r;
        }
        if constexpr(is_same_v(T, ellipse)){
            pair<double, double> rs=t.get_radiuss();
            return pi*rs.first*rs.second;
        }
        if constexpr(is_same_v(T, rectangle)){
            pair<double, double> bh=t.get_base_height();
            return bh.first*bh.second;
        }
        else{
            return 0;
        }
   }
};