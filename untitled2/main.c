/*crea  una  lista e la  stampa*/
#include  <stdio.h>
#include  <stdlib.h>
#include <stdbool.h>

typedef struct  node
{
    int  valore;
    struct  node* next;
}Node;

Node* ultimoInd(Node *list){
    Node *prec;
    while(list->next != NULL){
        prec = list;
        list = list->next;
         //free( ultimoInd(list->next));
    }
    if(prec->next == NULL){
        free(prec);
        return NULL;
    }
    return prec;
}

void disalloca(Node *list) {
    bool appost = false;
    Node *temp;
    while (!appost) {
        temp = ultimoInd(list);
        if (temp != NULL) {
            free(temp->next);
            temp->next = NULL;
        } else {
            appost = !appost;
        }
    }
}

void dealloca(Node *list){  //giusto credododododoodo
    Node* temp;
    while(list != NULL){
        temp = list;
        list = list->next;
        free(temp);

    }
}


int  main()
{
    int n;
    Node* lista;
    Node* l;
    lista=NULL;

    do
    {
        printf("Inserisci  un  naturale o  -1 per  terminare\n");
        scanf("%d",&n);
        if (n>=0)
        {
            if (lista==NULL) /*  prima  iterazione  */
            {
                lista = (Node*)  malloc(sizeof(Node));
                l = lista;
            }
            else /*  iterazioni  successive  */
            {
                l->next = (Node*)  malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    } while (n>=0);

    l=lista;
    printf("numeri  inseriti: ");
    while (l!=NULL)
    {
        printf("%d - %p \n",l->valore, l->next);
        l=l->next;
    }
    disalloca(lista);
    printf("lista: %p", lista );
    printf("\ndovrebbe essere stato tutto disallocato correttamente");
    printf("\n");



    return  0;
    }
