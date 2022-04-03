#include "Direction.hpp"
#include "Notebook.hpp"
#include <iostream>
using namespace std;
#include <string>
#include <stdexcept>

string ariel::Notebook:: read(int page, int row, int column,ariel::Direction direction, int length){
    const int len_max = 100;
    const int min_char = 32;
    const int max_char = 125;
    string str;
    //wrong arguments
    if (column < 0 || column > len_max-1|| row < 0 || page < 0 || length < 0) {
        throw runtime_error("negative variables");
    }
    //wrong varibelse
    if(Direction::Horizontal == direction && length + column > len_max) {
        throw invalid_argument("out of column!");
    }

    if (direction == Direction::Horizontal){
        if((column + length) > len_max){
            throw runtime_error("length out of line");
        }
        for(int i = column ; i < (column + length); i++){
            if(_map[page][row][i] >= min_char && _map[page][row][i] <= max_char+1){
                str += _map[page][row][i];
            }
            else{
                str += '_';
            }
        }
    }
    if (direction == Direction::Vertical){
        for(int i = row ; i < (row + length); i++){
            if(_map[page][i][column] >= min_char && _map[page][i][column] <= max_char+1){
                str += _map[page][i][column];
            }
            else{
                str += '_';
            }
        }
    }
    
    return str;
}

void ariel::Notebook::write(int page, int row, int column,ariel::Direction direction, string str){
    const int len_max = 100;
    const int min = 32;
    const int max = 125;
    int len_word = str.length();
    //wrong arguments
    if (column < 0 || column > len_max-1|| row < 0 || page < 0 || len_word < 0) {
        throw runtime_error("negative variables");
    }
    //the char is illeagal
     for (int i = 0; i < len_word; ++i) {
        if (str[(unsigned int)i] < min || str[(unsigned int)i] > max) {
            throw runtime_error("The character is invalid");
        }
    }
    if (direction == Direction::Horizontal){
        if(len_word + column > len_max){
            throw runtime_error("out of line");
        }
        for(int i= column ; i < column + len_word; i++){
            if(_map[page][row][i] == '~'){
                throw runtime_error("deleted line");
            }
            if(_map[page][row][i] >= min && _map[page][row][i] <= max){
                if(_map[page][row][i] == '_'){
                    _map[page][row][i] = str[(unsigned int)(i-column)];
                }
                else{
                    throw runtime_error("we have allready write");
                }
            }
            else{
                _map[page][row][i] = str[(unsigned int)(i-column)];
            }
        }
    }

    if (direction == Direction::Vertical){
        
        for(int i= row ; i < row +len_word; i++){
            if(_map[page][i][column] == '~'){
                throw runtime_error("deleted line");
            }
            if(_map[page][i][column] >= min && _map[page][i][column] <= max){
                if(_map[page][i][column] == '_'){
                    _map[page][i][column] = str[(unsigned int)(i-row)];
                }
                else{
                    throw runtime_error("we have allready write");
                }
            }
            else{
                _map[page][i][column] = str[(unsigned int)(i-row)];
            }
        }
    }
    
}


void ariel::Notebook:: erase(int page, int row, int column,ariel::Direction direction, int length){
    const int len_max = 100;
    //invaliad argument
    if (length < 0 || column < 0 || column > len_max-1|| row < 0 || page < 0) {
        throw invalid_argument(" negative variables!");
    }
    //invaliad argument
    if(Direction::Horizontal == direction && column + length > len_max) {
            throw invalid_argument("invalliad column!");
    }
    if (direction == Direction::Horizontal){
        if(length + column > len_max){
            throw runtime_error("out of line");
        }
        for(int i= column ; i < column + length; i++){
            _map[page][row][i] = '~';
        }
    }
    else{
        for(int i= row ; i < row + length; i++){
            _map[page][i][column] = '~';
        }
    }

}

void ariel::Notebook::show(int page){
    if(page < 0){
        throw runtime_error("negative page");
    }
    cout << _map[page][0][0] << "\n show page"<<endl;
    
}
