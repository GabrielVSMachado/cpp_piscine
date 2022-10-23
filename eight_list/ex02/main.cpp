#include <cstddef>
#include <cstdlib>
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main()
{
  {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete [] mirror;//

  }
  {
    srand(time(NULL));
    Array<int> numbers(10);
    Array<int> *tmp = new Array<int>();

    for (std::size_t i = 0; i < numbers.size(); i++) {
      numbers[i] = rand();
    }
    std::cout << "Print values from numbers: " << numbers << '\n';
    std::cout << "Print values in array tmp before assign numbers: "
              << *tmp << '\n';
    *tmp = numbers;
    std::cout << "Print values in array tmp after assign: " << *tmp << '\n';

    delete tmp;
  }
    return 0;
}
