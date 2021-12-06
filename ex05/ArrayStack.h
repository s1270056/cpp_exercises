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
        _allocated_size = allocated_size;
        _items = new double[allocated_size];

    }
    /* COMPLETE ... init _num_items to 0, 
     * pre-allocate memory for an array of size allocated_size
     * and make _items point to it */




  //copy
    ArrayStack(const ArrayStack& x){
         _num_items = x._num_items;
         _allocated_size = x._allocated_size;
         _items = new double[x._num_items];
         for( int i = 0; i < x._num_items; i++ ){
      _items[i] = x._items[i];
    }
         cout << "Copy Constructor" << endl;
    }  

   //assignment
    ArrayStack& operator = (const ArrayStack& y){
        delete[] _items;
        _num_items = y._num_items;
        _allocated_size = y._allocated_size;
        _items = new double[y._num_items];
        for( int i = 0; i < y._num_items; i++ ){
      _items[i] = y._items[i];
    }
        cout << "Assignment Operator" << endl;
        return *this;
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

        //move const
    ArrayStack(ArrayStack&& p) noexcept{
        int flag;
        _num_items = p._num_items;
        _allocated_size = p._allocated_size;
        _items = new double[p._num_items];
        for( int i = 0; i < p._num_items; i++ ){
      _items[i] = p._items[i];
      flag = i;
    }
    for(int j=flag; j >= 0; j-- ){
      p.pop();
    }
        cout << "Move Constructor" << endl;
    }

    //move assignment
    ArrayStack& operator=(ArrayStack&& q) noexcept{
        int flag;
        if(this == &q) return *this;
        _num_items = q._num_items;
        _allocated_size = q._allocated_size;
        _items = new double[q._num_items];
        for( int i = 0; i < q._num_items; i++ ){
      _items[i] = q._items[i];
      flag = i;
    }
    for(int j=flag; j >= 0; j-- ){
      q.pop();
    }
        cout << "Move Assignment" << endl;
        return *this;
    }

    // Destructor:
    virtual ~ArrayStack() {
        // COMPLETE
        // delete[] _num_items;
        // delete[] _allocated_size;
        delete[] _items;
    }
};

#endif // ARRAY_STACK_H