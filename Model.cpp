//
// Created by ren on 24.9.2018.
//

#include "Model.h"
#include <fstream>
#include <iostream>

void Model::addObserver(Observer *o) {
    observers.push_back(o);
}

void Model::removeObserver(Observer *o) {
    observers.remove(o);
}

void Model::notify(int i) {
    for(Observer* observer : observers){
        observer->update(i);
    }
}

void Model::addFile(std::string filePath) {
    files.push_back(filePath);
    std::fstream myFile(filePath);
    myFile.seekg(0, std::ios::end);
    totFileSize += myFile.tellg();
    myFile.clear();
    myFile.seekg(0, std::ios::beg);

}

int Model::getFilesSize() {
    return totFileSize;
}

std::list<std::string> Model::readFiles() {
    std::list<std::string> myContents;
    for (std::string myFilePath: files) {
        std::fstream myFile(myFilePath);
        if (myFile.is_open()){
            std::string myContent="";
            std::string myLine;
            while (!myFile.eof()){
                getline(myFile, myLine);
                myContent += '\n';
                myContent += myLine;
            }
            myContents.push_back(myContent);
        }

    }
    return myContents;
}

