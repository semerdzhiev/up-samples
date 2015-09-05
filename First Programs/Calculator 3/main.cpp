#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int Start = 0;
	int End = 100;
	int Step = 20;

	int Current = Start;

	while (Current <= End)
	{
		cout << setw(3) << Current << "C = "
		     << setw(6) << setprecision(2)
		     << ((Current - 32) * 5.0 / 9.0)
		     << "F" << endl;


		Current = Current + Step;
	}

	return 0;
}
