#include <bits/stdc++.h>
using namespace std;
int book[50010];
struct node{
	int value,cnt;
	bool operator < (const node &a)const{
		return (cnt!=a.cnt)?cnt>a.cnt:value<a.value;
	}
};
int main(){
	int n,k,num;
	scanf("%d %d",&n,&k);
	set<node> s;
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		if(i!=0){
			printf("%d:",num);
			int tmpCnt=0;
			for(auto iter = s.begin();tmpCnt<k&&iter!=s.end();iter++){
				printf(" %d",iter->value);
				tmpCnt++;
			}
			printf("\n");
		}
		auto iter = s.find(node{num,book[num]});
		if(iter!=s.end())s.erase(iter);
		book[num]++;
		s.insert(node{num,book[num]});
	}
	return 0;
}
