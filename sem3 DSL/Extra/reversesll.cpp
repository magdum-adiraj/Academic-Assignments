#include<iostream>
using namespace std;

class node
{
    private:
        int num;
        node *next;
    public:
        friend class reversesll;
};

class reversesll
{
    private:
        node* head=NULL;
    public:
        void push()
        {
            int number,n,i;
            node *newnode,*temp;
            cout<<"Enter total number of elements: ";
            cin>>n;
            for(i=0;i<n;i++)
            {
                cout<<"Enter number "<<i+1<<": ";
                cin>>number;
                newnode=new node;
                newnode->num=number;
                newnode->next=NULL;
                if(head==NULL)
                {
                    head=newnode;
                    temp=head;
                }
                else
                {
                    temp->next=newnode;
                    temp=newnode;
                }
            }
        }
        void display()
        {
            node *temp;
            temp=head;
            while(temp!=NULL)
            {
                cout<<temp->num<<" ";
                temp=temp->next;
            }
        }
        void reverse()
        {
            node *temp=head;
            node *prev=NULL,*next=NULL;
            while(temp!=NULL)
            {
                next=temp->next;
                temp->next=prev;
                prev=temp;
                temp=next;
            } 
            head=prev;
        }
};

int main()
{
    reversesll obj;
    obj.push();
    cout<<"Before reverseing: ";
    obj.display();
    obj.reverse();
    cout<<"\nAfter reversing: ";
    obj.display();
    return 0;
}