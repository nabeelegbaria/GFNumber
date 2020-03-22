#include <iostream>

#ifndef EX1_GField_H
#define EX1_GField_H

/**
 * this line is for declaring a class named GFNumber.
 */
class GFNumber;

/**
 * A class which defines a field .
 */
class GField
{
public:

    // ****************************** constructors ******************************
    /**
     * A default constructor which creates a field with values p=2,l=1.
     */
    GField();

    /**
     * A constructor which receives a long p and initialize l=1.
     * @param p
     */
    GField(long p);

    /**
     * A constructor which received a long p and long l .
     * @param p
     * @param l
     */
    GField(long p, long l);

    /**
     * A copy constructor which receives a field and creates a new one with the same values.
     * @param gfiled
     */
    GField(const GField &gfiled);

    /**
     * A destructor for GField.
     */
    ~GField() = default;

    // ****************************** METHODS ******************************
    /**
     * This function returns the char of the field .
     * @return field's char .
     */
    long getChar();

    /**
     * This function returns the degree of the field .
     * @return field's degree .
     */
    long getDegree();

    /**
     * This function returns the order of the field .
     * @return field's order .
     */
    long getOrder();

    /**
     * This function receives a long p and checks if it is prime in the field or not .
     * @param p
     * @return true if it is prime , false otherwise.
     */
    static bool isPrime(long p);

    /**
     * This function receives two GFNumbers and calculates their gcd .
     * @param a
     * @param b
     * @return a GFNumber which represents the gcd between the two given GFNumbers.
     */
    GFNumber &gcd(GFNumber &a, GFNumber &b);

    /**
     * This function receives a long k and creates an instance of GFNumber with value k and this GField .
     * @param k
     * @return an instance of GFNumber.
     */
    GFNumber &createNumber(long k);

    // ****************************** OPERATORS ******************************

    /**
     * an operator which sets the values from the given GField to this .
     * @param num
     * @return an instance of GField .
     */
    GField &operator=(const GField &num);

    /**
     * an operator which compare between two GField if they are equal or not.
     * @param num1
     * @param num2
     * @return true if they are equal , false otherwise.
     */
    friend bool operator==(const GField &num1, const GField &num2);

    /**
     * an operator which compare between two GField if they are equal or not.
     * @param num1
     * @param num2
     * @return true if they are not equal , false otherwise
     */
    friend bool operator!=(const GField &num1, const GField &num2);

    /**
     * the reading stream operator.
     * @param in
     * @param gfield
     * @return the input stream .
     */
    friend std::istream &operator>>(std::istream &in, GField &gfield);

    /**
     * the writing stream operator.
     * @param out
     * @param gField
     * @return the output stream.
     */
    friend std::ostream &operator<<(std::ostream &out, const GField &gField);

private:
    long p; // Fields char .
    long l; // Fields degree .
    long order; // Fields order.

};

#endif