#include <bits/stdc++.h>
using namespace std;
const int maxn = 50; 
struct node{
	int data;
	node *lchild;
	node *rchild;
};
int pre[maxn],in[maxn];
int n;
node *r;
node *create(int lpre,int rpre,int lin,int rin){
	if(lpre>rpre)return NULL;
	node *root  = new node;
	root->data = pre[lpre];
	int i;
	for(i = lin;i<=rin;i++)if(in[i]==pre[lpre])break;
	int lnum = i-lin;
	root->lchild = create(lpre+1,lpre+lnum,lin,i-1);
	root->rchild = create(lpre+lnum+1,rpre,i+1,rin);
	return root;
}
void postorder(node *root){
	if(root==NULL) return ;
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d",root->data);
	if(root!=r)printf(" ");
}
int main(){
	scanf("%d",&n);
	char tmp[5];
	int x;
	stack<int> s;
	for(int i =0,j=0,k=0;i<n*2;i++){
		scanf("%s",tmp);
		if(strcmp(tmp,"Push")==0){
			scanf("%d",&x);
			pre[j++] = x;
			s.push(x);
		}
		else{
			in[k++] = s.top();
			s.pop();
		}
	}
	r = create(0,n-1,0,n-1);
	postorder(r);
	return 0;
}
