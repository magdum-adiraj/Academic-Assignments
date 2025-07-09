#include <bits/stdc++.h>
#include<string>
using namespace std;

struct node
{
    string key;
    node *left=NULL;
    node *right=NULL;
};

class BinarySearchTree
{
    private:
        node *root;
    public:
        BinarySearchTree()
        {
            root=NULL;
        }
        node * getroot()
        {
            return root;
        }
        void insertnode(string);
        int searchkey(string,node*);
};

void BinarySearchTree::insertnode(string key)
{
    node *newn = new node();
    newn->key = key;
    if (root == NULL)
    {
        root = newn;
    }
    else
    {
        node *current = root;
        while (true)
        {
            if ((newn->key < current->key))
            {
                if (current->left == NULL)
                {
                    current->left = newn;
                    break;
                }
                else
                {
                    current = current->left;
                }
            }
            else if ((newn->key > current->key))
            {
                if (current->right == NULL)
                {
                    current->right = newn;
                    break;
                }
                else
                {
                    current = current->right;
                }
            }
        }
    }    
}    


int BinarySearchTree::searchkey(string fkey,node *root)
{
    node* current=root;
    int d=0;
    if(current!=NULL && current->key==fkey)
    {
        d++;
        cout<<"Key found";
        return d;
    }
    else if(current->key>fkey)
    {
        d=searchkey(fkey,current->left);
        d++;
        return d;
    }
    else if(current->key<fkey)
    {
        d=searchkey(fkey,current->right);
        d++;
        return d;
    }
    else if(current==NULL)
    {
        cout<<"Key not found";
        d++;
        return d;
    }
}

int main()
{
    BinarySearchTree b1;
    int ch;
    bool cont=true;
    string key,key1;
    ifstream fin;
    fin.open("input.txt");
    while(!fin.eof())
    {
        fin>>key;
        b1.insertnode(key);
    }
    cout<<"Enter word to be searched: ";
    cin>>key1;
    ch=b1.searchkey(key1,b1.getroot());
    cout<<"No of comparisons: "<<ch;
    return 0;
}