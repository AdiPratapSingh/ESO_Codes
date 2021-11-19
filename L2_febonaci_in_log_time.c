#include <stdio.h>
struct pair{
    int first;
    int second;
};

struct mat {
    struct pair v1;
    struct pair v2;
};

struct mat A = {{1,1},{1,0}};

void multiply_2by2_mat(struct mat*first, struct mat*second,struct mat*ans){
    int a,b,c,d;
    a = first->v1.first*second->v1.first + first->v1.second * second->v2.first;
    b = first->v1.first*second->v1.second + first->v1.second * second->v2.second;
    c = first->v2.first*second->v1.first + first->v2.second * second->v2.first;
    d = first->v2.first*second->v1.second + first->v2.second * second->v2.second;
    ans->v1.first =a;
    ans->v1.second=b;
    ans->v2.first=c ;
    ans->v2.second=d;
    return;
}

struct mat find_for(int n){
    struct mat ans;
    struct mat first;

    if(n==1){
        return A;
    }
    else if(n%2){
        first = find_for((n-1)/2);
        multiply_2by2_mat(&first,&first,&ans);
        multiply_2by2_mat(&A,&ans,&ans);
    }
    else{
        first = find_for(n/2);
        multiply_2by2_mat(&first,&first,&ans);
    }
    return ans;
}

int fib(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    return find_for(n-1).v1.first; 
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",fib(n));
    return 0;
}