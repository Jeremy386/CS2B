/*
Jeremy Satterfield
CS 2B
Foothill 1/19/2013
Mr. Harden
Assignment A1


***CLASS INVARIANT:
   There are two data members in this class.  Numerator and denominator.  
   Fractions are always stored as an improper fraction in is simpliest form.
   Fractions with a numerator of 0 will have their denominator set to 1.  
   Fractions entered with a negative denominator will have the negative symbol
   moved to the numerator.
*/


#include <iostream>
#include "fraction.h"
using namespace std;




fraction::fraction(int inNumerator, int inDenominator)
{
    numerator = inNumerator;
    denominator = inDenominator;
    reduce();
}










/*
  Pre: An object is ready for output.
  Post: The calling object is displayed as a Whole number, proper fraction, or a
  mixed fraction.  Mixed fractions have their whole number seperated by a '+'.
*/

ostream& operator<<(ostream& out, const fraction& right)
{
    if (right.denominator == 1){
        out << right.numerator;
    } else  if (abs(right.numerator) < right.denominator){
        out << right.numerator << "/" << right.denominator;
    } else {
        out << right.numerator/right.denominator << "+" <<
            (abs(right.numerator % right.denominator)) << "/" <<
            right.denominator;
    }

    return out;
}










/*
  Pre: An object is ready to read in.
  Post: First we peek at the first character to determine if the fraction being
  read in is negative or not.  First numbers read in are assumed to be the
  numerator unless through the in.peek() we find a '+', then the read in value
  is assigned to wholeNumer.  Continues reading in for the numerator untill a
  '/' is found.  This ends the numerator read in, then following numbers read
  in are assigned to the denominator.  Mixed fractions are converted to
  improper fractions and reduced.
*/

istream& operator>>(istream& in, fraction &fractionRead)
{
    int wholeNumber;
    int posOrNeg = 1;
    
        
    if (in.peek() == '-'){
        posOrNeg = -1;
        in.ignore();
    }
    
    in >> fractionRead.numerator;
    
    if (in.peek() == '+'){
        wholeNumber = fractionRead.numerator;
        in.ignore();
        in >> fractionRead.numerator;
    }
    
    if (in.peek() == '/'){
        in.ignore();
        in >> fractionRead.denominator;
    } else {
           fractionRead.denominator = 1;
    }
    
    fractionRead.numerator = posOrNeg * (wholeNumber * fractionRead.denominator + fractionRead.numerator); 
    
    fractionRead.reduce();
    return in;
}










/*
  Post:  The calling object is reduced to it's most reduced fractoin.  
  Any negative denominators have their negative sign moved to the denominator.
  Any calling object with a numerator of 0 has it's denominator changed to a 
  1.  Fractions get reduced by determining the Greatest Common Factor, and 
  dividing both the numerator and denominator by the gcf.
*/

void fraction::reduce()
{
    int gcf;

    if (denominator < 0){
        denominator = denominator * -1;
        numerator = numerator * -1;
    }
        
    if (numerator == 0){
       denominator = 1;
    }

    gcf = abs(numerator);

    while ( gcf > 0 && ((numerator % gcf !=0) || (denominator % gcf !=0))) {
        gcf--;
    }

    if (gcf > 0){
        numerator /= gcf;
        denominator /= gcf;
    }   
}











fraction operator+(const fraction &left, const fraction &right)
{
    fraction sum;

    sum.numerator = ((left.numerator * right.denominator) + (right.numerator * left.denominator));
    sum.denominator = (left.denominator * right.denominator);
    sum.reduce();

    return sum;
}










fraction operator-(const fraction &left, const fraction &right)
{
    fraction difference;

    difference.numerator = ((left.numerator * right.denominator) - (right.numerator * left.denominator));
    difference.denominator = (left.denominator * right.denominator);
    difference.reduce();

    return difference;
}











fraction operator*(const fraction &left, const fraction &right)
{
    fraction product;

    product.numerator = (left.numerator * right.numerator);
    product.denominator = (left.denominator * right.denominator);
    product.reduce();

    return product;
}











fraction operator/(const fraction &left, const fraction &right)
{
    fraction quotient;

    quotient.numerator = (left.numerator * right.denominator);
    quotient.denominator = (left.denominator * right.numerator);
    quotient.reduce();

    return quotient;
}












fraction fraction::operator+=(const fraction &right)
{
    *this = *this + right;

    return *this;
}











fraction fraction::operator-=(const fraction &right)
{
    *this = *this - right;

    return *this;
}












fraction fraction::operator*=(const fraction &right)
{
    *this = *this * right;

    return *this;
}












fraction fraction::operator/=(const fraction &right)
{
    *this = *this / right;

    return *this;
}











fraction fraction::operator++()
{
    numerator = numerator + denominator;
    return *this;
}












fraction fraction::operator++(int)
{
    fraction temp(numerator, denominator);
    numerator = numerator + denominator;
    return temp;
}












fraction fraction::operator--()
{
    numerator = numerator - denominator;
    return *this;
}












fraction fraction::operator--(int)
{
    fraction temp(numerator, denominator);
    numerator = numerator - denominator;
    return temp;
}    
    











bool operator<(const fraction &left, const fraction &right)
{
    return (left.numerator * right.denominator) < (right.numerator * left.denominator);
}












bool operator>(const fraction &left, const fraction &right)
{
    return operator<(right, left);
}












bool operator==(const fraction &left, const fraction &right)
{
    return (left.numerator * right.denominator) == (right.numerator * left.denominator);
}












bool operator!=(const fraction &left, const fraction &right)
{
    return !operator==(left, right);
}












bool operator<=(const fraction &left, const fraction &right)
{
    return !operator>(left, right);
}












bool operator>=(const fraction &left, const fraction &right)
{
    return !operator<(left, right);
}


