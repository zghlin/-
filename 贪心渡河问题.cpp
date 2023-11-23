/*
### ̰�Ķɺ�����
Description

A group of N people wishes to go across a river with only one boat, which can at most carry two persons. Therefore some sort of shuttle arrangement must be arranged in order to row the boat back and forth so that all people may cross. Each person has a different rowing speed; the speed of a couple is determined by the speed of the slower one. Your job is to determine a strategy that minimizes the time for these people to get across.
Input

The first line of the input contains a single integer T (1 <= T <= 20), the number of test cases. Then T cases follow. The first line of each case contains N, and the second line contains N integers giving the time for each people to cross the river. Each case is preceded by a blank line. There won't be more than 1000 people and nobody takes more than 100 seconds to cross.
Output

For each test case, print a line containing the total number of seconds required for all the N people to cross the river.
Sample Input

1<br>
4<br>
1 2 5 10
Sample Output

17
$������һȺ�ˣ�����һ���ӱߣ���Ҫ���ӣ�����ֻ��һ����һ�����ֻ���������ˣ��������滹��Ҫһ���˰Ѵ��������������������������ٶȻ�����������һ����������������η���������ʹ��ʱ����̡�\\
���룺\\
����t�����ݣ�ÿ�����ݵ�һ������n���ڶ�������n��������ʾÿ���˹��ӵ�ʱ�䡣\\
�����\\
���t�����ݣ�ÿ��1��������ÿ��������ٵ�ʱ��\\
�������룺4\\$
1 2 5 10

�������:

17

����1����������DFS
��$C_4^2C_2^1C_3^2C_2^1=6*2*3*2=72������б���һ����ʱ��̵ķ���$<br>
����2:̰��˼ά:

���1:ÿ�������Ĵ������Ĺ�ȥ�������ڻ�����ѭ��������

��n=1ʱ��t=a[1]
��n=2ʱ��t=a[2]
��n=3ʱ��t=a[3]+a[1]+a[2]
����������Ϊһ�֣���t=2a[1]+a[k]+a[k-1]

���2�������������ȶɺӣ����ķ��أ��������������ڶɺӣ��ٶȴο�ķ��ء�t=a[1]+2a[2]+a[k]

*/ 

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A[1005];
int n,time,ans;
void f(int m,int A[])
{
	int left=m;
	while(left>0){
		if(left==1){
			ans+=A[1];
			break;
		}
		else if(left==2){
			ans+=A[2];
			break;
		}
		else if(left==3)
		{
			ans+=A[1]+A[2]+A[3];
			break;
		}
		else{
			int s1=A[2]+A[1]+A[left]+A[2];
			int s2=A[left]+A[left-1]+2*A[1];
			ans+=min(s1,s2);
			left-=2;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&A[i]);
			
		}
		sort(A+1,A+n+1);
		f(n,A);
		printf("%d",ans);
		memset(A,0,sizeof(A));
		ans=0;
	}
	return 0;
}
