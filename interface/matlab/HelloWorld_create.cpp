/*
 * HelloWorld_create - example of class constructor wrapper.
 *
 * Creates an instance of HelloWorld and returns its handle.
 *
 * The calling syntax is:
 *
 *    handle = HelloWorld_create()
 *
 * The object is implemented in C++.
*/

#include "MatlabInterface.h"
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

  plhs[0] = mxCreateDoubleMatrix(1,1,mxREAL);
  double *outMatrix = mxGetPr(plhs[0]);
  BareLibrary::HelloWorld hw;
  outMatrix[0] = MatlabInterface<BareLibrary::HelloWorld>::registerInstance(hw);
}
