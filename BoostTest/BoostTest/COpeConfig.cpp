#include "COpeConfig.h"

void COpeConfig::funcid_split(string& s, vector<string>& v)
{
    int start = 0;
    size_t index = 0;
    while (true)
    {
        index = s.find(";");
        if (index == string::npos)
        {
            v.push_back(s.substr(start));
            break;
        }
        v.push_back(s.substr(start, index));
        s = s.substr(index + 1);
    }
}

int COpeConfig::ParseXML(const char* path)
{
    ptree root_pt;
    read_xml(path, root_pt, xml_parser::no_comments);
    ptree t2sdkust = root_pt.get_child("T2SDKUST.functions");
    for (ptree::iterator iter = t2sdkust.begin(); iter != t2sdkust.end(); ++iter)
    {
        if (iter->first != "<xmlattr>")
        {
            //cout << "-----------" << iter->second.get<string>("<xmlattr>.srcfunc") << "---------------\n";
            string func_id = iter->second.get<string>("<xmlattr>.srcfunc");
            //vector<string> key;
            vector<string*> req_value;
            vector<string*> rsp_value;
            //funcid_split(func_id, key);
            ptree sub = iter->second.get_child("");
            ptree req = sub.get_child("requestfield");
            for (ptree::iterator subit = req.begin(); subit != req.end(); ++subit)
            {
                string* p = new string[3]{
                    subit->second.get<string>("<xmlattr>.srcfield"),
                    subit->second.get<string>("<xmlattr>.srctype"),
                    subit->second.get<string>("<xmlattr>.destfield")
                };
                req_value.push_back(p);
            }

            ptree rsp = sub.get_child("answerfield");
            for (ptree::iterator rsp_it = rsp.begin(); rsp_it != rsp.end(); ++rsp_it)
            {
                string* q = new string[3]
                {
                    rsp_it->second.get<string>("<xmlattr>.srcfield"),
                    rsp_it->second.get<string>("<xmlattr>.srctype"),
                    rsp_it->second.get<string>("<xmlattr>.destfield")
                };
                rsp_value.push_back(q);
            }

            m_mapField.insert({ func_id, make_pair(req_value, rsp_value) });
        }
    }

    cout << "ParseXML" << endl;
    // ´òÓ¡vector
    for (field_iter iter = m_mapField.begin(); iter != m_mapField.end(); ++iter)
    {
        cout << "key: " << iter->first << endl;
        /*for (vector<string>::const_iterator itkey = (iter->first).begin(); itkey != (iter->first).end(); ++itkey)
        {
            cout << *itkey << " ";
        }*/
        //cout << endl;
        cout << "req value: ---------begin---------" << endl;
        for (vector<string*>::const_iterator it_value = (iter->second.first).begin(); it_value != (iter->second.first).end(); ++it_value)
        {
            cout << (*it_value)[0] << " " << (*it_value)[1] << " " << (*it_value)[2] << endl;
        }
        cout << "QSP£º---------" << endl;
        for (vector<string*>::const_iterator it_value = (iter->second.second).begin(); it_value != (iter->second.second).end(); ++it_value)
        {
            cout << (*it_value)[0] << " " << (*it_value)[1] << " " << (*it_value)[2] << endl;
        }
        cout << "value: -----------end-----------" << endl;
    }
    return 0;
}

std::pair<vector<string*>, vector<string*>>* COpeConfig::GetData(const int func_id)
{
    string id = to_string(func_id);
    for (field_iter iter = m_mapField.begin(); iter != m_mapField.end(); ++iter)
    {
        if (string::npos != iter->first.find(id))
        {
            return &(iter->second);
        }
    }
    return nullptr;
}

vector<string*>* COpeConfig::GetReqData(const int func_id)
{
    string id = to_string(func_id);
    for (field_iter iter = m_mapField.begin(); iter != m_mapField.end(); ++iter)
    {
        if (string::npos != iter->first.find(id))
        {
            return &(iter->second.first);
        }
    }
    return nullptr;
}

vector<string*>* COpeConfig::GetRspData(const int func_id)
{
    string id = to_string(func_id);
    for (field_iter iter = m_mapField.begin(); iter != m_mapField.end(); ++iter)
    {
        if (string::npos != iter->first.find(id))
        {
            return &(iter->second.second);
        }
    }
    return nullptr;
}


