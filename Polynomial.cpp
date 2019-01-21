#include "Polynomial.h"
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

Polynomial::Polynomial (int theDegree, double* theArray[])
// : degree(theDegree) , coeff(theArray) {
{
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
bool Polynomial:: findZeros(double coeff[] , int degree, double out[]) {

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
  degree = getDegree();
  double temp;
  temp = coeff[degree];
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
}

  Polynomial Polynomial::operator!=(const Polynomial & other) {
    if(this -> degree == other.getDegree())// checks to see if "this" degree equals to passed deg\
ree
      if(this -> coeff[degree] == other.getDegree())
        return false;
  }

int main(void) {
	double c0[] = {2};
	Polynomial p0(0, c0);

	double c1[] = {3, -5};
	Polynomial p1(1, c1);

	double c2[] = {4, -7, 8};
	Polynomial p2(2, c2);

	double c5[] = {4,-6,12,-23,45,16};
	Polynomial p5(5, c5);

	cout << "==========\n";
	string p0Str;
	p0.toString(p0Str);
	cout << p0Str << " is the polynomial." << endl;
	cout << "At x=3, it is: " << p0.evalAt(3) << endl;

	cout << "==========\n";
	string p1Str;
	p1.toString(p1Str);
	cout << p1Str << " is the polynomial." << endl;
	cout << "At x=3, it is: " << p1.evalAt(3) << endl;

	cout << "==========\n";
	string p2Str;
	p2.toString(p2Str);
	cout << p2Str << " is the polynomial." << endl;
	cout << "At x=3, it is: " << p2.evalAt(3) << endl;

	cout << "==========\n";
	string p5Str;
	p5.toString(p5Str);
	cout << p5Str << " is the polynomial." << endl;
	cout << "At x=3, it is: " << p5.evalAt(3) << endl;

	cout << "==========\n";
	double cAnother[] = {4, -7, 8};
	Polynomial another(2, cAnother);
	
	string anotherStr;
	another.toString(anotherStr);
	
	cout << anotherStr << " == " << p5Str << ": " << (another == p5) << endl;
	cout << anotherStr << " != " << p5Str << ": " << (another != p5) << endl;
	cout << anotherStr << " == " << p2Str << ": " << (another == p2) << endl;
	cout << anotherStr << " != " << p2Str << ": " << (another != p2) << endl;
	
	cout << "==========\n";
	double c6[] = {2, 4, 1};
	Polynomial p6(2, c6);
	string p6Str;
	p6.toString(p6Str);
	cout << p6Str << " is the polynomial." << endl;
	
	double zeroes[2];
	p6.findZeroes(zeroes);
	cout << "The zeroes are " << zeroes[0] << " and " << zeroes[1] << endl;
	
	cout << "The degree is " << p6.getDegree() << "." << endl;
	cout << "The coefficient of x^2 is " << p6.getCoeff(2) << "." << endl;
	p6.setCoeff(2, 99);
	p6.toString(p6Str);
	cout << "After changing the coefficient of x^2, it is " << p6.getCoeff(2) << ", and the entire polynomial is " << p6Str << endl;

	return 0;
}
    
    
