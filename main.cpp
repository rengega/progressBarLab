#include <iostream>
#include "Model.h"

int main() {
    Model* myModel;
    myModel = new Model;

    myModel->addFile("/home/ren/CLionProjects/untitled/res/text1");
    myModel->addFile("/home/ren/CLionProjects/untitled/res/text1.1");
    std::cout<<myModel->getFilesSize();
    std::list<std::string>myContents = myModel->readFiles();
    for (auto i : myContents) {
        std::cout<<i<<std::endl;
    }
    return 0;
}