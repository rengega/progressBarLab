//
// Created by ren on 24.9.2018.
//

#ifndef PROGRESSBARLAB_OBSERVER_H
#define PROGRESSBARLAB_OBSERVER_H


class Observer{
public:
    virtual ~Observer(){}
    virtual void update(int i) = 0;
};


#endif //PROGRESSBARLAB_OBSERVER_H
