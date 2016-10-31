# Servers System Simulator
This project is about simulating a distributed servers system. The idea behind this systems is to attend as many requests as quickly as possible with the available computational resources.

## (INSTRUCTIONS FOR RUNNING THE PROGRAM)
The program will ask you to write the path of the text file containing the input. Then just put on your seat belt and enjoy the simulation.

-Example of how to type the input location:
![alt text](https://github.com/josealvarez97/Servers_System_Simulator/blob/master/Sketch/Entrada.PNG)

## HOW DOES THE SIMULATION WORKS?
First of all we send all the requests from the file to the request queue, after that the load balancer takes the first three requests of the queue, this is the part where the load balancer has to comunicate with each server to know if they can afford one request, if the actual server can't we ask to the other server, if any server can't afford the request we send it to the failed requests stack. But if one server can afford it we assign the request to the server, this is the moment where the tick starts. The servers have the ram list, and the processing queue, when the processing list is empty (talking about the elements of a specific request) we operate the ram, and send it to succesfull requests stack. This is the moment where the actual tick ends.

### BASIC ALGORITHM
1. Read Input & queue requests into Requests Queue
2. Start Tick
3. Load Balancer takes three requests from requests queue
4. Load Balancer comunicates with servers
5. Servers work (they perform as many operations as they can in a tick)
6. Tick Ends. Go back to step 2 if there are still requests wating on requests queue OR 
   there's still a server working.
7. Display totals.

## BASIC STRUCTURE
### Principal Classes 
#### Server
##### Atributtes
- CRequestQueue ProcessingQueue
- CList Ram
- int OperationsPerTick

##### Methods
- void Work(): This methods does as many operations per tick as possible.
- bool AskAvailability(int processingSpaceNecessary, int ramSpaceNecessary): This function receives the parameters
  of a request and return if it is possible for the server to attend the request.

#### LoadBalancer
##### Atributtes
- CurrentFirstRequest
- CurrentSecondRequest
- CurrentThirdRequest

##### Methods
- void TakeRequestFromRequestQueue(CRequest request)
- CRequest GetCurrentFirstRequest()
- CRequest GetCurrentSecondRequest()
- CRequest GetCurrentThirdRequest()
- bool TryToAssignRequestToAServer(): this methods asks servers if it is possible
  to assign a request. If no server can take the request, loadBalancer sends it to
  failedRequestsStack.

## What is considered **ONE** operation?
- Every rotation of **Hard Disc**. (rotating from 1 to 4 or any other number is an operation)
- Consuming an element from the **Processing Queue**.
- Reorganize / Reordering the **RAM**.
- Executing a **Complete Request** (example, making everything neccesary to sum SUM, multiply in MUL, divide in DIV)


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



References:

1. [Doubly Linked Lists. Concept and Examples](http://es.ccm.net/faq/2872-listas-doblemente-enlazadas)
2. [How to make a doubly linked list in c++ p.1 (video)](https://www.youtube.com/watch?v=YJRRpXYldVQ)
3. [How to make a doubly linked list in c++ p.2 (video)](https://www.youtube.com/watch?v=5s0x8bc9DvQ)
4. [Basic functions of doubly linked lists. (English)](https://www.tutorialspoint.com/data_structures_algorithms/doubly_linked_list_algorithm.htm)
5. [Doubly linked list. Concept and fuctions in Spanish](http://c.conclase.net/edd/?cap=005)
6. [Doubly linked list. Concept and fuctions in Spanish](http://c.conclase.net/edd/?cap=005)
