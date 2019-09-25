#include <cstdio>
#include <queue>
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
void search(node* root,int x,int newdata){
	if(root==NULL) return;
	if(root->data==x) root->data = newdata;
	search(root->lchild,x,newdata);
	search(root->rchild,x,newdata);
}
void insert(node* &root,int x){
	if(root==NULL){
		root = newNode(x);
		return ;
	}
	if(x>=root->data)
		insert(root->rchild,x);
	else insert(root->lchild,x);
}
node* Create(int data[],int n){
	node* root = NULL;
	for(int i =0;i<n;i++)
		insert(root,data[i]);
	return root;
}
int post[maxn];
int in[maxn];
int n,m;
node* create(int postL,int postR,int inL,int inR){
	if(postL>postR) return NULL;
	node* root = new node;
	root->data = post[postR];
	int k =inL;
	while(in[k]!=post[postR]) ++k;
	root->lchild = create(postL,postL+k-inL-1,inL,k-1);
	root->rchild = create(postL+k-inL,postR-1,k+1,inR);
	return root;
}
void levelOrderTraverals(node* root){
	if(root!=NULL){
		queue<node*> q;
		node* temp;
		q.push(root);
		while(!q.empty()){
			temp = q.front();
			q.pop();
			printf("%d",temp->data);
			if(++m<n)printf(" ");
			if(temp->lchild!=NULL) q.push(temp->lchild);
			if(temp->rchild!=NULL) q.push(temp->rchild);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i =0;i<n;i++) scanf("%d",&post[i]);
	for(int i =0;i<n;i++) scanf("%d",&in[i]);
	node* root = create(0,n-1,0,n-1);
	levelOrderTraverals(root);
	return 0;
}
