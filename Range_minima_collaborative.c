#include <stdio.h>

//find min val in array
int find_min(int *a, int start,int end){
    int min = 10000000;
    for(int i = 0;i<=(end - start);i++){
        if(min>a[start + i]){
            min = a[start + i];
        }
    }
    return min;
}

int min(int a , int b){
    return a<b?a:b;
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int log_gif[n+1];
    int pow[n+1];
    for(int i=2,j=1,k=0;i<=n;i++){
        if(j<i){
            j*=2;           // j is the value of 2^k > i 
            k++;
        }
        log_gif[i - 1] = k - 1;     // it stores log value aka k
        pow[i-1]=j/2;
    }
    // for (int i=1;i<n;i++){
    //     printf("%d ",log_gif[i]);
    // }
    // printf("\n");
    // for(int i=1;i<n;i++){
    //     printf("%d ",pow[i]);
    // }
    // int arr[n][log_gif[n-1]];
    // for(int i=0;i<n-1;i++){
    //     int len = log_gif[n - i -1];
    //     for(int j=0;j<=len;j++){
    //         arr[i][j]=find_min(a,i,i + (1<<j));
    //     }
    // }
    int arr[n][log_gif[n-1]];
    for(int i=0;i<n-1;i++){
        int len = log_gif[n - i -1];
        int k=i;
        int hold = 10000000;
        for(int j=0;j<=len;j++){
            hold=find_min(a,k,i + (1<<j));
            if(j!=0)
            arr[i][j] = min(hold,arr[i][j-1]);
            else arr[i][j]=hold;
            k= i + (1<<j);
        }
    }
    int query;
    int start;
    int end;
    int diff;
    int min = 10000000;
    scanf("%d",&query);
    while(query--){
        scanf("%d%d",&start,&end);
        while(1){
            diff = end - start;
            if(min>arr[start][log_gif[diff]]){
                min = arr[start][log_gif[diff]];
            }
            start = start + pow[diff];
            if(start==end) break;
        }
        printf("%d\n",min);
        min = 10000000;
    }
}