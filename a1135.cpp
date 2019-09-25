#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
struct node{
	node* l;
	node* r;
	int data;
};
void insert(node* &r,int x){
	if(r==NULL){
		r = new node;
		r->l = r->r = NULL;
		r->data = x;
	}
	else if(abs(x)>abs(r->data)){
		insert(r->r,x);
	}
	else insert(r->l,x);
}
bool f;
int counter;
void dfs(node* root,int c){
	if(root==NULL){
		if(counter==-1){
			counter=c;
		}
		else if(counter!=c){
			f = false;
		}
	}
	else {
		if(root->data>0) c++;
		else if(root->l!=NULL&&root->l->data<0||root->r!=NULL&&root->r->data<0){
			f = false;
			return ;
		}
		dfs(root->l,c);
		dfs(root->r,c);
	}
}
node* root;
int main(){
	int k;
	scanf("%d",&k);
	for(int i =0;i<k;i++){
		root = NULL;
		int l;
		scanf("%d",&l);
		for(int j=0;j<l;j++){
			int x;
			scanf("%d",&x);
			insert(root,x);
		}
		f = true;
		if(root->data<0) f = false;
		counter=-1;
		dfs(root,0);
		if(f)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
