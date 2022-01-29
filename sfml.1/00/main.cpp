#include <iostream>

int main()
  {

      int num = 1;
      // условие: пока num меньше или равно 100
            while (num <= 100)
            {
                std::cout << num << std::endl;
                 // добавляем к числу 1
                 // оператор += это сокращение от `num = num + 1`
                num += 1;
            }
  }
