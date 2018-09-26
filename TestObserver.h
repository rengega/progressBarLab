//
// Created by ren on 26.9.2018.
//

#ifndef PROGRESSBARLAB_TESTOBSERVER_H
#define PROGRESSBARLAB_TESTOBSERVER_H

#include "Observer.h"

class TestObserver: public Observer{
public:
    virtual void update(int i){
        testResult += i;
    }
    int getTestResult(){
        return testResult;
    }

private:
    int testResult = 0;
};

#endif //PROGRESSBARLAB_TESTOBSERVER_H
