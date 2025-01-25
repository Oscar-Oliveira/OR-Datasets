# Instances

From: [https://www.grmauri.pro.br/problems/](https://www.grmauri.pro.br/problems/)

## Paper

Mauri, G. R., Biajoli, F. L., Rabello, R. L., Chaves, A. A., Ribeiro, G. M., & Lorena, L. A. N. (2021). Hybrid metaheuristics to solve a multiproduct two-stage capacitated facility location problem. International Transactions in Operational Research, 28(6), 3069–3093. https://doi.org/10.1111/itor.12930

## Instance description

```
NAME: PSC*-C**-***-****

PSC = Plant-Satellite-Customer
* = Instance number (1 to 5)
C = Class
** = Class number (1 to 5)
*** = Number of plants (50 or 100)
**** = Number of products (5 or 10)
```

### Format

* $I$ $J$ $K$ $L$ (#plants #satellites #customers #products)
* $K$ rows with customer demand for each product ($L$ columns)
* $I$ rows with plant capacity for each product ($L$ colunms) and fixed cost for plant (last column)
* $L$ matrices with $I$ rows and $J$ columns with flow cost of each product from plant to satellite (one matrix for product)
* $J$ rows with satellite capacity for each product ($L$ colunms) and fixed cost for satellite (last column)
* $L$ matrices with $J$ rows and K columns with flow cost of each product from sattelite to customer (one matrix for product)
