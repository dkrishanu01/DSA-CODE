#include<iostream>
using namespace std;

struct node{
	int value;
	struct node *right, *left;
	
	node(int value){
		int data;
		data=value;
		right=left=NULL;
	}
};

bool isBalanced(node *root, int *height){
	
	if(root==NULL){                        //time complexity O(n)..
		return true;
	}
	
	int lh=0, rh=0;
	if(isBalanced(root->left, &lh)==false){
		return false;
	}
	
	if(isBalanced(root->right, &rh)==false){
		return false;
	}
	
	*height=max(lh, rh)+1;
	
	if(abs(lh-rh)<=1){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	node *root1=new node(1);
	root1->left=new node(2);
	root1->left->left=new node(4); 
	root1->right=new node(3);
	root1->right->left=new node(6);
	root1->right->right=new node(7);
	
//	node *root2=new node(1);
//	root2->left=new node(2);
//	root2->left->left=new node(3);
	
	
	//calling height function
	int height=0;
	
	if(isBalanced(root1, &height)==true){
		cout<<"Balanced Tree"<<endl;
	}
	else{
		cout<<"Not a Balanced Tree"<<endl;
	}
}