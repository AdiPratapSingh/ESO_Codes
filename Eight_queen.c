#include <stdio.h>
// Abhi incomplete hai
struct location{
    int row;
    int col;
};
int board[6][6];

void place(int row,int col){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i==row||j==col||(i+j)==(row+col)){
                board[i][j] += 1;
            }
        }
    }
}
void lift(int row,int col){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if((i==row||j==col||(i+j)==(row+col))&&board[i][j]>0){
                board[i][j] -= 1;
            }
        }
    }
}

int main(){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            board[i][j]=0;
        }
    }
    int left = 8;
    int skips = 0;
    struct location position[left];
    while(left--){
        int i=0;int j=0;int flag = 0;
        for(i=0;i<8&&!flag;i++){
            for(j=0;j<8&&!flag;j++){
                if(board[i][j]==0){
                    if(!skips){
                        place(i,j);
                        position[8-left].row = i;
                        position[8-left].col = j;
                        flag = 1;
                    }
                    else skips --;
                }
            }
        }
        if(!flag){
            lift(position[8-left-1].row,position[8-left-1].col);
            left++;
            skips++;
        }
    }
    return 0;
}