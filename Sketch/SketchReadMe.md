# Classes

## Server
### Atributtes
- CRequestQueue ProcessingQueue
- CList Ram
- int OperationsPerTick

### Methods
- Work(): This methods does as many operations per tick as possible.

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
   
