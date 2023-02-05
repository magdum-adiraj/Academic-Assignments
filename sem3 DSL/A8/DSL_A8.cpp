#include<iostream>
using namespace std;
struct node
{    int roll;
      struct node *next;
};
class info
{       node *head1=NULL,*temp1=NULL,*head2=NULL,*temp2=NULL,*head=NULL,*temp=NULL,*h1=NULL,*head3=NULL,*temp3=NULL;
        int c,i,f,j,k;
       
        public:
    
            node  *create();
            void insert();
            void allstud();
            void vanila();
            void butters();
            void uice();
            void nice();
            void notice();
            void ovanila();
            void obutters();
            void display();   

           
            
} ;        
node *info::create()
{   node *p=new(struct node);
    cout<<"Enter roll number: ";
    cin>>c;
    p->roll=c;
    p->next=NULL;
    return  p;
} 
void info::insert()
{ 
    node *p=create();
    if(head==NULL)
    {
        head=p;
    }
    else
    { 
        temp=head;
        while(temp->next!=NULL)
        {    temp=temp->next;   }
        temp->next=p;
    }        
         
}
void info::display()
{   temp=head;
    while(temp->next!=NULL)
    { cout<<temp->roll<<" ";
        temp=temp->next;
    } 
    cout<<temp->roll<<"\n";
}
void info::allstud()
{
    cout<<"Enter total number of students: ";
    cin>>k;
    head=NULL;
    for(i=0;i<k;i++)
    {    
        insert();
        h1=head;   
    }
    cout<<"  Roll number of students in class:\n";
    display();
    head=NULL;
}
void info::vanila()
{
    cout<<"Enter total number of students who like vanila: ";
    cin>>k;
    head=NULL;
    for(i=0;i<k;i++)
    {
        insert();
        head1=head;
    }
    cout<<"  Roll number of students in class who like vanilla:\n";
    display();
    head=NULL;
}
void info::butters()
{
    cout<<"Enter total number of students who like butterscotch: ";
    cin>>j;
    for(i=0;i<j;i++)
    {
        insert();
        head2=head;
    }
    cout<<"  Roll number of students in class who like butterscotch:\n";
    display();
    head=NULL;
}
void info::uice()
{
    temp1=head1;
    while(temp1!=NULL)
    {
        node *p=new(struct node);
        p->roll=temp1->roll;
        p->next=NULL;     
        if(head3==NULL)
        {
            head3=p;
        }
        else
        {   
            temp3=head3;
            while(temp3->next!=NULL)
            {    temp3=temp3->next;   }
            temp3->next=p;
        }
        temp1=temp1->next;
    }
    temp2=head2;
    while(temp2!=NULL)
    {    
        f=0;
        temp1=head1;
        while(temp1!=NULL)
        {
        if(temp2->roll==temp1->roll)
        { f=1;                   }
        temp1=temp1->next;
        } 
        if(f==0)
        {  
            node *p=new(struct node);
            p->roll=temp2->roll;
            p->next=NULL;     
            if(head3==NULL)
            {    head3=p;
            }
            else
            {  
                temp3=head3;
                while(temp3->next!=NULL)
                {    temp3=temp3->next;   }
                temp3->next=p;
            }
    }
    temp2=temp2->next;     
    }
    temp3=head3;
    while(temp3->next!=NULL)
    {
        temp3=temp3->next;
    } 
}


void info::ovanila()
{
    temp1=head1;
    while(temp1!=NULL)
    {
        temp2=head2;
        f=0;
        while(temp2!=NULL)
        {   
            if(temp1->roll==temp2->roll)
            {  f=1;              }
            temp2=temp2->next;
        } 
        if(f==0)
        { cout<<temp1->roll<<" ";    }
        temp1=temp1->next;
    }
       
}
void info::obutters()
{
    temp2=head2;
    while(temp2!=NULL)
    {  
        temp1=head1;
        f=0;
        while(temp1!=NULL)
        {  
            if(temp2->roll==temp1->roll)
            {  f=1;              }
            temp1=temp1->next;
        } 
        if(f==0)
        { cout<<temp2->roll<<" ";    }
        temp2=temp2->next;
    }            
}
void info::nice()
{
    cout<<"\nstudents who like both vanila and butterscotch\n";
    temp1=head1;
    while(temp1!=NULL)
    {
        temp2=head2;
        while(temp2!=NULL)
        {
            if(temp1->roll==temp2->roll)
            { cout<<temp1->roll<<" ";   }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }      
}
void info::notice()
{
    cout<<"\nStudents who like neither vanila nor butterscotch\n";
    temp=h1;
    while(temp!=NULL)
    {
        temp3=head3;
        int f=0;
        while(temp3!=NULL)
        {
            if(temp->roll == temp3->roll)
            {  f=1;  
            break;            }
            temp3=temp3->next;
        } 
        if(f==0)
        { cout<<temp->roll<<" ";    }
        temp=temp->next;
    }      
}
int main()
{
    info s;
    int i;
    s.allstud();
    cout<<"\n\n";
    s.vanila();
    cout<<"\n\n";
    s.butters();
    cout<<"\n\n";
    char ch;
    do{
        cout<<"\n----------------------------MENU------------------------------------";
        cout<<"\n  1.  To display the rollno of student who like both vanila and butterscotch";
        cout<<"\n  2.  To display the rollno of student who like either vanila or butterscotch but not both";
        cout<<"\n  3.  To display the rollno of student who neither like vanila nor butterscotch";
        cout<<"\n  Enter your choice: ";
        cin>>i;
        switch(i)
        {
            case 1:
                s.nice();
                break;
            case 2:
                cout<<"\n\nStudents who like either vanila or butterscotch but not both \n";
                s.ovanila();
                s. obutters();
                break;
            case 3:
                s.uice();
                s.notice();
                break;      
            default:  cout<<"\n unknown choice";
        }
        cout<<"\n\n do you want to continue enter y/Y: ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');  
cout<<"\n\n";
cout<<"Thank you!!"; 
return 0;
}