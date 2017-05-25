//============================================================================
// Name        : Message.cpp
// Author      : Nancy Zhou
// Version     : ver 1.2- 
//               ver 1- 
//               
//
// Copyright   : dfasdfasdfas stealing is bad plz respek
// Description : 
//               
//               
//               
/*INSTRUCTIONS:
Write a program to read a file containing an encrypted message, which must 
be decoded and printed on the screen. Use the following key to decode:
input text :  abcdefghijklmnopqrstuvwxyz
decoded text: iztohndbeqrkglmacsvwfuypjx
That means each 'a' in the input text should be replaced with an 'i', each 
'b' with a 'z' and so forth.
Punctuation and space should be kept as is. You will notice that all the 
letters in the text are lowercase, so the second step will be to fix the 
captalization. First letter of each sentence should be capitalized.
Print the decoded text to the screen.
You must use an object-oriented approach on this lab. The specification of 
class Message is given in header file Message.h. You need to implement each of
the member functions in the Message.cpp, which you will turn in. The main function 
is also given so you can test your class, but you don't have to turn it in.
I have added in the class definition in "Message.h" that explain how to implement
each member function.
Constructor: Should open the text file and determine its size. To do this, call 
getFileSize() which is implemented in "Message.h". Check for errors when opening 
the input file and don't forget to close it at the end. If there is an error, 
such as the file can't be located, make sure to set length to zero. Otherwise, 
use the file size to allocate space for message.
Destructor: should free the space allocated for message.
decode: decodes the message according to the given key.
fixCapitalization: capitalizes the first letter of each sentence.
dump: prints the content of message on the screen
isEmpty: returns whether message is empty of not.
You only have to turn in message.cpp. You have to make sure it works with the 
header file that I'm providing, since it will be used to compile your message.cpp.
*/
//============================================================================

#include <fstream>
#include <iostream>
#include <string>
#include "Message.h"
using namespace std;

	
	Message::Message(string filename){
		fstream finput;
		finput.open(filename.c_str());
		while (finput >> *message)
		{
			length = getFileSize(finput);			
			for (int i = 0; i < length; i++)
			{
				finput >> message[i];
			}
			finput.close();
		}		
		if (finput.fail())
		{
			cout << "File failed to open" << endl;
			length = 0;
		}
			
	}/*
	* This constructor tries to open the file whose name is passed
	* to it in filename. If file opens successfully, calls function
	* getFileSize to determine how many bytes should be allocated
	* for the message. Allocates space for message and reads the
	* content from the file into it. Closes the file at the end.
	* Member variable length should be set to the file size.
	* If file cannot be found, length should be set to zero.
	*/
	
	Message::~Message(){
		delete message,length, code;

	}// The destructor frees the space allocated to message

	
	void Message::decode(){

	}// Decodes the message

	
	void Message::fixCapitalization(){
		for (int i = 0; i < length; i++){
			if (message[i] == '.')
				toupper(message[i + 1]);
		}
	}// Capitalizes first letter in each sentence

	
	void Message::dump() const{
		for (int i = 0; i < length; i++)
		{
			cout << message[i];
		}
	}// Prints the content of message on the screen

	
	bool Message::isEmpty() const{
		if (length != 0){	
				return 0;
		} 
		else 
			return 1;

	}// Returns true if the message is empty
