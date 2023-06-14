#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Product {
    int code;
    char description[100];
    float price;
    int quantity;
    char date[11];
};

struct node {
    struct Product data;
	struct node* next;
};

void print_list_products(struct node* head);
void print_list_sales(struct node* head);
int search_by_code(struct node* head, int code, int printData);
int search_by_description(struct node* head, char* desc, short printData);
struct Product get_node_data(struct node* head, int code);
void edit_node_data(struct node* head, int code, struct Product editData);
int push(struct node** head, struct Product data);
int delete_node(struct node* head, int code);
void delete_list(struct node* head);