// InfixToPostfix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Stack
{
private:
	char *elemanlar;
	int indis;
public:
	Stack()
	{
		elemanlar=new char[20];
		indis=0;
	}
	bool push(char c)
	{
		indis++;
		*(elemanlar+indis)=c;
		return 1;
	}
	bool pop(char &a)
	{
		if(!isEmpty())
		{
			a=*(elemanlar+indis);
			indis--;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	bool top(char &b)
	{
		if(isEmpty())
		{
			return 0;
		}
		else
		{
			b=*(elemanlar+indis);
			return 1;
		}
		
	}
	bool isEmpty()
	{
		return (indis==0);
	}
};
bool OncelikliMi(char a1, char a2)
{
	if((a1=='*' || a1=='/') &&( a2=='+' || a2=='-'))
	{
		return true;
	}
	else if(a1==a2 || (a1=='*' && a2== '/' )|| (a1=='/' && a2=='*')|| (a1=='+' && a2== '-' )|| (a1=='-' && a2=='+')) 
		return 1;
	else
		return false;
}
bool isoperator(char c)
{
	switch (c)
	{
	case '+':
			 return true;
			 break;
	case '-':
			 return true;
			 break; 
	case '/':
			 return true;
			 break;		 
	case '*':
			 return true;
			 break;
	default:
		return false;
		break;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	char *infix="(5+3)*(7*2+6/3)";
	char *cikti=new char[100];
	int katar=0;
	char c,c2;
	Stack mystack;
	for(int i=0;*(infix+i)!='\0';i++)
	{
		c=*(infix+i);
		if(isdigit(c))
		{
			*(cikti+katar)=c;
			katar++;
		}
		else if(isoperator(c))
		{
			while(!mystack.isEmpty())
			{
				mystack.top(c2);
				if(c2=='(')
				{
					break;
				}
				else if(isoperator(c2))
				{
					if(OncelikliMi(c2,c))
					{
						mystack.pop(c2);
						*(cikti+katar)=c2;
						katar++;
						break;
					}
					else
					{
						break;
					}
				}
			}
			mystack.push(c);
		}
		else if(c=='(')
		{
			mystack.push(c);
		}
		else if(c==')')
		{
			mystack.top(c2);
			while(c2!='(')
			{
				mystack.pop(c2);
				if(isoperator(c2))
				{
					*(cikti+katar)=c2;
					katar++;
				}
				mystack.top(c2);
			}
			mystack.pop(c2);
		}
		
	}
	while(!mystack.isEmpty())
	{
		mystack.pop(c2);
		*(cikti+katar)=c2;
		katar++;
	}
	for (int i = 0; i < katar; i++)
	{
		cout<<*(cikti+i);
	}
	cout<<endl;
	system("pause");
	return 0;
}

