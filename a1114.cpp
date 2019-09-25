#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int fanum[maxn];
struct node{
	int id,father,mother,knum,kids[6],eatates,area;
}people[maxn];
vector<int> idset;
int father[maxn];
struct node2{
	int id,num,totale,totala;
}family[maxn];
int family_num;
int getFather(int r){
	int x = r;
	while(x!=father[x])x = father[x];
	while(r!=father[r]){
		int tmp = r;
		r = father[r];
		father[tmp] = x;
	}
	return x;
}
void join(int a,int b){
	int fa = getFather(a);
	int fb = getFather(b);
	if(fa>fb){
		father[fa] = fb;
		fanum[fb]+=fanum[fa];
	}
	else if(fa<fb){
		father[fb] = fa;
		fanum[fa]+=fanum[fb];
	}
}
bool cmp(node2 a,node2 b){
	if(a.totala!=b.totala) return a.totala>b.totala;
	else return a.id<b.id;
}
int n;
int main(){
	for(int i=0;i<maxn;i++)father[i] = i;
	fill(fanum,fanum+maxn,1);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int id;
		idset.push_back(id);
		scanf("%d",&id);
		scanf("%d %d %d",&people[id].father,&people[id].mother,&people[id].knum);
		if(people[id].father!=-1)join(id,people[id].father);
		if(people[id].mother!=-1)join(id,people[id].mother);
		for(int j=0;j<people[id].knum;j++){
			scanf("%d",&people[id].kids[j]);
			join(id,people[id].kids[j]);
		}
		scanf("%d %d",&people[id].eatates,&people[id].area);
		people[id].id = id;
	}
	map<int,int> mp;
	set<int> s;
	for(int i=0;i<n;i++){
		int id = getFather(idset[i]);
		if(s.find(id)==s.end()){
			s.insert(id);
			mp[id] = family_num++;
		}
		family[mp[id]].totale+=people[idset[i]].eatates;
		family[mp[id]].totala+=people[idset[i]].area;
	}
	sort(family,family+family_num,cmp);
	printf("%d\n",family_num);
	for(int i =0;i<family_num;i++){
		printf("%04d %d %.3f %.3f\n",family[i].id,fanum[family[i].id],(float)family[i].totale/(float)fanum[family[i].id]+0.0005,(float)family[i].totale/(float)fanum[family[i].id]+0.0005);
	}
	return 0;
}
