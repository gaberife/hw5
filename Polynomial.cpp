#include <iostream>
#include <string>
#include <cmath>
using namespace std;

Polynomial::Polynomial (int theDegree, double* theArray[])
  : degree(theDegree) , coeff(theArray) {
}



double Polynomial:: evalAt(double coeff[], int degree, double eval) {
  double sum;
  double hold;
  for( int i = 0 ; i < degree + 1; i++) {
    hold = pow(eval , i);
    sum += (hold * coeff[i]);
  }
  cout<< "The sum is " << sum<<endl;
  return sum;
}
void Polynomial:: toString(double coeff[], int degree, string & result){
  stringstream s;

  for(int i = degree; i >= 0; i--) {
    s << coeff[i] << "x^" << i;
    if (i > 0)
      s << " + ";
  }

  result = s.str();
}
const  bool Polynomial:: findZeros(double coeff[] , int degree, double out[]) {

  double hold = 0;
  if( degree == 2) {
    double c = coeff[0];
    double b = coeff[1];
    double a = coeff[2];
    hold =( (-b) + sqrt(( b*b) - 4*(a * c))) / 2 * a;
    out[0] = hold;
    hold = ( (-b) - sqrt((b*b) - 4*(a * c))) / 2 * a;
    out[1] = hold;
    return true;
  }
  else if ( degree == 1) {
    double a = coeff[1];
    double b = coeff[0];
    double zero = (-b/a);
    out[0] = zero;
    cout <<out[0]<<endl;
    return true;
  }
  return false;
}

const int Polynomial::getDegree() {
  return degree;

}

const double Polynomial::getCoeff(int degree) {
  double temp;
 temp =  coeff[degree];
 return temp;
}

void Polynomial::setCoeff(int Deg, double newCoeff) {
  coeff[Deg] = newCoeff;

}
Polynomial Polynomial::operator==(const Polynomial & other) {
  if(this->degree == other.getDegree()){
    if(this -> coeff[degree] == other.getDegree())
      return true;
  }

    Polynomial Polynomial::operator!=(const Polynomial & other) {
      if(this -> degree == other.getDegree())// checks to see if "this" degree equals to passed degree
        if(this -> coeff[degree] == other.getDegree())
          return false;



  }
