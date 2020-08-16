// GIT-Labor
// main.h

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>		// Header für die Standard-IO-Objekte (z.B. cout, cin)
#include <stdlib.h>
#include "CWayPoint.h"
#include "CGPSSensor.h"
#include "CPOI.h"
#include "CPOIDatabase.h"
#include "CRoute.h"
#include "CNavigationSystem.h"
#include "CWpDatabase.h"
#include "CPersistentStorage.h"
#include "CFileHandling.h"

// TODO: Fügen Sie hier weitere benötigte Header-Dateien der
// Standard-Bibliothek ein z.B.
// #include <string>

using namespace std;	// Erspart den scope vor Objekte der
						// C++-Standard-Bibliothek zu schreiben
						// z.B. statt "std::cout" kann man "cout" schreiben

// Inkludieren Sie hier die Header-Files Ihrer Klassen, z.B.
// #include "CFraction.h"


// Hauptprogramm
// Dient als Testrahmen, von hier aus werden die Klassen aufgerufen
int main (void)
{
	CPOIDatabase cpd;
//	cpd.addPoi(CPOI(RESTAURANT,"KFC","Best chicken in the world",10,20));
//	cpd.addPoi(CPOI(RESTAURANT,"HDA","Best mensa in the world",10,20));
//	cpd.addPoi(CPOI(SHOPPING,"growel","Best mall in the world",19,18));
//	cpd.addPoi(CPOI(RESTAURANT,"sitte","More expensive but also good",11,22));
//	cpd.addPoi(CPOI(SIGHTSEEING,"juhu","Best seaface location",33,30));
//	cpd.addPoi(CPOI(SIGHTSEEING,"mumbai","Best Place", 43.56, 56.89));

	//cpd.getPointerToPoi("HDA")->print(DEGREE);

	CWpDatabase cwpd;
//cwpd.addWaypoint(CWaypoint("berlin", 52.5166, 13.4));
//	cwpd.addWaypoint(CWaypoint("amsterdam", 52.3667, 4.9000));
//	cwpd.addWaypoint(CWaypoint("darmstadt", 49.8667, 8.6500));
//	cwpd.addWaypoint(CWaypoint("tokio", 35.6833, 139.6833));
//	cwpd.addWaypoint(CWaypoint("mumbai", 43, 56));

	/*Testcase for read from wp database*/
		CFileHandling cfh;
		cfh.setMediaName("DatabaseFile");
		cfh.readData(cwpd,cpd,REPLACE);
        cwpd.print();
        //cpd.print();

//checking if the route adds from the database file created
//        CRoute cr;
//        cr.connectToWpDatabase(&cwpd);
//        cr.addWaypoint("darmstadt");
//        cr.addWaypoint("tokio");
//        cr.addWaypoint("mew");
//        cr.print();

//	CRoute cr;
//	cr.connectToWpDatabase(&cwpd);
//	cr.connectToPoiDatabase(&cpd);
//    cr.addWaypoint("darmstadt");
//	cr.addWaypoint("mumbai");
//	cr.addWaypoint("darmstadt");
//	cr.addWaypoint("berlin");
//	cr.addPoi("juhu", "mumbai");
//	cr.addPoi("growel","darmstadt");
//	cr.addPoi("HDA", "berlin");
//    cr.print();

/*Testing the overloaded += operator*/
//	cr+="juhu";
//	cr.print();

/*To test copy constructor and overloadded = operator*/
	//CRoute cr1(cr);
//	CRoute cr1=cr;
//	cr1.addPoi("Juhu","amsterdam");
//	cr1.print();

/*To test the concatenating of two routes*/
//	CWpDatabase cwpd2;
//	cwpd2.addWaypoint(CWaypoint("Tokio", 35.6833, 139.6833));
//	cwpd2.addWaypoint(CWaypoint("amsterdam",3, 4.9000));
//	cwpd2.addWaypoint(CWaypoint("darmstadt", 4, 8));
//
//	CRoute cr2;
//	cr2.connectToWpDatabase(&cwpd);
//	cr2.connectToPoiDatabase(&cpd);
//	cr2.addWaypoint("amsterdam");
//	cr2.addWaypoint("darmstadt");
//	cr2.addPoi("HDA","darmstadt");
//
//	(cr+cr2).print();

/*To test overloaded << operator for CWaypoint class*/
//	CWaypoint c("berlin", 52.5166, 13.4);
//	cout<<c;

/*To test overloaded << operator for CPOI class*/
//	CPOI cpoi(SIGHTSEEING,"Juhu","Best seaface location",33,30);
//	cout<<cpoi;

/*To test the CFileHandling write*/
//	CFileHandling f1;
//	f1.setMediaName("DatabaseFile");
//	f1.writeData(cwpd,cpd);


/*Creating an object of class CNavigationSystem*/
//CNavigationSystem cnav;

/*Calling run() function using object of CNavigationSystem*/
//cnav.run();

return 0;
}
