#include <iostream>
#include <string>
#include <cstdlib>
#include "classes.hpp"

using namespace std;


int sum_global;//GLOBAL VARIABLE THAT IS USED FOR THE ID NUMBER OF A SPECIFIC  OBJECT
int global_sum_PassengerCompartment;//GLOBAL VARIABLE THAT HOLDS THE NUMBER OF "PASSENGER COMPARTMENTS" OF A PLANE 
class String;
int g;

////////////////////////////functions of gets//////////////////////////////////////////////////////
string String::get_string()
{
	return s;
}

int Plane::get_sum()
{
	return sum;
}

String Plane::get_name_obj()
{
	return name;
}

EquipmentCompartment *Plane::get_EC1()
{
	return EC1;
}

EquipmentCompartment *Plane::get_EC2()
{
	return EC2;
}

PassengerCompartment ** Plane::get_PassengerCompartment_Plane()
{
	return this->PC;
}

PrivateCompartment *Plane::get_PrivateCompartment_Plane()
{
	return PRC;
}

CargoBay *PrivateCompartment::get_CargoBay_PrivateCompartment()
{
	return CB;
}

EquipmentCompartment *PrivateCompartment::get_EquipmentCompartment_PrivateCompartment()
{
	return EC;
}

EquipmentCompartment *CargoBay::get_EquipmentCompartmnet_CargoBay()
{
	return EC;
}

PassengerCompartment *PassengerCompartment::get_PassengerCompartment_PassengerCompartment()
{
	return PC;
}

String Employee::get()
{
	return name;
}

int Plane::get_sum_PassengerCompartment()
{
	return sum_PassengerCompartment;
}
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////functions of Object and String/////////////////////////
Object::Object()//CONSTRUCTOR
{
	ID=sum_global++;//THE ID OF AN OBJECT WILL BE EQUAL TO THE NUMBER sum_global
//	cout<<ID<<endl;
	cout<<"Object just created!"<<endl;
}

Object::~Object()//DESTRUCTOR
{
	cout<<"Object to be destroyed!"<<endl;
}

String Object::get_name_obj(){}

int Object::get_ID_Object()//FUNCTION THAT RETURNS THE ID OF AN OBJECT 
{
	return ID;
}

int Object::identical(Object *Ob1,Object *Ob2)//FUNCTION THAT COMPARES IF TWO OBJECTS ARE THE SAME IN TERMS OF THE MEMORY THEY HAVE OCCUPIED
{
	if(Ob1==Ob2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

String Object::toString()//FUNCTION THAT RETURNS THE DESCRIPTION OF AN OBJECT BY CONVERTING ALL OF ITS DATA MEMBERS INTO String FORM
{
	String result("Odject ID="+to_string(ID));
	return result;
}

String::String(string str)//CONSTRUCTOR OF String THAT TAKES AS ARGUMENT A string AND ASSIGNS IT TO THE MEMBER s OF THE CLASS 
{
	s=str;
	cout<<"String just created!"<<endl;
}

String::~String()//DESTRUCTOR OF String 
{
	cout<<"String to be destroyed!"<<endl;
}

void String::print()
{
	cout<<"\n\n";
	cout<<s<<endl;
	cout<<"\n\n";
}

int String::length()
{
	return s.length();
}

void String::clear()
{
	s.erase(0);
}

void String::concat(String s2)
{
	s.append(s2.s);
}

int String::at(string key)
{
	int pos;
	pos=s.find(key);
	if(pos==-1)
	{
		cout<<"Character not found"<<endl;
	}
	return pos;
}

void String::updateAt(int pos,string info)
{
	s.erase(pos,1);
	s.insert(pos,info);
}
//////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////functions of PlaneCompoment///////////////////////////////////////////
PlaneCompoment::PlaneCompoment()//CONSTRUCTOR
{
	cout<<"PlaneCompoment just created!"<<endl;
}

PlaneCompoment::~PlaneCompoment()//DESTRUCTOR
{
	cout<<"PlaneCompoment to be destroyed!"<<endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////functions of PassengerCompartment//////////////////////////////
PassengerCompartment::PassengerCompartment(const int i)
{//CONSTRUCTOR THAT HAS AS ARGUMENT A VARIABLE THAT DECLARES THAT IF IT IS 1 THE PASSENGER COMPARTMENT HAS SOME INNER "PASSENGER COMPARTMENT" OTHERWISE IF IT IS 0 IT DOES NOT HAVE 
	if(i==1)
	{
		PC=new PassengerCompartment(0);
	}
	else
	{
		PC=NULL;
	}
	cout<<"PassengerCompartment just created!"<<endl;
}

PassengerCompartment::~PassengerCompartment()//DESTRUCTOR
{
	if(PC!=NULL)
	{
		delete PC;
	}
	cout<<"PassengerCompartment to be destroyed!"<<endl;
}

int RAND()//FUNCTION THAT RETURNS 0 OR 1
{
	int x=rand()%2;
	return x;
}
////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////functions of EquipmentCompartmnet//////////////////////////
EquipmentCompartment::EquipmentCompartment()//CONSTRUCTOR
{
	cout<<"EquipmentCompartment just created!"<<endl;
}

EquipmentCompartment::~EquipmentCompartment()//DESTRUCTOR
{
	cout<<"EquipmentCompartment to be destroyed!"<<endl;
}
////////////////////////////////////////////////////////////////////////////////////
/////////////////////////functions of CargoBay/////////////////////////////////////
CargoBay::CargoBay()//CONSTRUCTOR OF CargoBay AND WE MAKE THE POINTER EC POINT TO AN EQUIPMENT COMPARTMENT 
{
	cout<<"CargoBay just created!"<<endl;
	EC=new EquipmentCompartment;
}

CargoBay::~CargoBay()//DESTRUCTOR
{
	cout<<"CargoBay to be destroyed!"<<endl;
	delete EC;
}
///////////////////////////////////////////////////////////////////////////
////////////////////////functions of PrivateCompartment/////////////////////
PrivateCompartment::PrivateCompartment()//CONSTRUCTOR
{										//FOR EACH PrivateCompartmnet TO BE DEFINED IT MUST CONTAIN ONE CargoBay AND ONE EquipmentCompartment SO WE MAKE THE
	cout<<"PrivateCompartement just created!"<<endl;//POINTERS CB AND EC POINT TO THE CORRESPONDING COMPARTMENTS 
	CB=new CargoBay;
	EC=new EquipmentCompartment;
}

PrivateCompartment::~PrivateCompartment()//DESTRUCTOR
{
	cout<<"PrivateCompartment to be destroyed!"<<endl;
	delete CB;
	delete EC;
}
//////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////function of Employee////////////////////////////////////////
Employee::Employee():name(" ")//CONSTRUCTOR
{
	cout<<"Employee just created!"<<endl;
}

Employee::~Employee()//DESTRUCTOR
{
	cout<<"Employee to be  destroyed!"<<endl;
}

void Employee::set(const string s1)//FUNCTION THAT ASSIGNS TO name THE s1
{
	this->name=s1;
}
///////////////////////////////////////////////////////////////////
////////////////////////////functions of SecurityEmployee//////////
void SecurityEmployee::workOn(PassengerCompartment **PC)//THE FUNCTION ASSIGNS THE EMPLOYEE TO WORK ON EACH PART OF THE PASSENGER COMPARTMENT OF THE PLANE 
{	
	for(int i=0; i<global_sum_PassengerCompartment; i++)
	{
		report(PC[i]);
		if(PC[i]->get_PassengerCompartment_PassengerCompartment())//IF THE SPECIFIC PASSENGER COMPARTMENT HAS AN INNER PASSENGER COMPARTMENT  
		{
			report(PC[i]->get_PassengerCompartment_PassengerCompartment());
		}
	}
}

void SecurityEmployee::workOn(PrivateCompartment *PRC)//THE FUNCTION ASSIGNS THE EMPLOYEE TO WORK IN THE RESTRICTED ACCESS COMPARTMENT
{
	report(PRC);
}

void SecurityEmployee::workOn(CargoBay *CB)//THE FUNCTION ASSIGNS THE EMPLOYEE TO WORK IN THE CARGO BAY
{
	report(CB);
}

void SecurityEmployee::workOn(EquipmentCompartment *EC)//THE FUNCTION ASSIGNS THE EMPLOYEE TO WORK IN THE EQUIPMENT COMPARTMENT
{
	report(EC);
}

void SecurityEmployee::report(PassengerCompartment *PC)
{
	cout<<"Passenger Compartment OK"<<endl;
}
												//THE report FUNCTIONS ARE USED TO DECLARE THAT THE EMPLOYEE WORKED IN THE SPECIFIC COMPARTMENT	
void SecurityEmployee::report(PrivateCompartment *PRC)
{
	cout<<"Private Cpmpartment OK"<<endl;
}

void SecurityEmployee::report(CargoBay *CB)
{
	cout<<"Cargo Bay OK"<<endl;
}

void SecurityEmployee::report(EquipmentCompartment *EC)
{
	cout<<"Equipment Compartment OK"<<endl;
}

SecurityEmployee::SecurityEmployee(const string s1)//CONSTRUCTOR THAT TAKES AS ARGUMENT A STRING THAT WILL BE ASSIGNED TO THE name OF Employee
{
	this->set(s1);
	cout<<"SecurityEmployee just created!"<<endl;
}

SecurityEmployee::~SecurityEmployee()//DESTRUCTOR
{
	cout<<"SecurityEmployee to be destroyed!"<<endl;
}
///////////////////////////////////////////////////////////////////
/////////////////////////////functions of MaintenanceEmployee//////
void MaintenanceEmployee::workOn(EquipmentCompartment *EC)
{
	report(EC);
}
											//THE workOn FUNCTIONS ASSIGN TO THE EMPLOYEE A COMPARTMENT OF THE PLANE TO WORK ON
void MaintenanceEmployee::workOn(CargoBay *CB)
{
	report(CB);
}

MaintenanceEmployee::MaintenanceEmployee(const string s1)//CONSTRUCTOR THAT TAKES AS ARGUMENT A STRING THAT WILL BE ASSIGNED TO THE name OF Employee
{
	this->set(s1);
	cout<<"MaintenanceEmployee just created!"<<endl;
}

MaintenanceEmployee::~MaintenanceEmployee()//DESTRUCTOR
{
	cout<<"MaintenceEmployee to be destroyed!"<<endl;
}

void MaintenanceEmployee::report(EquipmentCompartment *EC)
{
	cout<<"Equipment Compartment OK"<<endl;
}
												//THE report FUNCTIONS ARE USED TO DECLARE THAT THE EMPLOYEE WORKED IN THE SPECIFIC COMPARTMENT
void MaintenanceEmployee::report(CargoBay *CB)
{
	cout<<"Cargo Bay OK"<<endl;
}
//////////////////////////////////////////////////////////////////////////////
////////////////////functions of CleaningEmployee/////////////////////////
void CleaningEmployee::workOn(PassengerCompartment **PC)//THE FUNCTION ASSIGNS THE EMPLOYEE TO WORK ON EACH PART OF THE PASSENGER COMPARTMENT OF THE PLANE
{
	for(int i=0; i<global_sum_PassengerCompartment; i++)
	{
		report(PC[i]);
		if(PC[i]->get_PassengerCompartment_PassengerCompartment())//IF THE SPECIFIC PASSENGER COMPARTMENT HAS AN INNER PASSENGER COMPARTMENT 
		{
			report(PC[i]->get_PassengerCompartment_PassengerCompartment());
		}
	}
}

void CleaningEmployee::workOn(CargoBay *CB)//THE FUNCTION ASSIGNS THE EMPLOYEE TO WORK IN THE CARGO BAY
{
	report(CB);
}

CleaningEmployee::CleaningEmployee(const string s1)//CONSTRUCTOR THAT TAKES AS ARGUMENT A STRING THAT WILL BE ASSIGNED TO THE name OF Employee
{
	this->set(s1);
	cout<<"CleaningEmployee just created!"<<endl;
}

CleaningEmployee::~CleaningEmployee()//DESTRUCTOR
{
	cout<<"CleaningEmployee to be destroyed!"<<endl;
}

void CleaningEmployee::report(PassengerCompartment *PC)
{
	cout<<"Passenger Compartment OK"<<endl;
}
											//THE report FUNCTIONS ARE USED TO DECLARE THAT THE EMPLOYEE WORKED IN THE SPECIFIC COMPARTMENT
void CleaningEmployee::report(CargoBay *CB)
{
	cout<<"Cargo Bay OK"<<endl;
}
////////////////////////////////////////////////////////////////////////////
///////////////////////PROCESS FUNCTIONS///////////////////////////////////
void PrivateCompartment::process(SecurityEmployee *SE)
{
	SE->workOn(CB);
	SE->workOn(EC);
	CB->process(SE);
}
								//EACH PrivateCompartment CONSISTS OF A CargoBay THAT CONTAINS AN EquipmentCompartment AND OF AN EquipmentCompartmnet
void PrivateCompartment::process(MaintenanceEmployee *ME)//SO WE ASSIGN THE EMPLOYEE TO WORK ON THE CargoBay AND ON THE EquipmentCompartmnet AS WELL AS 
{														//ON THE EquipmentCompartmnet OF THE CargoBay
	ME->workOn(CB);
	ME->workOn(EC);
	CB->process(ME);
}

void PrivateCompartment::process(CleaningEmployee *CE)
{
	CE->workOn(CB);
}

void CargoBay::process(SecurityEmployee *SE)
{
	SE->workOn(EC);
}

void CargoBay::process(MaintenanceEmployee *ME)
{
	ME->workOn(EC);
}

void PassengerCompartment::process(CleaningEmployee *CE,PassengerCompartment **PC)
{
	CE->workOn(PC);
}

void PassengerCompartment::process(SecurityEmployee *SE,PassengerCompartment **PC)
{
	SE->workOn(PC);
}

void Plane::process(CleaningEmployee *CE)//WE ASSIGN THE EMPLOYEE TO WORK ON THE WHOLE PassengerCompartmnet AND ON THE  PrivateCompartment OF THE PLANE 
{
	(**PC).process(CE,PC);
	//CE->workOn(PC);//
	PRC->process(CE);
}

void Plane::process(MaintenanceEmployee *ME)//WE ASSIGN THE EMPLOYEE TO WORK ON THE EquipmentCompartments AND ON THE PrivateCompartment OF THE PLANE 
{
	ME->workOn(EC1);
	ME->workOn(EC2);
	PRC->process(ME);
}

void Plane::process(SecurityEmployee *SE)//WE ASSIGN THE EMPLOYEE TO WORK ON THE WHOLE PassengerCompartmnet ON THE EquipmentCompartments AND ON THE PrivateCompartment
{										//OF THE PLANE 
	//SE->workOn(PC);//
	(**PC).process(SE,PC);
	SE->workOn(EC1);
	SE->workOn(EC2);
	PRC->process(SE);
}
/////////////////////////////////////////////////////////////
/////////////////Plane functions////////////////////////////
void Plane::function_rand()//FUNCTION THAT DECIDES THE NUMBER OF PASSENGERS AND THE NUMBER OF THE PASSENGER COMPARTMENT OF THE PLANE
{
	int x=RAND();//FUNCTION THAT RETURNS 0 OR 1
	if(x==1)//IF THE VALUE IS 1 WE DECIDE THAT THE PLANE WILL HAVE 200 PASSENGERS AND 2 PASSENGER COMPARTMENTS WITHOUT KNOWING IF EACH COMPARTMENT WILL HAVE AN 
	{			//INNER PASSENGER COMPARTMENT
		sum=200;
		sum_PassengerCompartment=2;
	}
	else//OTHERWISE IT WILL HAVE 400 PASSENGERS AND 4 PASSENGER COMPARTMENTS 
	{
		sum=400;
		sum_PassengerCompartment=4;
	}
	global_sum_PassengerCompartment=sum_PassengerCompartment;
}

Plane::Plane():name("PLANE2000")//WE INITIALIZE THE NAME OF THE PLANE 
{
	cout<<"Plane just created!"<<endl;
	PRC=new PrivateCompartment;
	EC1=new	EquipmentCompartment;//WE CREATE THE CORRESPONDING COMPARTMENTS 
	EC2=new EquipmentCompartment;
	PC=new PassengerCompartment*[get_sum_PassengerCompartment()];
	int x;
	function_rand();
	for(int i=0; i<get_sum_PassengerCompartment(); i++)
	{
		x=RAND();//HERE WE DECIDE IF A PASSENGER COMPARTMENT WILL HAVE AN INNER PASSENGER COMPARTMENT DEPENDING ON THE VALUE OF x IF IT IS 1 IT MEANS YES OTHERWISE IT MEANS NO	
//		cout<<"x is "<<x<<endl;
		PC[i]=new PassengerCompartment(x);
	}
}

Plane::~Plane()//DESTRUCTOR
{
	cout<<"Plane to be destroyed!"<<endl;
	delete PRC;
	delete EC1;
	delete EC2;
	cout<<"\n";
	for(int i=0; i<get_sum_PassengerCompartment(); i++)
	{
		delete PC[i];
		cout<<"\n";
	}
	delete []PC;
}
///////////////////////////////////////////////
//////////////////TOSTRING FUCTIONS///////////
String EquipmentCompartment::toString()
{
	String result(to_string(get_ID_Object()));
	return result;	
}

String CargoBay::toString()//RETURNS THE DESCRIPTION OF THE CargoBay WHERE EACH GargoBay HAS AS A MEMBER AN EquipmentCompartment
{
	String result(",CargoBay ID="+to_string(get_ID_Object()));
	String space(" ");
	result.concat(space);
	String s1(",EquipmentCompartment inside in CargoBay ID=");
	result.concat(s1);
	result.concat(EC->toString());
	return result;
}

String PassengerCompartment::toString()
{
	String result(",PassengerCompartmnet ID="+to_string(get_ID_Object()));
	if(PC)//IF THE PassengerCompartment HAS AN INNER PassengerCompartment IT WILL CALL ITSELF TO COMPLETE ITS DESCRIPTION 
	{
		result.concat(PC->toString());
	}
	return result;
}

String CleaningEmployee::toString()
{
	String result("Employee with name:");
	result.concat(this->get());
	result.concat(" is CleaningEmployee and has ID="+to_string(get_ID_Object()));
	return result;
}
String MaintenanceEmployee::toString()
{
	String result("Employee with name:");
	result.concat(this->get());
	result.concat(" is MaintenanceEmployee and has ID="+to_string(get_ID_Object()));
	return result;
}
String SecurityEmployee::toString()
{
	String result("Employee with name:");
	result.concat(this->get());
	result.concat(" is SecurityEmployee and has ID="+to_string(get_ID_Object()));
	return result;
}
String PrivateCompartment::toString()//RETURNS THE DESCRIPTION OF THE PrivateCompartment WHERE EACH SUCH COMPARTMENT CONSISTS OF ONE CargoBay AND ONE EquipmentCompartment
{
	String result(CB->toString());//THE result WILL HAVE THE DESCRIPTION OF THE CargoBay OF THE PrivateCompartment 
	String s1(" ,EquipmentCompartment ID=");
	result.concat(s1);
	result.concat(EC->toString());//AND WE WILL CONCATENATE IT WITH THE DESCRIPTION EquipmentCompartment OF THE PrivateCompartment
	return result;
}
String Plane::toString()//RETURNS THE DESCRIPTION OF THE COMPARTMENT FROM ALL THE MEMBERS THAT COMPOSE IT 
{
	String result("Plane, ID="+to_string(get_ID_Object()));
	String space(" ");
	result.concat(space);
	String s0(" ,name of plane = ");
	result.concat(s0);
	result.concat(name);
	String s_("  ,sum_PassengerCompartment is "+to_string(sum_PassengerCompartment));
	result.concat(s_);
	result.concat(space);
	result.concat(",sum="+to_string(sum));
	result.concat(space);
	result.concat(PRC->toString());
	result.concat(space);
	String s1(",EquipmentCompartmnet inside in Plane ID=");
	result.concat(s1);
	result.concat(EC1->toString());
	result.concat(space);
	result.concat(s1);
	result.concat(EC2->toString());
	for(int i=0; i<get_sum_PassengerCompartment(); i++)
	{
		result.concat(PC[i]->toString());
	}
	return result;	
}
//////////////////////////////////////////////////////////////////////////////
///////////////////////////READY_CHECK FUNCTION////////////////////////////////
void PassengerCompartment::ready_check()
{
	toString().print();
	if(g+1==global_sum_PassengerCompartment)
	{
		cout<<"PassengerCompartment OK!"<<endl;
	}
}
void PrivateCompartment::ready_check()
{
	toString().print();
	cout<<"PrivateCompartment OK!"<<endl;
}
void Plane::ready_check()//WE DISPLAY ALL THE PARTS OF THE PLANE 
{
	PRC->ready_check();
	String result("EquipmentCompartmnet inside in Plane ID=");
	result.concat(EC1->toString());
	String s1(" ,EquipmentCompartmnet inside in Plane ID=");
	result.concat(s1);
	result.concat(EC2->toString());
	result.print();
	for(int i=0; i<get_sum_PassengerCompartment(); i++)//FOR EACH PASSENGER COMPARTMENT ITS DESCRIPTION IS DISPLAYED AND THE GLOBAL VARIABLE g IS USED SO THAT WHEN WE ARE
	{													//IN THE LAST  PASSENGER COMPARTMENT THE MESSAGE "PassengerCompartment OK!" IS ALSO PRINTED
		g=i;
		PC[i]->ready_check();
	}
	g=0;
	cout<<"Plane ready to take off!"<<endl;
}
///////////////////////////////////////////////////////////////
/////////////////////CLONE AREA///////////////////////////////
Plane::Plane(int copy):name(" ")//CONSTRUCTOR THAT IS USED IN clone_encypt_and_print FOR THE CREATION OF A SIMPLE PLANE CLONE 
{
	this->sum = -1;
	this->PC = NULL;
	this->PRC = NULL;
	this->sum_PassengerCompartment = -1;
	this->EC1 = NULL;
	this-> EC2 = NULL;
}

void PrivateCompartment::clone(Object &OB)//COPY OF THE PrivateCompartment OF THE PLANE 
{
	CargoBay *OB_CB=OB.get_CargoBay_PrivateCompartment();//THE OB_CB POINTS TO THE CargoBay OF THE INITIAL PLANE 
	this->CB->clone(*OB_CB);//ITS COPY IS MADE 
	EquipmentCompartment *OB_EC=OB.get_EquipmentCompartment_PrivateCompartment();//THE OB_EC POINTS TO THE EquipmentCompartment THAT IS THE MEMBER OF THE PrivateCompartmnet OF THE PLANE  
	this->EC->clone(*OB_EC);//THE COPY IS PERFORMED
}

Plane *clone_encrypt_and_print(Object &OB)
{
	Plane *new_plane=new Plane(1);//CREATION OF THE PLANE CLONE 
	new_plane->clone(OB);//THE PROCEDURE IS PERFORMED 
	new_plane->toString().print();//WE PRINT THE RESULT 
	if(new_plane->equal(new_plane,&OB))
	{
		cout<<"EQUAL!!!!!"<<endl;
	}
	else
	{
		cout<<"NOT EQUAL!!!!!!"<<endl;
	}
	if(new_plane->identical(new_plane, &OB))
	{
		cout<<"IDENTICAL!!!!!!!"<<endl;
	}
	else
	{
		cout<<"NOT IDENTICAL!!!!!"<<endl;
	}
	return new_plane;
}

void Object::set_ID(int i)
{
	ID=i;
}

void Plane::clone(Object &OB)//COPY OF THE PLANE 
{
	this->set_ID(OB.get_ID_Object());
	this->sum=OB.get_sum();
	this->name=OB.get_name_obj();//WE COPY THE NAME OF THE PLANE 
	this->sum_PassengerCompartment=OB.get_sum_PassengerCompartment();
	PassengerCompartment ** OB_pass=OB.get_PassengerCompartment_Plane();//THE OB_pass POINTS TO THE TABLE THAT CONTAINS THE ADDRESSES OF THE PASSENGER COMPARTMENTS OF THE WHOLE PLANE
	this->PC=new PassengerCompartment * [OB.get_sum_PassengerCompartment()];
	for(int i=0; i<OB.get_sum_PassengerCompartment(); i++)//FOR EACH PASSENGER COMPARTMENT OF THE INITIAL PLANE A COPY IS MADE 
	{													
		PC[i]=new PassengerCompartment(0);//CREATION OF A SIMPLE PASSENGER COMPARTMENT
		PC[i]->clone(*(OB_pass[i]));//AND ITS COPY 
	}
	cout<<"\n\n";
	PrivateCompartment *OB_PRC=OB.get_PrivateCompartment_Plane();//THE OB_PRC POINTS TO THE PrivateCompartment OF THE INITIAL PLANE 
	this->PRC=new PrivateCompartment();//CREATION OF THIS COMPARTMENT 
	this->PRC->clone(*OB_PRC);//AND COPY OF THIS COMPARTMENT FROM THE INITIAL PLANE 
	cout<<"\n\n";
	EquipmentCompartment *OB_EC1=OB.get_EC1();//THE OB_EC1 POINTS TO THE  FIRST EquipmentCompartment OF THE PLANE 
	EquipmentCompartment *OB_EC2=OB.get_EC2();//THE OB_EC2 POINTS TO THE SECOND EquipmentCompartment OF THE PLANE 
	this->EC1=new EquipmentCompartment();//CREATION OF THE COMPARTMENTS 
	this->EC2=new EquipmentCompartment();
	this->EC1->clone(*OB_EC1);//AND THEIR COPY 
	this->EC2->clone(*OB_EC2);
	cout<<"\n\n\n\n\n\n\n";
}

void PassengerCompartment::clone(Object &OB)//COPY OF THE PASSENGER COMPARTMENT OF THE PLANE 
{
	this->set_ID(OB.get_ID_Object());
	PassengerCompartment *OB_PC=OB.get_PassengerCompartment_PassengerCompartment();//THE OB_PC WILL TELL US IF THE INITIAL PASSENGER COMPARTMENT HAS AN INNER PASSENGER COMPARTMENT
	if(OB_PC!=NULL)																	//AND IF IT HAS ITS COPY IS MADE 
	{
		this->PC=new PassengerCompartment(0);//CREATION OF A SIMPLE PASSENGER COMPARTMENT
		this->PC->clone(*OB_PC);
	}
}

void CargoBay::clone(Object &OB)//COPY OF THE GargoBay SPACE OF THE PLANE 
{
	this->set_ID(OB.get_ID_Object());
	EquipmentCompartment *OB_CB=OB.get_EquipmentCompartmnet_CargoBay();//THE OB_CB WILL POINT TO THE EquipmentCompartment THAT IS A MEMBER OF THE CargoBay OF THE PLANE 
	this->EC->clone(*OB_CB);//THE COPY IS MADE
}

void EquipmentCompartment::clone(Object &OB)//COPY OF THE Equipment Compartment SPACE OF THE PLANE 
{
	this->set_ID(OB.get_ID_Object());
}
////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////EQUAL AREA///////////////////////////////////////////////////
int compare(String s1,String s2)//FUNCTION THAT COMPARES TWO String IF THEY ARE EQUAL 
{
	if(s1.get_string()==s2.get_string())
	{
		return 1;
	}
	return 0;
}


int Object::equal(Object *Ob1,Object *Ob2)//FUNCTION THAT COMPARES IF TWO OBJECTS ARE THE SAME IN TERMS OF THE MEMBERS THAT DEFINE THEM
{
	
	if(compare(Ob1->get_name_obj(),Ob2->get_name_obj()))
	{
		if(Ob1->get_ID_Object()==Ob2->get_ID_Object())//COMPARES IF THE IDs OF THE OBJECTS ARE THE SAME 
		{
	
			if(Ob1->get_sum()==Ob2->get_sum())
			{
				if(Ob1->get_sum_PassengerCompartment()==Ob2->get_sum_PassengerCompartment())
				{
					if(Ob1->get_EC1()->get_ID_Object()==Ob2->get_EC1()->get_ID_Object())
					{
						if(Ob1->get_EC2()->get_ID_Object()==Ob2->get_EC2()->get_ID_Object())
						{
							if(Ob1->get_PrivateCompartment_Plane()->get_CargoBay_PrivateCompartment()->get_ID_Object()==Ob2->get_PrivateCompartment_Plane()->get_CargoBay_PrivateCompartment()->get_ID_Object())
							{
								if(Ob1->get_PrivateCompartment_Plane()->get_EquipmentCompartment_PrivateCompartment()->get_ID_Object()==Ob2->get_PrivateCompartment_Plane()->get_EquipmentCompartment_PrivateCompartment()->get_ID_Object())
								{
									PassengerCompartment ** Ob_1 = Ob1->get_PassengerCompartment_Plane();//WE COMPARE IF THE TWO OBJECTS ARE THE SAME FOR EACH
									PassengerCompartment ** Ob_2 = Ob2->get_PassengerCompartment_Plane();//PASSENGER COMPARTMENT AND WE SEE AFTER IF THEY ALSO HAVE
									for(int i=0; i<Ob1->get_sum_PassengerCompartment(); i++)			//SOME INNER COMPARTMENT AND IF YES  THEY ARE COMPARED 
									{
										if(Ob_1[i]->get_ID_Object()==Ob_2[i]->get_ID_Object())
										{
											if(Ob_1[i]->get_PassengerCompartment_PassengerCompartment())
											{
												PassengerCompartment *Ob1_PC_PC = Ob_1[i]->get_PassengerCompartment_PassengerCompartment();
												PassengerCompartment *Ob2_PC_PC = Ob_2[i]->get_PassengerCompartment_PassengerCompartment();
												if(Ob1_PC_PC->get_ID_Object()==Ob2_PC_PC->get_ID_Object())
												{
													
												}
												else
												{
													return 0;
												}
											}
										}
										else
										{
											return 0;
										}
									}
								}
								else
								{
									return 0;
								}
							}
							else
							{
								return 0;
							}
						}
						else
						{
					  		return 0;
						}
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			else 
			{
				return 0;
			}
		}
		else 
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
	return 1;
		
}
