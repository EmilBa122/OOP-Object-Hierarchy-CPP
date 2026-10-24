#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

extern int sum_global;//GLOBAL VARIABLE THAT IS USED FOR THE ID NUMBER OF A SPECIFIC  OBJECT 
extern int global_sum_PassengerCompartment;//GLOBAL VARIABLE THAT HOLDS THE NUMBER OF "PASSENGER COMPARTMENTS" OF A PLANE 
extern int g;

///////////////////////////////////////////class/////////////////////////////////////////////////////
class SecurityEmployee;
class CleaningEmployee;
class MaintenanceEmployee;
class Plane;
class String;
class PassengerCompartment;
class PrivateCompartment;
class CargoBay;
class EquipmentCompartment;
class Employee;
class SecurityEmployee;
class Object{
	private:
		int ID;
	public:
		Object();//CONSTRUCTOR OF Object
		virtual ~Object();//DESTRUCTOR OF Object
		int equal(Object *Ob1,Object *Ob2);//FUNCTION THAT COMPARES IF TWO OBJECTS ARE THE SAME IN TERMS OF THE MEMBERS THAT DEFINE THEM 
		int identical(Object *Ob1,Object *Ob2);//FUNCTION THAT COMPARES IF TWO OBJECTS ARE THE SAME IN TERMS OF THE MEMORY THEY HAVE OCCUPIED
		virtual String toString();//FUNCTION THAT RETURNS THE DESCRIPTION OF AN OBJECT BY CONVERTING ALL OF ITS DATA MEMBERS INTO String FORM 
		int get_ID_Object();//FUNCTION THAT RETURNS THE ID OF AN OBJECT 
		void clone(Plane **);//FUNCTION THAT COPIES A PLANE 
		void set_ID(int i);
		
		
		virtual int get_sum_PassengerCompartment(){};//BECAUSE IN THE FUNCTION clone_encrypt_and_print I PASS A REFERENCE TO Object AND I NEED ACCESS TO THE CLASS
		virtual PassengerCompartment *get_PassengerCompartment_PassengerCompartment(){};//Plane THROUGH THE Object IN THE clone I HAVE DECLARED THESE FUNCTIONS AS virtual
		virtual PrivateCompartment * get_PrivateCompartment_Plane(){};//IN THE Object
		virtual CargoBay * get_CargoBay_PrivateCompartment(){};
		virtual EquipmentCompartment * get_EquipmentCompartment_PrivateCompartment() {};
		virtual EquipmentCompartment * get_EquipmentCompartmnet_CargoBay(){};
		virtual PassengerCompartment ** get_PassengerCompartment_Plane(){};
		virtual EquipmentCompartment * get_EC1(){};
		virtual EquipmentCompartment * get_EC2(){};
		virtual int get_sum(){};
		virtual String get_name_obj();
};

class String:public Object{
	private:
		string s;
	public:
		String(string str);//CONSTRUCTOR OF String THAT TAKES AS ARGUMENT A string 
		~String();//DESTRUCTOR OF String 
		void print();//FUNCTION THAT PRINTS THE String 
		int length();//FUNCTION THAT RETURNS THE LENGTH OF THE String	
		void clear();//FUNCTION THAT EMPTIES THE String
		void concat(String s2);//FUNCTION THAT CONCATENATES WITH ANOTHER String 
		int at(string key);//WE GET THE POSITION WHERE THE CHARACTER key IS LOCATED IN THE String 
		void updateAt(int pos,string info);//FUNCTION THAT CHANGES THE CHARACTER ACCORDING TO THE VALUE THAT info HAS AT THE POSITION pos OF A String 
		string get_string();//FUNCTION THAT RETURNS THE string OF THE CLASS String 
};

class PlaneCompoment:public Object{//CLASS THAT IS USED FOR THE "PLANE COMPONENT"
	public:
		PlaneCompoment();//CONSTRUCTOR
		~PlaneCompoment();//DESTRUCTOR
		virtual void ready_check()=0;//FUNCTION THAT PROVIDES THE ABILITY TO CONFIRM THE READINESS OF THE COMPARTMENT THAT IT MODELS
		virtual String toString()=0;//FUNCTION THAT RETURNS THE DESCRIPTION OF AN OBJECT BY CONVERTING ALL OF ITS DATA MEMBERS INTO String FORM 
		virtual void process(SecurityEmployee *SE){};//FUNCTION THAT RECEIVES A SecurityEmployee TO WORK IN A SPECIFIC COMPARTMENT
		virtual void process(MaintenanceEmployee *ME){};//FUNCTION THAT RECEIVES A MaintenanceEmployee TO WORK IN A SPECIFIC COMPARTMENT
		virtual void process(CleaningEmployee *CE){};//FUNCTION THAT RECEIVES A CleaningEmployee TO WORK IN A SPECIFIC COMPARTMENT
		virtual void process(CleaningEmployee *CE,PassengerCompartment **PC){};//FUNCTION THAT RECEIVES A CleaningEmployee TO WORK IN THE WHOLE SPACE OF THE PassengerCompartment OF THE PLANE 
		virtual void process(SecurityEmployee *SE,PassengerCompartment **PC){};//FUNCTION THAT RECEIVES A SecurityEmployee TO WORK IN THE WHOLE SPACE OF THE PassengerCompartment OF THE PLANE
};

class PassengerCompartment:public PlaneCompoment{//CLASS THAT IS USED FOR THE "PASSENGER COMPARTMENT"
	private:
		PassengerCompartment *PC;//THIS POINTER DECLARES THAT THE PASSENGER COMPARTMENT HAS SOME INNER "PASSENGER COMPARTMENT"
	public:
		PassengerCompartment(const int i);//CONSTRUCTOR THAT HAS AS ARGUMENT A VARIABLE THAT DECLARES THAT IF IT IS 1 THE PASSENGER COMPARTMENT HAS SOME INNER "PASSENGER COMPARTMENT" OTHERWISE IF IT IS 0 IT DOES NOT HAVE 
		~PassengerCompartment();//DESTRUCTOR
		void ready_check();//FUNCTION THAT IS USED FOR THE CONFIRMATION OF READINESS OF THE COMPARTMENT 	
		String toString();//FUNCTION THAT RETURNS THE DESCRIPTION OF THE COMPARTMENT BY CONVERTING ALL OF ITS DATA MEMBERS INTO String FORM
		int RAND();//FUNCTION THAT RETURNS 0 OR 1
		PassengerCompartment *get_PassengerCompartment_PassengerCompartment();//FUNCTION THAT RETURNS THE "PASSENGER COMPARTMENT"
		void process(CleaningEmployee *CE,PassengerCompartment **PC);//FUNCTION THAT RECEIVES A CleaningEmployee TO WORK IN THE WHOLE SPACE OF THE PassengerCompartment OF THE PLANE
		void process(SecurityEmployee *SE,PassengerCompartment **PC);//FUNCTION THAT RECEIVES A SecurityEmployee TO WORK IN THE WHOLE SPACE OF THE PassengerCompartment OF THE PLANE
		void clone(Object &OB);//FUNCTION THAT IS USED FOR THE COPY OF THE PassengerCompartment OF THE PLANE 		
};

class EquipmentCompartment:public Object{//CLASS THAT IS USED FOR THE "EQUIPMENT COMPARTMENT"
	public:
		EquipmentCompartment();//CONSTRUCTOR
		~EquipmentCompartment();//DESTRUCTOR
		String toString();//FUNCTION THAT RETURNS THE DESCRIPTION OF THE COMPARTMENT BY CONVERTING ALL OF ITS DATA MEMBERS INTO String FORM
		void clone(Object &OB);//FUNCTION THAT IS USED FOR THE COPY OF THE EquipmentCompartment OF THE PLANE 
};

class CargoBay:public Object{//CLASS THAT IS USED FOR THE "CARGO BAY"
	private:
		EquipmentCompartment *EC;//THIS POINTER DECLARES THAT EACH CARGO BAY CONTAINS AN EQUIPMENT COMPARTMENT 
	public:
		CargoBay();//CONSTRUCTOR
		~CargoBay();//DESTRUCTOR
		void process(SecurityEmployee *SE);//FUNCTION THAT RECEIVES A SecurityEmployee TO WORK IN THIS COMPARTMENT
		void process(MaintenanceEmployee *ME);//FUNCTION THAT RECEIVES A MaintenanceEmployee TO WORK IN THIS COMPARTMENT
		String toString();//FUNCTION THAT RETURNS THE DESCRIPTION OF THE COMPARTMENT BY CONVERTING ALL OF ITS DATA MEMBERS INTO String FORM
		EquipmentCompartment * get_EquipmentCompartmnet_CargoBay();//FUNCTION THAT RETURNS THE "EQUIPMENT COMPARTMENT" FROM THE CARGO BAY
		void clone(Object &OB);//FUNCTION THAT IS USED FOR THE COPY OF THE CargoBay OF THE PLANE 
};

class PrivateCompartment:public PlaneCompoment{//CLASS THAT IS USED FOR THE "RESTRICTED ACCESS COMPARTMENT"
	private://EACH RESTRICTED ACCESS COMPARTMENT HAS ONE CARGO BAY AND ONE EQUIPMENT COMPARTMENT
		CargoBay *CB;
		EquipmentCompartment *EC;
	public:
		PrivateCompartment();//CONSTRUCTOR 
		~PrivateCompartment();//DESTRUCTOR
		void ready_check();//FUNCTION THAT IS USED FOR THE CONFIRMATION OF READINESS OF THE COMPARTMENT 
		void process(SecurityEmployee *SE);////FUNCTION THAT RECEIVES A SecurityEmployee TO WORK IN THIS COMPARTMENT
		void process(MaintenanceEmployee *ME);//FUNCTION THAT RECEIVES A MaintenanceEmployee TO WORK IN THIS COMPARTMENT
		void process(CleaningEmployee *CE);//FUNCTION THAT RECEIVES A CleaningEmployee TO WORK IN THIS COMPARTMENT
		String toString();//FUNCTION THAT RETURNS THE DESCRIPTION OF THE COMPARTMENT BY CONVERTING ALL OF ITS DATA MEMBERS INTO String FORM
		CargoBay *get_CargoBay_PrivateCompartment();//FUNCTION THAT RETURNS THE CargoBay FROM THE RESTRICTED ACCESS COMPARTMENT
		EquipmentCompartment * get_EquipmentCompartment_PrivateCompartment();//FUNCTION THAT RETURNS THE "EQUIPMENT COMPARTMENT" FROM THE RESTRICTED ACCESS COMPARTMENT	
		void clone(Object &OB);//FUNCTION THAT IS USED FOR THE COPY OF THE PrivateCompartmnet OF THE PLANE 
};

class Employee:public Object{
	private:
		String name;//DECLARES THE NAME OF THE EMPLOYEE
	public:
		Employee();//CONSTRUCTOR
		~Employee();//DESTRUCTOR
		virtual void report(PassengerCompartment *PC){};//THE report FUNCTIONS ARE USED TO DECLARE THAT AN EMPLOYEE WORKED IN THE SPECIFIC COMPARTMENT
		virtual void report(PrivateCompartment *PRC){};
		virtual void report(CargoBay *CB){};
		virtual void report(EquipmentCompartment *EC){};
		virtual void workOn(PassengerCompartment **PC){};//THE workOn FUNCTIONS ASSIGN TO AN EMPLOYEE A COMPARTMENT OF THE PLANE TO WORK ON
		virtual void workOn(PrivateCompartment *PRC){};
		virtual void workOn(CargoBay *CB){};
		virtual void workOn(EquipmentCompartment *EC){};
		void set(const string s1);//FUNCTION THAT ASSIGNS TO name THE s1	
		String get();//FUNCTION THAT RETURNS THE name
};

class SecurityEmployee:public Employee{
	public:
		SecurityEmployee(const string s1);//CONSTRUCTOR THAT TAKES AS ARGUMENT A STRING THAT WILL BE ASSIGNED TO THE name OF Employee
		~SecurityEmployee();//DESTRUCTOR
		void report(PassengerCompartment *PC);//THE report FUNCTIONS ARE USED TO DECLARE THAT THE EMPLOYEE WORKED IN THE SPECIFIC COMPARTMENT
		void report(PrivateCompartment *PRC);
		void report(CargoBay *CB);
		void report(EquipmentCompartment *EC);
		void workOn(PassengerCompartment **PC);//THE workOn FUNCTIONS ASSIGN TO THE EMPLOYEE A COMPARTMENT OF THE PLANE TO WORK ON
		void workOn(PrivateCompartment *PRC);
		void workOn(CargoBay *CB);
		void workOn(EquipmentCompartment *EC);
		String toString();//FUNCTION THAT RETURNS THE DESCRIPTION OF THE Employee BY CONVERTING ALL OF ITS DATA MEMBERS INTO String FORM
};

class MaintenanceEmployee:public Employee{
	public:
		MaintenanceEmployee(const string s1);//CONSTRUCTOR THAT TAKES AS ARGUMENT A STRING THAT WILL BE ASSIGNED TO THE name OF Employee
		~MaintenanceEmployee();//DESTRUCTOR
		void report(EquipmentCompartment *EC);//THE report FUNCTIONS ARE USED TO DECLARE THAT THE EMPLOYEE WORKED IN THE SPECIFIC COMPARTMENT
		void report(CargoBay *CB);
		void workOn(EquipmentCompartment *EC);//THE workOn FUNCTIONS ASSIGN TO AN EMPLOYEE A COMPARTMENT OF THE PLANE TO WORK ON
		void workOn(CargoBay *CB); 
		String toString();//FUNCTION THAT RETURNS THE DESCRIPTION OF THE Employee BY CONVERTING ALL OF ITS DATA MEMBERS INTO String FORM
};

class CleaningEmployee:public Employee{
	public:
		CleaningEmployee(const string s1);//CONSTRUCTOR THAT TAKES AS ARGUMENT A STRING THAT WILL BE ASSIGNED TO THE name OF Employee
		~CleaningEmployee();//DESTRUCTOR
		void report(PassengerCompartment *PC);//THE report FUNCTIONS ARE USED TO DECLARE THAT THE EMPLOYEE WORKED IN THE SPECIFIC COMPARTMENT
		void report(CargoBay *CB);
		void workOn(PassengerCompartment **PC);//THE workOn FUNCTIONS ASSIGN TO AN EMPLOYEE A COMPARTMENT OF THE PLANE TO WORK ON
		void workOn(CargoBay *CB);
		String toString();//FUNCTION THAT RETURNS THE DESCRIPTION OF THE Employee BY CONVERTING ALL OF ITS DATA MEMBERS INTO String FORM
};

class Plane:public Object{
	private:
		String name;//DECLARES THE NAME OF THE PLANE
		int sum;//DECLARES THE NUMBER OF THE PASSENGERS
		PassengerCompartment **PC;//IT IS A DOUBLE POINTER THAT POINTS TO A TABLE THAT CONTAINS THE ADDRESSES OF THE PASSENGER COMPARTMENTS OF THE WHOLE PLANE 
		PrivateCompartment *PRC;//POINTS TO A RESTRICTED ACCESS COMPARTMENT
		int sum_PassengerCompartment;//DECLARES HOW MANY PassengerCompartment THE PLANE WILL HAVE
		EquipmentCompartment *EC1;//POINTS TO AN EQUIPMENT COMPARTMENT 
		EquipmentCompartment *EC2;//POINTS TO AN EQUIPMENT COMPARTMENT	
	public:
		Plane();//CONSTRUCTOR
		Plane(int copy);//CONSTRUCTOR THAT IS USED IN clone_encypt_and_print FOR THE CREATION OF A SIMPLE PLANE CLONE 
		~Plane();//DESTRUCTOR
		void process(CleaningEmployee *CE);//FUNCTION THAT RECEIVES A CleaningEmployee TO WORK ON THIS PLANE
		void process(MaintenanceEmployee *ME);//FUNCTION THAT RECEIVES A MaintenanceEmployee TO WORK ON THIS PLANE
		void process(SecurityEmployee *SE);//FUNCTION THAT RECEIVES A SecurityEmployee TO WORK ON THIS PLANE
		void ready_check();//FUNCTION THAT IS USED FOR THE CONFIRMATION OF READINESS OF THE PLANE
		String toString();//FUNCTION THAT RETURNS THE DESCRIPTION OF THE PLANE BY CONVERTING ALL OF ITS DATA MEMBERS INTO String FORM
		void function_rand();//FUNCTION THAT DECIDES THE NUMBER OF PASSENGERS AND THE NUMBER OF THE PASSENGER COMPARTMENT OF THE PLANE
		int get_sum_PassengerCompartment();//FUNCTION THAT RETURNS THE NUMBER OF THE PASSENGER COMPARTMENT OF THE PLANE 
		int get_sum();//FUNCTION THAT RETURNS THE NUMBER OF THE PASSENGERS
		String get_name_obj();//FUNCTION THAT RETURNS THE NAME OF THE PLANE
		PassengerCompartment ** get_PassengerCompartment_Plane();//FUNCTION THAT RETURNS THE DOUBLE POINTER PC THAT REFERS TO ALL THE PASSENGER COMPARTMENTS OF THE PLANE
		PrivateCompartment * get_PrivateCompartment_Plane();//FUNCTION THAT RETURNS THE RESTRICTED ACCESS COMPARTMENT OF THE PLANE 
		EquipmentCompartment *get_EC1();//FUNCTION THAT RETURNS THE CARGO BAY 
		EquipmentCompartment *get_EC2();//FUNCTION THAT RETURNS THE CARGO BAY
		void clone(Object &OB);//FUNCTION THAT IS USED FOR THE COPY OF THE PLANE 			
};

Plane * clone_encrypt_and_print(Object &OB);
int compare(String s1,String s2);//FUNCTION THAT COMPARES TWO String IF THEY ARE EQUAL
