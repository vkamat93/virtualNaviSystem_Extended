#include "CPOIDatabase.h"
#include "CPOI.h"
#include<iostream>
using namespace std;

#include<fstream>

/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CPOIDATABASE.CPP
 * Author          :
 * Description     :
 *
 *
 ****************************************************************************/

//System Include Files

//Own Include Files
//Method Implementations
CPOIDatabase::CPOIDatabase()
{

}

void CPOIDatabase::addPoi(CPOI const& poi)
{
	poiMap.insert(std::make_pair(poi.getName(),poi));
}

CPOI* CPOIDatabase::getPointerToPoi(string name)
{
	CPOI* pointerToPoi = NULL; //set pointer to NULL before scanning the database

//search for the find() function to replace for loop in map exclusive!!!!!! IMP...

	std::map<string,CPOI>::iterator it;
	for(it=poiMap.begin(); it!=poiMap.end(); ++it)
	{
		if(it->first==name)
		{
			pointerToPoi=&it->second;
		}
	}
	if (pointerToPoi == NULL)
	{
		cout << "ERROR: COULD NOT FIND POI IN THE POI DATABASE" << endl;
	}
	return pointerToPoi; //returns NULL pointer if no match
}

//map<string, CPOI> CPOIDatabase::getDummyPoiMap() const
//{
//	return poiMap;
//}

void CPOIDatabase::PoiDatabaseWriteToFile(string name) const
{
	ofstream fout;
	fout.open(name.c_str(), ios::app);
	for (map<string, CPOI>::const_iterator it = poiMap.begin();
			it != poiMap.end(); ++it)
	{
		string Poiname, PoiDescription;
		double PoiLat, PoiLong;
		t_poi Poitype;
		it->second.getAllDataByReference(Poiname, PoiLat, PoiLong, Poitype,
				PoiDescription);
		switch (Poitype)
		{
		case RESTAURANT:
			fout << "RESTAURANT" << ";" << Poiname << ";" << PoiDescription
					<< ";" << PoiLat << ";" << PoiLong << endl;
			break;
		case SIGHTSEEING:
			fout << "SIGHTSEEING" << ";" << Poiname << ";" << PoiDescription
					<< ";" << PoiLat << ";" << PoiLong << endl;
			break;
		case SHOPPING:
			fout << "SHOPPING" << ";" << Poiname << ";" << PoiDescription << ";"
					<< PoiLat << ";" << PoiLong << endl;
			break;
		default:
			fout << "NO such type found" << endl;
		}
	}
	fout.close();


}

void CPOIDatabase::print()
{
	std::map<string,CPOI>::iterator it;
	for(it=poiMap.begin(); it!=poiMap.end(); ++it)
	{
		it->second.print(MMSS);
	}

}

void CPOIDatabase::clearPoiMap()
{
    poiMap.clear();
}
