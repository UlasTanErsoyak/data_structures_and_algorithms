#pragma once
#include <cstdint>
#include <stdexcept>
template <typename T>
class array{
    private:
        std::uint32_t size;
        std::uint32_t contains;
        T* head;
        public:
            array(std::uint32_t len){
                this->contains = 0;
                this->size = len;
                this->head = static_cast<T*>(malloc(len * sizeof(T)));
                if(this->head==nullptr){
                    throw std::runtime_error("memory allocation failed");
                }
            }
            ~array(){
                free(this->head);
            }
            T& operator[](const std::uint32_t idx){
                if(idx>this->size){
                    throw std::runtime_error("index out of bounds.");
                }
                return *(head + idx);
            }
            std::uint32_t get_size(){
                return this->size;
            }
            std::uint32_t get_byte_size(){
                return (this->size* sizeof(T));
            }
            void push_back(T data){
                if(contains==size){
                    throw std::runtime_error("overflow");
                }
                *(this->head+contains) = data;
                contains+=1;
            }
            void insert(T data, std::uint32_t idx){
                if(idx>this->size){
                    throw std::runtime_error("cant append to an index that is bigger than array size");
                }
                if(idx!=this->contains+1){
                    *(this->head+contains+1) = data;
                    contains+=1;
                }else{
                    *(this->head+idx) = data;
                }
            }
            void clear(){
                free(this->head);
                this->head = nullptr;
                this->size = 0;
                this->contains = 0;
            }
            void shrink_to_fit(){
                if (contains < size) {
                    T* new_head = static_cast<T*>(malloc(contains * sizeof(T)));
                    if (new_head == nullptr) {
                        throw std::runtime_error("memory allocation failed");
                    }
                    for (auto i = 0; i < contains; ++i) {
                        new_head[i] = this->head[i];
                    }
                    free(this->head);
                    this->head = new_head;
                    this->size = contains;
                }
            }
            void reserve_space(std::uint32_t new_size){
                if(new_size<this->size){
                    throw std::runtime_error("use shrink_to_fit if you want to make the array smaller than the base array");
                }
                T* new_head = static_cast<T*>(malloc(new_size * sizeof(T)));
                if (new_head == nullptr) {
                        throw std::runtime_error("memory allocation failed");
                }
                for (auto i = 0; i < contains; ++i) {
                        new_head[i] = this->head[i];
                }
                free(this->head);
                this->head = new_head;
                this->size= new_size;
            }


            
};