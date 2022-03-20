#include "../libs/account.h"
using namespace std;

long Account::nextAccountNumber = 0;

Account::Account(/* args */) {};
Account::Account(string firstName, string lastName, float balance) {
    Account::setFirstName(firstName);
    Account::setLastName(lastName);
    Account::setBalance(balance);
    Account::setFirstName(firstName);
    Account::setAccountNumber(); 
}
long Account::getAccountNumber() { return this->accountNumber; }
string Account::getFirstName() { return this->firstName; }
string Account::getLastName() { return this->lastName; }
float Account::getBalance() { return this->balance; }
long Account::getLastAccountNumber() { return Account::nextAccountNumber; }

void Account::setAccountNumber() {
    this->accountNumber = getLastAccountNumber();
    setNextAccountNumber(getLastAccountNumber()+1);
}    
void Account::setFirstName(string firstName) {
    this->firstName = firstName;
}
void Account::setLastName(string lastName) {
    this->lastName = lastName;
}
void Account::setBalance(float balance) {
    this->balance = balance;
}
void Account::setNextAccountNumber(long accountNumber) {
    Account::nextAccountNumber = accountNumber;
}
void Account::deposit(float amount) {
    setBalance(getBalance() + amount);
    cout<<"You have deposit: "<<amount<<", actual balance: "<<getBalance()<<endl;
}
void Account::withdraw(float amount) {
    setBalance(getBalance() - amount);
    cout<<"You have withdraw: "<<amount<<", actual balance: "<<getBalance()<<endl;
}
void Withdraw(float amount);
        
    //friend ofstream & operator<<(ofstream &ofs, Account acc);
    //friend ifstream & operator>>(ifstream &ifs, Account acc);

ostream & operator<<(ostream &os, Account acc) {
    os<<"Acount data: "<<endl<<"First Name: "<<acc.getFirstName()<<endl
                                <<"Last Name: "<<acc.getLastName()<<endl
                                <<"Balance: "<<acc.getBalance()<<endl
                                <<"Account number: "<<acc.getAccountNumber()<<endl; 
    return os;
}
Account::~Account() {}
