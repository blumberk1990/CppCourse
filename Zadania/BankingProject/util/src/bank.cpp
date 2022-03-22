#include <iostream>
#include "../libs/bank.h"
#include <fstream>

using namespace std;

Bank::Bank() {
    Account account;
    ifstream inFile;
    
    inFile.open(INPUT_FILE_PATH);
    if(!inFile) {
        cout<<"Please check the file's existance."<<endl;
        //ret when it will go as a function
    }
    //Reading Account object from file
    while(!inFile.eof()) {
        inFile>>account;
        accounts.insert(AccountPair(account.getAccountNumber(), new Account(account)));
    }
    Account::setNextAccountNumber(account.getAccountNumber());
    inFile.close();
}

Account* Bank::openAccount(string firstName, string lastName, float balance) {
    ofstream outFile;
            
    outFile.open(INPUT_FILE_PATH, ios::app);
    if(!outFile) {
        cout<<"Please check the file's existance. No possibility to create ne account. try again."<<endl;
        //ret when it will go as a function
    }
    accounts.insert(AccountPair(Account::getLastAccountNumber()+1, new Account(firstName, lastName, balance)));
    AccountIterator itr;
    itr = accounts.end();
    --itr;
    outFile<<*itr->second;
    cout<<"Account has been created."<<endl;
    outFile.close();
    return itr->second;
}

Account* Bank::balanceEnquiry(long accountNumber) {
    AccountIterator itr = accounts.find(accountNumber); 
    cout<<"Account number: "<<itr->first<<endl
        <<"Balance: "<<itr->second->getBalance()<<endl;
    return itr->second;
}

Account* Bank::deposit(long accountNumber, float ammount) {
    AccountIterator itr = accounts.find(accountNumber); 
    itr->second->setBalance(itr->second->getBalance() + ammount);
    cout<<"Account number: "<<itr->first<<endl
        <<"Balance after deposit: "<<itr->second->getBalance()<<endl;
    return itr->second;
}

Account* Bank::withdraw(long accountNumber, float ammount) {
    AccountIterator itr = accounts.find(accountNumber);
    itr->second->setBalance(itr->second->getBalance() - ammount);
    cout<<"Account number: "<<itr->first<<endl
        <<"Balance after withdraw: "<<itr->second->getBalance()<<endl;
    return itr->second; 
}

void Bank::closeAccount(long accountNumber, float ammount) {
    AccountIterator itr = accounts.find(accountNumber);
    accounts.erase(itr);
    //update for Bank.data
}

void Bank::showAllAccount() {
    AccountIterator itr;
    for(itr=accounts.begin(); itr!=accounts.end(); itr++) {
        cout<<*itr->second<<endl;
    }            
}

Bank::~Bank() {}

