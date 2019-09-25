#include <bits/stdc++.h>
using namespace std;
const int maxn = 50010;
int pre[maxn],in[maxn];
void leftest(int preL,int preR,int inL,int inR){
	int k=inL;
	while(in[k]!=pre[preL])k++;
	if(k==inL){
		if(k==inR) printf("%d",in[k]);
		else leftest(preL+k-inL+1,preR,k+1,inR);
	}
	else leftest(preL+1,preL+k-inL,inL,k-1);
}
int n;
int main(){
	scanf("%d",&n);
	for(int i =0;i<n;i++)scanf("%d",&pre[i]);
	for(int i =0;i<n;i++)scanf("%d",&in[i]);
	leftest(0,n-1,0,n-1);
	return 0;
}
