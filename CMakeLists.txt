cmake_minimum_required(VERSION 3.1)
project(bag_of_virtual_word_html)

set (CMAKE_CXX_FLAGS "-lstdc++fs -std=c++17")

include_directories(.)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_library(html_writer html_writer_files/AddCSSStyle.cpp html_writer_files/AddImage.cpp html_writer_files/AddTitle.cpp html_writer_files/CloseBody.cpp html_writer_files/CloseDocument.cpp html_writer_files/CloseRow.cpp html_writer_files/OpenBody.cpp html_writer_files/OpenDocument.cpp html_writer_files/OpenRow.cpp)
add_library(image_browser image_browser_files/CreateImageBrowser.cpp image_browser_files/AddFullRow.cpp)
add_executable(bag_of_virtual_word main.cpp)
target_link_libraries(image_browser html_writer)
target_link_libraries(bag_of_virtual_word image_browser html_writer ${OpenCV_LIBS})
