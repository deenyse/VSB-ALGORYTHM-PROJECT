#ifndef ALGORYTHM_PROJECT_POLYNOMIAL_H
#define ALGORYTHM_PROJECT_POLYNOMIAL_H


class Polynomial {
private:
    double* coefficients;
    int length;
public:
    Polynomial(double * coefficients, int length);
    ~Polynomial();
    double *getCoefficients() {return coefficients;}
    int getLength() {return length;}
    void draw();
    int degree() {return length -1;}
    long double value(double x);

};


#endif //ALGORYTHM_PROJECT_POLYNOMIAL_H
