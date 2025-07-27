#pragma once
#include <string>
#include "User.h"

using namespace std;
class Manager :public User
{
	string JobId;
public:
	void SetJobId(string id);

};

