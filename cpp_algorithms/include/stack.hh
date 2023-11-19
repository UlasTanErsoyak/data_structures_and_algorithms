#pragma once
#include <cstdint>
#include <stdexcept>
#include "array.hh"
template <typename T>
class stack{
    private:
        std::uint32_t top;
        std::uint32_t size;
        array<T> stack_container;
    public:
        stack(){
            this->top=-1;
        }
        stack(const std::uint32_t size){
            this->stack_container.reserve_space(size);
            this->top=0;
            this->size=size;
        }
        stack(const array<T>& init_array){
            for(auto i=0;i<init_array.get_size();i++){
                this->stack_container[i]=init_array[i];
                this->top++;
                this->size++;
            }
        }
        void push(const T& data){
            if(this->top>this->size-1){
                throw std::runtime_error("stack overflow");
            }
            this->stack_container.push_back(data);
            top++;
        }
        T pop(){
            if(this->top==-1){
                throw std::runtime_error("cant pop from an empty stack");
            }
            top--;
            return this->stack_container.pop_back();
        }
        bool is_full(){
            return this->size==this->top;
        }
        bool is_empty(){
            return this->top==0;
        }
        T peek(){
            if(this->top==-1){
                throw std::runtime_error("cant peek an empty stack");
            }
            return this->stack_container.pop_back();
        }
};