const double PI = 3.141592653589793238462643383279;
pair<double, double> rotate_point(double cx, double cy, double base_x, double base_y, double theta) {
    complex<double> comp(cx - base_x, cy - base_y);
    comp *= exp(complex<double>(.0, theta * PI / 180.0));
    return make_pair(comp.real() + base_x, comp.imag() + base_y);
}