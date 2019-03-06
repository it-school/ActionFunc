#include "stdafx.h"
//Готовый вариант
#include <iostream>
#include <ctime>

using namespace std;
int const N = 3;
int field[N][N];
int n = 0;
char name1[30] = "Игрок";
char name2[30] = "Компьютер";

void printField(int field[N][N])
{
	cout << endl << " -----------------" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << "| " << (field[i][j] == 1 ? " X" : field[i][j] == 2 ? " O" : "  ") << "  ";
		}
		cout << "|" << endl << "|-----------------|" << endl;
	}
}

void fillField(int field[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			field[N][N] = 0;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	fillField(field);
	printField(field);
	int x, y, turn;
	turn = rand() % 2;
	do
	{
		if (turn % 2 == 0)
		{
			for (;;)
			{
				cout << "Ваш ход: " << endl;
				cout << endl << "X: ";
				cin >> x;
				cout << endl << "Y: ";
				cin >> y;
				x = x - 1;
				y = y - 1;
				if ((x >= 0 && x <= 3) && (y >= 0 && y <= 3) && (field[x][y] == 0))
				{
					field[x][y] = 1;
					break;
				}
			}
		}
		else
		{
			cout << name2;
			for (; ;)
			{
				x = rand() % 3;
				y = rand() % 3;
				if ((field[x][y] == 1) || (field[x][y] == 2) || (x < 0) || (y < 0))
				{
				}
				else
				{
					field[x][y] = 2;
					break;
				}
			}
		}
		printField(field);

		//проверка строк		
		for (int row = 0; row < N; row++)
		{
			if ((field[row][0] == 1 && field[row][1] == 1 && field[row][2] == 1))
			{
				cout << name1 << " Победитель" << endl;
				system("Pause");
				return 0;
			}
			else if ((field[row][0] == 2 && field[row][1] == 2 && field[row][2] == 2))
			{
				cout << name2 << " Победитель" << endl;
				system("Pause");
				return 0;
			}
		}

		//проверка столбцов
		for (int cols = 0; cols < N; cols++)
		{
			if (field[0][cols] == 1 && field[1][cols] == 1 && field[2][cols] == 1)
			{
				cout << name1 << " Победитель" << endl;
				system("Pause");
				return 0;
			}
			else if (field[0][cols] == 2 && field[1][cols] == 2 && field[2][cols] == 2)
			{
				cout << name2 << " Победитель" << endl;
				system("Pause");
				return 0;
			}
		}
		//побочная диагональ
		if (field[0][3] == 1 && field[1][2] == 1 && field[3][1] == 1)
		{
			cout << name1 << " Победитель" << endl;
			system("Pause");
			return 0;
		}
		else if (field[0][3] == 2 && field[1][2] == 2 && field[3][1] == 2)
		{
			cout << name2 << " Победитель" << endl;
			system("Pause");
			return 0;
		}
		//	главная диагональ	
		if (field[0][0] == 1 && field[1][1] == 1 && field[2][2] == 1)
		{
			cout << name1 << " Победитель" << endl;
			system("Pause");
			return 0;
		}
		else if (field[0][0] == 2 && field[1][1] == 2 && field[2][2] == 2)
		{
			cout << name2 << " Победитель" << endl;
			system("Pause");
			return 0;
		}
		turn++;
	} while (turn <= 9);
	system("Pause");
	return 0;
}

