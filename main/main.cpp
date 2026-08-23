#include <iostream>
#include <limits> // for numeric limits
#include <string> // for getline()
using namespace std;




void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   //ignoring the maximum buffer characters until a new line '\n'
   
    //std::cin.ignore(3, '\n');   //ignoring the buffer characters until a new line '\n' -> Manual way : ignores until the given position number

    cout << "ignoring the extra buffer inputs... \n"; 
}

//Error case 2: Extraction succeeds but with extraneous input
//
//to check buffer inputs after formatted 
bool hasUnExtractedInputs()
{
    return !std::cin.eof() && std::cin.peek() != '\n';
}


double getDouble()
{
    while (true)
    {
        std::cout << "Enter a decimal number: ";
        double x{};
        std::cin >> x;   // entering a invalid value to the allocatted type make cin fail and assigns 0 and will create a INFINITE LOOOP!!!!


        // I have implemented this with my own logical thinking. Proud of you Loki!!!!
        if (!std::cin)  
        {
            cout << "INPUT STREAM (cin) FAILURE \n";

            std::cin.clear();  // likethis also we can avoid the infinite loop and recover cin state
            cout << "Recovered cin failure. its up now! \n\n";


            // Ok, now how about we print the buffer which caused failure of cin ? below steps taken
            string buffer;

            cin >> buffer;

            cout << "After cin recovery, the buffer still inside is : " << buffer << "\n\n";  //likethis we can check the buffer which made cin fail

            continue; // skip the rest of iteration and go back, ask again user to enter

        }



        // In certain cases, it may be better to treat extraneous input as a failure case (rather than just ignoring it). We can then ask the user to re-enter their input.
        if (hasUnExtractedInputs())
        {
            cout << "Found Un Extracted Inputs inside input stream buffer!!! \n";  // Alert the user in console

            //Error case 2: Extraction succeeds but with extraneous input
            ignoreLine();

            cout << "Please try again... \n";
            continue;
        }

        return x;

    }
}


char getOperator()
{
    // Error case 1: Extraction succeeds but input is meaningless


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
    //double operand_1{ getDouble() };

    //char operation{getOperator()};

    //double operand_2{ getDouble() };

    //printResult(operand_1, operation, operand_2);


    int age;

    string name;

   

   

    cin >> age; // ok

    getline(cin, name); //not ok

    cout << "Hi " << name << ' '
        << "your age is " << age;

    return 0;
}