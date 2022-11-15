

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAPACITY 5000

typedef struct HT_item Ht_item;
typedef struct Hashtable Hashtable;
using namespace std;

unsigned long hash_function(char* str) {
    unsigned long i = 0;
    for (int j = 0; str[j]; j++)
        i += str[j];
    return i % CAPACITY;
}

typedef struct Ht_item Ht_item;


struct Ht_item {
    char* key;
    char* value;
};

typedef struct HashTable HashTable;


struct HashTable {
    
    Ht_item** items;
    int size;
    int count;
};

Ht_item* create_item(char* key, char* value) {
    
    Ht_item* item = (Ht_item*)malloc(sizeof(Ht_item));
    item->key = (char*)malloc(strlen(key) + 1);
    item->value = (char*)malloc(strlen(value) + 1);

    strcpy(item->key, key);
    strcpy(item->value, value);

    return item;
}

HashTable* create_table(int size) {
    
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (Ht_item**)calloc(table->size, sizeof(Ht_item*));
    for (int i = 0; i < table->size; i++)
        table->items[i] = NULL;

    return table;
}

void free_item(Ht_item* item) {
    
    free(item->key);
    free(item->value);
    free(item);
}

void free_table(HashTable* table) {
    
    for (int i = 0; i < table->size; i++) {
        Ht_item* item = table->items[i];
        if (item != NULL)
            free_item(item);
    }

    free(table->items);
    free(table);
}

void handle_collision(HashTable* table, unsigned long index, Ht_item* item) {
}

void ht_insert(HashTable* table, char* key, char* value) {
    
    Ht_item* item = create_item(key, value);

    
    unsigned long index = hash_function(key);

    Ht_item* current_item = table->items[index];

    if (current_item == NULL) {
        
        if (table->count == table->size) {
            
            printf("Insert Error: Hash Table is full\n");
            
            free_item(item);
            return;
        }

        
        table->items[index] = item;
        table->count++;
    }

    else {
        
        if (strcmp(current_item->key, key) == 0) {
            strcpy(table->items[index]->value, value);
            return;
        }

        else {
            
            handle_collision(table, index, item);
            return;
        }
    }
}

char* ht_search(HashTable* table, char* key) {
    
    int index = hash_function(key);
    Ht_item* item = table->items[index];

    
    if (item != NULL) {
        if (strcmp(item->key, key) == 0)
            return item->value;
    }
    return NULL;
}

void print_search(HashTable* table, char* key) {
    char* val;
    if ((val = ht_search(table, key)) == NULL) {
        printf("Key:%s does not exist\n", key);
        return;
    }
    else {
        printf("Key:%s, Value:%s\n", key, val);
    }
}

void print_table(HashTable* table) {
    printf("\nHash Table\n-------------------\n");
    for (int i = 0; i < table->size; i++) {
        if (table->items[i]) {
            printf("Index:%d, Key:%s, Value:%s\n", i, table->items[i]->key, table->items[i]->value);
        }
    }
    printf("-------------------\n\n");
}

int RNG()
{
    int x;
    x = rand() % 100;
    return x;
}

int Problema1(int x)
{
    HashTable* ht = create_table(CAPACITY);
    stringstream ss;
    int i;
    stack <int> Stack1;
    cout << "==================================== \n";
    cout << "\n";
    cout << "Introduzca cuantos numeros quiere: \n";
    cin >> i;
    cout << "Estos son los numeros generados: \n";
    for (int j = 0; j < i; j++)
    {
        RNG();
        Stack1.push(x);
        cout << x << "\n";
        
    }
    
    
}

void Menu()
{
    cout << "Ingrese 1 para el problema 1 y 2 para ir al problema 2 \n";
    cout << "\n";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:

        break;
    case 2:

        break;
    default:
        cout << "ingrese un numero valido";
        Menu();
        break;
    }
}

int main()
{
    cout << "Lab 7 :)";
    cout << ":)";
}

