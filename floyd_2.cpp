#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
const int inf = 0x7fffffff;
int G[maxn][maxn];
void floyd(){
	for(int k =0;k<n;k++){
		for(int i =0;i<n;i++){
			for(int j=0;j<n;j++){
				if(G[i][k]!=inf&&G[k][j]!=inf&&G[i][k]+G[k][j]<G[i][j]){
					G[i][j]=G[i][k]+G[k][j];
				}
			}
		}
	}
}

