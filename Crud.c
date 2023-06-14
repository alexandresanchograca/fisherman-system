#include "Crud.h"
#include "LinkedList.h"

//Adiciona um produto à lista
int addProduct(struct node** head) {
    //Criar nova instancia de produto, alocar memoria dinamica e ajustar os ponteiros da Linked list(na funcao push).
    struct Product newProd;

    printf("Input a code for the product: ");
    scanf("%i", &newProd.code);
    fflush(stdin);

    //Verifico se o código é único
    if (search_by_code(*head, newProd.code, 0)) {
        printf("\n[ERRO] Codigo de produto ja existente, insira um codigo de indentificador unico.\n\n");
        return 0;
    }

    printf("Input a description for the product: ");
    scanf("%s", newProd.description);
    fflush(stdin);

    printf("Input a value for the product: ");
    scanf("%f", &newProd.price);
    fflush(stdin);

    push(head, newProd);
    return 1;
}

//Edita um produto da lista
void editProduct(struct node** head) {
    printf("\n\nInsira o codigo do produto que pretende editar: ");
    int code;
    scanf("%i", &code);
    fflush(stdin);

    struct Product productInstance = get_node_data(*head, code);

    printf("Qual dos parametros deseja editar?\n[1] id\n[2] Descricao\n[3]Preco\n");
    int input;
    scanf("%i", &input);
    fflush(stdin);

    if (input == 1) {
        printf("Insira o novo codigo: ");
        int newCode;
        scanf("%i", &newCode);
        fflush(stdin);

        productInstance.code = newCode;

        if (search_by_code(*head, productInstance.code, 0)) {
            printf("\n[ERRO] Codigo de produto ja existente, insira um codigo de indentificador unico.\n\n");
            return 0;
        }

        edit_node_data(*head, code, productInstance);
    }
    else if (input == 2) {
        printf("Insira a nova descricao: ");
        char newDesc[100];
        scanf("%s", newDesc);
        fflush(stdin);

        strcpy(productInstance.description, newDesc);

        edit_node_data(*head, code, productInstance);
    }
    else if (input == 3) {
        printf("Insira o novo preco: ");
        float newPrice = 0;
        scanf("%f", newPrice);
        fflush(stdin);

        productInstance.price = newPrice;

        edit_node_data(*head, code, productInstance);
    }
    else {
        printf("Codigo invalido!");
    }
    return;
}

//Edita uma venda da lista
void editSale(struct node** head) {
    printf("\n\nInsira o codigo da venda do produto que pretende editar: ");
    int code;
    scanf("%i", &code);
    fflush(stdin);

    struct Product productInstance = get_node_data(*head, code);

    printf("Qual dos parametros deseja editar?\n[1] id\n[2] Descricao\n[3]Preco\n[4]Quantidade\n[5]Data\n");
    int input;
    scanf("%i", &input);
    fflush(stdin);

    if (input == 1) {
        printf("Insira o novo codigo: ");
        int newCode;
        scanf("%i", &newCode);
        fflush(stdin);

        productInstance.code = newCode;

        if (search_by_code(*head, productInstance.code, 0)) {
            printf("\n[ERRO] Codigo de produto ja existente, insira um codigo de indentificador unico.\n\n");
            return 0;
        }

        edit_node_data(*head, code, productInstance);
    }
    else if (input == 2) {
        printf("Insira a nova descricao: ");
        char newDesc[100];
        scanf("%s", newDesc);
        fflush(stdin);

        strcpy(productInstance.description, newDesc);

        edit_node_data(*head, code, productInstance);
    }
    else if (input == 3) {
        printf("Insira o novo preco: ");
        float newPrice = 0;
        scanf("%f", &newPrice);
        fflush(stdin);

        productInstance.price = newPrice;

        edit_node_data(*head, code, productInstance);
    }
    else if (input == 4) {
        printf("Insira a nova quantidade vendida: ");
        int newQuantity = 0;
        scanf("%i", &newQuantity);
        fflush(stdin);

        productInstance.quantity = newQuantity;

        edit_node_data(*head, code, productInstance);
    }
    else if (input == 5) {
        printf("Insira uma nova data (AAAA-MM-DD): ");
        char newDate[11];
        int ano, mes, dia;
        char delimitador;
        //Le ate 10 carateres
        scanf("%10s", newDate);
        fflush(stdin);

        //Error handling para a data
        if (sscanf(newDate, "%d%c%d%c%d", &ano, &delimitador, &mes, &delimitador, &dia) != 5) {
            printf("[ERRO]Formato de data inválido, tente novamente!\n");
            return;
        }

        printf("%d%c%d%c%d", ano, delimitador, mes, delimitador, dia);

        if (delimitador != '-') {
            printf("[ERRO]Formato de data inválido, tente novamente!\n");
            return;
        }

        if (ano <= 1700 || mes < 1 || mes > 12 || dia < 1 || dia > 31) {
            printf("[ERRO]Formato de data inválido, tente novamente!\n");
            return;
        }

        //Copiar a data para a variável
        strcpy(productInstance.date, newDate);

        edit_node_data(*head, code, productInstance);
    }
    else {
        printf("Codigo invalido!");
    }
    return;
}

//Procura um produto da lista
int searchProduct(struct node** head) {
    printf("\nInsira [1] para procurar por codigo.\nInsira [2] para procurar por descricao.\n");
    int input;
    scanf("%i", &input);
    fflush(stdin);


    if (input == 1) {
        printf("\n\nInsira o codigo desejado: ");
        scanf("%i", &input);
        fflush(stdin);

        if (search_by_code(*head, input, 1))
            return 1;
    }
    else if (input == 2) {
        char desc[100];
        printf("\n\nInsira a descricao desejada: ");
        scanf("%s", desc);
        fflush(stdin);

        if (search_by_description(*head, desc, 1))
            return 1;
    }
    else {
        printf("[ERRO]Opcao invalida!\n");
    }  
    return 0;
}

//Remove um produto da lista
void removeProduct(struct node** head) {
    printf("\nInsira o codigo do produto que pretende remover: ");
    int code;
    scanf("%i", &code);
    fflush(stdin);

    if(delete_node(*head, code))
        printf("\nProduto Removido com sucesso!\n");

    return;
}

//Gera um reporte das vendas efectuadas
int salesReport(struct node* head) {
    struct node* p = head;

    int quantity = 0;
    float priceSum = 0;

    printf("\n<=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=>\n");
    while (p != NULL) {
        printf("ID:%d, %s : %.2f$, Quantidade: %d Total: %.2f Data: %s \n", p->data.code, p->data.description, p->data.price, p->data.quantity, p->data.price * p->data.quantity, p->data.date);
        quantity += p->data.quantity;
        priceSum += p->data.price * p->data.quantity;
        p = p->next;
    }
    printf("<.....................................................>");
    printf("\nTotal de quantidades vendidas: %d\nTotal de vendas em dinheiro: %.2f\n", quantity, priceSum);
    printf("<=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=>\n\n");
}

void printSales(struct node** head) {
    print_list_sales(*head);
}

void printProducts(struct node** head) {
    print_list_products(*head);
}

void freeList(struct node** head) {
    delete_list(*head);
}