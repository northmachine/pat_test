#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
struct node{
	int l=-1,r=-1,p=-1;
}tree[maxn];
int n;
bool com = true;
bool tmp = true;
int last = 0;
void levelOrder(int root){
	queue<int> q;
	q.push(root);
	int now;
	while(!q.empty()){
		now = q.front();
		q.pop();
		if(tree[now].l!=-1) q.push(tree[now].l);
		if(tree[now].r!=-1) q.push(tree[now].r);
		if(tree[now].l==-1&&tree[now].r!=-1) com = false;
		if(!tmp&&(tree[now].l!=-1||tree[now].r!=-1)) com = false;
		if(tree[now].l==-1||tree[now].r==-1) tmp = false;
		if(q.empty()) last = now;
	}
}
int main(){
	scanf("%d",&n);
	string l,r;
	for(int i =0;i<n;i++){
		cin>>l>>r;
		if(l[0]!='-'){
			tree[i].l = stoi(l);
			tree[stoi(l)].p = i;
		}
		if(r[0]!='-'){
			tree[i].r = stoi(r);
			tree[stoi(r)].p = i;
		}
	}
	int root = 0;
	while(tree[root].p!=-1)root = tree[root].p;
	levelOrder(root);
	if(com)printf("YES %d",last);
	else printf("NO %d",root);
	return 0; 
}
