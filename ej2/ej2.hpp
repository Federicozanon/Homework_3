
static constexpr double pi = 3.14159265358979323846;
class point {
    private:
        double x_cord, y_cord;
    public:
        point(double x, double y) : x_cord(x), y_cord(y) {}
        double get_x() const { return x_cord; }
        double get_y() const { return y_cord; }
        void set_coords(double x, double y){ x_cord = x; y_cord = y; }
};
class circle: public point {
    private:
        double r;
    public:
        circle(double x, double y, double r) : point(x,y), r(r) {}
        double get_radius() const { return r; }
        void set_radius(double r1) { r=r1; }
};
class ellipse : public point{
    private:
        double max_radius, min_radius;
    public:
        ellipse(double x, double y, double r_max, double r_min) : point(x,y), max_radius(r_max), min_radius(r_min) {}
        double get_r_max() const { return max_radius; }
        double get_r_min() const { return min_radius; }
        void set_radius(double r_max, double r_min) { max_radius=r_max; min_radius=r_min; }
};
class rectangle : public point{
    private:
        double base, height;
    public:
        rectangle(double x, double y, double b, double h) : point(x,y), base(b), height(h) {}
        double get_base() const { return base; }
        double get_height() const { return height; }
        void set_lengths(double b, double h) { base = b; height = h; }
};
template<typename T>
class ProcesadorFigura {
    public:
        double funcion_area(const T& figure);
        
};
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