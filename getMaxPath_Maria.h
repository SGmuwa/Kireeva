/*
Файл содержит функцию для поиска максимального пути.
Автор: Киреева Мария
Соавтор: Сидоренко Михаил Павлович [SG]Muwa https://github.com/SGmuwa
2018 год.
*/

#pragma once

// Функция ищет максимальный путь из заданных точек. x[0] - точка старт.
// size_t N - Количество точек.
// unsigned * x - Указатель на массив точек.
// Возвращает: максимальный путь (?).
unsigned getMaxPath_Maria(size_t N, unsigned * x) // Выделение отдельной функции.
{
	if (N < 1 || x == nullptr) return -1; // Если не правильно отправлены данные.
	unsigned kmax = 0, k = 0;
	for (size_t i = 1; i < N; i++) {
		if (x[0] < x[i])
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

using namespace std;
// Функция ищет максимальный путь из заданных точек. Выполняется независимо. Работает с пользователем.
// Данная функция является исходным кодом Марии.
int getMaxPath_Maria_UserInterface() {
	int kmax, k, N, i, x, y;
	cin >> N;
	kmax = k = 0;
	cin >> y;
	for (i = 1; i<N; i++) {
		cin >> x;
		if (y<x)
			k += x - y;
		else
		{
			if (k > kmax)
				kmax = k;
			k = 0;
		}
		y = x;
	}
	if (k>kmax)
		kmax = k;
	cout << kmax;
	return 0;
}