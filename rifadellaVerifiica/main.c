    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #define LUNG 1024
    #define COSTO 100

    typedef char String[LUNG];

    typedef struct {
        String cognome;
        float euroVersati;
    }Pagamenti;

    typedef struct{
        String cognome;
        float totVersato;
    }Alunno;
    /*
     *  int data;
        String cognome;
        float euroVersati;
     */

    void stampaPagamenti(Alunno* classe, int dim);

    int contaRighe(String nomeFile){
        String temp;

        int k=0;
        FILE *fp = fopen(nomeFile, "r");
        if(fp != NULL){
            while(fgets(temp, LUNG, fp)){k++;}
            fclose(fp);
            return k;
        }else{
            fclose(fp);
            return -1;
        }
    }

    void caricaDafile(Pagamenti *tab, String nomeFile, int dim){
        Pagamenti* t = tab;
        String riga;
        String data;
        FILE *fp = fopen(nomeFile,"r");
        if(fp!=NULL){
            printf("\nfile aperto\n");
            while(t<tab+dim){
                /*fgets(riga, LUNG, fp);
                *(a+k)->data = strtok(riga,";");
                *(a+k)->cognome = strtok(NULL ,";");
                (a+k)->importo = atoi(strtok(NULL ,";"));
                 */
                fgets(riga, LUNG, fp);
                strtok(riga, ";");
                 strcpy(t->cognome, strdup(strtok(NULL, ";")));
                t->euroVersati = atof(strtok(NULL, ";"));
                t++;
            }
        }
    }

    void printaPagamenti(Pagamenti *p, int dim){
        int k;
        for(k=0; k<dim; k++){
            printf("\n%s, %f", (p+k)->cognome, (p+k)->euroVersati);
        }
    }


    int cercaCorrispondenze(String cognome, Pagamenti* source, int dim){ //returna la posizione della seconda corrispondenza
        Pagamenti* p;
        String cerca;
        int tro=0;
        int k=0;
        /*
         * mi devo fermare quando trovo due corrispondenze,
         */
        p = source;
        while(p<source + dim && tro <2){
            strcpy(cerca, p->cognome);
            if(strcmp(cognome, cerca)==0){
                tro ++;
                if(tro == 2){
                    return k;
                }
            }
            k++;
            p++; //puntatore a pagamenti
        }
        return -1;
    }

    int cercaCorrispondenzeDue(String cognome, Pagamenti* source, int dim, int vett[]){ // in un vettore al massimo due corrispondenze,
        //returna quante posizioni vengono utilizzare di "vett", 1 oppure 2
        Pagamenti* p;
        String cerca;
        int rit;
        int tro=0;
        int k=0;
        /*
         * mi devo fermare quando trovo due corrispondenze,
         */
        p = source;
        while(p<source + dim && tro <2){
            strcpy(cerca, p->cognome);
            if(strcmp(cognome, cerca)==0){
                tro ++;
                if(tro == 1){
                    vett[0]=k;
                    rit = 1;
                }else if(tro == 2){
                    vett[1]=k;
                    p = source + dim;
                    rit = 2;
                }
            }
            k++;
            p++; //puntatore a pagamenti
        }
        return rit;
    }

    int creaTabPagati(Pagamenti *source, Alunno *dest, int dim){
        /*
         * scorrere il vettore source e cercare il cognome al suo interno per controllare
         * quanti pagamenti una persona ha effettuato
         * comincio scorrendo il vettore, controllo se all'interno del vettore il cognome si
         * presenta piu di una volta nel caso sommo tutti gli importi e creo il nel vettore dest
         * una tabella di tutti i membri della classe con il pagamento in totale effettuato
         */
        Pagamenti *s;
        Alunno *d = dest;
        bool unico = false;
        int tro;
        int dimF=dim;
        int cont = 0;
        for(s = source; s < source + dim; s++){
            //(String cognome, Pagamenti* source, int dim)

            if((tro=cercaCorrispondenze(s->cognome, s, dim))==-1){
                strcpy(d->cognome, s->cognome);
                d->totVersato = s->euroVersati;

            }else{
                //*d->cognome = *s->cognome;

                strcpy(d->cognome, s->cognome);
                d->totVersato = ((float)s->euroVersati + (float)(s+tro)->euroVersati);
                printf("\n%s ha pagato %f+%f ", d->cognome, s->euroVersati, (s+tro)->euroVersati);
                dimF--;
            }
            if(cont < dimF){
                if(d->totVersato < COSTO){
                    printf("\n%s, non ha pagato tutta la quota, importo pagato: %f mancano: %f", d->cognome, d->totVersato, COSTO-d->totVersato);
                }else if(d->totVersato > COSTO){
                    printf("\n%s, ha pagato piu del necessario, ha pagato : %f, %f in più", d->cognome, d->totVersato, d->totVersato-COSTO);
                }else{
                    printf("\n%s, ha pagato la retta correttamente", d->cognome);
                }
                printf("\n");
                cont ++;
            }

            d++;
        }

        printf("%d", dimF);
        return dimF;
    }

    void stampaPagamenti(Alunno* classe, int dim){
        Alunno *c;
        for(c=classe; c< classe + dim; c++){
            printf("\n%s, tot. pagato: %f", c->cognome, c->totVersato);
        }
    }



    void cercaMioNome(Pagamenti *p, int dim){ //chiede in imput un nome e ne stampa un report accurato;
        String nome;
        Pagamenti *p2 = p;
        int pos[2];
        int dimPos;
        printf("\n\tinserire il proprio nome:");
        scanf("%s", nome);
        dimPos=cercaCorrispondenzeDue(nome, p2, dim, pos);
        if(dimPos == 1){
            printf("\nè stata effettuata una sola rata di %f euro\n", (p2+pos[0])->euroVersati);
        }else{
            printf("\nsono state effettuate due rate da %f %f euro", (p2+pos[0])->euroVersati, (p2+pos[1])->euroVersati);
        }

    }

    int main() {
        Pagamenti *versati;
        Alunno *classe;
        String nomeFile="../4AROB_GITA.csv";
        int dim = contaRighe(nomeFile);
        int dim2;
        if(dim > 0){
            printf("%d", dim);
            versati = (Pagamenti*)malloc(dim*sizeof(Pagamenti));
            classe = (Alunno*)malloc(dim*sizeof(Alunno));
            caricaDafile(versati, nomeFile, dim);
            printaPagamenti(versati, dim);
            dim2 = creaTabPagati(versati, classe, dim);

            stampaPagamenti(classe, dim2);
            cercaMioNome(versati, dim);
            free(versati);
            free(classe);
        }else{
            printf("non è stato possibile aprire il file oppure risulta vuoto");
        }
        return 0;
    }
