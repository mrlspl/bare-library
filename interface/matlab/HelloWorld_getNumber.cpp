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
  if(nrhs != 1)
    mexErrMsgIdAndTxt("BareLibrary:HelloWorld_sayHello:nrhs",
        "At least an input is expected! Always pass the class handle as the first input.");

  if(!mxIsUint64(prhs[0])) {
    mexErrMsgIdAndTxt("BareLibrary:HelloWorld_sayHello:trhs",
        "Handle must be of type uint64.");
  }

  if(mxGetN(prhs[0]) != 1 &&
      mxGetM(prhs[0]) != 1) {
    mexErrMsgIdAndTxt("BareLibrary:HelloWorld_sayHello:trhs",
        "Invalid handle. Handle is a single number. You cannot pass a matrix as a handle");
  }

  if(nlhs != 1)
    mexErrMsgIdAndTxt("BareLibrary:HelloWorld_create:nlhs",
        "Don't you wanna catch the function output?! This function has an output.");

  plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
  *mxGetPr(plhs[0]) = convertMat2Ptr<BareLibrary::HelloWorld>(prhs[0])->getNumber();
}
