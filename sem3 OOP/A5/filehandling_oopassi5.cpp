#include <iostream>
#include <fstream>
#include<string>
using namespace std;
int main()
{
    string str,str1;
    ofstream file;
    file.open("sample.txt",ios::app);
    cout<<"File created successfully."<<endl;
    cout<<"Enter the content of file: "<<endl;
    getline(cin,str);
    file<<str;
    file.close();
    ifstream file1;
    file1.open("sample.txt"); 
    cout<<"File content is: "<<endl;
    while(!file1.eof())
    {
        getline(file1,str1);
        cout<<str1;
    } 
    file1.close();  
    return 0;
}