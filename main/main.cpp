#include <iostream>
using namespace std;




void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   //ignoring the maximum buffer characters until a new line '\n'
   
    
    //std::cin.ignore(3, '\n');   //ignoring the buffer characters until a new line '\n' -> Manual way : ignores until the given position number
}


double getDouble()
{
    std::cout << "Enter a decimal number: ";
    double x{};
    std::cin >> x;

    //Error case 2: Extraction succeeds but with extraneous input
    ignoreLine(); 
    return x;
}

char getOperator()
{
    // Error case 1: Extraction succeeds but input is meaningless


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
                return op; // return it to the caller

            default: // otherwise tell the user what went wrong
                std::cout << "OOPS!...that value is invalid, please try again...\n";
        }

    }

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
    double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };

    printResult(x, operation, y);

   
    return 0;
}