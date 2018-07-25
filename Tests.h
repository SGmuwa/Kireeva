/*
Файл для тестирования данного проекта.
Автор: Сидоренко Михаил Павлович [SG]Muwa https://github.com/SGmuwa
2018 год.
*/

#pragma once

// Запускает тестирование поиска максимального пути.
void runTest()
{
	unsigned * x;
	unsigned path;
	unsigned(*getMaxPath)(size_t, unsigned*) = getMaxPath_Maria;

	// Инцилизация входных данных в формате {y, x1, x2, x3, ...} или {x0, x1, x2, x3}.
	x = new unsigned[1]{ 0 }; 
	// Выполнение программы.
	path = getMaxPath(1, x);
	// Узнаём, является ли ответ не правильным.
	if (path != 0)
		// Ответ оказался не правильным. Выводим отчёт: номер теста; какой результат получился.
		printf("0 error. %u\n", path);
	// Деинцилизируем входные данные, чтобы очистить оперативную память.
	delete x;

	x = new unsigned[2]{ 0, 1 };
	path = getMaxPath(2, x);
	if (path != 1)
		printf("1 error. %u\n", path);
	delete x;

	x = new unsigned[3]{ 0, 1, 2 };
	path = getMaxPath(3, x);
	if (path != 2)
		printf("2 error. %u\n", path);
	delete x;

	x = new unsigned[2]{ 0, 2 };
	path = getMaxPath(2, x);
	if (path != 2)
		printf("3 error. %u\n", path);
	delete x;

	x = new unsigned[4]{ 0, 2, 4, 2 };
	path = getMaxPath(4, x);
	if (path != 4)
		printf("4 error. %u\n", path);
	delete x;

	x = new unsigned[4]{ 1, 2, 4, 2 };
	path = getMaxPath(4, x);
	if (path != 3)
		printf("5 error. %u\n", path);
	delete x;

	x = new unsigned[2]{ 10, 2 };
	path = getMaxPath(2, x);
	if (path != 8)
		printf("6 error. %u\n", path);
	delete x;
}