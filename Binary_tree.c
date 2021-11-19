#include <stdio.h>
#include <stdbool.h>

int extra=0;
int n;
struct node{
    int data;
    struct node* left;
    struct node* right;
}; 

// struct node *create_tree(int h){
//     if(h!=0){
//         struct node* head = (struct node*)malloc(sizeof(struct node));
//         head->left = create_tree(h-1);
//         head->right = create_tree(h-1);
//         return head;
//     }
//     else if(h==0&&extra){
//         struct node* head = (struct node*)malloc(sizeof(struct node));
//         head->left = NULL;
//         head->right = NULL;
//         extra--;
//         return head;
//     }
//     return NULL;
// }
struct node*create_tree(int *a,int start,int end){
    int mid;
    mid= (start + end)/2;
    struct node*head= (struct node*)malloc(sizeof(struct node));
    if(start==end){
        head = (struct node*)malloc(sizeof(struct node));
        head->data = a[start];
    }
    else if(mid!=start){
        head->data= a[mid];
        head->left=create_tree(a,start,mid - 1);
        head->right=create_tree(a,mid+1,end);
    }
    else if(mid==start){
        head->data= a[end];
        head->left=(struct node*)malloc(sizeof(struct node));
        head->right=NULL;
        head->left->data = a[start];
        head->left->right = NULL;
        head->left->left = NULL;
    }
    return head;
}

// void Transversal(struct node*head){
//     if(head){
//         Transversal(head->left);
//         printf("%d",head->data);
//         Transversal(head->right);
//     }
//     return;
// }

void Transversal(struct node*head){
    if(head){
        Transversal(head->left);
        printf("%d",head->data);
        Transversal(head->right);
    }
    return;
}

int main(){
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int q = 1;
    int h = 0;
    while(n>=q){
        q = q*2;
        h++;
    }
    h--;
    extra = n+1-q/2;
    struct node* head = create_tree(a,0,n-1);
    Transversal(head);
    return 0;
}