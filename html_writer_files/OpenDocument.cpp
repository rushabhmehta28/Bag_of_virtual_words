#include<iostream>
#include "html_writer.hpp"
//using namespace html_writer;
void html_writer::OpenDocument() {
    std::cout << "<!DOCTYPE html>" <<std::endl;
    std::cout <<"<html>" <<std::endl;
}