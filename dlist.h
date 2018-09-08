#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T>
class DListIterator : public Iterator<T> {     
    public: 
        DListIterator() : Iterator<T>() {};
        DListIterator(Node<T> *current) : Iterator<T>(current) {};
        DListIterator<T> operator++(){
            if(this->current){
                this->current = this->current->next;
                return *this;
            }
        };
        DListIterator<T> operator--(){
            if(this->current){
                this->current = this->current->prev;
                return *this;
            }
        };
};

template <typename Tr>
class DList {     
    public:
        typedef typename Tr::T T;
        typedef DListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Node<T>* tail;
              
    public:
        DList() {
            head = tail = nullptr;
        };

        void push_front(T data) {
            auto* node = new Node(data);
            if(head){
                node->next=this->head;
                this->head->prev = node;
                this->head = node;
            }
            else{
                this->head = this->tail = node;
            }
        }

        void push_back(T data) {
            // TODO
            auto* node = new Node(data);
            if(this->tail){
                this->tail->next = node;
                node->prev = this->tail;
                this->tail = node;
            }
            else{
                this->head = this->tail = node;
            }
        }
             
        void pop_front() {
            // TODO
            auto tmp = this->head;
            if(this->head){
                this->head = this->head->next;
                delete tmp;
            }
        }
             
        void pop_back() {
            // TODO
            auto tmp = this->tail;
            if(this->tail){
                this->tail = this->tail->prev;
                delete tmp;
            }
        }
             
        iterator begin() {
            return DListIterator<T>(this->head);
        }
             
        iterator end() {
            return DListIterator<T>(this->tail);
        }
             
        ~DList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif