#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

struct edge
{
	int x;
	int y;
	int next;
};

int n, m, head, tail, total;
int first[50100], queue[50100];
edge map[10000];
int b[50100];


void Main(int start, int end)
{
	memset(b,0,sizeof(b));
	b[start] = 1;
	b[end] = -1;
	head = 0;
	tail = 1;
	queue[head] = start;
	queue[head+1] = end;
	while (head<=tail)
	{
		int x = queue[head];
		int state = b[x];
		int e = first[x];
		while (e)
		{
			int y = map[e].y;
			if (b[y] == state)
			{
				e = map[e].next;
				continue;
			}

			else if (!b[y])
			{
				b[y] = state;
				queue[++tail] = y;
			}

			else
			{
				if (state == 1)
					printf("The fleas jump forever between %d and %d.\n", min(x,y),max(x,y));
				else
					printf("The fleas meet at %d.\n",y);
				return;
			}
			e = map[e].next;
		}
		head++;
	}

}

void add_edge(int x, int y)
{
	total++;
	map[total].x = x;
	map[total].y = y;
	map[total].next = first[x];
	first[x] = total;
}

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);

	scanf("%d",&n);
	//printf("%d\n",n);
	while (n!=0)
	{
		memset(first,0,sizeof(first));
		total = 0;
		for (int i=0;i<n-1;i++)
		{
			int x,y;
			scanf("%d%d",&x, &y);
			//printf("%d %d\n", x, y);
			add_edge(x, y);
			add_edge(y, x);
		}

		//printf("%d\n",total);

		//for (int i=1;i<=total;i++)
		//	printf("%d %d\n",map[i].x,map[i].y);

		scanf("%d",&m);
		for (int i=0;i<m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if (x==y)
			{
				printf("The fleas meet at %d.\n",y);
				continue;
			}
			Main(x,y);
		}
		scanf("%d", &n);
	}

	fclose(stdin);fclose(stdout);

	return 0;
}
