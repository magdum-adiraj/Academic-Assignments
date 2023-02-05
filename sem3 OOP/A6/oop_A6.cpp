#include <iostream> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class student 
{
    public:
        string name,dob;
        int roll;
        bool operator==(const student& i1)
        {
            if(roll==i1.roll)
                return 1;
            return 0;
        }
        bool operator<(const student& i1)
        {
            if(roll<i1.roll)
                return 1;
            return 0;
        }
};
vector<student> o1;
void print(student &i1);
void display();
void insert();
void search();
void dlt();
bool compare(const student &i1, const student &i2)
{
    return i1.roll < i2.roll;
}

int main()
{
    int ch,m;
    do
    {
        cout<<"\n-----------Menu------------";
        cout<<"\n1.Insert";
        cout<<"\n2.Display";
        cout<<"\n3.Search";
        cout<<"\n4.Sort";
        cout<<"\n5.Delete";
        cout<<"\n6.Exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter total number of students: ";
                cin>>m;
                for (int i=0;i<m;i++)
                {
                    cout<<"\nEnter data for student "<<i+1<<"\n";
                    insert();
                }
                break;
            case 2:
                cout<<"Name   \t RollNo.    \t DOB";
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                sort(o1.begin(),o1.end(),compare);
                cout<<"\n\n Sorted on Roll No. : ";
                display();
                break;
            case 5:
                dlt();
                break;
            case 6:
                cout<<"Thank you!!";
                break;
        }    
    }while(ch!=6);
    return 0;
}

void insert()
{
    student i1;
    cout<<"Enter student Name : ";
    cin>>i1.name;
    cout<<"Enter student Date of Birth(dd/mm/yyyy) : ";
    cin>>i1.dob;
    cout<<"Enter student Roll No : ";
    cin>>i1.roll;
    o1.push_back(i1);
}

void display()
{
    for_each(o1.begin(),o1.end(),print);
}

void print(student &i1)
{
    cout<<"\n"<<i1.name<<"\t   "<<i1.roll<<"\t\t"<<i1.dob;
}

void search()
{
    vector<student>::iterator p;
    student i1;
    cout<<"\nEnter student roll number to search : ";
    cin>>i1.roll;
    p=find(o1.begin(),o1.end(),i1);
    if(p==o1.end())
    {
    cout<<"\nNot found!!!";
    }
    else
    {
    cout<<"\nFound!!!";
    }
}
void dlt()
{
    vector<student>::iterator p;
    student i1;
    cout<<"\nEnter student roll number to delete : ";
    cin>>i1.roll;
    p=find(o1.begin(),o1.end(),i1);
    if(p==o1.end())
    {
    cout<<"\nNot found!!!";
    }
    else
    {
    o1.erase(p);
    cout<<"\nDeleted!!!";
    }
}