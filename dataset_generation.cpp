#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
namespace fs = std::filesystem;

int main()
{
    std::vector<std::string> path_vector;
    std::string path = "/home/rushabh/working_dir/uni_bonn_cpp_tutorial/fifth_lecture/homework_3/web_app/data/";
    for (const auto & entry : fs::directory_iterator(path))
        {
            path_vector.push_back(entry.path());
        }
    
    for (int i = 0; i< path_vector.size(); i++)
    {
        std::cout << path_vector[i] <<std::endl;
    }    
}