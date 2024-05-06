#include <iostream>
#include "Polynomial.h"
#include "algorithm"
using namespace std;

Polynomial * sumPolynomial(Polynomial* a, Polynomial* b){
    double * biggerPolynonm = new double[max(a->getDegree(), b->getDegree()) + 1]();

    for (int i = 0; i < min(a->getDegree(), b->getDegree()) + 1; i++) //get sum to end of smaller polynomial
        biggerPolynonm[i] = a->getCoefficients()[i] + b->getCoefficients()[i];

    if (a->getDegree() > b->getDegree()) // rewrite bigger
        for (int i = b->getDegree() + 1; i < a->getDegree() + 1; i++)
            biggerPolynonm[i] = a->getCoefficients()[i];

    if (b->getDegree() > a->getDegree()) // rewrite bigger
        for (int i = a->getDegree() + 1; i < b->getDegree() + 1; i++)
             biggerPolynonm[i] = b->getCoefficients()[i];

    return new Polynomial(biggerPolynonm, max(a->getDegree(), b->getDegree()) + 1);
}

Polynomial * diffPolynomial(Polynomial* a, Polynomial* b){
    double * biggerPolynonm = new double[max(a->getDegree(), b->getDegree()) + 1]();

    for (int i = 0; i < min(a->getDegree(), b->getDegree()) + 1; i++) // get diff to end of smaller polynomial
        biggerPolynonm[i] = a->getCoefficients()[i] - b->getCoefficients()[i];

    if (a->getDegree() > b->getDegree())
        for (int i = b->getDegree() + 1; i < a->getDegree() + 1; i++)
            biggerPolynonm[i] = a->getCoefficients()[i];

    if (b->getDegree() > a->getDegree())
        for (int i = a->getDegree() + 1; i < b->getDegree() + 1; i++)
            biggerPolynonm[i] = - b->getCoefficients()[i];

    return new Polynomial(biggerPolynonm, max(a->getDegree(), b->getDegree()) + 1);
}

Polynomial * multiplyPolynomial(Polynomial *a, Polynomial*b){
    double* coefficients = new double[a->getDegree() + b->getDegree() + 1](); // +1 to add place for 0 degree

    for (int i = 0; i <= a->getDegree(); i++)
        for (int j = 0; j <= b->getDegree(); j++)
            coefficients[i+j] += a->getCoefficients()[i] * b->getCoefficients()[j];

    return new Polynomial(coefficients, a->getDegree() + b->getDegree() + 1);
}

Polynomial * derivatePolynomial(Polynomial *a){
    double* coefficients = new double[a->getDegree()]; // np +1 because highest degree will decrement

    for (int i = 1; i <= a->getDegree(); i++)
        coefficients[i-1] = a->getCoefficients()[i] * i;

    return new Polynomial(coefficients, a->getDegree());
}

Polynomial * integratePolynomial(Polynomial *a){
    double* coefficients = new double[a->getDegree() +2](); // + 1 for zero degree and +1 for new biggest degree

    for (int i = 0; i <= a->getDegree()+1; i++)
        coefficients[i+1] = a->getCoefficients()[i] / (i + 1);

    return new Polynomial(coefficients, a->getDegree()+2);
}

int main() {
    double a [] = {0,2,-0.5,0};
    Polynomial* myPolynomial = new Polynomial(a,4);
    cout << "First Polynomial" << endl;
    myPolynomial->draw();
    cout << "Value of first polynomial at point 3 is: " << myPolynomial->value(3) << endl;
    cout << "Degree of first polynomial is: " << myPolynomial->getDegree() << endl;

    double b[12] = {-1,0,1,0,0,2};
    Polynomial* myPolynomial1 = new Polynomial(b,6);
    cout << "Second Polynomial" << endl;
    myPolynomial1->draw();

    cout << "Difference betwen second and first polynomials is:" << endl;
    Polynomial* aa = diffPolynomial(myPolynomial1, myPolynomial)->draw();

    cout << "Sum between difference and first polynomial is:" << endl;
    sumPolynomial(aa, myPolynomial)->draw();

    cout << "Third Polynomial (created by 1 number)" << endl;
    Polynomial* myPolynomial2 = new Polynomial(4);
    myPolynomial2->draw();

    cout << "Multiplication of third and first polynomials is:" << endl;
    Polynomial* bb = multiplyPolynomial(myPolynomial, myPolynomial2)->draw();

    cout << "Multiplication of second and first polynomials is:" << endl;
    Polynomial* cc = multiplyPolynomial(myPolynomial1, myPolynomial)->draw();

    cout << "Derivation of second polinomial" << endl;
    Polynomial* dd = derivatePolynomial(myPolynomial1)->draw();

    cout << "One of many Integrations of derivation of second polinomial" << endl;
    Polynomial* ee = integratePolynomial(dd)->draw();

    return 0;
}