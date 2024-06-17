#include "Card.h"
#define DEBUG

Card::Card()
{
	cardNumber = rand() + 10'000;
	strcpy_s(name, 50, "undefined");
	strcpy_s(expiredDate, 6, "01.34");
	PIN = rand() % 10'000;
	cash = 0;

#ifdef DEBUG
	cout << "Card(): " << cardNumber << endl;
#endif // DEBUG

	cout << "Opened standart card: " << cardNumber << endl;
}

Card::Card(const char* client_name, double money)
{
	cardNumber = rand() + 10'000;
	strcpy_s(name, 50, client_name);	//!!!
	strcpy_s(expiredDate, 6, "01.34");
	PIN = rand() % 10'000;
	cash = money;						//!!!

#ifdef DEBUG
	cout << "Card(): " << cardNumber << endl;
#endif // DEBUG

	cout << "Opened VIP card: " << cardNumber << endl; //!!!
}

Card::~Card()
{
#ifdef DEBUG
	cout << "~Card(): " << cardNumber << endl;
#endif // DEBUG
	cout << "Closed card: " << cardNumber << endl;
}

int Card::getCardNumber(){		return cardNumber;}

const char* Card::getName(){	return name;}

const char* Card::getExpDate(){	return expiredDate;}

int Card::getPIN(){		return PIN;}

double Card::getCash(){		return cash;}

void Card::setPIN(int oldPIN, int newPIN)
{
	if (oldPIN == PIN) {
		PIN = newPIN;
	}
	else cout << "Error: PIN is not correct!!!\n";
}

void Card::showInfo()
{
	cout << "\n++++++++++++++++++++++++++++++++++\n";
	cout << "|\tCard:     " << cardNumber << endl;
	cout << "|\tClient:   " << name << endl;
	cout << "|\tCash:     " << cash << " UAH" << endl;
	cout << "++++++++++++++++++++++++++++++++++\n";
	cout << "|\tExp date: " << expiredDate << endl;
	cout << "|\tPIN:      " << PIN << endl;
	cout << "++++++++++++++++++++++++++++++++++\n\n";
}

void Card::topupCash(int money, int carNumber, int PIN)
{
	if (money < 0) cout << "Error: money < 0!!!\n";
	else if (this->cardNumber != carNumber) cout << "Error: carNumber not found!!!\n";
	else if (this->PIN != PIN) cout << "Error: PIN is not correct!!!\n";
	else {
		cash += money;
	}
}

void Card::withdrawCash(int money, int PIN)
{
	if (this->PIN != PIN) cout << "Error: PIN is not correct!!!\n";
	else if (money > cash) cout << "Error:money > cash!!!\n ";
	else {
		cash -= money;
	}
}
