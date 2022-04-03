/**
 *
 * AUTHORS: amit ginzberg
 * 
 * Date: 2021-03
 */

#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using namespace ariel;
using ariel::Direction;


TEST_CASE("check throw-illeagal input") {
	Notebook note;
	CHECK_THROWS(note.read(-10, -5, -5, Direction::Vertical,3));
	CHECK_THROWS(note.read(-1, -2, -5, Direction::Vertical,3));
	CHECK_THROWS(note.read(-1, -5, 0, Direction::Vertical,3));
	CHECK_THROWS(note.read(-5, -5, -5, Direction::Vertical,30));
	CHECK_THROWS(note.read(-6, -2, -5, Direction::Vertical,30));
	CHECK_THROWS(note.read(-7, -8, 0, Direction::Vertical,30));
}
TEST_CASE("check throw-illeagal input") {
	Notebook note;
	CHECK_THROWS(note.write(-10, -5, -5, Direction::Vertical,"3"));
	CHECK_THROWS(note.write(-1, -2, -5, Direction::Vertical,"3"));
	CHECK_THROWS(note.write(-1, -5, 0, Direction::Vertical,"3"));
	CHECK_THROWS(note.write(-5, -5, -5, Direction::Vertical,"30"));
	CHECK_THROWS(note.write(-6, -2, -5, Direction::Vertical,"30"));
	CHECK_THROWS(note.write(-7, -8, 0, Direction::Vertical,"30"));
	
	
}

TEST_CASE("check throw-illeagal input") {
	Notebook note;
	CHECK_THROWS(note.erase(-10, -5, -5, Direction::Vertical,3));
	CHECK_THROWS(note.erase(-1, -2, -5, Direction::Vertical,3));
	CHECK_THROWS(note.erase(-1, -5, 0, Direction::Vertical,3));
	CHECK_THROWS(note.erase(-5, -5, -5, Direction::Vertical,30));
	CHECK_THROWS(note.erase(-6, -2, -5, Direction::Vertical,30));
	CHECK_THROWS(note.erase(-7, -8, 0, Direction::Vertical,30));
	
	
}
TEST_CASE("Good input"){
	Notebook note;
	CHECK_NOTHROW(note.read(10, 5, 5, Direction::Vertical,3));
	CHECK_NOTHROW(note.read(1, 2, 5, Direction::Vertical,3));
	CHECK_NOTHROW(note.read(1, 5, 0, Direction::Vertical,3));
	CHECK_NOTHROW(note.read(5, 5, 5, Direction::Vertical,30));
	CHECK_NOTHROW(note.read(6, 2, 5, Direction::Vertical,30));
	CHECK_NOTHROW(note.read(7, 8, 0, Direction::Vertical,30));
	
}
TEST_CASE("Good input") {
	Notebook note;
	CHECK_NOTHROW(note.write(10, 5, 5, Direction::Vertical,"3"));
	CHECK_NOTHROW(note.write(1, 2, 5, Direction::Vertical,"3"));
	CHECK_NOTHROW(note.write(1, 5, 0, Direction::Vertical,"3"));
	CHECK_NOTHROW(note.write(5, 5, 5, Direction::Vertical,"30"));
	CHECK_NOTHROW(note.write(6, 2, 5, Direction::Vertical,"30"));
	CHECK_NOTHROW(note.write(7, 8, 0, Direction::Vertical,"30"));
	
	
}
TEST_CASE("Good input") {
	Notebook note;
	CHECK_NOTHROW(note.erase(7, 8, 0, Direction::Vertical,30));
	CHECK_NOTHROW(note.erase(7, 9, 15, Direction::Vertical,30));
	CHECK_NOTHROW(note.erase(7, 2, 0, Direction::Vertical,30));
	CHECK_NOTHROW(note.erase(2, 8, 5, Direction::Vertical,30));
	CHECK_NOTHROW(note.erase(1, 8, 6, Direction::Vertical,30));
	
}
TEST_CASE("erase-again") {
	Notebook note;
	note.write(1, 1, 1, Direction::Vertical,"1");
	note.write(2, 2, 2, Direction::Vertical,"1");
	note.write(3, 3, 3, Direction::Vertical,"1");
	note.write(4, 4, 4, Direction::Vertical,"1");
	note.write(5, 5, 5, Direction::Vertical,"1");
	note.write(6, 6, 6, Direction::Vertical,"1");
	note.erase(1, 1, 1, Direction::Vertical,1);
	note.erase(2, 2, 2, Direction::Vertical,1);
	note.erase(3, 3, 3, Direction::Vertical,1);
	note.erase(4, 4, 4, Direction::Vertical,1);
	note.erase(5, 5, 5, Direction::Vertical,1);
	note.erase(6, 6, 6, Direction::Vertical,1);
	for(int i = 1 ; i <=6 ; i++){
		CHECK_THROWS(note.erase(i, i, i, Direction::Vertical,1));
	}
}
TEST_CASE("worng input") {
	Notebook note;
 	note.write(58, 80, 6, Direction::Horizontal, "amit");                             
    note.write(58, 81, 4, Direction::Horizontal, "ginz");                             
    note.write(58, 82, 4, Direction::Horizontal, "mira");
	note.write(58, 83, 4, Direction::Horizontal, "mira");
   
    CHECK(note.read(58, 80, 6, Direction::Horizontal, 4) == "amit"); 
    CHECK(note.read(58, 81, 4, Direction::Horizontal, 4) == "ginz"); 
    CHECK(note.read(58, 82, 4, Direction::Horizontal, 4) == "mira");
	CHECK(note.read(58, 83, 4, Direction::Horizontal, 5) == "shaul");

	CHECK_FALSE(note.read(58, 80, 6, Direction::Horizontal, 4) == "aaaa"); 
    CHECK_FALSE(note.read(58, 81, 4, Direction::Horizontal, 4) == "gggg"); 
    CHECK_FALSE(note.read(58, 82, 4, Direction::Horizontal, 4) == "nmmmm");
	CHECK_FALSE(note.read(58, 83, 4, Direction::Horizontal, 5) == "gggg");
}