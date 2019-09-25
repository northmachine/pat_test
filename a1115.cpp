#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
struct node{
	node* l;
	node* r;
	int data;
};
int n;
node* root;
void insert(node* &root,int x){
	if(root==NULL){
		root = new node;
		root->data = x;
		root->l = root->r = NULL;
	}
	else if(x<=root->data) insert(root->l,x);
	else insert(root->r,x);
}
int n1,n2;
void levelOrder(){
	queue<node*> q;
	q.push(root);
	node* sym = q.back();
	node* now;
	int counter = 0;
	while(!q.empty()){
		now = q.front();
		q.pop();
		counter++;
		if(now->l!=NULL)q.push(now->l);
		if(now->r!=NULL)q.push(now->r);
		if(now==sym){
			n2 = n1;
			n1 = counter;
			counter=0;
			sym = q.back();
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		int x;
		scanf("%d",&x);
		insert(root,x);
	}
	levelOrder();
	printf("%d + %d = %d",n1,n2,n1+n2);
	return 0;
}
