/*********************************************************
*	A file that implements the Concert.h
*	
*	Created by: Keith Rodgers
*	Collaborated With: Ryan Walt,  Dylan Kernohan, Keith Schmitt
**********************************************************/

#include "Concert.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <algorithm>



/*************************************************************************************
*	Default Constructor
*************************************************************************************/
Concert::Concert(){
	concertName = "";
	friends.clear();
	desire = -1;
	date.tm_year = 2099;
	date.tm_mon = 1;
	date.tm_mday = 1;
}


/*************************************************************************************
*	Constructor
*************************************************************************************/
Concert::Concert(std::string concertName, std::vector<std::string> friends, int desire, std::tm date ){
	this -> concertName = concertName;
	this -> friends = friends;
	this -> desire = desire;
	this -> date = date;

}

// Getters

/*************************************************************************************
*	Get the Concert Name
*************************************************************************************/
std::string Concert::getConcertName() const{
	return concertName;
}

/*************************************************************************************
*	Get the Concert Friend Vector
*************************************************************************************/
std::vector<std::string> Concert::getFriends() const{
	return friends;
}

/*************************************************************************************
*	Get the Concert Desire
*************************************************************************************/
int Concert::getDesire() const{
	return desire;
}

/*************************************************************************************
*	Get the Concert Date
*************************************************************************************/
std::tm Concert::getDate() const{
	return date;
}



/************************************************************************************
*	< Operator Overload
*
*	Compare a concert by date first
*	then its desire
*
*	If the concert date is closer, the concert is higher priority (greater than) 
*************************************************************************************/
bool Concert::operator<(const Concert& other) const{


    if (date.tm_year > other.date.tm_year){
        return true;
    }
    else if (date.tm_year == other.date.tm_year){
        if(date.tm_mon > other.date.tm_mon){
            return true;
        }
        else if(date.tm_mon == other.date.tm_mon){
            if(date.tm_mday > other.date.tm_mday)
                return true;
            else if(date.tm_mday == other.date.tm_mday){
                if(desire < other.desire){
                    return true;
                }
            }
        }
    }


    return false;

}


/*************************************************************************************
*	<< Operator Overload
*
*	Allows the user to cout<< a Concert object easily
*************************************************************************************/
std::ostream& operator<<(std::ostream& out, const Concert& c) {

	// Gets the date of the concert
	std::tm date = c.getDate();

	// Gets the friends vector of the concert
	std::vector<std::string> friendsVector = c.getFriends();

	// Creates a string that will store all the friends
	std::string friends = "{";

	// Iterates throught he friends vector and stores each friend into the friend string
	for (int i = 0; i < friendsVector.size(); i++){
		// Checks to see if it is the last friend in the vector to add a comma or not
		if(i != friendsVector.size() - 1)
			friends += friendsVector[i] + ", ";
		else
			friends += friendsVector[i];
	}

	friends += "}";
	
	// Formats the out stream of the  Concert object
    out << '(' << c.getConcertName() << ": " << date.tm_mon << "/" << date.tm_mday << "/" << date.tm_year << " | " << c.getDesire() << " | " << friends << ')' << "\n";

    return out;
    }





/*************************************************************************************
*	Main: 
*	Creates 10 Concerts,
*	Sorts them using the overloaded < operator
*	Prints the sorted Concerts (greatest to least) using the overloaded << operator
*************************************************************************************/
int main(int argc, char* argv[]){

	// Concert 1 - 6
	std::tm tempdate1;
	tempdate1.tm_year = 2018;
	tempdate1.tm_mon = 3;
	tempdate1.tm_mday = 1;
	std::vector<std::string> sample1 {"Dylan", "Ryan", "Keith"};
	auto concert_1 = new Concert("Concert 1", sample1, 2, tempdate1);

	// Concert 2 - 1
	std::tm tempdate2;
	tempdate2.tm_year = 2017;
	tempdate2.tm_mon = 2;
	tempdate2.tm_mday = 1;
	std::vector<std::string> sample2 {"Dylan"};
	auto concert_2 = new Concert("Concert 2", sample2, 5, tempdate2);

	// Concert 3 - 9
	std::tm tempdate3;
	tempdate3.tm_year = 2019;
	tempdate3.tm_mon = 1;
	tempdate3.tm_mday = 4;
	std::vector<std::string> sample3 {"Ryan"};
	auto concert_3 = new Concert("Concert 3", sample3, 7, tempdate3);

	// Concert 4 - 3
	std::tm tempdate4;
	tempdate4.tm_year = 2017;
	tempdate4.tm_mon = 5;
	tempdate4.tm_mday = 15;
	std::vector<std::string> sample4 {"Keith"};
	auto concert_4 = new Concert("Concert 4", sample4, 1, tempdate4);

	// Concert 5 - 2
	std::tm tempdate5;
	tempdate5.tm_year = 2017;
	tempdate5.tm_mon = 3;
	tempdate5.tm_mday = 2;
	std::vector<std::string> sample5 {"Dylan", "Ryan"};
	auto concert_5 = new Concert("Concert 5", sample5, 5, tempdate5);

	// Concert 6 - 8
	std::tm tempdate6;
	tempdate6.tm_year = 2018;
	tempdate6.tm_mon = 11;
	tempdate6.tm_mday = 12;
	std::vector<std::string> sample6 {"Ryan", "Keith"};
	auto concert_6 = new Concert("Concert 6", sample6, 9, tempdate6);

	// Concert 7 - 10
	std::tm tempdate7;
	tempdate7.tm_year = 2019;
	tempdate7.tm_mon = 7;
	tempdate7.tm_mday = 20;
	std::vector<std::string> sample7 {"Dylan", "Keith"};
	auto concert_7 = new Concert("Concert 7", sample7, 4, tempdate7);

	// Concert 8 - 7
	std::tm tempdate8;
	tempdate8.tm_year = 2018;
	tempdate8.tm_mon = 5;
	tempdate8.tm_mday = 1;
	std::vector<std::string> sample8 {"Bob"};
	auto concert_8 = new Concert("Concert 8", sample8, 6, tempdate8);

	// Concert 9 - 4
	std::tm tempdate9;
	tempdate9.tm_year = 2017;
	tempdate9.tm_mon = 12;
	tempdate9.tm_mday = 25;
	std::vector<std::string> sample9 {"Brock", "Ash", "Misty"};
	auto concert_9 = new Concert("Concert 9", sample9, 10, tempdate9);

	// Concert 10 - 5
	std::tm tempdate10;
	tempdate10.tm_year = 2017;
	tempdate10.tm_mon = 12;
	tempdate10.tm_mday = 25;
	std::vector<std::string> sample10 {"Ira", "Dylan", "Programming"};
	auto concert_10 = new Concert("Concert 10", sample10, 3, tempdate10);

	std::vector<Concert> concerts;

	concerts.push_back(*concert_1);
	concerts.push_back(*concert_2);
	concerts.push_back(*concert_3);
	concerts.push_back(*concert_4);
	concerts.push_back(*concert_5);
	concerts.push_back(*concert_6);
	concerts.push_back(*concert_7);
	concerts.push_back(*concert_8);
	concerts.push_back(*concert_9);
	concerts.push_back(*concert_10);

	// Sort the concerts vector using the overoaded < operator
	sort(concerts.begin(), concerts.begin()+10);

	// Print the sorted concert vector with the overloaded << operator (Backwards so it prints most important concerts to least important concerts {Greates to Least})
	std::cout << "\nConcerts in order from most important to least important:\n\n" << concerts[9] << concerts[8] << concerts[7] << concerts[6] << concerts[5] << concerts[4] << concerts[3] << concerts[2] << concerts[1] << concerts[0] << std::endl;

	
}
