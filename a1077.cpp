#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string spoken[110];
int main(){
	int n;
	scanf("%d\n",&n);
	for(int i =0;i<n;i++){
		getline(cin,spoken[i]);
	}
	for(int i=0;i<n;i++){
		reverse(spoken[i].begin(),spoken[i].end());
	}
	int i=-1;
	char c;
	bool f = true;
	while(f){
		i++;
		c = spoken[0][i];
		for(int j=0;j<n;j++){
			if((spoken[j].size()-1)<i || spoken[j][i]!=c){
				f = false;
			}
		}
	}	
	i--;
	if(i==-1)printf("nai");
	else{
		for(int j=i;j>=0;j--) printf("%c",spoken[0][j]);
	}
	return 0;
}
