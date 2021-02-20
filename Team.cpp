
#include "Team.h"
#include <iostream>

void Team::generateTeam(int desiredTeamID)
{
	this->generateTeamSize();
	for (int i = 0; i < this->_teamSize ; i++)
	{
		Wrestler* newWrestler = new Wrestler(i+desiredTeamID, desiredTeamID, 0);
		switch (newWrestler->getWeightClass())
		{
		case 1 :
			this->weightClass1.push(newWrestler);
			break;
		case 2 :
			this->weightClass2.push(newWrestler);
			break;
		case 3 :
			this->weightClass3.push(newWrestler);
			break;
		case 4 :
			this->weightClass4.push(newWrestler);
			break;
		case 5 :
			this->weightClass5.push(newWrestler);
			break;
		case 6 :
			this->weightClass6.push(newWrestler);
			break;
		case 7 :
			this->weightClass7.push(newWrestler);
			break;
		case 8 :
			this->weightClass8.push(newWrestler);
			break;
		case 9 :
			this->weightClass9.push(newWrestler);
			break;
		case 10:
			this->weightClass10.push(newWrestler);
			break;
		case 11:
			this->weightClass11.push(newWrestler);
			break;
		case 12:
			this->weightClass12.push(newWrestler);
			break;
		case 13:
			 this->weightClass13.push(newWrestler);
			 break;
		default:
			break;
		}
	}
	this->team.emplace_back(weightClass1);
	this->team.emplace_back(weightClass2);
	this->team.emplace_back(weightClass3);
	this->team.emplace_back(weightClass4);
	this->team.emplace_back(weightClass5);
	this->team.emplace_back(weightClass6);
	this->team.emplace_back(weightClass7);
	this->team.emplace_back(weightClass8);
	this->team.emplace_back(weightClass9);
	this->team.emplace_back(weightClass10);
	this->team.emplace_back(weightClass11);
	this->team.emplace_back(weightClass12);
	this->team.emplace_back(weightClass13);
}
void Team::generateTeamSize()//generate random number of wrestlers in team
{
	std::normal_distribution<float> dist(35.0, 5.0);
	std::random_device teamSize;
	std::default_random_engine generator(teamSize());
	this->_teamSize = (int) round(dist(generator)); //cast from double-to-int is intended
}
int Team::getTeamSize()
{
	return _teamSize;
}
int Team::getTeamID()
{
	return _desiredTeamID;
}
int Team::getTeamPoints()
{
	return _totalTeamPoints;
}
void Team::addTeamPoints(int points)
{
	this->_totalTeamPoints = _totalTeamPoints + points;
}
void Team::addTeamWin()
{
	this->_wins = _wins + 1;
}