#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
using namespace std;
int n,m;
map<string,set<int>> table[6];
void query(int x,string msg){
	if(table[x][msg].size()!=0)
		for(auto i = table[x][msg].begin();i!=table[x][msg].end();i++){
			printf("%07d\n",*i);
		}
	else printf("Not Found\n");
}
int main(){
	cin>>n;
	int id;
	string tmp;
	for(int k =0;k<n;k++){
		cin>>id;
		getchar();
		for(int i =1;i<6;i++){
			if(i!=3){
				getline(cin,tmp);
				table[i][tmp].insert(id);
			}
			else{
				char f = ' ';
				while(f==' '){
					cin>>tmp;
					table[i][tmp].insert(id);
					f = getchar();
				}
			}
		}
	}
	cin>>m;
	for(int  i=0;i<m;i++){
		scanf("%d: ",&id);
		getline(cin,tmp);
		printf("%d: ",id);
		cout<<tmp<<endl;
		query(id,tmp);
	}
	return 0;
} 
