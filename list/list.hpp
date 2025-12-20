#pragma once

#include <iostream>

template<typename T>
class list {
private:
    class node {
    public:
        T data;
        node* next;
        node(const T& value) : data(value), next(nullptr) {}
    };

    node* head;
    size_t m_size;

public:
    list() : head(nullptr), m_size(0) {}
    ~list() {
        clear();
    }

    list(const list& other) : head(nullptr), m_size(0){
        node* cur = other.head;

        while (cur)
        {
            push_back(cur->data);
            cur = cur -> next;
        }
        
    }

    list(list&& other) noexcept {
        head = other.head;
        m_size = other.m_size;
        other.head = nullptr;
        other.m_size = 0;
    }

    list& operator=(const list& other) {
        if(this == &other) return *this;

        clear();

        node* cur = other.head;
        while(cur) {
            push_back(cur -> data);
            cur = cur ->next;
        }

        return *this;
    }

    list& operator=(list&& other) noexcept {
        if(this == &other) return *this;

        clear();

        head = other.head;
        m_size = other.m_size;
        other.head = nullptr;
        other.m_size = 0;

        return *this;
    }

    void push_back(const T& value) {
        node* newNode = new node(value);
        if(!head) {
            head = newNode;
        } else {
            node* cur = head;
            while (cur -> next) {
                cur = cur ->next;
            }
            cur ->next = newNode;
        }
        m_size++;
    }

    void push_front(const T& value) {
        node* temp = head;
        head = new node(value);
        head->next = temp;
        m_size++;
    }

    void pop_front() {
        if(!head) return;
        node* temp = head;
        head = head ->next;
        delete temp;
        m_size--;
    }

    void pop_back() {
        if(!head) return;

        if(!head ->next) {
            delete head;
            head = nullptr;
        } else { 
            node* cur = head;
            while (cur ->next ->next)
            {
                cur = cur ->next;
            }
            delete cur ->next;
            cur -> next = nullptr;
        }
        --m_size;
    }

    void print() const {
        node* cur = head;
        while(cur) {
            std::cout << cur ->data << ", ";
            cur = cur ->next;
        }
        std::cout << std::endl;
    }

    size_t size() const {
        return m_size;
    }

    bool empty() const {
        return m_size == 0;
    }

    void clear() {
        while (head) {
            node* temp = head;
            head = head->next;
            delete temp;
        }
        m_size = 0;
    }
};