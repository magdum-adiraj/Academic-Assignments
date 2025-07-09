#include<iostream>
using namespace std;
class publication
{
    protected:
        char pub_name[20];
        float rate1,rate2;
    public:
        publication()
        {
            rate1=0.5;
            rate2=1.5;
        }
        void getdata()
        {
            cout<<"Enter the name of publication ";
            cin>>pub_name;
        }
        void showdata_books()
        {
            cout<<"The cost of publishing per page for a book is Rs."<<rate1<<"\n";
        }
        void showdata_tapes()
        {
            cout<<"The cost of publishing per min for a tape is Rs."<<rate2<<"\n";
        }
};
class book:public publication
{
    protected:
        int n;
        float cost;
    public:
        void total()
        {
            cout<<"Enter total number of pages ";
            cin>>n;
            cost=rate1*n;
        }
        void showdata_books()
        {
            cout<<"The total cost of publishing book by "<<pub_name<<" is Rs."<<cost;
        }
};
class tape:public publication
{
    protected:
        float min,cost;
    public:
        void total()
        {
            cout<<"Enter total number of minutes of recording ";
            cin>>min;
            cost=rate2*min;
        }
        void showdata_tapes()
        {
             cout<<"The total cost of publishing tape by "<<pub_name<<" is Rs."<<cost;
        }
};
int main()
{
    char ch;
    int m;
    book b1;
    tape t1;
    do
    {
        cout<<"Select item:\n1)Book \n2)Tape\n";
        cin>>m;
        switch (m)
        {
            case 1:
                b1.getdata();
                b1.publication::showdata_books();
                b1.total();
                b1.showdata_books();
                break;
            case 2:
                t1.getdata();
                t1.publication::showdata_tapes();
                t1.total();
                t1.showdata_tapes();
                break;
            default:
                cout<<"Enter valid input";
                break;
        }
        cout<<"\nDo you want to continue?(y/n) ";
        cin>>ch;
    }while(ch=='y');
    cout<<"Thank you";
    return 0;
}
