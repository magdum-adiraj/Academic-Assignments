#include<iostream>
using namespace std;
template<class T>       
T selection_sort()        //Template function
{
    int n;
    cout<<"Enter the total number of elements ";
    cin>>n;
    T a[n];
    T temp;
    for(int i=0;i<n;i++)       
    {
        cout<<"Enter element "<<i+1<<": ";
        cin>>a[i];
    }
    for(int i=0;i<n;i++)         
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++)        
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    cout<<"\n Integer sorting \n";
    selection_sort<int>();
    cout<<"\n Floating sorting \n";
    selection_sort<float>();  
    cout<<"\n Character sorting \n";
    selection_sort<char>();     
}