/********************************************************************************
** Form generated from reading UI file 'userinterface.ui'
**
** Created: Sun Apr 3 18:40:02 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINTERFACE_H
#define UI_USERINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInterface
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionClose;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionAbout;
    QAction *actionInstructions;
    QAction *actionClose_2;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QCommandLinkButton *Format;
    QCommandLinkButton *generate;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QCommandLinkButton *export_2;
    QCommandLinkButton *commandLinkButton_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *plainTextEdit;
    QFrame *line;
    QTabWidget *tabWidget;
    QWidget *graph;
    QWidget *statistics;
    QLabel *graphLabel;
    QPlainTextEdit *statsText;
    QLabel *filename;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *UserInterface)
    {
        if (UserInterface->objectName().isEmpty())
            UserInterface->setObjectName(QString::fromUtf8("UserInterface"));
        UserInterface->setEnabled(true);
        UserInterface->resize(1024, 768);
        UserInterface->setMinimumSize(QSize(1024, 768));
        UserInterface->setBaseSize(QSize(1024, 768));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        UserInterface->setWindowIcon(icon);
        UserInterface->setAutoFillBackground(true);
        actionNew = new QAction(UserInterface);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon1);
        actionOpen = new QAction(UserInterface);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon2);
        actionCopy = new QAction(UserInterface);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon3);
        actionPaste = new QAction(UserInterface);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon4);
        actionClose = new QAction(UserInterface);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionClose->setCheckable(false);
        actionSave = new QAction(UserInterface);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon5);
        actionSave_As = new QAction(UserInterface);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionAbout = new QAction(UserInterface);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionInstructions = new QAction(UserInterface);
        actionInstructions->setObjectName(QString::fromUtf8("actionInstructions"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/icon_big.gif"), QSize(), QIcon::Normal, QIcon::Off);
        actionInstructions->setIcon(icon6);
        actionClose_2 = new QAction(UserInterface);
        actionClose_2->setObjectName(QString::fromUtf8("actionClose_2"));
        centralWidget = new QWidget(UserInterface);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 91, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(520, 0, 61, 21));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 630, 491, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Format = new QCommandLinkButton(horizontalLayoutWidget);
        Format->setObjectName(QString::fromUtf8("Format"));

        horizontalLayout->addWidget(Format);

        generate = new QCommandLinkButton(horizontalLayoutWidget);
        generate->setObjectName(QString::fromUtf8("generate"));

        horizontalLayout->addWidget(generate);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(520, 630, 491, 61));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        export_2 = new QCommandLinkButton(horizontalLayoutWidget_2);
        export_2->setObjectName(QString::fromUtf8("export_2"));

        horizontalLayout_2->addWidget(export_2);

        commandLinkButton_2 = new QCommandLinkButton(horizontalLayoutWidget_2);
        commandLinkButton_2->setObjectName(QString::fromUtf8("commandLinkButton_2"));

        horizontalLayout_2->addWidget(commandLinkButton_2);

        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 20, 1001, 601));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new QPlainTextEdit(horizontalLayoutWidget_3);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QFont font;
        font.setPointSize(11);
        plainTextEdit->setFont(font);
        plainTextEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        plainTextEdit->setContextMenuPolicy(Qt::ActionsContextMenu);

        horizontalLayout_3->addWidget(plainTextEdit);

        line = new QFrame(horizontalLayoutWidget_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        tabWidget = new QTabWidget(horizontalLayoutWidget_3);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/default.jpg);"));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        graph = new QWidget();
        graph->setObjectName(QString::fromUtf8("graph"));
        tabWidget->addTab(graph, QString());
        statistics = new QWidget();
        statistics->setObjectName(QString::fromUtf8("statistics"));
        graphLabel = new QLabel(statistics);
        graphLabel->setObjectName(QString::fromUtf8("graphLabel"));
        graphLabel->setGeometry(QRect(0, 0, 491, 581));
        statsText = new QPlainTextEdit(statistics);
        statsText->setObjectName(QString::fromUtf8("statsText"));
        statsText->setGeometry(QRect(0, 0, 491, 581));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        statsText->setFont(font1);
        statsText->setOverwriteMode(false);
        statsText->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        statsText->setBackgroundVisible(false);
        tabWidget->addTab(statistics, QString());

        horizontalLayout_3->addWidget(tabWidget);

        filename = new QLabel(centralWidget);
        filename->setObjectName(QString::fromUtf8("filename"));
        filename->setGeometry(QRect(110, 0, 401, 21));
        filename->setFrameShadow(QFrame::Sunken);
        filename->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);
        UserInterface->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UserInterface);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        UserInterface->setMenuBar(menuBar);
        statusBar = new QStatusBar(UserInterface);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UserInterface->setStatusBar(statusBar);
        mainToolBar = new QToolBar(UserInterface);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        UserInterface->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionClose);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionInstructions);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionCopy);
        mainToolBar->addAction(actionPaste);
        mainToolBar->addAction(actionInstructions);

        retranslateUi(UserInterface);
        QObject::connect(commandLinkButton_2, SIGNAL(clicked()), UserInterface, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UserInterface);
    } // setupUi

    void retranslateUi(QMainWindow *UserInterface)
    {
        UserInterface->setWindowTitle(QApplication::translate("UserInterface", "iCanC", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        UserInterface->setStatusTip(QApplication::translate("UserInterface", "Ready", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionNew->setText(QApplication::translate("UserInterface", "New", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("UserInterface", "New File", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionNew->setStatusTip(QApplication::translate("UserInterface", "New", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionOpen->setText(QApplication::translate("UserInterface", "Open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("UserInterface", "Open an existing file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionOpen->setStatusTip(QApplication::translate("UserInterface", "Open", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionCopy->setText(QApplication::translate("UserInterface", "Copy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionCopy->setStatusTip(QApplication::translate("UserInterface", "Copy", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionPaste->setText(QApplication::translate("UserInterface", "Paste", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionPaste->setStatusTip(QApplication::translate("UserInterface", "Paste", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionClose->setText(QApplication::translate("UserInterface", "Close", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("UserInterface", "Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("UserInterface", "Save the current file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSave->setStatusTip(QApplication::translate("UserInterface", "Save", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionSave_As->setText(QApplication::translate("UserInterface", "Save As", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionSave_As->setStatusTip(QApplication::translate("UserInterface", "Save As", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionAbout->setText(QApplication::translate("UserInterface", "About iCanC", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionAbout->setStatusTip(QApplication::translate("UserInterface", "About", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionInstructions->setText(QApplication::translate("UserInterface", "Instructions", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionInstructions->setStatusTip(QApplication::translate("UserInterface", "Instructions", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionClose_2->setText(QApplication::translate("UserInterface", "Close", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UserInterface", "Source Code:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("UserInterface", "Analysis", 0, QApplication::UnicodeUTF8));
        Format->setText(QApplication::translate("UserInterface", "Format", 0, QApplication::UnicodeUTF8));
        generate->setText(QApplication::translate("UserInterface", "Generate", 0, QApplication::UnicodeUTF8));
        export_2->setText(QApplication::translate("UserInterface", "Export", 0, QApplication::UnicodeUTF8));
        commandLinkButton_2->setText(QApplication::translate("UserInterface", "Close", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(graph), QApplication::translate("UserInterface", "Flow Graph", 0, QApplication::UnicodeUTF8));
        graphLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(statistics), QApplication::translate("UserInterface", "Statistics", 0, QApplication::UnicodeUTF8));
        filename->setText(QApplication::translate("UserInterface", "filename", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("UserInterface", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("UserInterface", "Edit", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("UserInterface", "Help", 0, QApplication::UnicodeUTF8));
        mainToolBar->setWindowTitle(QApplication::translate("UserInterface", "iCanC", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        mainToolBar->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class UserInterface: public Ui_UserInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINTERFACE_H
