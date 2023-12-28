// Copyright (c) 2011-2015 The BTCturquoise Core developers
// Copyright (c) 2014-2020 The Dash Core developers
// Copyright (c) 2020-2021 The BTCturquoise developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <qt/btcturquoiseunits.h>
#include <chainparams.h>
#include <primitives/transaction.h>
#include <validation.h>

#include <QSettings>
#include <QStringList>

BTCturquoiseUnits::BTCturquoiseUnits(QObject *parent):
        QAbstractListModel(parent),
        unitlist(availableUnits())
{
}

QList<BTCturquoiseUnits::Unit> BTCturquoiseUnits::availableUnits()
{
    QList<BTCturquoiseUnits::Unit> unitlist;
    unitlist.append(BTCQ);
    unitlist.append(mBTCQ);
    unitlist.append(uBTCQ);
    unitlist.append(ruffs);
    return unitlist;
}

bool BTCturquoiseUnits::valid(int unit)
{
    switch(unit)
    {
    case BTCQ:
    case mBTCQ:
    case uBTCQ:
    case ruffs:
        return true;
    default:
        return false;
    }
}

QString BTCturquoiseUnits::name(int unit)
{
    if(Params().NetworkIDString() == CBaseChainParams::MAIN)
    {
        switch(unit)
        {
            case BTCQ: return QString("BTCQ");
            case mBTCQ: return QString("mBTCQ");
            case uBTCQ: return QString::fromUtf8("μBTCQ");
            case ruffs: return QString("ruffs");
            default: return QString("???");
        }
    }
    else
    {
        switch(unit)
        {
            case BTCQ: return QString("tBTCQ");
            case mBTCQ: return QString("mtBTCQ");
            case uBTCQ: return QString::fromUtf8("μtBTCQ");
            case ruffs: return QString("truffs");
            default: return QString("???");
        }
    }
}

QString BTCturquoiseUnits::description(int unit)
{
    if(Params().NetworkIDString() == CBaseChainParams::MAIN)
    {
        switch(unit)
        {
            case BTCQ: return QString("BTCturquoise");
            case mBTCQ: return QString("Milli-BTCturquoise (1 / 1" THIN_SP_UTF8 "000)");
            case uBTCQ: return QString("Micro-BTCturquoise (1 / 1" THIN_SP_UTF8 "000" THIN_SP_UTF8 "000)");
            case ruffs: return QString("Ten Nano-BTCturquoise (1 / 100" THIN_SP_UTF8 "000" THIN_SP_UTF8 "000)");
            default: return QString("???");
        }
    }
    else
    {
        switch(unit)
        {
            case BTCQ: return QString("TestBTCturquoises");
            case mBTCQ: return QString("Milli-TestBTCturquoise (1 / 1" THIN_SP_UTF8 "000)");
            case uBTCQ: return QString("Micro-TestBTCturquoise (1 / 1" THIN_SP_UTF8 "000" THIN_SP_UTF8 "000)");
            case ruffs: return QString("Ten Nano-TestBTCturquoise (1 / 100" THIN_SP_UTF8 "000" THIN_SP_UTF8 "000)");
            default: return QString("???");
        }
    }
}

qint64 BTCturquoiseUnits::factor(int unit)
{
    switch(unit)
    {
    case BTCQ:  return 100000000;
    case mBTCQ: return 100000;
    case uBTCQ: return 100;
    case ruffs: return 1;
    default:   return 100000000;
    }
}

int BTCturquoiseUnits::decimals(int unit)
{
    switch(unit)
    {
    case BTCQ: return 8;
    case mBTCQ: return 5;
    case uBTCQ: return 2;
    case ruffs: return 0;
    default: return 0;
    }
}

QString BTCturquoiseUnits::format(int unit, const CAmount& nIn, bool fPlus, SeparatorStyle separators)
{
    // Note: not using straight sprintf here because we do NOT want
    // localized number formatting.
    if(!valid(unit))
        return QString(); // Refuse to format invalid unit
    qint64 n = (qint64)nIn;
    qint64 coin = factor(unit);
    int num_decimals = decimals(unit);
    qint64 n_abs = (n > 0 ? n : -n);
    qint64 quotient = n_abs / coin;
    qint64 remainder = n_abs % coin;
    QString quotient_str = QString::number(quotient);
    QString remainder_str = QString::number(remainder).rightJustified(num_decimals, '0');

    // Use SI-style thin space separators as these are locale independent and can't be
    // confused with the decimal marker.
    QChar thin_sp(THIN_SP_CP);
    int q_size = quotient_str.size();
    if (separators == separatorAlways || (separators == separatorStandard && q_size > 4))
        for (int i = 3; i < q_size; i += 3)
            quotient_str.insert(q_size - i, thin_sp);

    if (n < 0)
        quotient_str.insert(0, '-');
    else if (fPlus && n > 0)
        quotient_str.insert(0, '+');

    if (num_decimals <= 0)
        return quotient_str;

    return quotient_str + QString(".") + remainder_str;
}


// NOTE: Using formatWithUnit in an HTML context risks wrapping
// quantities at the thousands separator. More subtly, it also results
// in a standard space rather than a thin space, due to a bug in Qt's
// XML whitespace canonicalisation
//
// Please take care to use formatHtmlWithUnit instead, when
// appropriate.

QString BTCturquoiseUnits::formatWithUnit(int unit, const CAmount& amount, bool plussign, SeparatorStyle separators)
{
    return format(unit, amount, plussign, separators) + QString(" ") + name(unit);
}

QString BTCturquoiseUnits::formatHtmlWithUnit(int unit, const CAmount& amount, bool plussign, SeparatorStyle separators)
{
    QString str(formatWithUnit(unit, amount, plussign, separators));
    str.replace(QChar(THIN_SP_CP), QString(THIN_SP_HTML));
    return QString("<span style='white-space: nowrap;'>%1</span>").arg(str);
}

QString BTCturquoiseUnits::floorWithUnit(int unit, const CAmount& amount, bool plussign, SeparatorStyle separators)
{
    QSettings settings;
    int digits = settings.value("digits").toInt();

    QString result = format(unit, amount, plussign, separators);
    if(decimals(unit) > digits) result.chop(decimals(unit) - digits);

    return result + QString(" ") + name(unit);
}

QString BTCturquoiseUnits::floorHtmlWithUnit(int unit, const CAmount& amount, bool plussign, SeparatorStyle separators)
{
    QString str(floorWithUnit(unit, amount, plussign, separators));
    str.replace(QChar(THIN_SP_CP), QString(THIN_SP_HTML));
    return QString("<span style='white-space: nowrap;'>%1</span>").arg(str);
}

bool BTCturquoiseUnits::parse(int unit, const QString &value, CAmount *val_out)
{
    if(!valid(unit) || value.isEmpty())
        return false; // Refuse to parse invalid unit or empty string
    int num_decimals = decimals(unit);

    // Ignore spaces and thin spaces when parsing
    QStringList parts = removeSpaces(value).split(".");

    if(parts.size() > 2)
    {
        return false; // More than one dot
    }
    QString whole = parts[0];
    QString decimals;

    if(parts.size() > 1)
    {
        decimals = parts[1];
    }
    if(decimals.size() > num_decimals)
    {
        return false; // Exceeds max precision
    }
    bool ok = false;
    QString str = whole + decimals.leftJustified(num_decimals, '0');

    if(str.size() > 18)
    {
        return false; // Longer numbers will exceed 63 bits
    }
    CAmount retvalue(str.toLongLong(&ok));
    if(val_out)
    {
        *val_out = retvalue;
    }
    return ok;
}

QString BTCturquoiseUnits::getAmountColumnTitle(int unit)
{
    QString amountTitle = QObject::tr("Amount");
    if (BTCturquoiseUnits::valid(unit))
    {
        amountTitle += " ("+BTCturquoiseUnits::name(unit) + ")";
    }
    return amountTitle;
}

int BTCturquoiseUnits::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return unitlist.size();
}

QVariant BTCturquoiseUnits::data(const QModelIndex &index, int role) const
{
    return data(index.row(), role);
}

QVariant BTCturquoiseUnits::data(const int &row, int role) const
{
    if(row >= 0 && row < unitlist.size())
    {
        Unit unit = unitlist.at(row);
        switch(role)
        {
        case Qt::EditRole:
        case Qt::DisplayRole:
            return QVariant(name(unit));
        case Qt::ToolTipRole:
            return QVariant(description(unit));
        case UnitRole:
            return QVariant(static_cast<int>(unit));
        }
    }
    return QVariant();
}

CAmount BTCturquoiseUnits::maxMoney()
{
    if(Params().IsFutureActive(chainActive.Tip())){
        return MAX_MONEY;    
    }else{
        return OLD_MAX_MONEY;  
    }
}
