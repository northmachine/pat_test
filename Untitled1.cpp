#include <stdio.h>

//N�����鳤�ȣ�num�Ǵ���������飬����ȫ��������Ϊ���Կ��ܴ������
int N, num[16777216];

int solve(int left, int right)
{
    //���г���Ϊ1ʱ
    if(left == right)
        return num[left];
    
    //����Ϊ������ģ��С������
    int mid = left + right >> 1;
    int lans = solve(left, mid);
    int rans = solve(mid + 1, right);
    
    //���ָ������
    int sum = 0, lmax = num[mid], rmax = num[mid + 1];
    for(int i = mid; i >= left; i--) {
        sum += num[i];
        if(sum > lmax) lmax = sum;
    }
    sum = 0;
    for(int i = mid + 1; i <= right; i++) {
        sum += num[i];
        if(sum > rmax) rmax = sum;
    }

    //����������������ֵ
    int ans = lmax + rmax;
    if(lans > ans) ans = lans;
    if(rans > ans) ans = rans;

    return ans;
}

int main()
{
    //��������
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &num[i]);

    printf("%d\n", solve(1, N));

    return 0;
}
