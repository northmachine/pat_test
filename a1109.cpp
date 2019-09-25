#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n,k;
struct node{
	string name;
	int h;
}st[maxn];
bool cmp(node a,node b){
	if(a.h!=b.h)return a.h>b.h;
	else return a.name<b.name;
}
int main(){
	vector<string> row(maxn);
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		cin>>st[i].name>>st[i].h;
	}
	sort(st,st+n,cmp);
	int first = n/k+n%k;
	int other = n/k;
	int counter = 0;
	for(int i = 0;i<k;i++){
		int rp = i==0?first:other;
		for(int j=1;j<=rp;j++){
			row[j%2!=0?j/2+rp/2+1:rp/2+1-j/2] = st[counter].name;
			counter++; 
		}
		for(int j=1;j<=rp;j++){
			cout<<row[j];
			if(j==rp)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
