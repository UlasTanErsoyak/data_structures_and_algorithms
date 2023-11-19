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
            node* current=this->head;
            while (current!=nullptr) {
                node* next=current->next;
                free(current);
                current=next;
            }
        }
        T& operator[](std::uint32_t idx){
            if(idx>=this->size){
                throw std::runtime_error("index out of range");
            }
            node* current=this->head;
            for(int i=0;i<idx;i++){
                current=current->next;
            }
            return current->data;
        }
        void insert(T data,std::uint32_t idx){
            if(idx==0){
                this->push_head(data);
                return;
            }
            node* new_node=static_cast<node*>(malloc(sizeof(node)));
            new_node->data=data;
            new_node->prev=nullptr;
            node* current=this->head;
            if(idx>=this->size){
                this->tail=new_node;
                idx=this->size;
            }
            for(auto i=1;i<=idx-1;++i){
                current=current->next;
            }
            new_node->next=current->next;
            current->next=new_node;
            if(this->is_doubly){
                new_node->prev=current;
            }
            if(this->is_circular&&idx==this->size){
            }
            this->size++;
        }
        void push_head(const T data){
            node* new_head=static_cast<node*>(malloc(sizeof(node)));
            new_head->data=data;
            new_head->prev=nullptr;
            new_head->next=this->head;
            this->head=new_head;
            this->size++;
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
            if(this->is_circular){
                this->tail->next=nullptr;
                if(this->is_doubly){
                    this->head->prev=nullptr;
                }
            this->is_circular=false;
            }
        }
        void make_circular(){
            if(!this->is_circular){
                this->tail->next=this->head;
                if(this->is_doubly){
                        this->head->prev=this->tail;
                }
            this->is_circular=true;
            }
        }
        void make_singly(){
            if(this->is_doubly){
                node* current = this->head;
                while(current!=this->tail){
                    current->next->prev=nullptr;
                    current=current->next;
                }
                if(this->is_circular){
                    this->head->prev=nullptr;
                }
                this->is_doubly=false;
            }
        }
        void make_doubly(){
            if(!this->is_doubly){
                node* current = this->head;
                while(current!=this->tail){
                    current->next->prev=current;
                    current=current->next;
                }
                if(this->is_circular){
                    this->head->prev=this->tail;
                }
                this->is_doubly=true;
            }
        }
        void reverse() {
            node* prev=nullptr;
            if (this->is_circular){
                node* current=this->head;
                node* next_node;
                do {
                    next_node=current->next;
                    current->next=prev;
                    prev=current;
                    current=next_node;
                } while (current!=this->head);
                this->head->next=prev;
            }else{
                node* prev=nullptr;
                node* current=this->head;
                node* next_node;
                while (current!=nullptr){
                    next_node=current->next;
                    current->next=prev;
                    if (this->is_doubly){
                        current->prev=next_node;
                    }
                    prev=current;
                    current=next_node;
                }
            }
            this->tail=this->head;
            this->head=prev;
        }
        T& pop_head(){
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
            this->size--;
            node* prev_head=this->head;
            this->head=this->head->next;
            free(prev_head);
            return rs;
        }
        T& peek_head(){
            return this->head->data;
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