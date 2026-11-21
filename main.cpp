#include <iostream>
#include "polynomial.h"

int main(void) {
    int coeff1[] = {1, 2};
    Polynomial a(coeff1, 2);

    int coeff2[] = {5, 5, 5, 6};
    Polynomial b(coeff2, 4);

    a.Print_polynomial();
    b.Print_polynomial();

    std::cout << a.Polynomail_value(4) << "\n";
    std::cout << a.Polynomail_value(0) << "\n";

    Polynomial c = a + b;
    c.Print_polynomial();

    b = a;
    a.Print_polynomial();
    b.Print_polynomial();

    return 0;
}