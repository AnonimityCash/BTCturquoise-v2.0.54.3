// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The BTCturquoise Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BTCTURQUOISE_BTCTURQUOISECONSENSUS_H
#define BTCTURQUOISE_BTCTURQUOISECONSENSUS_H

#include <stdint.h>

#if defined(BUILD_BTCTURQUOISE_INTERNAL) && defined(HAVE_CONFIG_H)
#include <config/btcturquoise-config.h>
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBBTCTURQUOISECONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define BTCTURQUOISECONSENSUS_API_VER 0

typedef enum btcturquoiseconsensus_error_t
{
    btcturquoiseconsensus_ERR_OK = 0,
    btcturquoiseconsensus_ERR_TX_INDEX,
    btcturquoiseconsensus_ERR_TX_SIZE_MISMATCH,
    btcturquoiseconsensus_ERR_TX_DESERIALIZE,
    btcturquoiseconsensus_ERR_INVALID_FLAGS,
} btcturquoiseconsensus_error;

/** Script verification flags */
enum
{
    btcturquoiseconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    btcturquoiseconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    btcturquoiseconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    btcturquoiseconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    btcturquoiseconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    btcturquoiseconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    btcturquoiseconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = btcturquoiseconsensus_SCRIPT_FLAGS_VERIFY_P2SH | btcturquoiseconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                            btcturquoiseconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | btcturquoiseconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                            btcturquoiseconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int btcturquoiseconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, btcturquoiseconsensus_error* err);

EXPORT_SYMBOL unsigned int btcturquoiseconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // BTCTURQUOISE_BTCTURQUOISECONSENSUS_H
