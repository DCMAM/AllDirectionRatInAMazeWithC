#include <stdio.h>

#define MAX 4

int total = 0;
char unique[10][MAX][MAX];

void recursive(char maze[][MAX],int i,int j,int n,char final_maze[][MAX]){	
	if(i < 0 || i >= n || j < 0 || j >= n) return;
    if(maze[i][j] == '#' || final_maze[i][j] == '*') return;
    
    if(maze[i][j] == 'e'){
		final_maze[i][j] = '*';
		
		int a;
		for(a=0; a<n; a++){
			int b;
			for(b=0; b<n; b++){
				unique[total][a][b] = final_maze[a][b];
			}
		}
		
		total++;
        final_maze[i][j] = '.';
        
		return;
    }
    
    final_maze[i][j] = '*';
    
	recursive(maze,i-1,j,n,final_maze);
	recursive(maze,i+1,j,n,final_maze);
    recursive(maze,i,j-1,n,final_maze);
    recursive(maze,i,j+1,n,final_maze);

    final_maze[i][j] = '.';
    
    return;
} 

int main() {
	int T, row, col;
	
	printf("Input maze dimension [e.g 3 -> 3*3 maze]: ");
	scanf("%d", &T);
	
	char maze[MAX][MAX];
	
	printf("Build the maze [s: start, e: end, *: road, #:maze]:\n");
	int i,j;
	for(i=0; i<T; i++){
		scanf("%s", &maze[i]); 
		for(j=0; j<T; j++){
			if(maze[i][j] == 's'){
				row = i;
				col = j;
			}
		}
	}
	
	char final_maze[MAX][MAX];
	
	for(i=0; i<MAX; i++){
		for(j=0; j<MAX; j++){
			final_maze[i][j] = '.';
		}
	}
 	
	recursive(maze, row, col, T, final_maze);
    
	printf("\nTotal Unique steps: %d\n", total);
	
    printf("These are the unique steps:\n");
    int x, a, b;
	for(x=0; x<total; x++){
 	   for(a=0; a<T; a++){
			for(b=0; b<T; b++){
				printf("%c", unique[x][a][b]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
    return 0; 
}

