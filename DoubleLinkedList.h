/*
-------------------------------------------
Student: Malik Sheharyaar Talhat talhat@sheridan.desire2learn.com
StudentID: 991435266
-------------------------------------------
 */

/* 
 * File:   DoubleLinkedList.h
 * Author: Malik Sheharyaar Talhat talhat@sheridan.desire2learn.com
 *
 * Created on April 5, 2019, 5:08 PM
 */

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <fstream>
#include "Node.h"

using namespace std;

class DoubleLinkedList {
private:
    Node *head;
    Node *tail;
public:

    Node* insertNode(string first, string second, int);

    void deleteNode(int);

    void display();

    void editNode(Node **);

    void saveData();

    void loadData();

    void search(int);

    int length();


    //Constructor

    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
    }

};
//Allows the creation of a double linked list and to insert additional node at the end

Node *DoubleLinkedList::insertNode(string first, string last, int phone) {

    Node *temp = new(Node);
    temp->first_name = first;
    temp->last_name = last;
    temp->phone_number = phone;

    //Node pointer to start of the double linked list
    Node *current = head;


    if (head == NULL) {
        head = tail = temp;
        head->prev = NULL;
        tail->next = NULL;
        cout << "Contact " << temp->first_name << " " << temp->last_name << " Inserted";

    } else {

        while (current != NULL) {

            if (current->phone_number == temp->phone_number) {
                cout << "The phone number: " << current->phone_number << " already exists!" << endl;
                break;
            } else if (current->next == NULL) {
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
                tail->next = NULL;
                cout << "Contact " << temp->first_name << " " << temp->last_name << " Inserted";
                return temp;
                break;
            }
            current = current->next;
        }


    }

}

//Deletion of nodes depending on user's input of a existing phone number

void DoubleLinkedList::deleteNode(int phone) {


    Node *current = head;

    //Instance of phone number being the first node
    if (current->phone_number == phone) {
        head = current->next;
        return;
    }

    while (current->next != NULL) {



        if (current->next->phone_number == phone) {
            current = current->next;
            current->prev->next = current->next;



        } else if ((current->next->phone_number != phone)) {
            current = current->next;

        }
        //Checks if the current pointer is on the last node
        if ((current->phone_number == phone)&&(current->next == NULL)) {

            tail = current->prev;
            current->prev->next = current->next;

        }
        if ((current->phone_number != phone)&&(current->next == NULL)) {

            cout << "There is no contact for the following phone number " << phone << " in the Phone Book" << endl;
        }

    }
}

//This is a part of the Edit functionality, the search function finds the desired node and sends the pointer reference to the edit function

void DoubleLinkedList::search(int phone) {

    Node *current = head;

    if (current->phone_number == phone) {
        editNode(&current);
    }


    if (current->phone_number != phone) {
        while (current != NULL) {
            //Prints each node by incrementing pointer.

            if (current->phone_number == phone) {
                editNode(&current);

                break;


            } else if ((current->phone_number != phone) && current->next == NULL) {
                cout << "The contact your are trying to edit does not exits" << endl;
                break;
            }

            current = current->next;

        }
    }
}

//Handles what the data the user wants to change from a desired node

void DoubleLinkedList::editNode(Node** header) {
    int choice;
    string first;
    string last;
    string phone_string;
    int phone;

    int check = 1; //Used to determine when the user wants to leave the edit menu
    Node* temp = *header;

    //Used to determine the beginning of the double linked list
    Node* current = head;



    while (check > 0) {
        cout << endl << "---------------------------------";
        cout << endl << "Edit Contact";
        cout << endl << "---------------------------------" << endl;
        cout << "Name: " << temp->first_name << " " << temp->last_name << " Phone number: " << temp->phone_number << endl << endl;
        cout << "1.Edit First Name" << endl;
        cout << "2.Edit Last Name" << endl;
        cout << "3.Edit Phone Number" << endl;
        cout << "4.Exit menu" << endl;
        cout << "Enter your choice: ";
        cin>>choice;
        switch (choice) {
            case 1:

                std::cin.ignore();
                cout << "Insert new first name: ";
                std::getline(std::cin, first);
                temp->first_name = first;
                cout << "First name updated" << endl;
                break;

            case 2:
                std::cin.ignore();
                cout << "Insert new last name: ";
                std::getline(std::cin, last);
                temp->last_name = last;
                cout << "Last name updated" << endl;
                break;

            case 3:
                std::cin.ignore();
                cout << "Insert new phone number: ";
                //Validation of digit only input from user
                while (std::getline(std::cin, phone_string)) {

                    std::stringstream stream(phone_string);
                    if (stream >> phone) {
                        if (stream.eof()) {
                            break;
                        }

                    }
                    cout << "Phone number can only be digits and must not contain any spaces" << endl;


                }



                while (current != NULL) {

                    //Validation to avoid collision between an existing phone number , and the phone number about to be updated
                    if (current->phone_number == phone) {
                        cout << "User already exists, please enter another phone number" << endl;
                        break;
                    } else if (current->next == NULL) {
                        temp->phone_number = phone;
                        cout << "Phone number Updated" << endl;
                        /*Reset the current pointer so that the double linked list is scanned once again
                         *  if the user tries to change the number multiple times when inside the edit option menu
                         */
                        current = head;
                        break;
                    }
                    current = current->next;
                }

                break;

            case 4:
                cout << "Exiting edit menu" << endl;

                check = 0;

                //exit(0);
                break;
            default:
                cout << "Invalid Option" << endl;
        }
    }

}

void DoubleLinkedList::saveData() {
    Node *current = head;
    //External text file to hold raw data
    std::ofstream file("PhoneBook.txt");

    //Check if file can/has been opened properly
    if (file.good()) {

        while (current != NULL) {
            string first = current->first_name;
            string last = current->last_name;
            string phone = std::to_string(current->phone_number);

            if (current->next == NULL) {
                std::string user = first + "," + last + "," + phone + ";";
                file << user;
            } else {
                std::string user = first + "," + last + "," + phone + ";" + "\r\n";
                file << user;
            }


            current = current->next;

        }
        cout << "Contact list saved to external file PhoneBook.txt" << endl;

    } else {
        cout << "Error, could not save to file" << endl;
    }
    file.close();



}

void DoubleLinkedList::loadData() {

    string file = "PhoneBook.txt";

    if (std::fstream{file}) {
        cout << "Loading PhoneBook.txt" << endl;
        cout << endl;
        std::ifstream read(file);
        std::string buffer;

        //Check if file can be read
        while (read.good()) {

            std::string first;
            std::string last;
            std::string phone;

            //Obtain first name from PhoneBook.txt
            std::getline(read, buffer, ',');
            first = buffer;
            
            //Obtain last name from PhoneBook.txt
            std::getline(read, buffer, ',');
            last = buffer;
            
            //Obtain phone number from PhoneBook.txt
            std::getline(read, buffer, ';');
            phone = buffer;

            insertNode(first, last, std::stoi(phone));

            std::getline(read, buffer, '\r');

            std::getline(read, buffer, '\n');
            cout << endl;

        }
    } else {
        cout << "PhoneBook.txt cannot be opened or it does not exist" << endl;
    }


}
//Handles displaying Double linked list contents to user

void DoubleLinkedList::display() {
    Node *current = head;
    cout << endl << "Display elements of linked list:" << endl;
    if (head == NULL) {
        cout << endl;
        cout << "Contact list is empty\n" << endl;

    }

    else {
        while (current != NULL) {
            //Prints each node by incrementing pointer.

            cout << "Name: " << current->first_name << " " << current->last_name << " , Phone number: " << current->phone_number << endl;
            current = current->next;
        }

    }
}

//Determine length of Double linked list

int DoubleLinkedList::length() {
    int counter = 0;
    Node *current = head;
    while (current != NULL) {
        current = current->next;
        counter++;
    }
    return counter;
}
#endif /* DOUBLELINKEDLIST_H */

