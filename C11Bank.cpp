#include <iostream>
#include "UI Layer/clsLoginScreen.h"
#include "Global.h"
#include "Middle Layer/clsUser.h"

int main()
{
	while(clsSession::LoginTries)
		clsLoginScreen::Login();
}