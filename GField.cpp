#include <iostream>
#include <cmath>
#include "GField.h"
#include "GFNumber.h"
#include <cassert>
// **************************** IMPLEMENTATION OF GField.h ****************************
// ****************************        CONSTRUCTORS        ****************************
/**
     * A default constructor which creates a field with values p=2,l=1.
     */
GField::GField()
{
    l = 1;
    p = 2;
    order = (long) pow(p, l);
}

/**
     * A constructor which receives a long p and initialize l=1.
     * @param p
     */
GField::GField(long p)
{
    assert(isPrime(p));
    if (p < 0)
    {
        p = -p;
    }
    this->p = p;
    l = 1;
    order = p;
}

/**
     * A constructor which receives a long p and long l .
     * @param p
     * @param l
     */
GField::GField(long p, long l)
{
    assert(isPrime(p));
    assert(l > 0);
    if (p < 0)
    {
        p = -p;
    }
    this->p = p;
    this->l = l;
    order = (long) pow(p, l);

}

/**
   * A copy constructor which receives a field and creates a new one with the same values.
   * @param gfiled
   */
GField::GField(const GField &gfiled)
{
    l = gfiled.l;
    p = gfiled.p;
    order = gfiled.order;
}
// ****************************        METHODS        ****************************
/**
    * This function returns the char of the field .
    * @return field's char .
    */
long GField::getChar()
{
    return p;
}

/**
     * This function returns the degree of the field .
     * @return field's degree .
     */
long GField::getDegree()
{
    return l;
}

/**
     * This function returns the order of the field .
     * @return field's order .
     */
long GField::getOrder()
{
    return order;
}

/**
     * This function receives a long p and checks if it is prime in the field or not .
     * @param p
     * @return true if it is prime , false otherwise.
     */
bool GField::isPrime(long p)
{
    if (p != 2)
    {
        if (p < 2 || p % 2 == 0)
        {
            return false;
        }
        for (int i = 3; (i * i) <= (int) p; i += 2)
        {
            if ((int) p % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

/**
    * This function receives two GFNumbers and calculates their gcd .
    * @param a
    * @param b
    * @return a GFNumber which represents the gcd between the two given GFNumbers.
    */
GFNumber &GField::gcd(GFNumber &a, GFNumber &b)
{
    int gcd;
    if (a.getNumber() == 0 || b.getNumber() == 0)
    {
        if (a.getNumber() == 0)
        {
            gcd = (int) b.getNumber();
            return b;
        }
        gcd = (int) a.getNumber();
        return a;
    }
    if (a.getNumber() == 1 || b.getNumber() == 1)
    {
        gcd = 1;
        GFNumber *one = new GFNumber(1, a.getField());
        return *one;
    }
    for (int i = 1; i <= (int) a.getNumber() && i <= (int) b.getNumber(); i++)
    {
        if ((int) a.getNumber() % i == 0 && (int) b.getNumber() % i == 0)
        {
            gcd = i;
        }
    }
    GFNumber *num = new GFNumber((long) gcd, a.getField());
    return *num;
}

/**
 * This function receives a long k and creates an instance of GFNumber with value k and this GField .
 * @param k
 * @return an instance of GFNumber.
 */
GFNumber &GField::createNumber(long k)
{
    GFNumber *target = new GFNumber(k, *this);
    return *target;
}

// ****************************        OPERATORS        ****************************

/**
  * an operator which sets the values from the given GField to this .
  * @param num
  * @return an instance of GField .
  */
GField &GField::operator=(GField const &num)
{
    p = num.p;
    l = num.l;
    order = num.order;
    return *this;
}

/**
  * an operator which compare between two GField if they are equal or not.
  * @param num1
  * @param num2
  * @return true if they are equal , false otherwise.
  */
bool operator==(const GField &num1, const GField &num2)
{
    return num1.order == num2.order;
}

/**
   * an operator which compare between two GField if they are equal or not.
   * @param num1
   * @param num2
   * @return true if they are not equal , false otherwise
   */
bool operator!=(const GField &num1, const GField &num2)
{
    return num1.order != num2.order;
}

/**
    * the reading stream operator.
    * @param in
    * @param gfield
    * @return the input stream .
    */
std::istream &operator>>(std::istream &in, GField &gfield)
{
    in >> gfield.p >> gfield.l;
    assert(!in.fail());
    return in;
}

/**
    * the writing stream operator.
    * @param out
    * @param gField
    * @return the output stream.
    */
std::ostream &operator<<(std::ostream &out, const GField &gfield)
{
    out << "GF(" << gfield.p << "**" << gfield.l << ")";
    return out;
}






