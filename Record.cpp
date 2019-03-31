#include "pch.h"
#include "Record.h"
#include <string>
Record::Record()
{
	this->cId = 0;
	this->trType = 'Y';
	this->mType = 'X';
	this->title = "";
	this->director = "";
	string date = "0000/00/00 0:0:0";
}

Record::Record(int cid, char mType, string title, string director, char mediaType, string year_or_actor, char trType)
{
	this->cId = cid;
	this->trType = trType;
	this->mType = mType;
	this->title = title;
	this->director = director;
	this->mediaType = mediaType;
	this->year_or_actor = year_or_actor;
	struct tm t;
	time_t now;
	time(&now);
	localtime_s(&t, &now);
	string year = to_string(t.tm_year + 1900);
	string month = to_string(t.tm_mon + 1);
	string day = to_string(t.tm_mday);
	string hour = to_string(t.tm_hour);
	string min = to_string(t.tm_min);
	string second = to_string(t.tm_sec);
	this->date = month + "/" + day + "/" + year + " " + hour + ":" + min + ":" + second;
}

Record::Record(int cid, char mType, string title, string director, char mediaType, string year_or_actor, char trType, string date)
{
	this->year_or_actor = year_or_actor;
	this->cId = cid;
	this->trType = trType;
	this->mType = mType;
	this->title = title;
	this->mediaType = mediaType;
	this->director = director;
	this->date = date;
}


string Record::getYear_or_actor() const
{
	return year_or_actor;
}


Record::~Record()
{

}

int Record::getCId()
{
	return cId;
}
char Record::getTrType()const
{
	return trType;
}
char Record::getMType()const
{
	return mType;
}
string Record::getTitle()const
{
	return title;
}
string Record::getDirector()const
{
	return director;
}
string Record::getDate()const
{
	return date;
}

char Record::getMediaType() const
{
	return mediaType;
}
