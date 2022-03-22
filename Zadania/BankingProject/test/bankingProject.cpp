#include <iostream>
#include "../util/libs/account.h"
#include "../util/libs/bank.h"

using namespace std;

int main() {
    Bank bank;
    bank.openAccount("Jan", "Piszczal", 5000);
    bank.showAllAccount();

    bank.balanceEnquiry(2);

    

    //Account acc("Jan", "Piszczal", 5000);
    //bank.openAccount("Jan", "Piszczal", 5000);
    //cout<<acc<<endl;
    //acc.deposit(500);
    //cout<<acc<<endl;
    Account acc1("Jan", "pinkala", 5000);
    cout<<acc1<<endl;
    acc1.withdraw(500);
    cout<<acc1<<endl;
    return 0;
}