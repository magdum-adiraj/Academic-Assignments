#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int val)
    {
        data = val;
        next = NULL;
    }
    friend class Graph;
};

class Graph
{
    int max_size;
    Node *arr[20];

public:
    Graph()
    {
        max_size = 0;
    }
    Graph(int max)
    {
        max_size = max;
        for (int i = 0; i < max_size; i++)
        {
            arr[i] = NULL;
        }
    }
    void addEdge(int src_vertex, int dest_vertex)
    {
        Node *newn1 = new Node;
        newn1->data = dest_vertex;
        Node *temp;

        if (arr[src_vertex] == NULL)
        {
            arr[src_vertex] = newn1;
        }
        else
        {
            temp = arr[src_vertex];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn1;
        }
    }

    void display()
    {
        for (int i = 0; i < max_size; i++)
        {
            cout << "Vertex " << i << " -> ";
            Node *temp = arr[i];
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void topological_sort()
    {
        int in_degrees[max_size];
        for (int i = 0; i < max_size; i++)
        {
            in_degrees[i] = 0;
        }
        for (int i = 0; i < max_size; i++) // fill in degrees by visiting each vertex
        {
            Node *temp = arr[i];
            while (temp != NULL)
            {
                in_degrees[temp->data] = in_degrees[temp->data] + 1;
                temp = temp->next;
            }
        }

        while (true)
        {
            int c = 0;
            while (in_degrees[c] != 0 && c < max_size)
            {
                c++;
            }
            if (c < max_size)
            {
                cout << c << " ";
                in_degrees[c] = -1;
                Node *t = arr[c];

                while (t != NULL)
                {
                    in_degrees[t->data]--;
                    t = t->next;
                }
            }
            else
            {
                break;
            }
        }
    }
};

int main()
{
	int e;
	cout<<"enter the number of edges:";
    cin>>e;
	Graph g(e);
	int a,b;
	cout<<"enter the directed vertices:";
	for(int i=0;i<e;i++)
	{
	    cin>>a>>b;
	    g.addEdge(a,b);
	}
	cout << "Following is a Topological Sort of the given graph n";
	g.topological_sort();
    return 0;
}