# Classes

## Server
### Atributtes
- CRequestQueue ProcessingQueue
- CList Ram
- int OperationsPerTick

### Methods
- void Work(): This methods does as many operations per tick as possible.
- bool AskAvailability(int processingSpaceNecessary, int ramSpaceNecessary): This function receives the parameters
  of a request and return if it is possible for the server to attend the request.

## LoadBalancer
### Atributtes
- CurrentFirstRequest
- CurrentSecondRequest
- CurrentThirdRequest

### Methods
- void TakeRequestFromRequestQueue(CRequest request)
- CRequest GetCurrentFirstRequest()
- CRequest GetCurrentSecondRequest()
- CRequest GetCurrentThirdRequest()
- bool TryToAssignRequestToAServer(): this methods asks servers if it is possible
  to assign a request. If no server can take the request, loadBalancer sends it to
  failedRequestsStack.
   
