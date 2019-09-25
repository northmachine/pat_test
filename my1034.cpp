#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#define maxn 2010
using namespace std;
map<string,int> strToInt;
map<int,string> intToStr;
map<string,int> GangMen;
int G[maxn][maxn];
int weight[maxn];
int n,k,person;
bool vis[maxn];
void DFS(int s,int &total,int &head,int &menbernum){
	menbernum++;
//	cout<<menbernum<<endl;
	vis[s] = true;
	if(weight[s]>weight[head]) head = s;
	for(int  i=0;i<person;i++){
		if(G[s][i]>0){
			total+=G[s][i];
//			cout<<total<<endl;
			G[s][i]=0;
			if(vis[i]==false)
				DFS(i,total,head,menbernum); 
		}
	} 
}
void TraveDFS(){
	for(int  i=0;i<person;i++){
		if(vis[i]==false){
			int total=0,head=i,menbernum=0;
			DFS(i,total,head,menbernum);
			if(total>k&&menbernum>2)
				GangMen[intToStr[head]] = menbernum;
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int  i=0;i<n;i++){
		string name1,name2;
		int time;
		cin>>name1>>name2>>time;
		int i1,i2;
		if(strToInt.find(name1)!=strToInt.end()) i1 = strToInt[name1];
		else {
			i1 = person;
			strToInt[name1] = person++;
			intToStr[i1] = name1;
		}
		if(strToInt.find(name2)!=strToInt.end()) i2 = strToInt[name2];
		else {
			i2 = person;
			strToInt[name2] = person++;
			intToStr[i2] = name2;
		}
		G[i1][i2] += time;
		weight[i1]+=time;
		weight[i2]+=time;
	}
	TraveDFS();
	for(auto i = GangMen.begin();i!=GangMen.end();i++)
		cout<<i->first<<' '<<i->second<<endl;
	return 0;
}
