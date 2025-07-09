#include <iostream>
using namespace std;

class TreeNode
{
private:
    int data;
    bool rFlag;
    bool lFlag;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode()
    {
        data = 0;
        rFlag = 0;
        lFlag = 0;
        left = NULL;
        right = NULL;
    }
    friend class ThreadedBinaryTree;
};


class ThreadedBinaryTree
{
private:
    TreeNode *root;

public:
    ThreadedBinaryTree()
    {
        root = NULL;
    }

    void insertNode(int val)
    {
        TreeNode *newn = new TreeNode();
        newn->data = val;

        if (root == NULL)
        {
            root = newn;
            root->left = newn;
            root->right = newn;
            root->rFlag = 1;
            root->lFlag = 1;
            cout<<"Root Inserted\n";
        }
        else
        {
            TreeNode *current = root;
            while (true)
            {
                if(current->data > val)
                {
                    if(current->lFlag == 1)
                    {
                        newn->left = current->left;
                        newn->right = current;
                        current->left = newn;
                        newn->lFlag = 1;
                        newn->rFlag = 1;
                        current->lFlag = 0;
                        cout<<"Left Inserted\n";
                        break;
                    }
                    else
                    {
                        current = current->left;
                    }
                }
                else
                {
                    if(current->rFlag == 1)
                    {
                        newn->right = current->right;
                        newn->left = current;
                        current->right = newn;
                        newn->lFlag = 1;
                        newn->rFlag = 1;
                        current->rFlag = 0;
                        cout<<"Right Inserted\n";
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

    TreeNode *findSuccessor(TreeNode *current)
    {
        if(current->rFlag == 1)
        {
            return current->right;
        }
        else
        {
            TreeNode *temp = current->right;
            while (temp->lFlag == 0)
            {
                temp = temp->left;
            }
            return temp;
        }
    }

    void inOrderTraversal()
    {
        TreeNode *current = root;

        while(current->lFlag == 0)
        {
        	current = current->left;
        }
        cout<<current->data<<" ";
        while(current->right != root || current->data < root->data)
        {
        	current = findSuccessor(current);
        	cout<<current->data<<" ";
        }
        cout<<endl;
    }

    void preOrderTraversal()
    {
    	TreeNode *current = root;
    	bool flag = 0;
    	cout<<current->data<<" ";
    	while(current->right != root || current->data <= root->data)
    	{
    		while((current->lFlag == 0) && (flag == 0))
    		{
    			current = current->left;
    			cout<<current->data<<" ";
    		}
    		if(current->rFlag == 0)
    		{
    			current = current->right;
    			cout<<current->data<<" ";
    			flag = 0;
    		}
    		else
    		{
    			current = current->right;
    			flag = 1;
    		}
    	}

    }
};

int main()
{
    ThreadedBinaryTree tobj;
    int no,ele;
    char cont = 'y';
	while (cont == 'y')
	{
		cout << "<--------------Menu--------------->" << endl;
		cout << "1.Insert Nodes in tree." << endl;
		cout << "2.Inorder Traversal of tree" << endl;
		cout << "3.Preorder Traversal of tree" << endl;
		int choice;
		cout << "Enter the choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the no. of entries: ";
			cin >> no;
			for (int i = 0; i < no; i++)
			{
				cout << "Enter the number: ";
				cin >>ele;
				tobj.insertNode(ele);
			}
			cout << "All nodes inserted Successfully!" << endl;
			break;
		case 2:
			tobj.inOrderTraversal();
			break;
		case 3:
			tobj.preOrderTraversal();
			break;
		default:
			cout << "Invalid Choice!!!!" << endl;
			break;
		}
		cout << "Do you want to continue? (y/n): ";
		cin >> cont;
	}
	if (cont == 'n')
	{
		cout << "Thank You !!!" << endl;
	}
	return 0;
}