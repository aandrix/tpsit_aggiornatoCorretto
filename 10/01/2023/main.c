#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char c;
    struct Node *next;
}Node;

void push(Node **head, Node *element){
    printf("\npush %c\n", element->c);
    if(*head == NULL){
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }

}

Node* pop(Node **head){
    Node *ret = *head;
    if(*head == NULL){
        return  NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}

/*
Node* pop(struct Node* headRef){
    // underflow condition
    printf("\npop %c \n", headRef->c);
    if (headRef == NULL) {
        return NULL;
    }

    struct Node* head = headRef;
     headRef = headRef->next;
    return head;
}
 */

void scorriElavora(char strin[], Node **pila){
    int k = 0;
    Node *temp = (Node*)malloc(sizeof(Node));
    Node *tem = NULL;
    while(strin[k]!='\0'){
        temp->c = strin[k];
        printf("la Stringa %c", temp->c);
        if(strin[k]=='(' || strin[k]=='{' || strin[k]== '['){
            push(&pila, temp);
        }else if(strin[k]==')' || strin[k]=='}' || strin[k]== ']'){
            tem = (Node*)malloc(sizeof(Node));
            tem = pop(&pila);
            free(tem);
            /*00...ll
            temp = pop(&pila);
            if(temp != NULL)
                free(temp);
            else
                printf("escoo");
                break;
            */

        }
        k++;
    }
    free(temp);
}

int main() {
    Node *pila = NULL;

    scorriElavora("([ciao](((((", &pila);
    printf("pila alla fine %c", pila->c);
    if(pila == NULL){
        printf("tutte le parentesi sono chiuse");
    }else{
        printf("non sono state chiuse tutte le parentesi");
    }





}
