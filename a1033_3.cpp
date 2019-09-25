#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 510;
double c,dis,d;
int n;
struct node{
	double price;
	double dis;
}station[maxn];
bool cmp(node a,node b){
	return a.dis<b.dis;
}
int road[maxn];
int r;
int trace[maxn];
int t;
int main(){
	scanf("%lf %lf %lf %d ",&c,&dis,&d,&n);
	for(int i =0;i<n;i++){
		scanf("%lf %lf",&station[i].price,&station[i].dis);
	};
	sort(station,station+n,cmp);
	station[n].dis = dis;
	double ndis = 0;
	double maxd = 0;
	int i=-1;
	double total = 0;
	while(i<n&&ndis+maxd>=station[i+1].dis){
		int j=i+1;
		double price = i>=0?station[i].price:99999;
		for(;j<n&&ndis+maxd>=station[j].dis;j++){
			if(station[j].price<=price) break;
		}
		if(ndis+maxd<station[j].dis) j--;
		printf("%.2f\n",station[j].dis);
		ndis = station[j].dis;
		maxd = c*d;
		i=j;
		trace[t++] = j;
		printf("%d\n",j);
	}
	
	if(ndis == dis){
		printf("%.2f",total);
	}
	else printf("The maximum travel distance = %.2f",ndis+maxd);
	return 0;
}
