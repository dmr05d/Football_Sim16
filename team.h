#ifndef TEAM_H
#define TEAM_H

using namespace std;
// This class holds the values for a team and determines the outcome
// of plays the team runs.


enum conference {ACC = 0, SEC = 1, B1G = 2, BIG12 = 3, PAC12 = 4,
		 CUSA = 5, MAC = 6, WAC = 7, AAC = 8, MWC = 9, IND = 10,
		 SUN = 11, FCS = 12};
		
enum division {ATLANTIC, COASTAL, EAST, WEST, NORTH, SOUTH};

class Team
{
 private:
  static int yardstogo, down, quarter, field, timeremaining;
  static char choice;

  string teamName;

  conference conf;
  division div;
		
  int tendency, qbr, rbr, wrr, offline;
		
  int defpass, defline, spclteams;
		
  int yardsgained, completions, attempts,
    rushattempts, rushyards, passyards;
		
  int playcount, thirddown, firstdown, 
    thirddownatt, score, drivecount;

  int wins, losses, confwins, conflosses;

  static void RunClock(Team *);

 public:
  Team();
  Team(int);

  ~Team();

  void setAttributes(int, int, int, int, int, int);
  bool playSelect();

  // pass and run play returns yards gained.
  int passPlay(Team*, Team*);
  int runPlay(Team*, Team*);

  //Mutators
  void setStats()
  { rushyards = 0; completions = 0; attempts = 0; passyards = 0;
    rushattempts = 0; thirddown = 0; thirddownatt = 0; firstdown = 0;
    playcount = 0; score = 0; drivecount = 0; timeremaining = 1800;
    quarter = 1; };

  void addScore(int points)
  { score += points; };

  void addDrivecount()
  { drivecount++; };

  void subDrivecount()
  { drivecount--; };

  void resetDown()
  { down = 1; };

  void resetYardstogo()
  { yardstogo = 10; };

  void addDown()
  { down++; };

  void addQuarter()
  { quarter++; };
		
  void Yardstogo(int yardsgained)
  { yardstogo -= yardsgained; };

  void addField(int add)
  { field += add; };

  void flipField(int hold)
  { field = 100 - (field + hold); };

  void setField(int yardline)
  { field = yardline; };

  void addTime(int elapsed)
  { timeremaining -= elapsed; };

  void resetTime(int reset)
  { timeremaining = reset; };

  void changeChoice(char newchoice)
  { choice = newchoice; };

  void addPlaycount()
  { playcount++; }

  void addThirddown()
  { thirddown++; };

  void addFirstdown()
  { firstdown++; };
		
  void addThirddownatt()
  { thirddownatt++; };

  //Accessors
  string getTeamname()
  { return teamName; };

  int getScore()
  { return score; };

  int getYardstogo()
  { return yardstogo; };
		
  int getTend()
  { return tendency; };
		
  int getQBR()
  { return qbr; };
		
  int getRBR()
  { return rbr; };

  int getWRR()
  { return wrr; };

  int getOffline()
  { return offline; };

  int getDefpass()
  { return defpass; };

  int getDefline()
  { return defline; };

  int getSpecialTeams()
  { return spclteams; };

  int getAttempts()
  { return attempts; };

  int getCompletions()
  { return completions; };
		
  int getRushattempts()
  { return rushattempts; };

  int getRushyards()
  { return rushyards; };

  int getPassyards()
  { return passyards; };

  int getYardsgained()
  { return yardsgained; };

  int getTotalyards()
  { return rushyards + passyards; };
		
  int getFirstdown()
  { return firstdown; };
		
  int getThirddown()
  { return thirddown; };

  int getThirddownatt()
  { return thirddownatt; };
		
  int getPlaycount()
  { return playcount; };

  int getDrivecount()
  { return drivecount; };

  int getDown()
  { return down; };

  int getDistance()
  { return yardstogo; };

  int getQuarter()
  { return quarter; };

  int getField()
  { return field; };

  int getTime()
  { return timeremaining; };

  char getChoice()
  { return choice; };

};

#endif
