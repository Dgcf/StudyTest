#include "FstreamTest.h"

void test_writeCharsetToFile(const string& filename)
{
	ofstream file(filename);
	if (!file)
	{
		cerr << "can not open file\n";
		return;
	}
	for (int i = 32; i < 256; ++i)
	{
		file << "value: " << setw(3) << i << " "
			<< "char: " << static_cast<char>(i) << endl;
	}
}

void outputFile(const string& filename)
{
	ifstream file(filename);
	if (!file)
	{
		cerr << "can not open input file\n";
	}
	char c;
	while (file.get(c))
	{
		cout.put(c);
	}

	// all output:
	file.clear();
	std::cout << "all output: " << file.rdbuf();
}

void test_0()
{
	// ÏÈÐ´ºó¶Á
	string filepath = "./test0.txt";
	test_writeCharsetToFile(filepath);
	outputFile(filepath);
}


void readline()
{
	ifstream f("./JYtentrusts.txt");
	string line;
	
	ofstream wf("./writefile.txt", ios::app);
	f.ignore(numeric_limits<std::streamsize>::max(), '\n');
	while (getline(f, line))
	{
		if (line.empty())
		{
			continue;
		}
		wf.write(line.c_str(), line.size());
		wf.write(",2\n", strlen(",2\n"));
	}
}

void test_readline()
{

}
