// Normal distribution example
#include <TMB.hpp>
template<class Type>
Type objective_function<Type>::operator() ()
{
  // DATA
  DATA_VECTOR(Y);
  
  // PARATMETERS
  PARAMETER(logSigma);
 
  // NORMAL LOG-LIKELIHOOD
  Type nll = -sum(dnorm(Y, 0, exp(logSigma), true));
  
  // DERIVED PARAMETER
  Type Std_Dev = exp(logSigma);
  ADREPORT(Std_Dev);
  
  // OBJECTIVE FUNCTION TO MINIMIZE
  return nll;
}
