#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 10010;
const int maxl = 110;
struct node{
	int s,t;
}line[maxn]; 
int n,k;
int avi_time[maxl];
int wait_time[maxn];
bool cmp(node a,node b){
	return a.s<b.s;
}
int main(){
	scanf("%d %d",&n,&k);
	int h,m,s,t;
	for(int i=0;i<n;i++){
		scanf("%d:%d:%d %d",&h,&m,&s,&t);
		line[i].s = s+m*60+(h-8)*60*60;
		line[i].t = t*60;
	}
	sort(line,line+n,cmp);
	for(int i=0;i<n;i++){
		int l = 0;
		for(int j =0;j<k;j++){
			if(avi_time[j]<avi_time[l]){
				l = j;
			}
		}
		if(line[i].s<=9*60*60){
			wait_time[i] = avi_time[l]-line[i].s>0?avi_time[l]-line[i].s:0;
			avi_time[l] = avi_time[l]-line[i].s>0?avi_time[l]+line[i].t:line[i].s+line[i].t;
		}
		else wait_time[i] = -1;
	}
	int total =0;
	int no = 0;
	for(int i =0;i<n;i++){
		if(wait_time[i]!=-1)
			total+=wait_time[i];
		else no++;
	}
	float average = (float)total/(n-no);
	printf("%.1f",average/60);
	return 0;
}
