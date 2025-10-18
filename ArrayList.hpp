#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include "List.hpp"
#include <iostream>
using namespace std;

template <typename T>
class ArrayList : public List<T> {
    private:
        // an array that contains the elements
        T* buffer;

        // the maximum number of elements in the list
        int maxSize;

        // copy the state of the argument list to `this`
        void copy(const ArrayList<T>&);

    public:
        // constructor with the maximum size as the argument
        ArrayList(int = 100);

        // copy constructor
        ArrayList(const ArrayList<T>&);

        // overloaded assignment operator
        ArrayList<T>& operator=(const ArrayList<T>&);

        // destructor
        virtual ~ArrayList();

        // add the argument to the end of the list
        virtual void append(const T&) override;

        // remove all elements in the list, resetting to the initial state
        virtual void clear() override;

        // return the element at the given position (argument)
        virtual T getElement(int) const override;

        // return the current length of the list
        virtual int getLength() const override;

        // return the maximum size of the list
        int getMaxSize() const;

        // insert the given element (argument 2) at
        // the given position (argument 1)
        virtual void insert(int, const T&) override;

        // determine if the list currently empty
        virtual bool isEmpty() const override;

        // determine if the list currently full
        bool isFull() const;

        // remove the element at the given position (argument)
        virtual void remove(int) override;

        // replace the element at the given position (argument 1) with
        // the value given (argument 2)
        virtual void replace(int, const T&) override;

        // overloaded stream insertion operator to make printing easier
        template <typename U>
        friend ostream& operator<<(ostream&, const ArrayList<U>&);
};

#include "ArrayList.tpp"
#endif
