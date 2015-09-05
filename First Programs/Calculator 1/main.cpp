#include <iostream>
using namespace std;

int main()
{
	double Fahrenheit, Celsius;

	cout << "Enter temperature in Fahrenheit: ";

	// Стандартен вход
	cin >> Fahrenheit;

	// Извеждане на няколко елемента
	cout << "You entered: " << Fahrenheit << endl;

	// Формулата е C = (F – 32) * 5/9
	Celsius = (Fahrenheit - 32) * 5.0 / 9.0;

	cout << Fahrenheit << " in F = "
	     << Celsius << " in C\n";

	return 0;
}
