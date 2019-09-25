#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
map<string,int> sc;
int n,scn;
struct node{
	string name;
	int stn;
	double score;
}sclist[maxn]; 
bool cmp(node a,node b){
	if((int)a.score!=(int)b.score)return a.score>b.score;
	else if(a.stn!=b.stn) return a.stn<b.stn;
	else return a.name<b.name;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		string id,school;
		double score;
		cin>>id>>score>>school;
		for(int j=0;j<school.length();j++)school[j]|=32;
		if(id[0]=='T')score*=1.5;
		else if(id[0]=='B')score/=1.5;
		if(sc.find(school)==sc.end()){
			sc[school] = scn;
			sclist[scn] = {school,1,score};
			scn++;
		}
		else{
			sclist[sc[school]].stn++;
			sclist[sc[school]].score+=score;
		}
	}
	sort(sclist,sclist+scn,cmp);
	cout<<scn<<endl;
	int r = 1;
	cout<<r<<" "<<sclist[0].name<<" "<<(int)sclist[0].score<<" "<<sclist[0].stn<<endl;
	for(int  i=1;i<scn;i++){
		if((int)sclist[i].score!=(int)sclist[i-1].score)r=i+1;
		cout<<r<<" "<<sclist[i].name<<" "<<(int)sclist[i].score<<" "<<sclist[i].stn<<endl;
	}
	return 0;
}
