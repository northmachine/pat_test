#include <cstdio>
#include <algorithm>
using namespace std;
int n;
double amount;
struct node{
	double amount;
	double price;
}cakes[1010];
double total;
bool cmp(node a,node b){
	return a.price/a.amount>b.price/b.amount;
}
int main(){
	scanf("%d %lf",&n,&amount);
	for(int i =0;i<n;i++){
		scanf("%lf",&cakes[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%lf",&cakes[i].price);
	}
	sort(cakes,cakes+n,cmp);
	int i=0;
	while(amount>0&&i<n){
		if(cakes[i].amount<amount){
			amount-=cakes[i].amount;
			total+=cakes[i].price;
			i++;
		}
		else{
			total+=(double)amount*cakes[i].price/(double)cakes[i].amount;
			amount =0;
		}
	}
	printf("%.2f",total);
	return 0;
}
