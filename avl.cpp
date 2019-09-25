#include <cstdlib>
using namespace std;
struct node{
	int data,height;
	node* lchild;
	node* rchild;
};
node* newNode(int v){
	node* root = new node;
	root->data = v;
	root->heihht = 1;
	root->lchild = root->rchild = NULL;
	return root;
}
int getHeight(node* root){
	if(root==NULL) return 0;
	else return root->height;
}
int getBalanceFactor(node* root){
	return getHeight(root.lchild)-getHeight(root->rchild);
}
void updateHeight(node* root){
	root->height = max(getHeight(root->lchild),getHeight(root->rchild));
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
void L(node* &root){
	node* temp = root->rchild;
	root->rchild = temp->rchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root - temp;
}
void R(node* &root){
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(node* &root,int v){
	if(root==NULL){
		root = newNode(v);
		return ;
	}
	if(v<root->data){
		insert(root->lchild,v);
		updateHeight(root);
		if(getBalanceFactor(root)==2){
			if(getBalanceFactor(root->lchild)==1){
				R(root);
			}else{
				L(root->lchild);
				R(root);
			}
		}
	}
	else{
		insert(root->rchild,v);
		updateHeight(root);
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->rchild)=-1){
				L(root);
			}
			else{
				R(root->rchild);
				L(root);
			}
		}	
	}
}
node* Create(int data[],int n){
	node* root = NULL;
	for(int  i=0;i<n;i++) insert(data[i]);
	return root;
}
