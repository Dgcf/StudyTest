// TinyXmlTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "tinystr.h"
#include "tinyxml.h"
using namespace std;

void ParseXml()
{
    TiXmlDocument xml;
    if (!xml.LoadFile("./fieldswitch.xml"))
    {
        return;
    }
    TiXmlElement* root = xml.FirstChildElement();
    TiXmlElement* func = root->FirstChildElement();
    for (TiXmlElement* element = func->FirstChildElement(); element != nullptr; element = element->NextSiblingElement())
    {
        cout << "func: " << element->Attribute("srcfunc") << endl;
        // 解析request
        TiXmlElement* request = element->FirstChildElement();
        cout << "request:" << endl;
        for (TiXmlElement* field = request->FirstChildElement(); field != nullptr; field = field->NextSiblingElement())
        {
            for (TiXmlAttribute* p_attribute = field->FirstAttribute(); p_attribute; p_attribute = p_attribute->Next())
            {
                cout << p_attribute->Name() << endl;
                cout << p_attribute->Value() << endl;
            }
            /*cout << "\t" << field->Attribute("ufxfield") << endl;
            cout << "\t" << field->Attribute("ufxtype") << endl;
            cout << "\t" << field->Attribute("ustfield") << endl;
            cout << "\t" << field->Attribute("default") << endl;
            cout << "\t" << field->Attribute("translater") << endl;
            cout << "\t" << field->Attribute("dictionary") << endl;*/
        }

        TiXmlElement* answer = element->NextSiblingElement();
        cout << "answer:" << endl;
        for (TiXmlElement* field = answer->FirstChildElement(); field != nullptr; field = field->NextSiblingElement())
        {
            /*cout << "\t" << field->Attribute("ufxfield") << endl;
            cout << "\t" << field->Attribute("ufxtype") << endl;
            cout << "\t" << field->Attribute("ustfield") << endl;
            cout << "\t" << field->Attribute("default") << endl;
            cout << "\t" << field->Attribute("translater") << endl;
            cout << "\t" << field->Attribute("dictionary") << endl;*/
        }
    }
    TiXmlElement* dict = root->NextSiblingElement();

}

int main()
{
    ParseXml();
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
