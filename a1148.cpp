#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n;
int state[maxn]={0},state2[maxn] = {0};
struct node{
	int w1,w2;
};
node w[maxn*maxn];
int ansnum;
bool tmp[maxn];
bool cmp(node a,node b){
	if(a.w1!=b.w1)return a.w1<b.w1;
	else return a.w2<b.w2;
}
bool check(int a,int b){
	memset(tmp,false,sizeof(tmp));
	for(int i=1;i<=n;i++){
		if(i==a||i==b)tmp[i] = true;
	}
	bool f=false;
	for(int i=1;i<=n;i++){
		if(i!=a&&i!=b)continue;
		for(int j=1;j<=n;j++){
			if(j==a||j==b)continue;
			for(int k=1;k<=n;k++){
				if(k==i||k==j)state2[k] = -state[k];
				else state2[k] = state[k];
			}
		//	for(int k=1;k<=n;k++)printf("%d ",state2[k]);
		//	printf("\n");
			bool f2 = true;
			for(int k=1;k<=n;k++){
				if(tmp[abs(state2[k])]==true&&state2[k]>0||tmp[abs(state2[k])]==false&&state2[k]<0)f2 = false;
			}
			if(f2)f = true;
		}
	}
	return f;
}
int main(){
	scanf("%d",&n);
	for(int i =1;i<=n;i++){
		scanf("%d",&state[i]);
	}
	for(int i =1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(check(i,j)) w[ansnum++] = {i,j};
		}
	}
	sort(w,w+ansnum,cmp);
	if(ansnum!=0)printf("%d %d",w[0].w1,w[0].w2);
	else printf("No Solution");
	return 0;
} 
