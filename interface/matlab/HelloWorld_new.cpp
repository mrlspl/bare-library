/*
 * HelloWorld_new - example of class constructor wrapper.
 *
 * Creates an instance of HelloWorld and returns its handle.
 *
 * The calling syntax is:
 *
 *    handle = HelloWorld_new()
 *
 * The object is implemented in C++.
*/

#include "tools/tools.hpp"
#include "HelloWorld.h"

void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
  if(nrhs != 0)
      mexErrMsgIdAndTxt("BareLibrary:HelloWorld_create:nrhs",
                        "No input is expected.");

  if(nlhs != 1)
      mexErrMsgIdAndTxt("BareLibrary:HelloWorld_create:nlhs",
                        "One output required.");

  plhs[0] = convertPtr2Mat<BareLibrary::HelloWorld>(new BareLibrary::HelloWorld);
}
