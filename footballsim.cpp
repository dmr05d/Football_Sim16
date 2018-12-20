/*
  This is an attempt to make a realistic and detailed 
  football simulation-> It isn't meant to be a game but
  to play out a game player by player, play by play,
  drive by drive, quarter by quarter.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "team.h"

using namespace std;

void PlayGame(Team*, Team*);
void PrintGameResults(Team*, Team*);
void PrintDownAndDistance(Team*);
void PrintFieldPosition(Team*);
void PrintTimeRemaining(Team*);
void PrintScore(Team*, Team*);
void PrintMenu(int&);
int Drive(Team*, Team*);
int PuntPlay(Team*, Team*);
int FieldGoal(Team*, Team*);
int KickOff(Team*, Team*);

int main()
{
  srand((unsigned int) time(0));
  char choice = '\0';
  int teamchoice = '\0';

  // Add function to print teams available to choose->

  Team* homeTeam = 0, * awayTeam = 0;

  do
  {
    PrintMenu(teamchoice);

    homeTeam = new Team(teamchoice);

    PrintMenu(teamchoice);
			
    awayTeam = new Team(teamchoice);

    cout << awayTeam->getTeamname() << " vs. "
	 << homeTeam->getTeamname() << "\n";
    cin.get();

    //Team homeTeam(1), awayTeam(2);

    do
    {	
      PlayGame(homeTeam, awayTeam);

      cout << "Rematch? Enter 'n' to quit: ";
      cin >> choice;

    }while(choice != 'n');

    cout << "Play again? Enter 'n' to quit: ";
    cin >> choice;

    delete awayTeam;
    delete homeTeam;

    awayTeam = 0;
    homeTeam = 0;

  }while(choice != 'n');

	
  return 0;
}

void PrintMenu(int& confint)
{
  bool cinfail = false;

  do
  {
    cout << "Choose a conference\n";
    cout << "0 - ACC\n";
    cout << "1 - SEC\n";
    cout << "2 - B1G\n";
    cout << "3 - BIG12\n";
    cout << "4 - PAC12\n";
    cout << "--> ";
    cin >> confint;
    /*
    if(cin.fail())
    {
      cout << "cin.fail() triggered\n\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cinfail = true;
      continue;
    }
    */
    switch(confint)
    {
    case ACC:
      cout << "ACC:\n";
      cout << "\t0 - Florida State\n";
      cout << "\t1 - Boston College\n";
      cout << "\t2 - Clemson Tigers\n";
      cout << "\t3 - Louisville Cardinals\n";
      cout << "\t4 - Syracuse Orange\n";
      cout << "\t5 - NC State Wolfpack\n";
      cout << "\t6 - Wake Forest Deamon Deacons\n";
      cout << "\t7 - Geogia Tech Yellow Jackets\n";
      cout << "\t8 - Miami Hurricanes\n";
      cout << "\t9 - North Carolina Tar Heels\n";
      cout << "\t10 - Pittsburg Panthers\n";
      cout << "\t11 - Duke Blue Devils\n";
      cout << "\t12 - Virginia Cavaliers\n";
      cout << "\t13 - Virginia Tech Hokies\n";
      break;
    case SEC:
      cout << "SEC:\n";
      cout << "\t14 - Alabama Crimson Tide\n";
      cout << "\t15 - Auburn Tigers\n";
      cout << "\t16 - Ole Miss Rebels\n";
      cout << "\t17 - Mississippi State Bulldogs\n";
      cout << "\t18 - Texas A&M Aggies\n";
      cout << "\t19 - Arkansas Razorbacks\n";
      cout << "\t20 - LSU Tigers\n";
      cout << "\t21 - Vanderbilt Commadors\n";
      cout << "\t22 - Georgia Bulldogs\n";
      cout << "\t23 - Florida Gators\n";
      cout << "\t24 - Tennessee Volunteers\n";
      cout << "\t25 - Kentucky Wildcats\n";
      cout << "\t26 - South Carolina Gamecocks\n";
      cout << "\t27 - Missouri Tigers\n";
      break;
    default:
      //      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "There are only two choices currently. ACC or SEC.\n\n";
      break;
    }

    cinfail = false;

  }while(cinfail);

  //  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  do
  {
    cout << "--> ";
    cin >> confint;
    /*
    if(cin.fail())
    {
      cout << "cin.fail() triggered\n\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cinfail = true;
      continue;
    }
    */
    cinfail = false;
    //    cin.ignore(numeric_limits<streamsize>::max(), '\n');

  }while (cinfail);
}


void PrintScore(Team* homeTeam, Team* awayTeam)
{
  if(homeTeam->getQuarter() < 5)
    cout << "Quarter " << homeTeam->getQuarter() << "\n";
  //else
  //cout << "OT\n";

  cout << setw(30) << left << awayTeam->getTeamname() <<
    awayTeam->getScore() << "\n";
  cout << setw(30) << left << homeTeam->getTeamname() <<
    homeTeam->getScore() << "\n\n";
}

void PrintGameResults(Team* homeTeam, Team* awayTeam)
{
  cout << "\nFINAL SCORE\n\n";

  PrintScore(homeTeam, awayTeam);

  cout << setw(30) << left <<  awayTeam->getTeamname() << "pass " 
       << awayTeam->getCompletions() << "/" << awayTeam->getAttempts()
       << " " << awayTeam->getPassyards() << "\n";
  cout << setw(30) << left <<  awayTeam->getTeamname() << "run " 
       << awayTeam->getRushyards() << " yards on " << awayTeam->getRushattempts()
       << " attempts\n";
	
  cout << setw(30) << left <<  homeTeam->getTeamname() << "pass " 
       << homeTeam->getCompletions() << "/" << homeTeam->getAttempts()
       << " " << homeTeam->getPassyards() << "\n";
  cout << setw(30) << left <<  homeTeam->getTeamname() << "run " 
       << homeTeam->getRushyards() << " yards on " << homeTeam->getRushattempts()
       << " attempts\n\n";

  cout << setw(30) << left <<  awayTeam->getTeamname() << "Total Yards - " 
       << awayTeam->getTotalyards() << "\n";
  cout << setw(30) << left <<  homeTeam->getTeamname() << "Total Yards - " 
       << homeTeam->getTotalyards() << "\n\n";

  cout << setw(30) << left <<  awayTeam->getTeamname() << "First downs " <<
    awayTeam->getFirstdown() << " " << "\n";
  cout << setw(30) << left <<  homeTeam->getTeamname() << "First downs " <<
    homeTeam->getFirstdown() << " " << "\n";

  cout << setw(30) << left <<  awayTeam->getTeamname() << "Third downs " 
       << awayTeam->getThirddown() << "/" << awayTeam->getThirddownatt() << "\n";
  cout << setw(30) << left <<  homeTeam->getTeamname() << "Third downs " 
       << homeTeam->getThirddown() << "/" << homeTeam->getThirddownatt() << "\n";
	
  cout << setw(30) << left <<  awayTeam->getTeamname() << "Plays " <<
    awayTeam->getPlaycount() << " " << "\n";
  cout << setw(30) << left <<  homeTeam->getTeamname() << "Plays " <<
    homeTeam->getPlaycount() << " " << "\n\n";

  cout << setw(30) << left <<  awayTeam->getTeamname() << "Drives " <<
    awayTeam->getDrivecount() << " " << "\n";
  cout << setw(30) << left <<  homeTeam->getTeamname() << "Drives " <<
    homeTeam->getDrivecount() << " " << "\n\n";
	

  cout << "Total drives - " << homeTeam->getDrivecount() +
    awayTeam->getDrivecount() << "\n\n";
	
}

void PrintDownAndDistance(Team* offense)
{
  cout << offense->getDown();
		
  if(offense->getDown() == 1)
    cout << "st";
  if(offense->getDown() == 2)
    cout << "nd";
  if(offense->getDown() == 3)
    cout << "rd";
  if(offense->getDown() == 4)
    cout << "th";
  cout << " & " << offense->getDistance() << "\n";
	
}

void PrintFieldPosition(Team* offense)
{
  if(offense->getField() < 50)
    cout << "Ball on OWN " << offense->getField() << "\n";

  if(offense->getField() == 50)
    cout <<"Ball on the " << offense->getField() << "\n";

  if(offense->getField() > 50)
    cout <<"Ball on OPP " << 50 - (offense->getField() - 50)  << "\n";
}

void PrintTimeRemaining(Team* offense)
{
  if(offense->getTime() > 900)
  {
    cout << (offense->getTime() - 900)/60 << ":";

    if((offense->getTime() - 900) % 60 < 10)
      cout << "0";

    cout << (offense->getTime() - 900) % 60 << "\n";
  }
  else
  {
    cout << offense->getTime()/60 << ":";

    if((offense->getTime()) % 60 < 10)
      cout << "0";

    cout << offense->getTime() % 60 << "\n";
  }
}

//*******************
//*******************
//**** PLAY GAME ****
//*******************
//*******************
void PlayGame(Team * homeTeam, Team * awayTeam)
{

  bool possession = false;

  do
  {
    do
    {
      PrintScore(homeTeam, awayTeam);

      cout << "Drive Count = " << homeTeam->getDrivecount() +
	awayTeam->getDrivecount() 
	   << "\n\n";

      if(homeTeam->getTime() < 1)
	break;

      if(homeTeam->getQuarter() == 1 && homeTeam->getTime() == 1800)
	homeTeam->addScore(KickOff(awayTeam, homeTeam));

      if(homeTeam->getQuarter() == 3 && homeTeam->getTime() == 1800)
      {
	awayTeam->addDrivecount();

	if(homeTeam->getDrivecount() + awayTeam->getDrivecount() % 2 == 1)
	{
	  possession = true;

	  awayTeam->addDrivecount();
	}

	awayTeam->addScore(KickOff(homeTeam, awayTeam));

	cout << awayTeam->getTeamname() << "'s ball!\n";

	awayTeam->addScore(Drive(awayTeam, homeTeam));
      }

      if((homeTeam->getDrivecount() + awayTeam->getDrivecount()) % 2 == 0)
      {
	cout << homeTeam->getTeamname() << "'s ball!\n";

	homeTeam->addScore(Drive(homeTeam, awayTeam));

	homeTeam->addDrivecount();

	if(homeTeam->getTime() <= 0)
	  break;
      }
      else
      {
	cout << awayTeam->getTeamname() << "'s ball\n";

	awayTeam->addScore(Drive(awayTeam, homeTeam));

	awayTeam->addDrivecount();
      }
		
    }while(homeTeam->getTime() > 0);

    if(homeTeam->getQuarter() == 2)
    {
      cout << "\nHALFTIME!\n\n";

      homeTeam->resetTime(1800);
    }
	
    homeTeam->addQuarter();

  }while(homeTeam->getQuarter() < 5);

  // OVERTIME!
  if(homeTeam->getScore() == awayTeam->getScore())
  {
    cout << "OVERTIME!\n\n";

    PrintScore(homeTeam, awayTeam);

    homeTeam->resetTime(900);

    PrintTimeRemaining(homeTeam);

    while(homeTeam->getScore() == awayTeam->getScore()
	  || homeTeam->getTime() > 0)
    {
      if((homeTeam->getDrivecount() + awayTeam->getDrivecount()) % 2 == 0)
      {
	homeTeam->addScore(KickOff(awayTeam, homeTeam));

	homeTeam->addDrivecount();

	cout << homeTeam->getTeamname() << "'s ball!\n";

	PrintTimeRemaining(homeTeam);

	homeTeam->addScore(Drive(homeTeam, awayTeam));

	PrintTimeRemaining(homeTeam);
      }
      else
      {
	awayTeam->addScore(KickOff(homeTeam, awayTeam));

	awayTeam->addDrivecount();

	cout << awayTeam->getTeamname() << "'s ball!\n";

	PrintTimeRemaining(homeTeam);
					
	awayTeam->addScore(Drive(awayTeam, homeTeam));

	PrintTimeRemaining(homeTeam);
      }
    }
  }

  if(possession)
  {
    awayTeam->subDrivecount();
  }


  //Game has finished
  PrintGameResults(homeTeam, awayTeam);
	
  homeTeam->setStats();
  awayTeam->setStats();
	
}

int Drive(Team* offense, Team* defense)
{
  offense->resetDown();

  offense->resetYardstogo();

  while(offense->getDown() < 4)
  {
    if(offense->getTime() < 1)
      break;

    if(offense->getTime() < 901 && (offense->getQuarter() == 1
				    || offense->getQuarter() == 3))
    {
      offense->addQuarter();
      offense->resetTime(900);

      PrintTimeRemaining(offense);
    }

    PrintFieldPosition(offense);
		
    PrintDownAndDistance(offense);

    PrintTimeRemaining(offense);

    if(offense->playSelect())
    {
      if((offense->getYardstogo() > 14
	  && rand() % offense->getTend() > 1 && offense->getDown() == 3)
	 || (rand() % offense->getTend() > 44 && rand() % offense->getTend() < 51)
	 || (offense->getTime() < 9 && offense->getQuarter() == 4 
	     && (defense->getScore() - offense->getScore() < 8)))
      {
	offense->changeChoice('l');
	offense->Yardstogo(offense->passPlay(offense, defense));
      }
      else if(((offense->getYardstogo() > 3 && offense->getYardstogo() < 15) 
	       && rand() % offense->getTend() > 1 && offense->getDown() == 3)
	      || (rand() % offense->getTend() < 45 && rand() % offense->getTend() > 25))
      {
	offense->changeChoice('m');
	offense->Yardstogo(offense->passPlay(offense, defense));
      }
      else
      {
	offense->changeChoice('s');
	offense->Yardstogo(offense->passPlay(offense, defense));
      }
    }
    else
    {
      offense->Yardstogo(offense->runPlay(offense, defense));
    }

    if((offense->getQuarter() == 2 || offense->getQuarter() == 4) && offense->getTime() < 300)
      offense->addTime(2);
    else
      offense->addTime(5);

    if(offense->getDown() == 3)
      offense->addThirddownatt();

    if(offense->getYardstogo() <= 0)
    {
      if(offense->getDown() == 3)
	offense->addThirddown();

      offense->addFirstdown();

      offense->resetDown();
			
      offense->resetYardstogo();
    }
    else
      offense->addDown();

    offense->addField(offense->getYardsgained());

    if(offense->getField() > 99)
      break;

    cout << "\n";
  }

  if(offense->getField() > 99)
  {	
    cout << "TOUCHDOWN " << offense->getTeamname() << "!\n\n";
    if(rand() % 90 < offense->getSpecialTeams())
    {
      offense->addPlaycount();

      defense->addScore(KickOff(offense, defense));

      return 7;
    }
    else
    {
      offense->addPlaycount();

      cout << "Extra Point MISSED!\n\n";

      defense->addScore(KickOff(offense, defense));

      return 6;
    }
			
  }

  else if(offense->getField() < 100 && ((offense->getField() > 53
					 && offense->getSpecialTeams() >= 95) 
					|| (offense->getField() > 65
					    && offense->getSpecialTeams() >= 75)
					|| (offense->getField() > 80)))
  {	
    if(offense->getTime() < 1)
      return 0;

    return FieldGoal(offense, defense);
  }
  else
  {	
    if(offense->getTime() < 1)
      return 0;

    defense->addScore(PuntPlay(offense, defense));

    return 0;
  }
}

int FieldGoal(Team* offense, Team* defense)
{
  if(rand() % 99 < 95 && offense->getField() >= 75)
  {			
    PrintFieldPosition(offense);

    PrintTimeRemaining(offense);
			
    PrintDownAndDistance(offense);

    cout << 117 - offense->getField() << " yard FIELD GOAL\n\n";

    offense->addPlaycount();

    offense->addTime(6);

    defense->addScore(KickOff(offense, defense));

    return 3;
  }
  else if(rand() % offense->getSpecialTeams() > 15 
	  && offense->getField() > 67 && offense->getField() < 75)
  {			
    PrintFieldPosition(offense);

    PrintTimeRemaining(offense);
			
    PrintDownAndDistance(offense);

    offense->resetYardstogo();

    cout << 117 - offense->getField() << " yard FIELD GOAL\n\n";

    offense->addPlaycount();

    offense->addTime(6);
			
    defense->addScore(KickOff(offense, defense));

    return 3;
  }
  else if(rand() % offense->getSpecialTeams() > 45
	  && offense->getField() > 57 && offense->getField() <= 67)
  {			
    PrintFieldPosition(offense);

    PrintTimeRemaining(offense);
			
    PrintDownAndDistance(offense);

    offense->resetYardstogo();

    cout << 117 - offense->getField() << " yard FIELD GOAL\n\n";

    offense->addPlaycount();

    offense->addTime(6);
			
    defense->addScore(KickOff(offense, defense));

    return 3;
  }
  else 
  {
    PrintFieldPosition(offense);

    PrintTimeRemaining(offense);
			
    PrintDownAndDistance(offense);

    offense->resetYardstogo();
			
    cout << 117 - offense->getField() << " yard FIELD GOAL missed!\n\n";

    offense->flipField(0);

    offense->addPlaycount();

    offense->addTime(6);

    return 0;
  }
}


int PuntPlay(Team* offense, Team* defense)
{
  PrintFieldPosition(offense);

  if(offense->getTime() < 1)
    return 0;
	
  PrintDownAndDistance(offense);

  cout << "PUNT!\n";

  offense->addPlaycount();
		
  PrintTimeRemaining(offense);

  int hold; // to hold the length of the punt->

  if(offense->getField() > 50)
  {
    hold = (rand() % (50 - (50 - offense->getField()))) + 10;
		
    offense->flipField(hold);
  }
  else if(rand() % offense->getSpecialTeams() < 5)
  {
    hold = (rand() % 16 + 15);
		
    offense->flipField(hold);
  }
  else
  {
    hold = (rand() % 16 + 35);
		
    offense->flipField(hold);
  }

  cout << hold << " yard punt by " << offense->getTeamname() << "->\n\n";

  if(offense->getField() < 1)
  {
    cout << "TOUCHBACK!\n";

    cout << "Ball goes to the 20 yard line->\n\n";

    offense->setField(20);
		
    offense->addTime(9);
		
    return 0;
  }

  if((rand() % offense->getSpecialTeams() - rand() % defense->getSpecialTeams()) < 0)
  {			
    offense->addTime(9);
		
    return 0;
  }

  else if((rand() % offense->getSpecialTeams() - rand() % defense->getSpecialTeams()) > 0)
  {
    PrintFieldPosition(offense);

    hold = (rand() % offense->getSpecialTeams());
		
    offense->addField(hold);

    cout << hold << " yard PUNT RETURN!\n\n";
		
    if(offense->getField() > 99)
    {
      cout << "TOUCHDOWN " << defense->getTeamname() << "!\n\n";

      defense->addDrivecount();

      offense->addTime(15);

      if(rand() % 99 < defense->getSpecialTeams())
      {
	defense->addScore(7);

	offense->addScore(KickOff(defense, offense));

	return 0;
      }
      else
      {
	defense->addScore(6);

	cout << "MISSED extra point\n\n";

	offense->addScore(KickOff(defense, offense));

	return 0;
      }
    }
    return 0;
  }
	
  return 0;
}

int KickOff(Team* kickingTeam, Team* receivingTeam)
{
  int hold = 0;

  kickingTeam->setField(70);

  if(kickingTeam->getTime() < 1)
    return 0;

  if(rand() % kickingTeam->getSpecialTeams() > 3)
    hold = (-1) * (rand() % 18 + 62);
  else
  {
    kickingTeam->setField(40);

    cout << "PENALTY! Kick out of bounds by " << kickingTeam->getTeamname() 
	 << "-> Ball will be placed at the " << kickingTeam->getField()
	 << " yard line->\n\n";

    PrintDownAndDistance(kickingTeam);

    return 0;
  }

  if(kickingTeam->getField() + hold < 1)
  {
    cout << abs(hold) << " yard kickoff by "
	 << kickingTeam->getTeamname() << "->\n";
    cout << "TOUCHBACK!\n\n";
    cout << "Ball goes to the 20 yard line->\n\n";

    kickingTeam->setField(20);

    return 0;
  }
  else
  {
    cout << abs(hold) << " yard kickoff by " << kickingTeam->getTeamname()
	 << "->\n";

    kickingTeam->addField(hold);

    hold = rand() % receivingTeam->getSpecialTeams() + 10;

    kickingTeam->addField(hold);

    if(kickingTeam->getField() > 99)
    {
      cout << receivingTeam->getTeamname() << " " << hold 
	   << " yard kickoff return for a TOUCHDOWN!\n\n";

      receivingTeam->addDrivecount();
			
      if(rand() % 99 < receivingTeam->getSpecialTeams())
      {
	receivingTeam->addScore(7);

	kickingTeam->addTime(14);

	kickingTeam->addScore(KickOff(receivingTeam, kickingTeam));

	return 0;
      }
      else
      {
	receivingTeam->addScore(6);
				
	cout << "MISSED extra point\n\n";
				
	kickingTeam->addTime(14);

	kickingTeam->addScore(KickOff(receivingTeam, kickingTeam));

	return 0;
      }
    }
    else
    {
      cout << hold << " yard kickoff return by "
	   << receivingTeam->getTeamname()
	   << "->\n\n";

      kickingTeam->addTime(9);

      PrintFieldPosition(kickingTeam);

      return 0;
    }
  }
}
