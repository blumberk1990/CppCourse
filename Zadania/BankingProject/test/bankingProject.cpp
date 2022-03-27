#include <iostream>
//##include "../util/libs/account.h"
#include "../util/libs/bank.h"

using namespace std;

int main() {
    Bank bank;
    Account *account;
    string firstName, lastName;
    float balance, amount;
    long accountNumber;
    int option;
    cout<<"****Bank MGD****"<<endl;
    do {
        cout<<"\n\tSelect one option below ";
        cout<<"\n\t1 Open an Account";
        cout<<"\n\t2 Balance Enquiry";
        cout<<"\n\t3 Deposit";
        cout<<"\n\t4 Withdrawal";
        cout<<"\n\t5 Close an Account";
        cout<<"\n\t6 Show All Accounts";
        cout<<"\n\t7 Quit";
        cout<<"\nEnter your choice: ";
        cin>>option;
        switch(option) {
            case 1:
                cout<<"Enter first Name: ";
                cin>>firstName;
                cout<<"Enter last name: ";
                cin>>lastName;
                cout<<"Enter balance: ";
                cin>>balance;
                account = bank.openAccount(firstName, lastName, balance);
                cout<<"Done, account is created."<<endl;
                cout<<*account;
                break;
            case 2:
                cout<<"Enter account number: ";
                cin>>accountNumber;
                account = bank.balanceEnquiry(accountNumber);
                cout<<"Account details: "<<endl;
                cout<<*account;
                break;
            case 3:
                cout<<"Enter account number: ";
                cin>>accountNumber;
                cout<<"Enter amount: ";
                cin>>amount;
                account = bank.deposit(accountNumber, amount);
                cout<<"Account details: "<<endl;
                cout<<*account;
                break;
            case 4:
                cout<<"Enter account number: ";
                cin>>accountNumber;
                cout<<"Enter amount: ";
                cin>>amount;
                account = bank.withdraw(accountNumber, amount);
                cout<<"Account details: "<<endl;
                cout<<*account;
                break;
            case 5:
                cout<<"Enter account number: ";
                cin>>accountNumber;
                bank.closeAccount(accountNumber);
                cout<<"Account closed: "<<endl;
                break;
            case 6:
                bank.showAllAccount();
                cout<<"ok";
                break;
            case 7:
                break;
            default:
                cout<<"\nEnter corret option";
                exit(0);
        }
    } while(option!=7);

    return 0;
}