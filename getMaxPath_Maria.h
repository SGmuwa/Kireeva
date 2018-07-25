#pragma once

// Функция ищет максимальный путь из заданных точек. x[0] - точка старт.
// size_t N - Количество точек.
// unsigned * x - Указатель на массив точек.
// Возвращает: максимальный путь (?).
unsigned getMaxPath_Maria(size_t N, unsigned * x) // Выделение отдельной функции.
{
	if (N < 1 || x == nullptr) return -1; // Если не правильно.
	unsigned kmax = 0, k = 0;
	for (size_t i = 1; i < N; i++) {
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