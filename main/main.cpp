#include <iostream>
using namespace std;

double getDouble()
{
    std::cout << "Enter a decimal number: ";
    double x{};
    std::cin >> x;
    return x;
}

char getOperator()
{
    // Error case 1: Extraction succeeds but input is meaningless
    //bool isValid = true;
    //char operation;

    while (true) // loop it and ask again and again until user enters valid symbol, if valid....return it.
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char op{};
        std::cin >> op;

        switch (op)
        {
            case '+':
            case '-':
            case '*':
            case '/':
                std::cout << "Cases\n";
                //return op; // return it to the caller

            default: // otherwise tell the user what went wrong
                std::cout << "Default\n";
        }

    }

    //return operation;
}

void printResult(double x, char operation, double y)
{
    std::cout << x << ' ' << operation << ' ' << y << " is ";

    switch (operation)
    {
    case '+':
        std::cout << x + y << '\n';
        return;
    case '-':
        std::cout << x - y << '\n';
        return;
    case '*':
        std::cout << x * y << '\n';
        return;
    case '/':
        std::cout << x / y << '\n';
        return;
    }
}

int main()
{
    //double x{ getDouble() };
    //char operation{ getOperator() };
    //double y{ getDouble() };

    //printResult(x, operation, y);

    string firstName;
    string lastName;


    cin >> firstName;

    cin >> lastName;

    std::cout << firstName << ' ' << lastName;



    return 0;
}