#include<iostream>
#include<string>
#include "html_writer.hpp"
#include "image_browser.hpp"
#include<vector>
#include <array>
#include <tuple>
using namespace html_writer;

void image_browser::AddFullRow(const ImageRow& row, bool first_row) {
   OpenRow();
   for (int i = 0; i < 3; i++) {
    if (i == 0 && first_row == true){
        AddImage(std::get<0>(row[i]), std::get<1>(row[i]), true );
    } else {
    AddImage(std::get<0>(row[i]), std::get<1>(row[i]), false );
   }  
   } 
   CloseRow();
}