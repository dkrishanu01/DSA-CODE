#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node *prev;
		
		//constructor
		
		 Node(int d){
		 	this->data=d;
		 	this->next=NULL;
		 	this->prev=NULL;
		 }
};

void print(Node *head){
	Node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	
	cout<<endl;
}

void InsertAtHead(Node* &head, int d){
Node *temp=new Node(d);
temp->next=head;
head->prev=head;
head=temp;
}

void InsertAtTail(Node* &tail, int d){
Node *temp=new Node(d);
tail->next=temp;
temp->prev=tail;
tail=temp;
}

void InsertAtPositon(Node* &tail, Node* &head, int position, int d){
	
	//insert at start
	if(position==1){
		InsertAtHead(head, d);
		return;
	}
	
	Node *temp=head;
	int cnt=1;
	
	//insert any postion and traverse
	while(cnt<position-1){
		temp=temp->next;
		cnt++;
	}
	
	//insert at last
	if(temp==NULL){
		InsertAtTail(tail, d);
		return;
	}
	
	//insert at any middle position by creating a node
	Node *NodeToInsert=new Node(d);
	NodeToInsert->next=temp->next;
	temp->next->prev=NodeToInsert;
	temp->next=NodeToInsert;
	NodeToInsert->prev=temp;
}
int main()
{   
	Node *node1=new Node(40);
	Node *head=node1;
	Node *tail=node1;
	
	print(head);
	
InsertAtHead(head, 30);
print(head);

InsertAtHead(head, 20);
print(head);

InsertAtHead(head, 10);
print(head);

InsertAtTail(tail, 50);
print(head);

InsertAtTail(tail, 60);
print(head);

InsertAtPositon(tail, head, 3, 2000);
print(head);

}