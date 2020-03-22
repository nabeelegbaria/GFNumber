#include <iostream>
#include <sstream>
#include <cmath>
#include <cassert>
#include "GFNumber.h"

// **************************** IMPLEMENTATION OF GFNumber.h ****************************
// ****************************        CONSTRUCTORS        ****************************
/**
    * equal to default constructor
    * @param gf
    */
GFNumber::GFNumber(GField &gf)
{
    number = 0;
    gfield = &gf;
}

/**
    * A default constructor which creates a GFNumber with value 0 , GField = 2,1 .
    */
GFNumber::GFNumber()
{
    GFNumber(GField());
}

/**
    * A constructor which receives a long number and initialize GField = 2,1 .
    * @param p
    */
GFNumber::GFNumber(long n)
{

    number = n % gfield->getOrder();
    if (number < 0)
    {
        number += gfield->getOrder();
    }
}

/**
    * A constructor which receives a long number and a GField .
    * @param p
    */
GFNumber::GFNumber(long n, GField &field)
{
    number = n % field.getOrder();
    if (number < 0)
    {
        number += field.getOrder();
    }
    gfield = &field;
}

/**
  * A copy constructor which receives a GFNumber and creates an instance with same values.
  * @param p
  */
GFNumber::GFNumber(GFNumber &gfnum)
{
    number = gfnum.number;
    gfield = gfnum.gfield;
}

// ****************************** METHODS ******************************
/**
 * This function returns the number of the GFNumber .
 * @return field's char .
 */
long GFNumber::getNumber()
{
    return number;
}

/**
     * This function returns the GField of the GFNumber .
     * @return field's char .
     */
GField &GFNumber::getField()
{
    return *gfield;
}

/**
 * This function receives a long number and calculates its prime number by the tree division method .
 * @param n
 * @param factors
 * @param gfield
 * @param counter
 * @return A GFNumber array.
 */
GFNumber *directSearchFactorization(long n, GFNumber *factors, GField &gfield, int counter)
{
    int i = 2;
    while (i < floor(sqrt(n)))
    {
        if ((int) n % i == 0)
        {
            GFNumber primenum(i, gfield);
            factors[counter] = primenum;
            counter++;
            n = n / (long) (floor(i));
        }
        i++;
    }
    if (n > 1)
    {
        GFNumber primenum(n, gfield);
        factors[counter] = primenum;
        counter++;
    }
    GFNumber lenarr(0, gfield);
    factors[counter] = lenarr;
    return factors;
}

/**
 * This function receives a GFNumber array and updates its size +1.
 * @param size
 * @param arr
 * @return A GFNumber array .
 */
GFNumber *resize(int size, GFNumber *arr)
{
    GFNumber *updatedarr;
    updatedarr = new GFNumber[size + 1];
    for (int i = 0; i < size; ++i)
    {
        updatedarr[i] = arr[i];
    }
    return updatedarr;
}

/**
 * This function represents the Rho algorithim for calculating prime numbers .
 * @param n
 * @param gfield
 * @param currentprimenumber
 * @return A prime number of n returned as a GFNumber .
 */
GFNumber *rho(long n, GField &gfield, GFNumber *currentprimenumber)
{
    if (n == 0)
    {
        return nullptr;
    }
    if (n % 2 == 0)
    {
        GFNumber two(2, gfield);
        currentprimenumber = &two;
        return currentprimenumber;

    }
    srand(time(NULL));
    long x, y;
    int g = 1;
    x = rand() % n - 1 + 1;
    y = x;
    while (g == 1)
    {
        x = ((x * x) + 1) % n;
        y = ((y * y) + 1) % n;
        y = ((y * y) + 1) % n;
        long val = (long) abs((int) (x - y));
        GFNumber num1(val, gfield);
        GFNumber num2(n, gfield);
        if (gfield.gcd(num1, num2).getNumber() != 1)
        {
            GFNumber l(gfield.gcd(num1, num2).getNumber(), gfield);
            currentprimenumber = &l;
        }
        g = (int) gfield.gcd(num1, num2).getNumber();
    }
    if (g == n || !gfield.isPrime(g))
    {
        return nullptr;
    }
    return currentprimenumber;
}

/**
    * This function returns the prime factors which the GFNumber consists of .
    * @return An array of the prime factors returned as GFNumber objects .
    */
GFNumber *GFNumber::getPrimeFactors()
{
    GFNumber *currentprime;
    GFNumber *primefactors;
    primefactors = new GFNumber[1];
    int counter = 0;
    long n = number;
    while (currentprime != nullptr)
    {
        currentprime = rho(n, getField(), currentprime);
        if (currentprime != nullptr)
        {
            if (currentprime->number == 0)
            {
                break;
            }
            primefactors[counter] = *currentprime;
            counter++;
            primefactors = resize(counter, primefactors);
            n = n / primefactors[counter - 1].number;
            if (n == 1)
            {
                break;
            }
        }
    }
    if (currentprime != nullptr)
    {
        GFNumber zero(0, *gfield);
        primefactors[counter] = zero;
        return primefactors;
    }
    // if it is null try trial division.
    primefactors = directSearchFactorization(n, primefactors, getField(), counter);
    return primefactors;
}

/**
    * This function prints the prime factors which the GFNumber consists of as strings .
    */
void GFNumber::printFactors()
{
    if (number == 0 || number == 1 || getIsPrime())
    {
        std::cout << number << '=' << number << "*" << 1 << std::endl;
        return;
    }
    GFNumber *factors = getPrimeFactors();
    int len = 0;
    while (factors[len].number != 0)
    {
        len++;
    }
    for (int j = 0; j < len; ++j)
    {
        if (j == len - 1)
        {
            std::cout << factors[j].number;
            continue;
        }
        std::cout << factors[j].number << '*';
    }
    std::cout << std::endl;
}

/**
    * This function checks if the GFNumber is prime according to its GField or not.
    * @return true if it is prime , false otherwise.
    */
bool GFNumber::getIsPrime()
{
    return gfield->isPrime(this->number);
}

// ****************************** OPERATORS ******************************
/**
 * an operator which sets the values from the given GFNumber to this .
 * @param num
 * @return an instance of GFNumber .
 */
GFNumber &GFNumber::operator=(const GFNumber &other)
{
    number = other.number;
    gfield = other.gfield;
    return *this;
}

/**
   * a sum operator for two GFNumbers .
   * @param num1
   * @param num2
   * @return a GFNumber with value equal to the sum of the two given GFNumber values.
   */
GFNumber &operator+(const GFNumber &num1, const GFNumber &num2)
{
    assert(*num1.gfield == *num2.gfield);
    return num1.gfield->createNumber((num1.number + num2.number));
}

/**
     * a sum operator for GFNumber and a long .
     * @param num1
     * @param num2
     * @return a GFNumber with value equal to the sum of the  given GFNumber value and long .
     */
GFNumber &operator+(const GFNumber &num1, long num2)
{
    return num1.gfield->createNumber((num1.number + num2));
}

/**
    * a sum operator for this and given GFNumber .
    * @param num1
    * @param num2
    * @return updated this .
    */
GFNumber &GFNumber::operator+=(const GFNumber &gfnum)
{
    assert(*gfield == *gfnum.gfield);
    number += gfnum.number;
    return *this;
}

/**
    * a sum operator for this and given long .
    * @param num1
    * @param num2
    * @return updated this .
    */
GFNumber &GFNumber::operator+=(long num)
{
    number += num;
    return *this;
}

/**
* a subtraction operator for two GFNumbers .
* @param num1
* @param num2
* @return a GFNumber with value equal to the subtraction of the two given GFNumber values.
*/
GFNumber &operator-(const GFNumber &num1, const GFNumber &num2)
{
    assert(*num1.gfield == *num2.gfield);
    return num1.gfield->createNumber((num1.number - num2.number));
}

/**
   * a subtraction operator for GFNumber and a long .
   * @param num1
   * @param num2
   * @return a GFNumber with value equal to the subtraction of the  given GFNumber value and long .
   */
GFNumber &operator-(const GFNumber &num1, long num2)
{
    return num1.gfield->createNumber((num1.number - num2));
}

/**
    * a subtraction operator for this and given GFNumber .
    * @param num1
    * @param num2
    * @return updated this .
    */
GFNumber &GFNumber::operator-=(const GFNumber &gfnum)
{
    assert(*gfield == *gfnum.gfield);
    number -= gfnum.number;
    return *this;
}

/**
     * a subtraction operator for this and given long .
     * @param num1
     * @param num2
     * @return updated this .
     */
GFNumber &GFNumber::operator-=(long num)
{
    number -= num;
    return *this;
}

/**
* a multiplication operator for two GFNumbers .
* @param num1
* @param num2
* @return a GFNumber with value equal to the multiplication of the two given GFNumber values.
*/
GFNumber &operator*(const GFNumber &num1, const GFNumber &num2)
{
    assert(*num1.gfield == *num2.gfield);
    return num1.gfield->createNumber((num1.number * num2.number));
}

/**
   * a multiplication operator for GFNumber and a long .
   * @param num1
   * @param num2
   * @return a GFNumber with value equal to the multiplication of the  given GFNumber value and long .
   */
GFNumber &operator*(const GFNumber &num1, long num2)
{
    return num1.gfield->createNumber((num1.number * num2));
}

/**
   * a multiplication operator for this and given GFNumber .
   * @param num1
   * @param num2
   * @return updated this .
   */
GFNumber &GFNumber::operator*=(const GFNumber &gfnum)
{
    assert(*gfield == *gfnum.gfield);
    number *= gfnum.number;
    return *this;
}

/**
     * a multiplication operator for this and given long .
     * @param num1
     * @param num2
     * @return updated this .
     */
GFNumber &GFNumber::operator*=(long num)
{
    number *= num;
    return *this;
}

/**
* a modulo operator for two GFNumbers .
* @param num1
* @param num2
* @return a GFNumber with value equal to the modulo of the two given GFNumber values.
*/
GFNumber &operator%(const GFNumber &num1, const GFNumber &num2)
{
    assert(*num1.gfield == *num2.gfield);
    return num1.gfield->createNumber((num1.number % num2.number));
}

/**
* a modulo operator for GFNumber and a long .
* @param num1
* @param num2
* @return a GFNumber with value equal to the modulo of the  given GFNumber value and long .
*/
GFNumber &operator%(const GFNumber &num1, long num2)
{

    return num1.gfield->createNumber((num1.number % num2));
}

/**
   * a modulo operator for this and given GFNumber .
   * @param num1
   * @param num2
   * @return updated this .
   */
GFNumber &GFNumber::operator%=(const GFNumber &gfnum)
{
    assert(*gfield == *gfnum.gfield);
    number %= gfnum.number;
    return *this;
}

/**
* a modulo operator for this and given long .
* @param num1
* @param num2
* @return updated this .
*/
GFNumber &GFNumber::operator%=(long num)
{
    number %= num;
    return *this;
}

/**
   * an operator which compare between two GFNumbers if they are equal or not.
   * @param num1
   * @param num2
   * @return true if they are equal , false otherwise.
   */
bool operator==(const GFNumber &num1, const GFNumber &num2)
{
    return num1.gfield->getChar() == num2.gfield->getChar() && num1.number == num2.number;
}

/**
 * an operator which compare between two GFNumbers if they are equal or not.
 * @param num1
 * @param num2
 * @return true if they are not equal , false otherwise.
 */
bool GFNumber::operator!=(const GFNumber &other)
{
    return gfield->getChar() != other.gfield->getChar() || number != other.number;
}

/**
     * the comparition > for the two given GFNumbers.
     * @param num1
     * @param num2
     * @return true if num1 > num2, false otherwise.
     */
bool operator>(const GFNumber &num1, const GFNumber &num2)
{
    assert(*num1.gfield == *num2.gfield);
    return num1.number > num2.number;
}

/**
     * the comparition >= for the two given GFNumbers.
     * @param num1
     * @param num2
     * @return true if num1 >= num2, false otherwise.
     */
bool operator>=(const GFNumber &num1, const GFNumber &num2)
{
    assert(*num1.gfield == *num2.gfield);
    return num1.number >= num2.number;
}

/**
     * the comparition < for the two given GFNumbers.
     * @param num1
     * @param num2
     * @return true if num1 < num2, false otherwise.
     */
bool operator<(const GFNumber &num1, const GFNumber &num2)
{
    assert(*num1.gfield == *num2.gfield);
    return num1.number < num2.number;
}

/**
     * the comparition <= for the two given GFNumbers.
     * @param num1
     * @param num2
     * @return true if num1 <= num2, false otherwise.
     */
bool operator<=(const GFNumber &num1, const GFNumber &num2)
{
    assert(*num1.gfield == *num2.gfield);
    return num1.number <= num2.number;
}

/**
     * the reading stream operator.
     * @param in
     * @param gfield
     * @return the input stream .
     */
std::istream &operator>>(std::istream &in, GFNumber &gfnum)
{
    in >> gfnum.number >> *gfnum.gfield;
    return in;
}

/**
     * the writing stream operator.
     * @param out
     * @param gField
     * @return the output stream.
     */
std::ostream &operator<<(std::ostream &out, const GFNumber &gfnum)
{
    out << gfnum.number << " GF(" << gfnum.gfield->getChar() << "**" << gfnum.gfield->getDegree() << ")";
    return out;
}























