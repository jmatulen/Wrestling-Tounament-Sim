
#include "Match.h"
#include <iostream>
#include <iomanip>
using weightClasses = std::priority_queue<Wrestler*, std::vector<Wrestler*>, compareAbilityScore>;
int Match::conductWrestlingMatch(Team* team1, Team* team2, std::ostream& outs)
{
    weightClasses currWeightClassTeam1;
    weightClasses currWeightClassTeam2;
    
            outs << "|***************************************|***************************************|" << "*****************|*****************|" << std::endl
                << std::left << std::setw(WIDTH_LABEL)
                << "|TEAM" << "  :"
                << std::right << std::setw(WIDTH_VALUE)
                << team1->getTeamID() << " | "
                << std::left << std::setw(WIDTH_LABEL)
                << "TEAM" << " :"
                << std::right << std::setw(WIDTH_VALUE)
                << team2->getTeamID() << "|"
                << std::left << std::setw(11)
                << "TEAM" << team1->getTeamID()
                << std::right << std::setw(5)
                << "| "
                << std::left << std::setw(10)
                << "TEAM" << team2->getTeamID()
                << std::right << std::setw(4)
                << "|" << "\n"
                << "|***************************************|***************************************|" << "*****************|*****************|" << std::endl;

    for (int i = 0; i < 13; i++)
    {
        int sizeDiff, newPoints = 0;
        currWeightClassTeam1 = team1->team[i];
        currWeightClassTeam2 = team2->team[i];

        Wrestler* currWrestler1 = new Wrestler(*currWeightClassTeam1.top());
        Wrestler* currWrestler2 = new Wrestler(*currWeightClassTeam2.top());

        if (currWeightClassTeam1.size() == currWeightClassTeam2.size())
        {
            for (int i = 0; i < currWeightClassTeam1.size(); i++)
            {
                bout(currWrestler1, currWrestler2, team1, team2, outs);
                currWeightClassTeam1.pop();
                currWeightClassTeam2.pop();
                currWrestler1 = currWeightClassTeam1.top();
                currWrestler2 = currWeightClassTeam2.top();
            }
        }
        switch (currWeightClassTeam1.size() > currWeightClassTeam2.size())
        {
        case true :
            for (int i = 0; i < currWeightClassTeam2.size(); i++)
            {
                bout(currWrestler1, currWrestler2, team1, team2, outs);
                currWeightClassTeam1.pop();
                currWeightClassTeam2.pop();
                currWrestler1 = currWeightClassTeam1.top();
                currWrestler2 = currWeightClassTeam2.top();
            }
            sizeDiff = currWeightClassTeam1.size() - currWeightClassTeam2.size();
            //addToTeamPoints(team1, sizeDiff * 6);//add points due to forfeit
            newPoints = (sizeDiff * 6);
            team1->addTeamPoints(newPoints);
            outs << "|Team " << team1->getTeamID() << " recieves: " << newPoints << " points due to forfeits in weight class " << i + 1 << std::endl << std::endl;
            break;
        case false:
            for (int i = 0; i < currWeightClassTeam1.size(); i++)
            {
                bout(currWrestler1, currWrestler2, team1, team2, outs);
                currWeightClassTeam1.pop();
                currWeightClassTeam2.pop();
                currWrestler1 = currWeightClassTeam1.top();
                currWrestler2 = currWeightClassTeam2.top();
            }
            sizeDiff = currWeightClassTeam2.size() - currWeightClassTeam1.size();
            //addToTeamPoints(team2, sizeDiff * 6);//add points due to forfeit
            newPoints = (sizeDiff * 6);
            team2->addTeamPoints(newPoints);
            outs << "|Team " << team2->getTeamID() << " recieves: " << newPoints << " points due to forfeits in weight class "<< i + 1 << std::endl << std::endl;
            break;
        }
      
    }
    if (team1->getTeamPoints() > team2->getTeamPoints()) { team1->addTeamWin(); }
    else { team2->addTeamWin(); }
    std::cout <<
        std::left << std::setw(10)
        << "TEAM "<< team1->getTeamID() <<" FINAL SCORE" << ":"
        << std::right << std::setw(5)
        << team1->getTeamPoints() << " | "
        << std::left << std::setw(10)
        << "TEAM " << team2->getTeamID() << " FINAL SCORE" << ":"
        << std::right << std::setw(5)
        << team2->getTeamPoints() << "|" << "\n";
    return 0;
}


void Match::bout(Wrestler* wrestler0, Wrestler* wrestler1, Team* team0, Team* team1, std::ostream& outs) 
{
    int victoryMargin;
    int points;
    int wrestler0Performance = wrestler0->wrestle(wrestler0->getAbilityScore());
    int wrestler1Performance = wrestler1->wrestle(wrestler1->getAbilityScore());

    wrestler0->setWinStatus(false);
    wrestler1->setWinStatus(false);

    if (wrestler0Performance > wrestler1Performance)
    {
        victoryMargin = wrestler0Performance - wrestler1Performance;
        points = calculatePoints(victoryMargin);
        outs << "|Wrestler "<<wrestler0->getID()<<" Wins by: " << victoryMargin <<". Points given to Team " << team0->getTeamID() << ": "<< points << std::endl;
        team0->addTeamPoints(points);
        wrestler0->addToWin(wrestler1->getID());
        wrestler0->setWinStatus(true);
        wrestler1->addLosses(1);
        displayBoutResults(outs, wrestler0, wrestler1, team0, team1);
    }
    else if (wrestler1Performance > wrestler0Performance)
    {
        victoryMargin = wrestler1Performance - wrestler0Performance;
        points = calculatePoints(victoryMargin);
        outs << "|Wrestler " << wrestler1->getID() << " Wins by: " << victoryMargin << ". Points given to Team " << team1->getTeamID() << ": " << points << std::endl;
        team1->addTeamPoints(points);
        wrestler1->addToWin(wrestler0->getID());
        wrestler1->setWinStatus(true);
        wrestler0->addLosses(1);
        displayBoutResults(outs, wrestler0, wrestler1, team0, team1);
    }
}

int Match::calculatePoints(const int& victoryMargin)
{
    if (victoryMargin == 0) { return 0; }
    else if (isInRange(victoryMargin, 1, 7)) { return 3; }
    else if (isInRange(victoryMargin, 8, 14)) { return 4; }
    else if (isInRange(victoryMargin, 15, 21)) { return 5; }
    else if (isInRange(victoryMargin, 22, 999)) { return 6; }    //upper bound must be high enough to properly deal with large victory margins, like in forfeited matches.
}   
void Match::addToTeamPoints(Team* teamRecieveingPoints, int points)
{
    teamRecieveingPoints->addTeamPoints(points);
}
bool Match::isInRange(const int& value, const int& low, const int& high) {
    return !(value < low) && !(high < value);
}
void Match::displayBoutResults(std::ostream& outs, Wrestler* wrestler0, Wrestler* wrestler1, Team* team0, Team* team1)
{
    outs << std::left << std::setw(WIDTH_LABEL)
        << "|id" << "  :"
        << std::right << std::setw(WIDTH_VALUE)
        << wrestler0->getID() << " | "
        << std::left << std::setw(WIDTH_LABEL)
        << "id" << " :"
        << std::right << std::setw(WIDTH_VALUE)
        << wrestler1->getID() << "|" << "\n"

        << std::left << std::setw(WIDTH_LABEL)
        << "|Team_ID" << "  :"
        << std::right << std::setw(WIDTH_VALUE)
        << wrestler0->getTeamID() << " | "
        << std::left << std::setw(WIDTH_LABEL)
        << "Team_ID" << " :"
        << std::right << std::setw(WIDTH_VALUE)
        << wrestler1->getTeamID() << "|" << "\n"

        << std::left << std::setw(WIDTH_LABEL)
        << "|weight" << "  :"
        << std::right << std::setw(WIDTH_VALUE)
        << wrestler0->getWeight() << " | "
        << std::left << std::setw(WIDTH_LABEL)
        << "weight" << " :"
        << std::right << std::setw(WIDTH_VALUE)
        << wrestler1->getWeight() << "|" << "\n"

        << std::left << std::setw(WIDTH_LABEL)
        << "|weight class" << " :"
        << std::right << std::setw(WIDTH_VALUE)
        << wrestler0->getWeightClass() << " | "
        << std::left << std::setw(WIDTH_LABEL)
        << "weight class" << " :"
        << std::right << std::setw(WIDTH_VALUE)
        << wrestler1->getWeightClass() << "|" << "\n"

        << std::left << std::setw(WIDTH_LABEL)
        << "|ability_score" << ":"
        << std::right << std::setw(WIDTH_VALUE)
        << wrestler0->getAbilityScore() << " | "
        << std::left << std::setw(WIDTH_LABEL)
        << "ability_score" << ":"
        << std::right << std::setw(WIDTH_VALUE)
        << wrestler1->getAbilityScore() << "|" << "\n"

        << std::left << std::setw(WIDTH_LABEL)
        << "|wins" << "  :"
        << std::right << std::setw(WIDTH_VALUE)
        << wrestler0->getWins() << " | "
        << std::left << std::setw(WIDTH_LABEL)
        << "wins" << " :"
        << std::right << std::setw(WIDTH_VALUE)
        << wrestler1->getWins() << "|" << "\n"

        << std::left << std::setw(WIDTH_LABEL)
        << "|losses" << "  :"
        << std::right << std::setw(WIDTH_VALUE)
        << wrestler0->getLosses() << " | "
        << std::left << std::setw(WIDTH_LABEL)
        << "losses" << " :"
        << std::right << std::setw(WIDTH_VALUE)
        << wrestler1->getLosses() << "|" <<

        std::left << std::setw(10)
        << "TEAM SCORE" << ":"
        << std::right << std::setw(5)
        << team0->getTeamPoints() << " | "
        << std::left << std::setw(10)
        << "TEAM SCORE" << ":"
        << std::right << std::setw(5)
        << team1->getTeamPoints() << "|" << "\n" <<

        "|***************************************|***************************************|*****************|*****************|"
        << std::endl;
}
void Match::conductSingleBout(Team* team1, Team* team2, std::ostream& outs)
{
    weightClasses currWeightClassTeam1;
    weightClasses currWeightClassTeam2;

    outs << "|***************************************|***************************************|" << "*****************|*****************|" << std::endl
        << std::left << std::setw(WIDTH_LABEL)
        << "|TEAM" << "  :"
        << std::right << std::setw(WIDTH_VALUE)
        << team1->getTeamID() << " | "
        << std::left << std::setw(WIDTH_LABEL)
        << "TEAM" << " :"
        << std::right << std::setw(WIDTH_VALUE)
        << team2->getTeamID() << "|"
        << std::left << std::setw(10)
        << "SCORE" << ":"
        << std::right << std::setw(5)
        << team1->getTeamPoints() << " | "
        << std::left << std::setw(10)
        << "SCORE" << ":"
        << std::right << std::setw(5)
        << team2->getTeamPoints() << "|" << "\n"
        << "|***************************************|***************************************|" << "*****************|*****************|" << std::endl;

        int sizeDiff = 0;
        currWeightClassTeam1 = team1->team[0];
        currWeightClassTeam2 = team2->team[0];

        Wrestler* currWrestler1 = new Wrestler(*currWeightClassTeam1.top());
        Wrestler* currWrestler2 = new Wrestler(*currWeightClassTeam2.top());

        if (currWeightClassTeam1.size() == currWeightClassTeam2.size())
        {
                bout(currWrestler1, currWrestler2, team1, team2, outs);
                currWeightClassTeam1.pop();
                currWeightClassTeam2.pop();
                currWrestler1 = currWeightClassTeam1.top();
                currWrestler2 = currWeightClassTeam2.top();
        }
        switch (currWeightClassTeam1.size() > currWeightClassTeam2.size())
        {
        case true:
                bout(currWrestler1, currWrestler2, team1, team2, outs);
                currWeightClassTeam1.pop();
                currWeightClassTeam2.pop();
                currWrestler1 = currWeightClassTeam1.top();
                currWrestler2 = currWeightClassTeam2.top();
                sizeDiff = currWeightClassTeam1.size() - currWeightClassTeam2.size();
                addToTeamPoints(team1, sizeDiff * 6);
                break;
        case false:
                bout(currWrestler1, currWrestler2, team1, team2, outs);
                currWeightClassTeam1.pop();
                currWeightClassTeam2.pop();
                currWrestler1 = currWeightClassTeam1.top();
                currWrestler2 = currWeightClassTeam2.top();
                sizeDiff = currWeightClassTeam2.size() - currWeightClassTeam1.size();
                 addToTeamPoints(team2, sizeDiff * 6);
                 break;
        }
}