#include <iostream>
#include "Polynomial.h"
#include "algorithm"
using namespace std;

Polynomial * sumPolynomial(Polynomial* a, Polynomial* b){
    double * biggerPolynonm = new double[max(a->getLength(), b->getLength())]();

    for (int i = 0; i < min(a->getLength(), b->getLength()); i++)
        biggerPolynonm[i] = a->getCoefficients()[i] + b->getCoefficients()[i];

    if (a->getLength() > b->getLength())
        for (int i = b->getLength(); i < a->getLength(); i++)
            biggerPolynonm[i] = a->getCoefficients()[i];

    if (b->getLength() > a->getLength())
        for (int i = a->getLength(); i < b->getLength(); i++)
             biggerPolynonm[i] = b->getCoefficients()[i];

    return new Polynomial(biggerPolynonm, max(a->getLength(), b->getLength()));
}

Polynomial * diffPolynomial(Polynomial* a, Polynomial* b){
    double * biggerPolynonm = new double[max(a->getLength(), b->getLength())]();

    for (int i = 0; i < min(a->getLength(), b->getLength()); i++)
        biggerPolynonm[i] = a->getCoefficients()[i] - b->getCoefficients()[i];

    if (a->getLength() > b->getLength())
        for (int i = b->getLength(); i < a->getLength(); i++)
            biggerPolynonm[i] = a->getCoefficients()[i];

    if (b->getLength() > a->getLength())
        for (int i = a->getLength(); i < b->getLength(); i++)
            biggerPolynonm[i] = - b->getCoefficients()[i];

    return new Polynomial(biggerPolynonm, max(a->getLength(), b->getLength()));
}


int main() {
    double a [12] = {1,2,0,0,1};
    Polynomial* myPolynomial = new Polynomial(a,5);
    myPolynomial->draw();
//    cout << "Degree: " << myPolynomial->degree() << endl;
//    cout << "Value: " << myPolynomial->value(2) << endl;

    double b [12] = {1,0,0,0,1};
    Polynomial* myPolynomial1 = new Polynomial(b,5);
    myPolynomial1->draw();

    auto aa = diffPolynomial(myPolynomial, myPolynomial1);
    aa->draw();

    return 0;
}