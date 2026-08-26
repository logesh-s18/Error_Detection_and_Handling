#include <iostream>
#include <limits> // for numeric limits
#include <string> // for getline()
using namespace std;




void ignoreLine()
{
    cout << "\n\nignoreLine() started -------- >\n\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   //ignoring the maximum buffer characters until a new line '\n', later ^Z(Ctrl+Z) can be not valid for eof, but it also removes the trailing newline char in buffer
   
    cout << "ignoring the extra buffer inputs... \n"; 
    cout << "Please try again... \n";

    cout << "\n\nignoreLine() ended -------- X\n\n";
}

// *** Error case 2: Extraction succeeds but with extraneous input ----------------------------------------------------------------------------------------------------------------------------------------------
//
//to check buffer inputs after formatted 
bool hasUnExtractedInputs()
{
    cout << "\n\nhasUnExtractedInputs() started -------- >\n\n";

    char peek_1 = std::cin.peek();
    int peek_2 = std::cin.peek();

    cout << "peek_1 : " << peek_1 << '\n';
    cout << "peek_2 : " << peek_2 << '\n';
    cout << "cin.peek() : " << cin.peek() << '\n';

    cout << "\n\nhasUnExtractedInputs() ended -------- X\n\n";

    return !std::cin.eof() && std::cin.peek() != '\n';
}


bool isEOF()
{
    cout << "\n\isEOF() started -------- >\n\n";

    char peek_1 = std::cin.peek();
    int peek_2 = std::cin.peek(); // captures EOF sentinel (-1) if present

    cout << "real EOF value : " << std::char_traits<char>::eof() << '\n';
    cout << "peek_1 : " << peek_1 << '\n';
    cout << "peek_2 : " << peek_2 << '\n';
    cout << "cin.peek() : " << cin.peek() << '\n';

    if (peek_2 == std::char_traits<char>::eof()) 
    {
        cout << "WE GOT EOF! : " << peek_2 << '\n';
        return true;
    }
    else 
    {
        char c = static_cast<char>(peek_2);
        std::cout << "peeked: '" << c << "' (0x" << std::hex << peek_2 << ")\n";
        return false;
    }

    cout << "\n\isEOF() ended -------- X\n\n";

}


double getDouble()
{

    //keep looping, if there is a value, then 'return' will end this infinite loop
    while (true)
    {
        std::cout << "Enter a decimal number: ";
        double x{};
        std::cin >> x;   // entering a invalid value to the allocatted type make cin fail and assigns 0 and will create a INFINITE LOOOP!!!!


        //Early Detecting everytime to know if its EOF or not
        if (isEOF())
        {
            cout << "eof TRUE\n\n";
        }
        else
        {
            cout << "No eof \n\n";
        }

        //if its a newline in buffer
        if (cin.peek() == '\n')  
        {
            int value = cin.peek();
            char v = cin.peek();
            cout << "We have new line and its value is : " << v << "\n\n";
        }

        // *** Error case 3: Extraction fails ----------------------------------------------------------------------------------------------------------------------------------------------------------------
        // I have implemented this with my own logical thinking. Proud of you Loki!!!!
        if (std::cin.fail())  // ---> or use `
        {
            cout << "cin.failed \n";

            if (cin.eof())
            {
                cout << "eof OCCURED! \n";
                
            }


            std::cin.clear();  // recover cin state from failure
            cout << "called cin.clear(), Recovered cin failure. cin is good now! \n\n";


            // for my validation to understand if eof still exists or not
            if (cin.eof())
            {
                cout << "after cin recovery, eof still exists!!! \n";

            }


            cout << "after cin recovery, Currently, we have buffer value as peeked is " << cin.peek() << "\n\n"; //while it comes here, the buffer is empty, so it blinks console and waits for some inputs

            isEOF();

            
            if (cin.peek() != '\n')
            {
                cout << "the buffer peek() : " << std::cin.peek() << "\n\n";

                // Ok, now how about we print the buffer which caused failure of cin ? below steps taken
                string buffer;

                cin >> buffer;  //if buffer empty, then console pops and asks us to enter the input




                cout << "After cin recovery, the buffer still inside is : " << buffer << "\n\n";  //likethis we can check the buffer which made cin fail

                ignoreLine(); //after showing to user about the existing buffer came in console, remove the extra input buffers which is in console

                continue; // skip the rest of iteration and go back, ask again user to enter

            }
            else if (cin.peek() == '\n')  //if its a newline in buffer
            {
                cout << "if (cin.peek() == '\n') passed....\n\n";
                char peek_1 = std::cin.peek();
                int peek_2 = std::cin.peek(); // captures EOF sentinel (-1) if present
                cout << "\nnewline in buffer (char) : " << peek_1 << "\n\n";
                cout << "\nnewline in buffer (int) : " << peek_2 << "\n\n";
            }

            else //STRANGER THINGS in buffer
            {
                cout << "\n\n***************** STRANGER THINGS !!!!!W@ % !$# & !% @ & ^!********************\n\n\n";
            }

           

        }


        // *** Error case 2: Extraction succeeds but with extraneous input  ---------------------------------------------------------------------------------------------------------------------------------------
        // In certain cases, it may be better to treat extraneous input as a failure case (rather than just ignoring it). We can then ask the user to re-enter their input.
        if (hasUnExtractedInputs())
        {
            cout << "Found Un Extracted Inputs inside input stream buffer!!! \n";  // Alert the user in console

            ignoreLine(); //remove the extra input buffers which is in console
            
            continue; //skip the remaining executions and go back to next iteration
        }

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

    //cout << "1=========\n";
    //cout << "cin peek() 1 " << cin.peek() << '\n'; // cin.peek() always returns the ASCII value of buffer char

    //cout << "2=========\n";
    //cout << "cin peek() 2 " << cin.peek() << '\n';


    double operand_1{ getDouble() };

    char operation{getOperator()};

    double operand_2{ getDouble() };

    printResult(operand_1, operation, operand_2);

    return 0;
}