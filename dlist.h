#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T>
class DListIterator : public Iterator<T> {     
    public: 
        DListIterator() : Iterator<T>() {};
        DListIterator(Node<T> *current) : Iterator<T>(current) {};
        DListIterator<T> operator++(){
            if(this->current){ // Con este if, no vas a retornar nada si la lista está vacía
                this->current = this->current->next;
                return *this;
            }
        };
        DListIterator<T> operator--(){
            if(this->current){ // Con este if, no vas a retornar nada si la lista está vacía
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
            auto* node = new Node<T>(data);
            node->next=this->head;
            if(head){
                this->head->prev = node;
                this->head = node;
            }
            else{
                this->head = this->tail = node;
            }
        }

        void push_back(T data) {
            // TODO
            auto* node = new Node<T>(data);
            node->prev = this->tail;
            if(this->head){
                this->tail->next = node;
                this->tail = node;
            }
            else{
                this->head = this->tail = node;
            }
        }
             
        void pop_front() {
            // TODO
            if(!this->head)
                return;
            if(this->head and this->head->next){
                this->head = this->head->next;
                delete this->head->prev;
            }
            else if(this->head and !this->head->next){
                delete this->head;
            }
        }
             
        void pop_back() {
            // TODO
            if(!this->head)
                return;
            if(this->tail and this->tail->prev){
                this->tail = this->tail->prev;
                delete this->tail->next;
            }
            else
                delete this->tail;
        }
             
        iterator begin() {
            return iterator(this->head);
        }
             
        iterator end() {
            return iterator(this->tail);
        }
             
        ~DList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif