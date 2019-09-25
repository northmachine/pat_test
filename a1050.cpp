#include <cstdio>
#include <cstring>
char s1[10010];
char s2[10010];
bool table[1000];
int main(){
	fgets(s1,10010,stdin);
    s1[strlen(s1)-1]='\0';
	fgets(s2,10010,stdin);
    s2[strlen(s2)-1]='\0';
    int ls2 = strlen(s2);
    int ls1 = strlen(s1);
	for(int i=0;i<ls2;i++){
		table[s2[i]]=true;
	}
	for(int i =0;i<ls1;i++){
		if(!table[s1[i]]) printf("%c",s1[i]);
	}
	return 0;
}
