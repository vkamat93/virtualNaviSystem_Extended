/*
 * CFileHandling.cpp
 *
 *  Created on: 07-Dec-2015
 *      Author: VIKRANT
 */

#include "CFileHandling.h"
#include <fstream>
#include <string>
#include <stdlib.h>  //for using atof
#include <typeinfo>
using namespace std;

void CFileHandling::setMediaName(string name)
{
	wpMediaName=name+"-wp.txt";
	poiMediaName=name+"-poi.txt";
}

bool CFileHandling::writeData(const CWpDatabase& waypointDb,const CPOIDatabase& poiDb)
{
	waypointDb.WpDatabaseWriteToFile(wpMediaName);
	poiDb.PoiDatabaseWriteToFile(poiMediaName);
	return true;
}

bool CFileHandling::readData(CWpDatabase& waypointDb, CPOIDatabase& poiDb,MergeMode mode)
{
/*********For Waypoint****************/

	string wpstrfull, wpstrcut; //strfull to get the entire line
	ifstream wpfin;
	double wplat, wplong;
	wpfin.open(wpMediaName.c_str(), ios::in); //c_str() converts string to character
	wpfin.seekg(0);  //Sets the position of the next character to be extracted from the input stream.

	int wpfieldcount;
	int wplinenumber=0;

	string wpstrarray[3]; //since we have three fields in waypoint
	if (mode == REPLACE)
	{
		waypointDb.clearWpMap();
	}
	while (!wpfin.eof())
	{
		getline(wpfin, wpstrfull); //gets the entire line by line from the specified file
		wplinenumber++;

		string wptempstr=wpstrfull; //tempstr to store the full string to display in error msg and to count the size of entry

	for (unsigned int i = 0; i < 3; i++)  //to check number of semicolons
	{
		/*using find_first_of() for taking both ; and , as delimiter*/
		unsigned int pos = wpstrfull.find_first_of(";,");

		/*npos is a word for garbage/invalid value when it cant find the given character*/
		if (pos != string::npos)
		{
			wpfieldcount = i;

			wpstrcut = wpstrfull.substr(0, pos);
			wpstrfull.erase(0, wpstrcut.size() + 1);
			wpstrarray[i] = wpstrcut;
		}
		else
		{
			wpstrarray[i] = wpstrfull;
		}
	}

/*atof() converts string to float and returns value if successful else return 0*/
	wplat = atof(wpstrarray[1].c_str());
	wplong = atof(wpstrarray[2].c_str());

	CWaypoint wp(wpstrarray[0], wplat, wplong);

/*To add to Waypoint database and checking for the error conditions*/
		if (wptempstr.size() == 0)
		{
			cout << "Error: Blank entry in database in line number " << wplinenumber
					<< endl;
		}
		else
		{
			if (wpfieldcount == 1)
			{
				if (wplat != 0 && wplong != 0)
				{
					waypointDb.addWaypoint(wp);
				}
				else
				{
					cout << "Error: Invalid coordinates in line number "
							<< wplinenumber << " : " << wptempstr << endl;
				}
			}
			else if (wpfieldcount < 1)
			{
				cout << "Error: Too less fields in line number " << wplinenumber
						<< " : " << wptempstr << endl;
			}
			else
			{
				cout << "Error: Too many fields in line number " << wplinenumber
						<< " : " << wptempstr << endl;
			}
		}

	}
	wpfin.close();

/********For POI****************/

	string poistrfull, poistrcut; //strfull to get the entire line
	ifstream poifin;
	double poilat, poilong;
	poifin.open(poiMediaName.c_str(), ios::in); //c_str() converts string to character
	poifin.seekg(0);  //Sets the position of the next character to be extracted from the input stream.

	int poifieldcount;
	int poilinenumber=0;

	string poistrarray[5]; //since we have five fields in POI
	if (mode == REPLACE)
	{
		poiDb.clearPoiMap();
	}
	while (!poifin.eof())
	{
		getline(poifin, poistrfull); //gets the entire line by line from the specified file
		poilinenumber++;

		string poitempstr=poistrfull;  //tempstr to store the full string to display in error msg and to count the size of entry

for (unsigned int i = 0; i < 5; i++)  //to check number of semicolons
	{
/*using find_first_of() for taking both ; and , as delimiter*/
		unsigned int pos = poistrfull.find_first_of(";,");

/*npos is a word for garbage/invalid value when it cant find the given character*/
			if (pos != string::npos)
			{
				poifieldcount=i;
				poistrcut = poistrfull.substr(0, pos);
				poistrfull.erase(0, poistrcut.size() + 1);
				poistrarray[i] = poistrcut;
			}
			else
			{
				poistrarray[i] = poistrfull;
			}
		}

/*atof() converts string to float and returns value if successful else return 0*/
		poilat = atof(poistrarray[3].c_str());
		poilong = atof(poistrarray[4].c_str());

		t_poi t;
		if (poistrarray[0] == "RESTAURANT")
		{
			t = RESTAURANT;
		}
		else if (poistrarray[0] == "SIGHTSEEING")
		{
			t = SIGHTSEEING;
		}
		else if (poistrarray[0] == "SHOPPING")
		{
			t = SHOPPING;
		}

		CPOI poi(t, poistrarray[1], poistrarray[2], poilat, poilong);

/*To add to Poi database and checking for the error conditions*/
		if (poitempstr.size() == 0)
		{
			cout << "Error: Blank entry in database in line number "
					<< wplinenumber << endl;
		}
		else
		{
			if (poifieldcount == 3)
			{
				if (poilat != 0 && poilong != 0)
				{
					poiDb.addPoi(poi);
				}
				else
				{
					cout << "Error: Invalid coordinates in line number "
							<< poilinenumber << " : " << poitempstr << endl;
				}
			}
			else if (poifieldcount < 3)
			{
				cout << "Error: Too less fields in line number "
						<< poilinenumber << " : " << poitempstr << endl;
			}
			else
			{
				cout << "Error: Too many fields in line number "
						<< poilinenumber << " : " << poitempstr << endl;
			}

		}
	}
	poifin.close();
	return true;
}
