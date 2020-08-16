/*
 * CNavigationSystem.cpp
 *
 *  Created on: 10-Nov-2015
 *      Author: VIKRANT
 */

#include<iostream>
using namespace std;

#include "CNavigationSystem.h"

/*calling constructor of the CRoute class from this particular constructor*/
CNavigationSystem::CNavigationSystem()//:m_route(4,2)
{

}

void CNavigationSystem::enterRoute()
{
cout<<endl<<endl<<"*****NAVIGATION SYSTEM GESTARTED*****"<<endl<<endl;

//adding elements to the Database
//		m_PoiDatabase.addPoi(RESTAURANT,"HDA","Best mensa in the world",10,20);
//		m_PoiDatabase.addPoi(SHOPPING,"Growel","Best mall in the world",19,18);
//		m_PoiDatabase.addPoi(RESTAURANT,"Sitte","More expensive but also good",11,22);
//		m_PoiDatabase.addPoi(SIGHTSEEING,"Raigad","Best fort in the world",13,30);
//		m_PoiDatabase.addPoi(SIGHTSEEING,"Juhu","Best seaface location",33,30);
//		m_PoiDatabase.addPoi(RESTAURANT,"Noor","Best tandoori in the world",43,78);
//		m_PoiDatabase.addPoi(SHOPPING,"Inorbit","Third best Mall in the world",6.6,30);
//		m_PoiDatabase.addPoi(SHOPPING,"Hypercity","Second best Mall",60.7,38);
//		m_PoiDatabase.addPoi(SHOPPING,"Phoenix","Best Mall in the universe!",65,35);
//		m_PoiDatabase.addPoi(SIGHTSEEING,"Carter","Best hangout",63,33);

//To test condition of adding more than 10 POI objects to the array m_POI
//		m_PoiDatabase.addPoi(SIGHTSEEING,"IC","Best footballers",62.7,36.8);


//Connect database to Navigation system
 m_route.connectToPoiDatabase(&m_PoiDatabase);

//creating and adding Waypoints on our route
		CWaypoint berlin("berlin", 52.5166, 13.4);
		CWaypoint amsterdam("amsterdam", 52.3667, 4.9000);
		CWaypoint darmstadt("darmstadt", 49.8667, 8.6500);
//		m_route.addWayPoint(amsterdam);
//		m_route.addWayPoint(darmstadt);
//		m_route.addWayPoint(berlin);

//adding points of interest on the route
//		m_route.addPoi("HDA");
//		m_route.addPoi("Sitte");
//		m_route.addPoi("Schloss");
//		m_route.addPoi("Juhu");


/*NOTE: here since we have added 4 POIs to our route and the max POI limit is 2 as
 * set in the constructor thus we get an error message*/

/*Testing the copy constructor*/
//		CRoute m_route1 = CRoute(m_route);
//		cout<<"Copy constructor started"<<endl;
//		m_route1.addPoi("Sitte");
//		m_route1.print();
//		cout<<"COpy constructor finished"<<endl;

}

void CNavigationSystem::printRoute()
{
/*Calls the print function with object of CRoute*/
	m_route.print();
}

void CNavigationSystem::printDistanceCurPosNext()
{
/*Creating object of CGPSSensor*/
	CGPSSensor gps;

/*Details of position got through using the object of CWaypoint*/
	CWaypoint wp=gps.getCurrentPosition();

/*Creating an object of CPOI*/
	CPOI poi;

/*Check to determine whether indeed POI present on the route defined,using the dummy value
 * returned in getDistanceNextPoi as control check, if yes then print the shortest
 * distance and that particular POI details if no POI is found then distance is
 * not calculated and error message is printed */
//	if(m_route.getDistanceNextPoi(wp,poi)!=-1.0)
//	{
//	cout<<"Distance to next POI: "<<m_route.getDistanceNextPoi(wp,poi)<<endl;
//	poi.print();
//	}
//	else
//	{
//		cout<<"Error: No POI found on your route"<<endl;
//	}

}

void CNavigationSystem::run()
{
/*Calling the private functions from within run()*/
 enterRoute();
 printRoute();
 printDistanceCurPosNext();
}



