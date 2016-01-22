/*
 * HelloWorld_sayHello - example of class method wrapper.
 *
 * Returns an string containing "Hello World!"
 *
 * The calling syntax is:
 *
 *    message = HelloWorld_sayHello(handle)
 *
 * The object is implemented in C++.
 */

#include "tools/tools.hpp"
#include "HelloWorld.h"

void mexFunction(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
  if(nrhs != 2)
    mexErrMsgIdAndTxt("BareLibrary:HelloWorld_sayHello:nrhs",
        "Exactly two input is needed! The handle and the number to be set.");

  if(!mxIsUint64(prhs[0])) {
    mexErrMsgIdAndTxt("BareLibrary:HelloWorld_sayHello:trhs",
        "Handle must be of type uint64.");
  }

  if(mxGetN(prhs[0]) != 1 &&
      mxGetM(prhs[0]) != 1) {
    mexErrMsgIdAndTxt("BareLibrary:HelloWorld_sayHello:trhs",
        "Invalid handle. Handle is a single number. You cannot pass a matrix as a handle");
  }

  if(!mxIsDouble(prhs[1])) {
    mexErrMsgIdAndTxt("BareLibrary:HelloWorld_sayHello:trhs",
        "Second argument has to be of double type.");
  }

  if(mxGetN(prhs[0]) != 1 &&
      mxGetM(prhs[0]) != 1) {
    mexErrMsgIdAndTxt("BareLibrary:HelloWorld_sayHello:trhs",
        "The number to be set should be one in one.");
  }

  if(nlhs != 0)
    mexErrMsgIdAndTxt("BareLibrary:HelloWorld_create:nlhs",
        "Nothing is to be returned.");

  convertMat2Ptr<BareLibrary::HelloWorld>(prhs[0])->setNumber(*mxGetPr(prhs[1]));
}
