#pragma once
#include <cstdint>
#include <stdexcept>
template <typename T>
class linked_list{
    private:
        struct node{
            T data;
            node* next;
            node* prev;
        }
        bool is_doubly;
        bool is_circular;
        node* head;
        std::uint32_t size;
    public:
        linked_list(){
            this->head=nullptr;
            this->size=0;
            this->is_doubly=false;
            this->is_circular=false;
        }
        linked_list(std::uint32_t len){
            this->head=static_cast<node*>(malloc(sizeof(node)));
            this->size=len;
            this->is_doubly=false;
            this->is_circular=false;
            node* current=this->head;
            for(auto i=1;i<len;i++){
                current->next=static_cast<node*>(malloc(sizeof(node)));
                current=current->next;
            }
        }
        
};