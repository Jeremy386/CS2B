
#include <iostream>
#include "fraction.h"
#include <fstream>
#include <cassert>
using namespace std;

void BasicTest();
void RelationTest();
void BinaryMathTest();
void MathAssignTest();
bool eof(ifstream& in);


int main()
{
    BasicTest();
    RelationTest();
    BinaryMathTest();
    MathAssignTest();
    
    system("pause");
    
}





void BasicTest()
{
    cout << "\n----- Testing basic fraction creation & printing\n";
    cout << "(fractions should be in reduced form, and as mixed numbers.)\n";
    
    const fraction fr[] = {fraction(4, 8), fraction(-15,21), 
                           fraction(10), fraction(12, -3),
                           fraction(), fraction(28, 6), fraction(0, 12)};
                                                   
    for (int i = 0; i < 7; i++){
        cout << "fraction [" << i <<"] = " << fr[i] << endl;
    }
        
        
    cout << "\n----- Now reading fractions from file\n";
    ifstream in("fraction.txt");
    assert(in);
    while (!eof(in)) {
        fraction f;     
        if (in.peek() == '#') {   
            in.ignore(128, '\n');                       //skip this line, it's a comment
        } else {
            in >> f;
            cout << "Read fraction = " << f << endl;
        }
    }
}


bool eof(ifstream& in)
{
	char ch;
	in >> ch;
	in.putback(ch);
	return !in;
}






void RelationTest()
{
    cout << "\n----- Testing relational operators between fractions\n";

    const fraction fr[] =  {fraction(3, 6), fraction(1,2), fraction(-15,30), 
                            fraction(1,10), fraction(0,1), fraction(0,2)};

    for (int i = 0; i < 5; i++) {
          cout << "Comparing " << fr[i] << " to " << fr[i+1] << endl;
          cout << "\tIs left < right? " << (fr[i] < fr[i+1]) << endl;
          cout << "\tIs left <= right? " << (fr[i] <= fr[i+1]) << endl;
          cout << "\tIs left > right? " << (fr[i] > fr[i+1]) << endl;
          cout << "\tIs left >= right? " << (fr[i] >= fr[i+1]) << endl;
          cout << "\tDoes left == right? " << (fr[i] == fr[i+1]) << endl;
          cout << "\tDoes left != right ? " << (fr[i] != fr[i+1]) << endl;
    }
 
    cout << "\n----- Testing relations between fractions and integers\n";
    fraction f(-3,6);
    int num = 2;
    cout << "Comparing " << f << " to " << num << endl;
    cout << "\tIs left < right? " << (f < num) << endl;
    cout << "\tIs left <= right? " << (f <= num) << endl;
    cout << "\tIs left > right? " << (f > num) << endl;
    cout << "\tIs left >= right? " << (f >= num) << endl;
    cout << "\tDoes left == right? " << (f == num) << endl;
    cout << "\tDoes left != right ? " << (f != num) << endl;
    
    fraction g(1,4);
    num = -3;
    cout << "Comparing " << num << " to " << g << endl;
    cout << "\tIs left < right? " << (num < g) << endl;
    cout << "\tIs left <= right? " << (num <= g) << endl;
    cout << "\tIs left > right? " << (num > g) << endl;
    cout << "\tIs left >= right? " << (num >= g) << endl;
    cout << "\tDoes left == right? " << (num == g) << endl;
    cout << "\tDoes left != right ? " << (num != g) << endl;  
}





void BinaryMathTest()
{    
    cout << "\n----- Testing binary arithmetic between fractions\n";
    
    const fraction fr[] = {fraction(1, 6), fraction(1,3), 
                           fraction(-2,3), fraction(5), fraction(-4,3)};

    for (int i = 0; i < 4; i++) {
          cout << fr[i] << " + " << fr[i+1] << " = " << fr[i] + fr[i+1] << endl;
          cout << fr[i] << " - " << fr[i+1] << " = " << fr[i] - fr[i+1] << endl;
          cout << fr[i] << " * " << fr[i+1] << " = " << fr[i] * fr[i+1] << endl;
          cout << fr[i] << " / " << fr[i+1] << " = " << fr[i] / fr[i+1] << endl;
    }

    cout << "\n----- Testing arithmetic between fractions and integers\n";
    fraction f(-1, 2);
    int num = 4;
    cout << f << " + " << num << " = " << f + num << endl;
    cout << f << " - " << num << " = " << f - num << endl;
    cout << f << " * " << num << " = " << f * num << endl;
    cout << f << " / " << num << " = " << f / num << endl;
     
    fraction g(-1, 2);
    num = 3;
    cout << num << " + " << g << " = " << num + g << endl;
    cout << num << " - " << g << " = " << num - g << endl;
    cout << num << " * " << g << " = " << num * g << endl;
    cout << num << " / " << g << " = " << num / g << endl;
}






void MathAssignTest()
{    
    cout << "\n----- Testing shorthand arithmetic assignment on fractions\n";
    
    fraction fr[] = {fraction(1, 6), fraction(4), 
                     fraction(-1,2), fraction(5)};

    for (int i = 0; i < 3; i++) {
          cout << fr[i] << " += " << fr[i+1] << " = ";
          cout << (fr[i] += fr[i+1]) << endl;
          cout << fr[i] << " -= " << fr[i+1] << " = ";
          cout << (fr[i] -= fr[i+1]) << endl;
          cout << fr[i] << " *= " << fr[i+1] << " = ";
          cout << (fr[i] *= fr[i+1]) << endl;
          cout << fr[i] << " /= " << fr[i+1] << " = ";
          cout << (fr[i] /= fr[i+1]) << endl;
    }
   
    cout << "\n----- Testing shorthand arithmetic assignment using integers\n";
    fraction f(-1, 3);
    int num = 3;
    cout << f << " += " << num << " = ";
    cout << (f += num) << endl;
    cout << f << " -= " << num << " = ";
    cout << (f -= num) << endl;
    cout << f << " *= " << num << " = ";
    cout << (f *= num) << endl;
    cout << f << " /= " << num << " = ";
    cout << (f /= num) << endl;

    cout << "\n----- Testing increment/decrement prefix and postfix\n";
    fraction g(-1, 3);
    cout << "Now g = " << g << endl;
    cout << "g++ = " << g++ << endl;
    cout << "Now g = " << g << endl;
    cout << "++g = " << ++g << endl;
    cout << "Now g = " << g << endl;
    cout << "g-- = " << g-- << endl;
    cout << "Now g = " << g << endl;
    cout << "--g = " << --g << endl;
    cout << "Now g = " << g << endl;
}




