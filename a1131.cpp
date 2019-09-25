#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
const int inf = 0x7fffffff;
vector<vector<int>> G(maxn);
unordered_map<int,int> line;
int minCnt = inf,minTrans = inf,start,end1;
bool vis[maxn];
int n,m,k;
vector<int> tmp,best;
int transCnt(vector<int> a){
	int cnt = -1;
	int preLine = 0;
	for(int i =1;i<tmp.size();i++){
		if(line[a[i-1]*10000+a[i]]!=preLine) cnt++;
		preLine = line[a[i-1]*10000+a[i]];
	}
	return cnt;
}
void dfs(int r,int cnt){
	if(r==end1&&(cnt<minCnt||cnt==minCnt&&transCnt(tmp)<minTrans)){
		best = tmp;
		minCnt = cnt;
		minTrans = transCnt(best);
	}
	if(r==end1) return;
	for(int i =0;i<G[r].size();i++){
		if(!vis[G[r][i]]){
			vis[G[r][i]] = true;
			tmp.push_back(G[r][i]);
			dfs(G[r][i],cnt+1);
			vis[G[r][i]] = false;
			tmp.pop_back();
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int pre;
		scanf("%d %d",&m,&pre);
		for(int j=1;j<m;j++){
			int x;
			scanf("%d",&x);
			G[x].push_back(pre);
			G[pre].push_back(x);;
			line[pre*10000+x] = line[x*10000+pre] = i+1;
			pre = x;
		}
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d %d",&start,&end1);
		minCnt = inf,minTrans = inf;
		tmp.push_back(start);
		vis[start] = true;
		dfs(start,0);
		vis[start] = false;
		printf("%d\n",minCnt);
		int preLine =0,preTransfer = start;
		for(int j =1;j<best.size();j++){
			if(preLine!=line[best[j-1]*10000+best[j]]){
				if(preLine!=0)printf("Take Line#%d from %04d to %04d.\n",preLine,preTransfer,best[j-1]);
				preLine = line[best[j-1]*10000+best[j]];
				preTransfer = best[j-1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n",preLine,preTransfer,end1);
	}
	return 0;
}
