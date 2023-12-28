// Copyright (c) 2011-2015 The BTCturquoise Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BTCTURQUOISE_QT_UTILITYDIALOG_H
#define BTCTURQUOISE_QT_UTILITYDIALOG_H

#include <QDialog>
#include <QObject>

class BTCturquoiseGUI;

namespace interfaces {
    class Node;
}

namespace Ui {
    class HelpMessageDialog;
}

/** "Help message" dialog box */
class HelpMessageDialog : public QDialog
{
    Q_OBJECT

public:
    enum HelpMode {
        about,
        cmdline,
        pshelp
    };

    explicit HelpMessageDialog(interfaces::Node& node, QWidget *parent, HelpMode helpMode);
    ~HelpMessageDialog();

    void printToConsole();
    void showOrPrint();

private:
    Ui::HelpMessageDialog *ui;
    QString text;

private Q_SLOTS:
    void on_okButton_accepted();
};


/** "Shutdown" window */
class ShutdownWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ShutdownWindow(interfaces::Node& node, QWidget *parent=0, Qt::WindowFlags f=0);
    static QWidget *showShutdownWindow(interfaces::Node& node, BTCturquoiseGUI *window);

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // BTCTURQUOISE_QT_UTILITYDIALOG_H
