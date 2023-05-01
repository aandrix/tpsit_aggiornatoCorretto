#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/**********************************
 * Giordano andrea
 * algoritmo scheduling round robin
 **********************************/
#define L_STR 21
#define TIME_SLICE 30
#define MIN_TIME 50
#define MAX_TIME 250

typedef char String[200];

typedef struct{
    int pid; //identificatore unico del process
    String stato; //identifica lo stato del processo
    int time;  //tempo in cpu (50 e 200ms)
    struct node* next;
} Node;

void printList(Node *source);


void push(Node **head, Node *element){
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



void sleep(int millisec){
    clock_t  start = clock();
    while(start + millisec <clock());
}

void newPocess(Node **newList){
    Node *temp = (Node*)malloc(sizeof (Node));
    if(newList == NULL) {
        newList = (Node *) malloc(sizeof(Node));
    }
    int risp = 0;
    while(risp != 1){
        //void push(Node **head, Node *element){
        printf("inserire il nome del processo: ");
        fflush(stdin);
        scanf("%d", &temp->pid);
        printf("1 %d", temp->pid);
        do {
            printf("\ninserire il tempo di latenza del processo: ");
            scanf("%d", &temp->time);
        }while(temp->time < 50 || temp->time > 200 );
        strcpy(temp->stato, "new\0");
        push(newList, temp);
        printf("\npremere 1 per uscire dall'inserimento: ");
        scanf("%d", &risp);

    }
    free(temp);
    printf("\nfine caricamento\n");
    printList(newList);
}

void spostaInReady(Node *source, Node**destination ){
    *destination = source;
}

void printList(Node *source){
    printf("\nstampa\n");
    do{
        printf("pid: %d stato: %s time: %d", source->pid, source->stato, source->time);
        if(source->next != NULL)
        source = source->next;
        else
            break;
    }while(true);
}


int main() {
    Node *newList;
    Node *readyList;
    Node *terminateList;
    newPocess(&newList);
    printList(newList);
    spostaInReady(newList, &readyList);
    printList(readyList);




    return 0;
}
