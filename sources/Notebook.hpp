#pragma once
#include "Direction.hpp"
#include <string>
using namespace std;
#include <iostream>
#include <unordered_map>
#include <array>

namespace ariel {
    class Notebook
    {
    private:
        unordered_map <int ,unordered_map <int , char[100]>> _map;
    public:
        string read(int page, int row, int column,Direction direction, int length);
        
        void write(int page, int row, int column,Direction direction, string str);

        void erase(int page, int row, int column,Direction direction, int length);

        void show(int page);
    };

}
