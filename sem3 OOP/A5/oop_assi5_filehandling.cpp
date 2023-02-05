#include <iostream>
#include <fstream>
#include<string>
using namespace std;
int main()
{
   fstream File;
   File.open("sample.txt",ios::out);
   cout<<"File created successfully."<<endl;
   string str,str1;
   cout<<"Enter the content of file";
   getline(cin,str);
   File<<str;
   File.close();
   File.open("sample.txt",ios::in);
   cout<<"File content: ";
   while(!File.eof())
   {
       getline(File,str1);
       cout<<str1;
   } 
   File.close();  
   return 0;
}