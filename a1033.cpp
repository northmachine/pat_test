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
int main(){
	scanf("%lf %lf %lf %d ",&c,&dis,&d,&n);
	for(int i =0;i<n;i++){
		scanf("%lf %lf",&station[i].price,&station[i].dis);
	}
	sort(station,station+n,cmp);
	double dnow = 0;
	double maxd = 0;
	double total = 0;
	int i = -1;
	int j = 0;
	while(j<n){
		double minp = station[j].price;
		int x = i;
		while(station[j].dis-dnow<=maxd&&j<n){
			if(station[j].price<=minp){
				i = j;
				minp = station[j].price;
			}
			j++;
		}
		j=i+1;
		if(x==i) break;
		total+=station[x].price*(station[i].dis-dnow)/d;
		//printf("%.2f\n",total);
		dnow = station[i].dis;
		printf("%.2f\n",dnow);
		maxd = c*d;
	}
	if(dnow+maxd>=dis){
		total+=station[i].price*(dis-dnow)/d;
		printf("%.2f",total);
	}
	else{
		printf("The maximum travel distance = %.2f",dnow+maxd);
	}
	return 0;
}
