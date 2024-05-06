#include "Polynomial.h"
#include <iostream>
using namespace std;

double pows(double base, int exponent) {
    if (exponent == 0)
        return 1;

    double result = 1.0;
    for (int i = 0; i < abs(exponent); ++i) {
        result *= base;
    }

    if (exponent < 0)
        return 1.0 / result;
    else
        return result;
}


Polynomial::Polynomial(double * coefficients, int length){
    this->coefficients = coefficients;
    this->length = length;
    this->degree = this->countDegree();
}

Polynomial::Polynomial(double a){
    this->coefficients = new double [1];
    this->coefficients[0] = a;
    this->length = 1;
    this->degree = 0;
};


Polynomial::~Polynomial(){
    delete[] this->coefficients;
}

Polynomial*  Polynomial::draw() {
    for (int i = this->length -1; i>= 0; i--) {
        if (!this->coefficients[i]) // do not process zero
            continue;

        if (this->coefficients[i] > 0 && i != this->getDegree())
            cout << "+";

        if (this->coefficients[i] < 0)
            cout << "-";

        if (abs(this->coefficients[i]) != 1 || i == 0 && this->coefficients[i] != 0 )
            cout << abs(this->coefficients[i]);

        if (i != 0)
            cout << "x";
        if (abs(i) != 1 && i != 0 )
            cout << "^" << i;

        cout << " ";

    }


    cout << endl;
    return this;
}

long double Polynomial::value(double x) {
    long double acc = 0;

    for (int i = 0; i < length; i++){
        acc += this->coefficients[i] * pows(x,i);
    }

    return acc;
}

int Polynomial::countDegree(){
    int i = this->length -1;
    while (this->coefficients[i] == 0 && i > 0)
        --i;

    return i;
}