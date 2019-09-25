#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
const int maxn = 1010;
const int maxw = 30;
const int INF = 0x3fffffff;
int n,m,k,q;
struct node{
	int index;
	int time;
	int stime;
	node(int _index=0,int _time=0,int _stime=0):index(_index),time(_time),stime(_stime){}
};
bool ask[maxn];
node result[maxn];
int resn =0;
queue<node> Q[maxw];
queue<node> W;
int t=0;
void serve(){
	int min = INF;
	int x=0;
	for(int  i=0;i<n;i++){
		if(!Q[i].empty()){
			if(Q[i].front().time<min){
				x = i;
				min = Q[i].front().time;
			}
		}
	} 
	for(int i =0;i<n;i++){
		if(!Q[i].empty()){
			Q[i].front().time-=min;
			if(Q[i].front().time==0){
				if(ask[Q[i].front().index]==true){
				//	if(t+min<=540){
					for(int j =0;j<q;j++){
						if(result[j].index==Q[i].front().index){
							result[j].time = t+min;
							result[j].stime =t;
							break;
						}
					}
					//	result[resn++] = node(Q[i].front().index,t+min);
					//	printf("%02d:%02d\n",8+(t+min)/60,(t+min)%60);
				//	}
				//	else printf("Sorry\n");
				}
				Q[i].pop();
				if(!W.empty()){
					Q[i].push(W.front());
					W.pop();
				}
			}
		}
	}
	if(min == INF) ask[0] = true;
	t+=min;
	//printf("a\n");
}
int main(){
	scanf("%d %d %d %d",&n,&m,&k,&q);
	for(int i =1;i<=k;i++){
		int time;
		scanf("%d",&time);
		W.push(node(i,time));
	}
	for(int i=0;i<q;i++){
		int x;
		scanf("%d",&x);
		ask[x] = true;
		result[i].index = x;
	}
	for(int  i=0;i<n*m;i++){
		if(W.empty()) break;
		Q[i%m].push(W.front());
		W.pop();
	}
	while(!ask[0]) serve();
	for(int i =0;i<q;i++){
		int stime = result[i].stime;
		int t = result[i].time;
		if(stime<540){
			printf("%02d:%02d",8+t/60,t%60);
		}
		else printf("Sorry");
		if(i!=q-1) printf("\n");
	}
	return 0;
} 
