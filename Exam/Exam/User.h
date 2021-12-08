#pragma once

struct user
{
	char* name = nullptr;
	char* phone = nullptr;
	char* email = nullptr;
	int group;//0-All,1-Family,2-Work,3-Favorites
};