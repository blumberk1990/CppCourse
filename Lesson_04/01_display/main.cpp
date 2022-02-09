#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	int A[] = {2, 4, 6, 8, 10, 1};
	int sum = 0;
	int max = 0;

	// ex_1: display, using for each loop	
	// ex_2: sum of array
	// ex_3: max value of array
	
    for(auto x:A) {
    
		if(x > max) {
    		max = x;
		}
	
    	sum = sum + x;
	
		cout << x << " ";
	
	}
    
	cout << "\n" << "sum of A is equal to: " << sum << endl;
	cout << "max value of A array is: " << max << endl;
	return 0;
}
