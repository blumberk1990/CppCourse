#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(int argc, char** argv) {
	
	int A[]={3,5,-2,9,-4,10,-24,19,81,-7,12,13};
	int sum = 0;
	int max = 0;
	int min = A[0];
	int len = 0;
	int key;
	int posCount = 0;
	int negCount = 0;
	
	// ex_1: display, using for each loop	
	// ex_2: sum of array
	// ex_3: max value of array
	// ex_6: count number of negative and positive numnbers in Array
	

	len = sizeof(A)/sizeof(A[0]);
	
    for(auto x:A) {
    
		if(x > max) {
    		max = x;
		}
		if(x < min) {
    		min = x;
		}
	
		if(x > 0) {
			posCount++;
		} else {
			negCount++;
		}
		
    	sum = sum + x;
	
		cout << x << " ";
	
	}
	
    
	cout << "\n" << "sum of A is equal to: " << sum << endl;
	cout << "max value of A array is: " << max << endl;
	cout << "min value of A array is: " << min << endl;
	cout << "Array A contains, " << posCount << " positive numbers and " <<  negCount << " negative numbers" << endl;

	// ex_4: linear search	
	cout << "Linear sort!" << endl;
	cout << "numbers of element in array is: " << len << endl;
	cout << "Enter the value you want to find: ";
	cin >> key;
	
	for(int i=0; i<len; i++) {
		if(A[i] == key) {
			cout << "Key was found in position: " << i+1 << endl;
		}	
	}
	cin.clear();
	// ex_5: binary search, have to be sorted array
	cout << "Binary sort!" << endl;	

	sort(A, A+len);
	
	int low = 0;
	int high = len-1;
	
	
	while(low <= high){
		int mid = (low + high)/2;
		if(key == A[mid]) {
			cout << "Key was found in position: " << mid+1 << endl;
			break;
		} else if(key < A[mid]) {
			high = mid-1;
		} else {
			low = mid+1;
		}
	}
	

	
	

	
	
	
	
	
	
	return 0;
}
