// Copyright (c) 2011-2014 The BTCturquoise Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BTCTURQUOISE_QT_BTCTURQUOISEADDRESSVALIDATOR_H
#define BTCTURQUOISE_QT_BTCTURQUOISEADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class BTCturquoiseAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BTCturquoiseAddressEntryValidator(QObject *parent, bool fAllowURI = false);

    State validate(QString &input, int &pos) const;

private:
    bool fAllowURI;
};

/** BTCturquoise address widget validator, checks for a valid btcturquoise address.
 */
class BTCturquoiseAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BTCturquoiseAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // BTCTURQUOISE_QT_BTCTURQUOISEADDRESSVALIDATOR_H
