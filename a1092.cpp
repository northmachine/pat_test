#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1010;
char all[maxn];
char need[maxn];
int main(){
	scanf("%s\n%s",all,need);
	sort(all,all+strlen(all));
	sort(need,need+strlen(need));
	int a=0,n=0,match=0;
	while(a<strlen(all)&&n<strlen(need)){
		if(all[a]==need[n]){
			a++;
			n++;
			match++;
		}
		else{
			if(all[a]<need[n])
				a++;
			else
				n++;
		}
	}
	if(match == strlen(need)){
		printf("Yes %d",strlen(all)-match);
	}
	else{
		printf("No %d",strlen(need)-match);
	}
	return 0;
}
