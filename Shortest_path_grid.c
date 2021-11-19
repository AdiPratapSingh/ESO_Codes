#include <stdio.h>

int main(){
    //shortest path in grid
    int n;
    scanf("%d",&n);
    int d_row,d_col;
    scanf("%d",&d_row);
    scanf("%d",&d_col);
    int a[n][n][2];
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j][0]);        // travellable or not 
            a[i][j][1] = 0;                 // travelled or not
        }
    }
    int queue[100][3];
    queue[0][0] = 0;                        // distance
    queue[0][1] = 0;                        // row number
    queue[0][2] = 0;                        // column number
    a[0][0][1] = 1;
    int begin = 0;
    int end=0;
    int i=0,j=0;
    int dist = 0;
    while(a[d_row][d_col][1]==0){
         // if( travellable or not + travelled or not)
        if(((queue[begin][1]+1)<n)&&(a[(queue[begin][1]+1)][(queue[begin][2])][0])&&!(a[(queue[begin][1]+1)][(queue[begin][2])][1])){   // row + 1 ; col
            end++;
            queue[end][0] = queue[begin][0] + 1;
            queue[end][1] = queue[begin][1] + 1;
            queue[end][2] = queue[begin][2];
            a[(queue[end][1])][(queue[end][2])][1] = 1;
        }
        if(((queue[begin][2] + 1)<n)&&(a[(queue[begin][1])][(queue[begin][2] + 1)][0])&&!(a[(queue[begin][1])][(queue[begin][2] + 1)][1])){   // row  ; col + 1
            end++;
            queue[end][0] = queue[begin][0] + 1;
            queue[end][1] = queue[begin][1];
            queue[end][2] = queue[begin][2] + 1;
            a[(queue[end][1])][(queue[end][2])][1] = 1;
        }
        if(((queue[begin][1]-1)>=0)&&(a[(queue[begin][1]-1)][(queue[begin][2])][0])&&!(a[(queue[begin][1]-1)][(queue[begin][2])][1])){   // row - 1 ; col
            end++;
            queue[end][0] = queue[begin][0] + 1;
            queue[end][1] = queue[begin][1] - 1;
            queue[end][2] = queue[begin][2];
            (a[(queue[end][1])][(queue[end][2])][1]) = 1;
        }
        if(((queue[begin][2] - 1)>=0)&&(a[(queue[begin][1])][(queue[begin][2] - 1)][0])&&!(a[(queue[begin][1])][(queue[begin][2] - 1)][1])){   // row  ; col - 1
            end++;
            queue[end][0] = queue[begin][0] + 1;
            queue[end][1] = queue[begin][1];
            queue[end][2] = queue[begin][2] - 1;
            (a[(queue[end][1])][(queue[begin][2])][1]) = 1;
        }
        begin++;
    }
    printf("%d",queue[end][0]);
}