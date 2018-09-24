//
// Created by ren on 24.9.2018.
//

#ifndef PROGRESSBARLAB_MODEL_H
#define PROGRESSBARLAB_MODEL_H

#include <list>
#include "Subject.h"
#include <fstream>
#include <string>
#include <vector>

class Model: public Subject {
public:
    ~Model(){
        for(auto obs:observers){
            removeObserver(obs);
        }
    }

    int getFilesSize();

    std::vector<std::string> readFiles();

    void addFile(std::string filePath);

    virtual void addObserver(Observer* o) override;
    virtual void removeObserver(Observer* o) override;
    virtual void notify(int i) override;

private:
    int totFileSize = 0;
    std::vector<std::string> files;
    std::list<Observer*> observers;
};


#endif //PROGRESSBARLAB_MODEL_H
