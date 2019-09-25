#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
struct node{
	int weight,rank;
}mice[maxn];
int main(){
	int p,g;
	scanf("%d %d",&p,&g);
	for(int i =0;i<p;i++){
		scanf("%d",&mice[i].weight);
	} 
	queue<int> q;
	int x;
	for(int i =0;i<p;i++){
		scanf("%d",&x);
		q.push(x);
	}
	int pt = p;
 	while(q.size()!=1){
 		for(int i=0;i<(pt-1)/g+1;i++){
 			int t = q.front();
 			for(int j=0;j<g&&i*g+j<pt;j++){
 				if(mice[q.front()].weight>mice[t].weight) t = q.front();
 				mice[q.front()].rank = (pt-1)/g+2;
 				q.pop();
			}
			q.push(t);
		 }
		 pt = (pt-1)/g+1;
	}
	mice[q.front()].rank = 1;
	printf("%d",mice[0].rank);
	for(int i =1;i<p;i++)printf(" %d",mice[i].rank);
	return 0;
}
