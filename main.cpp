/*
-------------------------------------------
Student: Malik Sheharyaar Talhat talhat@sheridan.desire2learn.com
StudentID: 991435266
-------------------------------------------
 */

/* 
 * File:   main.cpp
 * Author: Malik Sheharyaar Talhat talhat@sheridan.desire2learn.com
 *
 * Created on March 31, 2019, 10:12 PM
 */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include "Node.h"
#include "DoubleLinkedList.h"

using namespace std;

int main() {
    int choice;
    std::string first;
    std::string last;
std:
    string phone_string; //used for input validation
    int phone; //used for input validation
    int length;

    DoubleLinkedList dl;
    //If external file exits then load data
    dl.loadData();


    while (1) {
        cout << "---------------------------------";
        cout << endl << "Phone Book";
        cout << endl << "---------------------------------" << endl;
        cout << "1.Insert Contact" << endl;
        cout << "2.Delete Contact" << endl;
        cout << "3.Edit Contact" << endl;
        cout << "4.Save Data" << endl;
        cout << "5.Load Data" << endl;
        cout << "6.Display Contacts" << endl;
        cout << "7.Exit Phone book" << endl;
        cout << endl << "Enter your choice: ";
        cin>>choice;
        switch (choice) {
            case 1:

                std::cin.ignore();
                cout << "Insert first name: ";
                std::getline(std::cin, first);

                cout << "Insert last name: ";
                std::getline(std::cin, last);


                cout << "Insert phone number: ";
                //Input validation
                while (std::getline(std::cin, phone_string)) {
                    std::stringstream stream(phone_string);
                    if (stream >> phone) {
                        if (stream.eof()) {
                            break;
                        }

                    }
                    cout << "Phone number can only be digits, must not contain any spaces, and has to be less than 10 digits" << endl;

                }

                dl.insertNode(first, last, phone);
                cout << endl;
                break;

            case 2:
                //Double Linked List cannot be empty for deletion to take place
                length = dl.length();
                if (length == 0) {
                    cout << "Contact list is empty, unable to delete" << endl;

                } else {
                    std::cin.ignore();
                    cout << "Insert phone number for the contact you want to delete ";
                    while (std::getline(std::cin, phone_string)) {

                        std::stringstream stream(phone_string);
                        if (stream >> phone) {
                            if (stream.eof()) {
                                break;
                            }

                        }
                        cout << "Phone number can only be digits and must not contain any spaces" << endl;

                    }

                    dl.deleteNode(phone);

                }
                break;

            case 3:
                //Double Linked List cannot be empty for being able to edit contacts
                length = dl.length();
                if (length == 0) {
                    cout << "Contact list is empty, unable to edit" << endl;

                } else {
                    std::cin.ignore();
                    cout << "Insert phone number for the contact you want to search ";
                    while (std::getline(std::cin, phone_string)) {

                        std::stringstream stream(phone_string);
                        if (stream >> phone) {
                            if (stream.eof()) {
                                break;
                            }

                        }
                        cout << "Phone number can only be digits and must not contain any spaces" << endl;

                    }

                    dl.search(phone);
                    cout << "Contact updated" << endl;
                }
                break;



            case 4:
                //Double Linked List cannot be empty for saving to take place
                length = dl.length();
                if (length == 0) {
                    cout << "Contact list is empty, unable to save" << endl;

                } else {
                    dl.saveData();
                }
                break;

            case 5:
                dl.loadData();
                break;

            case 6:
                dl.display();
                break;

            case 7:
                cout << "Exiting Phone Book application" << endl;
                exit(0);
                break;
            default:
                cout << "Invalid Option" << endl;
        }
    }
}

