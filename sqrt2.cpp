#include <cstdio>
double f(double x){
	return x*x-2;
} 
int main(){
	double left = 1,right = 2;
	double mid,esp;
	scanf("%lf",&esp);
	while(right-left>esp){
		mid = (right+left)/2;
		if(f(mid)<0){
			left = mid;
		}
		else{
			right = mid;
		}
	}
	printf("%f",mid);
	return 0;
}
