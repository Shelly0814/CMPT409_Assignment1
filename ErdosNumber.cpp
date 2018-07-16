#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

struct node
{
	int x,y,next;
};

struct Name_node
{
	char s[100];
	int len;
};

node map[100010];
Name_node name[10010];
int name_tot,f[10010],first[10010];
int n,m,tot,start_point;

void Insert(int x, int y)
{
	//printf("%d %d %d %d\n",x,y,tot,first[x]);
	map[++tot].x = x;
	map[tot].y = y;
	map[tot].next = first[x];
	first[x] = tot;
}

bool Init()
{
	memset(first,0,sizeof(first));
	tot = 0;
	name_tot = 0;

	char temp;
	n = 0;
	m = 0;
	scanf("%d%d%c",&n,&m,&temp);
	if (n == 0 || m == 0) return false;

	int comma;
	char temp_name[100];
	int temp_length = 0;
	int buffer[100];
	int buffer_length = 0;

	for (int i=1;i<=n;i++)
	{
		//printf("%d\n",i);
		comma = 0;
		buffer_length = 0;
		scanf("%c",&temp);
		while (1)
		{
			//printf("%c",temp);
			if (temp == ',') comma++;
			if (comma == 2  ||  temp == ':')
			{

				// for (int k = 1;k<=temp_length;k++) printf("%c",temp_name[k]);
				// printf("\n");

				bool find = false;
				for (int j=1;j<=name_tot;j++)
				{
					bool flag = true && (name[j].len == temp_length);  //true  =  match
					for (int k=1; (k<=name[j].len)  &&  flag;k++)
						if ( name[j].s[k] !=  temp_name[k] ) flag = false;

					if (flag)
					{
						buffer[++buffer_length] = j;
						find = true;
						break;
					}
				}

				if (!find)
				{
					name[++name_tot].len = temp_length;
					for (int j = 1;j<=temp_length;j++)
						name[name_tot].s[j] = temp_name[j];
					buffer[++buffer_length] = name_tot;
				}


				temp_length = 0;
				comma = 0;
			}
			if (temp == ':') break;

			if (temp != ','  ||  comma == 1)
				temp_name[++temp_length] = temp;
			else if (comma == 0  &&  temp == ',')
				scanf("%c",&temp);
			scanf("%c",&temp);
		}

		//printf("%d\n",i);
		while (1)
		{
			scanf("%c",&temp);
			if (temp == '\n') break;
		}

		// printf("--------------------------------\n");
		// for (int j=1;j<=buffer_length;j++)
		// 	printf("%d ",buffer[j]);
		// printf("---------------------\n");

		for (int j=1;j<=buffer_length;j++)
			for (int k=j+1;k<=buffer_length;k++)
			{
				Insert(buffer[j],buffer[k]);
				Insert(buffer[k],buffer[j]);
			}
		//printf("%d\n",i);
	}
	return true;
	//printf("Init finished\n");
	// for (int i=1;i<=name_tot;i++)
	// {
	// 	printf("%d ",i);
	// 	for (int j=1;j<=name[i].len;j++)
	// 		printf("%c",name[i].s[j]);
	// 	printf("\n");
	// }

	 // for (int i=1;i<=tot;i++)
	 // 	printf("%d %d %d\n",map[i].x,map[i].y,map[i].next);
}

void Find_start()
{
	char temp[10] = "Erdos, P.";


	for (int i=1;i<=name_tot;i++)
	{
		bool flag = name[i].len == 9;

		for (int j=1;(j<=name[i].len)  &&  flag;j++)
			if (name[i].s[j] != temp[j-1]) flag = false;


		if (flag)
		{
			start_point = i;
			return;
		}
	}
}

void Main(int test_case)
{
	//printf("Main\n");
	Find_start();
	//printf("Main\n");
	for (int i=1;i<=name_tot;i++) f[i] = 0x7fffffff;
	int queue[10010];
	bool b[10010];
	memset(b,false,sizeof(b));
	//printf("Main\n");
	int head = 1, tail = 1;
	queue[head] = start_point;
	f[start_point] = 0;
	//printf("Main\n");
	while (head <= tail)
	{

		int x = queue[head];
		int temp = first[x];
		//printf("%d %d %d\n",head,tail,temp);
		while (temp)
		{
			int y = map[temp].y;
			if (f[x] + 1 < f[y])
			{
				f[y] = f[x] + 1;
				if (!b[y])
				{
					queue[++tail] = y;
					b[y] = true;
				}
			}
			temp = map[temp].next;
		}

		b[x] = false;
		head++;
	}
	//printf("Main\n");

	// printf("--------\n");
	// for (int i=1;i<=name_tot;i++)
	// 	printf("%d %d\n",i,f[i]);
//--------------------print answer-------------
	printf("Scenario %d\n",test_case);
	char temp;
	char temp_name[100];
	int temp_length = 0;

	for (int i=1;i<=m;i++)
	{
		temp_length = 0;
		scanf("%c",&temp);

		//printf("#####%c\n",temp);

		while (1)
		{
			if (temp == '\n') break;
			temp_name[++temp_length] = temp;
			scanf("%c",&temp);

		}

		// for (int j=1;j<=temp_length;j++)
		//  	printf("%c",temp_name[j]); cout << endl;

		bool find = false;
		for (int j=1;j<=name_tot;j++)
		{
			bool flag = name[j].len == temp_length;

			for (int k=1;(k<=name[j].len)  &&  flag;k++)
			if (name[j].s[k] != temp_name[k]) flag = false;

			if (flag)
			{
				find = true;
				for (int k=1;k<=temp_length;k++)
					printf("%c",temp_name[k]);
				cout << " ";
				if (f[j] != 0x7fffffff) printf("%d\n",f[j]);
				else printf("infinity\n");
			}


		}

		if (!find)
		{
			for (int j=1;j<=temp_length;j++)
				printf("%c",temp_name[j]);
			printf(" infinity\n");
		}
	}
}


int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);

	int T;
	cin >> T;
	int current = 0;
	while (T--)
	{
		if (Init())
			Main(++current);

	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
