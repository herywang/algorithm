#ifndef RUNNABLE_H
#define RUNNABLE_H
#include <iostream>
class runnable {
public:
    virtual void run() = 0;
    ~runnable() {
        std::cout << "destroy runnable object" << std::endl;
    }
};
#endif