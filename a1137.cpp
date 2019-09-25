#include <bits/stdc++.h>
using namespace std;
const int maxn = 30010;
struct node{
	string id;
	int gp=-1,gm=-1,gf=-1,g;
}st[maxn];
int stnum;
int p,m,n;
map<string,int> mp;
int getId(string s){
	if(mp.find(s)==mp.end()){
		st[stnum].id = s;
		mp[s] = stnum;
		return stnum++;
	}
	else return mp[s];
}
bool cmp(node a,node b){
//	if(a.gp>=200&&b.gp<200||a.gp<200&&b.gp>=200) return a.gp>b.gp;
	if(a.g!=b.g) return a.g>b.g;
	else return a.id<b.id; 
}
int main(){
	scanf("%d %d %d",&p,&m,&n);
	string name;
	int score;
	for(int i=0;i<p;i++){
		cin>>name>>score;
		int id = getId(name);
		st[id].gp = score;
	}
	for(int i=0;i<m;i++){
		cin>>name>>score;
		int id = getId(name);
		st[id].gm = score;
	}
	for(int i=0;i<n;i++){
		cin>>name>>score;
		int id = getId(name);
		st[id].gf = score;
	}
	for(int i =0;i<stnum;i++){
		if(st[i].gp<200)continue;
		if(st[i].gm>st[i].gf)st[i].g = st[i].gf*0.6+st[i].gm*0.4+0.5;
		else st[i].g = st[i].gf;
	}
	sort(st,st+stnum,cmp);
	int access=0;
	for(;access<stnum;access++){
		if(st[access].g<60||st[access].gp<200) break;
	}
	for(int i=0;i<access;i++){
		cout<<st[i].id<<" "<<st[i].gp<<" "<<st[i].gm<<" "<<st[i].gf<<" "<<st[i].g<<endl;
	}
	return 0;
} 
