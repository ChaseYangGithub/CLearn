/********************************************************************************
** Form generated from reading UI file 'mainscene.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScene
{
public:
    QAction *actionLeaderBoard;
    QAction *actionLoginOut;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainScene)
    {
        if (MainScene->objectName().isEmpty())
            MainScene->setObjectName(QStringLiteral("MainScene"));
        MainScene->resize(400, 300);
        actionLeaderBoard = new QAction(MainScene);
        actionLeaderBoard->setObjectName(QStringLiteral("actionLeaderBoard"));
        actionLoginOut = new QAction(MainScene);
        actionLoginOut->setObjectName(QStringLiteral("actionLoginOut"));
        centralWidget = new QWidget(MainScene);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainScene->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainScene);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainScene->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionLeaderBoard);
        menu->addSeparator();
        menu->addAction(actionLoginOut);

        retranslateUi(MainScene);

        QMetaObject::connectSlotsByName(MainScene);
    } // setupUi

    void retranslateUi(QMainWindow *MainScene)
    {
        MainScene->setWindowTitle(QApplication::translate("MainScene", "MainScene", 0));
        actionLeaderBoard->setText(QApplication::translate("MainScene", "\346\216\222\350\241\214\346\246\234", 0));
        actionLoginOut->setText(QApplication::translate("MainScene", "\351\200\200\345\207\272", 0));
        menu->setTitle(QApplication::translate("MainScene", "\350\217\234\345\215\225", 0));
    } // retranslateUi

};

namespace Ui {
    class MainScene: public Ui_MainScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H
