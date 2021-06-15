#include <string>
#include <cstring>
#include <iostream>

int main(int argc, char *argv[]) {
    std::string fileName = std::string(argv[1]) + ".cpp";
    char compileCommand[fileName.length() + 11] = "g++ ";
    strcat(compileCommand, "codes/");
    for(int i = 0; i < fileName.length(); ++i) compileCommand[i+10] = fileName[i];
    std::cout << compileCommand;
    system(compileCommand);
    system("./a.out");

    return 0;
}
