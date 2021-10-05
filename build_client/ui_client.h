/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *addressLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSpinBox *portSpinBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *userLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *connectPushButton;
    QPushButton *disconnectPushButton;
    QTextEdit *log;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *textLineEdit;

    void setupUi(QWidget *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(798, 587);
        verticalLayout_2 = new QVBoxLayout(Client);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(Client);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        groupBox = new QGroupBox(Client);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        addressLineEdit = new QLineEdit(groupBox);
        addressLineEdit->setObjectName(QString::fromUtf8("addressLineEdit"));

        horizontalLayout_3->addWidget(addressLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_5);

        portSpinBox = new QSpinBox(groupBox);
        portSpinBox->setObjectName(QString::fromUtf8("portSpinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(portSpinBox->sizePolicy().hasHeightForWidth());
        portSpinBox->setSizePolicy(sizePolicy1);
        portSpinBox->setMaximum(1000000000);
        portSpinBox->setValue(9090);

        horizontalLayout_4->addWidget(portSpinBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        userLineEdit = new QLineEdit(groupBox);
        userLineEdit->setObjectName(QString::fromUtf8("userLineEdit"));

        horizontalLayout->addWidget(userLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        connectPushButton = new QPushButton(groupBox);
        connectPushButton->setObjectName(QString::fromUtf8("connectPushButton"));

        horizontalLayout_5->addWidget(connectPushButton);

        disconnectPushButton = new QPushButton(groupBox);
        disconnectPushButton->setObjectName(QString::fromUtf8("disconnectPushButton"));
        disconnectPushButton->setEnabled(false);

        horizontalLayout_5->addWidget(disconnectPushButton);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addWidget(groupBox);

        log = new QTextEdit(Client);
        log->setObjectName(QString::fromUtf8("log"));

        verticalLayout_2->addWidget(log);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Client);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        textLineEdit = new QLineEdit(Client);
        textLineEdit->setObjectName(QString::fromUtf8("textLineEdit"));

        horizontalLayout_2->addWidget(textLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QWidget *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "Client", nullptr));
        label_3->setText(QCoreApplication::translate("Client", "Server configuration", nullptr));
        groupBox->setTitle(QString());
        label_4->setText(QCoreApplication::translate("Client", "Address:", nullptr));
        addressLineEdit->setText(QCoreApplication::translate("Client", "127.0.0.1", nullptr));
        label_5->setText(QCoreApplication::translate("Client", "Port:", nullptr));
        label->setText(QCoreApplication::translate("Client", "User:", nullptr));
        connectPushButton->setText(QCoreApplication::translate("Client", "Connect", nullptr));
        disconnectPushButton->setText(QCoreApplication::translate("Client", "Disconnect", nullptr));
        label_2->setText(QCoreApplication::translate("Client", "Text:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
