#include <iostream>
#include <string.h>

/*
Написать программу вычисления факториала через циклы (6 слайд) 

Модифицировать программу подсчета символов: пользователь вводит строку с пробелами (7 слайд) 

Наибольшего общего делителя (алгоритм Евклида), числа Фибоначчи. Ханойская башня (8 слайд)
*/

int Count(char c, string s, int i);
int factorial(void);
int stringi(void);

using namespace std;

int main(void)
{
    cout << "\n\n\n==== FACTORIAL ====\n\n" << endl;
    //factorial();
    stringi();
}

int factorial(void)
{
    int num = 0, fac = 1;
    cout << "Enter N: ";
    cin >> num;
    
    for (int i = num; i > 0; i--)
    {
        fac *= i;
    }
    
    cout << "Factorial of N is: " << fac << endl;
    return 0;
}

int stringi(void)
{
    string s = "someright";
    int k;

    k = Count('r', s, 0);
    cout << k << endl;
}

int Count(char c, string s, int i)
{
    if (i == s.length())
        return 0;
    else
    {
        if (c == s[i])
            return Count(c, s, i+1) + 1;
        else
            return Count(c, s, i+1);
    }
}