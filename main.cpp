#include <iostream>
#include <string>
#include <cstdlib>
#include "classes.hpp"

using namespace std;

int main()
{
	sum_global=1;//GLOBAL VARIABLE THAT IS USED FOR THE ID NUMBER OF A SPECIFIC  OBJECT 
	Plane k;//CREATION OF THE PLANE 
	CleaningEmployee *CE=new CleaningEmployee("MARKOS");
	MaintenanceEmployee *ME=new MaintenanceEmployee("GIANNHS");
	SecurityEmployee *SE=new SecurityEmployee("KWSTAS");
	cout<<"\n\n\n";
	k.process(CE);//FUNCTION THAT RECEIVES A CleaningEmployee TO WORK ON THIS PLANE
	cout<<"\n";
	k.process(ME);//FUNCTION THAT RECEIVES A MaintenanceEmployee TO WORK ON THIS PLANE
	cout<<"\n";
	k.process(SE);//FUNCTION THAT RECEIVES A SecurityEmployee TO WORK ON THIS PLANE
	cout<<"----------------------------------------------"<<endl;
	k.ready_check();
	cout<<"----------------------------------------------"<<endl;
	cout<<"\n";
	
	k.toString().print();//PRINTING OF THE DESCRIPTION OF THE PLANE 

	CE->toString().print();//WE PRINT  THE DESCRIPTIONS OF THE EMPLOYEES 
	
	ME->toString().print();	
	
	SE->toString().print();
	cout<<"_____________________________________________________"<<endl;
	Plane * new_pl=clone_encrypt_and_print(k);
	cout<<"_____________________________________________________"<<endl;
	cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
	delete new_pl;
	//new_pl->toString().print();	
	cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
	
	cout<<"\n";
	
	delete CE;
	cout<<"\n";
	delete ME;
	cout<<"\n";
	delete SE;

	cout<<"\n\n\n\n\n\n\n";
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
