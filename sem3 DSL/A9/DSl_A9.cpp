#include <iostream>
using namespace std;

class stack
{
    char s[25];
    int top;
public :
    stack()
    {
        top=-1;
    }
    void push(char val)
    {
        if(top<=24)
        {
            top++;
            s[top]=val;
        }
        else
            cout<<"\n stack is full";
    }
    char pop()
    {
        char val;
        if(isempty()==0)
        {
            val=s[top];
            top--;
            return val;
        }
        else
        { cout<<"\n enter stack";
        return '*';
    }
    }
    bool isempty()
    {
        if(top==-1)
        {
            return 1;
        }
        else
            return 0;
    }
};

class paranthesis
{
    char expn[25];
    stack obj;
public:
    void read()
    {
        cout<<"Enter the expression: ";
        cin>>expn;
        cout<<"\n-------------------------------\nEntered expression is: "<<expn;
    }
    void checkexpn()
    {
        int i,flag;
        char ch;

        flag=0;
        for(i=0;expn[i]!='\0';i++)
        {
            if(expn[i]=='{' || expn[i]=='[' || expn[i]=='(')
            {
                obj.push(expn[i]);
            }

            if(expn[i]=='}' || expn[i]==']' || expn[i]==')')
            {
                if(obj.isempty()==0)
                {
                    ch=obj.pop();

                    if(expn[i]=='}'&& ch!='{')
                    {
                        flag=1;
                        break;
                    }

                    if(expn[i]==']'&&ch!='[')
                    {
                        flag=1;
                        break;
                    }

                    if(expn[i]==')'&&ch!='(')
                    {
                    
                        flag=1;
                        break;
                    }
                }

            }
        }
        if(flag==0 && obj.isempty()==1)
            cout<<"\nExpression is well paranthesized";
        else
            cout<<"\nExpression is not well paranthesized";
        }
};

int main()
{
    char ch;
    paranthesis obj1;
    do
    {
        obj1.read();
        obj1.checkexpn();
        cout<<"\nDo you want to continue?(y/n) ";
        cin>>ch;
    }while(ch=='y');
    cout<<"Thank you!!";
    return 0;
}


