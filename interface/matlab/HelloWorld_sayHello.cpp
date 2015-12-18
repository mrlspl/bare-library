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
    mexErrMsgIdAndTxt("BareLibrary:HelloWorld_sayHello:nrhs",
        "An input is expected! Pass the class handle.");

  if( !mxIsDouble(prhs[0]) ||
      mxIsComplex(prhs[0])) {
    mexErrMsgIdAndTxt("BareLibrary:HelloWorld_sayHello:trhs",
        "Handle must be of type double.");
  }

  if(mxGetN(prhs[0]) != 1 &&
      mxGetM(prhs[0]) != 1) {
    mexErrMsgIdAndTxt("BareLibrary:HelloWorld_sayHello:trhs",
        "Invalid handle. Handle is a single number.");
  }

  if(nlhs != 1)
    mexErrMsgIdAndTxt("BareLibrary:HelloWorld_create:nlhs",
        "You need to keep the handle (output) for further reference to the object.");

  unsigned handle = mxGetScalar(prhs[0]);
  plhs[0] = mxCreateString(MatlabInterface<BareLibrary::HelloWorld>::getInstance(handle).sayHello().c_str());
}
