#include<iostream>
#include<stack>
using namespace std;

struct node{
	
	int data;
	node *right, *left;
	
	node(int value){
		data=value;
		right=left=NULL;
	}
};

void ZigZagTraversal(node *root){
	
	if(root==NULL){
			return;
		}
	
	stack<node*> currlevel;
	stack<node*> nextlevel;
	
	bool LeftToRight=true;
	
	currlevel.push(root);
	
	while(!currlevel.empty()){
		
		node *ans=currlevel.top();
		currlevel.pop();
		
		if(ans){
			cout<<ans->data<<" ";
			
			if(LeftToRight){
				
				if(ans->left){
					nextlevel.push(ans->left);
				}
				
				if(ans->right){
					nextlevel.push(ans->right);
				}
			}
			
			else{
				if(ans->right){
					nextlevel.push(ans->right);
				}
				
				if(ans->left){
					nextlevel.push(ans->left);
				}
			}
		}
		
		if(currlevel.empty()){
		
		LeftToRight=!LeftToRight;
		swap(currlevel, nextlevel);
	}
		
  }
}
int main(){
	
	node *root=new node(15);
	root->left=new node(10);
	root->left->left=new node(5);
	root->left->right=new node(11);
	root->right=new node(20);
	root->right->left=new node(18);
	root->right->right=new node(21);
	
	ZigZagTraversal(root);
	cout<<endl;
}