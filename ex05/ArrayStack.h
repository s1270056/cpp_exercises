// ArrayStack.h

#include <string>
#include <iostream>
using namespace std;

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

class ArrayStack {
    private:
    int _num_items; // number of items in the stack
    double* _items; // stack items
    int _allocated_size; // size of memory allocated

    void resize(int max_size) {
        if (max_size==0) max_size++;
        
        // Move stack to a new array of size max
        _allocated_size = max_size;
        double* temp = new double[max_size];
        // Copy 
        for (int i = 0; i < _num_items; ++i) {
            temp[i] = _items[i];
        }
        delete[] _items;
        _items = temp;
    }

public:
    // Constructors:
    ArrayStack() {
        _num_items = 0;
        _allocated_size = 0;
        _items = nullptr;
    }
    /* COMPLETE ... init _num_items to 0, _allocated_size to 0, and
     * set _items to the null pointer, 
     */

    explicit ArrayStack(int allocated_size) {
        _num_items = 0;
         resize(allocated_size);
        

    }
    /* COMPLETE ... init _num_items to 0, 
     * pre-allocate memory for an array of size allocated_size
     * and make _items point to it */

    // Destructor:
    ~ArrayStack() {
        // COMPLETE
        // delete[] _num_items;
        // delete[] _allocated_size;
    }

  //copy
    ArrayStack(const ArrayStack& x){
         _num_items = x._num_items;
         _allocated_size = x._allocated_size;
         _items = new double[x._num_items];
         _items = x._items;
         cout << "Copy Constructor" << endl;
    }  

   //assignment
    ArrayStack& operator=(const ArrayStack& y){
        _num_items = y._num_items;
        _allocated_size = y._allocated_size;
        _items = y._items;
        cout << "Assignment Operator" << endl;
    }

    //move const
    ArrayStack(ArrayStack&& p){
        _num_items = p._num_items;
        _allocated_size = p._allocated_size;
        _items = p._items;
        cout << "Move Constructor" << endl;
    }

    //move assignment
    ArrayStack& operator=(ArrayStack&& q){
        _num_items = q._num_items;
        _allocated_size = q._allocated_size;
        _items = q._items;
        cout << "Move Assignment" << endl;
    }

    void push(double item) {
        if (_num_items == _allocated_size) resize(2*_allocated_size);
        _items[_num_items++] = item;
    }

    void pop() {
        _num_items--;
        if (_num_items > 0 && _num_items == _allocated_size/4) resize(_allocated_size/2);
    }

    double top() {
        return _items[_num_items-1];
    }

    bool empty() const { return _num_items == 0; }

    int size() const { return _num_items; }
};

#endif // ARRAY_STACK_H