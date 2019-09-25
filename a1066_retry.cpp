#include <bits/stdc++.h>
using namespace std;
struct node {
	node* lchild;
	node* rchild;
	int data,height;
};
node* newNode(int x){
	node* Node = new node;
	Node->data = x;
	Node->lchild = Node->rchild = NULL;
	Node->height = 1;
	return Node;
}
int getHeight(node* root){
	if(root==NULL) return 0;
	return root->height;
}
void updateHeight(node* root){
	root->height = max(getHeight(root->lchild),getHeight(root->rchild))+1;
}
int getBalance(node* root){
	return getHeight(root->lchild)-getHeight(root->rchild);
}
void R(node* &root){
	node* tmp = root->lchild;
	root->lchild = tmp->rchild;
	tmp->rchild = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}
void L(node* &root){
	node* tmp = root->rchild;
	root->rchild = tmp->lchild;
	tmp->lchild = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}
void insert(node* &root,int x){
	if(root==NULL){
		root = newNode(x);
	}
	else{
		if(x<root->data){
			insert(root->lchild,x);
			updateHeight(root);
			if(getBalance(root)==2){
				if(getBalance(root->lchild)==1){
					R(root);
				}
				else{
					L(root->lchild);
					R(root);
				}
			}
		}
		else{
			insert(root->rchild,x);
			updateHeight(root);
			if(getBalance(root)==-2){
				if(getBalance(root->rchild)==-1){
					L(root);
				}
				else{
					R(root->rchild);
					L(root);
				}
			}
		}
	}
}
node* root;
int main(){
	int n;
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		int x;
		scanf("%d",&x);
		insert(root,x);
	}
	printf("%d",root->data);
	return 0;
}
