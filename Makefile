test: test_queue.cpp Bounded_Queue.cpp Bounded_Queue.hpp
	g++ -Wall -Wextra -o test_queue test_queue.cpp Bounded_Queue.cpp

Queue: Bounded_Queue.cpp Bounded_Queue.hpp
	g++ -c -Wall Bounded_Queue.cpp

clean:
	rm -f Bounded_Queue.o
	rm -f ./test_queue

