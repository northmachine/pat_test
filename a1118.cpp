#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n;
int a[maxn];
int getFather(int t){
	int x=t;
	while(a[x]!=x)x = a[x];
	while(a[t]!=t){
		int tmp = t;
		t = a[t];
		a[tmp] = x;
	}
	return x;
}
void join(int x,int y){
	int fa = getFather(x);
	int fb = getFather(y);
	a[fb] = fa;
}
int main(){
	scanf("%d",&n);
	for(int i =0;i<maxn;i++)a[i] = i;
	int maxb=0;
	for(int i=0;i<n;i++){
		int num;
		int pre;
		scanf("%d %d",&num,&pre);
		if(pre>maxb)maxb = pre;
		for(int j =1;j<num;j++){
			int x;
			scanf("%d",&x);
			if(x>maxb)maxb = x;
			join(x,pre);
			pre = x;
		}
	}
	int treenum=0;
	for(int i=1;i<=maxb;i++){
		if(a[i]==i)treenum++;
	}
	printf("%d %d\n",treenum,maxb);
	int k;
	scanf("%d",&k);
	for(int i =0;i<k;i++){
		int a,b;
		scanf("%d %d",&a,&b);
	//	printf("father: %d %d\n",getFather(a),getFather(b));
		if(getFather(a)==getFather(b))printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
