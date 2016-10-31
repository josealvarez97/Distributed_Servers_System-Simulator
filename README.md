# Servers System Simulator
This project is about simulating a distributed servers system. The idea behind this systems is to attend as many requests as quickly as possible with the available computational resources.


## What is considered **ONE** operation?
- Every rotation of **Hard Disc**. (rotating from 1 to 4 or any other number is an operation)
- Consuming an element from the **Processing Queue**.
- Pushing a request to the **Succesful Requests Queue**.
- Reorganize / Reordering the **RAM**.
- Executing a **Complete Request** (example, making everything neccesary to sum SUM, multiply in MUL, divide in DIV)


References:

1. [Doubly Linked Lists. Concept and Examples](http://es.ccm.net/faq/2872-listas-doblemente-enlazadas)
2. [How to make a doubly linked list in c++ p.1 (video)](https://www.youtube.com/watch?v=YJRRpXYldVQ)
3. [How to make a doubly linked list in c++ p.2 (video)](https://www.youtube.com/watch?v=5s0x8bc9DvQ)
4. [Basic functions of doubly linked lists. (English)](https://www.tutorialspoint.com/data_structures_algorithms/doubly_linked_list_algorithm.htm)
5. [Doubly linked list. Concept and fuctions in Spanish](http://c.conclase.net/edd/?cap=005)
6. [Doubly linked list. Concept and fuctions in Spanish](http://c.conclase.net/edd/?cap=005)

## HOW DOES THE SIMULATION WORKS?
First of all we send all the requests from the file to the request queue, after that the load balancer takes the first tree requests of the queue, this is the part where the load balancer has to comunicate with each server to know if they can afford one request, if the actual server can't we ask to the other server, if any server can't afford the request we send it to the failed requests stack. But if one server


## OPTIMIZATIONS / EXTRAS

**We claim that we always assign a request to the server in best conditions.**
How?

We formulate a formula we called ***serverRank***. It measures how difficult is for a server to attend a request at the current tick, based on the *serverDegree* , *requestsWeight* and *serverOperationsPerTick*. It is computated as follows:

      serverRank = (serverDegree * requestsWeight) / serverOperationsPerTick

where:
- serverDegree is the number of requests it has been assigned and haven't been completed,
- requestsWeight is the sum of the ramSpace and ProcessingSpace needed for attending every requests assigned to a server
- operationsPerTick is the number of operations that a server can perform on a tick.

In summary, it is based on the fact that how "fucked up" is a server is directly proportional to how complex are the tasks assigned, and inversely proportional to the capacity/power of the server.

