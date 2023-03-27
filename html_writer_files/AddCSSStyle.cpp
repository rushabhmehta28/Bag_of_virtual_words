#include<iostream>
#include "html_writer.hpp"

void html_writer::AddCSSStyle(const std::string& stylesheet) {
    std::cout <<"    <head>" << std::endl;
    std::cout <<"        <link rel=\"stylesheet\" type=\"text/css\" href=\"" << stylesheet <<"\" />" << std::endl;
    std::cout <<"    </head>"  << std::endl;
}