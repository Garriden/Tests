#include <filesystem>
#include <fstream>

int main()
{
    std::filesystem::path path{"."};
    path /= "bones.txt"; //put something into there
    std::filesystem::create_directories(path.parent_path()); //add directories based on the object path.

    std::ofstream ofs(path);
    ofs << "this is some text in the new file\n"; 
    ofs.close();

    return 0;
}