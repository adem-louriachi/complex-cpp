#include <iostream>
#include "complex.h"

#include "math.h"

using namespace std;

int main() {

    Complex c1(1, 2);

    c1.display(cout);

    Complex c2(3, M_PI, true);

    c2.display(cout);

    Complex c;

    c.display(cout);

    (c1 * c2).display(cout);

    try {
        (c2 / c).display(cout);
    } catch (runtime_error e) {
        cerr << e.what() << endl;
    }

    cout << (c2 == c ? "c2 == c" : "c2 != c") << endl;

    return 0;
}
