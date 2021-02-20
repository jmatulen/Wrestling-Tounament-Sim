
#pragma once
#include "Team.h"

class Match {
	friend class Tournament;
	private:

	protected:
		static constexpr int WIDTH_LABEL = 12;  ///< Label Output Width
		static constexpr int WIDTH_VALUE = 24;  ///< Value Output Width
	public:
		Match() = default;
		virtual ~Match() = default;
		void conductSingleBout(Team* team1, Team* team2, std::ostream& outs);
		int conductWrestlingMatch(Team* team1, Team* team2, std::ostream& outs);
		bool isInRange(const int& value, const int& low, const int& high);
		void displayBoutResults(std::ostream& outs, Wrestler* wrestler0, Wrestler* wrestler1, Team* team0, Team* team1);
		int calculatePoints(const int& victoryMargin);
		void addToTeamPoints(Team* teamRecievingpoints, int points);
        void bout(Wrestler* wrestler0, Wrestler* wrestler1, Team* team0, Team* team1, std::ostream& outs);
};