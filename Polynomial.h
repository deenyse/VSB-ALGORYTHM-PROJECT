#ifndef ALGORYTHM_PROJECT_POLYNOMIAL_H
#define ALGORYTHM_PROJECT_POLYNOMIAL_H

class Polynomial {
private:
    double* coefficients;
    int degree;
    int length;
public:
    Polynomial(double * coefficients, int length);
    Polynomial(double a);
    ~Polynomial();
    double *getCoefficients() {return coefficients;}
    int getDegree() {return degree;}
    virtual Polynomial* draw();
    int countDegree();
    long double value(double x);
};


#endif //ALGORYTHM_PROJECT_POLYNOMIAL_H
