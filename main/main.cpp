#include <iostream>
using namespace std;




void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   //ignoring the maximum buffer characters until a new line '\n'
   
    
    //std::cin.ignore(3, '\n');   //ignoring the buffer characters until a new line '\n' -> Manual way : ignores until the given position number
}

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
        std::cin >> x;


        // In certain cases, it may be better to treat extraneous input as a failure case (rather than just ignoring it). We can then ask the user to re-enter their input.

        if (hasUnExtractedInputs())
        {
            //Error case 2: Extraction succeeds but with extraneous input
            ignoreLine();
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
    char ch1, ch2, ch3, ch4, ch5; // i will enter abcd -> goes to buffer  .... not a b c d as ' ' space gets included as character too


    std::cin.putback('Q');

    std::cin >> ch1; // 'a' gets assigned  ~~~~ Buffer = b c d

    std::cin.putback('O');

    ch2 = std::cin.peek(); // 'b' peeked, assigned to ch2 but no move of target position pointer ~~~~~~ ch2 = b

    std::cin.get(ch3); // ch3 = b, tpp moved next to 'c'

    std::cin.putback('L'); // goes back to 'b' position and puts back/uploads 'L'  ~~~~ Buffer = L c d

    std::cin.get(ch4); // ch4 = 'L' ~~~~ Buffer = c d

    std::cin.get(ch5); //  ch5 = 'c' ~~~~~~ Buffer = d


    std::cout << ch1 << ' ' << ch2 << ' ' << ch3 << ' ' << ch4 << ' ' << ch5 << '\n'; 

    //Output = a b b L c

    return 0;
}