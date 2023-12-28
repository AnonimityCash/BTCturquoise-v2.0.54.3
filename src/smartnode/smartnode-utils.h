// Copyright (c) 2014-2021 The Dash Core developers
// Copyright (c) 2020-2022 The BTCturquoise developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BTCTURQUOISE_SMARTNODE_MASTERNODE_UTILS_H
#define BTCTURQUOISE_SMARTNODE_MASTERNODE_UTILS_H

#include <evo/deterministicmns.h>

class CConnman;

class CSmartnodeUtils
{
public:
    static void ProcessSmartnodeConnections(CConnman& connman);
    static void DoMaintenance(CConnman &connman);
};

#endif // BTCTURQUOISE_SMARTNODE_MASTERNODE_UTILS_H
