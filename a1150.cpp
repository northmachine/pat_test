#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
int G[maxn][maxn];
set<int> vis;
int tmp[maxn];
int n,m;
int main(){
	int index,mind=0x7fffffff;
	scanf("%d %d",&n,&m);
	for(int i =0;i<m;i++){
		int a,b,d;
		scanf("%d %d %d",&a,&b,&d);
		G[a][b] = G[b][a] = d;
	}
	int k;
	scanf("%d",&k);
	for(int i =0;i<k;i++){
		int num,a,b,s;
		scanf("%d %d",&num,&a);
		s = a;
		vis.clear();
		int dis=0;
		bool f3 = true;
		for(int j=0;j<num-1;j++){
			if(!f3)continue;
			scanf("%d",&b);
			if(G[a][b]!=0)dis+=G[a][b];
			else{
				dis=-1;
				f3 = false;
			}
			vis.insert(b);
			a=b;
		}
		bool f1= true,f2 = false;
		if(vis.size()<n)f1 = false;
		else if(num==n+1)f2 = true;
		if(f1){	
			if(f2)printf("Path %d: %d (TS simple cycle)\n",i+1,dis);
			else printf("Path %d: %d (TS cycle)\n",i+1,dis);
			if(dis<mind){
				index = i+1;
				mind = dis;
			}
		}
		else {
			printf("Path %d: ",i+1);
			if(dis==-1)printf("NA (Not a TS cycle)\n");
			else printf("%d (Not a TS cycle)\n",dis);
		}
	}
	printf("Shortest Dist(%d) = %d",index,mind);
	return 0;
}
