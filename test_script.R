library(TMB)
setwd("/Users/stevenwhitlock/Desktop/WF latest 2020")
compile("test_example.cpp")

dyn.load(dynlib("test_example"))
set.seed(1)
data <- list(Y = rnorm(n=1000,mean = 0,sd=2))
parameters <- list(logSigma=0)
obj <- MakeADFun(data, parameters, DLL="test_example")
opt <- do.call("optim", obj)

out=sdreport(obj)
summary(out,"report")

