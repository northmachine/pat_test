#include <cstdio>
struct node{
	char name[11];
	char id[11];
	int grade;
}st[2]; 
int n;
int main(){
	scanf("%d",&n);
	char name[11];
	char id[11];
	int grade;
	char g;
	st[0].grade = -1;
	st[1].grade = 101;
	for(int i =0;i<n;i++){
		scanf("%s %c %s %d",name,&g,id,&grade);
		if(g=='M'){
			if(grade<st[1].grade){
				for(int i =0;i<11;i++){
					st[1].name[i] = name[i];
					st[1].id[i] = id[i];
				}
				st[1].grade = grade;
			}
		}
		else{
			if(grade>st[0].grade){
				for(int i =0;i<11;i++){
					st[0].name[i] = name[i];
					st[0].id[i] = id[i];
				}
				st[0].grade = grade;
			}
		}
	}
	if(st[0].grade==-1){
		printf("Absent\n");
	}
	else{
		printf("%s %s\n",st[0].name,st[0].id);
	}	
	if(st[1].grade==101){
		printf("Absent\n");
	}
	else{
		printf("%s %s\n",st[1].name,st[1].id);
	}
	if(st[0].grade!=-1&&st[1].grade!=101){
		printf("%d\n",st[0].grade-st[1].grade);
	}
	else printf("NA");
}
