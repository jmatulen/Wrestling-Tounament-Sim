
/// wrestlingTournament.cpp : This file contains the 'main' function. Program execution begins and ends there.
///
///
/// zeros in wrestler id output in the 'brackets.txt' file, which represents each bracket/bout, means there was no wrestler present in said weightclass
/// 
/// author:Josh Matulenas
#include "Wrestler.h"
#include "Team.h"
#include "Match.h"
#include "wrestlingTournament.h"
#include <algorithm>
#include <fstream>

using namespace std;
using weightClasses = std::priority_queue<Wrestler*, std::vector<Wrestler*>, compareAbilityScore>;

int main()
{
    ofstream boutResults;
    ofstream brackets;

    boutResults.open("boutResults.txt");
    brackets.open("brackets.txt");

    Tournament* tournament = new Tournament(8);
    tournament->conductWrestlingTournament(boutResults,brackets);
    delete tournament;

    boutResults.close();
    brackets.close();
    return 0;
}

void Tournament::conductWrestlingTournament(std::ostream& boutResults, std::ostream& brackets)
{
    Team* team1 = new Team(100);
    Team* team2 = new Team(200);
    for (int i = 0; i < 13; i++) {

        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        int count = 0;
        setCurrentWeightBracket(i, brackets);
        for (Team* aTeam : this->teamsInTournament)
        {
            if (aTeam->getTeamID() == this->weightBracketBout[count].first->getTeamID())
            {
                team1 = aTeam;
            }
            if (aTeam->getTeamID() == this->weightBracketBout[count].second->getTeamID())
            {
                team2 = aTeam;
            }
        }
        bout(this->weightBracketBout[count].first, this->weightBracketBout[count].second, team1, team2, boutResults);
        if (this->weightBracketBout[count].first->getWinStatus())
        {
            this->weightBracketBout[4].first = this->weightBracketBout[count].first;
            this->weightBracketBout[6].first = this->weightBracketBout[count].second;
        }
        else
        {
            this->weightBracketBout[4].first = this->weightBracketBout[count].second;
            this->weightBracketBout[6].first = this->weightBracketBout[count].first;
        }
        count++;
        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        for (Team* aTeam : this->teamsInTournament)
        {
            if (aTeam->getTeamID() == this->weightBracketBout[count].first->getTeamID())
            {
                team1 = aTeam;
            }
            if (aTeam->getTeamID() == this->weightBracketBout[count].second->getTeamID())
            {
                team2 = aTeam;
            }
        }
        bout(this->weightBracketBout[count].first, this->weightBracketBout[count].second, team1, team2, boutResults);
        if (this->weightBracketBout[count].first->getWinStatus())
        {
            this->weightBracketBout[4].second = this->weightBracketBout[count].first;
            this->weightBracketBout[6].second = this->weightBracketBout[count].second;
        }
        else
        {
            this->weightBracketBout[4].second = this->weightBracketBout[count].second;
            this->weightBracketBout[6].second = this->weightBracketBout[count].first;
        }
        count++;
        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        for (Team* aTeam : this->teamsInTournament)
        {
            if (aTeam->getTeamID() == this->weightBracketBout[count].first->getTeamID())
            {
                team1 = aTeam;
            }
            if (aTeam->getTeamID() == this->weightBracketBout[count].second->getTeamID())
            {
                team2 = aTeam;
            }
        }
        bout(this->weightBracketBout[count].first, this->weightBracketBout[count].second, team1, team2, boutResults);
        if (this->weightBracketBout[count].first->getWinStatus())
        {
            this->weightBracketBout[5].first = this->weightBracketBout[count].first;
            this->weightBracketBout[7].first = this->weightBracketBout[count].second;
        }
        else
        {
            this->weightBracketBout[5].first = this->weightBracketBout[count].second;
            this->weightBracketBout[7].first = this->weightBracketBout[count].first;
        }
        count++;
        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        for (Team* aTeam : this->teamsInTournament)
        {
            if (aTeam->getTeamID() == this->weightBracketBout[count].first->getTeamID())
            {
                team1 = aTeam;
            }
            if (aTeam->getTeamID() == this->weightBracketBout[count].second->getTeamID())
            {
                team2 = aTeam;
            }
        }
        bout(this->weightBracketBout[count].first, this->weightBracketBout[count].second, team1, team2, boutResults);
        if (this->weightBracketBout[count].first->getWinStatus())
        {
            this->weightBracketBout[5].second = this->weightBracketBout[count].first;
            this->weightBracketBout[7].second = this->weightBracketBout[count].second;
        }
        else
        {
            this->weightBracketBout[5].second = this->weightBracketBout[count].second;
            this->weightBracketBout[7].second = this->weightBracketBout[count].first;
        }
        count++;
        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        for (Team* aTeam : this->teamsInTournament)
        {
            if (aTeam->getTeamID() == this->weightBracketBout[count].first->getTeamID())
            {
                team1 = aTeam;
            }
            if (aTeam->getTeamID() == this->weightBracketBout[count].second->getTeamID())
            {
                team2 = aTeam;
            }
        }
        bout(this->weightBracketBout[count].first, this->weightBracketBout[count].second, team1, team2, boutResults);
        if (this->weightBracketBout[count].first->getWinStatus())
        {
            this->weightBracketBout[13].first = this->weightBracketBout[count].first;
            this->weightBracketBout[9].first = this->weightBracketBout[count].second;
        }
        else
        {
            this->weightBracketBout[13].first = this->weightBracketBout[count].second;
            this->weightBracketBout[9].first = this->weightBracketBout[count].first;
        }
        brackets << weightBracketBout[count].first->getID() << " vs. " << weightBracketBout[count].second->getID() << endl;
        count++;
        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        for (Team* aTeam : this->teamsInTournament)
        {
            if (aTeam->getTeamID() == this->weightBracketBout[count].first->getTeamID())
            {
                team1 = aTeam;
            }
            if (aTeam->getTeamID() == this->weightBracketBout[count].second->getTeamID())
            {
                team2 = aTeam;
            }
        }
        bout(this->weightBracketBout[count].first, this->weightBracketBout[count].second, team1, team2, boutResults);
        if (this->weightBracketBout[count].first->getWinStatus())
        {
            this->weightBracketBout[13].second = this->weightBracketBout[count].first;
            this->weightBracketBout[8].second = this->weightBracketBout[count].second;
        }
        else
        {
            this->weightBracketBout[13].second = this->weightBracketBout[count].second;
            this->weightBracketBout[8].second = this->weightBracketBout[count].first;
        }
        brackets << weightBracketBout[count].first->getID() << " vs. " << weightBracketBout[count].second->getID() << endl;
        count++;
        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        for (Team* aTeam : this->teamsInTournament)
        {
            if (aTeam->getTeamID() == this->weightBracketBout[count].first->getTeamID())
            {
                team1 = aTeam;
            }
            if (aTeam->getTeamID() == this->weightBracketBout[count].second->getTeamID())
            {
                team2 = aTeam;
            }
        }
        bout(this->weightBracketBout[count].first, this->weightBracketBout[count].second, team1, team2, boutResults);
        if (this->weightBracketBout[count].first->getWinStatus())
        {
            this->weightBracketBout[8].first = this->weightBracketBout[count].first;
            this->weightBracketBout[10].first = this->weightBracketBout[count].second;
        }
        else
        {
            this->weightBracketBout[8].first = this->weightBracketBout[count].second;
            this->weightBracketBout[10].first = this->weightBracketBout[count].first;
        }
        brackets << weightBracketBout[count].first->getID() << " vs. " << weightBracketBout[count].second->getID() << endl;
        count++;
        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        for (Team* aTeam : this->teamsInTournament)
        {
            if (aTeam->getTeamID() == this->weightBracketBout[count].first->getTeamID())
            {
                team1 = aTeam;
            }
            if (aTeam->getTeamID() == this->weightBracketBout[count].second->getTeamID())
            {
                team2 = aTeam;
            }
        }
        bout(this->weightBracketBout[count].first, this->weightBracketBout[count].second, team1, team2, boutResults);
        if (this->weightBracketBout[count].first->getWinStatus())
        {
            this->weightBracketBout[9].second = this->weightBracketBout[count].first;
            this->weightBracketBout[10].second = this->weightBracketBout[count].second;
        }
        else
        {
            this->weightBracketBout[9].second = this->weightBracketBout[count].second;
            this->weightBracketBout[10].second = this->weightBracketBout[count].first;
        }
        brackets << weightBracketBout[count].first->getID() << " vs. " << weightBracketBout[count].second->getID() << endl;
        count++;
        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        for (Team* aTeam : this->teamsInTournament)
        {
            if (aTeam->getTeamID() == this->weightBracketBout[count].first->getTeamID())
            {
                team1 = aTeam;
            }
            if (aTeam->getTeamID() == this->weightBracketBout[count].second->getTeamID())
            {
                team2 = aTeam;
            }
        }
        bout(this->weightBracketBout[count].first, this->weightBracketBout[count].second, team1, team2, boutResults);
        if (this->weightBracketBout[count].first->getWinStatus())
        {
            this->weightBracketBout[12].first= this->weightBracketBout[count].first;
            this->weightBracketBout[11].first = this->weightBracketBout[count].second;
        }
        else
        {
            this->weightBracketBout[12].first = this->weightBracketBout[count].second;
            this->weightBracketBout[11].first = this->weightBracketBout[count].first;
        }
        brackets << weightBracketBout[count].first->getID() << " vs. " << weightBracketBout[count].second->getID() << endl;
        count++;
        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        for (Team* aTeam : this->teamsInTournament)
        {
            if (aTeam->getTeamID() == this->weightBracketBout[count].first->getTeamID())
            {
                team1 = aTeam;
            }
            if (aTeam->getTeamID() == this->weightBracketBout[count].second->getTeamID())
            {
                team2 = aTeam;
            }
        }
        bout(this->weightBracketBout[count].first, this->weightBracketBout[count].second, team1, team2, boutResults);
        if (this->weightBracketBout[count].first->getWinStatus())
        {
            this->weightBracketBout[12].second = this->weightBracketBout[count].first;
            this->weightBracketBout[11].second = this->weightBracketBout[count].second;
        }
        else
        {
            this->weightBracketBout[12].second = this->weightBracketBout[count].second;
            this->weightBracketBout[11].second = this->weightBracketBout[count].first;
        }
        brackets << weightBracketBout[count].first->getID() << " vs. " << weightBracketBout[count].second->getID() << endl;
        count++;
        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        for (Team* aTeam : this->teamsInTournament)
        {
            if (aTeam->getTeamID() == this->weightBracketBout[count].first->getTeamID())
            {
                team1 = aTeam;
            }
            if (aTeam->getTeamID() == this->weightBracketBout[count].second->getTeamID())
            {
                team2 = aTeam;
            }
        }
        bout(this->weightBracketBout[count].first, this->weightBracketBout[count].second, team1, team2, boutResults);
        if (this->weightBracketBout[count].first->getWinStatus())
        {
            this->weightBracketBout[count].first->setPlace(7);
            this->weightBracketBout[count].second->setPlace(8);
        }
        else
        {
            this->weightBracketBout[count].first->setPlace(8);
            this->weightBracketBout[count].second->setPlace(7);
        }
        brackets << weightBracketBout[count].first->getID() << " vs. " << weightBracketBout[count].second->getID() << endl;
        count++;
        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        for (Team* aTeam : this->teamsInTournament)
        {
            if (aTeam->getTeamID() == this->weightBracketBout[count].first->getTeamID())
            {
                team1 = aTeam;
            }
            if (aTeam->getTeamID() == this->weightBracketBout[count].second->getTeamID())
            {
                team2 = aTeam;
            }
        }
        bout(this->weightBracketBout[count].first, this->weightBracketBout[count].second, team1, team2, boutResults);
        if (this->weightBracketBout[count].first->getWinStatus())
        {
            this->weightBracketBout[count].first->setPlace(5);
            this->weightBracketBout[count].second->setPlace(6);
        }
        else
        {
            this->weightBracketBout[count].first->setPlace(6);
            this->weightBracketBout[count].second->setPlace(5);
        }
        brackets << weightBracketBout[count].first->getID() << " vs. " << weightBracketBout[count].second->getID() << endl;
        count++;
        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        for (Team* aTeam : this->teamsInTournament)
        {
            if (aTeam->getTeamID() == this->weightBracketBout[count].first->getTeamID())
            {
                team1 = aTeam;
            }
            if (aTeam->getTeamID() == this->weightBracketBout[count].second->getTeamID())
            {
                team2 = aTeam;
            }
        }
        bout(this->weightBracketBout[count].first, this->weightBracketBout[count].second, team1, team2, boutResults);
        if (this->weightBracketBout[count].first->getWinStatus())
        {
            this->weightBracketBout[count].first->setPlace(3);
            this->weightBracketBout[count].second->setPlace(4);
        }
        else
        {
            this->weightBracketBout[count].first->setPlace(4);
            this->weightBracketBout[count].second->setPlace(3);
        }
        brackets << weightBracketBout[count].first->getID() << " vs. " << weightBracketBout[count].second->getID() << endl;
        count++;
        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        for (Team* aTeam : this->teamsInTournament)
        {
            if (aTeam->getTeamID() == this->weightBracketBout[count].first->getTeamID())
            {
                team1 = aTeam;
            }
            if (aTeam->getTeamID() == this->weightBracketBout[count].second->getTeamID())
            {
                team2 = aTeam;
            }
        }
        brackets << weightBracketBout[count].first->getID() << " vs. " << weightBracketBout[count].second->getID() << endl;
        bout(this->weightBracketBout[count].first, this->weightBracketBout[count].second, team1, team2, boutResults);
        if (this->weightBracketBout[count].first->getWinStatus())
        {
            this->weightBracketBout[count].first->setPlace(1);
            this->weightBracketBout[count].second->setPlace(2);
        }
        else
        {
            this->weightBracketBout[count].first->setPlace(2);
            this->weightBracketBout[count].second->setPlace(1);
        }
    }
    displayResults(std::cout);
    delete team1;
    delete team2;
}
void Tournament::generateTeams(int numTeams)
{
    teamsInTournament.reserve(numTeams);
    this->_numTeams = numTeams;
    for (int i = 0; i < numTeams; i++)
    {
        Team* team = new Team((i + 1) * 100);
        this->teamsInTournament.emplace_back(team);
    }
}
void Tournament::setCurrentWeightBracket(int weightBracket, std::ostream& bracketResults)
{
    while (!this->wrestlerPQ.empty())
    {
        this->wrestlerPQ.pop();
    }
    for (int i = 0; i<this->_numTeams; i++)
    {   
        if (this->teamsInTournament[i]->team[weightBracket].empty())
        {
            Wrestler* absentWrestler = new Wrestler(0, 0, 0, 0);
            absentWrestler->_weightClass = weightBracket+1;
            this->wrestlerPQ.push(absentWrestler);
            continue;
        }
        this->wrestlerPQ.push(this->teamsInTournament[i]->team[weightBracket].top());
    }
    this->weightBracketBout[0].first = this->wrestlerPQ.top(); this->wrestlerPQ.pop();
    this->weightBracketBout[3].first = this->wrestlerPQ.top(); this->wrestlerPQ.pop();
    this->weightBracketBout[2].first = this->wrestlerPQ.top(); this->wrestlerPQ.pop();
    this->weightBracketBout[1].second = this->wrestlerPQ.top(); this->wrestlerPQ.pop();
    this->weightBracketBout[1].first = this->wrestlerPQ.top(); this->wrestlerPQ.pop();
    this->weightBracketBout[2].second = this->wrestlerPQ.top(); this->wrestlerPQ.pop();
    this->weightBracketBout[3].second = this->wrestlerPQ.top(); this->wrestlerPQ.pop();
    this->weightBracketBout[0].second = this->wrestlerPQ.top(); this->wrestlerPQ.pop();

    bracketResults << "BRACKET FOR WEIGHT CLASS: " << weightBracket+1 << endl;
    for (int i = 0; i < 4; i++)
    {
        bracketResults << weightBracketBout[i].first->getID() << " vs. " << weightBracketBout[i].second->getID() << endl;
    }
}
void Tournament::displayResults(std::ostream& results)
{
    std::sort(this->teamsInTournament.begin(), this->teamsInTournament.end(), Scores);
    for (int i = 0; i < 3; i++)
    {
        cout << "Team: " << this->teamsInTournament[i]->getTeamID() << ", with " << this->teamsInTournament[i]->getTeamPoints() << " Points" << endl;
    }
    for (Team* team : this->teamsInTournament)
    {
        for (weightClasses weightClass : team->team)
        {
            for (int i = 0; i < weightClass.size(); i++)
            {
                switch (weightClass.top()->getPlace())
                {
                case 1:
                    //cout << "1st Place: " << endl; weightClass.top()->display(std::cout);
                    firstPlaceWrestlers.push_back(weightClass.top());
                    weightClass.pop();
                    break;
                case 2:
                    //cout << "2nd Place: " << endl; weightClass.top()->display(std::cout);
                    secondPlaceWrestlers.push_back(weightClass.top());
                    weightClass.pop();
                    break;
                case 3:
                    //cout << "3rd Place: " << endl; weightClass.top()->display(std::cout);
                    thirdPlaceWrestlers.push_back(weightClass.top());
                    weightClass.pop();
                    break;
                default:
                    weightClass.pop();
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 13; i++)
    {
        cout << endl << endl << "Weight Class " << i + 1 << " winners:" << endl<<endl;
        for (Wrestler* wrestler : this->firstPlaceWrestlers)
        {
            if (wrestler->getWeightClass() == i+1)
            {
                cout << "1st Place: " << endl; wrestler->display(results);
            }
        }
        for (Wrestler* wrestler : this->secondPlaceWrestlers)
        {
            if (wrestler->getWeightClass() == i+1)
            {
                cout << "2nd Place: " << endl; wrestler->display(results);
            }
        }
        for (Wrestler* wrestler : this->thirdPlaceWrestlers)
        {
            if (wrestler->getWeightClass() == i+1)
            {
                cout << "3rd Place: " << endl; wrestler->display(results);
            }
        }
    }
}
