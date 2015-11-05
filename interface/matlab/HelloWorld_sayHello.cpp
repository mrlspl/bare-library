/*
 * HelloWorld_create - example of class method wrapper.
 *
 * Returns an string containing "Hello World!"
 *
 * The calling syntax is:
 *
 *    HelloWorld_sayHello(handle)
 *
 * The object is implemented in C++.
*/

#include "MatlabInterface.h"
#include "HelloWorld.h"

void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
  if(nrhs != 1)
      mexErrMsgIdAndTxt("BareLibrary:HelloWorld_create:nrhs",
                        "An input is expected! Pass the class handle.");


  if(nlhs != 1)
      mexErrMsgIdAndTxt("BareLibrary:HelloWorld_create:nlhs",
                        "One output required.");

  plhs[0] = mxCreateDoubleMatrix(1,1,mxREAL);
  double *outMatrix = mxGetPr(plhs[0]);
  outMatrix[0] = MatlabInterface<BareLibrary::HelloWorld>::getInstance(0);
}
