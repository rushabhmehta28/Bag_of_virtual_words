#include<iostream>
#include "html_writer.hpp"

void html_writer::AddTitle(const std::string& title) {
    std::cout <<"<title>"<< title <<"</title>" <<std::endl;
}