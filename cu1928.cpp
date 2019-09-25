#include <cstdio>
bool isLeap(int y){
	return (y%4==0 && y%100!=0)||y%400==0; 
}
int main(){
	int monthday[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
	int d1,d2;
	int y1,m1,r1,y2,m2,r2;
	while(scanf("%d",&d1)!=EOF&&scanf("%d",&d2)!=EOF){
		if(d1>d2){
			int temp = d1;
			d1=d2;
			d2=temp;
		}
		int day = 1;
		y1=d1/10000;
		y2=d2/10000;
		m1=(d1%10000)/100;
		m2=(d2%10000)/100;
		r1=d1%100;
		r2=d2%100;
		while(y1+1<y2){
			y1++;
			if(isLeap(y1)) day+=366;
			else day+=365;
		}
		while(y1<y2||m1<m2||r1<r2){
			day++;
			r1++;
			if(r1==monthday[isLeap(y1)][m1]+1){
				m1++;
				r1=1;
			}
			if(m1==13){
				y1++;
				m1=1;
			}
		}
		printf("%d\n",day);
	}
	return 0;
}
