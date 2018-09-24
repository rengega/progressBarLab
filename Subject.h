//
// Created by ren on 24.9.2018.
//

#ifndef PROGRESSBARLAB_SUBJECT_H
#define PROGRESSBARLAB_SUBJECT_H

#include "Observer.h"

class Subject{
public:
    virtual ~Subject(){}
    virtual void notify(int i) = 0;
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer *o) = 0;
};
#endif //PROGRESSBARLAB_SUBJECT_H
