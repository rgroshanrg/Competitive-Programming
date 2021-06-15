#include <iostream>
#include <fstream>
#include <string>
int main(int argc, char *argv[]) {
    
    std::string CodeFileName = "./codes/" + std::string(argv[1]) + ".cpp";

    std::ifstream model;
    model.open("./builts/model.cpp", std::ios::in);
    if(!model) {
        std::cout << "Model file doesn't exists"; exit(0);
    }

    std::ofstream CodeFile;
    CodeFile.open(CodeFileName, std::ios::out);
    if(!CodeFile) {
        std::cout << "Code File is unable to Create"; exit(0);
    }

    std::string line;
    while(getline(model, line)) {
        CodeFile << line <<"\n";
    }

    std::cout << "Start Coding, File Created : " << CodeFileName << "\n";

    CodeFile.close();
    model.close();
    return 0;
}