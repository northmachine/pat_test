#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 2010;
const int INF = 1000000000;
map<int,string> intToString;
map<string,int> stringToInt;
map<string,int> Gang;
int G[maxn][maxn]  = {0}, weight[maxn] = {0};
int n,k,numPerson = 0;
bool vis[maxn] = {false};
void DFS(int nowVisit,int &head,int &numMember,int &totalValue){
	numMember++;
	vis[nowVisit] = true;
	if(weight[nowVisit]>weight[head]) head = nowVisit;
	for(int i = 0;i<numPerson;i++)
		if(G[nowVisit][i]>0){
			totalValue+= G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0;
			if(vis[i]==false)
				DFS(i,head,numMember,totalValue);
		}
}
void DFSTrave(){
	for(int  i=0;i<numPerson;i++)
		if(vis[i]==false){u 
			int head=i,numMenber=0,totalValue=0;
			DFS(i,head,numMenber,totalValue);
			if(numMenber>2&&totalValue>k) Gang[intToString[head]] = numMenber;
		}
}
int change(string s){
	if(stringToInt.find(s)!=stringToInt.end()) return stringToInt[s];
	else{
		stringToInt[s] = numPerson;
		intToString[numPerson] = s;
		return numPerson++;
	}
}
int main(){
	int w;
	string str1,str2;
	cin>>n>>k;
	for(int i =0;i<n;i++){
		cin>>str1>>str2>>w;
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	DFSTrave();
	cout<<Gang.size()<<endl;
	for(auto  i=Gang.begin();i!=Gang.end();i++) cout<< i->first<<' '<<i->second<<endl;
	return 0;
}
