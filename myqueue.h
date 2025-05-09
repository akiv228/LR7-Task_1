#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stdexcept>
#include <QVector>

class MyQueue {
public:
    struct Node {
        int data;      // значение
        Node* prev;    // ссылка на предыдущий узел
        Node* next;    // ссылка на следующий узел
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };

    MyQueue();
    ~MyQueue();

    bool isEmpty() const;          // проверка на пустоту
    void PushBack(int val);         // добавить в конец enqueue
    int PopFront();                 // удалить из начала и вернуть значение (или бросать исключение) dequeue
    int Head() const;             // посмотреть первый элемент (не удаляя)  (peek)
    int Tail() const;
    void clear();                  // полностью очистить
    int size() const;

    //  решения варианта 6
    void generateRandom(int count, int minVal, int maxVal);
    void removeNegatives();        // удалить все узлы с data < 0


    QVector<int> toVector() const; // вернуть содержимое в виде списка для отображения в UI

private:
    Node* head;     // указатель на первый элемент
    Node* tail;     // указатель на последний
    int count;    // текущее число элементов
};

#endif // MYQUEUE_H
