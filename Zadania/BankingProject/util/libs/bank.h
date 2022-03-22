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
        
    public:
    map<long, Account*> accounts;
        Bank();
        Account* openAccount(string firstName, string lastName, float balance);
        Account* balanceEnquiry(long accountNumber);
        Account* deposit(long accountNumber, float ammount);
        Account* withdraw(long accountNumber, float ammount);
        void closeAccount(long accountNumber, float ammount);
        void showAllAccount();
        ~Bank();
    };

    
#endif