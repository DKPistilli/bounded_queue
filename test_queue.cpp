/*
 *      test_queue.cpp
 *
 *      programmed by Dorian Pistilli
 *      last edit on 10/30/14
 *      Language used: C++
 *
 *      The test file for the Bounded_Queue class. Uses a series of
 *      asserts to test the functionality of the class and make sure
 *      every line of code has been hit and works as its supposed to.
 *      
 *      When using this, make sure to run with valgrind to verify that
 *      there are no errors with garbage collection.
 *      
 */

#include <iostream>
#include <cassert>
#include <exception>
#include "Bounded_Queue.hpp"

int main()
{
        Bounded_Queue testq1(10000);

        // verify that 100 elems are successfully pushed to queue of 
        // then verify that 101st add is unsuccessful
        for (int i = 0; i < 10000; i++) {
                assert(testq1.enqueue(i));
        }
        assert(!testq1.enqueue(10000));

        // pop those 100 elems, asserting that each one was stored
        // and then removed correctly in FIFO (first in first out) order
        int check_val;
        for (int i = 0; i < 10000; i++) {
                check_val = testq1.dequeue();
                assert(check_val == i);
        }

        // verify that the stack is now empty and that the correct
        // exception is thrown.
        try {
                check_val = testq1.dequeue();
        } catch (std::exception& std_except) {
                std::string testString = "Error: Attempting to dequeue "
                                        "from an empty queue\n";
                assert(testString.compare(std_except.what()) == 0);
        }

        std::cout << "Tests have Passed.\n";
        
}
