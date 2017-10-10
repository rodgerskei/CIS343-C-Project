/***********************************************************************************************
*	A class that holds concert info
*	
*	Created by: Keith Rodgers
*	Collaborated With: Ryan Walt,  Dylan Kernohan, Keith Schmitt
***********************************************************************************************/

#include <string>
#include <vector>
#include <ctime>



class Concert
{
	public:

		/*************************************************************************************
		*	Default Constructor
		*************************************************************************************/
		Concert();


		/*************************************************************************************
		*	Constructor
		*************************************************************************************/
		Concert(std::string concertName, std::vector<std::string> friends, int desire, std::tm date );
		

		/*************************************************************************************
		*	Getters
		*************************************************************************************/
		std::string getConcertName() const;
		std::vector<std::string> getFriends() const;
		int getDesire() const;
		std::tm getDate() const;
		

		/*************************************************************************************
		*	< Operator Overload
		*************************************************************************************/
		bool operator<(const Concert& other) const;


	private:

		// Who will be performing?
		std::string concertName;

		// A list of the people you want
		// to take with you.  May be empty
		// or arbitrarily full.
		std::vector<std::string> friends;

		// A value from 1-10 concerning how
		// badly you want to see this show.
		int desire;

		// The date of the show
		// See http://en.cppreference.com/w/cpp/chrono/c/tm
		std::tm date;

	
};

std::ostream& operator<<(std::ostream& out, const Concert& c);
