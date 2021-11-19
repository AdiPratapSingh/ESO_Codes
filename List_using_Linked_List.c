#include <stdio.h>
#include <stdbool.h>

struct link{
    int data;
    struct link*next;
    struct link*prev;
};

bool isEmpty(struct link*L){
    if(L){
        return false;
    }
    else return true;
}
bool search(int x,struct link*L){
    if(L!=NULL){
        if(L->data==x){
            return true;
        }
        L=L->next;
    }
    return false;
}
int successor(struct link*i,struct link*L){
    return i->next->data;
}
int predecessor(struct link*i,struct link*L){
    return i->prev->data;
}
struct link* CreateEmptyList(){
    struct link* L=NULL;
    return L;
}
struct link* Insert(int x,struct link*i,struct link*L){
    struct link*hold = (struct link*)malloc(sizeof(struct link));
    hold->data = x;
    hold->next = i;
    if(i){
        hold->prev = i->prev;
        hold->prev->next = hold;
        i->prev = hold;
    }
    else{
        L = hold;
        L->prev=NULL;
    }
    return L;
}
struct link* Delete(struct link*i,struct link*L){
    if(i!=L){
        i->prev->next = i->next;
        i->next->prev = i->prev;
    }
    else{
        L=L->next;
    }
    free(i);
    return L;
}
void MakeListEmpty(struct link*L){
    L= NULL;
}

int main(){
    return 0;
}