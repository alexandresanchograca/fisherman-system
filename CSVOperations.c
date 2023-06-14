#pragma once
#include "CSVOperations.h"
#include "LinkedList.h"

//Cria um ficheiro com o nome do input e extrai os dados usando os delimitadores ; que são os do csv da versao portuguesa.
//Depois de extraidos os dados são adicionados ou "empurrados" para uma lista linkada.
//Como não foi explicitado nos requisitos que os produtos teriam de ser adicionados de certa forma o método push é a implementação mais fácil e foi a que usei, mas poderia facilmente usar outra.
long* storeProductsCSVMemory(char* name) {
    struct node* head = NULL;
    struct node* current = NULL;

    FILE* fp;
    char line[1000];
    char* field;
    char id[100];
    char description[100];
    char price[100];

    fp = fopen(name, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    while (fgets(line, 1000, fp)) {
        //Extrair Id
        field = strtok(line, ";");
        strncpy(id, field, 100);

        //Extrair descricao
        field = strtok(NULL, ";");
        strncpy(description, field, 100);

        //Extrair o preco
        field = strtok(NULL, ";");
        strncpy(price, field, 100);

        //Guardar os dados em memoria
        struct Product newProd;
        newProd.code = atoi(id);
        strcpy(newProd.description, description);
        newProd.price = atof(price);
        push(&head, newProd);
    }

    return head;
}

//Cria um ficheiro com o nome do input e extrai os dados usando os delimitadores ; que são os do csv da versao portuguesa.
//Depois de extraidos os dados são adicionados ou "empurrados" para uma lista linkada.
//Como não foi explicitado nos requisitos que os produtos teriam de ser adicionados de certa forma o método push é a implementação mais fácil e foi a que usei, mas poderia facilmente usar outra.
long* storeSalesCSVMemory(char* name) {
    struct node* head = NULL;
    struct node* current = NULL;

    FILE* fp;
    char line[1000];
    char* field;
    char id[100];
    char description[100];
    char price[100];
    char quantity[100];
    char date[100];

    fp = fopen(name, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    while (fgets(line, 1000, fp)) {
        //Extrair Id
        field = strtok(line, ";");
        strncpy(id, field, 100);

        //Extrair descricao
        field = strtok(NULL, ";");
        strncpy(description, field, 100);

        //Extrair o preco
        field = strtok(NULL, ";");
        strncpy(price, field, 100);

        //Extrair a quantidade
        field = strtok(NULL, ";");
        strncpy(quantity, field, 100);

        //Extrair a data
        field = strtok(NULL, ";");
        strncpy(date, field, 100);

        //Guardar os dados em memoria
        struct Product newSales;
        newSales.code = atoi(id);
        strcpy(newSales.description, description);
        newSales.price = atof(price);
        newSales.quantity = atoi(quantity);
        strcpy(newSales.date, date);
        push(&head, newSales);
    }

    return head;
}

//Guarda os dados da Lista Linkada num ficheiro CSV
int storeProductsCSVDisk(struct node* head, char* filename) {
    FILE* fp;

    fp = fopen("mydata.csv", "w+");

    if (fp == NULL) {
        printf("Error creating file.\n");
        return 0;
    }

    struct node* p = head;

    while (p != NULL) {
        fprintf(fp, "%d;%s;%.2f;\n", p->data.code, p->data.description, p->data.price);
        p = p->next;
    }
    return 1;
}

//Guarda os dados da Lista Linkada num ficheiro CSV
int storeSalesCSVDisk(struct node* head, char* filename) {
    FILE* fp;

    fp = fopen("mysales.csv", "w+");

    if (fp == NULL) {
        printf("Error creating file.\n");
        return 0;
    }

    struct node* p = head;

    while (p != NULL) {
        fprintf(fp, "%d;%s;%.2f;%i;%s\n", p->data.code, p->data.description, p->data.price, p->data.quantity, p->data.date);
        p = p->next;
    }
    return 1;
}