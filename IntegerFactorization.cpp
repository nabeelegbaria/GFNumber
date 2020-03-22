#include <iostream>
#include <stdlib.h>
#include "GFNumber.cpp"
#include "GField.cpp"

/**
 * The main function which runs the code , receiving two GFNumbers .
 * calculating the sum , substraction , multiplication between them and printing the result .
 * printing the prime numbers which the two numbers consists of .
 * @param argc
 * @param argv
 * @return EXIT_SUCCESS if the code is ok , 1 otherwise.
 */
int main(int argc, char *argv[])
{
    long n1, p1, l1;
    long n2, p2, l2;
    std::cin >> n1 >> p1 >> l1;
    GField firstfield(p1, l1);
    GFNumber num1(firstfield.createNumber(n1));
    std::cin >> n2 >> p2 >> l2;
    GField secondfield(p2, l2);
    GFNumber num2 = secondfield.createNumber(n2);
    std::cout << num1 + num2 << std::endl;
    std::cout << num1 - num2 << std::endl;
    std::cout << num2 - num1 << std::endl;
    std::cout << num1 * num2 << std::endl;
    num1.printFactors();
    num2.printFactors();
    return EXIT_SUCCESS;
}