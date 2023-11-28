#include "orderFile.h"
pair<string, string> splitstr(string str)
{
	string key;
	string value;
	int pos = str.find(":");//data:1
	if (pos != -1)
	{
		key = str.substr(0, pos);
		value = str.substr(pos + 1, str.size() - pos - 1);
		return make_pair(key, value);
	}
}
orderFile::orderFile()
{
	ifstream ifs(ORDER_FILE, ios::in);
	string data;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;
	while (ifs >> data && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		//cout << data << endl;
		//cout << interval << endl;
		//cout << stuId << endl;
		//cout << stuName << endl;
		//cout << roomId << endl;
		//cout << status << endl;
		//cout << endl;//测试
		
		map<string, string> m;
		m.insert(splitstr(data));
		m.insert(splitstr(interval));
		m.insert(splitstr(stuId));
		m.insert(splitstr(stuName));
		m.insert(splitstr(roomId));
		m.insert(splitstr(status));
		this->m_orderDate.insert(make_pair(m_Size, m));
		this->m_Size++;
	}
	ifs.close();
	//测试
	/*for (map<int, map<string, string>>::iterator it = m_orderDate.begin(); it != m_orderDate.end(); it++)
	{
		cout << "条数：" << it->first << "  信息为： " << endl;
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
		{
			cout << "key = " << mit->first << " value = " << mit->second << endl;
		}
		cout << endl;
	}*/

}
void orderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "data:" << this->m_orderDate[i]["data"] << " ";
		ofs << "interval:" << this->m_orderDate[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderDate[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderDate[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderDate[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderDate[i]["status"] << endl;
	}
	ofs.close();
}