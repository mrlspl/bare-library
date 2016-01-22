/*
 * HelloWorld_delete - example of class destructor wrapper.
 *
 * Deletes a previously created instance of HelloWorld and frees its memory.
 *
 * The calling syntax is:
 *
 *    HelloWorld_delete()
 *
 * The object is implemented in C++.
*/

#include "tools/tools.hpp"
#include "HelloWorld.h"

void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
  if(nrhs < 1)
      mexErrMsgIdAndTxt("BareLibrary:HelloWorld_create:nrhs",
                        "A handle is expected to delete.");

  if(nrhs > 1)
      mexErrMsgIdAndTxt("BareLibrary:HelloWorld_create:nrhs",
                        "This function just needs the handle.");

  if(nlhs != 0)
      mexErrMsgIdAndTxt("BareLibrary:HelloWorld_create:nlhs",
                        "No output is to be returned.");

  destroyObject<BareLibrary::HelloWorld>(prhs[0]);
}
