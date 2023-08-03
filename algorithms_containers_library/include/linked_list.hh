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
        };
        bool is_doubly;
        bool is_circular;
        node* head;
        node* tail;
        std::uint32_t size;

    public:
        linked_list(){
            this->head=nullptr;
            this->tail=nullptr;
            this->size=0;
            this->is_doubly=false;
            this->is_circular=false;
        }
        ~linked_list(){
            //TODO
        }
        void push_head(T data){
            node* new_head=static_cast<node*>(malloc(sizeof(node)));
            new_head->data=data;
            new_head->prev=nullptr;
            new_head->next=this->head;
            this->head=new_head;
            this->size+=1;
            if(this->size==1){
                this->tail=this->head;
            }
            if(this->is_doubly){
                node* current=this->head;
                while(current!=this->tail){
                    if(current->next->prev==nullptr){
                    current->next->prev=current;
                    }
                    current=current->next;
                }
            }
            if(this->is_circular){
                this->head->prev=this->tail;
                this->tail->next=this->head;
                this->head->next->prev=this->head;
            }
        }
        void make_linear(){
            if(this->is_doubly){
                node* current=this->head;
                while(current!=this->tail){
                    this->next->prev=nullptr;
                    current=current->next;
                }
            }
        }
        T pop_head(){
            if(this->size==0){
                throw std::runtime_error("cant pop an empty linked list");
            }
            T rs = this->head->data;
            if(this->is_circular){
                this->tail->next=this->head->next;
                if(this->is_doubly){
                    this->head->next->prev=this->tail;
                }
            }else{
                if(this->head->next!=nullptr){
                    this->head->next->prev=nullptr;
                }
            }
            this->size-=1;
            node* prev_head=this->head;
            this->head=this->head->next;
            free(prev_head);
            return rs;
        }
        std::uint32_t get_size(){
            return this->size;
        }
        std::uint32_t get_byte_size(){
            return this->size*sizeof(node);
        }
        bool is_empty(){
            return this->size==0;
        }

};