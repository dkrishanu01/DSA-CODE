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

void sumReplacement(node *root){
	
	if(root==NULL){
		return;
	}
	sumReplacement(root->left);
	sumReplacement(root->right);
	
	if(root->left!=NULL){
		root->data+=root->left->data;
	}
	
	if(root->right!=NULL){
		root->data+=root->right->data;
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
	node *root1=new node(1);
	root1->left=new node(2);
	root1->left->left=new node(4); 
	root1->right=new node(3);
	root1->right->left=new node(6);
	root1->right->right=new node(7);

	preorder(root1);
	cout<<endl;
	sumReplacement(root1);
	cout<<"The sum replacement tree is:-"<<endl;
	preorder(root1);
}