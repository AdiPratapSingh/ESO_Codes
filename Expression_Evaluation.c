#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct num{
    int data;
    struct num*next;
    struct num*prev;
};
struct sign{
    int priority;
    char data;
    struct sign*next;
    struct sign*prev;
};
int set_priority(char c){
    if(c=='$'||c=='#'||c=='('){
        return 0;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='^'){
        return 3;
    }
}
int outside_stack_priority(char c){
    if(c=='$'||c=='#'||c==')'){
        return 0;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='^'){
        return 4;
    }
    else if(c=='('){
        return 5;
    }
}
void Push_num(int n,struct num**numbers){
    struct num*hold=(struct num*)malloc(sizeof(struct num));
    hold->data = n;
    hold->next = NULL;
    if((*numbers)!= NULL){
        (*numbers)->next = hold;
        hold->prev = *numbers;
        *numbers = hold;
    }
    else{
        *numbers=hold;
        (*numbers)->prev = NULL;
    }
    return;
}
void Push_sign(char c,struct sign**operators){
    struct sign*hold=(struct sign*)malloc(sizeof(struct sign));
    (*operators)->next=hold;
    hold->prev=*operators;
    *operators = hold;
    (*operators)->data = c;
    (*operators)->priority = set_priority(c);
    hold->next=NULL;
    return;
}
void pop_num(struct num**numbers){
    *numbers=(*numbers)->prev;
    free((*numbers)->next);
    (*numbers)->next = NULL;
    return;
}
void pop_sign(struct sign**operators){
    (*operators)=(*operators)->prev;
    free((*operators)->next);
    (*operators)->next = NULL;
    return;
}
void execute(struct num**numbers,struct sign**operators,char*s){
    char c = (*operators)->data;
    int second = (*numbers)->data;
    pop_num(numbers);
    if(!(c=='('&& *s==')')){
        int first = (*numbers)->data;
        if(c=='+'){
            (*numbers)->data = first + second;
        }
        else if(c=='-'){
            (*numbers)->data = first - second;
        }
        else if(c=='/'){
            (*numbers)->data = first / second;
        }
        else if(c=='*'){
            (*numbers)->data = first * second;
        }
        else if(c=='^'){
            (*numbers)->data = pow(first,second);
        }
    }
    else{
        scanf("%c",s);
        (*numbers)->data = second;
    }
    pop_sign(operators);
}
int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen ("input.txt", "r", stdin);
    //     freopen ("output.txt", "w", stdout);
    // #endif
    char c;
    int n;
    struct num*numbers =NULL;
    struct sign*operators = (struct sign*)malloc(sizeof(struct sign));
    operators->data='$';
    operators->priority=0;
    while(operators->data!='#'){
        scanf("%d ",&n);
        Push_num(n,&numbers);
        scanf("%c ",&c);
        while(operators->priority >= outside_stack_priority(c)){
            if(!(c=='#'&&operators->data=='$'))
            execute(&numbers,&operators,&c);
            else break;
        }
        Push_sign(c,&operators);
    }
    printf("%d",numbers->data);
}