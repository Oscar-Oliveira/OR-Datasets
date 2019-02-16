/**********************************************************************************************

2DCPackGen: A problem generator for two-dimensional rectangular cutting and packing problems
Elsa Silva, José Fernando Oliveira, Gerhard Wäscher

************************************************************************************************/


#if !defined _TwoDProbGen
#define _TwoDProbGen

#include <boost/math/distributions/beta.hpp> 
#include <iostream>
#include <ostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <assert.h>
#include <math.h>
#include <string.h>


class TwoDProbGen
{
public:
	
	TwoDProbGen();	
	
	virtual ~TwoDProbGen();
	
	/// Creates an empty input parameters file for the generation of 2D or 3D Rectangular Cutting and Packing Problem instances.
	int CreatInputFile();

	/// Reads the input parameters file for the generation of problem tests for 2D or 3D Rectangualr Cutting and Packing Problems.
	int ReadInputFile();

	/// Generates problem instances for Identical Item Packing Problems.
	int IIPP();

	/// Generates problem instances for Placement Problems.
	int PP();

	/// Generates problem instances for Knapsack Problems.
	int KP();

	/// Generates problem instances for Cutting Stcok Problems.
	int CSP();

	/// Generates problem instances for Bin Packing Packing Problems;
	int BPP();

	/// Generates problem instances for Open Dimensional Problem;
	int ODP();

/*
	1	Identical Item Packing Problem	(IIPP)
	2	Single Large Object Placement Problem	(SLOPP)
	3	Multiple Identical Large Object Placement Problem	(MILOPP)
	4	Multiple Heterogeneous Large Object Placement Problem	(MHLOPP/W)
	5	Multiple Heterogeneous Large Object Placement Problem	(MHLOPP/S)
	6	Single Knapsack Problem	(SKP)
	7	Multiple Identical Knapsack Problem	(MIKP)
	8	Multiple Heterogeneous Knapsack Problem	(MHKP/W)
	9	Multiple Heterogeneous Knapsack Problem	(MHKP/S)
	10	Single Stock Size Cutting Stock Problem	(SSSCSP)
	11	Multiple Stock Size Cutting Stock Problem	(MSSCSP)
	12	Residual Cutting Stock Problem	(RCSP)
	13	Single Bin Size Bin Packing Problem	(SBSBPP)
	14	Multiple Bin Size Bin Packing Problem	(MBSBPP)
	15	Residual Bin Packing Problem	(RBPP)
	16	Open Dimension Problem	(ODP/W)
	17	Open Dimension Problem	(ODP/S)*/
	int ProblemType;

	// Number of instances to generate;
	int n_instances;

	/* To decide if it is used an existing input file or a new one shoud be created
		1: the input file already exists;
		0: create an input file*/
	int newinput;
	
	/*  To define the problem dimensionality
		2: Two-Dimensional Problem
		3: Three-Dimensional Problem
	*/
	int NDim;
	
	//Takes value 1 if there is an error in the input parameters
	int error;

	// Name of the file to fill with the parameters (when newinput=0)
	char Parfilename[100];
	
	// Name of the input parameters file
	char InputParfilename[100];

	// Problem type 
	char* ProbT;




	
private:



	/// Number of distinct item types.
	 unsigned long n_Items;

	/// Minimum number of different item types.
	 unsigned long min_nItems;

	/// Maximum number of different item types.
	 unsigned long max_nItems;

	/// Minimum amount of demand for each item type.
	 unsigned long *DItem_L;

	/// Maximum amount of demand for each item type.
	 unsigned long *DItem_U;

	/// Minimum for DItem_L
	 unsigned long min_DItemL;

	/// Maximum for DItem_L
	 unsigned long max_DItemL;

	/// Minimum for DItem_U
	 unsigned long min_DItemU;

	/// Maximum for DItem_U
	 unsigned long max_DItemU;

	/// Items length.
	 unsigned long *ItemL;
	
	/// Items width.
	 unsigned long *ItemW;
	
	/// Items height.
	 unsigned long *ItemH;

	/// Items value.
	unsigned long *ItemValue;

	/// Minimum size dimension of the item defined by the user.
	unsigned long min_ItemS;

	/// Maximum size dimension of the item defined by the user.
	unsigned long max_ItemS;

	/// Minimum height of the item defined by the user.
	unsigned long min_ItemH;

	/// Maximum height of the item defined by the user.
	unsigned long max_ItemH;

	/// Minimum percentage of the area used for the items value;
	double min_ItemV;

	/// Maximu percentage of the area used for the items value;
	double max_ItemV;
		
	/// Number of different large objects.
	unsigned long n_LargeObj;

	/// Minimum number of different large object types.
	unsigned long min_nLargeObj;

	/// Maximum number of different large object types.
	unsigned long max_nLargeObj; //

	/// Minimum amount of each large object type available.
	unsigned long min_LargeObjType;

	/// Maximum amount of each large object type available.
	unsigned long max_LargeObjType;


	/// Large object length.
	unsigned long *LargeObjL;
	
	/// Large object width.
	unsigned long *LargeObjW;

	/// Large object height.
	unsigned long *LargeObjH;

	/// Large object value.
	unsigned long *LargeObj_Value;

	/// Number of Large objects avaibale;
	unsigned long *ALargeObj;

	/// Minimum size dimension of the large object defined by the user.
	unsigned long min_LargeObjS;

	/// Maximum size dimension of the large object defined by the user.
	unsigned long max_LargeObjS;

	/// Minimum height of the large object defined by the user.
	unsigned long min_LargeObjH;

	/// Maximum height of the large object defined by the user.
	unsigned long max_LargeObjH;

	/// Minimum percentage of the area used for the large object value;
	double min_LargObjV;

	/// Maximu percentage of the area used for the large object value;
	double max_LargObjV;
	
	/// Minimum width of the large object defined by the user for the ODP.
	unsigned long min_LargeObjW;

	/// Maximum width of the large object by the user for the ODP.
	unsigned long max_LargeObjW;


	/// Seed given by the user for the generation.
	unsigned long seed;

	// Parameters for the generation of uniformly distributed pseudo-random numbers	
	long sd;
	long a;
	long p;
	long q;
	long r;

	/*// Defines the size and shape of the items and large objects
		1 - Small and square
		2 -	Long and narrow
		3 -	Average length and narrow
		4 -	Small and square or long and narrow
		5	Short and tall
		6	Big and square
		7	Average length and tall
		8	Short and tall or long and tall
		9	Short and average width
		10	Long and average width
		11	Average size and square
		12	Short and average width or long and average width
		13	Short and narrow or short and tall
		14	Long and narrow or long and tall
		15	Average length and narrow or average length and tall
		16	Small and square, short and tall, long and narrow or big and square*/

	// Distribution for the size and shape of the small item types
	unsigned long Item_SizSh;

	// Distribution for the size and shape of the large object types
	unsigned long LargeObj_SizSh;

	// Alpha of the beta distribution for the generation of the length of the item
	double alpha_ItemL;

	// Beta of the beta distribution for the generation of the length of the item
	double beta_ItemL;

	// Alpha of the beta distribution for the generation of the width of the item
	double alpha_ItemW;

	// Beta of the beta distribution for the generation of the width of the item
	double beta_ItemW;

	// Alpha of the beta distribution for the generation of the length of the large object
	double alpha_LargeObjL;

	// Beta of the beta distribution for the generation of the length of large object
	double beta_LargeObjL;

	// Alpha of the beta distribution for the generation of the width of the large object
	double alpha_LargeObjW;
	
	// Beta of the beta distribution for the generation of the width of the  large object
	double beta_LargeObjW;

	/*Defines the characteristics (distribution) for:
	  - the number of different item types;
	  - value of the items;
	  - lower and upper bound for items demand;
	  - number of different large object types;
	  - value of the large objects;
	  - Upper bound for the different large objects available*/

	// Distribution for the number of different item types
	int n_ItemsDist;

	// Distribution for the lower bound demand for each item type
	int DItemL_Dist;

	// Distribution for the upper bound demand for each item type
	int DItemU_Dist;

	// Distribution for the height for each item type
	int HItem_Dist;

	// Distribution for the different large object type available
	int DLargeObj_Dist;

	// Distribution for the height of the large object
	int HLargeObj_Dist;

	// Distribution for the number of different large object types
	int n_LargeObjDist;

	// Distribution for the width of the large object for the Open Dimension Problem
	int w_LargeObjDist;

	// Pseudo-random numbers generator
	inline int Gen( double alpha, double beta, unsigned long min, unsigned long max);

	inline void BetaDist(int DistType);

	// Alpha parameter of the beta distribution 
	double alphaDist;
	
	// Beta parameter of the beta distribution 
	double betaDist;

	// Alpha of the beta distribution for the generation of the lower bound demand for each item type;
	double alpha_DItemL;

	// Beta of the beta distribution for the generation of the lower bound demand for each item type;
	double beta_DItemL;

	// Alpha of the beta distribution for the generation of the upper bound demand for each item type;
	double alpha_DItemU;

	// Beta of the beta distribution for the generation of the upper bound demand for each item type;
	double beta_DItemU;

	// Alpha of the beta distribution for the generation of the height for each item type;
	double alpha_ItemH;

	// Beta of the beta distribution for the generation of the height for each item type;
	double beta_ItemH;
	
	// Alpha of the beta distribution for the generation of the available large object type;
	double alpha_DLargeObjType;

	// Beta of the beta distribution for the generation of the available large object type;
	double beta_DLargeObjType;

	// Alpha of the beta distribution for the generation of the height for each large object type;
	double alpha_LargeObjH;

	// Beta of the beta distribution for the generation of the height for each large object type;
	double beta_LargeObjH;

	// To read the input parameter file;
	char Trash[200];
	char Trash2[200];

};

#endif 