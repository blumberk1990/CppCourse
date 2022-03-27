#ifndef BANK_H
#define BANK_H

    #include <iostream>
    #include <map>
    #include "account.h"
    #define INPUT_FILE_PATH "../util/data/Bank.data"
    typedef pair<long, Account*> AccountPair;
    typedef map<long, Account*>::iterator AccountIterator;
    
    using namespace std;
    
    //Clas as a conteiner
    class Bank
    {
    private:
        map<long, Account*> accounts;
    public:
    
        Bank();
        Account* const openAccount(string firstName, string lastName, float balance);
        Account* const balanceEnquiry(long accountNumber);
        Account* const deposit(long accountNumber, float ammount);
        Account* const withdraw(long accountNumber, float ammount);
        void closeAccount(long accountNumber);
        void showAllAccount();
        ~Bank();
    };

    
#endif