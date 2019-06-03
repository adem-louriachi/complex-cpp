#include "complex.h"

#include <math.h>

using namespace std;

Complex::Complex(const double &a, const double &b, const bool &polaire) {
    if (polaire) {
        this->ro = a;
        this->theta = b;

        this->a = this->ro * cos(this->theta);
        this->b = this->ro * sin(this->theta);
    } else {
        this->a = a;
        this->b = b;

        this->ro = sqrt(pow(a, 2) + pow(b, 2));

        this->theta = this->a >= 0 ? asin(this->b / this->ro) : this->theta = M_PI - asin(this->b / this->ro);

        this->theta = isnan(this->theta) ? 0 : this->theta;
    }
}

Complex Complex::operator*(const Complex &c) {
    return Complex(a * c.a - b * c.b, b * c.a + c.b * a);
}

Complex Complex::operator/(const Complex &c) {
    double denominateur = pow(c.a, 2) - pow(c.b, 2) + 2 * c.a * c.b;

    if (denominateur == 0) throw runtime_error("Division par 0");

    return Complex((a * c.a - b * c.b) / denominateur, (a * c.b + c.a * b) / denominateur);
}

Complex Complex::operator+(const Complex &c) {
    return Complex(a + c.a, b + c.b);
}

Complex Complex::operator-(const Complex &c) {
    return Complex(a - c.a, b - c.b);
}

bool Complex::operator==(const Complex &c) {
    return a == c.a && b == c.b;
}

void Complex::display(std::ostream &stream) {
    stream << "Complexe: a: " << a << " b: " << b << " ro: " << ro << "  theta: " << theta << endl;
}
