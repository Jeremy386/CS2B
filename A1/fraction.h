/*
Jeremy Satterfield
CS 2B
Foothill 1/19/2013
Mr. Harden
Assignment A1

*** File: fraction.h

*** The fraction class can be used to show the ratios of two numbers, in the
    form of a proper fraction with a numerator and denominator, and a mixed 
    fraction with a whole number, numerator and denominator.  All the 
    basic arithmetic operations, shorthand arithmetic operations, the 
    increment and decrement operations, and all relation operations.  The class
    provides as well a stream extraction and stream insertion operations.

* Constructor. Creates a fraction with a Numerator of inNumerator, and a 
* Denominator of inDenominator.

fraction(int inNumerator=0, int inDenominator=1);




* Pre: Object is ready to be output.
* Post: The calling object is displayed as a Whole number, proper fraction, or a
  mixed fraction.  Mixed fractions have their whole number seperated by a '+'.

        
friend ostream& operator<<(ostream& out, const fraction &right);

* Pre: An object is ready to read in.
* Post: First we peek at the first character to determine if the fraction being
  read in is negative or not.  First numbers read in are assumed to be the
  numerator unless through the in.peek() we find a '+', then the read in value
  is assigned to wholeNumer.  Continues reading in for the numerator untill a
  '/' is found.  This ends the numerator read in, then following numbers read
  in are assigned to the denominator.  Mixed fractions are converted to
  improper fractions and reduced.



* Returns the sum of the left and right fractions in a reduced from.

friend istream& operator>>(istream& in, fraction &fractionRead);



friend fraction operator+(const fraction &left, const fraction &right);

* Returns the difference of the left and right fractions in a reduced form.



friend fraction operator-(const fraction &left, const fraction &right);



* Returns the product of the left and right fractions in a reduced from.

friend fraction operator*(const fraction &left, const fraction &right);



* Returns the quotient of the left and right fractions in a reduced form.

friend fraction operator/(const fraction &left, const fraction &right);



* Returns the sum of the itself plus right in a reduced form.

fraction operator+=(const fraction &right);



* Returns the difference of the calling object and the value of right.

fraction operator -=(const fraction &right);



* Returns the product of the calling object and the value of right.

fraction operator*=(const fraction &right);



* Returns the quotient of the calling object and the value of right.

fraction operator/=(const fraction &right);



* Returns the calling object plus one.

fraction operator++();



* Returns the calling object, then adds one to the calling object.

fraction operator++(int);



* Returns the calling object minus one.

fraction operator--();



* Returns the calling object, then subtracts one from the calling object.

fraction operator--(int);



* Returns true if left is less than right.  False if not.

friend bool operator<(const fraction &left, const fraction &right);



* Returns true if left is more than right.  False if not.

friend bool operator>(const fraction &left, const fraction &right);



* Returns true if left is equal to right.  False if not.

friend bool operator==(const fraction &left, const fraction &right);



* Returns true if left does not equal right.  False if not.

friend bool operator!=(const fraction &left, const fraction &right);



* Returns true if left is less than or equal to right.  False if not.

friend bool operator<=(const fraction &left, const fraction &right);



* Returns true if left is greater than or equal to right.  False if not.

friend bool operator>=(const fraction &left, const fraction &right);

*/



#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;


class fraction {
      public:
             fraction(int inNumerator=0, int inDenominator=1);
             friend ostream& operator<<(ostream& out, const fraction &right);
             friend istream& operator>>(istream& in, fraction &fractionRead);
             friend fraction operator+(const fraction &left, const fraction &right);
             friend fraction operator-(const fraction &left, const fraction &right);
             friend fraction operator*(const fraction &left, const fraction &right);
             friend fraction operator/(const fraction &left, const fraction &right);
             fraction operator+=(const fraction &right);
             fraction operator-=(const fraction &right);
             fraction operator*=(const fraction &right);
             fraction operator/=(const fraction &right);
             fraction operator++();
             fraction operator++(int);
             fraction operator--();
             fraction operator--(int);
             friend bool operator<(const fraction &left, const fraction &right);
             friend bool operator>(const fraction &left, const fraction &right);
             friend bool operator==(const fraction &left, const fraction &right);
             friend bool operator!=(const fraction &left, const fraction &right);
             friend bool operator<=(const fraction &left, const fraction &right);
             friend bool operator>=(const fraction &left, const fraction &right);


      private:
              int numerator;
              int denominator;
              void reduce();
};

#endif



