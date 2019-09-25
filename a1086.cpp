#include <bits/stdc++.h>
using namespace std;
struct node{
	node *right;
	node *left;
	int data;
};
stack<node*> s;
node *r;
node *now;
node *tmp;
void postorder(node *root){
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%d",root->data);
	if(root!=r) printf(" ");
}
int main(){
	int n;
	scanf("%d",&n);
	char op[10];
	int x;
	bool f = true;
	for(int i =0;i<2*n;i++){
		scanf("%s",op);
		if(strcmp(op,"Push")==0){
			scanf("%d",&x);
			tmp = new node;
			tmp->data = x;
			tmp->left=0;
			tmp->right=0;
			if(i==0) r = tmp;
			if(now!=NULL){
				if(f)now->left = tmp;
				else {
					now->right = tmp;
					f = true;
				}
			}
			s.push(tmp);
			now = s.top();
		}
		else{
			now = s.top();
			s.pop();
			f= false;
		}
	}
	postorder(r);
//	printf("%d",r->right->left->data);
	return 0;
}
/*
3
Push 1
Push 2
Push 3
Pop
Pop
Pop
*/
