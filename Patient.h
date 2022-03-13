/*
 * Patient.h
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author: Mohammad Saghafian
 * Date: 22/January/2022
 * Modified: 1/February/2022
 */
#pragma once

// You can add #include statements if you wish.
#include <string>
using namespace std;
class Patient {
	
private:
    string name;        // name
    string address;     // address
    string phone;       // phone
    string email;       // email
    string careCard;    // carecard

public:

/* 
 * You can add more private methods to this class, 
 * but you cannot remove the methods below 
 * nor can you change their prototype.
 * Bottom line: you cannot change the public interface of this class.
 * 
 */

	// Default Constructor
	// Description: Create a patient with a care card number of "0000000000". 
	// Postcondition: All data members set to "To be entered", 
	//                except the care card number which is set to "0000000000".       
	Patient();

	// Parameterized Constructor
	// Description: Create a patient with the given care card number.
	// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
	//                All other data members set to "To be entered".
	Patient(string aCareCard);
	
	// Add more parameterized constructors here!
	// Paramaterized Constructor with parameters aCareCard, aName
	// Postcondition: All data members set to "To be eneterd",
	// 					If aCareCard does not have
	Patient(string aCareCard, string aName);

	// Paramaterized Constructor with parameters aCareCard, aName, aAdress
	Patient(string aCareCard, string aName, string aAdress);

	// Paramaterized Constructor with parameters aCareCard, aName, aAdress, aPhone
	Patient(string aCareCard, string aName, string aAdress, string aPhone);

	// Paramaterized Constructor with parameters aCareCard, aName, aAdress, aPhone, aEmail
	Patient(string aCareCard, string aName, string aAdress, string aPhone, string aEmail);

	// Getters and setters
	// Description: Returns patient's name.
	string getName() const;

	// Description: Returns patient's address.
	string getAddress() const;

	// Description: Returns patient's phone.
	string getPhone() const;

	// Description: Returns patient's email.
	string getEmail() const;
	
	// Description: Returns patient's care card.
	string getCareCard() const;

	// Description: Sets the patient's name.
	void setName(const string aName);

	// Description: Sets the patient's address.
	void setAddress(const string anAddress);

	// Description: Sets the patient's phone.
	void setPhone(const string aPhone);

	// Description: Sets the patient's email.
	void setEmail(const string anEmail);

	// Overloaded Operators
	// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
	//              Returns true if both Patient objects have the same care card number.
	bool operator == (const Patient & rhs);

	// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
	//              Returns true if the care card number of "this" Patient object is > the care card 
	//              number of "rhs" Patient object.
	bool operator > (const Patient & rhs);
	
	// Description: Less than operator. Compares "this" Patient object with "rhs" Patient object.
	//              Returns true if the care card number of "this" Patient object is < the care card 
	//              number of "rhs" Patient object.
	bool operator < (const Patient & rhs);
	
	// For testing purposes!
	// Description: Prints the content of "this".
	friend ostream & operator<<(ostream & os, const Patient & p);

}; // end of Patient.h