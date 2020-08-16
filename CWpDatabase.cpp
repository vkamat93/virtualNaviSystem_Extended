#include "CWpDatabase.h"
#include "CWaypoint.h"
#include <fstream>

//System Include Files


//Own Include Files

//Method Implementations

/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CWPDATABASE.CPP
* Author          :
* Description     :
*
*
****************************************************************************/
CWpDatabase::CWpDatabase()
{

}

void CWpDatabase::addWaypoint(CWaypoint const& wp)
{
	WpMap.insert(std::make_pair(wp.getName(),wp));
}

CWaypoint* CWpDatabase::getPointerToWaypoint(string name)
{
	CWaypoint* pointerToWaypoint = NULL; //set pointer to NULL before scanning database

	std::map<string,CWaypoint>::iterator it;
	for(it=WpMap.begin(); it!=WpMap.end(); ++it)
		{
			if(it->first==name)
			{
				pointerToWaypoint=&it->second;
			}
		}
//	if (pointerToWaypoint == NULL)
//	{
//		cout << "ERROR: COULD NOT FIND WAYPOINT IN THE WAYPOINT DATABASE" << endl;
//	}
	return pointerToWaypoint; //returns NULL pointer if no match
}

void CWpDatabase::clearWpMap()
{
	WpMap.clear();
}

void CWpDatabase::WpDatabaseWriteToFile(string name) const
{
	ofstream fout;
		//READ ABOUT c_str()
		fout.open(name.c_str(),ios::app);
		for(map<string,CWaypoint>::const_iterator it=WpMap.begin();it!=WpMap.end();++it)
		{
			string Wpname;
			double WpLat,WpLong;
			it->second.getAllDataByReference(Wpname,WpLat,WpLong);
			fout<<Wpname<<";"<<WpLat<<";"<<WpLong<<endl;
		}

	fout.close();
}

void CWpDatabase::print()
{
	std::map<string,CWaypoint>::iterator it;
	for(it=WpMap.begin(); it!=WpMap.end(); ++it)
	{
		it->second.print(MMSS);
	}

}
