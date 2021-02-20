#pragma once
#include "Match.h"
#include <iostream>
class compareTeamScore {
public:
	bool operator()(Team* t1, Team* t2)
	{
		return ((t1->getTeamPoints()) > (t2->getTeamPoints()));
	}
} Scores;
class Tournament : public Match{
private:
		std::vector<Wrestler*> firstPlaceWrestlers;
		std::vector<Wrestler*> secondPlaceWrestlers;
		std::vector<Wrestler*> thirdPlaceWrestlers;
		int _numTeams;
		std::priority_queue<Wrestler*, std::vector<Wrestler*>, compareAbilityScore> wrestlerPQ;
		std::vector<Team*> teamsInTournament;
		std::pair<Wrestler*, Wrestler*> weightBracketBout[14];
	public:
		Tournament(int numTeams)
		{
			generateTeams(numTeams);
		}
		virtual ~Tournament() = default;
		void displayResults(std::ostream& boutResults);
		void generateTeams(int numberOfTeams);
		void setCurrentWeightBracket(int weightBracket, std::ostream& bracketResults);
		void conductWrestlingTournament(std::ostream& boutResults, std::ostream& brackets);
};