#pragma once
/**
*	Wrestler class header file
*	Provides constructs for building individual wrestlers
*/

#include <list>
#include <random>
#include <ctime>
#include <cstdlib>


class Wrestler {
	friend class Tournament;
	protected:
		static constexpr int WIDTH_LABEL = 12;  ///< Label Output Width
		static constexpr int WIDTH_VALUE = 24;  ///< Value Output Width
	private:
		bool _winStatus;
		int _id;//id nummber of wrestler, each wrestler has a unique id within their team
		int _TeamID;					//id number of team
		int _abilityScore;			//ability score of wrestler
		int _losses;					//number of losses wrestler has
		double _weight;					//weight of wrestler
		int _weightClass;			//weight class of wrestler
		int _place;
		std::list<int> beatenWrestlers; //a list of the ids of wrestlers this wrestler has beaten
	public:
		Wrestler() = default;
		/**
		*	non-default constructor
		*/
		Wrestler(int id, int TeamID, int losses) :
			_id{id}, _TeamID{ TeamID }, _losses{ losses }
		{
			_winStatus = false;
			setAbilityScore();
			setWeightClass();
		}
		/**
		*	Wrestler constructor for representing absent wrestler
		*/
		Wrestler(int id, int TeamID, int losses, int abilityScore) :
			_id{ id }, _TeamID{ TeamID }, _losses{ losses }, _abilityScore{abilityScore}
		{
			_winStatus = false;
			setWeightClass();
		}
		/**
		*	Copy constructor
		*/
		Wrestler(const Wrestler& src) = default;
		/**
		*	Destructor
		*/
		virtual ~Wrestler() = default;
		/**
		*	Assignment operator overload
		*/
		Wrestler& operator=(const Wrestler& rhs) = default;
		/**
		*	Prints wrestler data
		*/
		void setPlace(const int& place);
		int getPlace();
		void display(std::ostream& outs) const;
		int wrestle(int abilityScore);
		int getTeamID() const;
		void setTeamID(int newID);
		int getID() const;
		void setID(int);
		int getAbilityScore() const;
		void setAbilityScore();
		void setWeight(double mean, double stdv);
		void setWeightClass();
		int getWeightClass() const;
		double getWeight() const;
		void addToWin(int beatenWrestlerID);
		int getWins() const;
		int getLosses() const;
		void addLosses(int lossNumber);
		bool getWinStatus();
		void setWinStatus(bool status);
};
