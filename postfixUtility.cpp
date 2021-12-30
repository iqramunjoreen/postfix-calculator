#include "postfixUtility.h"

float evaluatePostfix (string& pexp);
int convert (string a);
string getPostfix (string nexp);


int convert (string a)
{
	int i;
	istringstream potato(a);
	potato>>i;
	return i;
}

float evaluatePostfix (string& pexp)
{
	genericLinkedListStack<float> iqra; string temp=""; int temp2=0; int digit1, digit2;

	for (int i=0;i<pexp.size();i++)
	{
		if (isspace(pexp[i]))
		{
			if (temp!="")
				{
					temp2=convert(temp);
					iqra.push(temp2*1.0);
					temp="";
				}
			continue;
		}
		if (pexp[i]>='0' && pexp[i]<='9') //is a digit
		{
			temp+=pexp[i];
			continue;
		}
		else if (pexp[i]=='+'||pexp[i]=='-'||pexp[i]=='*'||pexp[i]=='/')
		{
			if (temp!="")
			{
				temp2=convert(temp);
				iqra.push(temp2*1.0);
				temp="";
			}

			if (pexp[i]=='+')
			{
				digit2=iqra.top();
				iqra.pop();
				digit1=iqra.top();
				iqra.pop();
				iqra.push((digit1*1.0)+(digit2*1.0));
				digit1=0; digit2=0;
				continue;
			}
			if (pexp[i]=='-')
			{
				digit2=iqra.top();
				iqra.pop();
				digit1=iqra.top();
				iqra.pop();
				iqra.push((digit1*1.0)-(digit2*1.0));
				digit1=0; digit2=0;
				continue;
			}
			if (pexp[i]=='*')
			{
				digit2=iqra.top();
				iqra.pop();
				digit1=iqra.top();
				iqra.pop();
				iqra.push(digit1*1.0*digit2*1.0);
				digit1=0; digit2=0;
				continue;
			}
			if (pexp[i]=='/')
			{
				digit2=iqra.top();
				iqra.pop();
				digit1=iqra.top();
				iqra.pop();
				iqra.push((digit1*1.0)/(digit2*1.0));
				digit1=0; digit2=0;
				continue;
			}
		}
	}
	return iqra.top();
}


string getPostfix (string nexp)
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
			ans+=" ";
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
}
