# OOP Object Hierarchy CPP

## Assignment Description
Implementing in C++ a class hierarchy with Object as the root class using Object-Oriented Programming, i.e. using inheritance 
and abstract classes for a Plane, its Compartments and its Employees

## Usage Instructions for the program:

1.Open Linux terminal
2.Type `unzip askisi3.zip`
3.TYPE `make`
4.TYPE `./main`

## Program design idea:

### Global variables

The sum_global is used for the assignment of the value to the ID of an
object.The global_sum_PassengerCompartment holds the number of "Passenger
Compartments" of a plane,in this number it is excluded if the "Passenger
Compartment" has some inner "Passenger Compartment".

### Design of the plane

**A PLANE CONSISTS OF A NUMBER OF "PASSENGER COMPARTMENTS" THAT IS CHOSEN
RANDOMLY , EACH "PASSENGER COMPARTMENT" CAN HAVE AN INNER "PASSENGER
COMPARTMENT" THAT IS ALSO CHOSEN RANDOMLY.THE PLANE HAS A SET OF
PassengerCompartment AND ONE PrivateCompartment SPACE THESE SPACES CONSTITUTE
THE "PLANE COMPONENTS"(PlaneComponent).ALSO IT CONSISTS OF ONE CargoBay
SPACE(WHERE THIS SPACE CONTAINS ONE EquipmentCompartment SPACE) AND OF ONE
EquipmentCompartment SPACE THAT CONTRIBUTE TO THE CREATION OF THE
PrivateCompartment OF THE PLANE.FINALLY THE PLANE HAS TWO OTHER
EquipmentCompartment SPACES,THEREFORE IT HAS THREE EquipmentCompartment BUT ONE
IS USED FOR THE CREATION OF THE PrivateCompartment OF THE PLANE.**

### Class inheritance

The class Object is the base class of the program that is all the other classes
are subclasses of it.There is the class String.The class PlaneComponent is the
"plane component" and is an abstract base class,as "children" it has the
class PassengerCompartment and the class PrivateCompartment.The classes
EquipmentCompartment and CargoBay are subclasses of Object.There is the class
Employee and the classes SecurityEmployee,MaintenanceEmployee and the
CleaningEmployee that are subclasses of it.

### Private members of classes

The class Object has an int ID that is the ID of an object.The class String has
a variable string,the class PassengerCompartment has a pointer to
PassengerComprtment where this pointer declares that the PassengerCompartment
can have some inner space.The class CargoBay has a pointer that points to
EquipmentComprtment.The PrivateCompartment has two pointers that point to
CargoBay and EquipmntCompartmnt.The class Employee has a String name that holds
the name of the employee.The class Plane has a variable sum that holds the
number of passengers,a variable sum_PassengerCompartment that holds the number
of the "passenger compartments" of the plane, the String name holds the name
of the plane,it has a double pointer which points to a table that contains the
addresses of the PassengerCompartment of the plane,a pointer that points to the
PrivateCompartment of the plane and two pointers that point to the
EquipmentCompartment of the plane.

### Creation of some basic objects

**DURING THE CREATION OF A PLANE WE CALL THE FUNCTION fuction_rand THAT BELONGS
TO THE public PART OF THE CLASS Plane THAT DECIDES THE NUMBER OF THE PASSENGERS
AND THE NUMBER OF THE "PASSENGER COMPARTMENT" OF THE PLANE , INSIDE IT WE CALL
THE FUNCTION RAND THAT RETURNS RANDOMLY 0 OR 1.THE RAND BELONGS TO THE public
PART OF THE CLASS PassengerCompartment.IF THE VALUE IS 1 THE PLANE WILL HAVE 200
PASSENGERS AND 2 PassengerCompartment OTHERWISE IT WILL HAVE 400 PASSENGERS AND
4 PassengerCompartment.AND WE DO new FOR ALL THE POINTERS OF THE PLANE THAT
POINT TO VARIOUS PARTS OF IT .BEFORE THE CREATION OF A PassengerCompartment WE
CALL THE FUNCTION RAND IF THE VALUE THAT IT RETURNED IS 1 THIS SPACE WILL HAVE
AN INNER PassengerCompartment SO WE CREATE THIS SPACE OTHERWISE IF THE VALUE OF
RAND IS 0 THE PassengerCompartment WILL NOT HAVE AN INNER SPACE.DURING THE
CREATION OF THE PrivateCompartment OF THE PLANE WE CREATE THE CargoBay(WHERE
DURING THE CREATION OF THE CargoBay WE CREATE AN EquipmentCompartment) AND THE
EquipmentCompartment THAT ARE ITS MEMBERS.DURING THE CREATION OF A
CleaningEmployee WE ASSIGN TO THE MEMBER name THE s1 THAT IS THE NAME OF THE
Employee(CORRESPONDING PROCEDURE ALSO FOR THE MaintenanceEmployee AND FOR THE
SecurityEmployee).DURING THE CREATION OF AN Object WE ASSIGN TO THE ID THE VALUE
OF sum_global WHERE WE INCREASE THE LAST ONE BY ONE.**

### Process,ready_check,workOn,report

In the program the different process functions that exist are distinguished by
the object that calls them as well as by the arguments that they take so that
each time the appropriate one is called that is e.g. we have PRC->process(SE)
that refers to the PrivateCompartment for the SecurityEmployee and the
CB->process(ME) that refers to the CargoBay for the MaintenanceEmployee.The same
also applies to the functions ready_check,workOn and report.

### Clone_encrypt_and_print

In the function we call a second constructor of Plane that is used only for the
creation of simple plane clones.As we have simply created the plane we call the
function clone of Plane which after it has created a part of the plane calls the
appropriate clone to copy this part from the initial plane and this is done for
all the parts of the plane.

In the public part of Object the virtual functions exist because I need access
to the class Plane through Object in clone,I have declared these functions as
virtual in Object.

**EVERYTHING HAS BEEN IMPLEMENTED EXCEPT THE FUNCTION clone_encrypt_and_print
WHICH ONLY CREATES A COPY OF THE OBJECT AND CHECKS THEM AGAINST EACH OTHER.**
