// nlog(n) time complexity
#include <stdio.h>

int find_min(int * a,int start,int end){
    int mid = (start + end)/2;
    if((a[mid]<a[mid - 1])&&(a[mid]<a[mid + 1])){
        return mid;
    }
    else if((a[start]<a[start + 1])){
        return start;
    }
    else if((a[end]<a[end - 1])){
        return end;
    }
    else if(a[mid]>a[mid-1]){
        end = mid -1;
        return find_min(a,start,end);
    }
    else if(a[mid]>a[mid+1]){
        start = mid +1;
        return find_min(a,start,end);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int ans_row;
    int ans_col;
    int row_begin = 0;
    int row_end = n-1;
    int mid_row;
    int min_val_index;
    int flag =1;
    min_val_index = find_min(mat[row_end],0,n-1);
    if(mat[row_end][min_val_index]<mat[row_end - 1][min_val_index]){
        ans_row = row_end;
        ans_col = min_val_index;
        flag = 0;
    }
    min_val_index = find_min(mat[row_begin],0,n-1);
    if(mat[row_begin][min_val_index]<mat[row_begin + 1][min_val_index]){
        ans_row = row_begin;
        ans_col = min_val_index;
        flag =0;
    }

    while(flag){
        mid_row = (row_end + row_begin)/2;
        min_val_index = find_min(mat[mid_row],0,n-1);
        if(mat[mid_row][min_val_index]<mat[mid_row - 1][min_val_index]&&mat[mid_row][min_val_index]<mat[mid_row + 1][min_val_index]){
            ans_row = mid_row;
            ans_col = min_val_index;
            break;
        }
        else if(mat[mid_row][min_val_index]>mat[mid_row - 1][min_val_index]){
            row_end = mid_row - 1;
            min_val_index = find_min(mat[row_end],0,n-1);
            if(mat[row_end][min_val_index]<mat[row_end - 1][min_val_index]&&mat[row_end][min_val_index]<mat[row_end + 1][min_val_index]){
                ans_row = row_end;
                ans_col = min_val_index;
                break;
            }
        }
        else if(mat[mid_row][min_val_index]>mat[mid_row + 1][min_val_index]){
            row_begin = mid_row + 1;
            min_val_index = find_min(mat[row_begin],0,n-1);
            if(mat[row_begin][min_val_index]<mat[row_begin - 1][min_val_index]&&mat[row_begin][min_val_index]<mat[row_begin + 1][min_val_index]){
                ans_row = row_begin;
                ans_col = min_val_index;
                break;
            }
        }
    }
    printf("%d",mat[ans_row][ans_col]);
    return 0;
}