// Kireeva.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

// Функция ищет максимальный путь из заданных точек. x[0] - точка старт.
// size_t N - Количество точек.
// unsigned * x - Указатель на массив точек.
// Возвращает: максимальный путь (?).
unsigned getMaxPath_Maria(size_t N, unsigned * x) // Выделение отдельной функции.
{
	if (N < 1 || x == nullptr) return -1; // Если не правильно.
	unsigned kmax = 0, k = 0;
	for (int i = 1; i < N; i++) {
		if (x[0]<x[i])
			k += x[i] - x[0];
		else
		{
			if (k > kmax)
				kmax = k;
			k = 0;
		}
		x[0] = x[i];
	}
	if (k>kmax)
		kmax = k;
	return kmax;
}

// Запускает графический интерфейс с пользователем.
// Возвращает: код ошибки. 0 - нет ошибок.
int startUserInterface()
{
	unsigned N;
	printf("N = ");
	scanf_s("%u", &N);
	if (N < 1)
	{
		printf("Error: must N >= 1!");
		return 1;
	}
	unsigned * x = new unsigned[N];
	if (x == nullptr)
	{
		printf("I can't create array int power %d", N);
		return 2;
	}
	for (unsigned i = 0; i < N; i++)
	{
		printf("x%d = ", i);
		scanf_s("%d", x + i);
	}
	int ret = getMaxPath_Maria(N, x);
	printf("%d", ret);
	return ret;
}

// Запускает тестирование поиска максимального пути.
void runTest()
{
	unsigned * x;
	unsigned path;
	unsigned (*getMaxPath)(size_t, unsigned*) = getMaxPath_Maria;

	x = new unsigned[1]{ 0 };
	path = getMaxPath(1, x);
	if (path != 0)
		printf("0 error. %u %u\n", x[0], path);
	delete x;

	x = new unsigned[2] { 0, 1 };
	path = getMaxPath(2, x);
	if (path != 1)
		printf("1 error. %u %u\n", x[1], path);
	delete x;

	x = new unsigned[3] { 0, 1, 2 };
	path = getMaxPath(3, x);
	if (path != 2)
		printf("2 error. %u %u\n", x[2], path);
	delete x;

	x = new unsigned[2] { 0, 2 };
	path = getMaxPath(2, x);
	if (path != 2)
		printf("3 error. %u %u\n", x[1], path);
	delete x;

	x = new unsigned[4] { 0, 2, 4, 2 };
	path = getMaxPath(4, x);
	if (path != 4)
		printf("4 error. %u %u\n", x[3], path);
	delete x;

	x = new unsigned[4] { 1, 2, 4, 2 };
	path = getMaxPath(4, x);
	if (path != 3)
		printf("5 error. %u %u\n", x[3], path);
	delete x;

	x = new unsigned[2]{ 10, 2 };
	path = getMaxPath(2, x);
	if (path != 8)
		printf("6 error. %u %u\n", x[1], path);
	delete x;
}

int main() {
	printf("Start test...\n");
	runTest();
	printf("Exit...\n");
	scanf_s("%*c");
	return 0;
}