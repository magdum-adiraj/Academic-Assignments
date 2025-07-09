#include<iostream>
#include<string>
using namespace std;
#define MAX 10

class item 
{
    private:
        string name;
        int priority;
        friend class priority_queue;
    public:
        void getdata()
        {
            cout<<"Enter item name: ";
            cin>>name;
            cout<<"Enter item priority: ";
            cin>>priority;
        }
        void showdata()
        {
            cout<<"\n"<<name;
            cout<<"\t\t"<<priority;
        }
};

class priority_queue
{
    private:
        int front,rear;
        item a[MAX];
    public:
        priority_queue()
        {
            front=-1;
            rear=-1;
        }
        bool empty()
        {
            if(front==(rear+1)||rear==-1)
                return 1;
            else
                return 0;
        }
        bool full()
        {
            if(rear==MAX-1)
                return 1;
            else    
                return 0;
        }
        void insert()
        {
            item i;
            if(full())
                cout<<"Queue is full";
            else
            {
                i.getdata();
                if(rear==-1)
                {
                    front++;
                    rear++;
                    a[rear]=i;
                }
                else
                {
                    int j=rear;
                    while((j>=front) && (a[j].priority)>i.priority)
                    {
                        a[j+1]=a[j];
                        j--;
                    }
                    a[j+1]=i;
                    rear++;
                }
                cout<<"ITEM ADDED\n";
            }
        }
        void display()
        {
            if(empty())
                cout<<"Queue is empty";
            else
            {
                for(int i=front;i<=rear;i++)
                {
                    a[i].showdata();
                }
            }
        }
        void deletion()
        {
            if(empty())
                cout<<"Queue is empty";
            else
            {
                front++;
                cout<<"ITEM DELETED "; 
            }
        }
};

int main()
{
    int ch;
    priority_queue pq;
    do
    {
        cout<<"\n1)Insert\n2)Display\n3)Delete\n4)Exit\n";
        cout<<"Enter choice:";
        cin>>ch;
        switch (ch)
        {
            case 1:
                pq.insert();
                break;
            case 2:
                cout<<"\nItem\t\tPriority";
                pq.display();
                break;
            case 3:
                pq.deletion();
                cout<<"\nItem\t\tPriority";
                pq.display();
        }
    }while(ch!=4);
    return 0;
}