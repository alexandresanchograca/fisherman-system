#include "AF2.h"

int main()
{
    //Criamos uma linked list na qual guardamos o valor do data.csv e esta funcao retorna o ponteiro do head
    struct node* productsHead = storeProductsCSVMemory("data.csv");
    struct node* salesHead = storeSalesCSVMemory("sales.csv");

    
    printf("Atual lista de Produtos em memoria: \n");
    printProducts(&productsHead);
    printf("<------------------------>\n");

    printf("Atual lista de Vendas em memoria: \n");
    printSales(&salesHead);
    printf("<------------------------>\n");

    int input = NULL;
    do {
        printf("Selecione as seguintes opcoes:\n 1: Adicionar Produto\n 2: Editar Produto\n 3: Remover Produto\n 4: Pesquisar Produto\n 5: Ler lista de produtos em memoria\n 6: Gerar reporte de vendas\n 7: Editar dados de vendas\n 8: Guardar dados em ficheiros CSV\n 0: Sair\n");
        scanf("%d", &input);
        fflush(stdin);

        switch (input)
        {
        case 1:
            printf("Adicionar produto...\n");
            if (addProduct(&productsHead))
                printf("\n<--Produto adicionado com sucesso!-->\n");
            break;
        case 2:
            printf("Editar produto...\n");
            editProduct(&productsHead);
            break;
        case 3:
            printf("Remover produto...\n");
            removeProduct(&productsHead);
            break;
        case 4:
            printf("Pesquisar produto...\n");
            searchProduct(&productsHead);
            break;
        case 5:
            printf("Ler lista da memória\n");
            printProducts(&productsHead);
            break;
        case 6:
            printf("Gerar reporte de vendas...\n");
            salesReport(salesHead);
            break;
        case 7:
            printf("Editar dados de vendas...\n");
            editSale(&salesHead);
            break;
        case 8:
            printf("Guardar dados em ficheiros CSV\n");
            if(storeProductsCSVDisk(productsHead, "data.csv") && storeSalesCSVDisk(salesHead, "sales.csv"))
                printf("\n<--Ficheiros Guardados com sucesso!-->\n\n");
            else
                printf("\n<--[ERRO] Nao foi possivel guardar os ficheiros-->\n");
            break;
        default:
            printf("[Erro] Opcao Invalida!\n\n");
            break;
        }
    } while (input != 0);


    //Liberto a memória explicitamente das listas
    freeList(&productsHead);
    freeList(&salesHead);
    return 0;
}
