#include <iostream>
using namespace std;

int main()
{

	int x{};


	cout << "Enter the age : ";

	int age;

	cin >> age;


	if (!cin)
	{
		cout << "invalid input! pls try again...\n";
		std::cin.clear(); //fix cin failed state
	}

	if(cin)  // if cin state fixed before, then here the condition would pass 
	{
		cout << "you have entered " << age;
	}
	return 0;
}