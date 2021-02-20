#pragma once
/**
*	Team class header file
*	Provides constructs for building individual teams
*/
#include "Wrestler.h"

#include <vector>
#include <queue>

/*
*	Comparator class to enable priority queue to prioritize by wrestler ability score
*/
class compareAbilityScore {
	public:
		bool operator()(const Wrestler* w1, const Wrestler* w2)
		{
			return ((w1->getAbilityScore()) < (w2->getAbilityScore()));
		}
};


class Team {
	friend class Match;
	friend class Wrestler;
	friend class Tournament;
	private:
		int _teamSize;			//size of team, is randomly generated using a normal distribution of (100, 20), mean and stdv respecitvely
		int _totalTeamPoints;	//Total amount of points earned by team in a given match
		int _desiredTeamID;		//the number the Team object's TeamID will be set to on Team object insantiation
		int _wins;
		std::priority_queue<Wrestler*, std::vector<Wrestler*>, compareAbilityScore> weightClass1;		//pq of weight class 1
		std::priority_queue<Wrestler*, std::vector<Wrestler*>, compareAbilityScore> weightClass2;		//pq of weight class 2
		std::priority_queue<Wrestler*, std::vector<Wrestler*>, compareAbilityScore> weightClass3;		//pq of weight class 3
		std::priority_queue<Wrestler*, std::vector<Wrestler*>, compareAbilityScore> weightClass4;		//pq of weight class 4
		std::priority_queue<Wrestler*, std::vector<Wrestler*>, compareAbilityScore> weightClass5;		//pq of weight class 5
		std::priority_queue<Wrestler*, std::vector<Wrestler*>, compareAbilityScore> weightClass6;		//pq of weight class 6
		std::priority_queue<Wrestler*, std::vector<Wrestler*>, compareAbilityScore> weightClass7;		//pq of weight class 7
		std::priority_queue<Wrestler*, std::vector<Wrestler*>, compareAbilityScore> weightClass8;		//pq of weight class 8
		std::priority_queue<Wrestler*, std::vector<Wrestler*>, compareAbilityScore> weightClass9;		//pq of weight class 9
		std::priority_queue<Wrestler*, std::vector<Wrestler*>, compareAbilityScore> weightClass10;		//pq of weight class 10
		std::priority_queue<Wrestler*, std::vector<Wrestler*>, compareAbilityScore> weightClass11;		//pq of weight class 11
		std::priority_queue<Wrestler*, std::vector<Wrestler*>, compareAbilityScore> weightClass12;		//pq of weight class 12
		std::priority_queue<Wrestler*, std::vector<Wrestler*>, compareAbilityScore> weightClass13;		//pq of weight class 13

		std::vector<std::priority_queue<Wrestler*, std::vector<Wrestler*>, compareAbilityScore>> team;		//vector of priority queues representing the team as a whole, 
																											//	with each element of the vector being a pq of weight classes
		
	public:
		//Team() = default;
		/**
		*	Non-default Constructor
		*/
		Team(int desiredTeamID) :
			_desiredTeamID{desiredTeamID}
		{
			_wins = 0;
			_totalTeamPoints = 0;
			generateTeam( _desiredTeamID);
		}
		/**
		*	Copy constructor
		*/
		Team(const Team& src) = default;
		/**
		*	Destructor
		*/
		virtual ~Team() = default;
		/**
		*	Generates team size (randomly)
		*/
		void generateTeamSize();
		/**
		*	Creates team, allocates each wrestler into proper weight class, then places weight classes into team vector
		*/
		void generateTeam(int desiredTeamID);
		/**
		*	returns size of team
		*/
		int getTeamSize();
		/**
		*	returns ID of team
		*/
		int getTeamID();
		/**
		*	Returns total points earned by team
		*/
		int getTeamPoints();
		/**
		*	adds points to current total amount of points held by team 
		*/
		void addTeamPoints(int points);
		/**
		*	adds win to total team wins
		*/
		void addTeamWin();
};