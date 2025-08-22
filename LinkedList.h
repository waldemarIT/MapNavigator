#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

using namespace std;
#define NAME_LEN 150

typedef char Name[NAME_LEN];
template <class T>
struct Node {
    T x;
    Node<T>* next;
    Node(T x) {
        this->x = x;
        next = nullptr;
    }
};

template <class T>
class LinkedList
{
    Node<T>* first;
    Node<T>* last;
    int Size;
public:
    LinkedList() {
        first = nullptr;
        last = nullptr;
        Size = 0;
    }

    bool isEmpty() const {
        return !first;
    }

    int size() const {
        return Size;
    }

    void push_back(T x) {
        Node<T>* node = new Node<T>(x);

        if (isEmpty()) {
            first = node;
            last = node;
            Size = 1;
            return;
        }

        last->next = node;
        last = node;
        Size++;
    }

    T pop_front() {
        if (isEmpty()) throw "LinkedList::pop_front() - Error: List is empty!";
        Node<T>* node = first;
        first = first->next;
        if (!first) last = nullptr;

        T x = node->x;
        delete node;
        Size--;
        return x;
    }

    void removeByIdx(int idx) {
        if (idx < 0)  throw "LinkedList::removeByIdx() - Error: idx<0!";
        int n = size();
        if (idx >= n)  throw "LinkedList::removeByIdx() - Error: idx>=size()!";
        LinkedList<T> temp;
        for (int i = 0; i < n; i++) {
            T x = pop_front();
            if (i != idx) temp.push_back(x);
        }
        first = temp.first;
        last = temp.last;
        Size = temp.Size;
        temp.first = nullptr;
        temp.last = nullptr;
        temp.Size = 0;
    }

    void show(bool newLine = false)const {
        if (isEmpty()) cout << "List is empty!" << endl;
        Node<T>* node = first;
        while (node) {
            cout << node->x << " ";
            if (newLine) cout << endl;
            node = node->next;
        }
        cout << endl;
    }

    void clear() {
        while (!isEmpty())
        {
            pop_front();
        }
    }

    T& operator[](int idx) {
        if (idx < 0)     throw "LinkedList::operator[](int idx) - Error: idx<0!";
        if (idx >= Size) throw "LinkedList::operator[](int idx) - Error: idx >= Size!";
        int cnt = 0;
        Node<T>* node = first;
        while (cnt < idx) {
            node = node->next;
            cnt++;
        }
        return node->x;
    }

    const T& operator[](int idx) const {
        if (idx < 0)     throw "LinkedList::operator[](int idx) - Error: idx<0!";
        if (idx >= Size) throw "LinkedList::operator[](int idx) - Error: idx >= Size!";
        int cnt = 0;
        Node<T>* node = first;
        while (cnt < idx) {
            node = node->next;
            cnt++;
        }
        return node->x;
    }

    const int indexOf(T x) const {
        int n = size();
        for (int i = 0; i < n; i++) {
            T xx = this->operator[](i);
            if (xx == x) return i;
        }
        return -1;
    }

    virtual ~LinkedList() {
        clear();
    }
};

#endif // LINKEDLIST_H
