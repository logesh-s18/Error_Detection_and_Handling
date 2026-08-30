#include <iostream>
#include <limits> // for numeric limits
#include <string> // for getline()
using namespace std;




void ignoreLine() //ignore extra buffer from input stream
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   //ignoring the maximum buffer characters until a new line '\n', later ^Z(Ctrl+Z) can be not valid for eof, but it also removes the trailing newline char in buffer
}

// *** Error case 2: Extraction succeeds but with extraneous input ----------------------------------------------------------------------------------------------------------------------------------------------
//
//to check buffer inputs after formatted 
bool hasUnExtractedInputs()  // check if the extra input is a valid values or eof
{

    return !std::cin.eof() && std::cin.peek() != '\n';
}

bool clearFailedExtraction()
{
    // check for cin health status
    
    // 1. if failed, recover cin and then remove the buffer from input stream which caused failure
    if (std::cin.fail())
    {
        if (std::cin.eof()) // 2. check if the failure is beacause of EOF
        {
            cout << "EOF occured....exiting the prgram...\n";
            std::exit(0); //termiante program
        }

        std::cin.clear(); // 3. recover cin
        ignoreLine();     //  4. remove the buffer which caused failure
    
        return true;  // indicating "Yes, extraction failure happened, and recovered
    }

    cout << "No Extraction failure.\n";
    return false;  // indicating there's no extraction failure.

}


double getDouble()
{

    //keep looping, if there is a value, then 'return' will end this infinite loop
    while (true)
    {
        std::cout << "Enter a decimal number: ";
        double x{};
        std::cin >> x;   // entering a invalid value to the allocatted type make cin fail and assigns 0 and will create a INFINITE LOOOP!!!!


        if (clearFailedExtraction()) // check for cin fail or pass
        {
            // if true (cin failed and recovered)
            cout << "clearFailedExtraction() : OOPS, thats an invalid value, please try again...\n";
            continue; // skip remaining logics, go back and ask to enter again
        }

        // SUCCESS CASE : if extraction success but in case extra buffer, we directly ignore
        ignoreLine(); // just for safer case, whether extra buffer inputs is not or there even if its a successful extraction, just clean
        return x; //we got the User Input after the Error handling and validation

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


        // remember, input type as char, cin failure occurs for integer
        if (!clearFailedExtraction()) // check for cin fail or pass
        {
            ignoreLine(); // if not clear (false) means, cin extraction is success but also incase extra buffer
        }

        // arithmetic operator symbol validation
        switch (op) //if extraction failed, buufer will be empty and this gets skipped
        {
            case '+':
            case '-':
            case '*':
            case '/':
                return op; // return it to the caller

            default: // otherwise tell the user what went wrong
                std::cout << "OOPS!...that value is invalid, please try again...\n";
                continue; // even if failed extraction
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

    cout << "UNKNOWN ERROR OCCURED !!! \n\n";
}

int main()
{

    double operand_1{ getDouble() };    // check - cin fail [ if eof - terminate, else recover & ignore buffer] / cin success [ ignore buffer ], continue ask again

    char operation{getOperator()}; // check - cin fail [ if eof - terminate, else recover & ignore buffer] / cin success [ ignore buffer ], cin symbol check, default invalid, continue ask again

    double operand_2{ getDouble() };  // check - cin fail [ if eof - terminate, else recover & ignore buffer] / cin success [ ignore buffer ], continue ask again

    while (operation == '/' && operand_2 == 0.0)  // check the divisor if 0.0 (undefined)
    {
        cout << "Undefined value for division...Try again with valid divisor\n";
        operand_2 = getDouble(); // get the value again from user and again check the loop if entered value is not 0.0 for divisor

    }

    printResult(operand_1, operation, operand_2); // good for the calculation and printing it

    return 0;
}