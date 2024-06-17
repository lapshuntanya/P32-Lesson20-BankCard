#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Card
{
	//          Властивості - змінні класу
	int		cardNumber;		// Номер картки
	char	name[50];			// Ім’я власника
	char	expiredDate[6];		// Дата дії
	int		PIN;				// Код картки
	double	cash;				// Сума грошей на картці


	//			Методи - поведінка - функції класу
public:
	Card(); // Конструктор за замовченням
	Card(const char* client_name, double money); // Конструктор з параметрами
	~Card(); //Деструктор

	void showInfo();
};

