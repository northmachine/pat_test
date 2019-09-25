#include <bits/stdc++.h>
using namespace std;
struct node{
	node* l;
	node* r;
	int data;
	int height;
	node(int _data):data(_data){
		l = r = NULL;
		height = 1;
	}
};
int getHeight(node* r){
	return r!=NULL?r->height:0;
}
void updateHeight(node* r){
	r->height = max(getHeight(r->l),getHeight(r->r))+1;
}
int getBalance(node* r){
	return getHeight(r->l)-getHeight(r->r);
}
void R(node* &root){
	node* tmp = root->l;
	root->l = tmp->r;
	tmp->r = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}
void L(node* &root){
	node* tmp = root->r;
	root->r = tmp->l;
	tmp->l = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}
void insert(node* &root,int x){
	if(root==NULL){
		root = new node(x);
	}
	else{
		if(x<root->data){
			insert(root->l,x);
			updateHeight(root);
			if(getBalance(root)==2){
				if(getBalance(root->l)==1){
					R(root);
				}
				else{
					L(root->l);
					R(root);
				}
			}
		}
		else{
			insert(root->r,x);
			updateHeight(root);
			if(getBalance(root)==-2){
				if(getBalance(root->r)==-1){
					L(root);
				}
				else{
					R(root->r);
					L(root);
				}
			}
		}
	}
}
int n;
node* root;
vector<int> cache;
void levelOrder(node* root){
	cache.push_back(0);
	queue<node*> q;
	q.push(root);
	node* sym = q.back();
	node* now;
	while(!q.empty()){
		now = q.front();
		cache.push_back(now->data);
		q.pop();
		if(now->l!=NULL) q.push(now->l);
		if(now->r!=NULL) q.push(now->r);
		if(now==sym){
			sym = q.back();
		}
	}
}
bool f = true;
void preOrder(int r){
	if(2*r<=n){
		if(cache[2*r]>cache[r]) f = false;
		preOrder(2*r);
	}
	if(2*r+1<=n){
		if(cache[2*r+1]<cache[r]) f = false;
		preOrder(2*r+1);
	}
}
int main(){
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		int x;
		scanf("%d",&x);
		insert(root,x);
	}
	levelOrder(root);
	for(int  i=1;i<=n;i++){
		printf("%d",cache[i]);
		if(i!=n)printf(" ");
	}
	preOrder(1);
	if(f)printf("\nYES");
	else printf("\nNO");
	return 0;
}
