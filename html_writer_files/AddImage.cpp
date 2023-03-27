#include<iostream>
#include<filesystem>
#include "html_writer.hpp"
#include<string>

void html_writer::AddImage(const std::string& img_path, float score, bool highlight) {
    if(highlight){
        std::cout <<"<div class= \"column\" style=\"border: 5px solid green;\">" <<std::endl;
    }
    else {
        std::cout <<"<div class= \"column\">" <<std::endl;
    }
    std::cout <<"<h2>"<< std::filesystem::path(img_path).filename() <<"</h2>" <<std::endl;
    std::cout <<"<img src="<< std::filesystem::path(img_path) <<" />" <<std::endl;
    std::cout <<"<p>"<<"score = " <<score <<"</p>" <<std::endl;
    std::cout <<"</div>" <<std::endl;
}