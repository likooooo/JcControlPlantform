/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCreateSln;
    QAction *actionOpenSln;
    QAction *actionCreateProj;
    QAction *actionOpenProj;
    QAction *actionFindAndReplace;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionzhantie;
    QAction *actionDelete;
    QAction *actionStartRun;
    QAction *actionHelp;
    QAction *actionAbout;
    QWidget *centralwidget;
    QMenuBar *menuBtn;
    QMenu *menu_F;
    QMenu *menu_E;
    QMenu *menu_D;
    QMenu *menu_T;
    QMenu *menu_H;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionCreateSln = new QAction(MainWindow);
        actionCreateSln->setObjectName(QStringLiteral("actionCreateSln"));
        actionOpenSln = new QAction(MainWindow);
        actionOpenSln->setObjectName(QStringLiteral("actionOpenSln"));
        actionCreateProj = new QAction(MainWindow);
        actionCreateProj->setObjectName(QStringLiteral("actionCreateProj"));
        actionOpenProj = new QAction(MainWindow);
        actionOpenProj->setObjectName(QStringLiteral("actionOpenProj"));
        actionFindAndReplace = new QAction(MainWindow);
        actionFindAndReplace->setObjectName(QStringLiteral("actionFindAndReplace"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionzhantie = new QAction(MainWindow);
        actionzhantie->setObjectName(QStringLiteral("actionzhantie"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionStartRun = new QAction(MainWindow);
        actionStartRun->setObjectName(QStringLiteral("actionStartRun"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menuBtn = new QMenuBar(MainWindow);
        menuBtn->setObjectName(QStringLiteral("menuBtn"));
        menuBtn->setGeometry(QRect(0, 0, 800, 23));
        menu_F = new QMenu(menuBtn);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menu_E = new QMenu(menuBtn);
        menu_E->setObjectName(QStringLiteral("menu_E"));
        menu_D = new QMenu(menuBtn);
        menu_D->setObjectName(QStringLiteral("menu_D"));
        menu_T = new QMenu(menuBtn);
        menu_T->setObjectName(QStringLiteral("menu_T"));
        menu_H = new QMenu(menuBtn);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        MainWindow->setMenuBar(menuBtn);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menuBtn->addAction(menu_F->menuAction());
        menuBtn->addAction(menu_E->menuAction());
        menuBtn->addAction(menu_D->menuAction());
        menuBtn->addAction(menu_T->menuAction());
        menuBtn->addAction(menu_H->menuAction());
        menu_F->addAction(actionCreateSln);
        menu_F->addAction(actionOpenSln);
        menu_F->addSeparator();
        menu_F->addAction(actionCreateProj);
        menu_F->addAction(actionOpenProj);
        menu_E->addAction(actionFindAndReplace);
        menu_E->addSeparator();
        menu_E->addAction(actionCut);
        menu_E->addAction(actionCopy);
        menu_E->addAction(actionzhantie);
        menu_E->addAction(actionDelete);
        menu_D->addAction(actionStartRun);
        menu_H->addAction(actionHelp);
        menu_H->addSeparator();
        menu_H->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "HelloQtTitle", Q_NULLPTR));
        actionCreateSln->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\247\243\345\206\263\346\226\271\346\241\210(N)", Q_NULLPTR));
        actionOpenSln->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\350\247\243\345\206\263\346\226\271\346\241\210(O)", Q_NULLPTR));
        actionCreateProj->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256(N)", Q_NULLPTR));
        actionOpenProj->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\351\241\271\347\233\256(O)", Q_NULLPTR));
        actionFindAndReplace->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\345\222\214\346\233\277\346\215\242(F)", Q_NULLPTR));
        actionCut->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207(T)", Q_NULLPTR));
        actionCopy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266(C)", Q_NULLPTR));
        actionzhantie->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264(V)", Q_NULLPTR));
        actionDelete->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244(D)", Q_NULLPTR));
        actionStartRun->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\350\260\203\350\257\225(F5)", Q_NULLPTR));
        actionHelp->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251(F1)", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216(A)", Q_NULLPTR));
        menu_F->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(F)", Q_NULLPTR));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(E)", Q_NULLPTR));
        menu_D->setTitle(QApplication::translate("MainWindow", "\350\260\203\350\257\225(D)", Q_NULLPTR));
        menu_T->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267(T)", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(H)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
