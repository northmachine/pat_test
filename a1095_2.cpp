#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;
const int maxn = 10010;
struct node{
	string plate;
	int time;
	bool flag;
}rec[maxn],valid[maxn];
int validnum;
int cars;
bool cmp(node a,node b){
	if(a.plate!=b.plate) return a.plate<b.plate;
	else return a.time<b.time;
}
bool cmp2(node a,node b){
	return a.time<b.time;
}
map<string,int> timetable;
int maxtime;
set<string> max_time_car;
int n,k;
int main(){
	scanf("%d %d",&n,&k);
	int h,m,s;
	char status[4];
	for(int i =0;i<n;i++){
		cin>>rec[i].plate;
		scanf("%d:%d:%d",&h,&m,&s);
		rec[i].time = h*3600+m*60+s;
		scanf("%s",status);
		if(strcmp(status,"in")==0)rec[i].flag = true;
	}
	sort(rec,rec+n,cmp);
	for(int i =1;i<n;i++){
		if(rec[i-1].plate==rec[i].plate&&rec[i-1].flag==true&&rec[i].flag==false){
			valid[validnum] = rec[i-1];
			valid[validnum+1] = rec[i];
			timetable[rec[i].plate]+=(rec[i].time-rec[i-1].time);
			if(timetable[rec[i].plate]>maxtime){
				maxtime = timetable[rec[i].plate];
				max_time_car.clear();
				max_time_car.insert(rec[i].plate);
			}
			else if(timetable[rec[i].plate]==maxtime){
				max_time_car.insert(rec[i].plate);
			}
			validnum+=2;
		}
	}
	sort(valid,valid+validnum,cmp2);
	int t;
	int j = 0;
	for(int i =0;i<k;i++){
		scanf("%d:%d:%d",&h,&m,&s);
		t = h*3600+m*60+s;
		while(t>=valid[j].time&&j<validnum){
			if(valid[j].flag==true) cars++;
			else cars--;
			j++;
		}
		printf("%d\n",cars);
	}
	for(auto iter = max_time_car.begin();iter!=max_time_car.end();iter++){
		cout<<*iter<<" ";
	}
	h = maxtime/3600;
	m = (maxtime%3600)/60;
	s = maxtime%60;
	printf("%02d:%02d:%02d",h,m,s);
	return 0;
}
