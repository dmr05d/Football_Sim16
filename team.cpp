
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include "team.h"

int Team::yardstogo = 10, Team::down = 1, Team::quarter = 1, 
  Team::field = 35, Team::timeremaining = 1800;
char Team::choice = '\0';
	
void Team::RunClock(Team * offense)
{
  if(offense->getTend() <= 25)
    offense->addTime(65);
  else if(offense->getTend() > 25 && offense->getTend() < 40)
    offense->addTime(58);
  else if(offense->getTend() >= 40 && offense->getTend() < 55)
    offense->addTime(53);
  else if(offense->getTend() >= 55 && offense->getTend() < 70)
    offense->addTime(49);
  else if(offense->getTend() >= 70 && offense->getTend() < 85)
    offense->addTime(46);
  else
    offense->addTime(42);
}


using namespace std;

Team::Team(int teamchoice)
{// Initialize values for temp team.
  switch(teamchoice)
  {
  case 0:
    cout << "You chose Florida State! Go NOLES!!!\n\n";
    teamName = "Florida State Seminoles";
    conf = ACC;
    div = ATLANTIC;
    tendency = 65;
    qbr = 95;
    rbr = 99;
    wrr = 92;
    offline = 80;
    defpass = 85;
    defline = 95;
    spclteams = 80;
    break;
	
  case 1:
    teamName = "Boston College Eagles";
    conf = ACC;
    div = ATLANTIC;
    tendency = 35;
    qbr = 60;
    rbr = 84;
    wrr = 64;
    offline = 86;
    defpass = 67;
    defline = 73;
    spclteams = 79;
    break;

  case 2:
    teamName = "Clemson Tigers";
    conf = ACC;
    div = ATLANTIC;
    tendency = 75;
    qbr = 87;
    rbr = 88;
    wrr = 85;
    offline = 86;
    defpass = 82;
    defline = 89;
    spclteams = 85;
    break;

  case 3:
    teamName = "Louisville Cardinals";
    conf = ACC;
    div = ATLANTIC;
    tendency = 75;
    qbr = 87;
    rbr = 81;
    wrr = 79;
    offline = 77;
    defpass = 77;
    defline = 78;
    spclteams = 80;
    break;

  case 4:
    teamName = "Syracuse Orange";
    conf = ACC;
    div = ATLANTIC;
    tendency = 75;
    qbr = 62;
    rbr = 58;
    wrr = 56;
    offline = 55;
    defpass = 61;
    defline = 55;
    spclteams = 70;
    break;

  case 5:
    teamName = "NC State Wolfpack";
    conf = ACC;
    div = ATLANTIC;
    tendency = 70;
    qbr = 74;
    rbr = 71;
    wrr = 72;
    offline = 71;
    defpass = 75;
    defline = 75;
    spclteams = 70;
    break;

  case 6:
    teamName = "Wake Forest Deamon Deacons";
    conf = ACC;
    div = ATLANTIC;
    tendency = 55;
    qbr = 65;
    rbr = 60;
    wrr = 65;
    offline = 60;
    defpass = 60;
    defline = 60;
    spclteams = 65;
    break;

  case 7:
    teamName = "Geogia Tech Yellow Jackets";
    conf = ACC;
    div = COASTAL;
    tendency = 25;
    qbr = 68;
    rbr = 79;
    wrr = 67;
    offline = 85;
    defpass = 65;
    defline = 71;
    spclteams = 65;
    break;

  case 8:
    teamName = "Miami Hurricanes";
    conf = ACC;
    div = COASTAL;
    tendency = 55;
    qbr = 77;
    rbr = 75;
    wrr = 76;
    offline = 74;
    defpass = 78;
    defline = 77;
    spclteams = 78;
    break;

  case 9:
    teamName = "North Carolina Tar Heels";
    conf = ACC;
    div = COASTAL;
    tendency = 70;
    qbr = 82;
    rbr = 76;
    wrr = 77;
    offline = 75;
    defpass = 72;
    defline = 76;
    spclteams = 81;
    break;

  case 10:
    teamName = "Pittsburg Panthers";
    conf = ACC;
    div = COASTAL;
    tendency = 65;
    qbr = 72;
    rbr = 76;
    wrr = 69;
    offline = 69;
    defpass = 69;
    defline = 67;
    spclteams = 65;
    break;

  case 11:
    teamName = "Duke Blue Devils";
    conf = ACC;
    div = COASTAL;
    tendency = 65;
    qbr = 70;
    rbr = 69;
    wrr = 68;
    offline = 67;
    defpass = 69;
    defline = 67;
    spclteams = 64;
    break;

  case 12:
    teamName = "Virginia Cavaliers";
    conf = ACC;
    div = COASTAL;
    tendency = 55;
    qbr = 68;
    rbr = 72;
    wrr = 69;
    offline = 67;
    defpass = 67;
    defline = 67;
    spclteams = 68;
    break;

  case 13:
    teamName = "Virginia Tech Hokies";
    conf = ACC;
    div = COASTAL;
    tendency = 55;
    qbr = 75;
    rbr = 72;
    wrr = 69;
    offline = 70;
    defpass = 71;
    defline = 73;
    spclteams = 71;
    break;

  case 14:
    teamName = "South Florida Bulls";
    conf = CUSA;
    div = EAST;
    tendency = 75;
    qbr = 70;
    rbr = 72;
    wrr = 69;
    offline = 70;
    defpass = 69;
    defline = 67;
    spclteams = 71;
    break;

  case 15:
    teamName = "Ole Miss Rebels";
    conf = SEC;
    div = WEST;
    tendency = 70;
    qbr = 81;
    rbr = 77;
    wrr = 79;
    offline = 78;
    defpass = 78;
    defline = 79;
    spclteams = 75;
    break;

  case 16:
    teamName = "Charleston Southern Bucs";
    conf = FCS;
    tendency = 75;
    qbr = 55;
    rbr = 65;
    wrr = 55;
    offline = 55;
    defpass = 55;
    defline = 55;
    spclteams = 55;
    break;

  case 23:
    cout << "You chose uf.\n\n";
    teamName = "Florida Gators";
    conf = SEC;
    div = EAST;
    tendency = 40;
    qbr = 65;
    rbr = 77;
    wrr = 74;
    offline = 75;
    defpass = 82;
    defline = 84;
    spclteams = 65;
    break;

  default:
    cout << "You made an invalid choice.";
    cout << "Defaulting to Florida State! Go NOLES!!!\n\n";
    teamName = "Florida State Seminoles";
    conf = ACC;
    div = ATLANTIC;
    tendency = 65;
    qbr = 95;
    rbr = 99;
    wrr = 92;
    offline = 80;
    defpass = 85;
    defline = 95;
    spclteams = 80;
    break;
  }

  wins = 0;
  losses = 0;
  confwins = 0;
  conflosses = 0;
  //ties = 0;
  score = 0;
  yardsgained = 0;
  completions = 0;
  attempts = 0;
  rushyards = 0;
  passyards = 0;
  rushattempts = 0;
  thirddown = 0; 
  thirddownatt = 0; 
  firstdown = 0;
  playcount = 0;
  drivecount = 0;
}

Team::~Team()
{
	
}


bool Team::playSelect()
{
  if(rand() % 100 <= tendency - 5 ||
     (timeremaining < 60 && quarter == 4))
    return true;
  else
    return false;
}

int Team::passPlay(Team * offense, Team * opponent)
{// For now this will be a team's offense against the defense->
  cout << "PASS!";

  bool valid = false;

  yardsgained = 0;

  offense->addPlaycount();

  do
  {
    valid = false;
    //	cout << "Short Pass 's', Medium Pass 'm', or Long Pass 'l'? ";
    //	cin >> choice;
    choice = toupper(choice);

    switch(choice)
    {
    case 'S':
    case 'M':
    case 'L':
      valid = true;
      if((rand() % offense->getQBR()) + (rand() % offense->getWRR()) >
	 rand() % opponent->getDefpass())
      {
	switch(choice)
	{
	case 'S':
	  cout << choice;
	  cout << "\tCOMPLETE!";

	  completions++; attempts++;

	  yardsgained = rand() % 6;

	  cout << "\tGained " << yardsgained << " yards.\n";

	  valid = true;
						
	  if(timeremaining > 60 && quarter == 4)
	    RunClock(offense);
						
	  break;
	case 'M':
	  cout << choice;
	  if(rand() % offense->getWRR() >
	     (rand() % opponent->getDefpass() -
	      (rand() % offense->getQBR() * (2 / 3))))
	  {
	    cout << "\tCOMPLETE!";
							
	    completions++; attempts++;
							
	    yardsgained = rand() % 15 + 6;
							
	    cout << "\tGained " << yardsgained << " yards.\n";
							
	    if(timeremaining > 60 && quarter == 4)
	      RunClock(offense);
	  }
	  else
	  {
	    cout << "\tINCOMPLETE!\n";
	    offense->addTime(7);
	    attempts++;
	  }
	  valid = true;
	  break;
	case 'L':
	  cout << choice;
	  if(rand() % offense->getWRR() >
	     (rand() % opponent->getDefpass() -
	      (rand() % offense->getQBR() / 2)))
	  {
	    cout << "\tCOMPLETE!";
	    yardsgained = (rand() % offense->getQBR()) + (rand() % 16) -
	      (rand() % (opponent->getDefpass()));
	    if(yardsgained < 0)
	      yardsgained = rand() % 4 * (-1);
	    completions++; attempts++;
	    cout << "\tGained " << yardsgained << " yards.\n";
					
	    if(timeremaining > 60 && quarter == 4)
	      RunClock(offense);
	  }
	  else
	  {
	    cout << "\tINCOMPLETE!\n";
	    offense->addTime(7);
	    attempts++;
	  }
	  valid = true;
	  break;
	default:
	  cout << "Make a valid selection\n";
	  valid = false;
	  break;
	}
				
	passyards += yardsgained;

	return yardsgained;
      }
      else if((rand() % offense->getQBR() +
	       rand() % offense->getOffline() +
	       rand() % offense->getWRR()) < 
	      ((rand() % opponent->getDefpass() +
		rand() % opponent->getDefline())))
      {
	cout << "\tSACK!";

	rushattempts++;

	yardsgained = 0 - ((rand() % 8) + 3);

	cout << "\tLoss of " << abs(yardsgained) <<
	  " yards. " << yardsgained << "\n";

	offense->addTime(18);

	if(timeremaining > 60 && quarter == 4)
	  RunClock(offense);

	rushyards = rushyards + yardsgained;

	return yardsgained;
      }
      else
      {
	cout << "\tINCOMPLETE!\n";
	offense->addTime(7);
	attempts++;
	return 0;
      }
			
      break;
    }
  }while(!valid);

  return yardsgained;

}

int Team::runPlay(Team * offense, Team * defense)
{// For now this will be a team's offense against the defense.

  yardsgained = 0;
	
  offense->addPlaycount();

  cout << "RUN!";

  if(rand() % offense->getOffline() > rand() % defense->getDefline())
  {
    if(rand() % 10 == 0 || (offense->getTend() <
			    50 && rand() % offense->getTend() <= 4))
    {
      yardsgained = (rand() % offense->getRBR());
			
      if(yardsgained > 19 && offense->getTend() <= 35)
	offense->addTime(31);
      else if(yardsgained > 19 && offense->getTend() >= 70)
	offense->addTime(17);
      else
	offense->addTime(22);
    }
    else
    {
      if((rand() % offense->getRBR()) - (rand() % defense->getDefline()) < 1)
      {
	yardsgained = rand() % 4 - (rand() % 6);

	offense->addTime(28);				
      }
      else if (((rand() % offense->getRBR()) -
		(rand() % defense->getDefline()) > 1 
		&& (rand() % offense->getRBR()) -
		(rand() % defense->getDefline()) < 21)
	       || (offense->getTend() <= 55
		   && rand() % offense->getTend() <= 28
		   && rand() % offense->getTend() > 15))
      {
	yardsgained = rand() % 26;

	if(yardsgained > 19 && offense->getTend() <= 35)
	  offense->addTime(31);
	else if(yardsgained > 19 && offense->getTend() >= 70)
	  offense->addTime(17);
	else
	  offense->addTime(20);
      }
      else if (((rand() % offense->getRBR()) -
		(rand() % defense->getDefline()) > 21 
		&& (rand() % offense->getRBR()) -
		(rand() % defense->getDefline()) < 51)
	       || (offense->getTend() < 50
		   && rand() % offense->getTend() <= 15
		   && rand() % offense->getTend() > 4))
      {
	yardsgained = rand() % 51;

	if(yardsgained > 19 && offense->getTend() <= 35)
	  offense->addTime(31);
	else if(yardsgained > 19 && offense->getTend() >= 70)
	  offense->addTime(17);
	else
	  offense->addTime(20);
      }
      else
      {
	yardsgained = rand() % 13;

	if(yardsgained > 9 && offense->getTend() <= 35)
	  offense->addTime(31);
	else if(yardsgained > 9 && offense->getTend() >= 70)
	  offense->addTime(17);
	else
	  offense->addTime(20);
      }
    }

    cout << "\t\t\tGained " << yardsgained << " yards!\n";
  }
  else
  {
    yardsgained = rand() % 3;

    cout << "\t\t\tGained " << yardsgained << " yards!\n";

    offense->addTime(12);
  }

  RunClock(offense);

  rushattempts++;

  rushyards += yardsgained;

  return yardsgained;
}
