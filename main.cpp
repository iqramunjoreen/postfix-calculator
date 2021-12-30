#include "postfixUtility.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	string a=argv[1];
	string b=getPostfix(a);
	float c=evaluatePostfix(b);
	cout<<c<<endl;

	/*string b="(4+3* 12)/ ( 12+ 3/ 2+ 46 /4)";
	cout<< b <<endl;
	string c= getPostfix(b);                             
	cout << c <<endl;
	float a=evaluatePostfix (c);
	cout<< a <<endl;
	*/

	return 0;
}