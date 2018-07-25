#pragma once

// Запускает тестирование поиска максимального пути.
void runTest()
{
	unsigned * x;
	unsigned path;
	unsigned(*getMaxPath)(size_t, unsigned*) = getMaxPath_Maria;

	x = new unsigned[1]{ 0 };
	path = getMaxPath(1, x);
	if (path != 0)
		printf("0 error. %u %u\n", x[0], path);
	delete x;

	x = new unsigned[2]{ 0, 1 };
	path = getMaxPath(2, x);
	if (path != 1)
		printf("1 error. %u %u\n", x[1], path);
	delete x;

	x = new unsigned[3]{ 0, 1, 2 };
	path = getMaxPath(3, x);
	if (path != 2)
		printf("2 error. %u %u\n", x[2], path);
	delete x;

	x = new unsigned[2]{ 0, 2 };
	path = getMaxPath(2, x);
	if (path != 2)
		printf("3 error. %u %u\n", x[1], path);
	delete x;

	x = new unsigned[4]{ 0, 2, 4, 2 };
	path = getMaxPath(4, x);
	if (path != 4)
		printf("4 error. %u %u\n", x[3], path);
	delete x;

	x = new unsigned[4]{ 1, 2, 4, 2 };
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