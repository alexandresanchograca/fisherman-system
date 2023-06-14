#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long* storeProductsCSVMemory(char* name);
long* storeSalesCSVMemory(char* name);
int storeProductsCSVDisk(struct node* head, char* filename);
int storeSalesCSVDisk(struct node* head, char* filename);
