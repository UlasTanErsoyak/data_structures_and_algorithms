#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
std::string read_from_file(std::string path){
    if(path.substr(path.length() - 3) != ".sg"){
        return "";
    }
    std::ifstream f(path);
    std::string str;
    if(f){
       std::ostringstream ss;
       ss << f.rdbuf();
       str = ss.str();
    } 
    return str;
}
