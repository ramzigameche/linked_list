#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
/*----------------------------------------------------*/
    typedef struct node {
        int val;
        struct node *next;
    }node;
/*----------------------------------------------------*/
    bool verif(node *head){
        if (head == NULL){
            return true;
        }
        else {
            return false;
        }
    }
/*----------------------------------------------------*/
    struct node* initializer(node *head){
        head = NULL;
        return head;
    }
/*----------------------------------------------------*/
    struct node* add_at_end(struct node *head,int data){
        struct node *q,*p;
        q=malloc(sizeof(node));
        p=head;
        q->next=NULL;
        q->val=data;
        if (verif(head)){
            head=q;
        }
        else {
            while(p->next!=NULL){
                p=p->next;
            }
            p->next=q;
        }
        return head;
    }
/*----------------------------------------------------*/
    void read_linked_list(struct node *head){
        struct node *q;
        if (verif(head)){
            printf("The linked list is free!!!\n");
        }
        else {
            q=head;
            while (q != NULL){
                printf("\t%d\n",q->val);
                q=q->next;
            }
        }
    }
/*----------------------------------------------------*/
    struct node* add_at_beg(struct node *head, int data){
        struct node *q;
        q=malloc(sizeof(node));
        q->next=NULL;
        q->val=data;
        if (verif(head)){
            head=q;
        }
        else {
            q->next=head;
            head = q;
        }
        return head;
    }
/*----------------------------------------------------*/
    struct node* creat_linked_list(struct node *head){
        int i,x,n;
            printf("How Many Element you want to enter :\n");
            scanf("%d",&n);
        for (i=0;i<n;i++){
            printf("\tNode N°%d\t=\t",i+1);
            scanf("%d",&x);
            head = add_at_end(head,x);
        }
        return head;
    }
/*----------------------------------------------------*/
    struct node* insert(struct node* head, int data){
    struct node* temp;
    struct node* newP =malloc(sizeof(struct node));
    newP->val=data;
    newP->next=NULL;
    int key = data;
    if (head == NULL || key < head->val){
        newP->next=head;
        head = newP;
    }
    else{
        temp=head;
        while (temp->next != NULL && temp->next->val < key){
            temp = temp->next;
            newP->next = temp->next;
            temp->next = newP;
        }
        return head;
    }


    }
/*----------------------------------------------------*/
    int length(struct node *head){
        int i;
        struct node *q;
        q=head;
        i=0;
        while (q!=NULL){
            q=q->next;
            i++;
        }
        return i;
    }
/*----------------------------------------------------*/
    struct node* delet_linked_list(struct node* head){
    struct node* tmp;
    tmp=head;
    while (tmp != NULL){
        tmp=tmp->next;
        free(head);
        head=tmp;
    }
    return head;
    }
/*----------------------------------------------------*/
    void sea_val(struct node *head,int n){
    int found;
    int k;
    struct node *q;
    q=head;
    found=0;
    k=1;
    while (q != NULL){
        if (q->val == n){
            found =1;
            printf("the value %d is found in the position %d\n",n,k);
        }
        k++;
        q=q->next;
    }
    if (found == 0){
        printf("The Value Doesn't exist inside the linked list!!\n");
    }
    }
/*----------------------------------------------------*/
    void delete_node(struct node **head,int pos){
    struct node *prv;
    struct node *curr;
    curr=*head;
    if (pos==1){
        *head=curr->next;
        free(curr);
        curr=NULL;
    }
    else{
        while (pos!=1){
            prv=curr;
            curr=curr->next;
            pos--;
        }
        prv->next=curr->next;
        free(curr);
        curr=NULL;
    }
    }
/*----------------------------------------------------*/
    void given_k(struct node **head,int k,int val){
    int i;
    struct node *new_node;
        new_node=malloc(sizeof(node));
        new_node->val=val;
        new_node->next=NULL;
    struct node *curr_node;
        curr_node=*head;
    struct node *pre_node;
        pre_node=NULL;
    i=1;
    while (curr_node!=NULL && i<k){
        pre_node=curr_node;
        curr_node=curr_node->next;
        i++;
    }
    if (i<k){
        printf("the linked list is not that tall !!\n");
    }

    if (pre_node==NULL){
        *head=new_node;
    }
    else{
        pre_node->next=new_node;
    }
        new_node->next=curr_node;


    }
/*----------------------------------------------------*/
int main()
{
    struct node *head;
    head=initializer(head);
    int option = 0;
    int x_beg,pos,x_pos,x_end,val;
            printf("\n");
        printf("--------------------------------------------------\n");
        printf("|                  Main Menu                     |\n");
        printf("--------------------------------------------------\n");
        printf("| 1. Add at Beg.                                  |\n");
        printf("| 2. add at pos k.                                |\n");
        printf("| 3. create linked list.                          |\n");
        printf("| 4. read linked list.                            |\n");
        printf("| 5. add at end.                                  |\n");
        printf("| 6. check if the list is free.                   |\n");
        printf("| 7. get lenght of the list.                      |\n");
        printf("| 8. search for value.                            |\n");
        printf("| 9. delete a node.                               |\n");
        printf("| 10. delete the linked list.                     |\n");
        printf("| 11. add with sorting.                           |\n");
        printf("| 12. Exit                                        |\n");
        printf("--------------------------------------------------\n");
    while (option != 12) {

        printf("Enter an option (1-12): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the value of the node : \n");
                scanf("%d",&x_beg);
                head=add_at_beg(head,x_beg);
                break;
            case 2:
                printf("Enter the position :\n");
                scanf("%d",&pos);
                printf("Enter the value of the node :\n");
                scanf("%d",&x_pos);
                given_k(&head,pos,x_pos);
                break;
            case 3:
                head=creat_linked_list(head);
                break;
            case 4:
                read_linked_list(head);
                break;
            case 5:
                printf("Enter the value of the node : \n");
                scanf("%d",&x_end);
                head=add_at_end(head,x_end);
                break;
            case 6:
                if(verif(head)){
                    printf("The linked list is free!!\n");
                }
                else{
                    printf("The linked list is not free!!\n");
                }
                break;
            case 7:
                printf("The length of the list is :%d\n",length(head));
                break;
            case 8:
                printf("Enter the value to search if it exists in the ll :\n");
                scanf("%d",&val);
                sea_val(head,val);
                break;
            case 9:
                printf("Enter the position of the Node :\n");
                scanf("%d",&val);
                delete_node(&head,val);
                break;
            case 10:
                head=delet_linked_list(head);
                break;
            case 11:
                printf("Enter a value : \n");
                scanf("%d",&val);
                head=insert(head,val);
                break;
            case 12:
                printf("Exiting program...\n");
                return 0;
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}

