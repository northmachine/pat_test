#include <cstdio>
#include <cstdlib>
const int maxn = 100010;
int n,m;
int dis[maxn];
int total;
int shortest(int a,int b){
	int x=0,y=0;
	int s = a>b?a:b;
	x = dis[s]-dis[a+b-s];
	y = total-x;
	return x<y?x:y;
}
int main(){
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%d",&dis[i+1]);
		total+=dis[i+1];
		dis[i+1] = total;
	}
	scanf("%d",&m);
	int a,b;
	for(int i =0;i<m;i++){
		scanf("%d %d",&a,&b);
		printf("%d\n",shortest(a-1,b-1));
	}
	return 0;
}
