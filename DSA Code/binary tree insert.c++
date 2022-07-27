#include<iostream>
using namespace std;

struct node{
	int data;
	node *right, *left;
	
	node(int value){
		data=value;
		right=left=NULL;
	}
};

node *RecursiveInsert(node *root, int key){
	node *temp;
	
	
	if(root==NULL){
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=key;
		temp->left=temp->right=NULL;
		
		if(key<root->data){
			root->left=RecursiveInsert(root->left, key);
		}
		
		if(key>root->data){
			root->right=RecursiveInsert(root->right, key);
		}
	   
	   return root;
	}
}

void preorder(node *root){
	if(root==NULL){
		return;
	}
	
	
	cout<<root->data<<" "<<endl;
	preorder(root->left);
	preorder(root->right);
}

int main(){
	node *root1= new node(9);
	root1->left=new node(2);
	root1->left->right=new node(10);
	root1->right=new node(12);
	root1->right->left=new node(8);
	
	preorder(root1);
	cout<<endl;
	RecursiveInsert(root1, 13);
	preorder(root1);
}