#include <stdio.h>
int arr[26]={0};
int alphabet = 0;

void dfs(char map[105][105], int i, int j, int N, int M)
{
	if (i<0 || j<0 || i>=N || j>=M) {
		return;
	}
	
	if (map[i][j]=='#') {
		return;
	}
	
	map[i][j]='#';
	arr[alphabet]++;
	
	dfs(map, i+1, j, N, M);
	dfs(map, i-1, j, N, M);
	dfs(map, i, j+1, N, M);
	dfs(map, i, j-1, N, M);
}


int main ()
{
	int N, M;
	char map[105][105];
	
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
			if (map[i][j]>='a' && map[i][j]<='z') {
				alphabet = map[i][j]-'a';
				dfs(map, i,j,N,M);
			}
		}
	}
	
	for (int i=0; i<26; i++)
	{
		if (arr[i]>0){
			printf ("%c %d\n", i+'a', arr[i]);
		}
	}
	
	return 0;
}
