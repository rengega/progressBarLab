#include <iostream>
#include "Model.h"

int main() {
    Model* myModel;
    myModel = new Model;

    myModel->addFile("/home/ren/CLionProjects/untitled/res/text1");
    myModel->addFile("/home/ren/CLionProjects/untitled/res/text1.1");
    std::cout<<myModel->getFilesSize();
    std::vector<std::string>myContents = myModel->readFiles();
    std::cout<<myContents[0];
    return 0;
}