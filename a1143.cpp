#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct node{
	node* l;
	node* r;
	int data;
};
void insert(node* &r,int x){
	if(r==NULL){
		r = new node;
		r->data = x;
		r->l = r->r = NULL;
	}
	else if(x>r->data) insert(r->r,x);
	else insert(r->l,x);
}
map<int,bool> tb;
int n,m;
void lca(int a,int b,node* r){
	if(r->data>a&&r->data>b)return lca(a,b,r->l);
	else if(r->data<a&&r->data<b)return lca(a,b,r->r);
	else if(r->data==a)printf("%d is an ancestor of %d.\n",a,b);
	else if(r->data==b) printf("%d is an ancestor of %d.\n",b,a);
	else printf("LCA of %d and %d is %d.\n",a,b,r->data);
}
node* root;
int main(){
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		insert(root,x);
		tb[x]=true;
	}
	printf("%d\n",root->data);
	for(int i =0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(!tb[a]&&!tb[b])printf("ERROR: %d and %d are not found.\n",a,b);
		else if(tb[a]&&tb[b])lca(a,b,root);
		else printf("ERROR: %d is not found.\n",tb[a]?b:a); 
	}
	return 0;
}
