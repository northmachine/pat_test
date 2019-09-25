#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int color[maxn];
struct node{
	int a,b;
}edge[maxn];
map<int,bool> chose;
int n,m,k;
int main(){
	scanf("%d %d",&n,&m);
	for(int i =0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		edge[i] = {a,b};
	} 
	scanf("%d",&k);
	for(int i =0;i<k;i++){
		chose.clear();
		int count1=0;
		for(int  j=0;j<n;j++){
			int c;
			scanf("%d",&c);
			color[j]  =c;
			if(!chose[c]){
				chose[c] = true;
				count1++;
			}
		}
		bool f = true;
		for(int j=0;j<m;j++){
			if(color[edge[j].a]==color[edge[j].b]){
			//	printf("AAA %d %d",edge[j].a,edge[j].b);
				f = false;
				break;
			}
		}
		if(f) printf("%d-coloring\n",count1);
		else printf("No\n");
	}
	return 0;
}
