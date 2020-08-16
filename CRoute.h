/*
 * CRoute.h
 *
 *  Created on: 07-Nov-2015
 *      Author: VIKRANT
 */

#ifndef CROUTE_H_
#define CROUTE_H_

#include "CPOIDatabase.h"
#include "CWpDatabase.h"
#include<vector>

/*This class does the job of linking the POI database, adding Waypoints and POIs,
 * printing them, calculating the closest POI and its distance from current location and
 * logic for error messages in this Navigation System*/
class CRoute
{
private:
	//since POIs are also type of waypoints itself thus *CWaypoint
	std::vector<CWaypoint*> myRoute;
	//std::vector<CWaypoint*> myRoute1(myRoute);

/*pointer variable of type CPOIDatabase*/
CPOIDatabase* m_pPoiDatabase;

/*pointer variable of type CWpDatabase*/
CWpDatabase* m_pWpDatabase;

public:
/*Constructor used to initialize the database pointers to NULL*/
 CRoute();

/*Operator overloading of =*/
CRoute& operator=(const CRoute& oldRoute); //return tyoe cuz this shd return actual value of cr not a copy

CRoute(CRoute const& origin);

/*Connects with the POI database
 *@param pPoiDB is pointer of type CPOIDatabase which stores address of the passed object
 *which is the POI database which we use.
 *@return returns void */
	void connectToPoiDatabase(CPOIDatabase* pPoiDB);

	void connectToWpDatabase(CWpDatabase* pWpDB);

	void addWaypoint(string name);

	void addPoi(string namePoi, string nameWp);

/*Prints the waypoints and POIs in our route
 *@return returns void */
	void print();

/*Destructor used to delete the memory space allocated to the dynamic arrays created for
 * storing the Waypoints and POIs at runtime*/
	~CRoute();

CRoute operator+=(string name);

CRoute operator+(const CRoute& r2);
};


#endif /* CROUTE_H_ */
