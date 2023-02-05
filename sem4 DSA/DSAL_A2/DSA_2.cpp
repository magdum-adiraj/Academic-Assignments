#include<iostream>
#include<string>
using namespace std;

class node
{
    string key,meaning;
    node *left, *right;
    public:
        node()
        {
            key="0";
            meaning="0";
            left=NULL;
            right=NULL;
        }
        friend class BinarySearchTree;
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
        void insertnode(string,string);
        void ascendingprint(node*);
        void descendingprint(node*);
        void findmeaning(string,node*);
        void updatemeaning(string,string,node*);
        void deletekey(string,node*,node*);
};

void BinarySearchTree::insertnode(string key, string meaning)
{
    node *newn = new node();
    newn->key = key;
    newn->meaning = meaning;
    if (root == NULL)
    {
        root = newn;
        cout<<"Key inserted\n";
    }
    else
    {
        node *current = root;
        while (true)
        {
            if (current->key == newn->key)
            {
                cout << "Key already exists, insert another word. \n";
                return;
            }
            else if ((newn->key < current->key))
            {
                if (current->left == NULL)
                {
                    current->left = newn;
                    cout << "Key inserted\n";
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
                    cout << "Key inserted\n";
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

void BinarySearchTree::ascendingprint(node *current)
{
    if(current!=NULL)
    {
        ascendingprint(current->left);
        cout<<current->key<<":"<<current->meaning<<"\n";
        ascendingprint(current->right);
    }
    else if(current==root && root==NULL)
    {
        cout<<"Empty Dictionary\n";
    }
}

void BinarySearchTree::descendingprint(node *current)
{
    if(current!=NULL)
    {
        descendingprint(current->right);
        cout<<current->key<<":"<<current->meaning<<"\n";
        descendingprint(current->left);
    }
    else if(current==root && root==NULL)
    {
        cout<<"Empty Dictionary\n";
    }
}

void BinarySearchTree::findmeaning(string fkey,node *root)
{
    node* current=root;
    if(current!=NULL)
    {
        if(current->key==fkey)
                {
                        cout<<"Meaning of "<<fkey<<" is: "<<current->meaning<<"\n";
                }
                else if(current->key>fkey)
                {
                        findmeaning(fkey,current->left);
                }
                else if(current->key<fkey)
                {
                        findmeaning(fkey,current->right);
                }
    }
    else
    {
        cout<<"Key not found\n";
    }
}

void BinarySearchTree::updatemeaning(string key,string nmeaning,node* root)
{
        node* current=root;
        if(current!=NULL)
        {
                if(current->key == key)
                {
                        current->meaning=nmeaning;
                        cout<<"Meaning updated:";
                        cout<<current->key<<":"<<current->meaning<<"\n";
                }
                else if(current->key > key)
                {
                        updatemeaning(key,nmeaning,current->left);
                }
                else if(current->key < key)
                {
                        updatemeaning(key,nmeaning,current->right);
                }
        }
        else
        {
                cout<<"Key not found\n";
        }
}

void BinarySearchTree::deletekey(string key,node *child,node *parent)
{
        node* current=child;
        if(current!=NULL)
        {
                if(current->key==key && current!=root)
                {
                        if(current->left==NULL && current->right==NULL)
                        {
                                if(parent->left==current)
                                {
                                        parent->left=NULL;
                                }
                                else
                                {
                                        parent->right=NULL;
                                }
                                delete current;
                                cout<<"Key deleted\n";
                        }
                        else if(current->left!=NULL && current->right==NULL)
                        {
                                if(parent->left==current)
                                {
                                        parent->left=current->left;
                                }
                                else
                                {
                                        parent->right=current->left;
                                }
                                delete current;
                                cout<<"Key deleted\n";
                        }
                        else if(current->left==NULL && current->right!=NULL)
                        {
                                if(parent->left==current)
                                {
                                        parent->left=current->right;
                                }
                                else
                                {
                                        parent->right=current->right;
                                }
                                delete current;
                                cout<<"Key deleted\n";
                        }
                        else if(current->left!=NULL && current->right!=NULL)
                        {
                                node *temp=current->left;
                                string k,m;
                                while(temp->right!=NULL)
                                {
                                        temp=temp->right;
                                }
                                k=temp->key;
                                m=temp->meaning;
                                deletekey(temp->key,getroot(),NULL);
                                current->key=k;
                                current->meaning=m;
                        }

                }
                else if(current->key==key && current==root)
                {
                        if(current->left==NULL && current->right==NULL)
                        {
                                delete current;
                                cout<<"Key deleted\n";
                        }
                        else if(current->left!=NULL && current->right==NULL)
                        {
                                root=root->left;
                                delete current;
                                cout<<"Key deleted\n";
                        }
                        else if(current->left==NULL && current->right!=NULL)
                        {
                                root=root->right;
                                delete current;
                                cout<<"Key deleted\n";
                        }
                        else if(current->left!=NULL && current->right!=NULL)
                        {
                                node *temp=current->left;
                                string k,m;
                                while(temp->right!=NULL)
                                {
                                        temp=temp->right;
                                }
                                k=temp->key;
                                m=temp->meaning;
                                deletekey(temp->key,getroot(),NULL);
                                current->key=k;
                                current->meaning=m;
                        }
                }
                else if(current->key>key)
                {
                        deletekey(key,current->left,current);
                }
                else if(current->key<key)
                {
                        deletekey(key,current->right,current);
                }
        }
    else
    {
        cout<<"Key not found\n";
    }
}
int main()
{
    BinarySearchTree b1;
    int ch;
    bool cont=true;
    string key,meaning,nmeaning;
    while(cont==true)
    {
        cout<<"-----------------MAIN MENU---------------\n";
        cout<<"1)Insert key and its meaning\n";
        cout<<"2)Print dictionary in ascending order\n";
        cout<<"3)Print dictionary in descending order\n";
        cout<<"4)Find meaning\n";
        cout<<"5)Update meaning in dictionary\n";
        cout<<"6)Delete key\n";
        cout<<"7)Exit\n";
        cout<<"Enter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter key to be added in dictionary:";
                cin.ignore();
                getline(cin,key);
                cout<<"Enter its meaning:";
                getline(cin,meaning);
                b1.insertnode(key,meaning);
                break;
            case 2:
                cout<<"Dictionary in ascending order is:\n";
                b1.ascendingprint(b1.getroot());
                break;
            case 3:
                cout<<"Dictionary in descending order is:\n";
                b1.descendingprint(b1.getroot());
                break;
            case 4:
                cout<<"Enter key whose meaning is to be found:";
                cin.ignore();
                getline(cin,key);
                b1.findmeaning(key,b1.getroot());
                break;
            case 5:
                cout<<"Enter key to be updated:";
                cin>>key;
                cout<<"Enter the new meaning:";
                cin.ignore();
                getline(cin,nmeaning);
                b1.updatemeaning(key, nmeaning, b1.getroot());
                break;
            case 6:
                cout<<"Enter the key to be deleted: ";
                cin>>key;
                b1.deletekey(key,b1.getroot(),NULL);
                break;
            case 7:
            cout<<"Thank You!";
                cont=false;
                break;
            default:
                cout<<"Enter valid choice";
        }
    }
    return 0;
}
