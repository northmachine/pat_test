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
int main(){
	scanf("%lf %lf %lf %d ",&c,&dis,&d,&n);
	for(int i =0;i<n;i++){
		scanf("%lf %lf",&station[i].price,&station[i].dis);
	};
	sort(station,station+n,cmp);
	if(station[0].dis!=0){
		printf("The maximum travel distance = 0.00");
	}
	else{
		station[n].dis = dis;
		int now = 0;
		double total = 0,tank = 0,maxd = c*d;
		while(now<n){
			int k =-1;
			double min = 1000000000;
			for(int i =now+1;i<=n&&station[i].dis-station[now].dis<=maxd;i++){
				if(station[i].price<min){
					min = station[i].price;
					k = i;
					if(min<station[now].price) break;
				}
			}
			if(k==-1) break;
			double need = (station[k].dis-station[now].dis)/d;
			if(min<station[now].price){
				if(tank<need){
					total+=(need-tank)*station[now].price;
					tank = 0;
				}
				else tank -= need;
			}
			else{
				total+=(c-tank)*station[now].price;
				tank = c-need;
			}
			now = k;
		}
		if(now == n)printf("%.2f",total);
		else printf("The maximum travel distance = %.2f",station[now].dis+maxd);
	}
	return 0;
}
