#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dict_len 10
#define key_len 256

struct element{
    char key[key_len];
    int value;
    struct element* next;
};

struct element* hashmap[dict_len];
int hash_fn(char* str);
void insert(char* key,int value);
int get_value_with_key(char* key);

void init_map();
int main(){
    init_map();

    insert("some", 1);
    insert("random", 2);
    insert("text", 3);
    printf("value->%d key->%s\n",get_value_with_key("text"),"text");
    // insert("qqqqqq", 4);
    // insert("adasfga", 1323);
    // insert("randomtextt", 35);
    // insert("afdagafa", 35);

    for (int i = 0; i < dict_len; i++) {
        struct element* current = hashmap[i];
        printf("index %d: ", i);
        while (current != NULL) {
            printf("(%s, %d) ", current->key, current->value);
            current = current->next;
        }
        printf("\n");
    }

    return 0;
}

void init_map(){
    for(int i=0;i<dict_len;i++){
        hashmap[i]=NULL;
    }
}

int hash_fn(char* str){
    int hash=0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash += (int)str[i];  
    }
    return hash%dict_len;
}

void insert(char* key,int value){
    int idx = hash_fn(key);
    struct element* new_element = malloc(sizeof(struct element));
    new_element->value = value;
    strcpy(new_element->key, key);
    new_element->next = NULL;
    if(hashmap[idx]==NULL){
        hashmap[idx]=new_element;
    }
    else{
        struct element* current = hashmap[idx];
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=new_element;
    }
}

int get_value_with_key(char* key){
    int idx = hash_fn(key);
    if(hashmap[idx]==NULL){
        printf("%s key doesnt exists in hashmap",&key);
        return -1;
    }
    else{
        struct element* current = hashmap[idx];
        while(1){
            if(strcmp(current->key,key)==0){
                return current->value;
            }
            current=current->next;
        }
    }
}

