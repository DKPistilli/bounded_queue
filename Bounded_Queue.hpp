/*      
 *      Bounded_Queue.hpp
 *      
 *      programmed by Dorian Pistilli
 *      Last edit on 10/28/14
 *      Language used: C++
 *
 *      A bounded queue data structure designed for the KPCB Fellows
 *      application. It offers the client a bounded queue for storing "n"
 *      integers, with n being a size they can set initially but remains
 *      static once set.
 *
 *      Implemented using a circular buffer to store the ints, and head
 *      and tail ints to keep track of which indices should be popped from
 *      or pushed to next.
 *      
 *      A circular buffer was chosen over a linked list because there's 
 *      less overhead (large L.Lists are storage heavy w/ Node pointers)
 *      and because it offers O(1) enQ/deQ operations vs O(n) for linked
 *      list.
 *
 *      I had some issues with one of the requirements in the spec that the
 *      applicant refrain from including any libraries, and relying solely
 *      on primitive types. Although its understandable that the use of
 *      pre-built data structures would defeat the challenge, it also puts
 *      restrictions on effective programming practices. In the end, I
 *      decided to use the iostream and exception libraries. I found this
 *      necessary, because without them I could not properly handle several
 *      potential errors, like running out of dynamic mem when allocating
 *      the new array, or trying to dequeue an empty list.
 *
 */ 

#ifndef __BOUNDED_QUEUE_INCLUDED__
#define __BOUNDED_QUEUE_INCLUDED__

class Bounded_Queue {
        public:
                Bounded_Queue(int q_size);
                ~Bounded_Queue();

                bool enqueue(int input);
                int dequeue();
        private:
                bool is_full();
                bool is_empty();

                void set_in_array(int val, int index);
                int get_from_array(int index);

                int max_size, curr_size, head, tail;
                int* queue;
};




#endif // __BOUNDED_QUEUE_INCLUDED__
