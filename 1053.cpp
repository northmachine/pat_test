#include <bits/stdc++.h>
#define maxn 110
using namespace std;
struct node{
	int data;
	int parent=-1;
	vector<int> child;
}Node[maxn];
vector<int> res[maxn];
int resnum;
bool cmp(vector<int> a,vector<int> b){
	int i =a.size(),j=b.size();
	while(a[--i]==b[--j]&&i>0&&j>0);
	if(i==0)return 1<2;
	else if(j==0)return 2>1;
	else return a[i]>b[j];
}
void DFS(int r,int s,int ans){
	if(ans>s)return ;
	int c = Node[r].child.size();
	if(c!=0)
		for(int i =0;i<c;i++)
			DFS(Node[r].child[i],s,ans+Node[r].data);
	else
		if(ans+Node[r].data==s){
			int p = r;
			while(p!=-1){
				res[resnum].push_back(Node[p].data);
				p = Node[p].parent;
			}
			resnum++;
		}
}
int main(){
	int n,m,s;
	int nn,x,c;
	scanf("%d %d %d",&n,&m,&s);
	for(int i =0;i<n;i++)
		scanf("%d ",&Node[i].data);
	for(int i =0;i<m;i++){
		scanf("%d ",&nn);
		scanf("%d ",&c);
		for(int j = 0;j<c;j++){
			scanf("%d",&x);
			Node[nn].child.push_back(x);
			Node[x].parent = nn;
		}
	}
	int p;
	while(Node[p].parent!=-1) p = Node[p].parent;
	DFS(p,s,0);
	sort(res+0,res+resnum,cmp);
	for(int i =0;i<resnum;i++){
		int j = res[i].size();
		for(int k =0;k<j;k++){
			printf("%d",res[i][j-1-k]);
			if(k!=j-1) printf(" ");
		}
		if(i!=resnum-1) printf("\n");
	}
	return 0;
} 
