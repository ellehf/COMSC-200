//
//  Frac.h
//  COMSC 200 - AS03
//
//  Created by Elle Hoarau on 2/20/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef Frac_h
#define Frac_h

#include <vector>
#include <sstream>
#include <iostream>
using namespace std;
 
class Frac
{
private:
    double num, den; //Holds numerator and denominator of fraction
    
    long gcd(long a, long b) //Function to find greatest common divisor
    {
        if (b == 0)
        return a;
        
        return gcd(b, a % b);
    };
    
    Frac lowterms(Frac &f)
    {
        double c = gcd(f.num, f.den); // Find gcd of both numerator and denominator
    
        f.den /= c; //Simplify fraction
        f.num /= c;
        
        return f;
    }
    
public:
    Frac() : num(0), den(1) {} //Default constructor
    Frac(int n, int d) {num=n; den=d;} //Constructor with numerator and denominator passed
    Frac(const Frac &obj) {*this = obj;} //Copy constructor
    void operator = (const Frac &rhs) {num = rhs.num; den = rhs.den;} //Assignment operator
    Frac(string s); //String to int constructor
    
    //Accessors and mutators
    void setNum(int n);
    void setDen(int d);
    int getNum();
    int getDen();
    double getFrac();
    
    operator int() {return getFrac();} //Return fraction as integer decimal
    operator double() {return getFrac();} //Return fraction as float decimal

    // math operators
    Frac operator + (const Frac &rhs);
    Frac operator - (const Frac &rhs);
    Frac operator * (const Frac &rhs);
    Frac operator / (const Frac &rhs);
    
    
    //Prefix ++ operator
    Frac operator ++ ();
    //Prefix -- operator
    Frac operator -- ();
    //Postfix ++ operator
    Frac operator ++ (int n);
    //Postfix -- operator
    Frac operator -- (int n);
    
    // comparators
    bool operator == (Frac &f2);
    bool operator != (Frac &f2);
    bool operator < (Frac &f2);
    bool operator > (Frac &f2);
    bool operator <= (Frac &f2);
    bool operator >= (Frac &f2);
    
    // overloading >> << stream operators
    friend ostream& operator<<(ostream& strm, const Frac& f);
    friend istream& operator >> (istream& strm, Frac& f);
    
};

//String constructor
Frac :: Frac(string s)
{
    stringstream ss(s);
    ss >> num;
    char peekchar = ss.peek();
    
    if( ss && peekchar == '/' )
    {
        ss.get();
        ss >> den;
    }
}

//Set numerator
void Frac :: setNum(int n)
{
    num = n;
}

//Set denominator
void Frac :: setDen(int d)
{
    den = d;
}

//Get numerator
int Frac :: getNum()
{
    return num;
}

//Get denominator
int Frac :: getDen()
{
    return den;
}

//Get fraction
double Frac :: getFrac()
{
    double dec = num/den; //Return fraction as decimal
    
    return dec;
};

//Overload + operator
Frac Frac :: operator + (const Frac &rhs)
{
    Frac temp;
    temp.num = num*rhs.den + rhs.num*den; //Add numerators
    temp.den = den*rhs.den; //Common denominator
    
    lowterms(temp); //Simplify fraction
    
    return temp;
};

//Overload - operator
Frac Frac :: operator - (const Frac &rhs)
{
    Frac temp;
    temp.num = num*rhs.den - rhs.num*den; //Add numerator
    temp.den = den*rhs.den; //Common denominator
    
    lowterms(temp); //Simplify fraction
    
    return temp;
};

//Overload * operator
Frac Frac :: operator * (const Frac &rhs)
{
    Frac temp;
    temp.num = num * rhs.num; //Multiply numerators
    temp.den = den * rhs.den; //Multiply denominators
    
    lowterms(temp); //Simplify fraction
    
    return temp;
};

//Overload / operator
Frac Frac :: operator / (const Frac &rhs)
{
    Frac temp;
    temp.num = num * rhs.den; //Multiply by reciprocal
    temp.den = den * rhs.num;
    
    lowterms(temp); //Simplify fraction
    
    return temp;
};

//Prefix ++ operator
Frac Frac :: operator ++ ()
{
    num += den; //Increment by 1
    
    lowterms(*this); //Simplify fraction
    
    return *this;
    
};

//Prefix -- operator
Frac Frac :: operator -- ()
{
    num -= den; //Decrement by 1
    
    lowterms(*this); //Simplify fraction
    
    return *this;
    
};

//Postfix ++ operator
Frac Frac :: operator ++ (int n)
{
    Frac temp = *this;
    
    ++*this;
    
    lowterms(temp); //Simplify fraction
    
    return temp;
};

//Postfix -- operator
Frac Frac :: operator -- (int n)
{
    Frac temp = *this;
    
    --*this;
    
    lowterms(temp); //Simplify fraction
    
    return temp;
};

// comparators
bool Frac :: operator == (Frac &f2)
{
    if(num == f2.num && den == f2.den) //True if fractions are equal
        return 1;
    else
        return 0;
};

//Overload != operator
bool Frac :: operator != (Frac &f2)
{
    if(num == f2.num && den == f2.den) //False if fractions are equal
        return 0;
    else
        return 1;
};

//Overload < operator
bool Frac :: operator < (Frac &f2)
{
    Frac temp1, temp2;
    temp1.num = num*f2.den; //Common denominators to compare numerators
    temp2.num = f2.num*den;
    
    if(temp1.num < temp2.num) //True if numerator is less than
        return 1;
    else
        return 0;
};

//Overload > operator
bool Frac :: operator > (Frac &f2)
{
    Frac temp1, temp2;
    temp1.num = num*f2.den; //Common denominators to compare numerators
    temp2.num = f2.num*den;
    
    if(temp1.num > temp2.num) //True if numerator is greater than
        return 1;
    else
        return 0;
};

//Overload <= operator
bool Frac :: operator <= (Frac &f2)
{
    Frac temp1, temp2;
    temp1.num = num*f2.den; //Common denominators to compare numerators
    temp2.num = f2.num*den;
    
    if(temp1.num < temp2.num) //True if numerator is less than
        return 1;
    
    else if(num == f2.num && den == f2.den) //True if fractions are equal
        return 1;
    
    else
        return 0;
};

//Overload >= operator
bool Frac :: operator >= (Frac &f2)
{
    Frac temp1, temp2;
    temp1.num = num*f2.den; //Common denominators to compare numerators
    temp2.num = f2.num*den;
    
    if(temp1.num > temp2.num) //True if numerator is greater than
        return 1;
    
    else if(num == f2.num && den == f2.den) //True if fractions are equal
        return 1;
    
    else
        return 0;
};

//Overload output
ostream &operator << (ostream &out, const Frac &F)
{
    out << F.num << "/" << F.den; //Output as numerator / denominator
    
    return out;
};

//Overload input
istream& operator >> (istream &in, Frac& F)
{
    cout << "\nEnter numerator: "; //Take in
    in >> F.num;
    
    cout << "Enter denominator: ";
    in>> F.den;
    
    return in;
};


#endif /* Frac_h */
