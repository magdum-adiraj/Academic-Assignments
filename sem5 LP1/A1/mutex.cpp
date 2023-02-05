#include <iostream>
using namespace std;

class op
{
    public:
        int wrt,mutex,readcnt;
    op()
    {
        wrt=1;
        mutex=1;
        readcnt=0;
    }
    void wait(int ins)
    {
        ins=0;
    }
    void signal(int ins)
    {
        ins=1;
    }
    void write()
    {
        bool flag=false;
        char ch;
        int ch2;
        do{
            wait(wrt);
            cout<<"Write process Executing!"<<endl;
            do{
                cout<<"What Process would you like to perform"<<endl;
                cout<<"1)Write\n2)Read\n3)None"<<endl;
                cout<<"Enter choice: ";
                cin>>ch2;

                switch(ch2)
                {
                    case 1:
                    cout<<"Another Write Process Not Allowed!"<<endl;
                    break;

                    case 2:
                    cout<<"Read process Not allowed when write process is executing!"<<endl;
                    break;
                }
            }while(ch2!=3);
            cout<<"Do you want to Exit write process(Y/n): ";
            cin>>ch;
            if(ch=='Y' or ch=='y'){
            signal(wrt);
            flag=true;
            }
        }while(flag!=true);
    }

    void read()
    {
        bool flag=false;
        int ch;
        char ch1;
        do{
            if(readcnt==0)
            {
                wait(mutex);
                readcnt++;
                cout<<"Read Process Executing!"<<endl;
            }
            if(readcnt>=1)
            {
                wait(wrt);
                signal(mutex);
            }
            cout<<"What Process would you like to perform"<<endl;
            cout<<"1)Write\n2)Read\n3)None"<<endl;
            cout<<"Enter choice: ";
            cin>>ch;
            if(ch==1)
            {
                cout<<"Write Process Not Allowed while Read Process is Executing!"<<endl;
            }
            else if(ch==2)
            {
                wait(mutex);
                readcnt++;
                cout<<"Another Read process executing!"<<endl;
            }
            else if(ch==3)
            {
                cout<<"Do you want to exit read process(Y/n): ";
                cin>>ch1;
                if(ch1=='Y' or ch1=='y'){
                readcnt--;
                }
            }
            
            if(readcnt==0)
            {
                cout<<"All Read Process Ended!"<<endl;
                signal(wrt);
                signal(mutex);
                flag=true;
            }
        }while(flag!=true);
    }
};
int main() 
{
    op t;
    int choice;
    do{
        cout<<"<-------------------Menu-------------------->"<<endl;
        cout<<"1)Write\n2)Read\n3)Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            t.write();
            break;
            
            case 2:
            t.read();
            break;
        }
    }while(choice!=3);
    return 0;
}