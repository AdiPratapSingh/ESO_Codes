#include <stdio.h>
#include <stdbool.h>
int len=0;

bool isEmpty(int *a){
    if(len==0){
        return true;
    }
    else return false;
}
bool Search(int x,int *a){
    for(int i=0;i<len;i++){
        if(a[i]==x){
            return true;
        }
    }
    return false;
}
int Successor(int p,int*a){
    return a[p];
}
int predecessor(int p,int *a){
    return a[p-2];
}
int creatEmptyList(char c){
    int *a = (int*)malloc(1000*sizeof(int));
    return a;
}
void insert(int x,int i,int *a){
    int hold = a[i-1];
    a[i-1]=x;
    for(int j=i;j<len;j++){
        x = a[j];
        a[j]=hold;
        hold=x;
    }
    len++;
    return;
}
void Delete(int i,int *a){
    int j;
    for(j=i;j<len;j++){
        a[j-1]=a[j];
    }
    a[len]=(-1);
    len --;
    return 0;
}
void MakeListEmpty(int *a){
    free(a);
    return 0;
}


int main(){
    return 0;
}