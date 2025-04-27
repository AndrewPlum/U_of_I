
#include <iostream>
using namespace std;
int main()
{
	int x;
	
	cout << "Enter a value for x" << endl;
	do{
	cout << "x: ";
	cin >> x >> endl;
	cout << "x = " << x << endl;
	} while(x > 5);
}



/*
#include <iostream>
using namespace std;
 
int main () {
   // Local variable declaration:
   int a = 10;

   // do loop execution
   do {
      cout << "value of a: " << a << endl;
      a = a + 1;
   } while( a < 20 );
 
   return 0;
}
*/
