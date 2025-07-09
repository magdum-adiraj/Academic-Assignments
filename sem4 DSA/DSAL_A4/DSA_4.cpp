#include <iostream>
#include <algorithm>
#include <string.h>
#define SIZE 10
using namespace std;

class node
{
    string name;
    long long int mobile;
    int link;

    node()
    {
        name = "";
        mobile = 0;
        link = -1;
    }
    node(string name, long long int mobile, int link)
    {
        this->name = name;
        this->mobile = mobile;
        this->link = link;
    }
    friend class hashtable;
};

class hashtable
{

    node table[SIZE];

public:
    int hashfun(long long int);
    void insertWithReplace(string, long long int);
    void insertWithoutReplace(string, long long int);
    void display();
    void search(long long int);
};

int hashtable::hashfun(long long int mobile)
{
    return mobile % SIZE;
}

void hashtable::insertWithoutReplace(string n, long long int num)
{
    int address = hashfun(num);
    int preadd;
    if (table[address].mobile == 0)
    {
        table[address].mobile = num;
        table[address].name = n;
    }
    else
    {
        while (table[address].link != -1)
        {
            address = table[address].link;
        }
        preadd = address;
        while (table[address].mobile != 0)
        {
            address = (address + 1) % 10;
        }
        table[address].mobile = num;
        table[address].name = n;

        table[preadd].link = address;
    }
}

void hashtable::display()
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << ")\t" << table[i].mobile << ":\t" << table[i].name << "\n";
    }
}

void hashtable::search(long long int num)
{
    

    int count = 1;
    int hashadd = hashfun(num);

    if (table[hashadd].mobile == num)
    {
        cout<<"Number is found "<<endl;
        cout <<"Mobile No. : "<<table[hashadd].mobile << " , Name of client : " << table[hashadd].name << " " << endl;
        cout <<"No. of comparisons : "<<count << endl;
        return;
    }
    else
    {
        while (table[hashadd].link != -1)
        {
            hashadd = table[hashadd].link;
            count++;
            if (table[hashadd].mobile == num)
            {
                cout<<"Number is found "<<endl;
                cout <<"Mobile No. : "<<table[hashadd].mobile << " , Name of client : " << table[hashadd].name << " " << endl;
                cout <<"No. of comparisons : "<<count << endl;
                return;
            }

        }
        cout<<"Not found..."<<endl;
    }
}

void hashtable::insertWithReplace(string n,long long int num){
    int address = hashfun(num);
    int preadd;

    if(table[address].mobile == 0){
        table[address].mobile = num;
        table[address].name = n;

    }
    else{
        if(address == hashfun(table[address].mobile)){
            preadd = address;
            while(table[address].link != -1){
                address = table[address].link;
                preadd = address;
            }

            while(table[address].mobile != 0){
                address = (address+1)%SIZE;
            }
            table[address].name = n;
            table[address].mobile = num;
            table[preadd].link = address;
        }

        else{
            node temp = table[address];
            int m = hashfun(table[address].mobile);
            table[m].link = temp.link;

            table[address].mobile = num;
            table[address].name = n;
            insertWithReplace(temp.name,temp.mobile);
        }
        
    }
}

int main()
{
    hashtable ht;
    string name;
    long long int  mobile;

    int choice;
    cout << "\n-----------------menu-----------\n 1.Table No. 1 (collision handeling without replace)\n 2.Table No. 2 (collision handeling with replace)\n 3.Exit" << endl;
    cout << "\nenter choice : ";
    cin >> choice;
    
    if(choice == 1){
        
        int ch;
        
        do{
            cout << "\n1.insert\n2.search\n3.display hashtable\n4.exit" << endl;
            cout << "\nenter choice : ";
            cin >> ch;

            switch(ch){
                case 1 : {
                    char a;
                    do{
                        cout<<"enter name : ";
                        cin>>name;
                        cout<<"enter mobile : ";
                        cin>>mobile;
                        ht.insertWithoutReplace(name,mobile);
                        cout<<"do you insert more ? (y/n) : ";
                        cin>>a;
                    }while(a=='y');
                    break;


                }
                case 2:{
                    
                    cout<<"enter mobile no. for search : ";
                    cin>>mobile;
                    ht.search(mobile);
                    break;

                }
                case 3:{
                    ht.display();
                    break;
                }
            }
            

        }while(ch!=4);
        
    }
    
    if(choice == 2){
        
        int ch;
        
        do{
            cout << "\n1.insert\n2.search\n3.display hashtable\n4.exit" << endl;
            cout << "\nenter choice : ";
            cin >> ch;

            switch(ch){
                case 1 : {
                    char a;
                    do{
                        cout<<"enter name : ";
                        cin>>name;
                        cout<<"enter mobile : ";
                        cin>>mobile;
                        ht.insertWithReplace(name,mobile);
                        cout<<"do you insert more ? (y/n) : ";
                        cin>>a;
                    }while(a=='y');
                    break;


                }
                case 2:{
                    
                    cout<<"enter mobile no. for search : ";
                    cin>>mobile;
                    ht.search(mobile);
                    break;

                }
                case 3:{
                    ht.display();
                    break;
                }
            }
            

        }while(ch!=4);
        
    }
    if(choice == 3){
        cout<<"thaks...";
    }
    return 0;
}
