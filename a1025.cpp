#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
struct st{
	char id[14];
	int score;
	int gr=1;
	int r=1;
	int g=0;
};
bool cmp(st s1,st s2){
	if(s1.score!=s2.score)
		return s1.score>s2.score;
	else return strcmp(s1.id,s2.id)<0;
}
int main(){
	int N;
	st s[30010];
	scanf("%d",&N);
	int *room = (int*)malloc(sizeof(int)*N);
	int i=0;
	int start=0;
	for(int r=0;r<N;r++){
		scanf("%d",&room[r]);
		for(int j = 0;j<room[r];j++){
			scanf("%s %d",s[i].id,&s[i].score);
			s[i].g=r+1;
			++i;
		}
		sort(s+start,s+start+room[r],cmp);
		for(int j=1;j<room[r];j++){
			if(s[j+start].score==s[j+start-1].score) s[j+start].gr=s[j+start-1].gr;
			else s[j+start].gr=j+1;
		}
		start+=room[r];
	}
	sort(s+0,s+start,cmp);
	for(int j=1;j<start;j++){
		if(s[j].score==s[j-1].score) s[j].r=s[j-1].r;
		else s[j].r=j+1;
	}
	printf("%d\n",start);
	for(int j=0;j<start;j++)
		printf("%s %d %d %d\n",s[j].id,s[j].r,s[j].g,s[j].gr);
	return 0;
}
