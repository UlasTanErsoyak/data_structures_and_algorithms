#pragma once
#include <cstdint>
#include <stdexcept>
#include "array.hh"
#include "linked_list.hh"
template <typename T>
class hash_table{
    private:
        array<linked_list<T>> table;
        std::uint32_t _hash_function(T data){
        std::uint32_t rs=0;
        while (data != 0) {
            rs = rs + data % 10;
            data = data / 10;
        }
        return rs%this->table.get_size();
        };
    public:
        hash_table(std::uint32_t len){
            this->table.reserve_space(len);
            for(auto i=0;i<len-1;i++){
                this->table[i]=linked_list<T>();
            }
        }
        ~hash_table()=default;
        void append(T key,T value){
            auto idx=this->_hash_function(key);
            this->table[idx].push_head(value);
        }
        T operator[](T key){
            return this->table[this->_hash_function(key)][0];
        }

};