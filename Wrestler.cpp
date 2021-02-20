

#include <iomanip>
#include "Wrestler.h"


void Wrestler::display(std::ostream& outs) const
{
    outs << std::left << std::setw(WIDTH_LABEL)
        << "id" << " :"
        << std::right << std::setw(WIDTH_VALUE)
        << getID() << "\n"
        << std::left << std::setw(WIDTH_LABEL)
        << "Team_ID" << " :"
        << std::right << std::setw(WIDTH_VALUE)
        << getTeamID() << "\n"
        << std::left << std::setw(WIDTH_LABEL)
        << "weight" << " :"
        << std::right << std::setw(WIDTH_VALUE)
        << getWeight() << "\n"
        << std::left << std::setw(WIDTH_LABEL)
        << "weight class" << " :"
        << std::right << std::setw(WIDTH_VALUE)
        << getWeightClass() << "\n"
        << std::left << std::setw(WIDTH_LABEL)
        << "ability_score" << ":"
        << std::right << std::setw(WIDTH_VALUE)
        << getAbilityScore() << "\n"
        << std::left << std::setw(WIDTH_LABEL)
        << "wins" << " :"
        << std::right << std::setw(WIDTH_VALUE)
        << getWins() << "\n"
        << std::left << std::setw(WIDTH_LABEL)
        << "losses" << " :"
        << std::right << std::setw(WIDTH_VALUE)
        << getLosses() << "\n" << "\n";
}
std::ostream& operator<<(std::ostream& outs, const Wrestler& prt)
{
    prt.display(outs);
    return outs;
}
int Wrestler::wrestle(int abilityScore)
{
    if (abilityScore == 0)
    {
        return 0;
    }
    std::normal_distribution<float>   wrestlePerformance(abilityScore, 15.0);
    std::random_device boutPerformance;
    std::default_random_engine generator(boutPerformance());
    return (int) round(wrestlePerformance(generator));
}
int Wrestler::getTeamID() const
{
    return _TeamID;
}
void Wrestler::setTeamID(int new_Team_ID)
{
    this->_TeamID = new_Team_ID;
}
int Wrestler::getID() const
{
    return _id;
}
void Wrestler::setID(int new_id)
{
    this->_id = new_id;
}
int Wrestler::getAbilityScore() const
{
    return _abilityScore;
}
void Wrestler::setAbilityScore()
{
    std::normal_distribution<float> distribution(100.0, 15.0);
    std::random_device ability;
    std::default_random_engine generator(ability());
    this->_abilityScore = (int) round(distribution(generator));
}
void Wrestler::setWeight(double mean, double stdv)
{
    std::random_device weight;
    std::normal_distribution<double> dist(mean, stdv);
    this->_weight = dist(weight);
}
double Wrestler::getWeight() const
{
    return _weight;
}
int Wrestler::getWins() const
{
    return beatenWrestlers.size();
}
int Wrestler::getLosses() const
{
    return _losses;
}
void Wrestler::addLosses(int lossNumber)
{
    this->_losses = _losses+lossNumber;
}
void Wrestler::addToWin(int beatenWrestlerID)
{
    this->beatenWrestlers.push_back(beatenWrestlerID);
}
void Wrestler::setWeightClass()//randomly sets weight based on randomly selected weightclass
{
    switch (this->_weightClass = rand() % 13 + 1)//randomly set weightclass of wrestler, 
                                                 // then genereate respective weight (using normal distribution).
                                                 //Each normal distribution for each weight class has a specific mean and stdv,
                                                 // which are accurate for each weightclass, based on actual data.
    {
    case 1 :
        setWeight(101.5, 1.2);
        break;
    case 2 :
        setWeight(108.5, 1.2);
        break;
    case 3 :
        setWeight(113.5, 1.2);
        break;
    case 4:
        setWeight(120.0, 1.2);
        break;
    case 5 :
        setWeight(126.5, 1.2);
        break;
    case 6 :
        setWeight(132.5, 1.2);
        break;
    case 7 :
        setWeight(139.0, 1.5);
        break;
    case 8 :
        setWeight(145.5, 1.5);
        break;
    case 9 :
        setWeight(153.0, 1.7);
        break;
    case 10:
        setWeight(162.5, 2.0);
        break;
    case 11:
        setWeight(175.0, 3.3);
        break;
    case 12:
        setWeight(194.0, 5.0);
        break;
    case 13:
        setWeight(237.5, 10.9);
        break;

    default:
        break;
    }
}
int Wrestler::getWeightClass() const
{
    return _weightClass;
}
void Wrestler::setPlace(const int& place)
{
    this->_place = place;
}
int Wrestler::getPlace()
{
    return _place;
}
bool Wrestler::getWinStatus()
{
    return _winStatus;
}
void Wrestler::setWinStatus(bool status)
{
    this->_winStatus = status;
}
