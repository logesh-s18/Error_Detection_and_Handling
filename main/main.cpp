#include <iostream>
#include <limits> // for numeric limits
#include <string> // for getline()
using namespace std;




void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   //ignoring the maximum buffer characters until a new line '\n'
   
    //std::cin.ignore(3, '\n');   //ignoring the buffer characters until a new line '\n' -> Manual way : ignores until the given position number

    //cout << "ignoring the extra buffer inputs... \n"; 
    //cout << "Please try again... \n";
}

// *** Error case 2: Extraction succeeds but with extraneous input ----------------------------------------------------------------------------------------------------------------------------------------------
//
//to check buffer inputs after formatted 
bool hasUnExtractedInputs()
{
    return !std::cin.eof() && std::cin.peek() != '\n';
}




double getDouble()
{

    //keep looping, if there is a value, then 'return' will end this infinite loop
    while (true)
    {
        std::cout << "Enter a decimal number: ";
        double x{};
        std::cin >> x;   // entering a invalid value to the allocatted type make cin fail and assigns 0 and will create a INFINITE LOOOP!!!!


        // *** Error case 3: Extraction fails ----------------------------------------------------------------------------------------------------------------------------------------------------------------
        bool success{ std::cin }; // Remember whether we had a successful extraction
        std::cin.clear();          // Put us back in 'normal' operation mode (in case we failed)
        ignoreLine();              // Ignore any additional input on this line (regardless)

        if (success)               // If we actually extracted a value
            return x;

    }
}


char getOperator()
{
    // *** Error case 1: Extraction succeeds but input is meaningless --------------------------------------------------------------------------------------------------------------------------------------------
    while (true) // loop it and ask again and again until user enters valid symbol, if valid....return it.
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char op{};
        std::cin >> op;


        // arithmetic operator symbol validation
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
    double operand_1{ getDouble() };

    char operation{getOperator()};

    double operand_2{ getDouble() };

    printResult(operand_1, operation, operand_2);

    return 0;
}