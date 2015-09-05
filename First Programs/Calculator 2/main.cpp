#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double Temperature, Result;
	char ConversionType;

	cout << "Convert to (C)elsius or (F)ahrenheit: ";
	cin >> ConversionType;

	cout << "Enter temperature: ";
	cin >> Temperature;


	if (ConversionType == 'F')
		Result = Temperature * 9.0 / 5.0 + 32;

	else
		Result = (Temperature - 32) * 5.0 / 9.0;

	cout << "Converted temperature is "
	     << fixed << setprecision(2) << Result << ConversionType
	     << endl;

	return 0;
}
