# Instances

From: [https://github.com/pehgonzalez/OCA](https://github.com/pehgonzalez/OCA)

## Paper

Fernandes, D. R. M., Rocha, C., Aloise, D., Ribeiro, G. M., Santos, E. M., & Silva, A. (2014). A simple and effective genetic algorithm for the two-stage capacitated facility location problem. Computers and Industrial Engineering, 75(1), 200–208. https://doi.org/10.1016/j.cie.2014.05.023

## Instance description

> _The instances used were defined in Fernandes et al. (2014) and can bedivided into two sets. The first set consists of 25 instances with 50 factories,100 warehouses and 200 customers. In the second set, also with 25 instances,the size of the problem is doubled, which means 100 factories, 200 warehousesand 400 customers. Both sets are divided into five instance classes with different characteristics._

### Format

* $I$ $J$ $K$ (#plants #satellites #customers)
* $K$ rows with customer demand
* $I$ rows with plant capacity and fixed cost for plant
* $L$ matrices with $I$ rows and $J$ columns with flow cost from plant to satellite
* $J$ rows with satellite capacity and fixed cost for satellite
* $L$ matrices with $J$ rows and K columns with flow cost from sattelite to customer
