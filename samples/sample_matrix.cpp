// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "tmatrix.h"
//---------------------------------------------------------------------------

void main()
{
	int LO = -5;
	int HI = 5;
	int num;
	srand((time(0)));
	setlocale(LC_ALL, "Russian");
	cout << "Тестирование класс работы с матрицами" << endl;
	cout << "Введите размерность матрицы: ";
	size_t sz = 0;
	cin >> sz;
	TDynamicMatrix<int> a(sz), b(sz), c(sz);
	cout << "Выберите операцию (введите номер): " << endl;
	cout << "1.Матрица * матрица" << endl;
	cout << "2.Матрица + матрица" << endl;
	cout << "3.Матрица * число" << endl;
	size_t choose = 0;
	cin >> choose;
	cout << "Нажмите 1 для автоматической генерации матриц." << endl;
	cout << "Нажмите 2 для заполнения матриц с клавиатуры." << endl;
	size_t genType = 0;
	cin >> genType;
	if (choose == 3)
	{
		switch (genType)
		{
		case 1:
			num = LO + (rand() / (RAND_MAX / (HI - LO)));
			for (int i = 0; i < sz; i++)
			{
				for (int j = 0; j < sz; j++)
				{
					a[i][j] = LO + (rand() / (RAND_MAX / (HI - LO)));
				}
			}
			break;
		case 2:
			cout << "Введите первую матрицу: ";
			cin >> a;
			cout << "Введите число: ";
			cin >> num;
			break;
		default:
			cout << "Неверный номер!";
			break;
		}
	}
	else
	{
		switch (genType)
		{
		case 1:
			for (int i = 0; i < sz; i++)
			{
				for (int j = 0; j < sz; j++)
				{
					a[i][j] = LO + (rand() / (RAND_MAX / (HI - LO)));
					b[i][j] = LO + (rand() / (RAND_MAX / (HI - LO)));
				}
			}
			break;
		case 2:
			cout << "Введите первую матрицу: ";
			cin >> a;
			cout << "Введите вторую матрицу: ";
			cin >> b;
			break;
		default:
			cout << "Неверный номер!";
			break;
		}
	}
	switch (choose)
	{
	case 1:
		cout << a << endl;
		cout << "\t * " << "\n\n";
		cout << b << endl;
		cout << "\t = " << "\n\n";
		c = a * b;
		cout << c << endl;
		break;
	case 2:
		cout << a << endl;
		cout << "\t + " << "\n\n";
		cout << b << endl;
		cout << "\t = " << "\n\n";
		c = a + b;
		cout << c << endl;
		break;
	case 3:
		cout << a << endl;
		cout << "\t * " << "\n\n";
		cout << num << endl;
		cout << "\t = " << "\n\n";
		c = a * num;
		cout << c << endl;
		break;
	default:
		cout << "Неверный номер!";
		break;
	}
}
//---------------------------------------------------------------------------
