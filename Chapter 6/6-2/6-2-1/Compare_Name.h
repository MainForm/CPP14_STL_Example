#ifndef COMPARE_NAMES_H
#define COMPAER_NAMES_H

#include "Account.h"

class Compare_Names
{
public:
	bool operator()(const Account& acc1, const Account& acc2) {
		const auto& name1 = acc1.get_name();
		const auto& name2 = acc2.get_name();

		return (name1.second < name2.second) || 
			((name1.second == name2.second) && (name1.first < name2.first));

	}
};

#endif