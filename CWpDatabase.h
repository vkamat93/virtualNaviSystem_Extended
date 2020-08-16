/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CWPDATABASE.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CWPDATABASE_H
#define CWPDATABASE_H
#include "CWaypoint.h"
#include<map>

class CWpDatabase {
private:

	std::map<string,CWaypoint> WpMap;

public:

    CWpDatabase();

    void addWaypoint(CWaypoint const& wp);

    CWaypoint* getPointerToWaypoint(string name);

    void WpDatabaseWriteToFile(string name) const;

    void clearWpMap();

    void print();
};
/********************
**  CLASS END
*********************/
#endif /* CWPDATABASE_H */
