
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <string>

using namespace std;

class Polynomial {

 private:
  int degree;
  double* coeff[];

 public:
  Polynomial (int degree. double* coeff[]): degree(getDegree), coeff(getCoeff){}
  double evalAt(double coeff[], int degree, double eval);
  void toString(double coeff[], int degree, string &result);
  bool findZeros(double coeff[], int degree, double out[]);
  const int getDegree();
  const double getCoeff(int degree);
  void setCoeff(int Deg, double newCoeff);
  Polynomial operator == (const Polynomial & other);
  Polynomial operator != (const Polynomial & other);
};

#endif

