#include <conio.h>
#include <iostream>
#include <cmath>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <random>
using namespace std;
// ���� "������ �����"
mt19937 mersenne{ static_cast<mt19937::result_type>(time(0)) };//�������������� ����� �������� �� ������ �������. (����� ���������������� � ����� ����������� ������� ���������)
int getRandomNumber(int min, int max)//������� ������� ��������� �� ������ �����
{//�� ������������ ����� ���������� �� min �� max
	uniform_int_distribution<> myrandom{ min, max };//uniform_int_distribution - �����, ������� ������������ ����������� � �������������� ������������� ����� �� ����� ���������
	return myrandom(mersenne);
}
void Info()
{
	cout << "����� ���������� � ���� \"������ �����\" \n��� ������ ��� ���� ������� �����, ���������� �����������.\n" <<
		"� ��� ���� 7 �������. ����� ������ �� ��� ��� ������� ���� ��� ���� ��������� ����� �����. \n";
	_getch();
	system("cls");
}
bool Check(int r)
{
	int c;

	cout << "������� �������� �� 1 �� 100" << endl;
	while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{

		cin >> c;
		if (cin.fail()) // ���� ���������� ���������� ��������� ���������,
		{
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			cout << "�� ����� �� ������ ��������";
		}
		else
		{
			std::cin.ignore(32767, '\n'); // ������� ������ ��������
			break;
		}
	}
	if (c <= r)
	{
		if (c == r)
		{
			cout << "�����������! �� �������!\n";
			return true;
		}
		else {
			cout << "���������� ������� ��������\n\n";
			return false;
		}
	}
	else {
		cout << "���������� ������� ��������\n\n";
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
	cout << "���� ��������" << endl;
	_getch();
	system("cls");
	while (true)
	{
		cout << "������ ������� ��� ���? (Y/N) " << endl;
		cin >> f;
		if (f == 'Y')
			goto mark;
		else if (f == 'N')
			return 0;
		else cout << "�� ������ ��������" << endl;
	}


}