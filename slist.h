#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"

template <class T>
class SListIterator : public Iterator<T> {     
    public: 
        SListIterator() : Iterator<T>() {};
        SListIterator(Node<T> *current) : Iterator<T>(current) {};
        SListIterator<T> operator++(){
            if(this->current){ // Con este if, no vas a retornar nada si la lista está vacía
                this->current = this->current->next;
                return *this;
            }
        };
};

template <typename Tr>
class SList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        typedef SListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Operation cmp;
              
    public:
        SList() {
            head = nullptr;
        };

        bool find(T search, Node<T> **&pointer) {
            // TODO
            pointer = &(this->head);
            while(*pointer){
                if(!cmp(search,(*pointer)->data)){
                    break;
                }
                pointer = &((*pointer)->next);
            }
            return ((*pointer)->data == search);
        }
             
        bool insert(T data) {
            // TODO
            auto* node = new Node<T>(data);
            if(this->head){
                Node<T>** pointer;
                if(find(data,pointer)){
                    return false;
                }
                else{
                    node->next = *pointer;
                    *pointer = node;
                    return true;
                }
            }
            else{
                this->head = node;
                return true;
            }
        }
             
        bool remove(T item) { // No estás borrando el Nodo
            // TODO
            Node<T> **pointer;
            if(this->head){
                if(find(item,pointer)){
                    Node<T> *tmp = (*pointer)->next;
                    *pointer = tmp;
                    return true;
                }
                return false;
            }
            return false;
        }  
             
        iterator begin() {
            // TODO
            return iterator(this->head);
        }
             
        iterator end() {
            // TODO
            return iterator(nullptr);
        }
             
        ~SList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif