#include <stdio.h>
#include <time.h>

long long int fib(int n){   //fabonacii through recursion
    if(n==1||n==2){
        return 1;
    }
    else{
        return fib(n-1) +fib(n-2);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    // time_t start, end;
    time_t start = time(NULL);
    long long int a=1,b=1,h;
    
    printf("%lld\n",fib(n));
    time_t end = time(NULL);
    int diff = (int)difftime(end,start);
    int seconds = diff % 60;
    int minutes = ((diff - seconds)/60) % 60;
    int hours = ((diff -seconds - 60*minutes)/3600);
    printf("Time taken is %d:%d:%d\n",hours,minutes,seconds);
    // printf("%f\n",difftime(end,start));
    return 0;
}