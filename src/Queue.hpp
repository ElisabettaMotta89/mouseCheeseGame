//
//  Queue.hpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 18/03/2016.
//
//

//This template has been taken from this website http://www.cprogramming.com/snippets/source-code/templated-queue-class

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include "ofMain.h"

template< class Q > class Queue  // template of class Queue
{
public:
    Queue(int);//default constructor
    ~Queue()//destructor
    {delete [] values; // delete the pointers
        values = nullptr;}
    bool enQueue( Q ); // return true
    Q deQueue(); // dequeue function
    bool isEmpty(); // check if empty
    bool isFull(); // check if Full
    int getFront(); // get fornt
    int getBack(); // get back
    void setFront(int x); // set fornt
    void setBack(int k); // set back
    int size; // size
private:
    
    Q *values; // pointer to the template
    int front; // front
    int back; // back
};

template< class Q > Queue<Q>::Queue(int x): // create the queue
size(x),//set the size
values(new Q[size]), // create value
front(0), // set front and back to 0
back(0)
{ /*empty*/  }

template< class Q > bool Queue<Q>::isFull() // return if the queue is full
{
    if((back + 1) %  size == front )
        return 1;
    else
        return 0;
}

template< class Q > bool Queue<Q>::enQueue(Q x) // put values in the queue
{
    bool b = 0;
    if(!Queue<Q>::isFull()) // if not full
    {
        values[back] = x; // add values
        back = (back + 1) % size;
        b = 1;
    }
    return b;
}

template< class Q > bool Queue<Q>::isEmpty() // check if empty
{
    if( back  == front )//is empty
        return 1;
    else
        return 0; //is not empty
}

template< class Q > int Queue<Q>::getFront() // get queue front
{
    return front; //is not empty
}
template< class Q > int Queue<Q>::getBack() // get queue back
{
    return back; //is not empty
}

template< class Q > void Queue<Q>::setFront(int x) // set front queu
{
    front = x;
}
template< class Q > void Queue<Q>::setBack(int k) // get front queue
{
    back=k; //is not empty
}



template< class Q > Q Queue<Q>::deQueue() // pop the queue if not empty
{
    Q val = " "; // string value allowed
    if(!Queue<Q>::isEmpty()) // not empty
    {
        val = values[front]; // add value
        front = ( front + 1 ) % size;
    }
    else
    {
       
    }
    return val; //return value
    
}


#endif /* Queue_hpp */
