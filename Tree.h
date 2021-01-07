#ifndef TREE_TREE_H
#define TREE_TREE_H

#include <functional>

#include "Sequence.h"


template <typename T>
struct brunch {

    explicit brunch(T data_) {
        data = data_;
        left = nullptr;
        right = nullptr;
    }

    ~brunch() = default;

    T data;

    brunch<T> *left;

    brunch<T> *right;

    void addElem(std::function<bool(T, T)> func, brunch<T> ** node, T _data) {
        if (*node == nullptr)
            *node = new brunch<T>(_data);
        else if (func((*node)->data , _data))
            addElem(func, &((*node)->left), _data);
        else
            addElem(func, &((*node)->right), _data);
    }   //Добавляет элемент в дерево по указателю ветки

    T LNR_help(brunch<T> *node, DynamicArray<T>* arr = new DynamicArray<T>()){

    }

    DynamicArray<T>* LNR(brunch<T> *node, DynamicArray<T>*) {

    }   //Обход дерева (лево-корень-право)

    void DeleteTree(brunch<T> **node) {
        if (*node != nullptr) {
            DeleteTree(&((*node)->left));
            delete *node;
            DeleteTree(&((*node)->right));
        }
    }   //Метод удаление дерева
};

template <typename T>

class Tree { ;
private:
    brunch<T>* head = nullptr;
    std::function<bool(T, T)> func;
public:
    Tree(std::function<bool(T, T)> func_) {
        func = func_;
    }

    Tree(std::function<bool(T, T)> func_, const T* items, const int &count){
        func = func_;
        head = nullptr;
        for (int i = 0; i<count; i++){
            head->addElem(func, &head, items[i]);
        }
    }

    Tree(const Tree<T> &tree){
        DynamicArray<T>* arr = tree.LNR();
        for(int i = 0; i<arr->GetReal(); i++){
            head->addElem(func, &head, arr[i]);
        }
    }

    ~Tree(){
        head->Delete(&head);
    }

    DynamicArray<T>* LNR() {
        return head->LNR(head);
    }   //Обход дерева (лево-корень-право)

    void addElem(const T &item){
        head->addElem(func, &head, item);
    }   //Добавляет элемент в дерево
};



#endif
