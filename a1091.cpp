#include <bits/stdc++.h>
using namespace std;
int brain[1300][150][100];
bool vis[1300][150][100];
int m,n,l,t;
struct node{
	int mm,nn,ll;
	node(){}
	node(int _mm,int _nn,int _ll):mm(_mm),nn(_nn),ll(_ll){}
};
void add(node &a){
	a.nn++;
	if(a.nn==n){
		a.nn = 0;
		a.mm++;
		if(a.mm==m){
			a.mm=0;
			a.ll++;
		}
	}
}
bool accessible(node a){
	if(a.ll>=0&&a.mm>=0&&a.nn>=0&&a.ll<l&&a.mm<m&&a.nn<n&&brain[a.nn][a.mm][a.ll]==1&&!vis[a.nn][a.mm][a.ll])
		return true;
	else return false;
}
queue<node> q;
int bfs(node a){
	int sum =0;
	if(accessible(a)){
		q.push(a);
		vis[a.nn][a.mm][a.ll] = true;
	}
	while(!q.empty()){
		node tmp = q.front();
		q.pop();
		sum++;
		node v[6];
		v[0] = node(tmp.mm,tmp.nn+1,tmp.ll);
		v[1] = node(tmp.mm,tmp.nn-1,tmp.ll);
		v[2] = node(tmp.mm+1,tmp.nn,tmp.ll);
		v[3] = node(tmp.mm-1,tmp.nn,tmp.ll);
		v[4] = node(tmp.mm,tmp.nn,tmp.ll+1);
		v[5] = node(tmp.mm,tmp.nn,tmp.ll-1);
		for(int  i=0;i<6;i++){
			if(accessible(v[i])){
				vis[v[i].nn][v[i].mm][v[i].ll] = true;
				q.push(v[i]);
			}
		}
	}
	return sum;
}
int main(){
	scanf("%d %d %d %d",&m,&n,&l,&t);
	for(int i =0;i<l;i++){
		for(int j=0;j<m;j++){
			for(int k =0;k<n;k++){
				scanf("%d",&brain[k][j][i]);
			}
		}
	}
	int res = 0;
	int j=0;
	for(node i = node(0,0,0);i.ll<l;add(i),j++){
		int sum=bfs(i);
		if(sum>=t) res+=sum;
	}
	printf("%d",res);
	return 0;
}
