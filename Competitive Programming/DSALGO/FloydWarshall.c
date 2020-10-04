#include<stdio.h>
#define n 5
#define inf 99999

void printsolution(int dist[][n]);

int main()
{
	int graph[n][n]={{0,3,8,inf,-4},
					{inf,0,inf,1,7},
					{inf,4,0,inf,inf},
					{2,inf,-5,0,inf},
					{inf,inf,inf,6,0}};
	floydwarshall(graph);
	return 0;
}
void floydwarshall(int graph[][n])
{
	int dist[n][n],i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			dist[i][j]=graph[i][j];
		}
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	printsolution(dist);
}
void printsolution(int dist[][n])
{
	int i,j;
	printf("the following matrix shows the shortest distance : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(dist[i][j]==inf)
			{
				printf("%s","inf");
			}
			else
			{
				printf("%d  ",dist[i][j]);
			}
		}
		printf("\n");
	}
}
