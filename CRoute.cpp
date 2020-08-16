/*
 * CRoute.cpp0
 *
 *  Created on: 07-Nov-2015
 *      Author: VIKRANT
 */

#include "CRoute.h"
#include <iostream>
using namespace std;

CRoute::CRoute()
{

//	m_nextWp = 0;
//	m_nextPoi = 0; //initialization to 0 for the variable
//
//	//Allocate memory for the storing waypoints at runtime
//	m_pWaypoint = new CWaypoint[maxWp];
//
//	//Allocate memory for storing CPOIs at runtime
//	m_pPoi = new CPOI*[maxPoi];
//
//	m_maxWp = maxWp;
//	m_maxPoi = maxPoi;

	/*Initially it must contain no address so that it will later get address of object
	 *passed for connecting Database*/
	m_pPoiDatabase = NULL;
	m_pWpDatabase = NULL;
}

CRoute& CRoute::operator=(const CRoute& oldRoute)
{
	this->myRoute=oldRoute.myRoute;
	this->m_pPoiDatabase=oldRoute.m_pPoiDatabase;
	this->m_pWpDatabase=oldRoute.m_pWpDatabase;
	return *this;
}

CRoute::CRoute(CRoute const& origin)
{
	*this=origin;
}

void CRoute::connectToPoiDatabase(CPOIDatabase* pPoiDB = NULL)
{
/*here we want the address of the database so in CNavigationSystem we have object of
 * database and &object gives address of 'real database' which is then
 * assigned to m_pPoiDatabase*/

/*pass address of object of database to the the database pointer present here in
* CRoute but currently not pointing anywhere,ie,NULL pointer*/
	m_pPoiDatabase = pPoiDB;
}

void CRoute::connectToWpDatabase(CWpDatabase* pWpDB = NULL)
{
/*here we want the address of the database so in CNavigationSystem we have object of
 * database and &object gives address of 'real database' which is then
 * assigned to m_pPoiDatabase*/

/*pass address of object of database to the the database pointer present here in
* CRoute but currently not pointing anywhere,ie,NULL pointer*/
	m_pWpDatabase = pWpDB;
}

void CRoute::addWaypoint(string name)
{
/*To check if m_pPoiDatabase holds address of the database,i.e database connected*/
	if(m_pWpDatabase!=NULL)
	{
		if(m_pWpDatabase->getPointerToWaypoint(name)!=NULL)
		{
		myRoute.push_back(m_pWpDatabase->getPointerToWaypoint(name));
	    }
		else
	    {
		cout << "ERROR: COULD NOT FIND WAYPOINT IN THE WAYPOINT DATABASE" << endl;
		}
	}
	else
	{
		cout<<"ERROR: WAYPOINT DATABASE NOT CONNECTED"<<endl;
	}
}

void CRoute::addPoi(string namePoi, string nameWp)
{
	int checkForWpInRoute = 0;
	if (m_pPoiDatabase != NULL)
	{
		if (myRoute.size() == 0)
		{
			cout << "ERROR: YOUR ROUTE IS EMPTY, THUS POI CAN'T BE ADDED" << endl;
		}
	    else if (m_pPoiDatabase->getPointerToPoi(namePoi) != NULL)
		{
			if (m_pWpDatabase->getPointerToWaypoint(nameWp) != NULL)
			{
				std::vector<CWaypoint*>::iterator itemp;
				for (std::vector<CWaypoint*>::iterator itr = myRoute.begin();
						itr < myRoute.end(); ++itr)
				{
					CPOI* temp = dynamic_cast<CPOI*>(*itr); //done to avoid adding poi after a poi with a Waypoint name
					if (temp == NULL) //it is a waypoint
					{
						if ((*itr)->getName() == nameWp)
						{
							itemp = itr;
							checkForWpInRoute = 1;
						}
					}
				}
				if(checkForWpInRoute==1)
				{
					myRoute.insert(++itemp,m_pPoiDatabase->getPointerToPoi(namePoi));
				}
				else
				{
					cout<<"ERROR: SPECIFIED WAYPOINT NOT FOUND IN YOUR ROUTE"<<endl;
				}
			}
			/*No need as this check already implemented before*/
//			else
//			{
//				cout<<"ERROR: NO SUCH WAYPOINT FOUND IN WAYPOINT DATABASE"<<endl;
//			}
		}
	}
	else
	{
		cout << "ËRROR: POI DATABASE NOT CONNECTED" << endl;
	}
}

//double CRoute::getDistanceNextPoi(CWaypoint const& wp, CPOI& poi)
//{
//	/*If condition to check whether there are POIs specified on the route*/
//	if(m_nextPoi!=0)
//	{
//	/*CPOI inherits CWaypoint so all its functions too and thus
//	 * we use this function to calculate distance*/
//	double smallestDist = m_pPoi[0]->calculateDistance(wp);
//
//	int count = 0;  //variable to store array location of the nearest POI details
//	for (unsigned int i = 0; i < m_nextPoi; i++)
//	{
//		if (smallestDist > m_pPoi[i]->calculateDistance(wp))
//		{
//			smallestDist = m_pPoi[i]->calculateDistance(wp);
//			count = i;
//		}
//	}
//	poi = *m_pPoi[count]; //to get the details of the nearest POI
//	return smallestDist;
//	}
//	/*If there is no POI specified on route return a dummy value in control logic
//	 * used later for printing a error message in Distance calculation   */
//	else
//	{
//		return -1.0;
//	}
//}

void CRoute::print()
{
	cout<<"------------------Route---------------------"<<endl;
	std::vector<CWaypoint*>::iterator itemp;
	for(std::vector<CWaypoint*>::iterator itr=myRoute.begin(); itr<myRoute.end(); ++itr)
	{
		//itr now searches for CPOI type pointers dynamically at runtime
		//done to avoid adding poi after a poi with a Waypoint name
		CPOI* temp=dynamic_cast<CPOI*>(*itr);
		if(temp==NULL) //means it is of type CWaypoint
		{
		   cout<<(**itr); //itr is kind of pointer pointing to pointer thus the double pointer
		}
		else
		{
		   cout<<*temp; //prints CPOIS //temp is already pointer pointing to object of CPOI
		}
	}
//	for(unsigned int i=0; i<myRoute.size();i++)
//	{
//
//		myRoute[i]->print(MMSS);
//	}
}

CRoute::~CRoute()
{
//	/*release the dynamic memory from use*/
//	delete m_pWaypoint;
//	delete m_pPoi;
}

CRoute CRoute::operator +=(string name)
{
	this->addWaypoint(name);

		if(m_pWpDatabase->getPointerToWaypoint(name)!=NULL)
			{
		     this->addPoi(name,name);
			}
		else if(m_pPoiDatabase->getPointerToPoi(name)!=NULL)
		    {
			myRoute.push_back(m_pPoiDatabase->getPointerToPoi(name));
		    }

/*This is to add the poi to after the last waypoint, thus not really end of the route*/
//	std::vector<CWaypoint*>::iterator itemp;
//	for(std::vector<CWaypoint*>::iterator it=myRoute.begin(); it<myRoute.end(); ++it)
//		{
//			CPOI* temp=dynamic_cast<CPOI*>(*it);
//			if(temp==NULL) //means its type CWaypoint
//			{
//			   itemp=it;
//			}
//		}
//	this->addPoi(name,(*itemp)->getName());
	return *this;
}

CRoute CRoute::operator +(const CRoute& r2)
{
	if(this->m_pPoiDatabase==r2.m_pPoiDatabase && this->m_pWpDatabase==r2.m_pWpDatabase)
	{
		this->myRoute.insert(this->myRoute.end(), r2.myRoute.begin(), r2.myRoute.end());
	}
	else
	{
		cout<<"ERROR:Both routes not connected to the same databases"<<endl;
		this->myRoute.clear();
	}
	return *this;
}
