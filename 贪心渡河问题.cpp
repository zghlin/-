/*
### 贪心渡河问题
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
$现在有一群人，到了一条河边，想要过河，但船只有一条，一次最多只能载两个人，开到对面还需要一个人把船开回来，而且若多人坐船，速度还是由最慢的一个决定，现在求如何分配坐船，使总时间最短。\\
输入：\\
输入t组数据，每组数据第一行输入n，第二行输入n个数，表示每个人过河的时间。\\
输出：\\
输出t行数据，每行1个数，求每组过河最少的时间\\
样例输入：4\\$
1 2 5 10

样例输出:

17

方法1：暴力搜索DFS
在$C_4^2C_2^1C_3^2C_2^1=6*2*3*2=72种情况中遍历一种用时最短的方法$<br>
方法2:贪心思维:

情况1:每次让最快的带最慢的过去，最快的在回来，循环往复。

当n=1时，t=a[1]
当n=2时，t=a[2]
当n=3时，t=a[3]+a[1]+a[2]
往返各两次为一轮，则t=2a[1]+a[k]+a[k-1]

情况2：最快的两个人先渡河，最快的返回，最慢的两个人在渡河，速度次快的返回。t=a[1]+2a[2]+a[k]

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
