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

node *LCA(node *root, int n1, int n2){
	
	if(root==NULL){
		return NULL;
	}
	
	if(root->data==n1 || root->data==n2){
		return root;
	}
	
	node *left=LCA(root->left, n1, n2);
	node *right=LCA(root->right, n1, n2);
    	
	if(left!=NULL && right!=NULL){
		return root;
	}
	
	if(left==NULL && right==NULL){
		return NULL;
	}
	if(left!=NULL){
		return LCA(root->left, n1, n2);
	}
	
	return LCA(root->right, n1, n2);
}

int findDist(node *root, int k, int dist){
	if(root==NULL){
		return -1;
	}
	
	if(root->data==k){
		return dist;
	}
	
	int left=findDist(root->left, k, dist+1);
	if(left!=-1){
		return left;
	}
	return findDist(root->right, k, dist+1);
	
	
}

int DistBetwNodes(node *root, int n1, int n2){
	
	node *lca=LCA(root, n1, n2);
    int d1=findDist(lca, n1, 0);
    int d2=findDist(lca, n2, 0);
    return d1+d2;
}

int main()
{
	node *root1=new node(10);
	root1->left=new node(6);
	root1->left->left=new node(5);
	root1->left->right=new node(7);
	root1->right=new node(9);
	root1->right->right=new node(11);
	root1->right->left=new node(8);
	
	cout<<"The distance between two nodes is:-"<<DistBetwNodes(root1, 5, 11)<<endl;
	return 0;
}