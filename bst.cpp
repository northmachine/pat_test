#include <cstdio>
#define maxn 40
using namespace std;
struct node{
	int data;
	node* lchild;
	node* rchild;
};
node* newNode(int x){
	node* Node = new node;
	Node->data = x;
	Node->lchild = Node->rchild = NULL;
	return Node;
}
void search(node* root,int x){
	if(root==NULL) {
		printf("search failed\n");
		return;
	}
	if(root->data==x) printf("%d\n",root->data);
	else if(x<root->data) search(root->lchild,x);
	else search(root->rchild,x);
}
void insert(node* &root,int x){
	if(root==NULL){
		root = newNode(x);
		return ;
	}
	if(x == root->data) return;
	else if(x>root->data)
		insert(root->rchild,x);
	else insert(root->lchild,x);
}
node* Create(int data[],int n){
	node* root = NULL;
	for(int i =0;i<n;i++)
		insert(root,data[i]);
	return root;
}
node* findMax(node* root){
	while(root->rchild!=NULL)
		root = root->rchild;
	return root;
}
node* findMin(node* root){
	while(root->lchild!=NULL);
		root = root->lchild;
	return root;
}
void deleteNode(node* &root,int x){
	if(root==NULL)return;
	if(root->data==x){
		if(root->lchild==NULL&&root->rchild==NULL) root = NULL;
		else if(root->lchild!=NULL){
			node* l=findMax(root->lchild);
			root->data = l->data;
			deleteNode(root->lchild,l->data);
		}
		else{
			node* r = findMin(root->rchild);
			root->data = r->data;
			deleteNode(root->rchild,r->data);
		}
	}	
	if(root->data>x) deleteNode(root->lchild,x);
	else deleteNode(root->rchild,x);
}











