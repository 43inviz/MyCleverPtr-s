#include <iostream>
#include "MySharedPtr.h"
#include "MyUniquePtr.h"
#include <string>

using namespace std;



int main() {

	//shared_ptr TEST
	/*MySharedPtr<string> sharedPtr(new string ("123123"));

	cout << "Count before: " << sharedPtr.getCount() << endl;
	MySharedPtr<string> sharedPtr2 = sharedPtr;
	cout << "Count afte: " << sharedPtr2.getCount() << endl;
	
	cout << "PTR1: " << *sharedPtr << endl;
	cout << "PTR2: " << *sharedPtr2 << endl;*/


	//Unique_ptr TEST

	MyUniquePtr<string> ptr1(new string("234234"));
	cout << *ptr1 << endl;
	MyUniquePtr<string> ptr2 = ptr1;
	if (ptr1.get() == nullptr) {
		cout << "PTR1 is Empty\n";
	}
	else {
		cout << "ptr1 not del\n";
	}


	return 0;
}