#ifndef ACCOUNT_H
#define ACCOUNT_H

    #include <iostream>
    #include <fstream>
    using namespace std;

    class Account
    {
    private:
        long accountNumber;
        string firstName;
        string lastName;
        float balance;
        static long nextAccountNumber;
    public:
        Account(/* args */);
        Account(string firstName, string lastName, float balance);

        long getAccountNumber();
        string getFirstName();
        string getLastName();
        float getBalance();
        static long getLastAccountNumber();
        
        void setAccountNumber();
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setBalance(float balance);
        static void setNextAccountNumber(long accountNumber);

        void deposit(float amount);
        void withdraw(float amount);
        
        friend ofstream & operator<<(ofstream &ofs, Account &acc);
        friend ifstream & operator>>(ifstream &ifs, Account &acc);
        friend ostream & operator<<(ostream &os, Account &acc);
        ~Account();
    };
#endif