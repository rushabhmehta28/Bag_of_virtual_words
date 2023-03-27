#include<iostream>
#include<string>
#include "html_writer.hpp"
#include "image_browser.hpp"
#include<vector>
#include <tuple>
#include <array>

void image_browser::CreateImageBrowser(const std::string& title, const std::string& stylesheet,
                        const std::vector<ImageRow>& rows) {
    html_writer::OpenDocument();
    html_writer::AddTitle(title);
    html_writer::AddCSSStyle(stylesheet);
    html_writer::OpenBody();
    for (int i = 0 ; i < rows.size(); i++){
        if (i == 0) {
            image_browser::AddFullRow(rows[i], true);
        }
        else{
        image_browser::AddFullRow(rows[i], false);
        }
    }
    html_writer::CloseBody();
    html_writer::CloseDocument();
                        }