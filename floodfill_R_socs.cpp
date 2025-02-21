#include <stdio.h>
int count = 0;

void dfs(char map[105][105], int i, int j, int N, int M)
{
	if (i<0 || j<0 ||i>=N || j>=M) {
		return;
	}
	
	if (map[i][j]=='#') {
		return;
	}
	
	if (map[i][j]=='.') {
		count++;
	}
	
	map[i][j]='#';
	dfs (map, i+1, j, N, M);
	dfs (map, i-1, j, N, M);
	dfs (map, i, j+1, N, M);
	dfs (map, i, j-1, N, M);
}

int main ()
{
	int T;
	int N, M;
	char map[105][105];
	
	scanf ("%d", &T);
	getchar();
	
	for (int tc=0; tc<T; tc++)
	{
		count=0;
		
		scanf ("%d %d", &N, &M);
		getchar();
		
		for (int i=0; i<N; i++)
		{
			for (int j=0; j<M; j++)
			{
				scanf ("%c", &map[i][j]);
			}
			getchar();
		}
		
		for (int i=0; i<N; i++)
		{
			for (int j=0; j<M; j++)
			{
				if (map[i][j]=='S') {
					dfs(map, i, j, N, M);
				}
			}
		}
		
		printf ("Case #%d: %d\n", tc+1, count);
		
		count=0;
	}
	
	return 0;
}
