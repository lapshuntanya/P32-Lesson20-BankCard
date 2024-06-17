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

	cout << "===========================================\n\n";
	int a = 0, b = 0;
	cout << "Input old PIN: "; cin >> a;
	cout << "Input new PIN: "; cin >> b;

	privat->setPIN(a, b);
	cout << "Card: " << privat->getCardNumber() << ", PIN: " << privat->getPIN() << endl;

	cout << "===========================================\n\n";
	cout << "Topup cash-> "; cin >> a;
	cout << "Input PIN: "; cin >> b;
	privat->topupCash(a, privat->getCardNumber(), b);
	cout << "\t Card: " << privat->getCardNumber() << " Cash: " << privat->getCash() << endl;
	cout << "===========================================\n\n";
	cout << "Withdraw cash-> "; cin >> a;
	cout << "Input PIN: "; cin >> b;
	privat->withdrawCash(a, b);
	cout << "\t Card: " << privat->getCardNumber() << " Cash: " << privat->getCash() << endl;

	delete privat;
}

