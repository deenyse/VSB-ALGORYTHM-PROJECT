#include "Polynomial.h"
#include <iostream>
using namespace std;

int countDigits(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        ++count;
    }
    return count;
}
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
}

Polynomial::Polynomial(double a){
    this->coefficients = new double [1];
    this->coefficients[0] = a;
    this->length = 1;
};

Polynomial::~Polynomial(){
    delete[] coefficients;
}


Polynomial*  Polynomial::draw() {
    for (int i = this->length -1; i > 1; i--) { // do not process 0 and 1 - unneccessary operation becouse lats digit dont have pow
        if (this->coefficients[i] == 0) // do not process zero coefficient
            continue;

        if (abs(this->coefficients[i]) != 1)
            for (int j = 0; j < countDigits(this->coefficients[i]); j++) // space for number
                cout << " ";

        if (i != this->length -1 || this->coefficients[i] <0) // space for sing
            cout << " ";

        cout << " " << i;
    }
    cout << endl;
    for (int i = this->length -1; i>= 0; i--) {
        if (!this->coefficients[i]) // do not process zero
            continue;

        if (this->coefficients[i] > 0 && i != this->length -1)
            cout << "+";

        if (this->coefficients[i] < 0)
            cout << "-";

        if (abs(this->coefficients[i]) != 1 || i == 0 && this->coefficients[i] != 0 )
            cout << abs(this->coefficients[i]);

        if (i != 0)
            cout << "x";

        for (int j = 0; j < countDigits(i); j++) // add space for degree
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