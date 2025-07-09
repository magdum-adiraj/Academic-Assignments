#include<iostream>
using namespace std;

class node
{
    private:
        int num;
        node *next;
    public:
        friend class insertionsort;
};

class insertionsort
{
    private:
        node *head=NULL,*sorted;
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
        void insertionSort()
        {
            sorted = NULL;
            node *current = head;
            while (current != NULL) 
            {
                node *next = current->next;
                sortedInsert(current);
                current = next;
            }
            head = sorted;
        }
        void sortedInsert(node *newnode)
        {
            if (sorted == NULL || sorted->num >= newnode->num)
            {
                newnode->next = sorted;
                sorted = newnode;
            }
            else 
            {
                node *current = sorted;
                while (current->next != NULL && current->next->num < newnode->num)
                {
                    current = current->next;
                }
                newnode->next = current->next;
                current->next = newnode;
            }
        }
};

int main()
{
    insertionsort obj;
    obj.push();
    cout<<"Before sorting: ";
    obj.display();
    obj.insertionSort();
    cout<<"\nAfter sorting: ";
    obj.display();
    return 0;
}