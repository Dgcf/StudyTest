#include "Unorder.h"

void unorder_set_test_0()
{
	unordered_set<int> coll = { 1,2,3,5,7,11,13,17,19,77 };

	cout << "coll: " << endl;
	for_each(coll.begin(), coll.end(), [](int it) {
		cout << it << " ";
		}
	);
	cout << endl;

	coll.insert({ -7, 17, 33, -11, 17, 19, 1, 13 });
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	coll.erase(33);
	cout << endl;
	coll.insert(accumulate(coll.begin(), coll.end(), 0));
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));

	cout << endl;
}
