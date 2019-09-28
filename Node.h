/*
-------------------------------------------
Student: Malik Sheharyaar Talhat talhat@sheridan.desire2learn.com
StudentID: 991435266
-------------------------------------------
 */

/* 
 * File:   Node.h
 * Author: Malik Sheharyaar Talhat talhat@sheridan.desire2learn.com
 *
 * Created on April 5, 2019, 5:08 PM
 */

#ifndef NODE_H
#define NODE_H
using namespace std;


struct Node {
    string first_name;
    string last_name;
    int phone_number;
    struct Node *prev;
    struct Node *next;

};

#endif /* NODE_H */

