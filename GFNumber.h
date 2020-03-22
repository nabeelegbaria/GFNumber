#include <iostream>
#include "GField.h"
#include <cassert>
#include <random>

#ifndef EX1_GFNumber_H
#define EX1_GFNumber_H


/**
 * A class which defines a GFNumber .
 */
class GFNumber
{
public:
// ****************************** constructors ******************************
    /**
        * A default constructor which creates a GFNumber with value 0 , GField = 2,1 .
        */
    GFNumber();

    /**
   * A constructor which receives a long number and a GField .
   * @param p
   */
    GFNumber(long n, GField &gf);

    /**
   * A constructor which receives a long number and initialize GField = 2,1 .
   * @param p
   */
    GFNumber(long n);

    /**
     * equal to default constructor
     * @param gf
     */
    GFNumber(GField &gf);

    /**
   * A copy constructor which receives a GFNumber and creates an instance with same values.
   * @param p
   */
    GFNumber(GFNumber &gfnum);


    /**
                 * A destructor for GFNumber.
                 */
    ~GFNumber() = default;
    // ****************************** METHODS ******************************
    /**
     * This function returns the number of the GFNumber .
     * @return field's char .
     */
    long getNumber();

    /**
     * This function returns the GField of the GFNumber .
     * @return field's char .
     */
    GField &getField();

    /**
     * This function returns the prime factors which the GFNumber consists of .
     * @return An array of the prime factors returned as GFNumber objects .
     */
    GFNumber *getPrimeFactors();

    /**
     * This function prints the prime factors which the GFNumber consists of as strings .
     */
    void printFactors();

    /**
     * This function checks if the GFNumber is prime according to its GField or not.
     * @return true if it is prime , false otherwise.
     */
    bool getIsPrime();

    // ****************************** OPERATORS ******************************
    /**
     * an operator which sets the values from the given GFNumber to this .
     * @param num
     * @return an instance of GFNumber .
     */
    GFNumber &operator=(const GFNumber &other);

    /**
     * a sum operator for two GFNumbers .
     * @param num1
     * @param num2
     * @return a GFNumber with value equal to the sum of the two given GFNumber values.
     */
    friend GFNumber &operator+(const GFNumber &num1, const GFNumber &num2);

    /**
     * a sum operator for GFNumber and a long .
     * @param num1
     * @param num2
     * @return a GFNumber with value equal to the sum of the  given GFNumber value and long .
     */
    friend GFNumber &operator+(const GFNumber &num1, long num2);

    /**
     * a sum operator for this and given GFNumber .
     * @param num1
     * @param num2
     * @return updated this .
     */
    GFNumber &operator+=(const GFNumber &gfnum);

    /**
     * a sum operator for this and given long .
     * @param num1
     * @param num2
     * @return updated this .
     */
    GFNumber &operator+=(long gfnum);

    /**
  * a subtraction operator for two GFNumbers .
  * @param num1
  * @param num2
  * @return a GFNumber with value equal to the subtraction of the two given GFNumber values.
  */
    friend GFNumber &operator-(const GFNumber &num1, const GFNumber &num2);

    /**
     * a subtraction operator for GFNumber and a long .
     * @param num1
     * @param num2
     * @return a GFNumber with value equal to the subtraction of the  given GFNumber value and long .
     */
    friend GFNumber &operator-(const GFNumber &num1, long num2);

    /**
    * a subtraction operator for this and given GFNumber .
    * @param num1
    * @param num2
    * @return updated this .
    */
    GFNumber &operator-=(const GFNumber &gfnum);

    /**
     * a subtraction operator for this and given long .
     * @param num1
     * @param num2
     * @return updated this .
     */
    GFNumber &operator-=(long num);

    /**
* a multiplication operator for two GFNumbers .
* @param num1
* @param num2
* @return a GFNumber with value equal to the multiplication of the two given GFNumber values.
*/
    friend GFNumber &operator*(const GFNumber &num1, const GFNumber &num2);

    /**
    * a multiplication operator for GFNumber and a long .
    * @param num1
    * @param num2
    * @return a GFNumber with value equal to the multiplication of the  given GFNumber value and long .
    */
    friend GFNumber &operator*(const GFNumber &num1, long num2);

    /**
    * a multiplication operator for this and given GFNumber .
    * @param num1
    * @param num2
    * @return updated this .
    */
    GFNumber &operator*=(const GFNumber &gfnum);

    /**
     * a multiplication operator for this and given long .
     * @param num1
     * @param num2
     * @return updated this .
     */
    GFNumber &operator*=(long num);

    /**
* a modulo operator for two GFNumbers .
* @param num1
* @param num2
* @return a GFNumber with value equal to the modulo of the two given GFNumber values.
*/
    friend GFNumber &operator%(const GFNumber &num1, const GFNumber &num2);

    /**
 * a modulo operator for GFNumber and a long .
 * @param num1
 * @param num2
 * @return a GFNumber with value equal to the modulo of the  given GFNumber value and long .
 */
    friend GFNumber &operator%(const GFNumber &num1, long num2);

    /**
   * a modulo operator for this and given GFNumber .
   * @param num1
   * @param num2
   * @return updated this .
   */

    GFNumber &operator%=(const GFNumber &gfnum);

    /**
  * a modulo operator for this and given long .
  * @param num1
  * @param num2
  * @return updated this .
  */
    GFNumber &operator%=(long num);

    /**
    * an operator which compare between two GFNumbers if they are equal or not.
    * @param num1
    * @param num2
    * @return true if they are equal , false otherwise.
    */
    friend bool operator==(const GFNumber &num1, const GFNumber &num2);

    /**
   * an operator which compare between two GFNumbers if they are equal or not.
   * @param num1
   * @param num2
   * @return true if they are not equal , false otherwise.
   */
    bool operator!=(const GFNumber &other);

    /**
     * the comparition > for the two given GFNumbers.
     * @param num1
     * @param num2
     * @return true if num1 > num2, false otherwise.
     */
    friend bool operator>(const GFNumber &num1, const GFNumber &num2);

    /**
     * the comparition >= for the two given GFNumbers.
     * @param num1
     * @param num2
     * @return true if num1 >= num2, false otherwise.
     */
    friend bool operator>=(const GFNumber &num1, const GFNumber &num2);

    /**
     * the comparition < for the two given GFNumbers.
     * @param num1
     * @param num2
     * @return true if num1 < num2, false otherwise.
     */
    friend bool operator<(const GFNumber &num1, const GFNumber &num2);

    /**
     * the comparition <= for the two given GFNumbers.
     * @param num1
     * @param num2
     * @return true if num1 <= num2, false otherwise.
     */
    friend bool operator<=(const GFNumber &num1, const GFNumber &num2);

    /**
     * the reading stream operator.
     * @param in
     * @param gfield
     * @return the input stream .
     */
    friend std::istream &operator>>(std::istream &in, GFNumber &gfnum);

    /**
     * the writing stream operator.
     * @param out
     * @param gField
     * @return the output stream.
     */
    friend std::ostream &operator<<(std::ostream &out, const GFNumber &gfnum);

private:
    long number; // the value of the number .
    GField *gfield; // the GField of the number
};

#endif