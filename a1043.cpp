#include <cstdio>
#include <vector>
using namespace std;
struct node{
	int data;
	node* lchild;
	node* rchild;
};
void insert(node* &root,int data){
	if(root==NULL){
		root = new node;
		root->data = data;
		root->lchild = root->rchild = NULL;
		return ;
	}
	if(data<root->data) insert(root->lchild,data);
	else insert(root->rchild,data);
}
void preOrder(node* root,vector<int> &pre){
	if(root==NULL) return ;
	pre.push_back(root->data);
	preOrder(root->lchild,pre);
	preOrder(root->rchild,pre);
}
void preOrderMirror(node* root,vector<int> &preM){
	if(root==NULL) return ;
	preM.push_back(root->data);
	preOrderMirror(root->rchild,preM);
	preOrderMirror(root->lchild,preM);
}
void postOrder(node* root,vector<int> &post){
	if(root==NULL) return ;
	postOrder(root->lchild,post);
	postOrder(root->rchild,post);
	post.push_back(root->data);
}
void postOrderMirror(node* root,vector<int> &postM){
	if(root==NULL) return ;
	postOrderMirror(root->rchild,postM);
	postOrderMirror(root->lchild,postM);
	postM.push_back(root->data);
}
vector<int> origin,pre,preM,post,postM;
int main(){
	int  n,x;
	node* root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		origin.push_back(x);
		insert(root,x);
	} 
	preOrder(root,pre);
	preOrderMirror(root,preM);
	postOrder(root,post);
	postOrderMirror(root,postM);
	if(origin==pre){
		printf("YES\n");
		for(int i=0;i<n;i++){
			printf("%d",post[i]);
			if(i!=n-1) printf(" ");
		}
	}
	else if(origin==preM){
		printf("YES\n");
		for(int i=0;i<n;i++){
			printf("%d",postM[i]);
			if(i!=n-1) printf(" ");
		}
	}
	else printf("NO");
	return 0;
}
