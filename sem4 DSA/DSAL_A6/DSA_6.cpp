#include <iostream>
using namespace std;
#define MAXSIZE 20

class Node
{
	int data;
	Node *next;

public:
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
	friend class Queue;
	friend class Stack;
};

class Stack
{
private:
	int data[MAXSIZE];
	int Top;

public:
	Stack()
	{
		Top = -1;
	}
	bool isEmpty()
	{
		if (Top == -1)
		{
			return true;
		}
		else
			return false;
	}
	void push(int element)
	{
		data[++Top] = element;
	}
	void pop()
	{
		Top--;
	}
	int top()
	{
		return data[Top];
	}
};

class Queue
{
private:
	Node *front;
	Node *rear;
	int size;

public:
	Queue()
	{
		front = NULL;
		rear = NULL;
		size = 0;
	}

	void push(int no)
	{
		Node *newn = new Node();
		newn->data = no;
		newn->next = NULL;

		if (front == NULL && rear == NULL)
		{
			front = newn;
			rear = newn;
		}
		else
		{
			rear->next = newn;
			rear = newn;
		}
		size++;
	}

	void pop()
	{
		Node *temp = front;
		if (front == NULL && rear == NULL)
		{
			cout << "Queue is empty\n";
		}

		if (front == rear)
		{
			delete front;
			front = NULL;
			rear = NULL;
		}
		else
		{
			front = front->next;
			delete temp;
		}
		size--;
	}

	bool empty()
	{
		if(size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int getfront()
	{
		return front->data;
	}
};

class Graph
{
	int max_size;
	Node *arr[MAXSIZE];

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
		newn1->data = src_vertex;
		Node *newn2 = new Node;
		newn2->data = dest_vertex;
		Node *temp;

		if (arr[src_vertex] == NULL)
		{
			arr[src_vertex] = newn2;
		}
		else
		{
			temp = arr[src_vertex];
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newn2;
		}

		if (arr[dest_vertex] == NULL)
		{
			arr[dest_vertex] = newn1;
		}
		else
		{
			temp = arr[dest_vertex];
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

	void BFS(int src_vertex)
	{
		Queue q;
		bool visited[max_size] = {};
		q.push(src_vertex);
		visited[src_vertex] = 1;
		while (!q.empty())
		{
			src_vertex = q.getfront();
			q.pop();
			cout << src_vertex << ", ";
			
			Node *temp = arr[src_vertex];
			while (temp != NULL)
			{
				if (visited[temp->data] == 0)
				{
					visited[temp->data] = 1;
					q.push(temp->data);
				}
				temp = temp->next;
			}
		}
	}

	void DFS(int src_vertex)
	{
		Stack st;
		bool visited[max_size] = {};
		st.push(src_vertex);
		visited[src_vertex] = 1;
		while (!st.isEmpty())
		{
			src_vertex = st.top();
			st.pop();
			cout << src_vertex << ", ";

			Node *temp = arr[src_vertex];
			while (temp != NULL)
			{
				if (visited[temp->data] == 0)
				{
					visited[temp->data] = 1;
					st.push(temp->data);
				}
				temp = temp->next;
			}
		}
	}
};

int main()
{
	int vertices, v1, v2;
	char choice;

	cout<<"Enter number of vertices\n";
	cin>>vertices;
	Graph g(vertices);
	do
	{
		cout<<"----MENU----\n";
		cout<<"1) Add Edge\n";
		cout<<"2) Display\n";
		cout<<"3) BFS\n";
		cout<<"4) DFS\n";
		cout<<"5) Exit\n";
		cout<<"Enter your choice\n";
		cin>>choice;

		
		switch(choice)
		{
			case '1':
				cout<<"Enter vertice 1 : \n";
				cin>>v1;
				cout<<"Enter vertice 2 : \n";
				cin>>v2;
				g.addEdge(v1,v2);
				break;
			case '2':
				g.display();
				break;
			case '3':
				g.BFS(0);
				break;
			case '4':
				g.DFS(0);
				break;
			case '5':
				cout<<"Thank you\n";
				break;
			default:
				cout<<"Choose between (0-5)\n";	
				
		}
	}while(choice != '5');
	

	return 0;
}
