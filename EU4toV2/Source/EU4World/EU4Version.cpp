#include "EU4Version.h"
#include "..\Log.h"



EU4Version::EU4Version()
{
	first		= 0;
	second	= 0;
	third		= 0;
	fourth	= 0;
}


EU4Version::EU4Version(Object* obj)
{
	vector<Object*> numObj;
	numObj = obj->getValue("first");
	if (numObj.size() > 0)
	{
		first = atoi(numObj[0]->getLeaf().c_str());
	}
	numObj = obj->getValue("second");
	if (numObj.size() > 0)
	{
		second = atoi(numObj[0]->getLeaf().c_str());
	}
	numObj = obj->getValue("third");
	if (numObj.size() > 0)
	{
		third = atoi(numObj[0]->getLeaf().c_str());
	}
	numObj = obj->getValue("forth");
	if (numObj.size() > 0)
	{
		fourth = atoi(numObj[0]->getLeaf().c_str());
	}
}


EU4Version::EU4Version(string version)
{
	int dot = version.find_first_of('.');
	first = atoi(version.substr(0, dot).c_str());

	version = version.substr(dot + 1, version.size());
	dot = version.find_first_of('.');
	second = atoi(version.substr(0, dot).c_str());

	version = version.substr(dot + 1, version.size());
	dot = version.find_first_of('.');
	third = atoi(version.substr(0, dot).c_str());

	version = version.substr(dot + 1, version.size());
	dot = version.find_first_of('.');
	fourth = atoi(version.substr(0, dot).c_str());
}


bool EU4Version::operator >= (EU4Version& rhs) const
{
	if (first > rhs.first)
	{
		return true;
	}
	else if ((first == rhs.first) && (second > rhs.second))
	{
		return true;
	}
	else if ((first == rhs.first) && (second == rhs.second) && (third > rhs.third))
	{
		return true;
	}
	else if ((first == rhs.first) && (second == rhs.second) && (third == rhs.third) && (fourth > rhs.fourth))
	{
		return true;
	}
	else if ((first == rhs.first) && (second == rhs.second) && (third == rhs.third) && (fourth == rhs.fourth))
	{
		return true;
	}
	else
	{
		return false;
	}
}