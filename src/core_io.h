// Copyright (c) 2009-2015 The BTCturquoise Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BTCTURQUOISE_CORE_IO_H
#define BTCTURQUOISE_CORE_IO_H

#include <amount.h>
#include <attributes.h>

#include <string>
#include <vector>

class CBlock;
class CScript;
class CTransaction;
struct CMutableTransaction;
class uint256;
class UniValue;

struct CSpentIndexTxInfo;
struct CFutureIndexTxInfo;

// core_read.cpp
CScript ParseScript(const std::string& s);
std::string ScriptToAsmStr(const CScript& script, const bool fAttemptSighashDecode = false);
NODISCARD bool DecodeHexTx(CMutableTransaction& tx, const std::string& strHexTx);
NODISCARD bool DecodeHexBlk(CBlock&, const std::string& strHexBlk);
uint256 ParseHashStr(const std::string&, const std::string& strName);
std::vector<unsigned char> ParseHexUV(const UniValue& v, const std::string& strName);

// core_write.cpp
UniValue ValueFromAmount(const CAmount& amount);
std::string FormatScript(const CScript& script);
std::string EncodeHexTx(const CTransaction& tx);
void ScriptPubKeyToUniv(const CScript& scriptPubKey, UniValue& out, bool fIncludeHex);
void TxToUniv(const CTransaction& tx, const uint256& hashBlock, UniValue& entry, bool include_hex = true, const CSpentIndexTxInfo* ptxSpentInfo = nullptr, const CFutureIndexTxInfo* ptxFutureInfo = nullptr);

#endif // BTCTURQUOISE_CORE_IO_H
