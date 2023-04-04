bounded_queue
=============

programmer: Dorian Pistilli


language used: C++


A bounded queue data structure designed for the KPCB Fellows
application. It offers the client a bounded queue for storing "n"
integers, with n being a size they can set initially but remains
static once set.


###Architectural Details:###

- Implemented using a circular buffer to store the ints, and head
and tail ints to keep track of which indices should be popped from
or pushed to next.
- A circular buffer was chosen over a linked list because there's 
less overhead (large L.Lists are storage heavy w/ Node pointers)
and because it offers O(1) enQ/deQ operations vs O(n) for linked
list.
- I had some issues with one of the requirements in the spec that the
applicant refrain from including any libraries, and relying solely
on primitive types. Although its understandable that the use of
pre-built data structures would defeat the challenge, it also puts
restrictions on effective programming practices. In the end, I
decided to use the iostream and exception libraries. I found this
necessary, because without them I could not properly handle several
potential errors, like running out of dynamic mem when allocating
the new array, or trying to dequeue an empty list.


###Future Updates:###

- [ ] create front / enqueue / dequeue interface with only those functions,
standardizing its functionality to better fit the C++ stdlib data 
structures. Also gets rid of that awkward case where the client is popping 
from an empty list AND expecting to have an int returned... ooh awkward!!!
- [ ] use templates to make the bounded_queue more modular (so that it 
doesn't only work with ints)







