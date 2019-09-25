#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 1010;
struct node{
	string name;
	int month,d,h,m;
	bool flag;
};
struct cam{
	int mi;
	float cost;
	cam(int _mi,float _cost): mi(_mi),cost(_cost){}
};
int price[24];
int n;
node record[maxn];
bool cmp(node a,node b){
	if(a.name!=b.name) return a.name<b.name;
	else if(a.month!=b.month) return a.month<b.month;
	else if(a.d!=b.d) return a.d<b.d;
	else if(a.h!=b.h) return a.h<b.h;
	else return a.m<b.m;
}
cam cost(node a,node b){
	float cost=0;
	int mi=0;
	while(b.d!=a.d||b.h!=a.h||b.m!=a.m){
		cost+=(float)price[a.h]/100;
		a.m++;
		mi++;
		if(a.m>59){
			a.m=0;
			a.h++;
			if(a.h>23){
				a.h=0;
				a.d++;
			}
		}
	}
	return cam(mi,cost);
} 
int main(){
	for(int  i=0;i<24;i++){
		scanf("%d",&price[i]);
	}
	scanf("%d",&n);
	string flag;
	for(int  i=0;i<n;i++){
		cin>>record[i].name;
		scanf("%d:%d:%d:%d",&record[i].month,&record[i].d,&record[i].h,&record[i].m);
		cin>>flag;
		if(flag=="on-line") record[i].flag=1;		
	}
	sort(record,record+n,cmp);
	/*
	for(int i=0;i<n;i++){
		cout<<record[i].name;
		printf(" %02d:%02d:%02d:%02d ",record[i].month,record[i].d,record[i].h,record[i].m);
		if(record[i].flag==true) printf("on-line\n");
		else printf("off-line\n"); 
	}
	*/
	/*
	for(int i=0;i<n-1;){
		int x = i;
		float total=0;
		bool zero = true;
		while(record[x].name==record[i].name&&record[x].month==record[i].month&&x<n-1){

			++x;
			if(!record[x].flag){
				if(zero){
					cout<<record[i].name;
					printf(" %02d\n",record[i].month);
				}
				zero = false;
				cam tmp = cost(record[x-1],record[x]);
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
						record[x-1].d,record[x-1].h,record[x-1].m,
						record[x].d,record[x].h,record[x].m,tmp.mi,tmp.cost);
				total+=tmp.cost;
			}
		}
		i=x;
		if(total!=0)
			printf("Total amount: $%.2f",total);
		if(i!=n-1&&!zero)printf("\n");
	}
	*/
	
	
	string now = record[0].name;
	bool zero = true;
	float total =0;
	for(int  i=0;i<n;i++){
		if(record[i].name==now&&record[i].flag==false){
			if(zero){
				cout<<now;
				printf(" %02d\n",record[i].month);
			}
			cam  tmp = cost(record[i-1],record[i]);
			total+=tmp.cost;
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
				record[i-1].d,record[i-1].h,record[i-1].m,
				record[i].d,record[i].h,record[i].m,
				tmp.mi,tmp.cost);
			zero = false;
		}
		else if(record[i].name!=now&&!zero){
			zero = true;
			now = record[i].name;
			printf("Total amount: $%.2f\n",total);
			total = 0;
		}
		if(i==n-1&&!zero)printf("Total amount: $%.2f\n",total);
	}
	return 0;
}

/*
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
5
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-ilne
aaa 01:05:02:24 on-line
aaa 01:02:00:02 off-line


*/
