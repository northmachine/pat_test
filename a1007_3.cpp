#include <stdio.h>

//N�����鳤�ȣ�num�Ǵ���������飬����ȫ��������Ϊ���Կ��ܴ������
int N, num[134217728];

int main()
{
    //��������
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &num[i]);
    
    //��������ǰ׺�ͣ����ڴ˹����еõ���
    num[0] = 0;
    int ans = num[1], lmin = 0;
    for(int i = 1; i <= N; i++) {
        num[i] += num[i - 1];
        if(num[i] - lmin > ans)
            ans = num[i] - lmin;
        if(num[i] < lmin)
            lmin = num[i];
    }

    printf("%d\n", ans);

    return 0;
}
