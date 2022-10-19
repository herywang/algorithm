#include <unistd.h>
#include "threadpool.h"

class my_runnable : public runnable {
public:
    my_runnable() {
    }

    void run() override {
        std::cout << "hello runnable" << std::endl;
        sleep(3);
    }
};

int main() {
    threadpool *pool = new threadpool(3, 10);
    for (int i = 0; i < 4; i++) {
        std::shared_ptr<runnable> task(new my_runnable());
        pool->append(task);
    }
    sleep(20);
    delete pool;
    return 0;
}