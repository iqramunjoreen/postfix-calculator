#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include "genericLinkedListStack.h"
using namespace std;

string getPostfix (string nexp);
float evaluatePostfix (string& pexp);
int convert (string a);

/*string getPostfix (string nexp)
{
	string a="";
	for (int i=0;i<nexp.size();i++)
	{
		if (isspace(nexp[i]))
			continue;
		else
			a+=nexp[i];
	}
	

	stack<char> operand;
	string ans="";

	for (int i=0;i<a.size();i++)
	{
		if (a[i]>='0' && a[i]<='9') //its a digit
		{
			ans+=a[i];
			continue;
		}
		if (a[i]=='(')
		{
			ans+=" ";                                  //tried this //didnt work
			operand.push(a[i]);
			continue;
		}
		if (a[i]==')')
		{
			ans+=" ";
			while (operand.top()!='(')
			{
				ans+=operand.top();
				operand.pop();
			}
			operand.pop();
			continue;
		}

		if (a[i]=='*'||a[i]=='+'||a[i]=='-'||a[i]=='/')  //incoming operand
		{
			ans+=" ";
			if (operand.empty()==1)
			{
				operand.push(a[i]);
				continue;
			}
			else if (operand.top()=='(')
			{
				operand.push(a[i]);
				continue;
			}
		}

		if ( (operand.top()=='+'||operand.top()=='-') && (a[i]=='*'||a[i]=='/') ) //higher precedence
		{
			operand.push(a[i]);
			continue;
		}
		if ( (operand.top()=='+'||operand.top()=='-') && (a[i]=='+'||a[i]=='-') ) //same precendence
		{
			ans+=operand.top();
			operand.pop();
			operand.push(a[i]);
			continue;
		}
		if ( (operand.top()=='*'||operand.top()=='/') && (a[i]=='*'||a[i]=='/') ) //same precendence
		{
			ans+=operand.top();
			operand.pop();
			operand.push(a[i]);
			continue;
		}
		if ( (operand.top()=='*'||operand.top()=='/') && (a[i]=='+'||a[i]=='-') )  //lower precendence
		{
			ans+=operand.top();
			operand.pop();
			operand.push(a[i]);
			continue;
		}
		else
			continue;
	}
	while (operand.empty()==0)
	{
		ans+=operand.top();
		operand.pop();
	}
	return ans;
}*/
