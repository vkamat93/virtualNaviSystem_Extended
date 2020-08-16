/*
 * CFileHandling.h
 *
 *  Created on: 07-Dec-2015
 *      Author: VIKRANT
 */

#ifndef CFILEHANDLING_H_
#define CFILEHANDLING_H_

#include<iostream>
#include<string.h>

#include"CWpDatabase.h"
#include"CPOIDatabase.h"

#include"CPersistentStorage.h"

class CFileHandling : public CPersistentStorage
{
private:
	std::string wpMediaName;
	std::string poiMediaName;

public:
	void setMediaName(std::string name);
	bool writeData (const CWpDatabase& waypointDb, const CPOIDatabase& poiDb);
	bool readData (CWpDatabase& waypointDb, CPOIDatabase& poiDb, MergeMode mode);

};

#endif /* CFILEHANDLING_H_ */
