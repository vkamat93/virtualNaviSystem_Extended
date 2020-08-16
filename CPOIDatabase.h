/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CPOIDATABASE.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CPOIDATABASE_H
#define CPOIDATABASE_H
#include "CPOI.h"
#include<map>

//This class is used to make a database of the POIs and store all their details
class CPOIDatabase
{
private:

	std::map<string,CPOI> poiMap;

public:

/*Default Constructor
 *@return no return type in Constructor */
    CPOIDatabase();

/*This function adds the POIs to the database one by one
 *@return returns void*/
    void addPoi(CPOI const& poi);

/*This function is used to check whether desired POI in route exists in the Database
 *@param name to get a name of the POI which is to be checked for existence in Database
 *@return returns a pointer of type CPOI*/
    CPOI* getPointerToPoi(string name);

void clearPoiMap();

void PoiDatabaseWriteToFile(string name) const;

void print();

};
/********************
**  CLASS END
*********************/
#endif /* CPOIDATABASE_H */
