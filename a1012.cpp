#include <cstdio>
#include <cstdlib>
int getIndex(int *ary, bool *t, int n) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (ary[i] > ary[k] && t[i])
			k = i;
	}
	return k;
}
int main() {
	int N, m;
	scanf("%d%d", &N, &m);
	int *id = (int*)malloc(N * sizeof(int));
	int *A = (int*)malloc(N * sizeof(int));
	int *C = (int*)malloc(N * sizeof(int));
	int *M = (int*)malloc(N * sizeof(int));
	int *E = (int*)malloc(N * sizeof(int));
	int *rA = (int*)malloc(101 * sizeof(int));
	int *rC = (int*)malloc(101 * sizeof(int));
	int *rM = (int*)malloc(101 * sizeof(int));
	int *rE = (int*)malloc(101 * sizeof(int));
	for(int i =0;i<101;i++)
		rA[i]=rC[i]=rM[i]=rE[i]=1;
	for (int i = 0; i < N; i++){
		scanf("%d %d %d %d", &id[i], &C[i], &M[i], &E[i]);
		A[i] = (C[i] + M[i] + E[i]) / 3;
		for(int j = 0;j<A[i];j++)rA[j]++;
		for(int j = 0;j<C[i];j++)rC[j]++;
		for(int j = 0;j<M[i];j++)rM[j]++;
		for(int j = 0;j<E[i];j++)rE[j]++;
	}
	int *search = (int*)malloc(m * sizeof(int));
	for (int j = 0; j < m; j++)
		scanf("%d", &search[j]);
	for(int i = 0;i<m;i++){
		int j =0;
		while(id[j]!=search[i]&&j!=N) j++;
		if(j==N) printf("N/A");
		else{
		int rank = rA[A[j]];
		char sub = 'A';
			if(rC[C[j]]<rank) {rank = rC[C[j]];sub='C';}
			if(rM[M[j]]<rank) {rank = rM[M[j]];sub='M';}
			if(rE[E[j]]<rank) {rank = rE[E[j]];sub='E';}
			printf("%d %c",rank,sub);
		}
		if(i!=m)printf("\n");
	}
	return 0;
}
