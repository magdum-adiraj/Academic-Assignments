#include <iostream>
#include <string>
#include <vector>
using namespace std;

class transposition
{
    public:
        string encrypt(string key,string pt)
        {
            int n=key.length();
            int lpt=pt.length();
            int x=lpt;
            if(x%n==0)
            {
                x=x/n;
            }
            else
            {
                int c=x%n;
                x=(x/n)+1;
                for(int i=c;i<n;i++)
                {
                    pt.push_back('_');
                }
            }
            char a[x][n];
            int k=0;
            for(int i=0;i<x;i++)
            {
                for(int j=0;j<n;j++)
                {
                    a[i][j]=pt[k];
                    k++;
                }
            }
            string s="";
            for(int i=0;i<x;i++)
            {
                for(int j=0;j<n;j++)
                {
                    s+=a[i][j];
                    cout<<a[i][j]<<" ";
                }
                cout<<"\n";
            }
            vector<string> ed(n,"");
            string q="";
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<x;j++)
                {
                    q+=a[j][i];
                }
                ed[key[i]-'1']=q;
                q="";
            }
            string ct;
            for(int i=0;i<n;i++)
            {
                ct+=ed[i];
            }
            return ct;
        }

        string decrypt(string key,string ct)
        {
            int n=key.length();
            int lct=ct.length();
            int x=lct/n;
            char a[x][n];
            int k=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<x;j++)
                {
                    a[j][i]=ct[k];
                    k++;
                }
            }
            for(int i=0;i<x;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<a[i][j]<<" ";
                }
                cout<<"\n";
            }
            char pt[x][n];
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<x;j++)
                {
                    pt[j][i]=a[j][key[i]-'1'];
                }
            }
            for(int i=0;i<x;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<pt[i][j]<<" ";
                }
                cout<<"\n";
            }
            string dt;
            for(int i=0;i<x;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(pt[i][j]!='_')
                        dt+=pt[i][j];
                }
            }
            return dt;
        }
};

int main()
{
    transposition t;
    string d=t.encrypt("2314","hello rohan");
    cout<<d<<"\n";
    string f=t.decrypt("2314",d);
    cout<<f;
    return 0;
}