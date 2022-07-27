#include<iostream>
#include<queue>
using namespace std;

struct node{
	int data;
	struct node *right, *left;
	
	//constructor
	node(int value){
		data=value;
		right=left=NULL;
	}
};

void rightview(node *root){
	if(root==NULL){
		return;
	}
	
	queue<node*> q;
	q.push(root);
	
	while(!q.empty()){
		int n=q.size();
		
		for(int i=0; i<n; i++){
			node *curr=q.front();
			q.pop();
			 
			if(i==n-1){
				cout<<curr->data<<" ";
			} 
			
			if(curr->left!=NULL){
				q.push(curr->left);
			}
			
			if(curr->right!=NULL){
				q.push(curr->right);
			}
	
		}
	}
}

int main(){
	node *root1=new node(2);
	root1->left=new node(5);
	root1->left->left=new node(9); 
	root1->left->right=new node(10); 
	root1->right=new node(8);
	root1->right->left=new node(11);
	root1->right->right=new node(12);
	root1->right->right->left=new node(13);
	root1->right->right->right=new node(16);
    
    cout<<"The right view nodes are:-";
    rightview(root1 );
    return 0;
}