#include <iostream>
#include <limits> // for numeric limits    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
#include <string> // for getline()
using namespace std;


void ignoreLine()
{
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}



bool hasBufferInputs()
{
	return (!cin.eof() && cin.peek() != '\n');  // de morgan's law ->  not [cin.eof() || cin.peek() == '\n']
}

bool clearFailedStream()
{
	if (cin.fail()) //check for cin failure
	{ 
		if (cin.eof())  // check for eof occurence
		{
			cout << "EOF Occurred!....terminating the program\n";

			std::exit(0); //terminate
		}

		cin.clear(); //recover
		ignoreLine(); // ignore buffer which caused failure

		return true;
	}

	return false;
}


double getDouble()
{
	while (true)

	{
		cout << "Enter the Decimal Number :";

		double value{};

		cin >> value;

		//cin fail check & cin eof check
		if (clearFailedStream())
		{
			cout << "Invalid input!..Try again you Mf ;p\n";

			continue; //skip the loop, move to next iteration which asks again the input
		}

		// cin success but extra input ignore
		ignoreLine();
		return value;
	}
}


char getSymbol()
{
	while (true)
	{
		cout << "Choose one of the following operation : +, -, /, * : ";

		char operation{};

		cin >> operation;


		//cin health checks

		if (!clearFailedStream())
		{
			ignoreLine(); // even if cin good, there may or maynot be buffer exists input stream
		}


		// char validation
		switch (operation)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			return operation;


		default:
			cout << "Uh uhhh...Operation invalid. Please Try again\n";
			continue; // just ask again if its invalid or cin fail (with or without eof)

		}
	}

}



void printResult(double x, char operation, double y)
{

	switch (operation)
	{

		case '+':
			cout << x + y;
			return;

		case '-':
			cout << x - y;
			break;

		case '*':
			cout << x * y;
			return;

		case '/':
			cout << x / y;
			return;

	}

	cout << "SOMETHING STRANGE HAPPENED!\n";

}

int main()
{

	double operator_1{getDouble()};
	
	char operation{getSymbol()};

	double operator_2{ getDouble() };

	//divisor 0 (undefined) check
	while (operation == '/' && operator_2 == 0)

	{
		cout << "0 is undefined dividend, please try again with valid value...\n";
		operator_2 = getDouble();
	}


	printResult(operator_1, operation, operator_2);

	return 0;
}