#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n; 
int a[maxn],tree[maxn];
int c=0;
void dfs(int index){
	if(index>=n) return;
	dfs(2*index+1);
	tree[index] = a[c++];
	dfs(2*index+2);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	dfs(0);
	for(int i =0;i<n;i++){
		printf("%d",tree[i]);
		if(i!=n-1) printf(" ");
	}
	return 0;
}
