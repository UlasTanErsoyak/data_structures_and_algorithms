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
                this->contains=0;
                this->size=len;
                this->head=static_cast<T*>(malloc(len*sizeof(T)));
                if(this->head==nullptr){
                    throw std::runtime_error("memory allocation failed");
                }
            }
            array(array<T>& other){
                T* new_head = static_cast<T*>(malloc(other.size*sizeof(T)));
                for(auto i=0;i<other.contains;i++){
                    new_head[i]=other[i];
                }
                this->head=new_head;
                this->contains=other.contains;
                this->size=other.size;
            }
            ~array(){
                free(this->head);
            }
            T& operator[](const std::uint32_t idx){
                if(idx>this->size){
                    throw std::runtime_error("index out of bounds.");
                }
                return *(this->head+idx);
            }
            array<T>& operator=(const array<T>& other){
                if(this==&other){
                    return *this;
                }
                T* new_head = static_cast<T*>(malloc(other.size*sizeof(T)));
                for(auto i=0;i<other.contains;i++){
                    new_head[i]=other.head[i];
                }
                delete[] this->head;
                this->head=new_head;
                this->size=other.size;
                this->contains=other.contains;
                return *this;
            }
            bool operator==(array<T>& other){
                if(this->contains!=other.contains || this->size!=other.size){
                    return false;
                }
                for(auto i=0;i<other.size;i++){
                    if(this->head[i]!=other.head[i]){
                        return false;
                    }
                }
                return true;
            }
            bool operator!=(array<T>& other){
                return !(*this==other);
            }
            bool is_empty(){
                return this->head==nullptr;
            }
            std::uint32_t get_size(){
                return this->size;
            }
            std::uint32_t get_byte_size(){
                return (this->size*sizeof(T));
            }
            T* begin(){
                return *(head);
            }
            T* end(){
                return *(head+contains);
            }
            void push_back(const T data){
                if(contains==size){
                    throw std::runtime_error("overflow");
                }
                *(this->head+contains) = data;
                contains+=1;
            }
            T pop_back(){
                if(contains==0){
                    throw std::runtime_error("cant pop from an empty array");
                }
                contains-=1;
                return *(this->head[contains]);
            }
            void insert(const T data, const std::uint32_t idx){
                if(idx>this->size){
                    throw std::runtime_error("cant append to an index that is bigger than array size");
                }
                if(idx!=this->contains+1){
                    *(this->head+contains+1)=data;
                    contains+=1;
                }else{
                    *(this->head+idx)=data;
                }
            }
            void clear(){
                free(this->head);
                this->head=nullptr;
                this->size=0;
                this->contains=0;
            }
            void shrink_to_fit(){
                if (contains < size) {
                    T* new_head = static_cast<T*>(malloc(this->contains * sizeof(T)));
                    if (new_head == nullptr) {
                        throw std::runtime_error("memory allocation failed");
                    }
                    for (auto i=0;i<this->contains;++i) {
                        new_head[i]=this->head[i];
                    }
                    free(this->head);
                    this->head=new_head;
                    this->size=contains;
                }
            }
            void reserve_space(const std::uint32_t new_size){
                if(new_size<this->size){
                    throw std::runtime_error("use shrink_to_fit if you want to make the array smaller than the base array");
                }
                T* new_head=static_cast<T*>(malloc(new_size * sizeof(T)));
                if (new_head==nullptr) {
                        throw std::runtime_error("memory allocation failed");
                }
                for (auto i =0;i<this->contains;++i) {
                        new_head[i]=this->head[i];
                }
                free(this->head);
                this->head=new_head;
                this->size= new_size;
            }
};