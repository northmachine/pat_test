#include <cstdio>
#include <algorithm>
using namespace std;
struct lap{
	double left;
	double price=0;
};
bool cmp(lap a,lap b){
	return a.price>b.price;
}
int main(){
	int N,m;
	scanf("%d%d",&N,&m);
	lap *ary = (lap*)malloc(N*sizeof(lap));
	for(int i=0;i<N;i++) scanf("%lf",&ary[i].left);
	for(int i=0;i<N;i++) scanf("%lf",&ary[i].price);
	for(int i=0;i<N;i++) ary[i].price /= ary[i].left;
	sort(ary+0,ary+N,cmp);
	double ans = 0.0;
	int j=0;
	while(m-ary[j].left>=0 && j!=N){
		m-=ary[j].left;
		ans = ans + ary[j].price*ary[j].left;
		++j;
	}
	ans = ans + ary[j].price*m;
	printf("%.2f",ans);
	return 0;
} 
