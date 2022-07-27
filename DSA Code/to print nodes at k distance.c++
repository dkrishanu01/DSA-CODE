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

//case1
void printSubtreeNodes(node *root, int k){
	if(root==NULL || k<0){
		return;
	}
	
	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	
	printSubtreeNodes(root->left, k-1);
	printSubtreeNodes(root->right, k-1);
}

//case2
int printNodesAtk(node *root, node *target, int k){
	if(root==NULL){
		return -1;
	}
	
	if(root==target){
		printSubtreeNodes(root, k);
		return 0;
	}
	
	int dl=printNodesAtk(root->left, target, k);
	
	if(dl!=-1){
		if(dl+1==k){
			cout<<root->data<<" ";
		}
		
		else{
			printSubtreeNodes(root->right, k-dl-2);
		}
		
		return 1+dl;
	}
	
	int dr=printNodesAtk(root->left, target, k);
	
	if(dr!=-1){
		if(dr+1==k){
			cout<<root->data<<" ";
		}
		
		else{
			printSubtreeNodes(root->left, k-dr-2);
		}
		
		return 1+dr;
	}
}

int main(){
	
	node *root1=new node(1);
	root1->left=new node(2);
	root1->right=new node(3);
	root1->left->left=new node(4);
	
	printNodesAtk(root1, root1->left, 2);
}
