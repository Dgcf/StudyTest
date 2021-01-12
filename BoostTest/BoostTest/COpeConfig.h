#pragma once
#include "common.h"
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/xml_parser.hpp"
#include "boost/typeof/typeof.hpp"

using namespace boost::property_tree;


class COpeConfig
{
public:
	typedef map<string, std::pair<vector<string*>, vector<string*>>>::iterator field_iter;

	void funcid_split(string& s, vector<string>& v);
	int ParseXML(const char* path);
	std::pair<vector<string*>, vector<string*>>* GetData(const int func_id);
	vector<string*>* GetReqData(const int func_id);
	vector<string*>* GetRspData(const int func_id);

	void UnpackerData();

private:
	map < string, std::pair<vector<string*>, vector<string*>>> m_mapField;
};