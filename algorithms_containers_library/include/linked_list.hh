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
            bool is_doubly;
            bool is_linked;
        }
        node* head;
        std::uint32_t size;
    public:
    //todo
};