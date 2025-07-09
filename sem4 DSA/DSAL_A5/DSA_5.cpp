#include <iostream>
#include <stdlib.h>
using namespace std;

class Dictionary;
class Node{
	string key,value;
	Node *link;
public:
	Node(){
		key=value="";
		link=NULL;
	}
	Node(string s1,string s2){
		key=s1;
		value=s2;
		link=NULL;
	}
	friend Dictionary;
};

class Dictionary{
	Node data[100];
public:
	void insert(const string &s1, const string &s2){
		int index=hash(s1);
		if(data[index].key==""){
			data[index].key=s1;
			data[index].value=s2;
			cout<<"\nRecord inserted successfully!"<<endl;
		}
		else{
			Node *ptr=new Node(s1,s2);
			if(data[index].link==NULL){
				data[index].link=ptr;
				cout<<"\nRecord inserted successfully!"<<endl;
			}
			else{
				Node *temp=data[index].link;
				while(temp->link!=NULL){
					temp=temp->link;
				}
				temp->link=ptr;
				cout<<"\nRecord inserted successfully!"<<endl;
			}
		}
	}
	int hash(const string s){
		return (s[0]-'0')%100;
	}
	void search(const string &s1){
		int index=hash(s1);
		int flag=0,comps=0;
		if(data[index].key==s1){
			comps+=1;flag=1;
			cout<<"\nRecord found!"<<endl;
			cout<<"Key: "<<data[index].key<<endl;
			cout<<"Value: "<<data[index].value<<endl;
			cout<<"Number of comparisons: "<<comps<<endl;
			return;
		}
		else{
			comps+=1;
			Node *temp=data[index].link;
			while(temp!=NULL){
				if(temp->key==s1){
					comps+=1;flag=1;
					cout<<"\nRecord found!"<<endl;
					cout<<"Key: "<<temp->key<<endl;
					cout<<"Value: "<<temp->value<<endl;
					cout<<"Number of comparisons: "<<comps<<endl;
					break;
				}
				else{
					comps+=1;
					temp=temp->link;
				}
			}
		}
		if(flag==0){
			cout<<"\nRecord not found!"<<endl;
			cout<<"Number of comparisons: "<<comps<<endl;
		}
	}
	void deleteRecord(string &s1){
		int index=hash(s1);
		if(data[index].key==s1){
			if(data[index].link!=NULL){
				Node *ptr=data[index].link;
				data[index].key=ptr->key;
				data[index].value=ptr->value;
				data[index].link=ptr->link;
				delete ptr;
				cout<<"\nRecord deleted successfully!"<<endl;
				return;
			}
			else{
				data[index].key=data[index].value="";
				cout<<"\nRecord deleted successfully!"<<endl;
				return;
			}
		}
		else{
			Node *temp=data[index].link;
			if(!temp){
				cout<<"\nError! Record not found!"<<endl;
				return;
			}
			while(temp->link!=NULL){
				if(temp->key==s1){
					Node *ptr=temp->link;
					temp->key=ptr->key;
					temp->value=ptr->value;
					temp->link=ptr->link;
					delete ptr;
					cout<<"\nRecord deleted successfully!"<<endl;
					return;
				}
				else{
					temp=temp->link;
				}
			}
			if(temp->key==s1){
				temp->key=temp->value="";
				cout<<"\nRecord deleted successfully!"<<endl;
				return;
			}
	}
	}
};
int main() {
	Dictionary d;
	string s1,s2;
	int cho;
	cout<<"-------------Hashed Dictionary Program--------------"<<endl;
	while(true){
		cout<<"\n------------Menu------------\n1.Insert record\n2.Search record\n3.Delete record\n4.Exit\nEnter your choice: ";cin>>cho;
		switch(cho){
			case 1:
				cout<<"\nEnter key to be inserted: ";cin>>s1;
				cout<<"Enter value to be inserted: ";cin>>s2;
				d.insert(s1, s2);
				break;
			case 2:
				cout<<"\nEnter name to be searched: ";cin>>s1;
				d.search(s1);
				break;
			case 3:
				cout<<"\nEnter name to be searched: ";cin>>s1;
				d.deleteRecord(s1);
				break;
			case 4:
				cout<<"\nThank You!";
				break;
			}
		}

	return 0;
}
