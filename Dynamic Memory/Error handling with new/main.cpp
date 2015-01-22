﻿#include <iostream>
#include <new> // заради std::nothrow

void MyNewHandler()
{
	//
	// Функцията може да се опита да освободи памет (ако има как).
	//
	// След това има три начина, по които тя може да приключи работата си:
	//
	// 1. Ако просто прекрати изпълнението си (напр. с return),
	// се предполага, че тя е успяла да освободи памет.
	// Тогава се прави нов опит да се задели памет. Ако той е неуспешен
	// функцията се извиква отново и това може да продължи произволен брой пъти.
	//
	// 2. Да прекрати изпълнението на програмата с exit() (с подходящ изходен код)
	// или с abort(). Например:
	//    std::exit(1)
	//
	// 3. Да индикира, че е възникнала грешка, като хвърли изключение от
	// тип std::bad_alloc
	//

	std::cerr << "ERROR: allocation failed (entering MyNewHandler())\n";

	throw std::bad_alloc();
}

int main()
{
	size_t SIZE = 0x0FFFFFFF;

	int *p;

	// Заделяме памет, докато не изчерпим свободната.
	while (new (std::nothrow) int[SIZE])
	{
		std::cout << "Allocated " << SIZE << " ints.\n";
	}


	//-----------------------------------------------------------------------
	// Вариант 1: При заделяне с nothrow, new връща NULL,
	// ако заделянето не е успешно.
	p = new (std::nothrow) int[SIZE];

	if (!p)
	{
		std::cerr << "ERROR: allocation failed (new returned NULL)\n";
	}


	//-----------------------------------------------------------------------
	// Вариант 2: Ако не е указано друго, new хвърля изключение,
	// когато заделянето не е успешно
	try
	{
		p = new int[SIZE];
	}
	catch (std::bad_alloc& e)
	{
		std::cerr << "ERROR: allocation failed (exception: " << e.what() << ")\n";
	}


	//-----------------------------------------------------------------------
	// Вариант 3: Можем да укажем функция, която да се извика,
	// в случай, че заделянето с new не е успешно.
	std::set_new_handler(MyNewHandler);

	try
	{
		p = new int[SIZE];
	}
	catch (std::bad_alloc& e)
	{
		std::cerr << "ERROR: allocation failed (exception: " << e.what() << ")\n";
	}

	// Връщаме обратно стандартната функция, която
	// обработва случаите на неуспешно заделяне.
	std::set_new_handler(NULL);

	return 0;
}