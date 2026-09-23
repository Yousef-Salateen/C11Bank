#pragma once

#include "Middle Layer/clsClientManager.h"
#include "Middle Layer/clsUserManager.h"
#include "Middle Layer/clsLoginLogManager.h"
#include "Middle Layer/clsTransferLogManager.h"

enum enPermissions : short {
	eAll = -1, eListClients = 1, eAddNewClient = 2, eDeleteClient = 4, eUpdateClient = 8,
	eFindClient = 16, eTransactions = 32, eManageUsers = 64, eListLoginLogs = 128
};

short _EncryptionKey = 3;


clsClientManager Clients;
clsUserManager Users;
clsLoginLogManager LoginLogs;
clsTransferLogManager TransferLogs;