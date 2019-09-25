#include <bits/stdc++.h> 
using namespace std;
const int maxn = 50;
int n;
int in[maxn],post[maxn];
struct node{
	node* l;
	node* r;
	int data;
};
node* root;
node* create(int inL,int inR,int postL,int postR){
	if(inL>inR) return NULL;
	node* root = new node;
	root->data = post[postR];
	int r = 0;
	for(int i=inL;i<=inR;i++){
		if(in[i]==post[postR]){
			r = i;
			break;
		}
	}
	int rk = inR-r;
	root->r = create(r+1,inR,postR-rk,postR-1);
	root->l = create(inL,r-1,postL,postR-rk-1);
	return root;
}
void levelOrder(){
	vector<int> cache;
	queue<node*> q;
	q.push(root);
	node* sym = q.back();
	node* now;
	bool f = false;
	int counter = 0;
	while(!q.empty()){
		now =q.front();
		q.pop();
		cache.push_back(now->data);
		if(now->l!=NULL)q.push(now->l);
		if(now->r!=NULL)q.push(now->r);
		if(now==sym){
			if(f){
				for(int i =0;i<cache.size();i++){
					printf("%d",cache[i]);
					counter++;
					if(counter!=n)printf(" ");
				}
			}
			else{
				for(int i =cache.size()-1;i>=0;i--){
					printf("%d",cache[i]);
					counter++;
					if(counter!=n) printf(" ");
				}
			}
			cache.clear();
			sym = q.back();
			f = !f;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	root = create(0,n-1,0,n-1);
	levelOrder();
	return 0;
}
