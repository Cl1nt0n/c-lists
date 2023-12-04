/**************************************************************************************************/
/*                                       Линейные списки                                          */
/**************************************************************************************************/
/*	Project Type	: Win64 Console Applicatoin                                                   */
/*	Progect Name	: Лаб.р. №1 lists-lab4													      */
/*	File Name		: Лаб.р. №1 main.cpp                                                          */
//*	Language		: CPP, MSVS ver 2022                                                          */
//*	Programmers		: Исламов Раиль Азатович, Чиняков Игорь Павлович М3О-210Б-22                  */
/*	Modified by		:                                                                             */
/*	Created			:                                                                             */
/*	Last Revision	:                                                                             */
/*                                                                                                */
/*________________________________________________________________________________________________*/
/*	Comment			: Однонаправленный целочисленный список, вар 7                                */
/**************************************************************************************************/

#include <iostream>
#include "list.h"
#include "header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	while (true)
	{
		cout << "Нажмите '1', чтобы создать список" << endl;
		int command;

		while (!(cin >> command) || command != 1)
		{
			cout << "Неверная команда. " << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}

		List list;

		print_menu();

		while (command != 5)
		{
			while (!(cin >> command) || (command < 1 || command > 5))
			{
				cout << "Неверная команда. " << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}

			switch (command)
			{
			case 1:
				list.print();
				cout << endl;
				print_menu();
				break;
			case 2:
				int numb;
				cout << "Введите число." << endl;
				while (!(cin >> numb))
				{
					cout << "Ошибка. Элемент должен быть числом. " << endl;
					cin.clear();
					cin.ignore(10000, '\n');
				}
				list.push_back(numb);
				cout << endl;
				print_menu();
				break;
			case 3:
				if (list.get_size() == 0)
				{
					cout << "Удаление невозможно. Список пуст." << endl; 
					break;
				}
				int index;
				cout << "Введите номер элемента." << endl;
				while (!(cin >> index) || index < 0 || index >= list.get_size())
				{
					cout << "Ошибка. Вводимое значение должно быть числом, меньшим размера листа и большим либо равным 0" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
				}
				list.erase(index);
				cout << endl;
				print_menu();
				break;
			case 4:
				cout << "Индекс максимального элемента: " << list.get_max_element() << endl;
				cout << endl;
				print_menu();
				break;
			case 5:
				list.clear();
				break;
			}
		}
	}

	system("pause");
	return 0;
}

void print_menu()
{
	cout << "1. Печать списка" << endl;
	cout << "2. Добавление элемента в список" << endl;
	cout << "3. Удаление элемента из списка" << endl;
	cout << "4. Поиск максимальногоэлемента в списке" << endl;
	cout << "5. Удаление списка" << endl;
}
