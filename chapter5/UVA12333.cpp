#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
int trie[4586400][10],cnt = 1,pos[4586400]; // pos�����������ڵ��β�ķ�֧�ǵڼ���쳲������� cnt�ǽڵ���� 
int a[2][52] = {{1},{1}}; //a[0]�������Ϊż����쳲���������ǰ50λ a[1]�������Ϊ������쳲���������ǰ50λ 

void trie_insert(int *s,int wz)
{
    int p = 0;
    int i = 50;
    while(!s[i]) i--;
    for(; i >= 0 ; i--){
        int x = s[i];
        if(trie[p][x] == 0) {
            trie[p][x] = cnt++;
        }
        p = trie[p][x];
        if(pos[p] == INF) pos[p] = wz;
    }
}

int Find(char *a)
{
    int p = 0;
    for(int i = 0 ; a[i] ;i++){
        if(trie[p][a[i] - '0'])
            p = trie[p][a[i] - '0'];
        else return -1;
    }
    return pos[p];
}

void del(int *a)//����һλ��������λ 
{
    for(int i = 0 ; i <= 50 ; i++) a[i] = a[i+1];
}

int main()
{
    //freopen("E://text//text.txt","w",stdout);
    memset(pos,INF,sizeof pos);
    trie_insert(a[0],0);
    for(int i=2;i<100000;i++)//ע��ԭ��涨��ȡ100000
    {
        if(a[1][50]||a[0][50])del(a[1]),del(a[0]);//��λ
        for(int j=0;j<50&&a[j];j++)//�߾��ӷ�,����ѹ��
        {
            a[i&1][j]+=a[(i&1)^1][j];//f(i)+=f(i-1) i��i-1һ����һ������һ��ż�� 
            a[i&1][j+1]+=a[i&1][j]>=10;
            a[i&1][j]%=10;
        }
        trie_insert(a[i&1],i);
    }
    int t;
    scanf("%d",&t);
    int x;
    char s[50];
    for(int i = 0 ; i < t ; i++){
        scanf("%s",s);
        int ans = Find(s);
        printf("Case #%d: %d\n",i+1,ans);
    }
    return 0;
}

