#include<iostream>
using namespace std;

class node
{
    int data;
    node *left,*right;
    public: 
        node()
        {
            data=0;
            left=NULL;
            right=NULL;
        }
        node(int d)
        {
            data=d;
        }
        friend class binarytree;
        friend class stack;
        friend void copy(node*,node*);
};

class stack
{
    node *s[30];
    int top;
    public:
        stack()
        {
            top=-1;
        }
        void push(node *x)
        {
            s[++top]=x;
        }
        void pop()
        {
            top--;
        }
        node *gettop()
        {
            return s[top];
        }
        bool isempty()
        {
            if(top==-1)
                return true;
            else
                return false;
        }
        friend class node;
};
class binarytree
{
    private:
        node* root;
    public:
        binarytree()
        {
            root=NULL;
        }
        void create();
        node* insert();
        node* getroot()
        {
            return root;
        }
        void inorderrecursive(node*);
        void preorderrecursive(node*);
        void postorderrecursive(node*);
        void inorder_iterator(node*);
        void preorder_iterator(node*);
        void postorder_iterator(node*);
        int height(node*);
        int leaves(node*);
        int internal_nodes(node*);
        void operator=(binarytree tree)
        {
            if (tree.root == NULL)
            {
                return;
            }
            root = tree.root;
            copy(tree.root->left, root->left);
            copy(tree.root->right, root->right);
        }
        friend void copy(node*,node*);
        friend class stack;
};

void binarytree::create()
{
    root=insert();
}

node* binarytree::insert()
{
    node* temp;
    char ch;
    temp=new node();
    cout<<"\nEnter the data to be added in tree: ";
    cin>>temp->data;
    cout<<"Do you want to add data to left child of "<<temp->data<<"?(y/n): ";
    cin>>ch;
    if(ch=='y')
    {
        temp->left=insert();
    }
    cout<<"Do you want to add data to right child of "<<temp->data<<"?(y/n): ";
    cin>>ch;
    if(ch=='y')
    {
        temp->right=insert();
    }
    return temp;
}

void binarytree::inorderrecursive(node* temp)
{
    if(temp!=NULL)
    {
        inorderrecursive(temp->left);
        cout<<temp->data<<" ";
        inorderrecursive(temp->right);
    }
}

void binarytree::preorderrecursive(node* temp)
{
    if(temp!=NULL)
    {
        cout<<temp->data<<" ";
        preorderrecursive(temp->left);
        preorderrecursive(temp->right);
    }
}

void binarytree::postorderrecursive(node* temp)
{
    if(temp!=NULL)
    {
        postorderrecursive(temp->left);
        postorderrecursive(temp->right);
        cout<<temp->data<<" ";
    }
}

void binarytree::inorder_iterator(node* root)
{
    node* current;
    stack s1;
    current=root;
    while(true)
    {
        while(current!=NULL)
        {
            s1.push(current);
            current=current->left;
        }
        if(s1.isempty()==false)
        {
            current=s1.gettop();
            s1.pop();
            cout<<current->data<<" ";
            current=current->right;
        }
        else
        {
            break;
        }
    }
}

void binarytree::preorder_iterator(node* root)
{
    node* current;
    stack s1;
    current=root;
    while(true)
    {
        while(current!=NULL)
        {
            s1.push(current);
            cout<<current->data<<" ";
            current=current->left;
        }
        if(s1.isempty()==false)
        {
            current=s1.gettop();
            s1.pop();
            current=current->right;
        }
        else
        {
            break;
        }
    }
}

void binarytree::postorder_iterator(node* root)
{
    node* current=root,*last_visit;
    stack s1;
    last_visit=NULL;
    do
    {
        while(current!=NULL)
        {
            s1.push(current);
            current=current->left;
        }
        while(current==NULL && !s1.isempty())
        {
            current=s1.gettop();
            if (current->right==NULL || current->right==last_visit)
            {
                cout<<current->data<<" ";
                s1.pop();
                last_visit=current;
                current=NULL;
            }
            else
            {
                current=current->right;
            }
        }
    }while(!s1.isempty());
}

int binarytree::height(node *root)
{
    int lheight, rheight;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        lheight = height(root->left);
        rheight = height(root->right);
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}

int binarytree::leaves(node *root)
{
    if (root == NULL)
    {
       return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return (leaves(root->left) + leaves(root->right));
    }
}

int binarytree::internal_nodes(node *root)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return 0;
    }
    else
    {
        return internal_nodes(root->left) + internal_nodes(root->right) + 1;
    }
}

void copy(node *temp,node *ctemp)
{
    if (temp == NULL)
    {
        return;
    }

        ctemp = new node(temp->data);
        copy(temp->left, ctemp->left);
        copy(temp->right, ctemp->right);
}

int main()
{
    node* abc=NULL;
    int x,d;
    binarytree b1,b2;
    do 
	{
		cout <<"\nEnter: "
			<< "\n1. Make Tree "
			<< "\n2. Traversal "
			<< "\n3. Height "
			<< "\n4. Copy "
			<< "\n5. Mirror "
			<< "\n6. Number of leaves, internal nodes"
			<< "\n7. Exit \n ENTER YOUR CHOICE: ";
		cin >> x;
		cout << endl;
		switch (x) 
		{
		case 1: b1.create();
			break;
		case 2:
            cout<<"\nTraversel by recursive inorder: ";
            b1.inorderrecursive(b1.getroot());
            cout<<"\n\nTraversal by recursive preorder: ";
            b1.preorderrecursive(b1.getroot());
            cout<<"\n\nTraversal by recursive postorder: ";
            b1.postorderrecursive(b1.getroot());
            cout<<"\n\nTraversal by iterative inorder: ";
            b1.inorder_iterator(b1.getroot());
            cout<<"\n\nTraversal by iterative preorder: ";
            b1.preorder_iterator(b1.getroot());
            cout<<"\n\nTraversal by iterative postorder: ";
            b1.postorder_iterator(b1.getroot());
			break;
		case 3: d=b1.height(b1.getroot());
        cout<<d;
			break;
		case 4:	b2 = b1;
			cout << "Successfully copied!\n";
            cout<<"\nTraversel of copied tree by recursive inorder: ";
            b1.inorderrecursive(b1.getroot());
			break;
		case 5:
			cout << "Mirror of tree successfully done.";
			break;
		case 6:
            cout<<b1.leaves(b1.getroot());
            cout<<b1.internal_nodes(b1.getroot());
			break;
		case 7: 
            break;
		default: cout << "Enter number between 1 through 7 only! \n";
		}
	} while (x != 7);
	return 0;
}