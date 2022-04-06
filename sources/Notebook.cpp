#include "Direction.hpp"
#include "Notebook.hpp"
#include <iostream>
using namespace std;
#include <string>
#include <stdexcept>
#include <tuple>

string ariel::Notebook:: read(int page, int row, int column,ariel::Direction direction, int length){
    const int len_max = 100;
    const int min_char = 32;
    const int max_char = 126;
    string str;
    //wrong arguments
    if (column < 0 || column > len_max-1|| row < 0 || page < 0 || length < 0) {
        throw invalid_argument("negative variables");
    }
    //wrong varibelse
    if(Direction::Horizontal == direction && (length + column) > len_max) {
        throw invalid_argument("out of column!");
    }

    if (direction == Direction::Horizontal){
        if((column + length) > len_max){
            throw invalid_argument("length out of line");
        }
        //add char to the str to read
        for(int i = column ; i < (column + length); i++){
            if(_maping[page][row][i] >= min_char && _maping[page][row][i] <= max_char){
                str += _maping[page][row][i];
            }
            else{
                str += '_';
            }
        }
    }
    if (direction == Direction::Vertical){
         //add char to the str to read
        for(int i = row ; i < (row + length); i++){
            if(_maping[page][i][column] >= min_char && _maping[page][i][column] <= max_char){
                str += _maping[page][i][column];
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
        throw invalid_argument("negative variables");
    }
    //the char is illeagal
     for (int i = 0; i < len_word; ++i) {
        if (str[(unsigned int)i] < min || str[(unsigned int)i] > max) {
            throw invalid_argument("The character is invalid");
        }
    }
    if (direction == Direction::Horizontal){
        if(len_word + column > len_max){
            throw invalid_argument("out of line-length");
        }
        for(int i= column ; i < (column + len_word); i++){
            if(_maping[page][row][i] == '~'){
                throw invalid_argument("deleted line");
            }
            if(_maping[page][row][i] >= min && _maping[page][row][i] <= max){
                if(_maping[page][row][i] == '_'){
                    // _maping[page][row][i] = str[(unsigned int)(i-column)];
                    _maping.insert((pair<int,char>(i,str[(unsigned int)(i-column)])));
                }
                else{
                    throw invalid_argument("we have allready write");
                }
            }
            else{
                _maping[page][row][i] = str[(unsigned int)(i-column)];
            }
        }
    }

    if (direction == Direction::Vertical){
        
        for(int i= row ; i < (row +len_word); i++){
            if(_maping[page][i][column] == '~'){
                throw runtime_error("deleted line");
            }
            if(_maping[page][i][column] >= min && _maping[page][i][column] <= max){
                if(_maping[page][i][column] == '_'){
                    // _maping[page][i][column] = str[(unsigned int)(i-row)];
                    _maping.insert((pair<int,char>(i,str[(unsigned int)(i-column)])));
                }
                else{
                    throw runtime_error("we have allready write");
                }
            }
            else{
                _maping[page][i][column] = str[(unsigned int)(i-row)];
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
            throw runtime_error("out of line-length");
        }
        for(int i= column ; i < (column + length); i++){
            _maping[page][row][i] = '~';
        }
    }
    else{
        for(int i= row ; i < (row + length); i++){
            _maping[page][i][column] = '~';
        }
    }

}

void ariel::Notebook::show(int page){
    if(page < 0){
        throw runtime_error("negative page");
    }
    cout << _maping[page][0][0] << "\n show notebook"<<endl;
    
}
