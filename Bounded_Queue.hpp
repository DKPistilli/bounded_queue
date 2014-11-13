/*      
 *      Bounded_Queue.hpp
 *      
 *      programmed by Dorian Pistilli
 *      Last edit on 11/13/14
 *
 *      Header file for the Bounded_Queue class. Offers the client
 *      queue/dequeue functions for storing / removing integers from the
 *      queue. The queue is bounded, meaning its length is static and set
 *      upon initialization.
 *
 */ 

#ifndef __BOUNDED_QUEUE_INCLUDED__
#define __BOUNDED_QUEUE_INCLUDED__

class Bounded_Queue {
        public:
                /* * * * * * * * * * * * * * * * * * * * * * */
                /*          Constructor / Destructor         */
                /* * * * * * * * * * * * * * * * * * * * * * */
                
                // initializes queue to hold a given static # of ints
                Bounded_Queue(int q_size);

                // handles garbage collection
                ~Bounded_Queue();

                /* * * * * * * * * * * * * * * * * * * * * * */
                /*         Queue Manipulation / Access       */
                /* * * * * * * * * * * * * * * * * * * * * * */
                
                // stores given int in queue. returns 1 on success, else 0
                bool enqueue(int input);
                // removes and returns int from queue in FIFO order
                int dequeue();
        private:

                /* * * * * * * * * * * * * * * * * * * * * * */
                /*              Helper Functions             */
                /* * * * * * * * * * * * * * * * * * * * * * */

                // return 1 if "is_condition", else 0
                bool is_full();
                bool is_empty();

                // getters & setters
                void set_in_array(int val, int index);
                int get_from_array(int index);

                /* * * * * * * * * * * * * * * * * * * * * * */
                /*             Pvt Member Variables          */
                /* * * * * * * * * * * * * * * * * * * * * * */

                int max_size, curr_size; 
                int head, tail;
                int* queue;
};




#endif // __BOUNDED_QUEUE_INCLUDED__
