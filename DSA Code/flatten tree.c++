#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *right, *left;
	
	node(int value){
		data=value;
		right=left=NULL;
	}
};

void flattenTree(node *root){
	if(root==NULL || root->left==NULL && root->right){
		return;
	}
	
	if(root->left!=NULL){
		flattenTree(root->left);
		
		node *temp=root->right;	
		root->right=root->left;
		root->left=NULL;
		
		node *t=root->right;
		
		while(t->right!=NULL){
			t=t->right;
			
		}
		
		 t->right=temp;
	}
	
	flattenTree(root->right);
}

void inorder(node *root){
	if(root==NULL){
		return;
	}
	
	inorder(root->left);
	cout<<root->data<<"   ";
	inorder(root->right);
}

int main(){
	node *root1=new node(1);
	root1->left=new node(2);
	root1->left->left=new node(4); 
	root1->right=new node(3);
	root1->right->left=new node(6);
	root1->right->right=new node(7);
	
	flattenTree(root1);
	cout<<"The flatten tree is:-"<<endl;
	inorder(root1);
}