#include "LinkedList.h"
#include "MassageCases.h"


//Mostra a lista de produtos
void print_list_products(struct node* head) {
    struct node* p = head;

    while (p != NULL) {
        printf("ID:%d, %s : %.2f$ \n", p->data.code, p->data.description, p->data.price);
        p = p->next;
    }
}

//Mostra a lista das vendas
void print_list_sales(struct node* head) {
    struct node* p = head;

    while (p != NULL) {
        printf("ID:%d, %s : %.2f$, Quantidade: %d Data: %s \n", p->data.code, p->data.description, p->data.price, p->data.quantity, p->data.date);
        p = p->next;
    }
}

//Procura o produto por código
int search_by_code(struct node* head, int code, short printData) {
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data.code == code) {

            if(printData)
                printf("\n<-------------Resultado Encontrado---------------->\nid: %d, Descricao: %s, Preco: %.2f$\n<------------------------------------------------->\n", temp->data.code, temp->data.description, temp->data.price);

            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

//Procura o produto por descricao
int search_by_description(struct node* head, char* desc, short printData) {
    struct node* temp = head;
    
    //Por todos os chars em lowercase
    const char* lowerDesc = toLower(desc);

    while (temp != NULL) {

        char* tempLowerCase = toLower(temp->data.description);

        if (!strcmp(lowerDesc, tempLowerCase)){

            if (printData)
                printf("\n<-------------Resultado Encontrado---------------->\nid: %d, Descricao: %s, Preco: %.2f$\n<------------------------------------------------->\n", temp->data.code, temp->data.description, temp->data.price);

            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

//Adiciona um nó à linked list
int push(struct node** head, struct Product data) {

    //criar a ligação
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    //Verifica se a memória foi alocada
    if (temp == NULL) {
        printf("\n[ERRO] Memória não alocada.\n");
        return 0;
    }

    temp->data = data;

    // aponta para o primeiro elemento da lista
    temp->next = *head;

    //assignamos o atual ao primeiro da lista
    *head = temp;
    return 1;
}

//Obtem os dados do produto do código inserido e retorna o valor da estrutura data
struct Product get_node_data(struct node* head, int code) {
    struct node* temp = head;

    while (temp != NULL) {
        if (temp->data.code == code) {
            return temp->data;
        }
        temp = temp->next;
    }
    return;
}

//Edita os dados do nó
void edit_node_data(struct node* head, int code, struct Product editData) {
    struct node* temp = head;

    while (temp != NULL) {
        if (temp->data.code == code) {

            //Copiamos os dados da estrutura para o nó que queremos
            temp->data.code = editData.code;
            strcpy(temp->data.description, editData.description);
            temp->data.price = editData.price;
            strcpy(temp->data.date, editData.date);
            temp->data.quantity = editData.quantity;

            printf("\n<-------------Resultado Editado------------------->\nid: %d, Descricao: %s, Preco: %.2f$", temp->data.code, temp->data.description, temp->data.price);

            if (temp->data.date != NULL) {
                printf("Quantidade: %d Data: %s\n<------------------------------------------------->\n", temp->data.quantity, temp->data.date);
            }

            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

//Apaga o nó da Linked List(LL)
int delete_node(struct node* head, int code) {
    struct node* temp = head, *prev = NULL;

    if (temp != NULL && temp->data.code == code) {
        head = temp->next;
        free(temp);
        return 1;
    }

    while (temp != NULL && temp->data.code != code) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("[ERRO] Produto nao encontrado\n");
        return 0;
    }

    prev->next = temp->next;
    free(temp);
    return 1;
}

void delete_list(struct node* head) {
    struct node* current = head;
    struct node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    head = NULL;
}

