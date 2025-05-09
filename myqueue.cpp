#include "myqueue.h"
#include <stdexcept>
#include <QVector>
#include <cstdlib>

MyQueue::MyQueue() : head(nullptr), tail(nullptr), count(0) {}

MyQueue::~MyQueue() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

bool MyQueue::isEmpty() const {
    return count == 0;
}

void MyQueue::PushBack(int val) {
    Node* newNode = new Node(val);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
}

int MyQueue::PopFront() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    int value = head->data;
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
    count--;
    return value;
}


int MyQueue::Head() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return head->data;
}

int MyQueue::Tail() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return tail->data;
}

void MyQueue::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    count = 0;
}

int MyQueue::size() const {
    return count;
}

void MyQueue::generateRandom(int count, int minVal, int maxVal) {
    for (int i = 0; i < count; ++i) {
        int val = minVal + std::rand() % (maxVal - minVal + 1);
        PushBack(val);
    }
}

void MyQueue::removeNegatives() {
    Node* current = head;
    while (current != nullptr) {
        if (current->data < 0) {
            Node* toDelete = current;
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            current = current->next;
            delete toDelete;
            count--;
        } else {
            current = current->next;
        }
    }
}


QVector<int> MyQueue::toVector() const {
    QVector<int> vec;
    Node* current = head;
    while (current != nullptr) {
        vec.append(current->data);
        current = current->next;
    }
    return vec;
}
