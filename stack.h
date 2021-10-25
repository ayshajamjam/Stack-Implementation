#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <new>
#include "node.h"
#include "nosuchobject.h"

using namespace std;

template <typename T>
class Stack
{
public:
    Stack();
    Stack( const Stack<T>& s ) throw ( bad_alloc );
    bool empty() const;
    unsigned size() const;
    T& top() const throw ( NoSuchObject );
    T pop() throw ( NoSuchObject );
    void push( const T& ) throw ( bad_alloc );
    const Stack<T>& operator=( const Stack<T>& ) throw ( bad_alloc );
    void printInternal() const;
    void clear();
    ~Stack();
    
private:
    unsigned sz;
    Node<T>* topPtr;
    
    void initialize();
    
}; // Stack<T> class

// initialize method
template <typename T>
void Stack<T>::initialize()
{
    sz = 0;
    topPtr = 0;
}

// default constructor
template <typename T>
Stack<T>::Stack()
{
    initialize();
}

// explicit constructor
template <typename T>
Stack<T>::Stack(const Stack <T> & s) throw ( bad_alloc )
{
    initialize();
    *this = s;
}

// empty
template <typename T>
bool Stack<T>::empty() const
{
    return (sz == 0);
}

// size
template <typename T>
unsigned Stack<T>::size() const
{
    return sz;
}

// top
template <typename T>
T & Stack<T>::top() const throw (NoSuchObject)
{
    if(empty())
        throw NoSuchObject( "Stack::top: stack is empty" );
        
        return topPtr->getObject();
        }

// pop
template <typename T>
T Stack<T>::pop() throw (NoSuchObject)
{
    if(empty()){
        throw NoSuchObject( "Stack::top: stack is empty" );
    }
    
    Node<T> * ptr = topPtr;
    topPtr = topPtr->getNextPtr();
    T object = ptr->getObject();
    delete ptr;
    sz--;
    
    return object;
    
}

// push
template <typename T>
void Stack<T>::push(const T &object) throw (bad_alloc)
{
    Node<T> * newNode = new Node<T>(object);
    newNode->setNextPtr(topPtr);
    topPtr = newNode;
    sz++;
    
}

// operator =
template <typename T>
const Stack<T>& Stack<T>::operator=( const Stack<T> &s ) throw (bad_alloc)
{
    if( &s != this ){
        if( !empty() ){
            clear();
        }
        
        sz = s.size();
        Node<T> * sptr = s.topPtr;
        Node<T> * last = 0;
        
        while( sptr != 0 ){
            if( last == 0 ){
                topPtr = last = new Node<T>(*sptr);
            }
            else{
                last->setNextPtr(new Node<T>(*sptr));
                last = last->getNextPtr();
            }
            
            sptr = sptr->getNextPtr();
        }
    }
    
    return * this;
    
}

// print internal
template <typename T>
void Stack<T>::printInternal() const
{
    Node<T> * current = topPtr;
    int i = 0;
    cout << "top: " << topPtr << endl;
    while ( current != 0 ) {
        cout << "Node " << i << endl;
        cout << "  address: " << current << endl;
        cout << "  object: " << current->getObject() << endl;
        cout << "  next: " << current->getNextPtr() << endl;
        current = current->getNextPtr();
        i++;
    } // while
    
} // Stack<T>::printInternal

template <typename T>
void Stack<T>::clear(){
    
    Node<T> * ptr = topPtr;
    
    while( topPtr != 0 ){
        topPtr = topPtr->getNextPtr();
        delete ptr;
        sz--;
        ptr = topPtr;
    }
    
}

// destructor
template <typename T>
Stack<T>::~Stack(){
    clear();
}

#endif // STACK_H



