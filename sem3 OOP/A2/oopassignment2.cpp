#include<iostream>
#include<string>
using namespace std;
class student
{
    private:
        string name,Class,div,bg,dob,con_no,address;
        int roll_no;
        string clg_name="PICT";
        friend class college_name;
    public:
        static int count;
        student()                                                      //default consturctor
        {
            name="";
            Class="";
            div="";
            dob="";
            bg="";
            con_no="";
            address="";
            roll_no=0;
        }

        void getdata(string name)
        {
            this->name=name;                                          //this pointer
            cout<<"Enter roll number ";
            cin>>roll_no;
            cout<<"Enter class and div ";
            cin>>Class>>div;
            cout<<"Enter blood group ";
            cin>>bg;
            cout<<"Enter date of birth(dd/mm/year)";
            cin>>dob;
            cout<<"Enter contact number ";
            cin>>con_no;
            cout<<"Enter address ";
            cin.ignore();
            getline(cin,address);
        }    
        void display()
        {
            cout<<"\nStudent name:"<<name<<"\n";
            cout<<"Student roll number:"<<roll_no<<"\n";
            cout<<"Student class and div:"<<Class<<div<<"\n";
            cout<<"Student blood group:"<<bg<<"\n";
            cout<<"Student date of birth is:"<<dob<<"\n";
            cout<<"Student address :"<<address<<"\n";
        }
        void contact_number();
        static void get_count();
        ~student()                                                      //destructor
        {
            cout<<"\nDestructor was called \n";
        }
};
int student::count=0;
inline void student::contact_number()                                  //inline code
{
    cout<<"Student contact number :"<<con_no<<"\n";
}
void student::get_count()                                           //static member function
{
    cout<<"\n \n \nData of student:"<<count+1;
    count++;
}
class college_name                                                         //friend class 
{
    public:
        void display(student s)
        {
            cout<<"Student College name:"<<s.clg_name;
        }
};
int main()
{
    string name;
    int n;
    cout<<"Enter total number of students ";
    cin>>n;
    student *s[n];
    college_name c1;
    int i=0;
    while(i<n)
    {
        cout<<"Enter data for student "<<i+1;
        s[i]=new student;                                         //memory allocation
        cout<<"\nEnter student name ";
        cin>>name;
        s[i]->getdata(name);
        student::get_count();
        s[i]->display();
        s[i]->contact_number();
        c1.display(*s[i]);
        i++;
    }
    for(int i=0;i<n;i++)
    {
        delete s[i];                                            //release memory
    }
    return 0;
}