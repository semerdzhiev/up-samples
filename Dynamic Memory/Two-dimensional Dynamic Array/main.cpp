#include <iostream>
#include <new> // заради std::nothrow

void Free(int**& pArr, size_t Rows);

/**
 *
 *	Динамично заделя двумерен масив от тип int
 *
 *	Масивът ще бъде с размери [Rows][Cols].
 *	Тази верси на функцията използва new със std::nothrow.
 *
 *	\return
 *		Функцията връща указател към заделения масив
 *		или NULL, ако заделянето не успее.
 *
 */
int** Allocate1(size_t Rows, size_t Cols)
{
	int **pArr = NULL;

	// Заделяме вектор от указатели, които ще
	// сочат към редовете на масива
	pArr = new (std::nothrow) int*[Rows];

	if (pArr)
	{
		// Нулираме всички указатели във вектора
		for (size_t r = 0; r < Rows; r++)
			pArr[r] = NULL;

		// Заделяме всеки от редовете в масива
		for (size_t r = 0; r < Rows; r++)
		{
			pArr[r] = new (std::nothrow) int[Cols];

			if (!pArr[r])
			{
				// Ако възникне грешка, трябва да освободим заетата памет
				Free(pArr, Rows);
				break;
			}
		}
	}

	return pArr;
}


/**
 *
 *	Динамично заделя двумерен масив от тип int
 *
 *	Масивът ще бъде с размери [Rows][Cols].
 *	Тази версия на функция използва изключения (exceptions)
 *	за проверка за грешки при заделянето на памет.
 *
 *	\return
 *		Функцията връща указател към заделения масив
 *		или NULL, ако заделянето не успее.
 *
 */
int** Allocate2(size_t Rows, size_t Cols)
{
	int **pArr = NULL;

	try
	{
		// Заделяме вектор от указатели, които ще сочат към редовете на масива
		pArr = new (std::nothrow) int*[Rows];

		// Нулираме всички указатели във вектора
		for (size_t r = 0; r < Rows; r++)
			pArr[r] = NULL;

		// Заделяме всеки от редовете в масива
		for (size_t r = 0; r < Rows; r++)
			pArr[r] = new int[Cols];
	}
	catch (std::bad_alloc&)
	{
		// Ако възникне грешка, трябва да освободим заетата памет
		Free(pArr, Rows);
	}

	return pArr;
}


/**
*
*	Освобождава паметта на динамично заделен двумерен масив
*
*	Функцията освобождава паметта и след това нулира
*	подадения ѝ указател.
*
*	\param pArr
*		Указател към масива, който ще бъде освободен.
*		Ако този параметър е NULL, функцията не прави нищо.
*
*	\param Rows
*		Брой на редовете в масива
*
*/
void Free(int**& pArr, size_t Rows)
{
	if (!pArr)
		return;

	for (size_t r = 0; r < Rows; r++)
		delete[] pArr[r];

	delete[] pArr;

	pArr = NULL;
}


int main()
{
	const size_t ROWS = 10;
	const size_t COLS = 20;

	int **p = Allocate1(ROWS, COLS);

	if (!p)
	{
		std::cerr << "Error: Allocation failed.\n";
		return 1;
	}

	Free(p, ROWS);

	return 0;
}