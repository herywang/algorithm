/**
 * @file solution146.cpp
 * @author your name (you@domain.com)
 * @brief 设计LRU缓存
 * @version 0.1
 * @date 2022-08-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <unordered_map>

using namespace std;

struct DNode {
    int key;
    int val;
    DNode *prev;
    DNode *next;
    DNode(int key, int _val) {
        this->key = key;
        this->val = _val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache {
private:
    int capacity = 0;
    int count = 0;
    DNode *head = NULL;
    DNode *tail = NULL;
    unordered_map<int, DNode *> _map;

    /**
     * @brief 将节点移动到头节点
     *
     * @param _tmp
     */
    void moveToHead(DNode *_tmp) {
        _tmp->prev->next = _tmp->next;
        _tmp->next->prev = _tmp->prev;

        _tmp->next = this->head->next;
        _tmp->prev = this->head;

        this->head->next->prev = _tmp;
        this->head->next = _tmp;
    }

    /**
     * @brief 添加一个头节点
     *
     * @param node
     */
    void addToHead(DNode *node) {
        node->next = this->head->next;
        node->prev = this->head;
        this->head->next->prev = node;
        this->head->next = node;
    }

    /**
     * @brief 删除尾节点
     *
     */
    void deleteTailNode() {
        if (this->tail->prev->prev == nullptr) {
            return;
        }
        DNode *node = this->tail->prev;
        node->prev->next = this->tail;
        this->tail->prev = node->prev;
        this->_map.erase(node->key);
        delete node;
    }

    void destroy(DNode *node) {
        DNode *P = node;
        while (P != nullptr) {
            DNode *t = P;
            P = P->next;
            delete t;
        }
    }

public:
    LRUCache(int capacity) {
        this->count = 0;
        this->capacity = capacity;
        this->head = new DNode(-1, -1);
        this->tail = new DNode(-1, -1);
        this->tail->next = nullptr;
        this->head->prev = nullptr;
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }
    ~LRUCache() {
        destroy(this->head);
    }

    int get(int key) {
        if (!_map.count(key)) {
            return -1;
        }
        DNode *_tmp = this->_map[key];
        this->moveToHead(_tmp);
        return _tmp->val;
    }

    void put(int key, int value) {
        if (!this->_map.count(key)) {
            // 不存在元素
            DNode *node = new DNode(key, value);
            this->addToHead(node);
            this->count += 1;
            this->_map[key] = node;
            if (this->count > this->capacity) {
                this->deleteTailNode();
                this->count--;
            }
        } else {
            // 存在元素，将其移动到队列头部
            DNode *node = this->_map[key];
            node->val = value;
            this->moveToHead(node);
        }
    }
};

void testSolution() {
    auto lRUCache = new LRUCache(2);
    lRUCache->put(2, 1);              // 缓存是 {1=1}
    lRUCache->put(2, 2);              // 缓存是 {1=1, 2=2}
    cout << lRUCache->get(1) << endl; // 返回 1
    lRUCache->put(3, 3);              // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache->get(2) << endl; // 返回 -1 (未找到)
    lRUCache->put(4, 4);              // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache->get(1) << endl; // 返回 -1 (未找到)
    cout << lRUCache->get(3) << endl; // 返回 3
    cout << lRUCache->get(4) << endl; // 返回 4
    delete lRUCache;
}

int main(int argc, char *argv[]) {
    testSolution();
    cout << "hello world" << endl;
    return 0;
}