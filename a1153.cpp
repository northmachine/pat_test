#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
struct node{
	string card;
	int score;
}st[maxn],tmp[maxn];
map<string,int> tmp2;
struct node2{
	int sit,num;
}tmp4[1010];
bool cmp2(node2 a,node2 b){
	if(a.num!=b.num) return a.num>b.num;
	else return a.sit<b.sit;
}
int n,m,t;
bool cmp(node a,node b){
	if(a.score!=b.score) return a.score>b.score;
	else return a.card<b.card;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		cin>>st[i].card>>st[i].score;
	}
	sort(st,st+n,cmp);
	for(int i =0;i<m;i++){
		int c;
		string s;
		cin>>c>>s;
		t=0;
		int count1=0,sum=0;
		int t2=0;
		switch(c){
			case 1:
				for(int i =0;i<n;i++){
					if(st[i].card[0]==s[0]){
						tmp[t++] = st[i];
					}
				}
				printf("Case %d: %d %c\n",i+1,c,s[0]);
				if(t!=0)
					for(int i =0;i<t;i++){
						cout<<tmp[i].card<<" "<<tmp[i].score<<endl;
					}
				else printf("NA\n");
				break;
			case 2:
				for(int i =0;i<n;i++){
					string str1;
					for(int j=1;j<4;j++)str1+=st[i].card[j];
					if(str1==s){
						count1++;
						sum+=st[i].score;
					}
				}
				printf("Case %d: %d ",i+1,c);
				cout<<s<<endl;
				if(count1!=0)
					printf("%d %d\n",count1,sum);
				else printf("NA\n");
				break;
			case 3:
				tmp2.clear();
				for(int i =0;i<n;i++){
					string str1;
					for(int j=4;j<10;j++)str1+=st[i].card[j];
					if(str1==s){
						string t3;
						for(int j=1;j<4;j++)t3+=st[i].card[j];
						tmp2[t3]++;
					}
				}
				for(auto iter =tmp2.begin();iter!=tmp2.end();iter++ ){
					tmp4[t2].num = iter->second;
					tmp4[t2].sit = stoi(iter->first);
					t2++;
				}
				printf("Case %d: %d ",i+1,c);
				cout<<s<<endl;
				if(t2!=0){
					sort(tmp4,tmp4+t2,cmp2);
					for(int j =0;j<t2;j++){
						printf("%d %d\n",tmp4[j].sit,tmp4[j].num);
					}
				}
				else printf("NA\n");
				break;
			default:
				break;
		}
	}
	return 0;
}
