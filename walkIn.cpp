/*
 * WalkIn.cpp
 * 
 * Description: Test Driver for List class (ADT) including
 *                  the main function.
 * 
 *     
 * Author: Mohammad Saghafian
 * Modified: 24/January/2022
 * Date: 22/January/2022
 */

 #include <iostream>
 #include <string>
 #include "Patient.h"
 #include "List.h"

 using namespace std;
 
 // test1
 // Description: Testing different Methods of Patient class by instantiating multiple objects. 
 void test1(){
     Patient P1;
     // Testing the default constructor
     if(P1.getCareCard() != "0000000000"){
         cout << "Test1 S1" << endl;
     }
     // Testing getName
     if(P1.getName() != "To be entered"){
         cout << "Test1 S2" << endl;
         
     }
     //Testing getPhone
     if(P1.getPhone() != "To be entered"){
         cout << "Test1 S3" << endl;
     }
     // Testing the paramaterized constructors 
     Patient P2("123123123", "Jeff Bezos");
     if(P2.getCareCard() != "0000000000"){
         cout << "Test1 S4" << endl;
     }
     // Testing getName
     if(P2.getName() != "Jeff Bezos"){
         cout << "Test1 S5" << endl;
     }
     // Testing the setters and getters methods
     P2.setName("Elon Musk");
     if(P2.getName() != "Elon Musk"){
         cout << "Test1 S6" << endl;
     }
     P2.setAddress("Austin, Texas");
     if(P2.getAddress() != "Austin, Texas"){
         cout << "Test1 S7" << endl;
     }

     // Testing the default construcotors
     Patient P3("2342342342");
     Patient P4("1231231231");

     // Testing the boolean operators
     if(P3 < P4){
         cout << "Test1 S8" << endl;
     }
     if(P3 == P4){
         cout << "Test1 S9" << endl;
     }
     
     cout << "Test1 finished successfully" << endl;
 }
 // End of test1


 // test2
 // Description: Testing the construcotr of List class. Testing the methods insert and remove 
 //                    of the List class
 void test2(){
     // Instantiating the first class.
     List Clinic;
     if(Clinic.getElementCount() != 0){
         cout << "Test2 S1" << endl;
     }
     // Instantiating several Patients
     Patient P1("1234123411", "Mo");
     Patient P2("2342342342", "Ali");
     Patient P3("1111111111", "Kia");
     Patient P4("0000000001", "Cyrus");
     Patient P5("0000000002", "Hafez", "Iran");
     Patient P6("1111111112", "Farzan");
     Patient P7("9999999999", "Michael");
     // Testing the accuracy of the insert method
     Clinic.insert(P1);
     Clinic.insert(P1);
     if(Clinic.getElementCount() != 1){
         cout << "Test2 S2" << endl;
         return;
     }
     // Testing the insert method
     Clinic.insert(P3);
     if(Clinic.getElementCount() != 2){
         cout << "Test2 S3" << endl;
         return;
     }
     // Testing the insert method
     for(int i = 0; i < 10; i++){
         Clinic.insert(P2);
     }
     // Testing the insert method
     if(Clinic.getElementCount() != 3){
         cout << "Test2 S4" << endl;
         return;
     }
     // Testing the insert method
     for(int i = 0; i < 10; i++){
         Clinic.insert(P4);
     }
     if(Clinic.getElementCount() != 4){
         cout << "Test2  S5" << endl;
         return;
     }
     // Testing the insert method
     for(int i = 0; i < 10; i++){
         Clinic.insert(P5);
     }
     if(Clinic.getElementCount() != 5){
         cout << "Test2 S6" << endl;
         return;
     }
     // Testing the insert method
     for(int i = 0; i < 10; i++){
         Clinic.insert(P6);
     }
     if(Clinic.getElementCount() != 6){
         cout << "Test2 S7" << endl;
         return;
     }
     // Testing the insert method
     for(int i = 0; i < 10; i++){
         Clinic.insert(P7);
     }
     if(Clinic.getElementCount() != 7){
         cout << "Test2 S8" << endl;
         return;
     }

     cout << "Test2 finished successfully" << endl;
 }
 // End of test 2

 // test3
 // Description: Testing the two methods of remove and remove all of the List class
 void test3(){
     Patient P1("1234123411", "Mo");
     Patient P2("2342342342", "Ali");
     Patient P3("1111111111", "Kia");
     Patient P4("0000000001", "Cyrus");
     Patient P5("0000000002", "Hafez", "Iran");
     Patient P6("1111111112", "Farzan");
     Patient P7("9999999999", "Michael");
     // Instantiating Clinic from List
     List Clinic;

     // Inserting several patients to our Clinic
     Clinic.insert(P1);
     Clinic.insert(P2);
     Clinic.insert(P3);
     Clinic.insert(P4);
     
     // Testing the remove method from the list class
     bool P1bool = Clinic.remove(P1);
     if(Clinic.getElementCount() != 3 && P1bool){
         cout << "Test3 S1" << endl;
     }
     // Testing the remove method from the list class
     
     P1bool = Clinic.remove(P1);
     if(Clinic.getElementCount() != 3 && P1bool == false){
         cout << "Test3 S2" << endl;
     }
     // Testing removeAll from the list class
     Clinic.removeAll();
     if(Clinic.getElementCount() != 0){
         cout << "Test3 S3" << endl;
         return;
     }
     Clinic.printList();
     cout << "Test3 finished successfully" << endl;

 }
 // end of test3

 // test4
 // Description: Testing the insert method of the List class with Psedurandom careCard numbers.
 //                 Testing different capacities to check the the abilities of dynamically allocated arrays. 
 //     
 void test4(){
     List Clinic;
     int num;
     // Testing the implementation of the dynamic array with a 
     // higher number of patients
     for(int i = 0; i < 300; i++){
        num = rand() % 100000000 + 10000000000;
        Patient p(to_string(num));
        Clinic.insert(p);
     }
     if(Clinic.getElementCount() != 300){
         cout << "Test4 S1" << endl;
     }
     // Testing the implementation of the dynamic array with 
     // inserting an excessive amount of patients.
     for(int i = 0; i < 1000; i++){
         num = rand() % 100000000 + 10000000000;
         Patient p(to_string(num));
         Clinic.insert(p);
     }
     if(Clinic.getElementCount() != 1300){
         cout << "Test4 S2" << endl;
     }
     // Testing the search mehtod of the List class
     Patient* Pointer = Clinic.search(to_string(num));
     if(Pointer->getCareCard() != to_string(num)){
         cout << "Test4 S3" << endl;
     }
     // Testing the remove method by using the returned pointer
     // from the search method
     string careCard = Pointer->getCareCard();
     Clinic.remove(*Pointer);
     Pointer = Clinic.search(Pointer->getCareCard());
     if(Pointer != NULL){
         cout << "Test4 S4" << endl;
     }
     // Testing the removeAll method
     Clinic.removeAll();
     if(Clinic.getElementCount() != 0){
         cout << "Test4 S5" << endl;
     }
     // Deleting the pointer
     delete Pointer;
     cout << "Test4 finished successfully" << endl;
 }
 // End of test4


 int main() {
    test1();
    test2();
    test3();
    test4();
 }