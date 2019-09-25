#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
const int maxn = 10010;
struct node{
	string plate;
	int time;
	bool flag;
}rec[maxn];
bool cmp(node a,node b){
	return a.time<b.time;
}
map<string,bool> table;
int n,k;
int main(){
	scanf("%d %d",&n,&k);
	int h,m,s;
	char status[4];
	for(int i =0;i<n;i++){
		cin>>rec[i].plate;
		scanf("%d:%d:%d",&h,&m,&s);
		rec[i].time = h*10000+m*100+s;
		scanf("%s",status);
		if(strcmp(status,"in")==0)rec[i].flag = true;
	}
	sort(rec,rec+n,cmp);
	for(int i =0;i<n;i++){
		if(rec[i].flag&&table[rec[i].plate]==false){
			table[rec[i].plate] = false;
		}
		else if(!rec[i].flag&&table.find(rec[i].plate)!=table.end()){
			table[rec[i].plate] = true;
		}
	}
	for(auto iter = table.begin();iter!=table.end();iter++){
		printf("%d\n",iter->second);
	}
	for(int i =0;i<n;i++){
		cout<<rec[i].plate;
		printf(" %d %d\n",rec[i].time,rec[i].flag);
	}
	int time;
	int j=0;
	int cars = 0;
	for(int i =0;i<k;i++){
		scanf("%d:%d:%d",&h,&m,&s);
		time = h*10000+m*100+s;
		while(rec[j].time<=time){
			if(table[rec[j].plate]==true){
				if(rec[j].flag)cars++;
				else cars--;
			}
			j++;
		}
		printf("%d\n",cars);
	}
	return 0;
}
