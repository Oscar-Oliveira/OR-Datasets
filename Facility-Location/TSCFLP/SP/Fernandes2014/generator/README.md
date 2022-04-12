# Generator

## How to execute

There are two executables for the TSCFL, the ones for the instances with 50 factories and one for the 100 factories. They are the "ALNS50" and "ALNS100".
For running the linux executables for the TSCFL, the parameters are:

\<input_instance_name> \<iter> \<alpha> \<maxiter> \<gama> \<maxvolume> \<ineficiency_max> \<delta> \<alpha2> \<sigma> \<timeLB> \<seed>

* \<input_instance_name>: instance name
* \<iter>: number of iterations from the algorithm
* \<alpha>: value for the constructive between [0,1]
* \<maxiter>: maximum iterations for the metaheuristics CS-ALNS-LB
* \<gama>: Cluster size
* \<maxvolume>: Maximum volume of the cluster before the local search
* \<ineficiency_max>: maximum ineficency for the cluster
* \<delta>: value for the window of the semi-greedy destructive between [0,1]
* \<alpha2>: value for the window of the semi-greedy repairer between [0,1]
* \<sigma>: Destroy rate between [0,1]
* \<timeLB>: time for the local branch
* \<seed>: Seeds from the algorithm

An example file can be runned by the run_experiments.sh. The output of the file will be directed to experimentosALNS.txt
