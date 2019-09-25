#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
	int lchild=-1;
	int rchild=-1;
	int parent=-1;
}tree[11];
int count1=0;
void inorder(int r){
	if(r==-1) return ;
	inorder(tree[r].rchild);
	printf("%d",r);
	if(count1++<n-1)printf(" ");
	inorder(tree[r].lchild);
}
int count2=0;
void levelorder(int r){
	queue<int> q;
	q.push(r);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		printf("%d",t);
		if(count2++<n-1) printf(" ");
		if(tree[t].rchild!=-1)q.push(tree[t].rchild);
		if(tree[t].lchild!=-1)q.push(tree[t].lchild);
	}
}
int root;
int main(){
	scanf("%d",&n);
	char l,r;
	for(int i =0;i<n;i++){
		scanf("%*c%c %c",&l,&r);
		if(l!='-'){
			tree[i].lchild = l-'0';
			tree[l-'0'].parent = i;
		}
		if(r!='-'){
			tree[i].rchild = r-'0';
			tree[r-'0'].parent = i;
		}
	}
	root=0;
	while(tree[root].parent!=-1){
		root = tree[root].parent;
	}
	levelorder(root);
	printf("\n");
	inorder(root);
	return 0;
} 
