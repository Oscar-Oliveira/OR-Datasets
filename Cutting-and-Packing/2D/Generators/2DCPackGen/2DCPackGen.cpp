/**********************************************************************************************

2DCPackGen: A problem generator for two-dimensional rectangular cutting and packing problems
Elsa Silva, José Fernando Oliveira, Gerhard Wäscher

************************************************************************************************/



#include "2DCPackGen.h"

using boost::math::beta_distribution;
using namespace std;

TwoDProbGen::TwoDProbGen()
{
	DItem_L=NULL;
	DItem_U=NULL;
	ItemL=NULL;
	ItemW=NULL;
	ItemH=NULL;
	ItemValue=NULL;
	LargeObjL=NULL;
	LargeObjW=NULL;
	LargeObjH=NULL;
	LargeObj_Value=NULL;
	ALargeObj=NULL;

}
TwoDProbGen::~TwoDProbGen()
{
	if (DItem_L!=NULL) delete [] DItem_L;
	if (DItem_U!=NULL) delete [] DItem_U;
	if (ItemL!=NULL) delete [] ItemL;
	if (ItemW !=NULL) delete [] ItemW;
	if (ItemH !=NULL) delete [] ItemH;
	if (ItemValue !=NULL) delete [] ItemValue;
	if (LargeObjL!=NULL) delete [] LargeObjL;
	if (LargeObjW!=NULL) delete [] LargeObjW;
	if (LargeObjH!=NULL) delete [] LargeObjH;
	if (LargeObj_Value!=NULL) delete [] LargeObj_Value;
	if (ALargeObj!=NULL) delete [] ALargeObj;
		
}
int main()
{	
				   
	TwoDProbGen tdp; 

	tdp.error=0;

	cout << endl << "****This program generates problem instances for Two-Dimensional and Three-Dimensional Rectangular Cutting and Packing problems.****" << endl << endl ; 

	cout <<"_____________________________________________" << endl << endl;
	cout <<" ID	Input Parameter file selection                              " << endl;
	cout <<"_____________________________________________" << endl;
	cout <<" 0	New Input Parameter file" << endl;
	cout <<" 1	Existing Input Parameter file" << endl;
	cout <<"_____________________________________________" << endl;
	cout << endl << " Select the ID for the parameter file selection: ";
	cin>>tdp.newinput;

	if (tdp.newinput!=0 && tdp.newinput!=1){
			cout << endl << "***Error in the input parameter file selection, please select 0 or 1!***" << endl;
			cout << endl << " The program will be closed." << endl;
			tdp.error=1;
	}

	if(tdp.newinput==0){
		if(tdp.error==0){
			cout << endl;
			cout <<"___________________________________________________________" << endl << endl;
			cout <<" ID for the number of dimensions that define the Problem "<< endl;
			cout <<"___________________________________________________________" << endl;
			cout <<" 2	2D Rectangular Cutting and Packing Problem              " << endl;
			cout <<" 3	3D Rectangular Cutting and Packing Problem              " << endl;
			cout <<"___________________________________________________________" << endl;
			cout << endl << " Select the ID for dimensions of the problem: ";
			cin>>tdp.NDim;
			
			if (tdp.NDim!=2 && tdp.NDim!=3){
				cout << " Please select 2 or 3 Dimensions!" << endl << endl;
				cout << endl << " The program will be closed." << endl;
				tdp.error=1;

			}
		
			if (tdp.NDim==2) cout <<" The 2-Dimensional Rectangular Cutting and Packing Problem has been selected!" << endl;
			if (tdp.NDim==3) cout <<" The 3-Dimensional Rectangular Cutting and Packing Problem has been selected!" << endl;

			if (tdp.NDim==2) cout << endl << "****This program generates problem instances for Two-Dimensional Rectangular Cutting and Packing problems.****" << endl << endl ;
			if (tdp.NDim==3) cout << endl << "****This program generates problem instances for Three-Dimensional Rectangular Cutting and Packing problems.****" << endl << endl ;
			cout <<"_______________________________________________________________________" << endl << endl;
			cout <<" ID	Rectangular Cutting and Packing Problem                               " << endl;
			cout <<"_______________________________________________________________________" << endl;
			cout <<" 1	Identical Item Packing Problem	(IIPP)" << endl;
			cout <<" 2	Single Large Object Placement Problem	(SLOPP)" << endl;
			cout <<" 3	Multiple Identical Large Object Placement Problem	(MILOPP)" << endl;
			cout <<" 4	Multiple Heterogeneous Large Object Placement Problem	(MHLOPP/W)" << endl;
			cout <<" 5	Multiple Heterogeneous Large Object Placement Problem	(MHLOPP/S)" << endl;
			cout <<" 6	Single Knapsack Problem	(SKP)" << endl;
			cout <<" 7	Multiple Identical Knapsack Problem	(MIKP)" << endl;
			cout <<" 8	Multiple Heterogeneous Knapsack Problem	(MHKP/W)" << endl;
			cout <<" 9	Multiple Heterogeneous Knapsack Problem	(MHKP/S)" << endl;
			cout <<" 10	Single Stock Size Cutting Stock Problem	(SSSCSP)" << endl;
			cout <<" 11	Multiple Stock Size Cutting Stock Problem	(MSSCSP)" << endl;
			cout <<" 12	Residual Cutting Stock Problem	(RCSP)" << endl;
			cout <<" 13	Single Bin Size Bin Packing Problem	(SBSBPP)" << endl;
			cout <<" 14	Multiple Bin Size Bin Packing Problem	(MBSBPP)" << endl;
			cout <<" 15	Residual Bin Packing Problem	(RBPP)" << endl;
			cout <<" 16	Open Dimension Problem	(ODP/W)" << endl;
			cout <<" 17	Open Dimension Problem	(ODP/S)" << endl;
			cout <<"_______________________________________________________________________" << endl << endl; 

			if (tdp.NDim==2)cout <<" Please select the ID of the 2D Rectangular Cutting and Packing Problem to be considered: ";
			if (tdp.NDim==3)cout <<" Please select the ID of the 3D Rectangular Cutting and Packing Problem to be considered: ";

			cin >> tdp.ProblemType;
			
			if (tdp.ProblemType==0){
				cout << " Please select the problem type according to the previous table (1 to 17)!" << endl << endl;
				cout << endl << " The program will be closed." << endl;
				tdp.error=1;
			}
			if (tdp.ProblemType>17){
				cout << " Please select the problem type according to the previous table (1 to 17)!" << endl << endl;
				cout << endl << " The program will be closed." << endl;
				tdp.error=1;
			}
			
			if(tdp.ProblemType==1){
				cout <<"_____________________________________________________________________________" << endl;
				cout << endl << " *** The Identical Item Packing Problem (IIPP) has been selected.***" << endl;	
				cout <<"_____________________________________________________________________________" << endl << endl;
				tdp.ProbT = " IIPP";
			}
			if(tdp.ProblemType==2){
				cout <<"_____________________________________________________________________________" << endl;
				cout << endl << " *** The Single Large Object Placement Problem (SLOPP) has been selected.***" << endl;	
				cout <<"_____________________________________________________________________________" << endl << endl;
				tdp.ProbT = " SLOPP";
			}
			if(tdp.ProblemType==3){
				cout <<"_____________________________________________________________________________" << endl;
				cout << endl << " *** The Multiple Identical Large Object Placement Problem (MILOPP) has been selected.***" << endl;	
				cout <<"_____________________________________________________________________________" << endl<< endl;
				tdp.ProbT = " MILOPP";
			}
			if(tdp.ProblemType==4){
				cout <<"_____________________________________________________________________________" << endl;
				cout << endl << " *** The Multiple Heterogeneous Large Object Placement Problem with weakly assortment of the large objects (MHLOPP/W) has been selected.***" << endl ;	
				cout <<"_____________________________________________________________________________" << endl << endl;
				tdp.ProbT = " MHLOPPW";
			}
			if(tdp.ProblemType==5){
				cout <<"_____________________________________________________________________________" << endl;
				cout << endl << " *** The Multiple Heterogeneous Large Object Placement Problem with strongly assortment of the large objects(MHLOPP/S) has been selected.***" << endl;	
				cout <<"_____________________________________________________________________________" << endl << endl;
				tdp.ProbT = " MHLOPPS";
			}
			if(tdp.ProblemType==6){
				cout <<"_____________________________________________________________________________" << endl;
				cout << endl << " *** The Single Knapsack Problem (SKP) has been selected.***" << endl;	
				cout <<"_____________________________________________________________________________" << endl << endl;
				tdp.ProbT = " SKP";
			}
			if(tdp.ProblemType==7){
				cout <<"_____________________________________________________________________________" << endl;
				cout << endl << " *** The Multiple Identical Knapsack Problem (MIKP) has been selected.***" << endl;	
				cout <<"_____________________________________________________________________________" << endl << endl;
				tdp.ProbT = " MIKP";
			}
			if(tdp.ProblemType==8){
				cout <<"_____________________________________________________________________________" << endl;
				cout << endl << " *** The Multiple Identical Knapsack Problem (MHKP/W) has been selected.***" << endl;	
				cout <<"_____________________________________________________________________________" << endl << endl;
				tdp.ProbT = " MHKPW";
			}
			if(tdp.ProblemType==9){
				cout <<"_____________________________________________________________________________" << endl;
				cout << endl << " *** The Multiple Heterogeneous Knapsack Problem (MHKP/S) has been selected.***" << endl;	
				cout <<"_____________________________________________________________________________" << endl << endl;
				tdp.ProbT = " MHKPS";
			}
			if(tdp.ProblemType==10){
				cout <<"_____________________________________________________________________________" << endl;
				cout << endl << " *** The Single Stock Size Cutting Stock Problem (SSCSP) has been selected.***" << endl;	
				cout <<"_____________________________________________________________________________" << endl << endl;
				tdp.ProbT = " SSSCSP";
			}
			if(tdp.ProblemType==11){
				cout <<"_____________________________________________________________________________" << endl;
				cout << endl << " *** The Multiple Stock Size Cutting Stock Problem (MSSCSP) has been selected.***" << endl;	
				cout <<"_____________________________________________________________________________" << endl << endl;
				tdp.ProbT = " MSSCSP";
			}
			if(tdp.ProblemType==12){
				cout <<"_____________________________________________________________________________" << endl;
				cout << endl << " *** The Residual Cutting Stock Problem (RCSP) has been selected.***" << endl;	
				cout <<"_____________________________________________________________________________" << endl << endl;
				tdp.ProbT = " RCSP";
			}
			if(tdp.ProblemType==13){
				cout <<"_____________________________________________________________________________" << endl;
				cout << endl << " *** The Single Bin Size Bin Packing Problem (SBSBPP) has been selected.***" << endl;	
				cout <<"_____________________________________________________________________________" << endl << endl;
				tdp.ProbT = " SBSBPP";
			}
			if(tdp.ProblemType==14){
				cout <<"_____________________________________________________________________________" << endl;
				cout << endl << " *** The Multiple Bin Size Bin Packing Problem (MBSBPP) has been selected.***"  << endl;	
				cout <<"_____________________________________________________________________________" << endl << endl;
				tdp.ProbT = " MBSBPP";
			}
			if(tdp.ProblemType==15){
				cout <<"_____________________________________________________________________________" << endl;
				cout << endl << " *** The Residual Bin Packing Problem (RBPP) has been selected.***" << endl;
				cout <<"_____________________________________________________________________________" << endl << endl;
				tdp.ProbT = " RBPP";
			}
			if(tdp.ProblemType==16){
				cout <<"_____________________________________________________________________________" << endl;
				cout << endl << " *** The Open Dimension Problem (ODP/W) has been selected.***" << endl << endl;	
				cout <<"_____________________________________________________________________________" << endl<< endl;
				tdp.ProbT = " ODPW";
				

			}
			if(tdp.ProblemType==17){
				cout <<"_____________________________________________________________________________" << endl;
				cout << endl << " *** The Open Dimension Problem (ODP/S) has been selected.***" << endl << endl;
				cout <<"_____________________________________________________________________________" << endl << endl;
				tdp.ProbT = " ODPS";
			}
		}
	}
		
		
	// The program creates an empty input parameter file 
	if (tdp.newinput==0 && tdp.error==0) tdp.CreatInputFile();
	

	// Creates the problem instances for each problem
	if (tdp.newinput==1 && tdp.error==0){

		// Reads an existing input parameter file
		tdp.ReadInputFile();

		if (tdp.error==0){
			if (tdp.ProblemType==1){
					tdp.IIPP();
					cout <<"_____________________________________________________________________________" << endl;
					cout << endl << " *** The problem instances for the Identical Item Packing Problem (IIPP) were generated!***" << endl ;	
					cout <<"_____________________________________________________________________________" << endl << endl;
				}
				if (tdp.ProblemType==2){
					tdp.PP();
					cout <<"_____________________________________________________________________________" << endl;
					cout << endl << " *** The problem instances for the Single Large Object Placement Problem (SLOPP) were generated!***" << endl;
					cout <<"_____________________________________________________________________________" << endl << endl;
				}
				if (tdp.ProblemType==3){
					tdp.PP();
					cout <<"_____________________________________________________________________________" << endl;
					cout << endl << " *** The problem instances for the Multiple Identical Large Object Placement Problem (MILOPP) were generated!***" <<  endl;
					cout <<"_____________________________________________________________________________" << endl << endl;
				}
				if (tdp.ProblemType==4){
					tdp.PP();
					cout <<"_____________________________________________________________________________" << endl;
					cout << endl << " *** The problem instances for the Multiple Heterogeneous Large Object Placement Problem (MHLOPP/W) were generated!***" << endl;
					cout <<"_____________________________________________________________________________" << endl << endl;
				}
				if (tdp.ProblemType==5){
					tdp.PP();
					cout <<"_____________________________________________________________________________" << endl;
					cout << endl << " *** The problem instances for the Multiple Heterogeneous Large Object Placement Problem (MHLOPP/S were generated!***" << endl;
					cout <<"_____________________________________________________________________________" << endl << endl;
				}
				if (tdp.ProblemType==6){
					tdp.KP();
					cout <<"_____________________________________________________________________________" << endl;
					cout << endl << " *** The problem instances for the Single Knapsack Problem (SKP) were generated!***" << endl;
					cout <<"_____________________________________________________________________________" << endl << endl;
				}
				if (tdp.ProblemType==7){
					tdp.KP();
					cout <<"_____________________________________________________________________________" << endl;
					cout << endl << " *** The problem instances for the Multiple Identical Knapsack Problem (MIKP) were generated!***" << endl;
					cout <<"_____________________________________________________________________________" << endl << endl;
				}
				if (tdp.ProblemType==8){
					tdp.KP();
					cout <<"_____________________________________________________________________________" << endl;
					cout << endl << " *** The problem instances for the Multiple Heterogeneous Knapsack Problem (MHKP/W) were generated!***" << endl ;
					cout <<"_____________________________________________________________________________" << endl << endl;
				}
				if (tdp.ProblemType==9){
					tdp.KP();
					cout <<"_____________________________________________________________________________" << endl;
					cout << endl << " *** The problem instances for the Multiple Heterogeneous Knapsack Problem (MHKP/S) were generated!***" << endl;
					cout <<"_____________________________________________________________________________" << endl << endl;
				}
				if (tdp.ProblemType==10){
					tdp.CSP();
					cout <<"_____________________________________________________________________________" << endl;
					cout << endl << " *** The problem instances for the Single Stock Size Cutting Stock Problem (SSSCSP) were generated!***" << endl ;
					cout <<"_____________________________________________________________________________" << endl << endl;
				}
				if (tdp.ProblemType==11){
					tdp.CSP();
					cout <<"_____________________________________________________________________________" << endl;
					cout << endl << " *** The problem instances for the Multiple Stock Size Cutting Stock Problem (MSSCSP) were generated!***" << endl;
					cout <<"_____________________________________________________________________________" << endl << endl;
				}
				if (tdp.ProblemType==12){
					tdp.CSP();
					cout <<"_____________________________________________________________________________" << endl;
					cout << endl << " *** The problem instances for the Residual Cutting Stock Problem (RCSP) were generated!***" << endl;
					cout <<"_____________________________________________________________________________" << endl  << endl;
				}
				if (tdp.ProblemType==13){
					tdp.BPP();
					cout << endl << " *** The problem instances for the Single Bin Size Bin Packing Problem(SBSBPP) were generated!***" << endl;
					cout <<"_____________________________________________________________________________" << endl  << endl;				
				}
				if (tdp.ProblemType==14){
					tdp.BPP();
					cout <<"_____________________________________________________________________________" << endl;
					cout << endl << " *** The problem instances for the Multiple Bin Size Bin Packing Problem (MBSBPP) were generated!***" << endl;
					cout <<"_____________________________________________________________________________" << endl  << endl;
				}
				if (tdp.ProblemType==15) {
					tdp.BPP();
					cout <<"_____________________________________________________________________________" << endl;
					cout << endl << " *** The problem instances for the Residual Bin Packing Problem	(RBPP) were generated!***" << endl;
					cout <<"_____________________________________________________________________________" << endl  << endl;
				}
				if (tdp.ProblemType==16){
					tdp.ODP();
					cout <<"_____________________________________________________________________________" << endl;
					cout << endl << " *** The problem instances for the Open Dimension Problem (ODP/W) were generated!***" << endl;
					cout <<"_____________________________________________________________________________" << endl  << endl;
				}
				if (tdp.ProblemType==17){
					tdp.ODP();
					cout <<"_____________________________________________________________________________" << endl;
					cout << endl << " *** The problem instances for the Open Dimension Problem (ODP/S) were generated!***" << endl ;
					cout <<"_____________________________________________________________________________" << endl  << endl;
				}
			}
		}
	
	
	int close;
	cout << endl << " Enter a number to quit!" << endl;
	cin >> close;

}

int TwoDProbGen::CreatInputFile()
{
	cout<< endl << " Enter the name for the parameter file (e. g. C:\\programs\\" << ProbT <<"par.txt): " << endl;
	cin>>Parfilename;

			
	ofstream FileInpPar;
	FileInpPar.open(Parfilename);

	if(!FileInpPar.is_open( )){
		cout<<" It was not possible to open the file!\n";
		FileInpPar.clear( ); 
	}

	
	// These parameters are defined when running the DOS window
	FileInpPar <<"_______________________________________________________________________________________________________. "<< endl;
	if (ProblemType== 1)FileInpPar << "***Input parameters file for the Identical Item Packing Problem (IIPP)***" << endl;
	if (ProblemType== 2)FileInpPar << "***Input parameters file for the Single Large Object Placement Problem (SLOPP)***" << endl;
	if (ProblemType== 3)FileInpPar << "***Input parameters file for the Multiple Identical Large Object Placement Problem (MILOPP)***" << endl;
	if (ProblemType== 4)FileInpPar << "***Input parameters file for the Multiple Heterogeneous Large Object Placement Problem (MHLOPP/W)***" << endl;
	if (ProblemType== 5)FileInpPar << "***Input parameters file for the Multiple Heterogeneous Large Object Placement Problem (MHLOPP/S)***" << endl;
	if (ProblemType== 6)FileInpPar << "***Input parameters file for the Single Knapsack Problem (SKP)***" << endl;
	if (ProblemType== 7)FileInpPar << "***Input parameters file for the Multiple Identical Knapsack Problem (MIKP)***" << endl;
	if (ProblemType== 8)FileInpPar << "***Input parameters file for the Multiple Heterogeneous Knapsack Problem (MHKP/W)***" << endl;
	if (ProblemType== 9)FileInpPar << "***Input parameters file for the Multiple Heterogeneous Knapsack Problem (MHKP/S)***" << endl;
	if (ProblemType== 10)FileInpPar << "***Input parameters file for the Single Stock Size Cutting Stock Problem (SSSCSP)***" << endl;
	if (ProblemType== 11)FileInpPar << "***Input parameters file for the Multiple Stock Size Cutting Stock Problem (MSSCSP)***" << endl;
	if (ProblemType== 12)FileInpPar << "***Input parameters file for the Residual Cutting Stock Problem (RCSP)***" << endl;
	if (ProblemType== 13)FileInpPar << "***Input parameters file for the Single Bin Size Bin Packing Problem (SBSBPP)***" << endl;
	if (ProblemType== 14)FileInpPar << "***Input parameters file for the Multiple Bin Size Bin Packing Problem (MBSBPP)***" << endl;
	if (ProblemType== 15)FileInpPar << "***Input parameters file for the Residual Bin Packing Problem (RBPP)***" << endl;
	if (ProblemType== 16)FileInpPar << "***Input parameters file for the Open Dimension Problem(ODP/W)***" << endl;
	if (ProblemType== 17)FileInpPar << "***Input parameters file for the Open Dimension Problem (ODP/S)***" << endl;
	FileInpPar <<"_______________________________________________________________________________________________________. "<< endl;
	FileInpPar << "Number of Dimensions which defines the problem: " << endl;
	FileInpPar << NDim << endl;
	FileInpPar << "ID of the rectangular cutting and packing problem: " << endl;
	FileInpPar << ProblemType << endl; 
	FileInpPar <<"_______________________________________________________________________________________________________. "<< endl;
	

	// Parameters for the generation of large objects and item types 
	FileInpPar << "Enter an integer seed (smaller than 2,147,483,647): "<< endl;
	FileInpPar << endl;
	FileInpPar <<"Please insert the number of instances to generate: "<< endl;
	FileInpPar << endl;
	if(ProblemType<16){
		if(NDim==2){
			FileInpPar << "Please insert integer values for the minimum and maximum size dimension of the large object (separated by a space):"<< endl;
			FileInpPar << endl;
		}
		if(NDim==3){
			FileInpPar << "Please insert integer values for the minimum and maximum size dimension of the large object base (separated by a space):"<< endl;
			FileInpPar << endl;
		}
	}
	else{
		FileInpPar << "Please insert integer values for the minimum and maximum width of the large object (separated by a space):"<< endl;
		FileInpPar << endl;
	}
	if(NDim==2){
		FileInpPar << "Please insert integer values for the minimum and maximum size dimension of the items (separated by a space):"<< endl;
		FileInpPar << endl;
	}
	if(NDim==3){
		FileInpPar << "Please insert integer values for the minimum and maximum size dimension of the base of the items (separated by a space):"<< endl;
		FileInpPar << endl;
		FileInpPar <<"Please insert integer values for the minimum and maximum size height of the large object (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar <<"Please insert integer values for the minimum and maximum size height of the small item (separated by a space): "<< endl;
		FileInpPar << endl;
	}

	//Parameters for the Size and shape control of the items and large objects
	FileInpPar <<"___________________________________________________________________________."<< endl;
	FileInpPar <<" ID Characteristics of the size and shape for items and large objects.           "<< endl;
	FileInpPar <<"___________________________________________________________________________. "<< endl;
	FileInpPar <<" 1	Small and square;"<< endl;
	FileInpPar <<" 2	Long and narrow;" << endl;
	FileInpPar <<" 3	Average length and narrow;" << endl;
	FileInpPar <<" 4	Small and square or long and narrow;" << endl;
	FileInpPar <<" 5	Short and tall;" << endl;
	FileInpPar <<" 6	Big and square;" << endl;
	FileInpPar <<" 7	Average length and tall;" << endl;
	FileInpPar <<" 8	Short and tall or long and tall;" << endl;
	FileInpPar <<" 9	Short and average width;" << endl;
	FileInpPar <<" 10	Long and average width;" << endl;
	FileInpPar <<" 11	Average size and square;" << endl;
	FileInpPar <<" 12	Short and average width or long and average width;" << endl;
	FileInpPar <<" 13	Short and narrow or short and tall;" << endl;
	FileInpPar <<" 14	Long and narrow or long and tall;" << endl;
	FileInpPar <<" 15	Average length and narrow or average length and tall;" << endl;
	FileInpPar <<" 16	Small and square, short and tall, long and narrow or big and square;" << endl;
	FileInpPar <<"___________________________________________________________________________."<< endl;
	if(NDim==2){
		FileInpPar << "Please select the ID of the size and shape of the items: "<< endl;
		FileInpPar << endl;
	}
	if(NDim==3){
		FileInpPar << "Please select the ID of the size and shape of base of the items: "<< endl;
		FileInpPar << endl;
	}
	if(ProblemType<16){
		if (ProblemType==1 || ProblemType==2 || ProblemType==3 || ProblemType==6 || ProblemType==7 || ProblemType==10 || ProblemType==13){
			if(NDim==2){
				FileInpPar << "Please select the ID of the size and shape of the large object: "<< endl;
				FileInpPar << endl;
			}
			if(NDim==3){
				FileInpPar << "Please select the ID of the size and shape of the base of the large object: "<< endl;
				FileInpPar << endl;
			}
		}
		else{
			if(NDim==2){
				FileInpPar << "Please select the ID of the size and shape of the large objects: "<< endl;
				FileInpPar << endl;
			}
			if(NDim==3){
				FileInpPar << "Please select the ID of the size and shape of the base of the large objects: "<< endl;
				FileInpPar << endl;
			}
			
		}
	}
			
	if(ProblemType==1){
			if(NDim==3){
				FileInpPar <<"_________________________________________________________." << endl;	
				FileInpPar <<" ID Characteristics.             " << endl;
				FileInpPar <<"_________________________________________________________." << endl;
				FileInpPar <<" 1	Beta distribution with alpha=1 and beta=3;"<< endl;
				FileInpPar <<" 2	Beta distribution with alpha=2 and beta=5;" << endl;
				FileInpPar <<" 3	Beta distribution with alpha=2 and beta=2;" << endl;
				FileInpPar <<" 4	Beta distribution with alpha=0.5 and beta=0.5;" << endl;
				FileInpPar <<" 5	Beta distribution with alpha=1 and beta=1;" << endl;
				FileInpPar <<" 6	Beta distribution with alpha=3 and beta=1;" << endl;
				FileInpPar <<" 7	Beta distribution with alpha=5 and beta=2;" << endl;
				FileInpPar <<"_________________________________________________________." << endl;
				FileInpPar <<"Please select the ID of the characteristic for the height of the large object: "<< endl;
				FileInpPar << endl;
				FileInpPar <<"Please select the ID of the characteristic for the height of the small item type: "<< endl;
				FileInpPar << endl;
		}
	}

	if(ProblemType==2){
		FileInpPar << "Please insert the minimum and maximum number of different item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please give a range between 0.5 and 1 to the value of the items (If the items' value is equal to its area insert 1 1) (separated by a space):"<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert a minimum and a maximum value for the lower bound demand of the item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert a minimum and a maximum value for the upper bound demand of the item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar <<"_________________________________________________________." << endl;	
		FileInpPar <<" ID Characteristics.             " << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" 1	Beta distribution with alpha=1 and beta=3;"<< endl;
		FileInpPar <<" 2	Beta distribution with alpha=2 and beta=5;" << endl;
		FileInpPar <<" 3	Beta distribution with alpha=2 and beta=2;" << endl;
		FileInpPar <<" 4	Beta distribution with alpha=0.5 and beta=0.5;" << endl;
		FileInpPar <<" 5	Beta distribution with alpha=1 and beta=1;" << endl;
		FileInpPar <<" 6	Beta distribution with alpha=3 and beta=1;" << endl;
		FileInpPar <<" 7	Beta distribution with alpha=5 and beta=2;" << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		if(NDim==3){
			FileInpPar <<"Please select the ID of the characteristic for the height of the large object: "<< endl;
			FileInpPar << endl;
			FileInpPar <<"Please select the ID of the characteristic for the height of the small item: "<< endl;
			FileInpPar << endl;
		}
		FileInpPar <<"Please select the ID of the characteristic for the number of different item types: "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please select the ID of the characteristic for the lower bound of the item type demand: "<< endl;
		FileInpPar << endl;		
		FileInpPar << "Please select the ID of the characteristic for the upper bound of the item type demand: "<< endl;
		FileInpPar << endl;
		
	}
	if(ProblemType==3){
		FileInpPar << "Please insert the minimum and maximum number of large objects available (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number of different item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please give a range between 0.5 and 1 to the value of the items (if the items' value is equal to its area insert 1 1), separated by a space:" << endl;
		FileInpPar << endl;
		FileInpPar << "Please insert a minimum and a maximum value for the lower bound demand of the item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert a minimum and a maximum value for the upper bound demand of the item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" ID Characteristics.             " << endl;
		FileInpPar <<"_________________________." << endl;
		FileInpPar <<" 1	Beta distribution with alpha=1 and beta=3;"<< endl;
		FileInpPar <<" 2	Beta distribution with alpha=2 and beta=5;" << endl;
		FileInpPar <<" 3	Beta distribution with alpha=2 and beta=2;" << endl;
		FileInpPar <<" 4	Beta distribution with alpha=0.5 and beta=0.5;" << endl;
		FileInpPar <<" 5	Beta distribution with alpha=1 and beta=1;" << endl;
		FileInpPar <<" 6	Beta distribution with alpha=3 and beta=1;" << endl;
		FileInpPar <<" 7	Beta distribution with alpha=5 and beta=2;" << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		if(NDim==3){
			FileInpPar <<"Please select the ID of the characteristic for the height of the large object: "<< endl;
			FileInpPar << endl;
			FileInpPar <<"Please select the ID of the characteristic for the height of the small item: "<< endl;
			FileInpPar << endl;
		}
		FileInpPar <<"Please select the ID of the characteristic for the number of large objects available: "<< endl;
		FileInpPar << endl;
		FileInpPar <<"Please select the ID of the characteristic for the number of different item types: "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please select the ID of the characteristic for the lower bound of the item type demand: "<< endl;
		FileInpPar << endl;		
		FileInpPar << "Please select the ID of the characteristic for the upper bound of the item type demand: "<< endl;
		FileInpPar << endl;
	}
	if(ProblemType==4){
		FileInpPar << "Please insert the minimum and maximum number of different large object types (separated by a space): "<< endl;
		FileInpPar << endl;		
		FileInpPar << "Please insert the minimum and maximum number of large objects available (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number of different item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please give a range between 0.5 and 1 to the value of the items (if the items' value is equal to its area insert 1 1), separated by a space: " << endl;
		FileInpPar << endl;
		FileInpPar << "Please insert a minimum and a maximum value for the lower bound demand of the item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert a minimum and a maximum value for the upper bound demand of the item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar <<"_________________________________________________________." << endl;	
		FileInpPar <<" ID Characteristics.             " << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" 1	Beta distribution with alpha=1 and beta=3;"<< endl;
		FileInpPar <<" 2	Beta distribution with alpha=2 and beta=5;" << endl;
		FileInpPar <<" 3	Beta distribution with alpha=2 and beta=2;" << endl;
		FileInpPar <<" 4	Beta distribution with alpha=0.5 and beta=0.5;" << endl;
		FileInpPar <<" 5	Beta distribution with alpha=1 and beta=1;" << endl;
		FileInpPar <<" 6	Beta distribution with alpha=3 and beta=1;" << endl;
		FileInpPar <<" 7	Beta distribution with alpha=5 and beta=2;" << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		if(NDim==3){
			FileInpPar <<"Please select the ID of the characteristic for the height of the large object: "<< endl;
			FileInpPar << endl;
			FileInpPar <<"Please select the ID of the characteristic for the height of the small item: "<< endl;
			FileInpPar << endl;
		}
		FileInpPar <<"Please select the ID of the characteristic for the number of different large object types: "<< endl;
		FileInpPar << endl;
		FileInpPar <<"Please select the ID of the characteristic for the number of large objects available of each type: "<< endl;
		FileInpPar << endl;
		FileInpPar <<"Please select the ID of the characteristic for the number of different item types: "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please select the ID of the characteristic for the lower bound of the item type demand: "<< endl;
		FileInpPar << endl;		
		FileInpPar << "Please select the ID of the characteristic for the upper bound of the item type demand: "<< endl;
		FileInpPar << endl;
	}
	if(ProblemType==5){
		FileInpPar << "Please insert the minimum and maximum number of different large object types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number of different item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please give a range between 0.5 and 1 to the value of the items (if the items' value is equal to its area insert 1 1), separated by a space:" << endl;
		FileInpPar << endl;
		FileInpPar << "Please insert a minimum and a maximum value for the lower bound demand of the item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert a minimum and a maximum value for the upper bound demand of the item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar <<"_________________________________________________________." << endl;	
		FileInpPar <<" ID Characteristics.             " << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" 1	Beta distribution with alpha=1 and beta=3;"<< endl;
		FileInpPar <<" 2	Beta distribution with alpha=2 and beta=5;" << endl;
		FileInpPar <<" 3	Beta distribution with alpha=2 and beta=2;" << endl;
		FileInpPar <<" 4	Beta distribution with alpha=0.5 and beta=0.5;" << endl;
		FileInpPar <<" 5	Beta distribution with alpha=1 and beta=1;" << endl;
		FileInpPar <<" 6	Beta distribution with alpha=3 and beta=1;" << endl;
		FileInpPar <<" 7	Beta distribution with alpha=5 and beta=2;" << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		if(NDim==3){
			FileInpPar <<"Please select the ID of the characteristic for the height of the large object: "<< endl;
			FileInpPar << endl;
			FileInpPar <<"Please select the ID of the characteristic for the height of the small item: "<< endl;
			FileInpPar << endl;
		}
		FileInpPar <<"Please select the ID of the characteristic for the number of different large object types: "<< endl;
		FileInpPar << endl;
		FileInpPar <<"Please select the ID of the characteristic for the number of different item types: "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please select the ID of the characteristic for the lower bound of the item type demand: "<< endl;
		FileInpPar << endl;		
		FileInpPar << "Please select the ID of the characteristic for the upper bound of the item type demand: "<< endl;
		FileInpPar << endl;
	}

	if(ProblemType==6){
		FileInpPar << "Please insert the minimum and maximum number of different item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please give a range between 0.5 and 1 to the value of the items (if the items' value is equal to its area insert 1 1), separated by a space: " << endl;
		FileInpPar << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" ID Characteristics.             " << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" 1	Beta distribution with alpha=1 and beta=3;"<< endl;
		FileInpPar <<" 2	Beta distribution with alpha=2 and beta=5;" << endl;
		FileInpPar <<" 3	Beta distribution with alpha=2 and beta=2;" << endl;
		FileInpPar <<" 4	Beta distribution with alpha=0.5 and beta=0.5;" << endl;
		FileInpPar <<" 5	Beta distribution with alpha=1 and beta=1;" << endl;
		FileInpPar <<" 6	Beta distribution with alpha=3 and beta=1;" << endl;
		FileInpPar <<" 7	Beta distribution with alpha=5 and beta=2;" << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		if(NDim==3){
			FileInpPar <<"Please select the ID of the characteristic for the height of the large object: "<< endl;
			FileInpPar << endl;
			FileInpPar <<"Please select the ID of the characteristic for the height of the small item: "<< endl;
			FileInpPar << endl;
		}
		FileInpPar <<"Please select the ID of the characteristic for the number of different item types: "<< endl;
		FileInpPar << endl;
	}
	if(ProblemType==7){
		FileInpPar << "Please insert the minimum and maximum number for the number of large objects available of each type (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number of different item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please give a range between 0.5 and 1 to the value of the items (if the items' value is equal to its area insert 1 1), separated by a space: " << endl;
		FileInpPar << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" ID Characteristics.             " << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" 1	Beta distribution with alpha=1 and beta=3;"<< endl;
		FileInpPar <<" 2	Beta distribution with alpha=2 and beta=5;" << endl;
		FileInpPar <<" 3	Beta distribution with alpha=2 and beta=2;" << endl;
		FileInpPar <<" 4	Beta distribution with alpha=0.5 and beta=0.5;" << endl;
		FileInpPar <<" 5	Beta distribution with alpha=1 and beta=1;" << endl;
		FileInpPar <<" 6	Beta distribution with alpha=3 and beta=1;" << endl;
		FileInpPar <<" 7	Beta distribution with alpha=5 and beta=2;" << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		if(NDim==3){
			FileInpPar <<"Please select the ID of the characteristic for the height of the large object: "<< endl;
			FileInpPar << endl;
			FileInpPar <<"Please select the ID of the characteristic for the height of the small item: "<< endl;
			FileInpPar << endl;
		}
		FileInpPar <<"Please select the ID of the characteristic for the number of large objects available: "<< endl;
		FileInpPar << endl;
		FileInpPar <<"Please select the ID of the characteristic for the number of different item types: "<< endl;
		FileInpPar << endl;
	}
	if(ProblemType==8){
		FileInpPar << "Please insert the minimum and maximum number of different large object types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number for the number of large objects available of each type (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number of different item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please give a range between 0.5 and 1 to the value of the items (if the items' value is equal to its area insert 1 1), separated by a space: " << endl;
		FileInpPar << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" ID Characteristics.             " << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" 1	Beta distribution with alpha=1 and beta=3;"<< endl;
		FileInpPar <<" 2	Beta distribution with alpha=2 and beta=5;" << endl;
		FileInpPar <<" 3	Beta distribution with alpha=2 and beta=2;" << endl;
		FileInpPar <<" 4	Beta distribution with alpha=0.5 and beta=0.5;" << endl;
		FileInpPar <<" 5	Beta distribution with alpha=1 and beta=1;" << endl;
		FileInpPar <<" 6	Beta distribution with alpha=3 and beta=1;" << endl;
		FileInpPar <<" 7	Beta distribution with alpha=5 and beta=2;" << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		if(NDim==3){
			FileInpPar <<"Please select the ID of the characteristic for the height of the large object: "<< endl;
			FileInpPar << endl;
			FileInpPar <<"Please select the ID of the characteristic for the height of the small item: "<< endl;
			FileInpPar << endl;
		}
		FileInpPar <<"Please select the ID of the characteristic for the number of different large object types: "<< endl;
		FileInpPar << endl;
		FileInpPar <<"Please select the ID of the characteristic for the number of large objects available of each type: "<< endl;
		FileInpPar << endl;
		FileInpPar <<"Please select the ID of the characteristic for the number of different item types: "<< endl;
		FileInpPar << endl;
	}
	if(ProblemType==9){
		FileInpPar << "Please insert the minimum and maximum number of different large object types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number of different item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please give a range between 0.5 and 1 to the value of the items (if the items' value is equal to its area insert 1 1), separated by a space: " << endl;
		FileInpPar << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" ID Characteristics.             " << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" 1	Beta distribution with alpha=1 and beta=3;"<< endl;
		FileInpPar <<" 2	Beta distribution with alpha=2 and beta=5;" << endl;
		FileInpPar <<" 3	Beta distribution with alpha=2 and beta=2;" << endl;
		FileInpPar <<" 4	Beta distribution with alpha=0.5 and beta=0.5;" << endl;
		FileInpPar <<" 5	Beta distribution with alpha=1 and beta=1;" << endl;
		FileInpPar <<" 6	Beta distribution with alpha=3 and beta=1;" << endl;
		FileInpPar <<" 7	Beta distribution with alpha=5 and beta=2;" << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		if(NDim==3){
			FileInpPar <<"Please select the ID of the characteristic for the height of the large object: "<< endl;
			FileInpPar << endl;
			FileInpPar <<"Please select the ID of the characteristic for the height of the small item: "<< endl;
			FileInpPar << endl;
		}
		FileInpPar <<"Please select the ID of the characteristic for the number of different large object types: "<< endl;
		FileInpPar << endl;
		FileInpPar <<"Please select the ID of the characteristic for the number of different item types: "<< endl;
		FileInpPar << endl;
	}
	if(ProblemType==10){
		
		FileInpPar << "Please insert the minimum and maximum number of different item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number for the item type demand (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" ID Characteristics.             " << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" 1	Beta distribution with alpha=1 and beta=3;"<< endl;
		FileInpPar <<" 2	Beta distribution with alpha=2 and beta=5;" << endl;
		FileInpPar <<" 3	Beta distribution with alpha=2 and beta=2;" << endl;
		FileInpPar <<" 4	Beta distribution with alpha=0.5 and beta=0.5;" << endl;
		FileInpPar <<" 5	Beta distribution with alpha=1 and beta=1;" << endl;
		FileInpPar <<" 6	Beta distribution with alpha=3 and beta=1;" << endl;
		FileInpPar <<" 7	Beta distribution with alpha=5 and beta=2;" << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		if(NDim==3){
			FileInpPar <<"Please select the ID of the characteristic for the height of the large object: "<< endl;
			FileInpPar << endl;
			FileInpPar <<"Please select the ID of the characteristic for the height of the small item: "<< endl;
			FileInpPar << endl;
		}
		FileInpPar << "Please select the ID of the characteristic for the number of different item types: "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please select the ID of the characteristic for the item type demand: "<< endl;
		FileInpPar << endl;
	}
	if(ProblemType==11){
		FileInpPar << "Please insert the minimum and maximum number of different large objects (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number for the available large objects (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please give a range between 0.5 and 1 to the value of the large objects (if the value  of the large object is equal to its area insert 1 1), separated by a space: " << endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number of different item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number for the item type demand (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" ID Characteristics.             " << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" 1	Beta distribution with alpha=1 and beta=3;"<< endl;
		FileInpPar <<" 2	Beta distribution with alpha=2 and beta=5;" << endl;
		FileInpPar <<" 3	Beta distribution with alpha=2 and beta=2;" << endl;
		FileInpPar <<" 4	Beta distribution with alpha=0.5 and beta=0.5;" << endl;
		FileInpPar <<" 5	Beta distribution with alpha=1 and beta=1;" << endl;
		FileInpPar <<" 6	Beta distribution with alpha=3 and beta=1;" << endl;
		FileInpPar <<" 7	Beta distribution with alpha=5 and beta=2;" << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		if(NDim==3){
			FileInpPar <<"Please select the ID of the characteristic for the height of the large object: "<< endl;
			FileInpPar << endl;
			FileInpPar <<"Please select the ID of the characteristic for the height of the small item: "<< endl;
			FileInpPar << endl;
		}
		FileInpPar << "Please select the ID of the characteristic for the number of different large object types: "<< endl;
		FileInpPar << endl;
		FileInpPar <<"Please select the ID of the characteristic for the number of large objects available of each type: "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please select the ID of the characteristic for the number of different item types: "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please select the ID of the characteristic for the item type demand: "<< endl;
		FileInpPar << endl;
	}
	if(ProblemType==12){
		FileInpPar << "Please insert the minimum and maximum number of different large objects (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please give a range between 0.5 and 1 to the value of the large objects (if the value of the large object is equal to its area insert 1 1), separated by a space:" << endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number of different item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number for the item type demand (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" ID Characteristics.             " << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" 1	Beta distribution with alpha=1 and beta=3;"<< endl;
		FileInpPar <<" 2	Beta distribution with alpha=2 and beta=5;" << endl;
		FileInpPar <<" 3	Beta distribution with alpha=2 and beta=2;" << endl;
		FileInpPar <<" 4	Beta distribution with alpha=0.5 and beta=0.5;" << endl;
		FileInpPar <<" 5	Beta distribution with alpha=1 and beta=1;" << endl;
		FileInpPar <<" 6	Beta distribution with alpha=3 and beta=1;" << endl;
		FileInpPar <<" 7	Beta distribution with alpha=5 and beta=2;" << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		if(NDim==3){
			FileInpPar <<"Please select the ID of the characteristic for the height of the large object: "<< endl;
			FileInpPar << endl;
			FileInpPar <<"Please select the ID of the characteristic for the height of the small item: "<< endl;
			FileInpPar << endl;
		}
		FileInpPar << "Please select the ID of the characteristic for the number of different large object types: "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please select the ID of the characteristic for the number of different item types: "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please select the ID of the characteristic for the item type demand: "<< endl;
		FileInpPar << endl;
	}
	if(ProblemType==13){
		FileInpPar << "Please insert the minimum and maximum number of different item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" Enter: Characteristics.             " << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" 1	Beta distribution with alpha=1 and beta=3;"<< endl;
		FileInpPar <<" 2	Beta distribution with alpha=2 and beta=5;" << endl;
		FileInpPar <<" 3	Beta distribution with alpha=2 and beta=2;" << endl;
		FileInpPar <<" 4	Beta distribution with alpha=0.5 and beta=0.5;" << endl;
		FileInpPar <<" 5	Beta distribution with alpha=1 and beta=1;" << endl;
		FileInpPar <<" 6	Beta distribution with alpha=3 and beta=1;" << endl;
		FileInpPar <<" 7	Beta distribution with alpha=5 and beta=2;" << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		if(NDim==3){
			FileInpPar <<"Please select the ID of the characteristic for the height of the large object: "<< endl;
			FileInpPar << endl;
			FileInpPar <<"Please select the ID of the characteristic for the height of the small item: "<< endl;
			FileInpPar << endl;
		}
		FileInpPar << "Please select the ID of the characteristic for the number of different item types: "<< endl;
		FileInpPar << endl;
	}
	if(ProblemType==14){
		FileInpPar << "Please insert the minimum and maximum number of different large objects (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number for the available large objects (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please give a range between 0.5 and 1 to the value of the large objects (if the value of the large object is equal to its area insert 1 1), separated by a space:" << endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number of different item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar <<"_________________________________________________________." << endl;	
		FileInpPar <<" ID Characteristics.             " << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" 1	Beta distribution with alpha=1 and beta=3;"<< endl;
		FileInpPar <<" 2	Beta distribution with alpha=2 and beta=5;" << endl;
		FileInpPar <<" 3	Beta distribution with alpha=2 and beta=2;" << endl;
		FileInpPar <<" 4	Beta distribution with alpha=0.5 and beta=0.5;" << endl;
		FileInpPar <<" 5	Beta distribution with alpha=1 and beta=1;" << endl;
		FileInpPar <<" 6	Beta distribution with alpha=3 and beta=1;" << endl;
		FileInpPar <<" 7	Beta distribution with alpha=5 and beta=2;" << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		if(NDim==3){
			FileInpPar <<"Please select the ID of the characteristic for the height of the large object: "<< endl;
			FileInpPar << endl;
			FileInpPar <<"Please select the ID of the characteristic for the height of the small item: "<< endl;
			FileInpPar << endl;
		}
		FileInpPar << "Please select the ID of the characteristic for the number of different large object types : "<< endl;
		FileInpPar << endl;
		FileInpPar <<"Please select the ID of the characteristic for the number of large objects available of each type: "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please select the ID of the characteristic for the number of different item types: "<< endl;
		FileInpPar << endl;
	}
	if(ProblemType==15){
		FileInpPar << "Please insert the minimum and maximum number of different large objects (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please give a range between 0.5 and 1 to the value of the large objects (if the value of the large objects is equal to its area insert 1 1), separated by a space: " << endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number of different item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" ID Characteristics.             " << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" 1	Beta distribution with alpha=1 and beta=3;"<< endl;
		FileInpPar <<" 2	Beta distribution with alpha=2 and beta=5;" << endl;
		FileInpPar <<" 3	Beta distribution with alpha=2 and beta=2;" << endl;
		FileInpPar <<" 4	Beta distribution with alpha=0.5 and beta=0.5;" << endl;
		FileInpPar <<" 5	Beta distribution with alpha=1 and beta=1;" << endl;
		FileInpPar <<" 6	Beta distribution with alpha=3 and beta=1;" << endl;
		FileInpPar <<" 7	Beta distribution with alpha=5 and beta=2;" << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		if(NDim==3){
			FileInpPar <<"Please select the ID of the characteristic for the height of the large object: "<< endl;
			FileInpPar << endl;
			FileInpPar <<"Please select the ID of the characteristic for the height of the small item: "<< endl;
			FileInpPar << endl;
		}
		FileInpPar << "Please select the ID of the characteristic for the number of different large object types : "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please select the  ID of the characteristic for the number of different item types: "<< endl;
		FileInpPar << endl;
	}
	if(ProblemType==16){
		FileInpPar << "Please insert the minimum and maximum number of different large objects (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number for the available large objects (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please give a range between 0.5 and 1 to the value of the large objects (if the value of the large object is equal to its area insert 1 1), separated by a space: " << endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number of different item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number for the item type demand (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" ID Characteristics.             " << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" 1	Beta distribution with alpha=1 and beta=3;"<< endl;
		FileInpPar <<" 2	Beta distribution with alpha=2 and beta=5;" << endl;
		FileInpPar <<" 3	Beta distribution with alpha=2 and beta=2;" << endl;
		FileInpPar <<" 4	Beta distribution with alpha=0.5 and beta=0.5;" << endl;
		FileInpPar <<" 5	Beta distribution with alpha=1 and beta=1;" << endl;
		FileInpPar <<" 6	Beta distribution with alpha=3 and beta=1;" << endl;
		FileInpPar <<" 7	Beta distribution with alpha=5 and beta=2;" << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		if(NDim==3){
			FileInpPar <<"Please select the ID of the characteristic for the height of the large object: "<< endl;
			FileInpPar << endl;
			FileInpPar <<"Please select the ID of the characteristic for the height of the small item: "<< endl;
			FileInpPar << endl;
		}
		FileInpPar << "Please select the  ID of the characteristic for the number of different large object types : "<< endl;
		FileInpPar << endl;
		FileInpPar <<"Please select the ID of the characteristic for the number of large objects available of each type: "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please select the  ID of the characteristic for the width of the large object: " << endl;
		FileInpPar << endl;
		FileInpPar << "Please select the  ID of the characteristic for the number of different item types: "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please select the  ID of the characteristic for the item type demand: "<< endl;
		FileInpPar << endl;
	}
	if(ProblemType==17){
		FileInpPar << "Please insert the minimum and maximum number of different large objects (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please give a range between 0.5 and 1 to the value of the large objects (if the value of the large object is equal to its area insert 1 1), separated by a space: " << endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number of different item types (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please insert the minimum and maximum number for the item type demand (separated by a space): "<< endl;
		FileInpPar << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" ID Characteristics.             " << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		FileInpPar <<" 1	Beta distribution with alpha=1 and beta=3;"<< endl;
		FileInpPar <<" 2	Beta distribution with alpha=2 and beta=5;" << endl;
		FileInpPar <<" 3	Beta distribution with alpha=2 and beta=2;" << endl;
		FileInpPar <<" 4	Beta distribution with alpha=0.5 and beta=0.5;" << endl;
		FileInpPar <<" 5	Beta distribution with alpha=1 and beta=1;" << endl;
		FileInpPar <<" 6	Beta distribution with alpha=3 and beta=1;" << endl;
		FileInpPar <<" 7	Beta distribution with alpha=5 and beta=2;" << endl;
		FileInpPar <<"_________________________________________________________." << endl;
		if(NDim==3){
			FileInpPar <<"Please select the ID of the characteristic for the height of the large object: "<< endl;
			FileInpPar << endl;
			FileInpPar <<"Please select the ID of the characteristic for the height of the small item: "<< endl;
			FileInpPar << endl;
		}
		FileInpPar << "Please select the  ID of the characteristic for the number of different large object types: "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please select the  ID of the characteristic for the width of the large object: " << endl;
		FileInpPar << endl;
		FileInpPar << "Please select the  ID of the characteristic for the number of different item types: "<< endl;
		FileInpPar << endl;
		FileInpPar << "Please select the  ID of the characteristic for the item type demand: "<< endl;
		FileInpPar << endl;
	}
	FileInpPar.close();

	cout << endl << "_____________________________________________________________"<< endl;
	cout << endl << endl << "  The input parameter file has been created! " << endl;
	cout << endl << "_____________________________________________________________"<< endl;
	cout << endl << "  Fill the empty lines of the new input parameter file with the respective parameter." << endl; 
	cout << endl << "  Save the changes made in the new input parameter file and run again the 2DPCPackGen program. Then, select ID 1 (Existing Input Parameter file) for parameter file selection." << endl;
	cout <<"_____________________________________________________________"<< endl;
	cout << endl << endl << "**** The program will be closed. ****" << endl;

	return 0;
}


int TwoDProbGen::ReadInputFile()
{
	// Reads the input parameter file	
	cout<<" Enter the input parameter file (e. g. C:\\programs\\ProblemInputPar.txt): ";
    cin>>InputParfilename;

	
	ifstream FileInput (InputParfilename);

	if(!FileInput.is_open( )){
		cout<<"It was not possible to open the file!\n";
		FileInput.clear( ); 
		exit (-1);
	}

	FileInput.getline (Trash,256,'.'); 
	FileInput.getline (Trash,256,'*'); 
	FileInput.getline (Trash,256,'.'); 
	FileInput.getline (Trash,256,':'); 
	FileInput >> NDim;
	if (FileInput.fail() || NDim > 3 || NDim <2){
		cout << endl;
		cout <<"_______________________________________________"<< endl;
		cout <<  endl <<"  Error in the input parameters file!"<< endl;
		cout <<"_______________________________________________"<< endl;
		cout << endl << "  Please check the value for the Number of dimensions which defines the problem ."<< endl;
		cout <<"_______________________________________________"<< endl;
		cout << endl << endl << "  The program will be closed." << endl;
		error=1;
		return 0;
	}

	FileInput.getline (Trash,256,':'); 
	FileInput >> ProblemType;
	if (FileInput.fail() || ProblemType > 17 || ProblemType <0){
		cout << endl;
		cout <<"_______________________________________________"<< endl;
		cout <<  endl <<"  Error in the input parameters file!"<< endl;
		cout <<"_______________________________________________"<< endl;
		cout << endl << "  Please check the value for the ID of the problem type."<< endl;
		cout <<"_______________________________________________"<< endl;
		cout << endl << endl << "  The program will be closed." << endl;
		error=1;
		return 0;
	}

	
	FileInput.getline (Trash,256,'.'); 
	FileInput.getline (Trash,256,':'); 
	FileInput >> seed;
	if (FileInput.fail() || seed > 2147483646){
		cout << endl;
		cout <<"_______________________________________________"<< endl;
		cout <<  endl <<"  Error in the input parameters file!"<< endl;
		cout <<"_______________________________________________"<< endl;
		cout << endl << "  Please check the value for the seed."<< endl;
		cout <<"_______________________________________________"<< endl;
		cout << endl << endl << "  The program will be closed." << endl;
		error=1;
		return 0;
	}
	FileInput.getline (Trash2,200,':');
	FileInput >> n_instances;
	if (FileInput.fail()){
		cout << endl;
		cout <<"_______________________________________________"<< endl;
		cout <<  endl <<"  Error in the input parameters file!"<< endl;
		cout <<"_______________________________________________"<< endl;
		cout << endl << "  Please check the value for the the number of instances."<< endl;
		cout <<"_______________________________________________"<< endl;
		cout << endl << endl << "  The program will be closed." << endl;
		error=1;
		return 0;
	}

	if(ProblemType<16){
		FileInput.getline (Trash2,200,':');
		FileInput >> min_LargeObjS >> max_LargeObjS;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			if(NDim==2) cout << endl << "  Please check the value for the the minimum and maximum size dimension of the large object."<< endl;
			else cout << endl << "  Please check the value for the the minimum and maximum size dimension of the large object base."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
	}
	else{
		FileInput.getline (Trash2,200,':');
		FileInput >> min_LargeObjW >> max_LargeObjW;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the the minimum and maximum width of the Large Object."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
	}
	FileInput.getline (Trash,256,':');
	FileInput >> min_ItemS >> max_ItemS;

	if (FileInput.fail()){
		cout << endl;
		cout <<"_______________________________________________"<< endl;
		cout <<  endl <<"  Error in the input parameters file!"<< endl;
		cout <<"_______________________________________________"<< endl;
		cout << endl << "  Please check the value for the the minimum and maximum size dimension of the items."<< endl;
		cout <<"_______________________________________________"<< endl;
		cout << endl << endl << "  The program will be closed." << endl;
		error=1;
		return 0;
	}
	if(NDim==3){
		FileInput.getline (Trash2,200,':');
		FileInput >> min_LargeObjH >> max_LargeObjH;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the the minimum and maximum size height of the large object."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash2,200,':');
		FileInput >> min_ItemH >> max_ItemH;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the the minimum and maximum size height of the items."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
	}

	FileInput.getline (Trash,256,'.');
	FileInput.getline (Trash,256,'.');
	FileInput.getline (Trash,256, '.');
	FileInput.getline (Trash,256,';');
	FileInput.getline (Trash,256,';');
	FileInput.getline (Trash,256,';');
	FileInput.getline (Trash,256,';');
	FileInput.getline (Trash,256,';');
	FileInput.getline (Trash,256,';');
	FileInput.getline (Trash,256,';');
	FileInput.getline (Trash,256,';');
	FileInput.getline (Trash,256,';');
	FileInput.getline (Trash,256,';');
	FileInput.getline (Trash,256,';');
	FileInput.getline (Trash,256,';');
	FileInput.getline (Trash,256,';');
	FileInput.getline (Trash,256,';');
	FileInput.getline (Trash,256,';');
	FileInput.getline (Trash,256,';');
	FileInput.getline (Trash,256,'.');
	FileInput.getline (Trash,256,':');
	FileInput  >> Item_SizSh;
	
	if (FileInput.fail()){
		cout << endl;
		cout <<"_______________________________________________"<< endl;
		cout <<  endl <<"  Error in the input parameters file!"<< endl;
		cout <<"_______________________________________________"<< endl;
		cout << endl << "  Please check the value for the the ID of the size and shape of the items."<< endl;
		cout <<"_______________________________________________"<< endl;
		cout << endl << endl << "  The program will be closed." << endl;
		error=1;
		return 0;
	}

	if(ProblemType<16){
		FileInput.getline (Trash,256,':');
		FileInput  >> LargeObj_SizSh;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the the ID of the size and shape of the large object."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
	}


	/** Errors of inconsistent input data **/
	if(ProblemType<16){
		if (min_LargeObjS>max_LargeObjS){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum size dimension of the large object, the minimum must be smaller or equal to the maximum  (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum dimension size for large object= " << min_LargeObjS << " and Maximum dimension size for large object= " << max_LargeObjS<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_ItemS > min_LargeObjS ){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum size dimension of the large object or the minimum size dimension for the small items (the minimum for the small item must be smaller or equal to the minimum for the large object)!"<< endl;
			cout << endl << " Current Parameters: Minimum dimension size for large object= " << min_LargeObjS << " and Minimum dimension size for the small item types= " << min_ItemS<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}

	}
	else{
		if(min_LargeObjW > max_LargeObjW){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum Width of the large object, the minimum must be smaller or equal to the maximum  (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum dimension size for large object= " << min_LargeObjW << " and Maximum dimension size for large object= " << max_LargeObjW<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_ItemS > min_LargeObjW ){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum size dimension of the large object or the minimum size dimension for the small items (the minimum for the small item must be smaller or equal to the minimum for the large object)!"<< endl;
			cout << endl << " Current Parameters: Minimum dimension size for large object= " << min_LargeObjW << " and Minimum dimension size for the small item types= " << min_ItemS<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}

	}
	if (min_ItemS>max_ItemS){
		cout << endl;
		cout <<"_____________________________________________________________________________"<< endl;
		cout << endl << "	 Error in the input parameters file! " << endl;
		cout <<"_____________________________________________________________________________"<< endl;
		cout << endl << " Change the range for the minimum and maximum size dimension of the small item types, the minimum must be smaller or equal to the maximum  (min<=max)!"<< endl;
		cout << endl << " Current Parameters: Minimum dimension size of the item types= " << min_ItemS << " and Maximum dimension size of the item types= " << max_ItemS<< endl;
		cout <<"_____________________________________________________________________________"<< endl;
		cout << endl << endl << "The program will be closed." << endl;
		error=1;
		return 0;
	}
	if(ProblemType<16){
		if (min_ItemS>max_LargeObjS || max_ItemS> max_LargeObjS){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The range for the minimum and maximum size dimension of the small item must be contained in the range for the minimum and maximum size dimension of the large object!"<< endl;
			cout << endl << " Please change the range for the size dimension of the large object or the range for the size dimension of the small items!"<< endl;
			if(min_ItemS>max_LargeObjS){
				cout << endl << " Current Parameters: Maximum dimension size for large object= " << max_LargeObjS << " and Minimum dimension size for the small item type= " << min_ItemS<< endl;
			}
			if(max_ItemS> max_LargeObjS){
				cout << endl << " Current Parameters:  Maximum dimension size for large object= " << max_LargeObjS << " and Maximum dimension size for the small item type= " << max_ItemS<< endl;
			}
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
	}
	else{
		if (min_ItemS>max_LargeObjW || max_ItemS> max_LargeObjW){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The range for the minimum and maximum size dimension of the small item must be contained in the range for the minimum and maximum size dimension of the large object!"<< endl;
			cout << endl << " Please change the range for the size dimension of the large object or the range for the size dimension of the small items!"<< endl;
			if(min_ItemS>max_LargeObjW){
				cout << endl << " Current Parameters: Maximum dimension size for large object= " << max_LargeObjW << " and Minimum dimension size for the small item type= " << min_ItemS<< endl;
			}
			if(max_ItemS> max_LargeObjW){
				cout << endl << " Current Parameters:  Maximum dimension size for large object= " << max_LargeObjW << " and Maximum dimension size for the small item type= " << max_ItemS<< endl;
			}
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}

	}
	
	if(NDim==3){
		if (min_LargeObjH>max_LargeObjH){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Please change the range for the minimum and maximum height of the large object, the minimum must be smaller or equal to the maximum  (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum height of large object= " << min_LargeObjH << " and Maximum height of large object= " << max_LargeObjH<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_ItemH>max_ItemH){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Please change the range for the minimum and maximum height of the large object, the minimum must be smaller or equal to the maximum  (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum height of small item types= " << min_ItemH << " and Maximum height of small item types= " << max_ItemH<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_ItemH>min_LargeObjH){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum size height of the large object or the minimum size height for the small items (the minimum for the small item must be smaller or equal to the minimum for the large object)!"<< endl;
			cout << endl << " Current Parameters: Minimum dimension size for large object= " << min_LargeObjH << " and Minimum dimension size for the small item types= " << min_ItemH << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_ItemH>max_LargeObjH || max_ItemH> max_LargeObjH){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The range for the minimum and maximum height of the small items must be contained in the range for the minimum and maximum height of the large object!"<< endl;
			cout << endl << " Please change the range for the height of the large object or the range for the height of the small items!"<< endl;
			if(min_ItemH>max_LargeObjH){
				cout << endl << " Current Parameters: Maximum height of large objects= " << max_LargeObjH << " and Minimum height of the small item types= " << min_ItemH<< endl;
			}
			if(max_ItemH> max_LargeObjH){
				cout << endl << " Current Parameters:  Maximum height of large objects= " << max_LargeObjH << " and Maximum height of the small item types= " << max_ItemH<< endl;
			}
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
	}

	
	if(ProblemType==1){
		if(NDim==3){
			FileInput.getline (Trash,256,'.');
			FileInput.getline (Trash,256,'.');
			FileInput.getline (Trash,256,'.');
			FileInput.getline (Trash,256,';');
			FileInput.getline (Trash,256,';');
			FileInput.getline (Trash,256,';');
			FileInput.getline (Trash,256,';');
			FileInput.getline (Trash,256,';');
			FileInput.getline (Trash,256,';');
			FileInput.getline (Trash,256,';');
			FileInput.getline (Trash,256,'.');
			FileInput.getline (Trash,256,':');
			FileInput >> HLargeObj_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the large object."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
			FileInput >> HItem_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the small items."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}

			if (HLargeObj_Dist>7 || HLargeObj_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the large objects' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HLargeObj_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << " The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (HItem_Dist>7 || HItem_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the small items' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HItem_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << " The program will be closed." << endl;
				error=1;
				return 0;
			}
		}

	}

	if(ProblemType==2){

		FileInput.getline (Trash,256,':');
		FileInput >> min_nItems >> max_nItems;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the minimum and maximum number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_ItemV >> max_ItemV;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the range for the value of the items"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_DItemL >> max_DItemL;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the minimum and a maximum values for the lower bound demand of the item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		
		FileInput.getline (Trash,256,':');
		FileInput >> min_DItemU >> max_DItemU;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the minimum and a maximum values for the upper bound demand of the item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,':');

		if(NDim==3){
			FileInput >> HLargeObj_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the large object."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
			FileInput >> HItem_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the small items."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
		}
		FileInput >> n_ItemsDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> DItemL_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the lower bound of the item type demand."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> DItemU_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the upper bound of the item type demand."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		/** Errors of inconsistent input data **/

		if (min_nItems>max_nItems){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different item types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << " and Maximum number of different item types= " << max_nItems<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==2){
			if (max_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << " Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Maximum number of different item types= " << max_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << "Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}

		}
		if(NDim==3){
			if (min_ItemS == min_LargeObjS || min_ItemS > min_LargeObjS || max_ItemS > min_LargeObjS ){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The minimum and the maximum sizes for the base  of the item must be contained in the range defined by the minimum and maximum size for the base of the Large Object." << endl;
				cout << endl << " Current Parameters for the Items: Minimum size for the base= " << min_ItemS << " Maximum size for the base= " << max_ItemS <<  endl;
				cout << endl << " Current Parameters for the Large Object: Minimum size for the base= " << min_LargeObjS << " Maximum size for the base= " << max_LargeObjS <<  endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if ( min_ItemH > min_LargeObjH || min_ItemH == min_LargeObjH || max_ItemH > min_LargeObjH ){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The minimum and the maximum sizes for the height of the item must be contained in the range defined by the minimum and maximum size for height of the Large Object." << endl;
				cout << endl << " Current Parameters for the Items: Minimum height= " << min_ItemH << " Maximum height= " << max_ItemH <<  endl;
				cout << endl << " Current Parameters for the Large Object: Minimum height= " << min_LargeObjH << " Maximum height= " << max_LargeObjH <<  endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-min_ItemH +1) || max_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-min_ItemH +1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << "Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}

		}

		if (min_ItemV>max_ItemV){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "The minimum number of the range for the item value calculation must be smaller or equal to the maximum number of the range (min<=max)!" << endl;
			cout << endl << " Current Parameters: Minimum= " << min_ItemV << " Maximum= " << max_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_ItemV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The minimum number of the range for the item value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << min_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (max_ItemV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The maximum number of the range for the item value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Maximum= " << max_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_DItemL>max_DItemL){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum value for the item lower bound demand, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum lower bound demand= " << min_DItemL << " and Maximum lower bound demand= " << max_DItemL<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}
		if (min_DItemU>max_DItemU){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum value for the item upper bound demand, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum lower bound demand= " << min_DItemU << " and Maximum lower bound demand= " << max_DItemU<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}
		if (min_DItemL>min_DItemU && max_DItemL>max_DItemU){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Revise the minimum and maximum values for the lower and upper bound demand.The ranges are not feasible! (Min LowerBound <= Min Upper bound and Max Lower Bound <= Max UpperBound)"<< endl;
			cout << endl << " Current Parameters: Minimum lower bound demand= " << min_DItemL << " and Minimum upper bound demand= " << min_DItemU<< endl;
			cout << endl << " Maximum lower bound demand= " << max_DItemL << " and Maximum upper bound demand= " << max_DItemU<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}

		if (n_ItemsDist>7 || n_ItemsDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_ItemsDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}
		if (DItemL_Dist>7 || DItemL_Dist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the lower bound demand of the item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << DItemL_Dist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}
		if (DItemU_Dist>7 || DItemU_Dist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the upper bound demand of the item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << DItemU_Dist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==3){

			if (HLargeObj_Dist>7 || HLargeObj_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the large objects' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HLargeObj_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (HItem_Dist>7 || HItem_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the small items' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HItem_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}
	}
	if(ProblemType==3){
		
		FileInput.getline (Trash,256,':');
		FileInput >> min_LargeObjType >> max_LargeObjType;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the values for the minimum and maximum number of large objects available."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_nItems >> max_nItems;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the minimum and maximum number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_ItemV >> max_ItemV;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the range for the value of the items"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_DItemL >> max_DItemL;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the minimum and a maximum values for the lower bound demand of the item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		FileInput.getline (Trash,256,':');
		FileInput >> min_DItemU >> max_DItemU;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the minimum and a maximum values for the upper bound demand of the item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,':');

		if(NDim==3){
			FileInput >> HLargeObj_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the large object."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
			FileInput >> HItem_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the small items."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
		}
		FileInput >> DLargeObj_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of large objects available."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		FileInput.getline (Trash,256,':');
		FileInput >> n_ItemsDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> DItemL_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the lower bound of the item type demand."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> DItemU_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the upper bound of the item type demand."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		/** Errors of inconsistent input data **/

		if (min_LargeObjType>max_LargeObjType){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of large objects available of each type, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of large objects available of each type= " << min_LargeObjType << " and Maximum number of large objects available of each type= " << max_LargeObjType<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}
		if (min_nItems>max_nItems){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different item types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << " and Maximum number of different item types= " << max_nItems<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==2){
			if (max_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << " Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Maximum number of different item types= " << max_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}

			if (min_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << "Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}
		if(NDim==3){
			if (min_ItemS == min_LargeObjS || min_ItemS > min_LargeObjS || max_ItemS > min_LargeObjS ){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The minimum and the maximum sizes for the base  of the item must be contained in the range defined by the minimum and maximum size for the base of the Large Object." << endl;
				cout << endl << " Current Parameters for the Items: Minimum size for the base= " << min_ItemS << " Maximum size for the base= " << max_ItemS <<  endl;
				cout << endl << " Current Parameters for the Large Object: Minimum size for the base= " << min_LargeObjS << " Maximum size for the base= " << max_LargeObjS <<  endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if ( min_ItemH > min_LargeObjH || min_ItemH == min_LargeObjH || max_ItemH > min_LargeObjH ){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The minimum and the maximum sizes for the height of the item must be contained in the range defined by the minimum and maximum size for height of the Large Object." << endl;
				cout << endl << " Current Parameters for the Items: Minimum height= " << min_ItemH << " Maximum height= " << max_ItemH <<  endl;
				cout << endl << " Current Parameters for the Large Object: Minimum height= " << min_LargeObjH << " Maximum height= " << max_LargeObjH <<  endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-min_ItemH +1) || max_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-min_ItemH +1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << "Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}

		}

		if (min_ItemV>max_ItemV){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "The minimum number of the range for the item value calculation must be smaller or equal to the maximum number of the range (min<=max)!" << endl;
			cout << endl << " Current Parameters: Minimum= " << min_ItemV << " Maximum= " << max_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_ItemV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The minimum number of the range for the item value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << min_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (max_ItemV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The maximum number of the range for the item value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Maximum= " << max_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_DItemL>max_DItemL){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum value for the item lower bound demand, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum lower bound demand= " << min_DItemL << " and Maximum lower bound demand= " << max_DItemL<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_DItemU>max_DItemU){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum value for the item upper bound demand, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum lower bound demand= " << min_DItemU << " and Maximum lower bound demand= " << max_DItemU<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}
		if (min_DItemL>min_DItemU && max_DItemL>max_DItemU){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Revise the minimum and maximum values for the lower and upper bound demand.The ranges are not feasible! (Min LowerBound <= Min Upper bound and Max LowerBound <= Max UpperBound)"<< endl;
			cout << endl << " Current Parameters: Minimum lower bound demand= " << min_DItemL << " and Minimum upper bound demand= " << min_DItemU<< endl;
			cout << endl << " Maximum lower bound demand= " << max_DItemL << " and Maximum upper bound demand= " << max_DItemU<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
	
		if (DLargeObj_Dist>7 || DLargeObj_Dist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of large object types available from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << DLargeObj_Dist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}
		if (n_ItemsDist>7 || n_ItemsDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_ItemsDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (DItemL_Dist>7 || DItemL_Dist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the lower bound demand of the item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << DItemL_Dist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (DItemU_Dist>7 || DItemU_Dist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the upper bound demand of the item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << DItemU_Dist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==3){
	
			if (HLargeObj_Dist>7 || HLargeObj_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the large objects' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HLargeObj_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (HItem_Dist>7 || HItem_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the small items' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HItem_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}

	}
	if(ProblemType==4){

		FileInput.getline (Trash,256,':');
		FileInput >> min_nLargeObj >> max_nLargeObj;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the values for the minimum and maximum number of different large object types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		

		FileInput.getline (Trash,256,':');
		FileInput >> min_LargeObjType >> max_LargeObjType;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the values for the minimum and maximum number of large objects available."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_nItems >> max_nItems;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the minimum and maximum number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_ItemV >> max_ItemV;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the range for the value of the items"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_DItemL >> max_DItemL;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the minimum and a maximum values for the lower bound demand of the item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		FileInput.getline (Trash,256,':');
		FileInput >> min_DItemU >> max_DItemU;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the minimum and a maximum values for the upper bound demand of the item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,':');

		if(NDim==3){
			FileInput >> HLargeObj_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the large object."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
			FileInput >> HItem_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the small items."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
		}
		FileInput >> n_LargeObjDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different large objects."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> DLargeObj_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number different large objects available of each type."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> n_ItemsDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> DItemL_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the lower bound of the item type demand."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> DItemU_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the upper bound of the item type demand."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}


		/** Errors of inconsistent input data **/

		if (min_nLargeObj>max_nLargeObj){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different large object types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of large object types= " << min_nLargeObj << " and Maximum number of large object types= " << max_nLargeObj<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==2){
			if (max_nLargeObj>(max_LargeObjS-min_LargeObjS+1)*(max_LargeObjS-min_LargeObjS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different large objects given the minimum and maximum size dimension of the Large Object is " << (max_LargeObjS-min_LargeObjS+1)*(max_LargeObjS-min_LargeObjS+1) << " **"<< endl;
				cout << endl << " Change the range for the minimum and maximum number of different large objects or the range for the size dimension of the large objects!" << endl; 
				cout << endl << " Current Parameters: Maximum number of different large object types= " << max_nLargeObj << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nLargeObj>(max_LargeObjS-min_LargeObjS+1)*(max_LargeObjS-min_LargeObjS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different large objects given the minimum and maximum size dimension of the Large Object is " << (max_LargeObjS-min_LargeObjS+1)*(max_LargeObjS-min_LargeObjS+1) << endl;
				cout << endl << " Change the range for the minimum and maximum number of different large objects or the range for the size dimension of the large objects!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different large object types= " << min_nLargeObj << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}
		if(NDim==3){
			if (min_ItemS == min_LargeObjS || min_ItemS > min_LargeObjS || max_ItemS > min_LargeObjS ){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The minimum and the maximum sizes for the base  of the item must be contained in the range defined by the minimum and maximum size for the base of the Large Object." << endl;
				cout << endl << " Current Parameters for the Items: Minimum size for the base= " << min_ItemS << " Maximum size for the base= " << max_ItemS <<  endl;
				cout << endl << " Current Parameters for the Large Object: Minimum size for the base= " << min_LargeObjS << " Maximum size for the base= " << max_LargeObjS <<  endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if ( min_ItemH > min_LargeObjH || min_ItemH == min_LargeObjH || max_ItemH > min_LargeObjH ){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The minimum and the maximum sizes for the height of the item must be contained in the range defined by the minimum and maximum size for height of the Large Object." << endl;
				cout << endl << " Current Parameters for the Items: Minimum height= " << min_ItemH << " Maximum height= " << max_ItemH <<  endl;
				cout << endl << " Current Parameters for the Large Object: Minimum height= " << min_LargeObjH << " Maximum height= " << max_LargeObjH <<  endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-min_ItemH +1) || max_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-min_ItemH +1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << "Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}

		}

		if (min_nItems>max_nItems){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different item types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << " and Maximum number of different item types= " << max_nItems<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}

		if(NDim==2){
			if (max_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << " Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Maximum number of different item types= " << max_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << "Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}
		if (min_LargeObjType>max_LargeObjType){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of large objects available of each type, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of large objects available of each type= " << min_LargeObjType << " and Maximum number of large objects available of each type= " << max_LargeObjType<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		
		if (min_ItemV>max_ItemV){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "The minimum number of the range for the item value calculation must be smaller or equal to the maximum number of the range (min<=max)!" << endl;
			cout << endl << " Current Parameters: Minimum= " << min_ItemV << " Maximum= " << max_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_ItemV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "The minimum number of the range for the item value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << min_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (max_ItemV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The maximum number of the range for the item value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Maximum= " << max_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_DItemL>max_DItemL){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum value for the item lower bound demand, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum lower bound demand= " << min_DItemL << " and Maximum lower bound demand= " << max_DItemL<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_DItemU>max_DItemU){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum value for the item upper bound demand, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum lower bound demand= " << min_DItemU << " and Maximum lower bound demand= " << max_DItemU<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}
		if (min_DItemL>min_DItemU && max_DItemL>max_DItemU){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Revise the minimum and maximum values for the lower and upper bound demand.The ranges are not feasible! (Min LowerBound <= Min Upper bound and Max LowerBound <= Max UpperBound)"<< endl;
			cout << endl << " Current Parameters: Minimum lower bound demand= " << min_DItemL << " and Minimum upper bound demand= " << min_DItemU<< endl;
			cout << endl << " Maximum lower bound demand= " << max_DItemL << " and Maximum upper bound demand= " << max_DItemU<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}
		if (n_LargeObjDist>7 || n_LargeObjDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different large objects from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_LargeObjDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (DLargeObj_Dist>7 || DLargeObj_Dist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of large object types available from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << DLargeObj_Dist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}
		if (n_ItemsDist>7 || n_ItemsDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_ItemsDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (DItemL_Dist>7 || DItemL_Dist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the lower bound demand of the item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << DItemL_Dist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (DItemU_Dist>7 || DItemU_Dist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the upper bound demand of the item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << DItemU_Dist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==3){
			
			if (HLargeObj_Dist>7 || HLargeObj_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the large objects' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HLargeObj_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (HItem_Dist>7 || HItem_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the small items' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HItem_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}

	}
	if(ProblemType==5){
		FileInput.getline (Trash,256,':');
		FileInput >> min_nLargeObj >> max_nLargeObj;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the values for the minimum and maximum number of different large object types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_nItems >> max_nItems;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the minimum and maximum number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_ItemV >> max_ItemV;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the range for the value of the items"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_DItemL >> max_DItemL;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the minimum and a maximum values for the lower bound demand of the item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		FileInput.getline (Trash,256,':');
		FileInput >> min_DItemU >> max_DItemU;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the minimum and a maximum values for the upper bound demand of the item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,':');

		if(NDim==3){
			FileInput >> HLargeObj_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the large object."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
			FileInput >> HItem_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the small items."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
		}
		FileInput >> n_LargeObjDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different large objects."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> n_ItemsDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> DItemL_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the lower bound of the item type demand."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> DItemU_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the upper bound of the item type demand."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		/** Errors of inconsistent input data **/

		if (min_nLargeObj>max_nLargeObj){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different large object types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of large object types= " << min_nLargeObj << " and Maximum number of large object types= " << max_nLargeObj<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}

		if (min_nItems>max_nItems){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different item types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << " and Maximum number of different item types= " << max_nItems<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==2){
			if (max_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << " Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Maximum number of different item types= " << max_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << "Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}
		if(NDim==3){
			if (min_ItemS == min_LargeObjS || min_ItemS > min_LargeObjS || max_ItemS > min_LargeObjS ){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The minimum and the maximum sizes for the base  of the item must be contained in the range defined by the minimum and maximum size for the base of the Large Object." << endl;
				cout << endl << " Current Parameters for the Items: Minimum size for the base= " << min_ItemS << " Maximum size for the base= " << max_ItemS <<  endl;
				cout << endl << " Current Parameters for the Large Object: Minimum size for the base= " << min_LargeObjS << " Maximum size for the base= " << max_LargeObjS <<  endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if ( min_ItemH > min_LargeObjH || min_ItemH == min_LargeObjH || max_ItemH > min_LargeObjH ){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The minimum and the maximum sizes for the height of the item must be contained in the range defined by the minimum and maximum size for height of the Large Object." << endl;
				cout << endl << " Current Parameters for the Items: Minimum height= " << min_ItemH << " Maximum height= " << max_ItemH <<  endl;
				cout << endl << " Current Parameters for the Large Object: Minimum height= " << min_LargeObjH << " Maximum height= " << max_LargeObjH <<  endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-min_ItemH +1) || max_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-min_ItemH +1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << "Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}

		}

		if (min_ItemV>max_ItemV){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "The minimum number of the range for the item value calculation must be smaller or equal to the maximum number of the range (min<=max)!" << endl;
			cout << endl << " Current Parameters: Minimum= " << min_ItemV << " Maximum= " << max_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_ItemV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The minimum number of the range for the item value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << min_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (max_ItemV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The maximum number of the range for the item value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Maximum= " << max_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_DItemL>max_DItemL){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum value for the item lower bound demand, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum lower bound demand= " << min_DItemL << " and Maximum lower bound demand= " << max_DItemL<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_DItemU>max_DItemU){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum value for the item upper bound demand, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum lower bound demand= " << min_DItemU << " and Maximum lower bound demand= " << max_DItemU<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}
		if (min_DItemL>min_DItemU && max_DItemL>max_DItemU){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Revise the minimum and maximum values for the lower and upper bound demand.The ranges are not feasible! (Min LowerBound <= Min Upper bound and Max LowerBound <= Max UpperBound)"<< endl;
			cout << endl << " Current Parameters: Minimum lower bound demand= " << min_DItemL << " and Minimum upper bound demand= " << min_DItemU<< endl;
			cout << endl << " Maximum lower bound demand= " << max_DItemL << " and Maximum upper bound demand= " << max_DItemU<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (n_LargeObjDist>7 || n_LargeObjDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different large objects from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_LargeObjDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (n_ItemsDist>7 || n_ItemsDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_ItemsDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (DItemL_Dist>7 || DItemL_Dist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the lower bound demand of the item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << DItemL_Dist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (DItemU_Dist>7 || DItemU_Dist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the upper bound demand of the item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << DItemU_Dist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==3){
			if (HLargeObj_Dist>7 || HLargeObj_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the large objects' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HLargeObj_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (HItem_Dist>7 || HItem_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the small items' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HItem_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}


	}

	if(ProblemType==6){
		FileInput.getline (Trash,256,':');
		FileInput >> min_nItems >> max_nItems;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the minimum and maximum number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_ItemV >> max_ItemV;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the range for the value of the items"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,':');

		if(NDim==3){
			FileInput >> HLargeObj_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the large object."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
			FileInput >> HItem_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the small items."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
		}
		FileInput >> n_ItemsDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		/** Errors of inconsistent input data **/

		if (min_nItems>max_nItems){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different item types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << " and Maximum number of different item types= " << max_nItems<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_ItemV>max_ItemV){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "The minimum number of the range for the item value calculation must be smaller or equal to the maximum number of the range (min<=max)!" << endl;
			cout << endl << " Current Parameters: Minimum= " << min_ItemV << " Maximum= " << max_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_ItemV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The minimum number of the range for the item value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << min_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (max_ItemV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The maximum number of the range for the item value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Maximum= " << max_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (n_ItemsDist>7 || n_ItemsDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_ItemsDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==3){
		
			if (HLargeObj_Dist>7 || HLargeObj_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the large objects' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HLargeObj_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (HItem_Dist>7 || HItem_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the small items' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HItem_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}

	}

	if(ProblemType==7){
		
		FileInput.getline (Trash,256,':');
		FileInput >> min_LargeObjType >> max_LargeObjType;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the values for the minimum and maximum number of large objects available."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_nItems >> max_nItems;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the minimum and maximum number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_ItemV >> max_ItemV;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the range for the value of the items"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,':');

		if(NDim==3){
			FileInput >> HLargeObj_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the large object."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
			FileInput >> HItem_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the small items."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
		}
		FileInput >> DLargeObj_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number different large objects available of each type."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> n_ItemsDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

	
		/** Errors of inconsistent input data **/

		if (min_LargeObjType>max_LargeObjType){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of large objects available of each type, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of large objects available of each type= " << min_LargeObjType << " and Maximum number of large objects available of each type= " << max_LargeObjType<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_nItems>max_nItems){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different item types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << " and Maximum number of different item types= " << max_nItems<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_ItemV>max_ItemV){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "The minimum number of the range for the item value calculation must be smaller or equal to the maximum number of the range (min<=max)!" << endl;
			cout << endl << " Current Parameters: Minimum= " << min_ItemV << " Maximum= " << max_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_ItemV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The minimum number of the range for the item value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << min_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (max_ItemV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The maximum number of the range for the item value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Maximum= " << max_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}

		
		if (DLargeObj_Dist>7 || DLargeObj_Dist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of large objects available from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << DLargeObj_Dist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}
		if (n_ItemsDist>7 || n_ItemsDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_ItemsDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==3){
			
			if (HLargeObj_Dist>7 || HLargeObj_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the large objects' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HLargeObj_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (HItem_Dist>7 || HItem_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the small items' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HItem_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}

		
	}

	if(ProblemType==8){
		FileInput.getline (Trash,256,':');
		FileInput >> min_nLargeObj >> max_nLargeObj;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the values for the minimum and maximum number of different large object types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_LargeObjType >> max_LargeObjType;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the values for the minimum and maximum number of large objects available."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_nItems >> max_nItems;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the minimum and maximum number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_ItemV >> max_ItemV;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the range for the value of the items"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,':');

		if(NDim==3){
			FileInput >> HLargeObj_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the large object."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
			FileInput >> HItem_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the small items."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
		}
		FileInput >> n_LargeObjDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different large objects."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> DLargeObj_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number different large objects available of each type."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> n_ItemsDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		/** Errors of inconsistent input data **/

		if (min_nLargeObj>max_nLargeObj){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different large object types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of large object types= " << min_nLargeObj << " and Maximum number of large object types= " << max_nLargeObj<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==2){
			if (max_nLargeObj>(max_LargeObjS-min_LargeObjS+1)*(max_LargeObjS-min_LargeObjS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different large objects given the minimum and maximum size dimension of the Large Object is " << (max_LargeObjS-min_LargeObjS+1)*(max_LargeObjS-min_LargeObjS+1) << " **"<< endl;
				cout << endl << " Change the range for the minimum and maximum number of different large objects or the range for the size dimension of the large objects!" << endl; 
				cout << endl << " Current Parameters: Maximum number of different large object types= " << max_nLargeObj << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}

			if (min_nLargeObj>(max_LargeObjS-min_LargeObjS+1)*(max_LargeObjS-min_LargeObjS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different large objects given the minimum and maximum size dimension of the Large Object is " << (max_LargeObjS-min_LargeObjS+1)*(max_LargeObjS-min_LargeObjS+1) << endl;
				cout << endl << " Change the range for the minimum and maximum number of different large objects or the range for the size dimension of the large objects!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different large object types= " << min_nLargeObj << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}

		if (min_LargeObjType>max_LargeObjType){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of large objects available of each type, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of large objects available of each type= " << min_LargeObjType << " and Maximum number of large objects available of each type= " << max_LargeObjType<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_nItems>max_nItems){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different item types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << " and Maximum number of different item types= " << max_nItems<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_ItemV>max_ItemV){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "The minimum number of the range for the item value calculation must be smaller or equal to the maximum number of the range (min<=max)!" << endl;
			cout << endl << " Current Parameters: Minimum= " << min_ItemV << " Maximum= " << max_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_ItemV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The minimum number of the range for the item value calculation must be smaller or equal to 1! "<< endl;
			cout << endl << " Current Parameters: Minimum= " << min_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (max_ItemV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The maximum number of the range for the item value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Maximum= " << max_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}

		if (n_LargeObjDist>7 || n_LargeObjDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different large objects from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_LargeObjDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (DLargeObj_Dist>7 || DLargeObj_Dist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of large object types available from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << DLargeObj_Dist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}
		if (n_ItemsDist>7 || n_ItemsDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_ItemsDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}	
		if(NDim==3){
	
			if (HLargeObj_Dist>7 || HLargeObj_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the large objects' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HLargeObj_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (HItem_Dist>7 || HItem_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the small items' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HItem_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}

	}

	if(ProblemType==9){
		FileInput.getline (Trash,256,':');
		FileInput >> min_nLargeObj >> max_nLargeObj;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the values for the minimum and maximum number of different large object types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_nItems >> max_nItems;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the minimum and maximum number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_ItemV >> max_ItemV;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the range for the value of the items"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,':');

		if(NDim==3){
			FileInput >> HLargeObj_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the large object."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
			FileInput >> HItem_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the small items."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
		}
		FileInput >> n_LargeObjDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different large objects."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> n_ItemsDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		if (min_nLargeObj>max_nLargeObj){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different large object types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of large object types= " << min_nLargeObj << " and Maximum number of large object types= " << max_nLargeObj<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}

		if (min_nItems>max_nItems){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different item types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << " and Maximum number of different item types= " << max_nItems<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_ItemV>max_ItemV){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "The minimum number of the range for the item value calculation must be smaller or equal to the maximum number of the range (min<=max)!" << endl;
			cout << endl << " Current Parameters: Minimum= " << min_ItemV << " Maximum= " << max_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_ItemV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The minimum number of the range for the item value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << min_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (max_ItemV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The maximum number of the range for the item value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Maximum= " << max_ItemV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}

		if (n_LargeObjDist>7 || n_LargeObjDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different large objects from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_LargeObjDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (n_ItemsDist>7 || n_ItemsDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_ItemsDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==3){
		
			if (HLargeObj_Dist>7 || HLargeObj_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the large objects' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HLargeObj_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (HItem_Dist>7 || HItem_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the small items' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HItem_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}

	}

	if(ProblemType==10){
		
		FileInput.getline (Trash,256,':');
		FileInput >> min_nItems >> max_nItems;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the minimum and maximum number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_DItemU >> max_DItemU;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the minimum and maximum values for the item type demand"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,':');

		if(NDim==3){
			FileInput >> HLargeObj_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the large object."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
			FileInput >> HItem_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the small items."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
		}
		FileInput >> n_ItemsDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> DItemU_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the item type demand."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		/** Errors of inconsistent input data **/

		if (min_nItems>max_nItems){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different item types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << " and Maximum number of different item types= " << max_nItems<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==2){
			if (max_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << " Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Maximum number of different item types= " << max_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << "Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}
		if(NDim==3){
			if (min_ItemS == min_LargeObjS || min_ItemS > min_LargeObjS || max_ItemS > min_LargeObjS ){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The minimum and the maximum sizes for the base  of the item must be contained in the range defined by the minimum and maximum size for the base of the Large Object." << endl;
				cout << endl << " Current Parameters for the Items: Minimum size for the base= " << min_ItemS << " Maximum size for the base= " << max_ItemS <<  endl;
				cout << endl << " Current Parameters for the Large Object: Minimum size for the base= " << min_LargeObjS << " Maximum size for the base= " << max_LargeObjS <<  endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if ( min_ItemH > min_LargeObjH || min_ItemH == min_LargeObjH || max_ItemH > min_LargeObjH ){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The minimum and the maximum sizes for the height of the item must be contained in the range defined by the minimum and maximum size for height of the Large Object." << endl;
				cout << endl << " Current Parameters for the Items: Minimum height= " << min_ItemH << " Maximum height= " << max_ItemH <<  endl;
				cout << endl << " Current Parameters for the Large Object: Minimum height= " << min_LargeObjH << " Maximum height= " << max_LargeObjH <<  endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-min_ItemH +1) || max_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-min_ItemH +1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << "Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}

		}

		if (min_DItemU>max_DItemU){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum value for the item upper bound demand, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum lower bound demand= " << min_DItemU << " and Maximum lower bound demand= " << max_DItemU<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}
		

		if (n_ItemsDist>7 || n_ItemsDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_ItemsDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==3){
			
			if (HLargeObj_Dist>7 || HLargeObj_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the large objects' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HLargeObj_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (HItem_Dist>7 || HItem_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the small items' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HItem_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}

	}
	if(ProblemType==11){
		FileInput.getline (Trash,256,':');
		FileInput >> min_nLargeObj >> max_nLargeObj;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the values for the minimum and maximum number of different large object types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_LargeObjType >> max_LargeObjType;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the values for the minimum and maximum number of large objects available."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_LargObjV >> max_LargObjV;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the range for the value of the large objects."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_nItems >> max_nItems;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the minimum and maximum number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_DItemU >> max_DItemU;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the minimum and maximum values for the item type demand"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,':');

		if(NDim==3){
			FileInput >> HLargeObj_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the large object."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
			FileInput >> HItem_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the small items."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
		}
		FileInput >> n_LargeObjDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different large objects."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> DLargeObj_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number different large objects available of each type."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> n_ItemsDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> DItemU_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the item type demand."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		/** Errors of inconsistent input data **/

		if (min_nLargeObj>max_nLargeObj){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different large object types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of large object types= " << min_nLargeObj << " and Maximum number of large object types= " << max_nLargeObj<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}

		if(NDim==2){
			if (max_nLargeObj>(max_LargeObjS-min_LargeObjS+1)*(max_LargeObjS-min_LargeObjS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different large objects given the minimum and maximum size dimension of the Large Object is " << (max_LargeObjS-min_LargeObjS+1)*(max_LargeObjS-min_LargeObjS+1) << " **"<< endl;
				cout << endl << " Change the range for the minimum and maximum number of different large objects or the range for the size dimension of the large objects!" << endl; 
				cout << endl << " Current Parameters: Maximum number of different large object types= " << max_nLargeObj << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}

			if (min_nLargeObj>(max_LargeObjS-min_LargeObjS+1)*(max_LargeObjS-min_LargeObjS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different large objects given the minimum and maximum size dimension of the Large Object is " << (max_LargeObjS-min_LargeObjS+1)*(max_LargeObjS-min_LargeObjS+1) << endl;
				cout << endl << " Change the range for the minimum and maximum number of different large objects or the range for the size dimension of the large objects!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different large object types= " << min_nLargeObj << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}
		if(NDim==3){
			if (min_ItemS == min_LargeObjS || min_ItemS > min_LargeObjS || max_ItemS > min_LargeObjS ){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The minimum and the maximum sizes for the base  of the item must be contained in the range defined by the minimum and maximum size for the base of the Large Object." << endl;
				cout << endl << " Current Parameters for the Items: Minimum size for the base= " << min_ItemS << " Maximum size for the base= " << max_ItemS <<  endl;
				cout << endl << " Current Parameters for the Large Object: Minimum size for the base= " << min_LargeObjS << " Maximum size for the base= " << max_LargeObjS <<  endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if ( min_ItemH > min_LargeObjH || min_ItemH == min_LargeObjH || max_ItemH > min_LargeObjH ){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The minimum and the maximum sizes for the height of the item must be contained in the range defined by the minimum and maximum size for height of the Large Object." << endl;
				cout << endl << " Current Parameters for the Items: Minimum height= " << min_ItemH << " Maximum height= " << max_ItemH <<  endl;
				cout << endl << " Current Parameters for the Large Object: Minimum height= " << min_LargeObjH << " Maximum height= " << max_LargeObjH <<  endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-min_ItemH +1) || max_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-min_ItemH +1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << "Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}

		}


		if (min_LargeObjType>max_LargeObjType){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of large objects available of each type, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of large objects available of each type= " << min_LargeObjType << " and Maximum number of large objects available of each type= " << max_LargeObjType<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_nItems>max_nItems){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different item types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << " and Maximum number of different item types= " << max_nItems<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==2){
			if (max_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << " Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Maximum number of different item types= " << max_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << "Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}
		if (min_DItemU>max_DItemU){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum value for the item upper bound demand, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum lower bound demand= " << min_DItemU << " and Maximum lower bound demand= " << max_DItemU<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}
		if (min_LargObjV>max_LargObjV){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "The minimum number of the range for the large object value calculation must be smaller or equal to the maximum number of the range (min<=max)!" << endl;
			cout << endl << " Current Parameters: Minimum= " << min_LargObjV << " Maximum= " << max_LargObjV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_LargObjV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The minimum number of the range for the large object value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << min_LargObjV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (max_LargObjV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The maximum number of the range for the large object value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << max_LargObjV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		
		if (n_LargeObjDist>7 || n_LargeObjDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different large objects from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_LargeObjDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (DLargeObj_Dist>7 || DLargeObj_Dist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of large object types available from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << DLargeObj_Dist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}
		if (n_ItemsDist>7 || n_ItemsDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_ItemsDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (DItemU_Dist>7 || DItemU_Dist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the upper bound demand of the item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << DItemU_Dist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==3){
			
			if (HLargeObj_Dist>7 || HLargeObj_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the large objects' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HLargeObj_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (HItem_Dist>7 || HItem_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the small items' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HItem_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}


	}
	if(ProblemType==12){
		FileInput.getline (Trash,256,':');
		FileInput >> min_nLargeObj >> max_nLargeObj;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the values for the minimum and maximum number of different large object types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_LargObjV >> max_LargObjV;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the range for the value of the large objects."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_nItems >> max_nItems;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the minimum and maximum number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_DItemU >> max_DItemU;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the minimum and maximum values for the item type demand"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,':');

		if(NDim==3){
			FileInput >> HLargeObj_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the large object."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
			FileInput >> HItem_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the small items."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
		}
		FileInput >> n_LargeObjDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different large objects."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> n_ItemsDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> DItemU_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the item type demand."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}


		/** Errors of inconsistent input data **/

		if (min_nLargeObj>max_nLargeObj){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different large object types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of large object types= " << min_nLargeObj << " and Maximum number of large object types= " << max_nLargeObj<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		
		if (min_nItems>max_nItems){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different item types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << " and Maximum number of different item types= " << max_nItems<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==2){
			if (max_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << " Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Maximum number of different item types= " << max_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << "Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}
		if(NDim==3){
			if (min_ItemS == min_LargeObjS || min_ItemS > min_LargeObjS || max_ItemS > min_LargeObjS ){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The minimum and the maximum sizes for the base  of the item must be contained in the range defined by the minimum and maximum size for the base of the Large Object." << endl;
				cout << endl << " Current Parameters for the Items: Minimum size for the base= " << min_ItemS << " Maximum size for the base= " << max_ItemS <<  endl;
				cout << endl << " Current Parameters for the Large Object: Minimum size for the base= " << min_LargeObjS << " Maximum size for the base= " << max_LargeObjS <<  endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if ( min_ItemH > min_LargeObjH || min_ItemH == min_LargeObjH || max_ItemH > min_LargeObjH ){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The minimum and the maximum sizes for the height of the item must be contained in the range defined by the minimum and maximum size for height of the Large Object." << endl;
				cout << endl << " Current Parameters for the Items: Minimum height= " << min_ItemH << " Maximum height= " << max_ItemH <<  endl;
				cout << endl << " Current Parameters for the Large Object: Minimum height= " << min_LargeObjH << " Maximum height= " << max_LargeObjH <<  endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-min_ItemH +1) || max_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-min_ItemH +1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << "Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}

		}

		if (min_DItemU>max_DItemU){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum value for the item upper bound demand, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum lower bound demand= " << min_DItemU << " and Maximum lower bound demand= " << max_DItemU<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}

		if (min_LargObjV>max_LargObjV){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "The minimum number of the range for the large object value calculation must be smaller or equal to the maximum number of the range (min<=max)!" << endl;
			cout << endl << " Current Parameters: Minimum= " << min_LargObjV << " Maximum= " << max_LargObjV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_LargObjV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The minimum number of the range for the large object value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << min_LargObjV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (max_LargObjV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The maximum number of the range for the large object value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << max_LargObjV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		
		if (n_LargeObjDist>7 || n_LargeObjDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different large objects from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_LargeObjDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (n_ItemsDist>7 || n_ItemsDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_ItemsDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		
		if (DItemU_Dist>7 || DItemU_Dist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the upper bound demand of the item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << DItemU_Dist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==3){
			
			if (HLargeObj_Dist>7 || HLargeObj_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the large objects' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HLargeObj_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (HItem_Dist>7 || HItem_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the small items' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HItem_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}


	}
	if(ProblemType==13){
		
		FileInput.getline (Trash,256,':');
		FileInput >> min_nItems >> max_nItems;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the minimum and maximum number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,':');

		if(NDim==3){
			FileInput >> HLargeObj_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the large object."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
			FileInput >> HItem_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the small items."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
		}
		FileInput >> n_ItemsDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		/** Errors of inconsistent input data **/

		if (min_nItems>max_nItems){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different item types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << " and Maximum number of different item types= " << max_nItems<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
	
		if (n_ItemsDist>7 || n_ItemsDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_ItemsDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==3){
			
			if (HLargeObj_Dist>7 || HLargeObj_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the large objects' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HLargeObj_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (HItem_Dist>7 || HItem_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the small items' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HItem_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}


	}
	if(ProblemType==14){
		FileInput.getline (Trash,256,':');
		FileInput >> min_nLargeObj >> max_nLargeObj;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the values for the minimum and maximum number of different large object types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_LargeObjType >> max_LargeObjType;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the values for the minimum and maximum number of large objects available."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_LargObjV >> max_LargObjV;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the range for the value of the large objects."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_nItems >> max_nItems;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the minimum and maximum number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,':');

		if(NDim==3){
			FileInput >> HLargeObj_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the large object."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
			FileInput >> HItem_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the small items."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
		}
		FileInput >> n_LargeObjDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different large objects."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> DLargeObj_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number different large objects available of each type."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> n_ItemsDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		/** Errors of inconsistent input data **/

		if (min_nLargeObj>max_nLargeObj){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different large object types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of large object types= " << min_nLargeObj << " and Maximum number of large object types= " << max_nLargeObj<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==2){
			if (max_nLargeObj>(max_LargeObjS-min_LargeObjS+1)*(max_LargeObjS-min_LargeObjS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different large objects given the minimum and maximum size dimension of the Large Object is " << (max_LargeObjS-min_LargeObjS+1)*(max_LargeObjS-min_LargeObjS+1) << " **"<< endl;
				cout << endl << " Change the range for the minimum and maximum number of different large objects or the range for the size dimension of the large objects!" << endl; 
				cout << endl << " Current Parameters: Maximum number of different large object types= " << max_nLargeObj << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nLargeObj>(max_LargeObjS-min_LargeObjS+1)*(max_LargeObjS-min_LargeObjS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different large objects given the minimum and maximum size dimension of the Large Object is " << (max_LargeObjS-min_LargeObjS+1)*(max_LargeObjS-min_LargeObjS+1) << endl;
				cout << endl << " Change the range for the minimum and maximum number of different large objects or the range for the size dimension of the large objects!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different large object types= " << min_nLargeObj << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}
		if (min_LargeObjType>max_LargeObjType){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of large objects available of each type, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of large objects available of each type= " << min_LargeObjType << " and Maximum number of large objects available of each type= " << max_LargeObjType<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_LargObjV>max_LargObjV){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "The minimum number of the range for the large object value calculation must be smaller or equal to the maximum number of the range (min<=max)!" << endl;
			cout << endl << " Current Parameters: Minimum= " << min_LargObjV << " Maximum= " << max_LargObjV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_LargObjV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The minimum number of the range for the large object value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << min_LargObjV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (max_LargObjV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The maximum number of the range for the large object value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << max_LargObjV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_nItems>max_nItems){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different item types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << " and Maximum number of different item types= " << max_nItems<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		
		
		if (n_LargeObjDist>7 || n_LargeObjDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different large objects from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_LargeObjDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (DLargeObj_Dist>7 || DLargeObj_Dist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of large object types available from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << DLargeObj_Dist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}
		if (n_ItemsDist>7 || n_ItemsDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_ItemsDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==3){
			
			if (HLargeObj_Dist>7 || HLargeObj_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the large objects' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HLargeObj_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (HItem_Dist>7 || HItem_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the small items' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HItem_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}

		

	}
	if(ProblemType==15){
		FileInput.getline (Trash,256,':');
		FileInput >> min_nLargeObj >> max_nLargeObj;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the values for the minimum and maximum number of different large object types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_LargObjV >> max_LargObjV;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the range for the value of the large objects."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_nItems >> max_nItems;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the minimum and maximum number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,':');

		if(NDim==3){
			FileInput >> HLargeObj_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the large object."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
			FileInput >> HItem_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the small items."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
		}
		FileInput >> n_LargeObjDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different large objects."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> n_ItemsDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		/** Errors of inconsistent input data **/

		if (min_nLargeObj>max_nLargeObj){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different large object types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of large object types= " << min_nLargeObj << " and Maximum number of large object types= " << max_nLargeObj<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}

		if (min_LargObjV>max_LargObjV){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "The minimum number of the range for the large object value calculation must be smaller or equal to the maximum number of the range (min<=max)!" << endl;
			cout << endl << " Current Parameters: Minimum= " << min_LargObjV << " Maximum= " << max_LargObjV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_LargObjV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The minimum number of the range for the large object value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << min_LargObjV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (max_LargObjV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The maximum number of the range for the large object value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << max_LargObjV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_nItems>max_nItems){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of different item types, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << " and Maximum number of different item types= " << max_nItems<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (n_LargeObjDist>7 || n_LargeObjDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different large objects from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_LargeObjDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (n_ItemsDist>7 || n_ItemsDist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of different item types from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << n_ItemsDist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if(NDim==3){
			
			if (HLargeObj_Dist>7 || HLargeObj_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the large objects' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HLargeObj_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (HItem_Dist>7 || HItem_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the small items' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HItem_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}

		

	}
	if(ProblemType==16){

		FileInput.getline (Trash,256,':');
		FileInput >> min_nLargeObj >> max_nLargeObj;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the values for the minimum and maximum number of different large object types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_LargeObjType >> max_LargeObjType;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the values for the minimum and maximum number of large objects available."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_LargObjV >> max_LargObjV;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the range for the value of the large objects."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_nItems >> max_nItems;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the minimum and maximum number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_DItemU >> max_DItemU;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the minimum and maximum values for the item type demand"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		
		
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,':');

		if(NDim==3){
			FileInput >> HLargeObj_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the large object."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
			FileInput >> HItem_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the small items."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
		}
		FileInput >> n_LargeObjDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different large objects."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> DLargeObj_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number different large objects available of each type."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> w_LargeObjDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the width of the large object."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> n_ItemsDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> DItemU_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the item type demand."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		/** Errors of inconsistent input data **/

		if(NDim==2){
			if (max_nLargeObj>(max_LargeObjW-min_LargeObjW+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different large objects given the minimum and maximum size dimension of the Large Object is " << (max_LargeObjW-min_LargeObjW+1) << " **"<< endl;
				cout << endl << " Change the range for the minimum and maximum number of different large objects or the range for the size dimension of the large objects!" << endl; 
				cout << endl << " Current Parameters: Maximum number of different large object types= " << max_nLargeObj << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nLargeObj>(max_LargeObjW-min_LargeObjW+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different large objects given the minimum and maximum size dimension of the Large Object is " << (max_LargeObjW-min_LargeObjW+1) << endl;
				cout << endl << " Change the range for the minimum and maximum number of different large objects or the range for the size dimension of the large objects!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different large object types= " << min_nLargeObj << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (max_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << " Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Maximum number of different item types= " << max_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << "Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}
		if(NDim==3){
			if (min_ItemS == min_LargeObjW || min_ItemS > min_LargeObjW || max_ItemS > min_LargeObjW ){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The minimum and the maximum sizes for the base  of the item must be contained in the range defined by the minimum and maximum size for the base of the Large Object." << endl;
				cout << endl << " Current Parameters for the Items: Minimum size for the base= " << min_ItemS << " Maximum size for the base= " << max_ItemS <<  endl;
				cout << endl << " Current Parameters for the Large Object: Minimum size for the base= " << min_LargeObjW << " Maximum size for the base= " << max_LargeObjW <<  endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if ( min_ItemH > min_LargeObjH || min_ItemH == min_LargeObjH || max_ItemH > min_LargeObjH ){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The minimum and the maximum sizes for the height of the item must be contained in the range defined by the minimum and maximum size for height of the Large Object." << endl;
				cout << endl << " Current Parameters for the Items: Minimum height= " << min_ItemH << " Maximum height= " << max_ItemH <<  endl;
				cout << endl << " Current Parameters for the Large Object: Minimum height= " << min_LargeObjH << " Maximum height= " << max_LargeObjH <<  endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-min_ItemH +1) || max_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-min_ItemH +1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << " Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}

		}

		if (min_LargeObjType>max_LargeObjType){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Change the range for the minimum and maximum number of large objects available of each type, the minimum must be smaller or equal to the maximum (min<=max)!"<< endl;
			cout << endl << " Current Parameters: Minimum number of large objects available of each type= " << min_LargeObjType << " and Maximum number of large objects available of each type= " << max_LargeObjType<< endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (DLargeObj_Dist>7 || DLargeObj_Dist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the number of large object types available from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << DLargeObj_Dist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;

		}
		if (min_LargObjV>max_LargObjV){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The minimum number of the range for the large object value calculation must be smaller or equal to the maximum number of the range (min<=max)!" << endl;
			cout << endl << " Current Parameters: Minimum= " << min_LargObjV << " Maximum= " << max_LargObjV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_LargObjV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The minimum number of the range for the large object value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << min_LargObjV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (max_LargObjV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The maximum number of the range for the large object value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << max_LargObjV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}

		if(NDim==3){
			
			if (HLargeObj_Dist>7 || HLargeObj_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the large objects' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HLargeObj_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (HItem_Dist>7 || HItem_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the small items' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HItem_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}

	}

	if(ProblemType==17){

		FileInput.getline (Trash,256,':');
		FileInput >> min_nLargeObj >> max_nLargeObj;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the values for the minimum and maximum number of different large object types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_LargObjV >> max_LargObjV;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the range for the value of the large objects."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_nItems >> max_nItems;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the value for the minimum and maximum number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> min_DItemU >> max_DItemU;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the minimum and maximum values for the item type demand"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

				
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,';');
		FileInput.getline (Trash,256,'.');
		FileInput.getline (Trash,256,':');

		if(NDim==3){
			FileInput >> HLargeObj_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the large object."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
			FileInput >> HItem_Dist;
			if (FileInput.fail()){
				cout << endl;
				cout <<"_______________________________________________"<< endl;
				cout <<  endl <<"  Error in the input parameters file!"<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << "  Please check the ID of the Beta distribution for the height of the small items."<< endl;
				cout <<"_______________________________________________"<< endl;
				cout << endl << endl << "  The program will be closed." << endl;
				error=1;
				return 0;
			}
			FileInput.getline (Trash,256,':');
		}
		FileInput >> n_LargeObjDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different large objects."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> w_LargeObjDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the width of the large object."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
			
		FileInput.getline (Trash,256,':');
		FileInput >> n_ItemsDist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the number of different item types."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}
		FileInput.getline (Trash,256,':');
		FileInput >> DItemU_Dist;
		if (FileInput.fail()){
			cout << endl;
			cout <<"_______________________________________________"<< endl;
			cout <<  endl <<"  Error in the input parameters file!"<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << "  Please check the ID of the Beta distribution for the item type demand."<< endl;
			cout <<"_______________________________________________"<< endl;
			cout << endl << endl << "  The program will be closed." << endl;
			error=1;
			return 0;
		}

		/** Errors of inconsistent input data **/

		if(NDim==2){
			if (max_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << " Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Maximum number of different item types= " << max_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << "Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}

		}
		if(NDim==3){
			if (min_ItemS == min_LargeObjW || min_ItemS > min_LargeObjW || max_ItemS > min_LargeObjW ){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The minimum and the maximum sizes for the base  of the item must be contained in the range defined by the minimum and maximum size for the base of the Large Object." << endl;
				cout << endl << " Current Parameters for the Items: Minimum size for the base= " << min_ItemS << " Maximum size for the base= " << max_ItemS <<  endl;
				cout << endl << " Current Parameters for the Large Object: Minimum size for the base= " << min_LargeObjW << " Maximum size for the base= " << max_LargeObjW <<  endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if ( min_ItemH > min_LargeObjH || min_ItemH == min_LargeObjH || max_ItemH > min_LargeObjH ){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " The minimum and the maximum sizes for the height of the item must be contained in the range defined by the minimum and maximum size for height of the Large Object." << endl;
				cout << endl << " Current Parameters for the Items: Minimum height= " << min_ItemH << " Maximum height= " << max_ItemH <<  endl;
				cout << endl << " Current Parameters for the Large Object: Minimum height= " << min_LargeObjH << " Maximum height= " << max_LargeObjH <<  endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (min_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-min_ItemH +1) || max_nItems>(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-min_ItemH +1)){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "The maximum number of different item types given the minimum and maximum size dimension of the small items is " << (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1) << endl;
				cout << endl << "Change the range for the minimum and maximum number of different item types or the range for the size dimension of the small item types!" << endl; 
				cout << endl << " Current Parameters: Minimum number of different item types= " << min_nItems << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}

		}
		if (min_LargObjV>max_LargObjV){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "The minimum number of the range for the large object value calculation must be smaller or equal to the maximum number of the range (min<=max)!" << endl;
			cout << endl << " Current Parameters: Minimum= " << min_LargObjV << " Maximum= " << max_LargObjV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (min_LargObjV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The minimum number of the range for the large object value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << min_LargObjV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
		if (max_LargObjV>1){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " The maximum number of the range for the large object value calculation must be smaller or equal to 1!"<< endl;
			cout << endl << " Current Parameters: Minimum= " << max_LargObjV <<  endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}

		if(NDim==3){
		
			if (HLargeObj_Dist>7 || HLargeObj_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the large objects' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HLargeObj_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
			if (HItem_Dist>7 || HItem_Dist==0){
				cout << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << "	 Error in the input parameters file! " << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << " Select the ID of the distribution for the small items' height from 1 to 7!"<< endl;
				cout << endl << " Current ID selected: " << HItem_Dist << endl;
				cout <<"_____________________________________________________________________________"<< endl;
				cout << endl << endl << "The program will be closed." << endl;
				error=1;
				return 0;
			}
		}

	}

	if (ProblemType==16 || ProblemType==17){
		min_LargeObjS=min_LargeObjW;
		max_LargeObjS=max_LargeObjW;
	}



	if(NDim==3){
		
		if (HItem_Dist>7 || HItem_Dist==0){
			cout << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << "	 Error in the input parameters file! " << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << " Select the ID of the distribution for the small items' height from 1 to 7!"<< endl;
			cout << endl << " Current ID selected: " << HItem_Dist << endl;
			cout <<"_____________________________________________________________________________"<< endl;
			cout << endl << endl << "The program will be closed." << endl;
			error=1;
			return 0;
		}
	}

		

	if(Item_SizSh>16 || Item_SizSh==0){
		cout << endl << "Error in the input parameters file!" << endl;
		cout << endl << "Please select the ID of the size and shape of the items from 1 to 16!" << endl;
		error=1;
		return 0;
	}
		

	if(ProblemType<16){
		if(LargeObj_SizSh>16 || LargeObj_SizSh==0){
			cout << endl << "Error in the input parameters file!" << endl;
			cout << endl << "Please select the ID of the size and shape of the large objects from 1 to 16!" << endl;
			error=1;
			return 0;
		}
	}

		
	// Parameters of the distributions for the size and shape control of the items

	if (Item_SizSh==1){
		alpha_ItemW=2;
		beta_ItemW=5;
		alpha_ItemL=2;
		beta_ItemL=5;
	}

	if (Item_SizSh==2){
		alpha_ItemW=2;
		beta_ItemW=5;
		alpha_ItemL=5;
		beta_ItemL=2;
	}

	if (Item_SizSh==3){
		alpha_ItemW=2;
		beta_ItemW=5;
		alpha_ItemL=2;
		beta_ItemL=2;
	}

	if (Item_SizSh==4){
		alpha_ItemW=2;
		beta_ItemW=5;
		alpha_ItemL=0.5;
		beta_ItemL=0.5;
	}

	if (Item_SizSh==5){
		alpha_ItemW=5;
		beta_ItemW=2;
		alpha_ItemL=2;
		beta_ItemL=5;
	}

	if (Item_SizSh==6){
		alpha_ItemW=5;
		beta_ItemW=2;
		alpha_ItemL=5;
		beta_ItemL=2;
	}

	if (Item_SizSh==7){
		alpha_ItemW=5;
		beta_ItemW=2;
		alpha_ItemL=2;
		beta_ItemL=2;
	}

	if (Item_SizSh==8){
		alpha_ItemW=5;
		beta_ItemW=2;
		alpha_ItemL=0.5;
		beta_ItemL=0.5;
	}

	if (Item_SizSh==9){
		alpha_ItemW=2;
		beta_ItemW=2;
		alpha_ItemL=2;
		beta_ItemL=5;
	}

	if (Item_SizSh==10){
		alpha_ItemW=2;
		beta_ItemW=2;
		alpha_ItemL=5;
		beta_ItemL=2;
	}

	if (Item_SizSh==11){
		alpha_ItemW=2;
		beta_ItemW=2;
		alpha_ItemL=2;
		beta_ItemL=2;
	}

	if (Item_SizSh==12){
		alpha_ItemW=2;
		beta_ItemW=2;
		alpha_ItemL=0.5;
		beta_ItemL=0.5;
	}

	if (Item_SizSh==13){
		alpha_ItemW=0.5;
		beta_ItemW=0.5;
		alpha_ItemL=2;
		beta_ItemL=5;
	}

	if (Item_SizSh==14){
		alpha_ItemW=0.5;
		beta_ItemW=0.5;
		alpha_ItemL=5;
		beta_ItemL=2;
	}

	if (Item_SizSh==15){
		alpha_ItemW=0.5;
		beta_ItemW=0.5;
		alpha_ItemL=2;
		beta_ItemL=2;
	}

	if (Item_SizSh==16){
		alpha_ItemW=0.5;
		beta_ItemW=0.5;
		alpha_ItemL=0.5;
		beta_ItemL=0.5;
	}
		
	// Parameters of the distributions for the size and shape control of the large objects
	
	if(ProblemType<16){
		if (LargeObj_SizSh==1){
			alpha_LargeObjW=2;
			beta_LargeObjW=5;
			alpha_LargeObjL=2;
			beta_LargeObjL=5;
		}

		if (LargeObj_SizSh==2){
			alpha_LargeObjW=2;
			beta_LargeObjW=5;
			alpha_LargeObjL=5;
			beta_LargeObjL=2;
		}

		if (LargeObj_SizSh==3){
			alpha_LargeObjW=2;
			beta_LargeObjW=5;
			alpha_LargeObjL=2;
			beta_LargeObjL=2;
		}

		if (LargeObj_SizSh==4){
			alpha_LargeObjW=2;
			beta_LargeObjW=5;
			alpha_LargeObjL=0.5;
			beta_LargeObjL=0.5;
		}

		if (LargeObj_SizSh==5){
			alpha_LargeObjW=5;
			beta_LargeObjW=2;
			alpha_LargeObjL=2;
			beta_LargeObjL=5;
		}

		if (LargeObj_SizSh==6){
			alpha_LargeObjW=5;
			beta_LargeObjW=2;
			alpha_LargeObjL=5;
			beta_LargeObjL=2;
		}

		if (LargeObj_SizSh==7){
			alpha_LargeObjW=5;
			beta_LargeObjW=2;
			alpha_LargeObjL=2;
			beta_LargeObjL=2;
		}

		if (LargeObj_SizSh==8){
			alpha_LargeObjW=5;
			beta_LargeObjW=2;
			alpha_LargeObjL=0.5;
			beta_LargeObjL=0.5;
		}
		if (LargeObj_SizSh==9){
			alpha_LargeObjW=2;
			beta_LargeObjW=2;
			alpha_LargeObjL=2;
			beta_LargeObjL=5;
		}

		if (LargeObj_SizSh==10){
			alpha_LargeObjW=2;
			beta_LargeObjW=2;
			alpha_LargeObjL=5;
			beta_LargeObjL=2;
		}

		if (LargeObj_SizSh==11){
			alpha_LargeObjW=2;
			beta_LargeObjW=2;
			alpha_LargeObjL=2;
			beta_LargeObjL=2;
		}

		if (LargeObj_SizSh==12){
			alpha_LargeObjW=2;
			beta_LargeObjW=2;
			alpha_LargeObjL=0.5;
			beta_LargeObjL=0.5;
		}

		if (LargeObj_SizSh==13){
			alpha_LargeObjW=0.5;
			beta_LargeObjW=0.5;
			alpha_LargeObjL=2;
			beta_LargeObjL=5;
		}

		if (LargeObj_SizSh==14){
			alpha_LargeObjW=0.5;
			beta_LargeObjW=0.5;
			alpha_LargeObjL=5;
			beta_LargeObjL=2;
		}

		if (LargeObj_SizSh==15){
			alpha_LargeObjW=0.5;
			beta_LargeObjW=0.5;
			alpha_LargeObjL=2;
			beta_LargeObjL=2;
		}

		if (LargeObj_SizSh==16){
			alpha_LargeObjW=0.5;
			beta_LargeObjW=0.5;
			alpha_LargeObjL=0.5;
			beta_LargeObjL=0.5;
		}
	}

	
	// Parameters for the generation of pseudo-random numbers
	a = 16807;
	p = 2147483647;
	q = 127773;
	r = 2836;
	sd = seed;
	
	
	return 0;

}
inline int TwoDProbGen::Gen(double alpha, double beta, unsigned long min, unsigned long max)
{

	long h1;
    long h2;
    double h3;
    
    h2 = (long)sd/q;
    h1 = sd-h2*q;
    
    sd = a*h1 - r*h2;

    if (sd<0)
       sd = sd+p;

	   
	// To obtain a number in the range [0, 1[
    h3 = ((double)sd)/((double)p);
 
	// Definition of alpha and beta for beta distribution
	beta_distribution<> gen(alpha,beta);

	double a = alpha;
	beta;
	
	// Determination of the inverse cumulative beta distribution
	quantile(gen, h3);
	
	double x_gen= quantile(gen, h3);

	 unsigned long newval;

	max=max+1; 

	newval = min + ( unsigned long) (x_gen*(max-min));

	return newval;
}

int TwoDProbGen::IIPP()
{
	int i;
	unsigned long itL, itW, itH;

	
	cout<<" Enter the filename to save the problem test (e. g. C:\\programs\\IIPP.txt): ";
	char filename[100];
    cin>>filename;

	ofstream FileOutRst;
	FileOutRst.open(filename);

	if(!FileOutRst.is_open( )){
		cout<<" It was not possible to open the file!\n";
		FileOutRst.clear( ); 
		exit (-1);
	}
	
	if(NDim==2)FileOutRst << "***2D Rectangular Problem***" << endl;
	if(NDim==3)FileOutRst << "***3D Rectangular Problem***" << endl;
	FileOutRst << "***Problem tests for the Identical Item Packing Problem (IIPP)***" << endl;
	FileOutRst << "Input parameter file: " << InputParfilename  << endl;
	FileOutRst << "*****************************************************************************"<< endl;
	FileOutRst << "Total number of instances " << endl;
	if(NDim==2) FileOutRst << "LargeObject.Length" << "\t" << "LargeObject.Width" << "\t" << "Item[i].Length" << "\t" << "Item[i].Width"  << endl;
	if(NDim==3) FileOutRst << "LargeObject.Length" << "\t" << "LargeObject.Width" << "\t" << "LargeObject.Height" << "\t" << "Item[i].Length" << "\t" << "Item[i].Width"  << "\t" << "Item[i].Height"  << endl;
	FileOutRst << "*****************************************************************************"<< endl;

	FileOutRst << n_instances << endl;

	LargeObjL= new  unsigned long [1];
	LargeObjW= new  unsigned long [1];
	LargeObjH= new  unsigned long [1];

	if(NDim==3){
		BetaDist(HLargeObj_Dist);
		alpha_LargeObjH=alphaDist;
		beta_LargeObjH=betaDist;
		BetaDist(HItem_Dist);
		alpha_ItemH=alphaDist;
		beta_ItemH=betaDist;
	}
	

	for (i=0; i<n_instances; i++){

		LargeObjL[0]= Gen(alpha_LargeObjL,beta_LargeObjL,min_LargeObjS,max_LargeObjS);
		LargeObjW[0]= Gen(alpha_LargeObjW,beta_LargeObjW,min_LargeObjS,max_LargeObjS);
		if(NDim==2) FileOutRst << LargeObjL[0] << '\t' << LargeObjW[0];
		
		if(NDim==3){
			LargeObjH[0]= Gen(alpha_LargeObjH,beta_LargeObjH,min_LargeObjH,max_LargeObjH);
			FileOutRst << LargeObjL[0] << '\t' << LargeObjW[0] << '\t' << LargeObjH[0];
		}

		itL = Gen(alpha_ItemL,beta_ItemL,min_ItemS,max_ItemS);
		itW = Gen(alpha_ItemW,beta_ItemW,min_ItemS,max_ItemS);

		if(NDim==2){

			// Items are smaller or equal to the large object
			while( itL > LargeObjL[0]){
				itL = Gen(alpha_ItemL,beta_ItemL,min_ItemS,max_ItemS);
			}
			while( itW > LargeObjW[0]){
				itW = Gen(alpha_ItemW,beta_ItemW,min_ItemS,max_ItemS);
			}
			
			FileOutRst << '\t' << itL << '\t' << itW << endl;
		}
		if(NDim==3){
			itH = Gen(alpha_ItemH,beta_ItemH,min_ItemH,max_ItemH);
			
			// Items are smaller or equal to the large object
			while( itL > LargeObjL[0]){
				itL = Gen(alpha_ItemL,beta_ItemL,min_ItemS,max_ItemS);
			}
			while( itW > LargeObjW[0]){
				itW = Gen(alpha_ItemW,beta_ItemW,min_ItemS,max_ItemS);
			}
			while( itH > LargeObjH[0]){
				itH = Gen(alpha_ItemH,beta_ItemH,min_ItemH,max_ItemH);
			}

			FileOutRst << '\t' << itL << '\t' << itW << '\t' << itH << endl;
		}
	}
	FileOutRst.close();


 return 0;
}
int TwoDProbGen::PP()
{

	int i;
	unsigned long j, l, k;
	unsigned long itL, itW, itH;
	unsigned long maxAuxItemL, maxAuxItemW;
	unsigned long current_n=0;
	int aux=1;
	unsigned long LObjL, LObjW, LObjH;
	unsigned long long int TtLargeObjArea;
	
	
	// Determines the alpha and beta parameters for the generation of the lower and upper bounds for the demand of each item type
	BetaDist(DItemL_Dist);
	alpha_DItemL=alphaDist;
	beta_DItemL=betaDist;
	BetaDist(DItemU_Dist);
	alpha_DItemU=alphaDist;
	beta_DItemU=betaDist;
	if(NDim==3){
		BetaDist(HLargeObj_Dist);
		alpha_LargeObjH=alphaDist;
		beta_LargeObjH=betaDist;
		BetaDist(HItem_Dist);
		alpha_ItemH=alphaDist;
		beta_ItemH=betaDist;
	}

	char filename[100];
	
	if (ProblemType==2)cout<<" Enter the filename to save the problem test (e. g. C:\\programs\\SLOPP.txt): ";
	if (ProblemType==3)cout<<" Enter the filename to save the problem test (e. g. C:\\programs\\MILOPP.txt): ";
	if (ProblemType==4)cout<<" Enter the filename to save the problem test (e. g. C:\\programs\\MHLOPPW.txt): ";
	if (ProblemType==5)cout<<" Enter the filename to save the problem test (e. g. C:\\programs\\MHLOPPS.txt): ";
    cin>>filename;
	ofstream FileOutRst;
	FileOutRst.open(filename);

	if(!FileOutRst.is_open( )){
		cout<<"It was not possible to open the file!\n";
		FileOutRst.clear( ); 
		exit (-1);
	}

	if(NDim==2)FileOutRst << "***2D Rectangular Problem***" << endl;
	if(NDim==3)FileOutRst << "***3D Rectangular Problem***" << endl;
	if (ProblemType==2) FileOutRst << "***Instances for the Single Large Object Placement Problem (SLOPP)***" << endl;
	if (ProblemType==3) FileOutRst << "***Instances for the Multiple Identical Large Object Placement Problem (MILOPP)***" << endl;
	if (ProblemType==4) FileOutRst << "***Instances for the Multiple Heterogeneous Large Object Placement Problem (MHLOPP/W)***" << endl;
	if (ProblemType==5) FileOutRst << "***Instances for the Multiple Heterogeneous Large Object Placement Problem (MHLOPP/S)***" << endl;
	FileOutRst << "Input parameter file: " << InputParfilename  << endl;
	FileOutRst << "***************************************************************************************************************"<< endl;
	FileOutRst << "Total number of instances " << endl;
	if (ProblemType==4||ProblemType==5)	FileOutRst << "Number of different large objects (j)" << endl;
	if (ProblemType==2){
		if(NDim==2) FileOutRst << "LargeObject.Length" << "\t" << "LargeObject.Width" << endl;
		if(NDim==3) FileOutRst << "LargeObject.Length" << "\t" << "LargeObject.Width" << "\t" << "LargeObject.height" << endl;
	}
	if (ProblemType==3){
		if(NDim==2) FileOutRst << "LargeObject.Length" << "\t" << "LargeObject.Width" << "\t" << "LargeObject.Available" <<  endl;
		if(NDim==3) FileOutRst << "LargeObject.Length" << "\t" << "LargeObject.Width" << "\t" << "LargeObject.Height" << "\t" << "LargeObject.Available" <<  endl;
	}
	if (ProblemType==4){
		if(NDim==2) FileOutRst << "LargeObject[j].Length" << "\t" << "LargeObject[j].Width" << "\t" << "LargeObject[j].Available" << endl;
		if(NDim==3) FileOutRst << "LargeObject[j].Length" << "\t" << "LargeObject[j].Width" << "\t" << "LargeObject[j].Height" << "\t" << "LargeObject[j].Available" << endl;
	}
	if (ProblemType==5){
		if(NDim==2) FileOutRst << "LargeObject[j].Length" << "\t" << "LargeObject[j].Width" << endl;
		if(NDim==3) FileOutRst << "LargeObject[j].Length" << "\t" << "LargeObject[j].Width" <<  "\t" << "LargeObject[j].Height" << endl;
	}
	 
	FileOutRst << "Number of different item types (i)" << endl;
	if(NDim==2) FileOutRst << "Item[i].Length" << "\t" << "Item[i].Width" << "\t" << "Item[i].LowerBoundDemand" << "\t" << "Item[i].UpperBoundDemand" <<  "\t" << "Item[i].Value" <<  endl;
	if(NDim==3) FileOutRst << "Item[i].Length" << "\t" << "Item[i].Width" << "\t" << "Item[i].Height" << "\t" << "Item[i].LowerBoundDemand" << "\t" << "Item[i].UpperBoundDemand" <<  "\t" << "Item[i].Value" <<  endl;
	FileOutRst << "***************************************************************************************************************"<< endl;

	FileOutRst << n_instances << endl;

	for (i=0;i<n_instances;i++){

		// Determines the number of different large objects
		if(ProblemType==4 || ProblemType==5){
			BetaDist(n_LargeObjDist);
			n_LargeObj=Gen(alphaDist,betaDist,min_nLargeObj,max_nLargeObj);
			FileOutRst << n_LargeObj << endl;
		}
		else n_LargeObj=1;

		LargeObjL= new  unsigned long [n_LargeObj]; 
		LargeObjW= new  unsigned long [n_LargeObj]; 
		if(NDim==3) LargeObjH= new  unsigned long [n_LargeObj]; 
		ALargeObj= new  unsigned long [n_LargeObj]; 
		

		
		TtLargeObjArea=0;

		aux=1;
		current_n=0;
		if(ProblemType==2 || ProblemType==3 || ProblemType==4){
			for (j=0;j<n_LargeObj;j++){
				// To prevent large object size repetition
				while(aux==1){
					aux=0;
					LObjL = Gen(alpha_LargeObjL,beta_LargeObjL,min_LargeObjS,max_LargeObjS);
					LObjW = Gen(alpha_LargeObjW,beta_LargeObjW,min_LargeObjS,max_LargeObjS);
					if(NDim==3) LObjH = Gen(alpha_LargeObjH,beta_LargeObjH,min_LargeObjH,max_LargeObjH);
					for(k=0; k<current_n; k++){
						if(NDim==2)if(LargeObjL[k]==LObjL && LargeObjW[k]==LObjW) aux=1;
						if(NDim==3) if(LargeObjL[k]==LObjL && LargeObjW[k]==LObjW && LargeObjH[k]==LObjH) aux=1;
					}
				}
				
				LargeObjL[current_n]=LObjL;
				LargeObjW[current_n]=LObjW;
				if(NDim==3) LargeObjH[current_n]=LObjH;

				// Generation of large object availability
				if(ProblemType==3 || ProblemType==4){
					BetaDist(DLargeObj_Dist);
					ALargeObj[current_n]=Gen(alphaDist,betaDist,min_LargeObjType,max_LargeObjType);
					TtLargeObjArea+=LargeObjL[current_n]*LargeObjW[current_n]*ALargeObj[current_n];
				}
				
				if(ProblemType==2){
					TtLargeObjArea+=LargeObjL[current_n]*LargeObjW[current_n]; 
					if(NDim==2) FileOutRst << LargeObjL[current_n] << '\t' << LargeObjW[current_n]<< endl;
					if(NDim==3) FileOutRst << LargeObjL[current_n] << '\t' << LargeObjW[current_n]<< '\t' << LargeObjH[current_n]<< endl;
				}
				if(ProblemType==3 || ProblemType==4){
					if(NDim==2) FileOutRst << LargeObjL[current_n] << '\t' << LargeObjW[current_n] << '\t' << ALargeObj[current_n] << endl;
					if(NDim==3) FileOutRst << LargeObjL[current_n] << '\t' << LargeObjW[current_n] << '\t' << LargeObjH[current_n] << '\t' << ALargeObj[current_n] << endl;
				}
				current_n++;
				aux=1;

			}
		}

		// It is allowed large objects repetition 
		if(ProblemType==5){
			for (j=0;j<n_LargeObj;j++){
				LargeObjL[j]=Gen(alpha_LargeObjL,beta_LargeObjL,min_LargeObjS,max_LargeObjS);
				LargeObjW[j]=Gen(alpha_LargeObjW,beta_LargeObjW,min_LargeObjS,max_LargeObjS);
				if(NDim==2){
					TtLargeObjArea+=LargeObjL[j]*LargeObjW[j];
					FileOutRst << LargeObjL[j] << '\t' << LargeObjW[j] << endl;
				}
				if(NDim==3){
					LargeObjH[j]=Gen(alpha_LargeObjH,beta_LargeObjH,min_LargeObjH,max_LargeObjH);
				    TtLargeObjArea+=LargeObjL[j]*LargeObjW[j]*LargeObjH[j];
					FileOutRst << LargeObjL[j] << '\t' << LargeObjW[j] <<  '\t' << LargeObjH[j] << endl;
				}
			}
		}



		// Determines the number of different item types
		BetaDist(n_ItemsDist);
		n_Items=Gen(alphaDist,betaDist,min_nItems,max_nItems);

		
		unsigned long Maximum_NPossibleItems;
		if(NDim==2){
			Maximum_NPossibleItems =(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1);
			if(n_Items==Maximum_NPossibleItems) n_Items= (unsigned long) (Maximum_NPossibleItems-Maximum_NPossibleItems*0.15);
		}
		if(NDim==3){
			Maximum_NPossibleItems = (max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-max_ItemH+1);
			if(n_Items==Maximum_NPossibleItems) n_Items=n_Items= (unsigned long) (Maximum_NPossibleItems-Maximum_NPossibleItems*0.15);
		}
		
		
		//Determines the maximum number of different item types considering the sizes of large objects generated
		if(NDim==2){
			maxAuxItemL=min_LargeObjS;
			maxAuxItemW=min_LargeObjS;
			unsigned long aux_nItems;


			unsigned long *LO_ItemMaxL = new unsigned long [n_LargeObj];
			if (LO_ItemMaxL==NULL) {
				cout << endl << "ERROR on memory allocation" << endl;
				exit(-1);
			}
			unsigned long *LO_ItemMaxW = new unsigned long [n_LargeObj];
			if (LO_ItemMaxW==NULL) {
				cout << endl << "ERROR on memory allocation" << endl;
				exit(-1);
			}

			
			for(j=0;j<n_LargeObj;j++){
				if (LargeObjL[j]>max_ItemS) LO_ItemMaxL[j]=max_ItemS;
				else LO_ItemMaxL[j]=LargeObjL[j];
				if (LargeObjW[j]>max_ItemS) LO_ItemMaxW[j]=max_ItemS;
				else LO_ItemMaxW[j]=LargeObjW[j];

			}

		
			unsigned long auxW=min_LargeObjS;
			unsigned long auxL=min_LargeObjS;

			for(j=0;j<n_LargeObj;j++){
				if (maxAuxItemL<=LO_ItemMaxL[j]){
					if(maxAuxItemL==LO_ItemMaxL[j]){
						if(auxW<LO_ItemMaxW[j]) auxW=LO_ItemMaxW[j];
					}
					else{
						maxAuxItemL=LO_ItemMaxL[j];
						auxW=LO_ItemMaxW[j];
					}
				}
				if (maxAuxItemW<=LO_ItemMaxW[j]){
					if(maxAuxItemW==LO_ItemMaxW[j]){
						if(auxL<LO_ItemMaxL[j]) auxL=LO_ItemMaxL[j];
					}
					else{
						maxAuxItemW=LO_ItemMaxW[j];
						auxL=LO_ItemMaxL[j];
					}
				}
			}

			
			unsigned long *extraL = new unsigned long [n_LargeObj];
			if (extraL==NULL) {
				cout << endl << "ERROR on memory allocation" << endl;
				exit(-1);
			}
			unsigned long *extraW = new unsigned long [n_LargeObj];
			if (extraW==NULL) {
				cout << endl << "ERROR on memory allocation" << endl;
				exit(-1);
			}

			unsigned long maxextraL=0;
			unsigned long maxextraW=0;

			for(j=0; j<n_LargeObj; j++){
				if(LO_ItemMaxL[j] > auxL && LO_ItemMaxW[j] > auxW){
					extraL[j]=LO_ItemMaxL[j];
					extraW[j]=LO_ItemMaxW[j];
				}
				else{
					extraL[j]=0;
					extraW[j]=0;
				}
			}

			for(j=0; j<n_LargeObj; j++){
				if(maxextraL < extraL[j] && maxextraW < extraW[j]){
					maxextraL=extraL[j];
					maxextraW=extraW[j];
				}

			}


			delete [] LO_ItemMaxL;
			delete [] LO_ItemMaxW;
			delete [] extraL;
			delete [] extraW;
			
			
			int A, B, C, D, E, F;
		
			
			if(maxAuxItemL>max_ItemS)A=max_ItemS;
			else A=maxAuxItemL;
			if(auxW>max_ItemS)B=max_ItemS;
			else B=auxW;
			C =(A-min_ItemS+1)*(B-min_ItemS+1);

			
			if(maxAuxItemW>max_ItemS)A=max_ItemS;
			else A=maxAuxItemW;
			if(auxL>max_ItemS)B=max_ItemS;
			else B=auxL;
			D =(A-min_ItemS+1)*(B-min_ItemS+1);

			
			if(auxW>max_ItemS)A=max_ItemS;
			else A=auxW;
			if(auxL>max_ItemS)B=max_ItemS;
			else B=auxL;
			E =(A-min_ItemS+1)*(B-min_ItemS+1);
			aux_nItems=C+D-E;

			if (maxextraL> 0 && maxextraW >0){
				F=(maxextraL-auxL)*(maxextraW-auxW);
				aux_nItems+=F;
			}

		
			if (aux_nItems<n_Items){
				cout << endl << "**Warning**" << endl;
				cout << endl << " In instance "<< i+1 <<" the number of different item types generated was " << n_Items << " this value is not feasible given the size of the large object and the range for the size of the item types!"  << endl;
				n_Items= (unsigned long) (aux_nItems-(aux_nItems*0.15));
				cout << endl << " The number of different item types was changed to " << n_Items << "."<< endl;

			}
		}

				

		FileOutRst << n_Items << endl;
	
		ItemL = new  unsigned long [n_Items];
		ItemW = new  unsigned long [n_Items];
		ItemH = new  unsigned long [n_Items];
		DItem_L = new  unsigned long [n_Items]; 
		DItem_U = new  unsigned long [n_Items];
		ItemValue = new  unsigned long [n_Items];


		 unsigned long long int TtItemAreaU=0;
		 unsigned long long int TtItemAreaL=0;
		 unsigned long minval;
		 unsigned long maxval;


		 int aux2;
		 for(j=0; j<n_Items; j++){	
			 aux=0;			
			 do {
				 k=0;
				 itL=Gen(alpha_ItemL,beta_ItemL,min_ItemS,max_ItemS);
				 itW=Gen(alpha_ItemW,beta_ItemW,min_ItemS,max_ItemS);
				 if(NDim==3) itH=Gen(alpha_ItemH,beta_ItemH,min_ItemH,max_ItemH);

				 //To forbid item repetition
				 aux2=0;
				 if(NDim==2){
					 for(l=0; l<j; l++){
						 if(ItemL[l]==itL && ItemW[l]==itW) aux2=1;
					 }
				 }
				 if(NDim==3){
					 for(l=0; l<j; l++){
						 if(ItemL[l]==itL && ItemW[l]==itW && ItemH[l]==itH) aux2=1;
					 }
				 }
				 if(aux2==0){
					 do{					
						 // Item must fit in at least one large object
						 if(NDim==2){
							 if(itL<=LargeObjL[k] && itW<=LargeObjW[k]){
								 ItemL[j]=itL;
								 ItemW[j]=itW;
								 aux=1;
							 }
						 }
						 if(NDim==3){
							 if(itL<=LargeObjL[k] && itW<=LargeObjW[k] && itH<=LargeObjH[k]){
								 ItemL[j]=itL;
								 ItemW[j]=itW;
								 ItemH[j]=itH;
								 aux=1;
							 }
						 }

						 k++;
					 } while (k<n_LargeObj && aux==0);
				 }
			 } while (aux==0);	

			DItem_L[j] = Gen(alpha_DItemL,beta_DItemL,min_DItemL,max_DItemL);
			DItem_U[j] = Gen(alpha_DItemU,beta_DItemU,min_DItemU,max_DItemU);
			
			//To ensure that the upper bound demand is greater or equal to the lower bound demand
			while(DItem_U[j]<DItem_L[j]){
				DItem_U[j] = Gen(alpha_DItemU,beta_DItemU,min_DItemU,max_DItemU);
				DItem_L[j] = Gen(alpha_DItemL,beta_DItemL,min_DItemL,max_DItemL);
			}

			// To generate the value of the items

			if(NDim==2){
				minval= (unsigned long) (min_ItemV*ItemL[j]*ItemW[j]);
				maxval= (unsigned long) (max_ItemV*ItemL[j]*ItemW[j]);
			}
			if(NDim==3){
				minval= (unsigned long) (min_ItemV*ItemL[j]*ItemW[j]*ItemH[j]);
				maxval= (unsigned long) (max_ItemV*ItemL[j]*ItemW[j]*ItemH[j]);
			}
			
			ItemValue[j] = Gen(1,1,minval,maxval);
			if(ItemValue[j]==0) ItemValue[j]=1;
		

			TtItemAreaU+= ItemL[j]*ItemW[j]*DItem_U[j];
			TtItemAreaL+=ItemL[j]*ItemW[j]*DItem_L[j];
			
			
			if(NDim==2) FileOutRst << ItemL[j] << '\t' << ItemW[j] << '\t' << DItem_L[j] << '\t' << DItem_U[j] << '\t' << ItemValue[j] << endl;
			if(NDim==3) FileOutRst << ItemL[j] << '\t' << ItemW[j] << '\t' << ItemH[j] << '\t' << DItem_L[j] << '\t' << DItem_U[j] << '\t' << ItemValue[j] << endl;
	
		}

		if(NDim==2){
			if (TtItemAreaU<TtLargeObjArea*0.5){
				cout << endl << "***Warning***" << endl;
				cout << endl << "Instance number " << i+1 << " may be very easy to solve, since the total area of the items times its upper bound demand  is smaller than 50% of the large objects area!" << endl; 
			}
			if (TtItemAreaL>TtLargeObjArea) cout << endl << "Instance number " << i+1 << " is impossible to solve since the total area of the items times its lower bound demand is greater than  the total large object area!" << endl; 
		}
	}

	FileOutRst.close();

 return 0;
}
int TwoDProbGen::KP()
{
	int i;
	unsigned long j, k;
	unsigned long itL, itW, itH;
	int aux;
	unsigned long current_n;
	unsigned long minLargObjL, minLargObjW;
	unsigned long LObjL, LObjW, LObjH;
	unsigned long long int TtItemArea;
	unsigned long long int TtLargeObjArea;


	char filename[100];
	if (ProblemType==6)cout<<" Enter the filename to save the problem test (e. g. C:\\programs\\SKP.txt): ";
	if (ProblemType==7)cout<<" Enter the filename to save the problem test (e. g. C:\\programs\\MIKP.txt): ";
	if (ProblemType==8)cout<<" Enter the filename to save the problem test (e. g. C:\\programs\\MHKPW.txt): ";
	if (ProblemType==9)cout<<" Enter the filename to save the problem test (e. g. C:\\programs\\MHKPS.txt): ";
    cin>>filename;
	ofstream FileOutRst;
	FileOutRst.open(filename);

	if(!FileOutRst.is_open( )){
		cout<<"It was not possible to open the file!\n";
		FileOutRst.clear( ); 
		exit (-1);
	}
	
	if(NDim==2)FileOutRst << "***2D Rectangular Problem***" << endl;
	if(NDim==3)FileOutRst << "***3D Rectangular Problem***" << endl;
	if(ProblemType==6) FileOutRst << "***Instances for the Single Knapsack Problem (SKP)***" << endl;
	if(ProblemType==7) FileOutRst << "***Instances for the Multiple Identical Knapsack Problem (MIKP)***" << endl;
	if(ProblemType==8) FileOutRst << "***Instances for the Multiple Heterogeneous Knapsack Problem (MHKP/W)***" << endl;
	if(ProblemType==9) FileOutRst << "***Instances for the Multiple Heterogeneous Knapsack Problem (MHKP/S)***" << endl;
	FileOutRst << "Input parameter file: " << InputParfilename << endl;
	FileOutRst << "***********************************************************************"<< endl;
	FileOutRst << "Total number of instances " << endl;
	if (ProblemType==8 || ProblemType==9)	FileOutRst << "Number of different large objects (j)" << endl;
	if (ProblemType==6){
		if(NDim==2) FileOutRst << "LargeObject.Length" << "\t" << "LargeObject.Width" << endl;
		if(NDim==3) FileOutRst << "LargeObject.Length" << "\t" << "LargeObject.Width" << "\t" << "LargeObject.Height" << endl;
	}
	if (ProblemType==7){
		if(NDim==2) FileOutRst << "LargeObject.Length" << "\t" << "LargeObject.Width" << "\t" << "LargeObject.Available" << endl;
		if(NDim==3) FileOutRst << "LargeObject.Length" << "\t" << "LargeObject.Width" << "\t" << "LargeObject.Height" << "\t" << "LargeObject.Available" << endl;
	}
	if (ProblemType==8){
		if(NDim==2) FileOutRst << "LargeObject[j].Length" << "\t" << "LargeObject[j].Width" << "\t" << "LargeObject[j].Available" << endl;
		if(NDim==3) FileOutRst << "LargeObject[j].Length" << "\t" << "LargeObject[j].Width" << "\t" << "LargeObject[j].Height" << "\t" << "LargeObject[j].Available" << endl;
	}
	if (ProblemType==9){
		if(NDim==2) FileOutRst << "LargeObject[j].Length" << "\t" << "LargeObject[j].Width" << endl;
		if(NDim==3) FileOutRst << "LargeObject[j].Length" << "\t" << "LargeObject[j].Width" << "\t" << "LargeObject[j].Height" << endl;
	}
		
	FileOutRst << "Number of different item types (i)" << endl;
	if(NDim==2) FileOutRst << "Item[i].Length" << "\t" << "Item[i].Width" << "\t" << "Item[i].Value" << endl;
	if(NDim==3) FileOutRst << "Item[i].Length" << "\t" << "Item[i].Width" << "\t" << "Item[i].Height" <<"\t" << "Item[i].Value" << endl;
	FileOutRst << "***********************************************************************"<< endl;

	FileOutRst << n_instances << endl;

	if(NDim==3){
		BetaDist(HLargeObj_Dist);
		alpha_LargeObjH=alphaDist;
		beta_LargeObjH=betaDist;
		BetaDist(HItem_Dist);
		alpha_ItemH=alphaDist;
		beta_ItemH=betaDist;
	}

	for (i=0;i<n_instances;i++){

		if (ProblemType==8 || ProblemType==9){
			BetaDist(n_LargeObjDist);
			n_LargeObj=Gen(alphaDist,betaDist,min_nLargeObj,max_nLargeObj);
			FileOutRst << n_LargeObj << endl;
		}
		else n_LargeObj=1;
	

		LargeObjL= new  unsigned long [n_LargeObj]; 
		LargeObjW= new  unsigned long [n_LargeObj]; 
		LargeObjH= new  unsigned long [n_LargeObj]; 
		ALargeObj= new  unsigned long [n_LargeObj]; 
		

		minLargObjL=max_LargeObjS;
		minLargObjW=max_LargeObjS;
		TtLargeObjArea=0;

		aux=1;
		current_n=0;
		if (ProblemType==6 || ProblemType==7 || ProblemType==8){
			for (j=0;j<n_LargeObj;j++){
				// To prevent large object repetition
				while(aux==1){
					aux=0;
					LObjL = Gen(alpha_LargeObjL,beta_LargeObjL,min_LargeObjS,max_LargeObjS);
					LObjW = Gen(alpha_LargeObjW,beta_LargeObjW,min_LargeObjS,max_LargeObjS);
					if(NDim==3) LObjH = Gen(alpha_LargeObjH,beta_LargeObjH,min_LargeObjH,max_LargeObjH);
					if(NDim==2){
						for(k=0; k<current_n; k++){
							if(LargeObjL[k]==LObjL && LargeObjW[k]==LObjW) aux=1;
						}
					}
					if(NDim==3){
						for(k=0; k<current_n; k++){
							if(LargeObjL[k]==LObjL && LargeObjW[k]==LObjW && LargeObjH[k]==LObjH ) aux=1;
						}
					}
				}
				
				LargeObjL[current_n]=LObjL;
				LargeObjW[current_n]=LObjW;
				if(NDim==3)LargeObjH[current_n]=LObjH;
				
				// To determine the number of large objects available of each type
				if(ProblemType==7 || ProblemType==8){
					BetaDist(DLargeObj_Dist);
					ALargeObj[current_n]=Gen(alphaDist,betaDist,min_LargeObjType,max_LargeObjType);
					if(NDim==2){
						TtLargeObjArea+=LargeObjL[current_n]*LargeObjW[current_n]*ALargeObj[current_n];
						FileOutRst << LargeObjL[current_n] << '\t' << LargeObjW[current_n] << '\t' << ALargeObj[current_n] << endl;
					}
					if(NDim==3){
						TtLargeObjArea+=LargeObjL[current_n]*LargeObjW[current_n]*LargeObjH[current_n]*ALargeObj[current_n];
						FileOutRst << LargeObjL[current_n] << '\t' << LargeObjW[current_n] << '\t' << LargeObjH[current_n] << '\t' << ALargeObj[current_n] << endl;
					}
				}
				else{
					if(NDim==2){
						TtLargeObjArea+=LargeObjL[current_n]*LargeObjW[current_n];
						FileOutRst << LargeObjL[current_n] << '\t' << LargeObjW[current_n] << endl;
					}
					if(NDim==3){
						TtLargeObjArea+=LargeObjL[current_n]*LargeObjW[current_n]*LargeObjH[current_n];
						FileOutRst << LargeObjL[current_n] << '\t' << LargeObjW[current_n] << '\t' << LargeObjH[current_n] << endl;
					}
				}

				current_n++;
				aux=1;
			}
		}

		// It is allowed large objects repetition 
		if(ProblemType==9){
			for (j=0;j<n_LargeObj;j++){
				LargeObjL[j]=Gen(alpha_LargeObjL,beta_LargeObjL,min_LargeObjS,max_LargeObjS);
				LargeObjW[j]=Gen(alpha_LargeObjW,beta_LargeObjW,min_LargeObjS,max_LargeObjS);
				
				if(NDim==2){
					TtLargeObjArea+=LargeObjL[j]*LargeObjW[j];
					FileOutRst << LargeObjL[j] << '\t' << LargeObjW[j] << endl;
				}
				if(NDim==3){
					LargeObjH[j]=Gen(alpha_LargeObjH,beta_LargeObjH,min_LargeObjH,max_LargeObjH);
					FileOutRst << LargeObjL[j] << '\t' << LargeObjW[j] << '\t' << LargeObjH[j] << endl;
					TtLargeObjArea+=LargeObjL[j]*LargeObjW[j]*LargeObjH[j];
				}
			}
		}


		BetaDist(n_ItemsDist);
		n_Items=Gen(alphaDist,betaDist,min_nItems,max_nItems);
		FileOutRst << n_Items << endl;

		ItemL = new  unsigned long [n_Items];
		ItemW = new  unsigned long [n_Items];
		ItemH = new  unsigned long [n_Items];
		ItemValue = new  unsigned long [n_Items];
		

		TtItemArea=0;
		for(j=0; j<n_Items; j++){	
			aux=0;			
			do {
				k=0;
				itL=Gen(alpha_ItemL,beta_ItemL,min_ItemS,max_ItemS);
				itW=Gen(alpha_ItemW,beta_ItemW,min_ItemS,max_ItemS);
				if(NDim==3) itH=Gen(alpha_ItemH,beta_ItemH,min_ItemH,max_ItemH);
				do{
					// Item must fit in at least one large object 
					if(NDim==2){
						if(itL<=LargeObjL[k] && itW<=LargeObjW[k]){
							ItemL[j]=itL;
							ItemW[j]=itW;
							aux=1;
						}
					}
					if(NDim==3){
						if(itL<=LargeObjL[k] && itW<=LargeObjW[k] && itH<=LargeObjH[k]){
							ItemL[j]=itL;
							ItemW[j]=itW;
							ItemH[j]=itH;
							aux=1;
						}
					}
					k++;
				} while (k<n_LargeObj && aux==0);
			} while (aux==0);	

			// To generate the value of the items
			unsigned long minval= (unsigned long) (min_ItemV*ItemL[j]*ItemW[j]);
			unsigned long maxval= (unsigned long) (max_ItemV*ItemL[j]*ItemW[j]);
			ItemValue[j] = Gen(1,1,minval,maxval);
			if(ItemValue[j]==0) ItemValue[j]=1;
		

			TtItemArea+= ItemL[j]*ItemW[j];			
			if(NDim==2) FileOutRst << ItemL[j] << '\t' << ItemW[j] << '\t' << ItemValue[j] << endl;
			if(NDim==3) FileOutRst << ItemL[j] << '\t' << ItemW[j] << '\t' << ItemH[j] << '\t' << ItemValue[j] << endl;
	
		}
		
		if(NDim==2){
			if (TtItemArea<TtLargeObjArea*0.5){
				cout << endl << "***Warning***" << endl;
				cout << endl << " Instance number " << i+1 << " may be very easy to solve, since the total area of the items times its upper bound demand  is smaller than 50% of the large objects area!" << endl; 
			}
		}
	}

	FileOutRst.close();


 return 0;
}
int TwoDProbGen::CSP()
{
	int i;
	unsigned long j,k,l;
	unsigned long itL, itW, itH;
	unsigned long maxAuxItemL, maxAuxItemW;
	unsigned long LObjL, LObjW, LObjH;
	unsigned long current_n;
	int aux;
	unsigned long long int TtLargeObjArea;
	unsigned long minval;
	unsigned long maxval;



	char filename[100];
	if(ProblemType==10) cout<<" Enter the filename to save the problem test (e. g. C:\\programs\\SSSCSP.txt): ";
	if(ProblemType==11) cout<<" Enter the filename to save the problem test (e. g. C:\\programs\\MSSCSP.txt): ";
	if(ProblemType==12) cout<<" Enter the filename to save the problem test (e. g. C:\\programs\\RCSP.txt): ";
    cin>>filename;
	ofstream FileOutRst;
	FileOutRst.open(filename);

	if(!FileOutRst.is_open( )){
		cout<<"It was not possible to open the file!\n";
		FileOutRst.clear( ); 
		exit (-1);
	} 
	
	if(NDim==2)FileOutRst << "***2D Rectangular Problem***" << endl;
	if(NDim==3)FileOutRst << "***3D Rectangular Problem***" << endl;
	if(ProblemType==10) FileOutRst << "***Instances for the Single Stock Size Cutting Stock Problem (SSSCSP)***" << endl;
	if(ProblemType==11) FileOutRst << "***Instances for the Multiple Stock Size Cutting Stock Problem (MSSCSP)***" << endl;
	if(ProblemType==12) FileOutRst << "***Instances for the Residual Cutting Stock Problem (RCSP)***" << endl;
	FileOutRst << "Input parameter file: " << InputParfilename << endl;
	FileOutRst << "****************************************************************************************************"<< endl;
	FileOutRst << "Total number of instances " << endl;
	if(ProblemType==11 || ProblemType==12)FileOutRst << "Number of different large objects (j)" << endl;
	if(ProblemType==10){
		if(NDim==2) FileOutRst << "LargeObject.Length" << "\t" << "LargeObject.Width" <<  endl; 
		if(NDim==3) FileOutRst << "LargeObject.Length" << "\t" << "LargeObject.Width" << "\t" << "LargeObject.Height" <<  endl; 
	}
	if(ProblemType==11){
		if(NDim==2) FileOutRst << "LargeObject[j].Length" << "\t" << "LargeObject[j].Width" << "\t" << "LargeObject[j].Available" << "\t" <<  "LargeObject[j].Value"  <<  endl; 
		if(NDim==3) FileOutRst << "LargeObject[j].Length" << "\t" << "LargeObject[j].Width" << "\t" << "LargeObject[j].Height" << "\t" << "LargeObject[j].Available" << "\t" <<  "LargeObject[j].Value"  <<  endl; 
	}
	if(ProblemType==12){
		if(NDim==2) FileOutRst << "LargeObject[j].Length" << "\t" << "LargeObject[j].Width" <<  "\t" << "LargeObject[j].Value"  << endl; 
		if(NDim==3) FileOutRst << "LargeObject[j].Length" << "\t" << "LargeObject[j].Width" << "\t" << "LargeObject[j].Height" << "\t" << "LargeObject[j].Value"  << endl; 
	}
	FileOutRst << "Number of different item types (i)" << endl;
	if(NDim==2) FileOutRst << "Item[i].Length" << "\t" << "Item[i].Width" << "\t" << "Item[i].Demand" <<  endl;
	if(NDim==3) FileOutRst << "Item[i].Length" << "\t" << "Item[i].Width" << "\t" << "Item[i].Height" << "\t" << "Item[i].Demand" <<  endl;
	FileOutRst << "*****************************************************************************************************"<< endl;
		
	FileOutRst << n_instances << endl;

	if(NDim==3){
		BetaDist(HLargeObj_Dist);
		alpha_LargeObjH=alphaDist;
		beta_LargeObjH=betaDist;
		BetaDist(HItem_Dist);
		alpha_ItemH=alphaDist;
		beta_ItemH=betaDist;
	}

	for (i=0;i<n_instances;i++){

		//Determines the number of different large objects
		if(ProblemType==11 || ProblemType==12){
			BetaDist(n_LargeObjDist);
			n_LargeObj=Gen(alphaDist,betaDist,min_nLargeObj,max_nLargeObj);
			FileOutRst << n_LargeObj << endl;
		}
		else n_LargeObj=1;

		TtLargeObjArea=0;

		LargeObjL= new  unsigned long [n_LargeObj]; 
		LargeObjW= new  unsigned long [n_LargeObj]; 
		LargeObjH= new  unsigned long [n_LargeObj]; 
		ALargeObj= new  unsigned long [n_LargeObj]; 
		LargeObj_Value = new  unsigned long [n_LargeObj]; 


		aux=1;
		current_n=0;
		// To forbid large object size repetition
		if (ProblemType==11){
			for (j=0;j<n_LargeObj;j++){
				
				while(aux==1){
					if(NDim==2){
						aux=0;
						LObjL = Gen(alpha_LargeObjL,beta_LargeObjL,min_LargeObjS,max_LargeObjS);
						LObjW = Gen(alpha_LargeObjW,beta_LargeObjW,min_LargeObjS,max_LargeObjS);
						for(k=0; k<current_n; k++){
							if(LargeObjL[k]==LObjL && LargeObjW[k]==LObjW) aux=1;
						}
					}
					if(NDim==3){
						aux=0;
						LObjL = Gen(alpha_LargeObjL,beta_LargeObjL,min_LargeObjS,max_LargeObjS);
						LObjW = Gen(alpha_LargeObjW,beta_LargeObjW,min_LargeObjS,max_LargeObjS);
						LObjH = Gen(alpha_LargeObjH,beta_LargeObjH,min_LargeObjH,max_LargeObjH);
						for(k=0; k<current_n; k++){
							if(LargeObjL[k]==LObjL && LargeObjW[k]==LObjW && LargeObjH[k]==LObjH) aux=1;
						}
					}
					
				}
				
				LargeObjL[current_n]=LObjL;
				LargeObjW[current_n]=LObjW;
				if(NDim==3) LargeObjH[current_n]=LObjH;
				
				// To determine number of large objects available of each type				
				BetaDist(DLargeObj_Dist);
				ALargeObj[current_n]=Gen(alphaDist,betaDist,min_LargeObjType,max_LargeObjType);
				TtLargeObjArea+=LargeObjL[current_n]*LargeObjW[current_n]*ALargeObj[current_n];								

				// To generate the value of the large objects
				if(NDim==2){
					minval= (unsigned long) (min_LargObjV*LargeObjL[current_n]*LargeObjW[current_n]);
					maxval= (unsigned long) (max_LargObjV*LargeObjL[current_n]*LargeObjW[current_n]);
				}
				if(NDim==3){
					minval= (unsigned long) (min_LargObjV*LargeObjL[current_n]*LargeObjW[current_n]*LargeObjH[current_n]);
					maxval= (unsigned long) (max_LargObjV*LargeObjL[current_n]*LargeObjW[current_n]*LargeObjH[current_n]);
				}
				
				LargeObj_Value[current_n] = Gen(1,1,minval,maxval);
	 
				current_n++;
				aux=1;

			}
		}
		// Large object size repetition is allowed
		else {
			for (j=0;j<n_LargeObj;j++){
				LargeObjL[j]=Gen(alpha_LargeObjL,beta_LargeObjL,min_LargeObjS,max_LargeObjS);
				LargeObjW[j]=Gen(alpha_LargeObjW,beta_LargeObjW,min_LargeObjS,max_LargeObjS);
				if(NDim==3) LargeObjH[j]=Gen(alpha_LargeObjH,beta_LargeObjH,min_LargeObjH,max_LargeObjH);
				if(NDim==2)TtLargeObjArea+=LargeObjL[current_n]*LargeObjW[current_n];
				if(NDim==3)TtLargeObjArea+=LargeObjL[current_n]*LargeObjW[current_n]*LargeObjH[current_n];

				if (ProblemType==12){
					if(NDim==2){
						minval= (unsigned long) (min_LargObjV*LargeObjL[j]*LargeObjW[j]);
						maxval= (unsigned long) (max_LargObjV*LargeObjL[j]*LargeObjW[j]);
					}
					if(NDim==3){
						minval= (unsigned long) (min_LargObjV*LargeObjL[j]*LargeObjW[j]*LargeObjH[j]);
						maxval= (unsigned long) (max_LargObjV*LargeObjL[j]*LargeObjW[j]*LargeObjH[j]);
					}

					LargeObj_Value[j] = Gen(1,1,minval,maxval);
				}
			}
		}


		// Determines the number of different item types
		BetaDist(n_ItemsDist);
		n_Items=Gen(alphaDist,betaDist,min_nItems,max_nItems);

		unsigned long Maximum_NPossibleItems =(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1);
		Maximum_NPossibleItems= (unsigned long) (Maximum_NPossibleItems-Maximum_NPossibleItems*0.15);
		if(NDim==2){
			if(n_Items> Maximum_NPossibleItems) n_Items=Maximum_NPossibleItems;
		}
		if(NDim==3){
			Maximum_NPossibleItems=(max_ItemS-min_ItemS+1)*(max_ItemS-min_ItemS+1)*(max_ItemH-max_ItemH+1);
			if(n_Items==Maximum_NPossibleItems) n_Items= (unsigned long) (Maximum_NPossibleItems-Maximum_NPossibleItems*0.15);
		}

		//Determines the maximum number of different item types considering the sizes of large objects generated
		if(NDim==2){
			maxAuxItemL=min_LargeObjS;
			maxAuxItemW=min_LargeObjS;
			unsigned long aux_nItems;


			unsigned long *LO_ItemMaxL = new unsigned long [n_LargeObj];
			if (LO_ItemMaxL==NULL) {
				cout << endl << "ERROR on memory allocation" << endl;
				exit(-1);
			}
			unsigned long *LO_ItemMaxW = new unsigned long [n_LargeObj];
			if (LO_ItemMaxW==NULL) {
				cout << endl << "ERROR on memory allocation" << endl;
				exit(-1);
			}

			
			for(j=0;j<n_LargeObj;j++){
				if (LargeObjL[j]>max_ItemS) LO_ItemMaxL[j]=max_ItemS;
				else LO_ItemMaxL[j]=LargeObjL[j];
				if (LargeObjW[j]>max_ItemS) LO_ItemMaxW[j]=max_ItemS;
				else LO_ItemMaxW[j]=LargeObjW[j];

			}

			

			unsigned long auxW=min_LargeObjS;
			unsigned long auxL=min_LargeObjS;

			for(j=0;j<n_LargeObj;j++){
				if (maxAuxItemL<=LO_ItemMaxL[j]){
					if(maxAuxItemL==LO_ItemMaxL[j]){
						if(auxW<LO_ItemMaxW[j]) auxW=LO_ItemMaxW[j];
					}
					else{
						maxAuxItemL=LO_ItemMaxL[j];
						auxW=LO_ItemMaxW[j];
					}
				}
				if (maxAuxItemW<=LO_ItemMaxW[j]){
					if(maxAuxItemW==LO_ItemMaxW[j]){
						if(auxL<LO_ItemMaxL[j]) auxL=LO_ItemMaxL[j];
					}
					else{
						maxAuxItemW=LO_ItemMaxW[j];
						auxL=LO_ItemMaxL[j];
					}
				}
			}		

			unsigned long *extraL = new unsigned long [n_LargeObj];
			if (extraL==NULL) {
				cout << endl << "ERROR on memory allocation" << endl;
				exit(-1);
			}
			unsigned long *extraW = new unsigned long [n_LargeObj];
			if (extraW==NULL) {
				cout << endl << "ERROR on memory allocation" << endl;
				exit(-1);
			}

			unsigned long maxextraL=0;
			unsigned long maxextraW=0;

			for(j=0; j<n_LargeObj; j++){
				if(LO_ItemMaxL[j] > auxL && LO_ItemMaxW[j] > auxW){
					extraL[j]=LO_ItemMaxL[j];
					extraW[j]=LO_ItemMaxW[j];
				}
				else{
					extraL[j]=0;
					extraW[j]=0;
				}
			}

			for(j=0; j<n_LargeObj; j++){
				if(maxextraL < extraL[j] && maxextraW < extraW[j]){
					maxextraL=extraL[j];
					maxextraW=extraW[j];
				}

			}


			delete [] LO_ItemMaxL;
			delete [] LO_ItemMaxW;
			delete [] extraL;
			delete [] extraW;


			int A, B, C, D, E, F;

	
			if(maxAuxItemL>max_ItemS)A=max_ItemS;
			else A=maxAuxItemL;
			if(auxW>max_ItemS)B=max_ItemS;
			else B=auxW;
			C =(A-min_ItemS+1)*(B-min_ItemS+1);

			
			if(maxAuxItemW>max_ItemS)A=max_ItemS;
			else A=maxAuxItemW;
			if(auxL>max_ItemS)B=max_ItemS;
			else B=auxL;
			D =(A-min_ItemS+1)*(B-min_ItemS+1);

			
			if(auxW>max_ItemS)A=max_ItemS;
			else A=auxW;
			if(auxL>max_ItemS)B=max_ItemS;
			else B=auxL;
			E =(A-min_ItemS+1)*(B-min_ItemS+1);
			aux_nItems=C+D-E;

			if (maxextraL> 0 && maxextraW >0){
				F=(maxextraL-auxL)*(maxextraW-auxW);
				aux_nItems+=F;
			}
		
			if (aux_nItems<n_Items){
				cout << endl << "**Warning**" << endl;
				cout << endl << " In instance "<< i+1 <<" the number of different item types generated was " << n_Items << " this value is not feasible given the size of the large object and the range for the size of the item types!"  << endl;
				n_Items= (unsigned long)(aux_nItems-(aux_nItems*0.15));
				cout << endl << " The number of different item types was changed to " << n_Items << "."<< endl;

			}
		}

					

		ItemL = new unsigned long [n_Items];
		ItemW = new unsigned long [n_Items];
		ItemH = new unsigned long [n_Items];
		DItem_U = new unsigned long [n_Items];

		BetaDist(DItemU_Dist);
		alpha_DItemU=alphaDist;
		beta_DItemU=betaDist;


		unsigned long long int TtItemArea;
		TtItemArea=0;

		int aux2;
		for(j=0; j<n_Items; j++){	
			aux=0;			
			do {
				k=0;
				itL=Gen(alpha_ItemL,beta_ItemL,min_ItemS,max_ItemS);
				itW=Gen(alpha_ItemW,beta_ItemW,min_ItemS,max_ItemS);
				if(NDim==3) itH=Gen(alpha_ItemH,beta_ItemH,min_ItemH,max_ItemH);

				//To forbid item repetition
				aux2=0;
				if(NDim==2){
					for(l=0; l<j; l++){
						if(ItemL[l]==itL && ItemW[l]==itW) aux2=1;
					}
				}
				if(NDim==3){
					for(l=0; l<j; l++){
						if(ItemL[l]==itL && ItemW[l]==itW && ItemH[l]==itH) aux2=1;
					}
				}
				if(aux2==0){
					do{					
						// Item must fit in at least one large object
						if(NDim==2){
							if(itL<=LargeObjL[k] && itW<=LargeObjW[k]){
								ItemL[j]=itL;
								ItemW[j]=itW;
								DItem_U[j] = Gen(alpha_DItemU,beta_DItemU,min_DItemU,max_DItemU);
								TtItemArea+= ItemL[j]*ItemW[j]*DItem_U[j];
								aux=1;
							}
						}
						if(NDim==3){
							if(itL<=LargeObjL[k] && itW<=LargeObjW[k] && itH<=LargeObjH[k]){
								ItemL[j]=itL;
								ItemW[j]=itW;
								ItemH[j]=itH;
								DItem_U[j] = Gen(alpha_DItemU,beta_DItemU,min_DItemU,max_DItemU);
								TtItemArea+= ItemL[j]*ItemW[j]*DItem_U[j]*ItemH[j];
								aux=1;
							}
						}
						
						k++;
					} while (k<n_LargeObj && aux==0);
				}
			} while (aux==0);	
		}

		

		for (j=0;j<n_LargeObj;j++){
			if(ProblemType==10){
				if(NDim==2) FileOutRst << LargeObjL[j] << '\t' << LargeObjW[j] << endl;
				if(NDim==3) FileOutRst << LargeObjL[j] << '\t' << LargeObjW[j] << '\t' << LargeObjH[j] << endl;
			}
			if(ProblemType==11){
				if(NDim==2) FileOutRst << LargeObjL[j] << '\t' << LargeObjW[j] << '\t' << ALargeObj[j]  <<  '\t' <<  LargeObj_Value[j] << endl;
				if(NDim==3) FileOutRst << LargeObjL[j] << '\t' << LargeObjW[j] << '\t' << LargeObjH[j] << '\t' << ALargeObj[j]  <<  '\t' <<  LargeObj_Value[j] << endl;
			}
			if(ProblemType==12){
				if(NDim==2) FileOutRst << LargeObjL[j] << '\t' << LargeObjW[j] << '\t' << LargeObj_Value[j] << endl;
				if(NDim==3) FileOutRst << LargeObjL[j] << '\t' << LargeObjW[j] << '\t' << LargeObjH[j] << '\t' << LargeObj_Value[j] << endl;
			}
		}

		FileOutRst << n_Items << endl;

		for (j=0;j<n_Items;j++){
			if(NDim==2) FileOutRst << ItemL[j] << '\t' << ItemW[j] << '\t' << DItem_U[j] << endl;
			if(NDim==3) FileOutRst << ItemL[j] << '\t' << ItemW[j] << '\t' << ItemH[j] << '\t' << DItem_U[j] << endl;
		}

		if(NDim==2){
			if(n_LargeObj==1){
				if (TtItemArea<TtLargeObjArea*0.5){
					cout << endl << "***Warning***" << endl;
					cout << endl << " Instance number " << i+1 << " may be very easy to solve, since the total area of the items is smaller than 50% of the large object area!" << endl;
				}
			}
		}
		
	}

	FileOutRst.close();

	
 return 0;
}
int TwoDProbGen::BPP()
{
 int i;
 unsigned long j, k;
 unsigned long itL, itW, itH;
 unsigned long minLargObjL, minLargObjW;
 unsigned long LObjL, LObjW, LObjH;
 unsigned long current_n;
 int aux;
 unsigned long TtLargeObjArea;
 unsigned long TtItemArea;
 unsigned long minval;
 unsigned long maxval;

	
	char filename[100];
	if(ProblemType==13) cout<<" Enter the filename to save the problem test (e. g. C:\\programs\\SBSBPP.txt): ";
	if(ProblemType==14) cout<<" Enter the filename to save the problem test (e. g. C:\\programs\\MBSBPP.txt): ";
	if(ProblemType==15) cout<<" Enter the filename to save the problem test (e. g. C:\\programs\\RBPP.txt): ";
    cin>>filename;
	ofstream FileOutRst;
	FileOutRst.open(filename);

	if(!FileOutRst.is_open( )){
		cout<<"It was not possible to open the file!\n";
		FileOutRst.clear( ); 
		exit (-1);
	}
	
	if(NDim==2)FileOutRst << "***2D Rectangular Problem***" << endl;
	if(NDim==3)FileOutRst << "***3D Rectangular Problem***" << endl;
	if(ProblemType==13) FileOutRst << "***Instances for the Single Bin Size Bin Packing Problem (SBSBPP)***"<< endl;
	if(ProblemType==14) FileOutRst << "***Instances for the Multiple Bin Size Bin Packing Problem (MBSBPP)***"<< endl;
	if(ProblemType==15) FileOutRst << "***Instances for the Residual Bin Packing Problem (RBPP)***"<< endl;
	FileOutRst << "Input parameter file: " << InputParfilename  << endl;
	FileOutRst << "***********************************************************************"<< endl;
	FileOutRst << "Total number of instances " << endl;
	if(ProblemType==14 || ProblemType==15) 	FileOutRst << "Number of different large objects (j)" << endl;
	if(ProblemType==13){
		if(NDim==2) FileOutRst << "LargeObject.Length" << "\t" << "LargeObject.Width" << endl;
		if(NDim==3) FileOutRst << "LargeObject.Length" << "\t" << "LargeObject.Width" << "\t" << "LargeObject.Height" << endl;
	}
	if(ProblemType==14){
		if(NDim==2) FileOutRst << "LargeObject[j].Length" << "\t" << "LargeObject[j].Width" << "\t" << "LargeObject[j].Available" << "\t" << "LargeObject[j].Value" << endl;
		if(NDim==3) FileOutRst << "LargeObject[j].Length" << "\t" << "LargeObject[j].Width" << "\t" << "LargeObject[j].Height" << "\t" << "LargeObject[j].Available" << "\t" << "LargeObject[j].Value" << endl;
	}
	if(ProblemType==15){
		if(NDim==2) FileOutRst << "LargeObject[j].Length" << "\t" << "LargeObject[j].Width"<<  "\t" << "LargeObject[j].Value" << endl; 
		if(NDim==3) FileOutRst << "LargeObject[j].Length" << "\t" << "LargeObject[j].Width"<< "\t" << "LargeObject[j].Height"<<  "\t" << "LargeObject[j].Value" << endl; 
	}
	FileOutRst << "Number of different item types (i)" << endl;
	if(NDim==2) FileOutRst << "Item[i].Length" << "\t" << "Item[i].Width" <<  endl;
	if(NDim==3) FileOutRst << "Item[i].Length" << "\t" << "Item[i].Width" << "\t" << "Item[i].Height" <<  endl;
	FileOutRst << "***********************************************************************"<< endl;

	FileOutRst << n_instances << endl;

	if(NDim==3){
		BetaDist(HLargeObj_Dist);
		alpha_LargeObjH=alphaDist;
		beta_LargeObjH=betaDist;
		BetaDist(HItem_Dist);
		alpha_ItemH=alphaDist;
		beta_ItemH=betaDist;
	}
	
	
	if(ProblemType==14){
		BetaDist(DLargeObj_Dist);
		alpha_DLargeObjType=alphaDist;
		beta_DLargeObjType=betaDist;
	}
	
	for (i=0;i<n_instances;i++){
		

	// Determination of the number of different large objects
		if(ProblemType==14 || ProblemType==15){
			BetaDist(n_LargeObjDist);
			n_LargeObj=Gen(alphaDist,betaDist,min_nLargeObj,max_nLargeObj);
			FileOutRst << n_LargeObj << endl;
		}
		else n_LargeObj=1;


		LargeObjL= new  unsigned long [n_LargeObj]; 
		LargeObjW= new  unsigned long [n_LargeObj]; 
		LargeObjH= new  unsigned long [n_LargeObj]; 
		ALargeObj= new  unsigned long [n_LargeObj]; 
		LargeObj_Value= new   unsigned long [n_LargeObj];

		minLargObjL=max_LargeObjS;
		minLargObjW=max_LargeObjS;
		aux=1;
		current_n=0;
		TtLargeObjArea=0;
		
		if(ProblemType==14){
			for (j=0;j<n_LargeObj;j++){
				// To prevent large object repetition
				while(aux==1){
					if(NDim==2){
						aux=0;
						LObjL = Gen(alpha_LargeObjL,beta_LargeObjL,min_LargeObjS,max_LargeObjS);
						LObjW = Gen(alpha_LargeObjW,beta_LargeObjW,min_LargeObjS,max_LargeObjS);
						for(k=0; k<current_n; k++){
							if(LargeObjL[k]==LObjL && LargeObjW[k]==LObjW) aux=1;
						}
					}
					if(NDim==3){
						aux=0;
						LObjL = Gen(alpha_LargeObjL,beta_LargeObjL,min_LargeObjS,max_LargeObjS);
						LObjW = Gen(alpha_LargeObjW,beta_LargeObjW,min_LargeObjS,max_LargeObjS);
						LObjH = Gen(alpha_LargeObjH,beta_LargeObjH,min_LargeObjH,max_LargeObjH);
						for(k=0; k<current_n; k++){
							if(LargeObjL[k]==LObjL && LargeObjW[k]==LObjW && LargeObjH[k]==LObjH) aux=1;
						}
					}
					
				}
				
				LargeObjL[current_n]=LObjL;
				LargeObjW[current_n]=LObjW;
				if(NDim==3) LargeObjH[current_n]=LObjH;

				// To determine the number of bins of each type available				
				BetaDist(DLargeObj_Dist);
				ALargeObj[current_n]=Gen(alphaDist,betaDist,min_LargeObjType,max_LargeObjType);
				if(NDim==2)TtLargeObjArea+=LargeObjL[current_n]*LargeObjW[current_n]*ALargeObj[current_n];
				if(NDim==3)TtLargeObjArea+=LargeObjL[current_n]*LargeObjW[current_n]*LargeObjH[current_n]*ALargeObj[current_n];
				
				
				// To generate the value of the large objects
				
				if(NDim==2){
					minval= (unsigned long) (min_LargObjV*LargeObjL[current_n]*LargeObjW[current_n]);
					maxval= (unsigned long) (max_LargObjV*LargeObjL[current_n]*LargeObjW[current_n]);
				}
				if(NDim==3){
					minval= (unsigned long) (min_LargObjV*LargeObjL[current_n]*LargeObjW[current_n]*LargeObjH[current_n]);
					maxval= (unsigned long) (max_LargObjV*LargeObjL[current_n]*LargeObjW[current_n]*LargeObjH[current_n]);
				}
				
				LargeObj_Value[current_n] = Gen(1,1,minval,maxval);
		

				current_n++;
				aux=1;

			}
		}


		// Large object size repetition is allowed
		else {
			for (j=0;j<n_LargeObj;j++){
				LargeObjL[j]=Gen(alpha_LargeObjL,beta_LargeObjL,min_LargeObjS,max_LargeObjS);
				LargeObjW[j]=Gen(alpha_LargeObjW,beta_LargeObjW,min_LargeObjS,max_LargeObjS);
				if(NDim==3) LargeObjH[j]=Gen(alpha_LargeObjH,beta_LargeObjH,min_LargeObjH,max_LargeObjH);
				if(NDim==2)TtLargeObjArea+=LargeObjL[current_n]*LargeObjW[current_n];
				if(NDim==3)TtLargeObjArea+=LargeObjL[current_n]*LargeObjW[current_n]*LargeObjH[current_n];
				if (ProblemType==15){
					if(NDim==2){
						minval= (unsigned long) (min_LargObjV*LargeObjL[j]*LargeObjW[j]);
						maxval= (unsigned long) (max_LargObjV*LargeObjL[j]*LargeObjW[j]);
					}
					if(NDim==3){
						minval= (unsigned long) (min_LargObjV*LargeObjL[j]*LargeObjW[j]*LargeObjH[j]);
						maxval= (unsigned long) (max_LargObjV*LargeObjL[j]*LargeObjW[j]*LargeObjH[j]);
					}
					LargeObj_Value[j] = Gen(1,1,minval,maxval);
				}
			}
		}

		BetaDist(n_ItemsDist);
		n_Items=Gen(alphaDist,betaDist,min_nItems,max_nItems);

		ItemL = new  unsigned long [n_Items];
		ItemW = new  unsigned long [n_Items];
		ItemH = new  unsigned long [n_Items];

		TtItemArea=0;
		
		for(j=0; j<n_Items; j++){	
			aux=0;			
			do {
				k=0;
				itL=Gen(alpha_ItemL,beta_ItemL,min_ItemS,max_ItemS);
				itW=Gen(alpha_ItemW,beta_ItemW,min_ItemS,max_ItemS);
				if(NDim==3) itH=Gen(alpha_ItemH,beta_ItemH,min_ItemH,max_ItemH);
				do{
					// Item must fit in at least one large object 
					if(NDim==2){
						if(itL<=LargeObjL[k] && itW<=LargeObjW[k]){
							ItemL[j]=itL;
							ItemW[j]=itW;
							aux=1;
						}
					}
					if(NDim==3){
						if(itL<=LargeObjL[k] && itW<=LargeObjW[k] && itH<=LargeObjH[k]){
							ItemL[j]=itL;
							ItemW[j]=itW;
							ItemH[j]=itH;
							aux=1;
						}
					}
					
					k++;
				} while (k<n_LargeObj && aux==0);
			} while (aux==0);	

	
			if(NDim==2)TtItemArea+= ItemL[j]*ItemW[j];	
			if(NDim==3)TtItemArea+= ItemL[j]*ItemW[j]*ItemH[j];	
	
		}
		
	
		for (j=0;j<n_LargeObj;j++){
			if(ProblemType==13){
				if(NDim==2) FileOutRst << LargeObjL[j] << '\t' << LargeObjW[j] << endl;
				if(NDim==3) FileOutRst << LargeObjL[j] << '\t' << LargeObjW[j] << '\t' << LargeObjH[j] << endl;
			}
			if(ProblemType==14){
				if(NDim==2) FileOutRst << LargeObjL[j] << '\t' << LargeObjW[j] << '\t' << ALargeObj[j] <<  '\t' <<  LargeObj_Value[j] << endl;
				if(NDim==3) FileOutRst << LargeObjL[j] << '\t' << LargeObjW[j] << '\t' << LargeObjH[j] << '\t' << ALargeObj[j] <<  '\t' <<  LargeObj_Value[j] << endl;
			}
			if(ProblemType==15){
				if(NDim==2) FileOutRst << LargeObjL[j] << '\t' << LargeObjW[j] << '\t' << LargeObj_Value[j] << endl;
				if(NDim==3) FileOutRst << LargeObjL[j] << '\t' << LargeObjW[j] << '\t' << LargeObjH[j] << '\t' << LargeObj_Value[j] << endl;
			}
		}
		FileOutRst << n_Items << endl;

		if(NDim==2){
			for (j=0;j<n_Items;j++){
				FileOutRst << ItemL[j] << '\t' << ItemW[j] << endl;
			}
		}
		
		if(NDim==3){
			for (j=0;j<n_Items;j++){
				FileOutRst << ItemL[j] << '\t' << ItemW[j] << '\t' << ItemH[j] << endl;
			}
		}

		if(NDim==2){
			if (n_LargeObj==1){
				if (TtItemArea<TtLargeObjArea*0.5) cout << endl << " Instance number " << i+1 << " may be very easy to solve, since the total area of the items is smaller than 60% of the large object area!" << endl;
			}
		}
	}


	FileOutRst.close();

 return 0;

}
int TwoDProbGen::ODP()
{
 int i;
 unsigned long j,k, l;
 unsigned long itL, itW, itH;
 unsigned long LObjW, LObjH;
 unsigned long current_n;

 int aux;
 int A;
	


	char filename[100];
	if(ProblemType==16) cout<<" Enter the filename to save the problem test (e. g. C:\\programs\\ODPW.txt): ";
	if(ProblemType==17) cout<<" Enter the filename to save the problem test (e. g. C:\\programs\\ODPS.txt): ";
    cin>>filename;
	ofstream FileOutRst;
	FileOutRst.open(filename);

	if(!FileOutRst.is_open( )){
		cout<<"It was not possible to open the file!" << endl;
		FileOutRst.clear( ); 
		exit (-1);
	}
	
	if(NDim==2)FileOutRst << "***2D Rectangular Problem***" << endl;
	if(NDim==3)FileOutRst << "***3D Rectangular Problem***" << endl;
	if(ProblemType==16) FileOutRst << "***Problem tests for the Open Dimension Problem (ODP/W)***" << endl;
	if(ProblemType==17) FileOutRst << "***Problem tests for the Open Dimension Problem (ODP/S)***" << endl;
	FileOutRst << "Input parameter file: " << InputParfilename << endl;
	FileOutRst << "***********************************************************************"<< endl;
	FileOutRst << "Total number of instances " << endl;
	FileOutRst << "Number of different large objects (j)" << endl;
	if(ProblemType==16){
		if(NDim==2) FileOutRst << "LargeObject[j].Width" << "\t" << "LargeObject[j].Available" << "\t" << "LargeObject[j].Value" <<  endl;
		if(NDim==3) FileOutRst << "LargeObject[j].Width" << "\t" << "LargeObject[j].Height" << "\t" << "LargeObject[j].Available" << "\t" << "LargeObject[j].Value" <<  endl;
	}
	if(ProblemType==17){
		if(NDim==2) FileOutRst << "LargeObject[j].Width" << "\t" << "LargeObject[j].Value" << endl;
		if(NDim==3) FileOutRst << "LargeObject[j].Width" << "\t" << "LargeObject[j].Height" << "\t" << "LargeObject[j].Value" << endl;
	}
	FileOutRst << "Number of different item types (i)" << endl;
	if(NDim==2) FileOutRst << "Item[i].Length" << "\t" << "Item[i].Width" << "\t" <<  "Item[i].Demand" <<  endl;
	if(NDim==3) FileOutRst << "Item[i].Length" << "\t" << "Item[i].Width" << "\t" <<  "Item[i].Height" << "\t" <<  "Item[i].Demand" <<  endl;
	FileOutRst << "***********************************************************************"<< endl;

	FileOutRst << n_instances << endl;

	BetaDist(w_LargeObjDist);
	alpha_LargeObjW=alphaDist;
	beta_LargeObjW=betaDist;
	BetaDist(DItemU_Dist);
	alpha_DItemU=alphaDist;
	beta_DItemU=betaDist;
	if(NDim==3){
		BetaDist(HLargeObj_Dist);
		alpha_LargeObjH=alphaDist;
		beta_LargeObjH=betaDist;
		BetaDist(HItem_Dist);
		alpha_ItemH=alphaDist;
		beta_ItemH=betaDist;
	}


	for (i=0;i<n_instances;i++){

		BetaDist(n_LargeObjDist);
		n_LargeObj=Gen(alphaDist,betaDist,min_nLargeObj,max_nLargeObj);
		FileOutRst << n_LargeObj << endl;


		LargeObjW= new  unsigned long [n_LargeObj]; 
		LargeObjH= new  unsigned long [n_LargeObj]; 
		ALargeObj= new  unsigned long [n_LargeObj]; 
		LargeObj_Value= new   unsigned long [n_LargeObj];
		
		aux=1;
		current_n=0;			
		if (ProblemType==16) {
			for(j=0;j<n_LargeObj;j++){
				// To forbid Width repetition of the large object
				while(aux==1){
					if(NDim==2){
						aux=0;
						LObjW = Gen(alpha_LargeObjW,beta_LargeObjW,min_LargeObjS,max_LargeObjS);
						for(k=0; k<current_n; k++){
							if(LargeObjW[k]==LObjW) aux=1;
						}
					}
					if(NDim==3){
						aux=0;
						LObjW = Gen(alpha_LargeObjW,beta_LargeObjW,min_LargeObjS,max_LargeObjS);
						LObjH = Gen(alpha_LargeObjH,beta_LargeObjH,min_LargeObjH,max_LargeObjH);
						for(k=0; k<current_n; k++){
							if(LargeObjW[k]==LObjW && LargeObjH[k]==LObjH) aux=1;
						}
					}
				}

				LargeObjW[current_n]=LObjW;
				// To determine number of large objects available of each type
				BetaDist(DLargeObj_Dist);
				ALargeObj[j]=Gen(alphaDist,betaDist,min_LargeObjType,max_LargeObjType);
				current_n++;
				aux=1;
			}
		}
		if(ProblemType==17){
			for(j=0;j<n_LargeObj;j++){
				LargeObjW[j]=Gen(alpha_LargeObjW,beta_LargeObjW,min_LargeObjW,max_LargeObjW);
				if(NDim==3)	LargeObjH[j]=Gen(alpha_LargeObjH,beta_LargeObjH,min_LargeObjH,max_LargeObjH);
			}
		}

		for(j=0;j<n_LargeObj;j++){

			// To generate the value of the large objects
			unsigned long minval;
			unsigned long maxval;
			if(NDim==2){
				minval= (unsigned long) (min_LargObjV*LargeObjW[j]);
				maxval= (unsigned long) (max_LargObjV*LargeObjW[j]);
			}
			if(NDim==3){
				minval= (unsigned long) (min_LargObjV*LargeObjW[j]*LargeObjH[j]);
				maxval= (unsigned long) (max_LargObjV*LargeObjW[j]*LargeObjH[j]);
			}
			LargeObj_Value[j] = Gen(1,1,minval,maxval);		
			
			if (ProblemType==16){
				if(NDim==2) FileOutRst << LargeObjW[j] << "\t" << ALargeObj[j] << "\t" << LargeObj_Value[j] <<  endl;
				if(NDim==3) FileOutRst << LargeObjW[j] << "\t" << LargeObjH[j] << "\t" << ALargeObj[j] << "\t" << LargeObj_Value[j] <<  endl;
			}
			if (ProblemType==17){
				if(NDim==2) FileOutRst << LargeObjW[j] << "\t" << LargeObj_Value[j] <<  endl;
				if(NDim==3) FileOutRst << LargeObjW[j] << "\t" << LargeObjH[j] << "\t" << LargeObj_Value[j] <<  endl;
			}
		

		}

		BetaDist(n_ItemsDist);
		n_Items=Gen(alphaDist,betaDist,min_nItems,max_nItems);
		unsigned long Maximum_NPossibleItems;
		unsigned long auxMaxW=min_LargeObjW;
		if(NDim==3){
			for(j=0;j<n_LargeObj;j++){
				if(LargeObjW[j]>auxMaxW) auxMaxW=LargeObjW[j];
			}
			if(auxMaxW<max_ItemS) A=auxMaxW;
			else A=max_ItemS;
			Maximum_NPossibleItems = (A-min_ItemS+1)*(A-min_ItemS+1)*(max_ItemH-max_ItemH+1);
			if(n_Items>=Maximum_NPossibleItems)
			cout << endl << "**Warning**" << endl;
			cout << endl << " In instance "<< i+1 <<" the number of different item types generated was " << n_Items << " this value is not feasible given the range for the size of the item types!"  << endl;
			n_Items= (unsigned long) (Maximum_NPossibleItems-Maximum_NPossibleItems*0.15);
			cout << endl << " The number of different item types was changed to its maximum value " << n_Items << "."<< endl;
		}

		auxMaxW=min_LargeObjW;
		if(NDim==2){
			for(j=0;j<n_LargeObj;j++){
				if(LargeObjW[j]>auxMaxW) auxMaxW=LargeObjW[j];
			}

			if(auxMaxW<max_ItemS) A=auxMaxW;
			else A=max_ItemS;
			if (n_Items>((A-min_ItemS+1)*(max_ItemS-min_ItemS+1)-(max_ItemS-min_ItemS))){	
				cout << endl << "**Warning**" << endl;
				cout << endl << " In instance "<< i+1 <<" the number of different item types generated was " << n_Items << " this value is not feasible given the range for the size of the item types!"  << endl;
				n_Items=((A-min_ItemS+1)*(max_ItemS-min_ItemS+1));
				n_Items=(unsigned long) (n_Items-n_Items*0.15);
				cout << endl << " The number of different item types was changed to its maximum value " << n_Items << "."<< endl;
			}
		}
				
			
		FileOutRst << n_Items << endl;


		ItemL = new  unsigned long [n_Items];
		ItemW = new  unsigned long [n_Items];
		ItemH = new  unsigned long [n_Items];
		DItem_U = new  unsigned long [n_Items];

		int aux2;
		for(j=0; j<n_Items; j++){	
			aux=0;			
			do {
				k=0;
				itL=Gen(alpha_ItemL,beta_ItemL,min_ItemS,max_ItemS);
				itW=Gen(alpha_ItemW,beta_ItemW,min_ItemS,max_ItemS);
				if(NDim==3) itH=Gen(alpha_ItemH,beta_ItemH,min_ItemH,max_ItemH);

				//To forbid item repetition
				aux2=0;
				if(NDim==2){
					for(l=0; l<j; l++){
						if(ItemW[l]==itW && ItemH[l]==itH) aux2=1;
					}
				}
				if(NDim==3){
					for(l=0; l<j; l++){
						if(ItemW[l]==itW && ItemH[l]==itH && ItemH[l]==itH) aux2=1;
					}
				}
				if(aux2==0){
					do{					
						// Item must fit in at least one large object
						if(NDim==2){
							if(itW<=LargeObjW[k]){
								ItemL[j]=itL;
								ItemW[j]=itW;
								DItem_U[j] = Gen(alpha_DItemU,beta_DItemU,min_DItemU,max_DItemU);
								aux=1;
							}
						}
						if(NDim==3){
							if(itW<=LargeObjW[k] && itH<=LargeObjH[k]){
								ItemL[j]=itL;
								ItemW[j]=itW;
								ItemH[j]=itH;
								DItem_U[j] = Gen(alpha_DItemU,beta_DItemU,min_DItemU,max_DItemU);
								aux=1;
							}
						}

						k++;
					} while (k<n_LargeObj && aux==0);
				}
			} while (aux==0);	
			
		}
		
		for (j=0;j<n_Items;j++){
			if(NDim==2) FileOutRst << ItemL[j] << '\t' << ItemW[j] << '\t' << DItem_U[j] << endl;
			if(NDim==3) FileOutRst << ItemL[j] << '\t' << ItemW[j] << '\t' << ItemH[j] << '\t' << DItem_U[j] << endl;
		}

	}

	FileOutRst.close();
	return 0;


}
inline void TwoDProbGen::BetaDist(int DistType)
{
	if(DistType==1){
		alphaDist=1;
		betaDist=3;
	}
	if(DistType==2){
		alphaDist=2;
		betaDist=5;
	}
	if(DistType==3){
		alphaDist=2;
		betaDist=2;
	}
	if(DistType==4){
		alphaDist=0.5;
		betaDist=0.5;
	}
	if(DistType==5){
		alphaDist=1;
		betaDist=1;
	}
	if(DistType==6){
		alphaDist=5;
		betaDist=1;
	}
	if(DistType==7){
		alphaDist=5;
		betaDist=2;
	}
}
	

