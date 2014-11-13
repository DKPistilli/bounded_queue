/*      
 *      Bounded_Queue.cpp
 *
 *      Dorian Pistilli 
 *      dkpistilli@gmail.com
 *
 *      Function Implementation File. Details and ADT architecture are 
 *      given in more depth in both Bounded_Queue.hpp and README.md
 */ 


#include "Bounded_Queue.hpp"
#include <iostream> // for printing exceptions to the cerr stream
#include <exception> //for throwing/catching necessary exceptions

/************************************************
*                                               *
*            Constructor/Destructor             *
*                                               *
************************************************/

Bounded_Queue::Bounded_Queue(int q_size)
{
        this->curr_size = 0;
        this->max_size = q_size;

        try {
               this->queue = new int[q_size];
        }
        catch (std::exception& std_e) {
                std::cerr << "Error: " << std_e.what() << std::endl;
        } 

        this->head = this->tail = 0;
}

Bounded_Queue::~Bounded_Queue()
{
        delete[] this->queue;
}

/************************************************
*                                               *
*             Public/Client Functions           *
*                                               *
************************************************/

bool Bounded_Queue::enqueue(int input)
// Function: Allows the client to push one int onto the queue and
//           returns whether or not the push was a success
//     Args: int (the integer to be pushed onto the queue)
//  Returns: bool (returns 1 if push was successful or 0 if queue was full)
{
        if (is_full()) {
                return 0;
        } else {
                set_in_array(input, tail);
                curr_size++;
                tail++;
                tail = this->tail % max_size;
                return 1;
        }
}

int Bounded_Queue::dequeue()
// Function: Allows the client to pop one int off of the queue and
//           returns that value
//     Args: n/a
//  Returns: int (the number being popped off)
//    Notes: Throws std::logic_error if called on an empty queue
{
        if (is_empty()) {
                std::string error = "Error: Attempting to dequeue from "
                                    "an empty queue\n";
                throw std::logic_error(error);
        } else {
                int temp_index = head;
                curr_size--;
                head++;
                head = head % max_size;
                return get_from_array(temp_index); 
        }
}


  
/************************************************
*                                               *
*            Private/Helper Functions           *
*                                               *
************************************************/

void Bounded_Queue::set_in_array(int val, int index)
{
        this->queue[index] = val;
}

int Bounded_Queue::get_from_array(int index)
{
        return queue[index];
}

// is_full() and and is_empty() are fairly intuitive,
// returning 1 if is_condition and 0 if not
bool Bounded_Queue::is_full()
{
        if (curr_size >= max_size) {
                return 1;
        } else {
                return 0;
        }
}

bool Bounded_Queue::is_empty()
{
        if (curr_size == 0) {
                return 1;
        } else {
                return 0;
        }
}
