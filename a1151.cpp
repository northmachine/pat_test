#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int in[maxn],pre[maxn];
int n,m;
struct node{
	node* r;
	node* l;
	int data;
};
vector<int> f1,f2,f,res;
node* buildtree(int inL,int inR,int preL,int preR){
	if(inL>inR) return NULL;
	node* root = new node;
	root->l = root->r = NULL;
	root->data = pre[preL];
	int r=0;
	for(int i =inL;i<=inR;i++){
		if(in[i] = pre[preL]){
			r = i;
			break;
		}
	}
	int kl = r-inL;
	root->l = buildtree(inL,r-1,preL+1,preL+kl);
	root->r = buildtree(r+1,inR,preL+kl+1,preR);
	return root;
}
void dfs(node* root,int x){
	if(root==NULL) return;
	f.push_back(root->data);
	for(int i=0;i<f.size();i++) printf("%d ",f[i]);
	printf("\n");
	if(root->data==x){
		res=f;
	}
	dfs(root->l,x);
	dfs(root->r,x);
	f.pop_back();
//	printf("size1:%d\n",f.size());
}
int main(){
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	for(int i =0;i<n;i++) scanf("%d",&pre[i]);
	node* root = buildtree(0,n-1,0,n-1);
	for(int i =0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		res.clear();
		dfs(root,a);
		f1 = res;
		res.clear();
		dfs(root,b);
		f2 = res;
		if(f1.size()!=0&&f2.size()!=0){
			int j;
			for(j=0;j<f1.size()&&j<f2.size();j++){
				if(f1[j]!=f2[j])break;
			}
			printf("%d %d %d\n",f2[j-1],f1.size(),f2.size());
			if(j==f1.size())printf("%d is an ancestor of %d.\n",a,b);
			else if(j==f2.size())printf("%d is an ancestor of %d.\n",b,a);
			else printf("LCA of %d and %d is %d.\n",a,b,f1[j-1]);
		}
		else{
			if(f1.size()==0&&f2.size()==0)printf("ERROR: %d and %d are not found.\n",a,b);
			else if(f1.size()==0)printf("ERROR: %d is not found.\n",a);
			else printf("ERROR: %d is not found.\n",b);
		}
	}
	return 0;
}
