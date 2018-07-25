#pragma once

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