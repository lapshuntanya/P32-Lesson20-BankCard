#include "Card.h"
#include <ctime>

int main()
{
	srand(time(0));
	int user = 0;
	Card* privat = nullptr;

	cout << "0 - Standart card\n";
	cout << "1 - VIP card\n";
	cin >> user;

	if (user == 0) {
		privat = new Card();//Конструктор за замовченням
	}
	else {
		privat = new Card("Lapshun Tetiana", 1'000); //Конструктор з параметрами
	}

	privat->showInfo();
	 

	delete privat;
}

