#include <iostream>
#include <malloc.h>

int main()
{
	// Заделяне и освобождаване на памет с malloc/free
	int *pArr1 = (int*)malloc(10 * sizeof(int));

	if (pArr1)
		std::cout << pArr1[0] << std::endl;
	else
		std::cerr << "Allocation failed! (errno " << errno << ")\n";

	free(pArr1);


	// Заделяне и освобождаване на памет с calloc/free
	// Паметта се нулира
	int *pArr2 = (int*)calloc(10, sizeof(int));

	if (pArr2)
		std::cout << pArr2[0] << std::endl;
	else
		std::cerr << "Allocation failed! (errno " << errno << ")\n";

	free(pArr2);


	// Преоразмеряване с realloc
	int *p = (int*) malloc(0);

	int *q = (int*) realloc(p, 10 * sizeof(int)); // нарастване

	if (q != NULL)
	{
		// Ако преоразмеряването е било успешно, q сочи към новия масив
		// Трябва да обновим p, защото той може да се намира на ново място в паметта.
		p = q;
	}
	else
	{
		// Ако функцията върне NULL, преоразмеряването не е било успешно,
		// но старото съдържание е в добро състояние и p все още сочи към него.
		std::cerr << "Reallocation failed! (errno " << errno << ")\n";
		
		// обработка на грешката...
	}

	realloc(p, 2 * sizeof(int)); // смаляване

	free(p);

	return 0;
}