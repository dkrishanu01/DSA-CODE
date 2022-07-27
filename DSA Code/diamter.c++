#include<iostream>
using namespace std;

class node{
	public:
		int data;
	    node *left;
	    node *right;
	 	
	 node(int d){
	 	this->data=d;
	 	this->left=NULL;
	 	this->right=NULL;
	 }
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

int cheight(node *root){
	if(root=NULL){
		return 0;
	}
	
	return max(cheight(root->left), cheight(root->right))+1;
}

int cdiameter(node *root){
	
	if(root=NULL){
		return 0;
	}
	int lheight=cheight(root->left);
	int rheight=cheight(root->right);
	int currdiameter=cheight(root->left)+cheight(root->right)+1;
	
	int ldiameter=cdiameter(root->left);
	int rdiameter=cdiameter(root->right);
	
	return max(currdiameter, (ldiameter, rdiameter));
}

int main(){
	 node* root = NULL;
	 	 
    //creating a Tree
    root = buildTree(root);
    
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    
    cdiameter(root);
    cout<<cdiameter(root)<<endl;
}