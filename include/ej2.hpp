using namespace std;
#include <iostream>
constexpr double pi = 3.14159265358979323846;
class point {
    private:
        double x_cord, y_cord;
    public:
        point(double x, double y);
        double get_x() const;
        double get_y() const;
        void set_coords(double x, double y);
};
class circle: public point {
    private:
        double r;
    public:
        circle(double x, double y, double r);
        double get_radius() const;
        void set_radius(double r1);
};
class ellipse : public point{
    private:
        double max_radius, min_radius;
    public:
        ellipse(double x, double y, double r_max, double r_min);
        double get_r_max() const;
        double get_r_min() const;
        void set_radius(double r_max, double r_min);
};
class rectangle : public point{
    private:
        double base, height;
    public:
        rectangle(double x, double y, double b, double h);
        double get_base() const;
        double get_height() const;
        void set_lengths(double b, double h);
};
template<typename T>
class ProcesadorFigura {
    public:
        static double funcion_area(const T& figure);
};