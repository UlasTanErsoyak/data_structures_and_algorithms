#pragma once
#include <cstdint>
#include <stdexcept>
#include <cmath>
#include "array.hh"
class string{
    private:
        array<char> chars;
    public:
        string(){}
        string(const char* str){
            std::uint32_t idx=0;
            while(str[idx]!='\0'){
                idx++;
            }
            this->chars.reserve_space(idx+1);
            for (std::uint32_t i=0;i<idx;i++) {
                this->chars.push_back(str[i]);
            }
            this->chars.push_back('\0');
        }
        bool operator==(string& other){
            if(this->chars.get_size()!=other.chars.get_size()){
                return false;
            }
            for(auto i=0;i<this->chars.get_size();i++){
                if(this->chars[i]!=other.chars[i]){
                    return false;
                }
            }
            return true;
        }
        char operator[](std::uint32_t idx){
            return this->chars[idx];
        }
        bool operator!=(string& other){
            return !(this->chars==other.chars);
        }
        string operator+(string& other){
            string result=*this;
            result.chars.concat(other.chars);
            return result;
        }
        void reserve_space(std::uint32_t new_size){
            this->chars.reserve_space(new_size);
        }
        void shrink_to_fit(){
            this->chars.shrink_to_fit();
        }
        void change(char data,std::uint32_t idx){
            this->chars.change(data,idx);
        }
        string substring(std::uint32_t start_idx,std::uint32_t length) {
            string result;
            result.chars.reserve_space(length+1);
            for (auto i=0;i<length;i++) {
                result.chars.push_back(this->chars[start_idx+i]);
            }
            result.chars.push_back('\0');
            return result;
        }
        std::uint32_t get_size(){
            return this->chars.get_size();
        }
        std::uint32_t get_byte_size(){
            return this->chars.get_byte_size();
        }
        std::uint32_t parse(){
            std::uint32_t size=this->chars.get_size();
            std::uint32_t rs=0;
            for(auto i=0;i<size-1;i++){
                if(!isdigit(this->chars[i])){
                    return 0;
                }
                rs = rs * 10 + (this->chars[i] - 48);
            }
            return rs;
        }
        bool is_palindrome(){
            std::uint32_t end_idx=this->chars.get_size()-2;
            std::uint32_t mid_idx=end_idx/2;
            for(auto i=0;i<=mid_idx;i++){
                if(this->chars[i]!=this->chars[end_idx]){
                    return false;
                }
                end_idx--;
            }
            return true;
        }
        void to_upper(){
            for(auto i=0;this->chars[i]!='\0';i++){
                this->chars[i]=this->chars[i]&~32;
            }
        }
        void to_lower(){
            for(auto i=0;this->chars[i]!='\0';i++){
                this->chars[i]=this->chars[i]|32;
            }
        }
        void trim_left(){
            std::uint32_t idx=0;
            while (this->chars[idx]!='\0'&&std::isspace(this->chars[idx])) {
                idx++;
            }
            if (idx>0){
                for(std::uint32_t i=0;i<=this->chars.get_size()-idx;i++) {
                    this->chars[i]=this->chars[i+idx];
                }
            }
        }
        void trim_right(){
            std::uint32_t idx=this->chars.get_size()-2;
            while (idx>=0&&std::isspace(this->chars[idx])){
                idx--;
            }
            this->chars[idx + 1] = '\0';
        }
        void trim(){
            trim_left();
            trim_right();
        }
};