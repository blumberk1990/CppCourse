#include <iostream>
#include "../util/libs/account.h"

using namespace std;

int main() {

    Account acc("Jan", "Piszczal", 5000);
    cout<<acc<<endl;
    acc.deposit(500);
    cout<<acc<<endl;
    Account acc1("Jan", "pinkala", 5000);
    cout<<acc1<<endl;
    acc1.withdraw(500);
    cout<<acc1<<endl;
    return 0;
}