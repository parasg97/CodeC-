#include <bits/stdc++.h>

using namespace std;



struct Tree
{
	int val;
	Tree* left;
	Tree* right;
	Tree(int val){
		this->val=val;
		left=NULL;
		right=NULL;
	}
};

void bfs(Tree* root){
	if(root==NULL){
		return;
	}
	cout<<root->val<<" ";
	bfs(root->left);
	bfs(root->right);
}

//traverse the tree in sorted of if tree is a BST
void inOrder(Tree* root){
	if(root==NULL){
		return;
	}
	inOrder(root->left);
	cout<<root->val<<" ";
	inOrder(root->right);
}

void preOrder(Tree* root){
	if(root==NULL){
		return;
	}
	cout<<root->val<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(Tree* root){
	if(root==NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->val<<" ";
}

int main(int argc, char const *argv[])
{
	Tree* root = new Tree(10);
	root->left= new Tree(9);
	root->right = new Tree(12);
	cout<<root->left->val<<endl;
	inOrder(root);
	cout<<endl;
	preOrder(root);
	cout<<endl;
	postOrder(root);
	cout<<endl;
	bfs(root);
	return 0;
}