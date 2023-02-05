#include<iostream>
using namespace std;
class complex
{
    private:
        int real,imaginary;
    public:
        complex()
        {
            real=0;
            imaginary=0;
        }
        complex(int x,int y)
        {
            real=x;
            imaginary=y;
        }
        void print()
        {
            cout<<real<<"+"<<imaginary<<"i";
        }
        void add(complex u,complex v)
        {
            real=u.real + v.real;
            imaginary=u.imaginary+v.imaginary;
        }
        
};
int main()
{
    int a,b;
    cout<<"Enter the real and imaginary part of number 1 \n";
    cin>>a>>b;
    complex c1(a,b);
    c1.print();
    cout<<"Enter the real and imaginary part of number 2 \n";
    cin>>a>>b;
    complex c2(a,b);
    c2.print();
    complex c3;
    c3.add(c1,c2);
    c3.print();
}