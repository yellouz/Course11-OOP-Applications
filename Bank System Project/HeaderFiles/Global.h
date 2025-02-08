#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

#include "Utils/clsDate.h"
#include "Utils/clsInputValidate.h"
#include "Utils/clsString.h"
#include "Utils/clsUtil.h"

#include "InterfaceCommunication.h"
#include "Core/clsPerson.h"
#include "Core/clsBankClient.h"
#include "Core/clsUser.h"

clsUser CurrentUser = clsUser::Find("", "");

#include "Screens/clsScreen.h"

#include "Screens/Client/clsAddNewClientScreen.h"
#include "Screens/Client/clsClientListScreen.h"
#include "Screens/Client/clsDeleteClientScreen.h"
#include "Screens/Client/clsFindClientScreen.h"
#include "Screens/Client/clsUpdateClientScreen.h"
#include "Screens/Transactions/clsDepositScreen.h"
#include "Screens/Transactions/clsTotalBalancesScreen.h"
#include "Screens/Transactions/clsTransferScreen.h"
#include "Screens/Transactions/clsWithdrawScreen.h"
#include "Screens/User/clsAddNewUserScreen.h"
#include "Screens/User/clsDeleteUserScreen.h"
#include "Screens/User/clsFindUserScreen.h"
#include "Screens/User/clsLoginRegisterScreen.h"
#include "Screens/User/clsUpdateUserScreen.h"
#include "Screens/User/clsUsersListScreen.h"

#include "Screens/User/clsManageUsersScreen.h"
#include "Screens/Transactions/clsTransactionsScreen.h"
#include "Screens/clsMainScreen.h"
#include "Screens/clsLoginScreen.h"


using namespace std;






