#include <conio.h>
#include <iostream>
#include <cmath>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <random>
using namespace std;
// Игра "Угадай число"
mt19937 mersenne{ static_cast<mt19937::result_type>(time(0)) };//инициализируем Вихрь Мерсенна на основе времени. (можно инициализировать в своей собственной области видимости)
int getRandomNumber(int min, int max)//создаем функцию генерации на основе вихря
{//он распределяет числа равномерно от min до max
	uniform_int_distribution<> myrandom{ min, max };//uniform_int_distribution - класс, который обеспечивает равномерное и равновероятное распределение чисел по всему диапазону
	return myrandom(mersenne);
}
void Info()
{
	cout << "Добро пожаловать в игру \"Угадай число\" \nДля победы Вам надо угадать число, загаданное компьютером.\n" <<
		"У Вас есть 7 попыток. После каждой из них Вам сообщат выше или ниже требуется брать число. \n";
	_getch();
	system("cls");
}
bool Check(int r)
{
	int c;

	cout << "Введите значение от 1 до 100" << endl;
	while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{

		cin >> c;
		if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << "Вы ввели не верное значение";
		}
		else
		{
			std::cin.ignore(32767, '\n'); // удаляем лишние значения
			break;
		}
	}
	if (c <= r)
	{
		if (c == r)
		{
			cout << "Поздравляем! Вы угадали!\n";
			return true;
		}
		else {
			cout << "Попробуйте большее значение\n\n";
			return false;
		}
	}
	else {
		cout << "Попробуйте меньшее значение\n\n";
		return false;
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
mark:
	int count(0);
	char f;
	Info();
	int r = getRandomNumber(1, 100);
	while (count < 7)
	{
		if (Check(r) != true)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	cout << "Игра окончена" << endl;
	_getch();
	system("cls");
	while (true)
	{
		cout << "Хотите сыграть еще раз? (Y/N) " << endl;
		cin >> f;
		if (f == 'Y')
			goto mark;
		else if (f == 'N')
			return 0;
		else cout << "Не верное значение" << endl;
	}


}