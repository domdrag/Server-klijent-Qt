/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *nazivLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *disconnectPushButton;
    QLabel *label_2;
    QPlainTextEdit *log;

    void setupUi(QWidget *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QString::fromUtf8("Server"));
        Server->resize(800, 600);
        verticalLayout = new QVBoxLayout(Server);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        nazivLabel = new QLabel(Server);
        nazivLabel->setObjectName(QString::fromUtf8("nazivLabel"));

        horizontalLayout->addWidget(nazivLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        disconnectPushButton = new QPushButton(Server);
        disconnectPushButton->setObjectName(QString::fromUtf8("disconnectPushButton"));
        disconnectPushButton->setEnabled(false);

        horizontalLayout->addWidget(disconnectPushButton);


        verticalLayout->addLayout(horizontalLayout);

        label_2 = new QLabel(Server);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        log = new QPlainTextEdit(Server);
        log->setObjectName(QString::fromUtf8("log"));
        log->setReadOnly(true);

        verticalLayout->addWidget(log);


        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QWidget *Server)
    {
        Server->setWindowTitle(QCoreApplication::translate("Server", "Server", nullptr));
        nazivLabel->setText(QCoreApplication::translate("Server", "127.0.0.1 9090", nullptr));
        disconnectPushButton->setText(QCoreApplication::translate("Server", "Disconnect", nullptr));
        label_2->setText(QCoreApplication::translate("Server", "Log:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
