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

int maxSumUtil(node *root, int ans){
	if(root==NULL){
		return 0;
	}
	
	int left=maxSumUtil(root->left, ans);
	int right=maxSumUtil(root->right, ans);
	
	int nodeMax=max(max(root->data, root->data+left+right), max(root->data+left, root->data+right));
	ans=max(ans, nodeMax);
	
	int singlePath=max(root->data, max(root->data+left, root->data+right));
	return singlePath;
}

int maxSumPath(node *root){
	int ans= INT_MIN;
	maxSumUtil(root, ans);
	return ans;
}

int main(){
	node *root1=new node(1);
	root1->left=new node(2);
	root1->left->left=new node(4); 
	root1->right=new node(3);
	root1->right->left=new node(6);
	root1->right->right=new node(7);
	
	cout<<"The maximum sum path of a tree is:-"<<endl<<maxSumPath(root1);
}