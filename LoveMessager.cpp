//--------------------Header Files------------------
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<algorithm>
#include<deque>
#include<set>
#include <functional> 

#include<iomanip>
#include<stack>
#include<Windows.h>
#include<string>
#include<stdio.h>
#include<cstring>
//----------------------------------------------------
using namespace std;
//////////////////////////////////////////////////////
vector < string> intro,body,conclusion,message; // template strings
map<string, bool>repeat;
/////////////////////////////////////////////////////

//////////////Functions Defination//////////////////
void initialTemplates();
bool doAgain();
void title();
void prLine(int n);
void getInfo(string& sender, string& reciever);
void makeLove(string& sender, string& reciever);
int randomi(int start, int end);
string arrange(string temp, string& sender, string& reciever);
void align();
void printM();
////////////////////////////////////////////////////
int main() {
	initialTemplates();
	do {
		repeat.clear();
		message.clear();
		srand(time(NULL));

		// title
		title(); cout << "\b"; prLine(50);
		///////////////////////////////////
		// get names 
		string sender, reciever;
		getInfo(sender,reciever);
		///////////////////////////////////
		// make messege
		makeLove(sender,reciever);
		// align it
		align();
		///////////////
	    // print
		printM();
		//////////////
		cout << "\n\n";
		system("pause");
	} while (doAgain());




}

//---------------Functions Body-----------------------

//////////////////////////////////////////////////////
void initialTemplates() {
	short choosed = 0;
	string tempStr;
	// open file
	ifstream tempFile; 
	tempFile.open("temps.txt",  ifstream::out | ifstream::app);
	if (tempFile.is_open()) {
		//
		//
		//
	}
	while (getline(tempFile, tempStr)) {
		/////to change vector we fill////
		if (tempStr == "###") {
			choosed++; continue;
		}
		////////////////////////////////
		// then fill the vector //
		if (choosed == 0) { // intro
			intro.push_back(tempStr);
		}
		else if (choosed == 1) {// body
			body.push_back(tempStr);
		}
		else if (choosed == 2) { // conclusion
			conclusion.push_back(tempStr);
		}
		else {
			break;
		}
		////////////////////////////////
	}
	// close file
	tempFile.close(); 
}
//////////////////////////////////////////////////////
bool doAgain() {
	system("cls");
	title();
	prLine(50);
	cout << "Press Y to write agian,\nor any key to break!\n";
	char input;
	cin >> input;
	return (tolower(input) == 'y') ? true : false;
}
//////////////////////////////////////////////////////
void title() {
	system("cls");
	cout << "\tLL           OOO       V       V     EEEE     RRRRRR \n ";
	cout << "\tLL          O   O       V     V     E    E    RR    R  \n";
	cout << "\tLL         O     O       V   V      EEEEE     RRRRRR   \n";
	cout << "\tLL          O   O         V V       E         RR   RR   \n";
	cout << "\tLLLLLLL      OOO           V         EEEE     RR    RR  \n";
	cout << "\n\n";
}
//////////////////////////////////////////////////////
void prLine(int n) {
	cout << "\n";
	while (n--)cout << "-";
	cout << "\n";
}
//////////////////////////////////////////////////////
void getInfo(string& sender, string& reciever) {
	cout << "ENTER SENDER NAME:  "; cin >> sender;
	cout << "\n";
	cout << "ENTER RECIEVER NAME:  "; cin >> reciever;
	cout << "\n";
}
//////////////////////////////////////////////////////
void makeLove(string&sender,string& reciever) {
	string str;
	//////////head/////////////
	str = ("To: " + reciever+".\n");
	message.push_back(str);
	str = ("From: " + sender+".\n");
	message.push_back(str);
	str = "--------------------------------------------------------------\n\n";
	message.push_back(str);
	message.push_back("");
	//////////////////////////
	short it = 1;
	while (it++ < 13) {
		int index;

		if (it < 4) {// intro phase
			// get string index
			do {
				index = randomi(0, intro.size() - 1);
			} while (repeat[intro[index]]);
			repeat[intro[index]] = 1;
			//-----------------
			//check if there is (sender) or (reciever.)
			str=arrange(intro[index],sender,reciever)+". ";
			message.back() += str;
			
		}
		else if (it < 11) { // body phase
			// get string index

			do {
				index = randomi(0, body.size() - 1);
			} while (repeat[body[index]]);
			repeat[body[index]] = 1;			//-----------------
			//check if there is (sender) or (reciever.)
			str = arrange(body[index], sender, reciever) + ". ";
			message.back() += str;

		}
		else { // conclusion
			// get string index
			do {
				index = randomi(0, conclusion.size() - 1);
			} while (repeat[conclusion[index]]);
			repeat[conclusion[index]] = 1;			//-----------------
			//check if there is (sender) or (reciever.)
			str = arrange(conclusion[index], sender, reciever) + ". ";
			message.back() += str;

		}
		///////////////////////////
		if (it == 3 || it == 10) {
			message.push_back("\n\n");
			message.push_back("");
		}
	}
	str = "\n\n\t\t------------------\n\t\tSincerly,\n\t\t" + sender;
	message.push_back(str);
}
//////////////////////////////////////////////////////

int randomi(int start, int end) {
	return(start + rand() % (++end));
}
//////////////////////////////////////////////////////
string arrange(string temp,string&sender,string&reciever) {
	int it = temp.find("(sender)");
	if (it !=-1) {
		temp.erase(it, 8);
		temp.insert(it, sender);
	}
	it = temp.find("(reciever)");
	if (it!=-1) {
		temp.erase(it, 10);
		temp.insert(it, reciever);
	}
	return temp;
}
//////////////////////////////////////////////////////
void align() {
	// 3,5,7;
	for (int i = 0; i < message[3].size(); i++) {
		if (!(i % 150)&&i) { // new line
			if (message[3][i] != ' '&& message[3][i] != '.'&&message[3][i - 1] != ' ') { // insert dash _ and new line
				message[3].insert(i, "_\n");
			}
			else { // insert new line
				message[3].insert(i+1, "\n");
			}
		}
	}
	///
	for (int i = 0; i < message[5].size(); i++) {
		if (!(i % 150)&&i) { // new line
			if (message[5][i] != ' ' && message[5][i] != '.' && message[5][i - 1] != ' ') { // insert dash _ and new line
				message[5].insert(i, "_\n");
			}
			else { // insert new line
				message[5].insert(i + 1, "\n");
			}
		}
	}
	///
	for (int i = 0; i < message[7].size(); i++) {
		if (!(i % 150)&&i) { // new line
			if (message[7][i] != ' ' && message[7][i] != '.' && message[7][i - 1] != ' ') { // insert dash _ and new line
				message[7].insert(i, "_\n");
			}
			else { // insert new line
				message[7].insert(i+1 , "\n");
			}
		}
	}
}
//////////////////////////////////////////////////////
void printM() {
	for (auto it : message) {
		cout << it;
	}
}
////////////////////////////////////////////////////////