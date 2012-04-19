#include "userinterface.h"
#include "ui_userinterface.h"
#include <cstdlib>
#include <sys/param.h>
#include <iostream>
#include <unistd.h>
#include <string>
#include <sstream>
#include <QtGui>
#include <QGridLayout>
#include "SourceFormat.h"
#include "NodeData.h"
#include "NodeStat.h"
#include "LogicAnalyzer.h"
#include "CyclomaticComplexity.h"

#define FREQACC 5


UserInterface::UserInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);
    setCurrentFile("");

    vector<NodeStat> empty;

    pieChart = new PieChartWidget(empty, this);

    ui->tabWidget->addTab(pieChart, tr("Pie Chart"));
}

UserInterface::~UserInterface()
{
    delete ui;
}

void UserInterface::about()
{
   QMessageBox::about(this, tr("About iCanC"),
            tr("The <b>iCanC</b> program provides a flow graph and statistical analysis representing C source code. <br>"
               "iCanC was created and developed by Team Cougar: Matt Oskamp, Kieran Lafferty, Rachel Zhang, "
               "Andrew Murray, and Matthew Ma."));
}

void UserInterface::instructions() {
    QMessageBox::about(this, tr("iCanC Instructions"),
             tr("Welcome to <b>iCanC</b>! <br> "
                "1. Click <b>Open</b> to select the source code file (<i>*.c</i>) you wish to analyze. <br>"
                "2. Click <b>Generate</b> to view the analysis (flow chart and statistics). <br><br>"
                "You can edit your code within iCanC and compile it by clicking <b>Compile</b>. <br>"
                "Exit the program by clicking <b>Close</b>."));
}

void UserInterface::loadFile(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("iCanC"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    QTextStream in(&file);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    ui->plainTextEdit->setPlainText(in.readAll());
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif
    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
}

bool UserInterface::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("iCanC"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    out << ui->plainTextEdit->toPlainText();
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

void UserInterface::setCurrentFile(const QString &fileName)
{
    curFile = fileName;
    ui->plainTextEdit->document()->setModified(false);
    setWindowModified(false);

    QString shownName = curFile;
    if (curFile.isEmpty())
        shownName = "untitled.txt";
    ui->filename->setText(shownName);
    setWindowFilePath(shownName);
}

bool UserInterface::maybeSave()
{
    if (ui->plainTextEdit->document()->isModified()) {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("iCanC"),
                     tr("The document has been modified.\n"
                        "Do you want to save your changes?"),
                     QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
            return on_actionSave_triggered();
        else if (ret == QMessageBox::Cancel)
            return false;
    }
    return true;
}

void UserInterface::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

bool UserInterface::on_actionSave_triggered()
{
    if (curFile.isEmpty()) {
        return on_actionSave_As_triggered();
    } else {
        return saveFile(curFile);
    }
}

bool UserInterface::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

void UserInterface::on_actionNew_triggered()
{
    if (maybeSave()) {
        ui->plainTextEdit->clear();
        setCurrentFile("");
    }
}

void UserInterface::on_actionOpen_triggered()
{
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this,"Open File",QDesktopServices::storageLocation(QDesktopServices ::DocumentsLocation),"*.c");
        if (!fileName.isEmpty())
            loadFile(fileName);
    }
}

void UserInterface::on_actionClose_triggered()
{
    close();
}

void UserInterface::on_actionAbout_triggered()
{
    about();
}

void UserInterface::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}

void UserInterface::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();
}

void UserInterface::on_actionInstructions_triggered()
{
    instructions();
}

void UserInterface::on_Format_clicked()
{
    on_actionSave_triggered();
    string file = curFile.toLocal8Bit().constData();
    SourceFormat SourceCode(file);
    try {
        SourceCode.runAStyle();
    }
    catch (exception e) {
        QMessageBox::warning(this, tr("iCanC"), tr("Cannot run AStyle."));
    }
    loadFile(curFile);
    statusBar()->showMessage(tr("File formatted"), 2000);
}

void UserInterface::on_generate_clicked()
{
    if (curFile == "") {
        on_actionOpen_triggered();
    }
    on_actionSave_triggered();
    string file = curFile.toLocal8Bit().constData();
    SourceFormat SourceCode(file);
    string PDFdest;
    try {
        SourceCode.runAStyle();
    }
    catch (exception e) {
        QMessageBox::warning(this, tr("iCanC"), tr("Cannot run AStyle."));
    }
    vector<NodeData> holder(SourceCode.getNodes());
    LogicAnalyzer la(holder, PDFdest);
    la.createAdjacencyMatrix();

    vector<NodeStat> stats;
    stats.push_back(NodeStat("if", holder));
    stats.push_back(NodeStat("else", holder));
    stats.push_back(NodeStat("while", holder));
    stats.push_back(NodeStat("for", holder));
    stats.push_back(NodeStat("switch", holder));
    stats.push_back(NodeStat("case", holder));

    CyclomaticComplexity cc = CyclomaticComplexity(holder, la.createAdjacencyMatrix());


    showGraph();
    showStatistics(stats, cc);
    //showPieChart(stats);

}

void UserInterface::showGraph() {
    ui->graph->setStyleSheet("background-image: url(analysis.png) stretch;"
                            "background-color: white;"
                            "background-repeat: none;"
                            "background-position: top center;"
                            "background-origin: padding;"
                            "border-width: 4px");
    QPixmap flowGraph;
    //QPainter painter;
    flowGraph.load("analysis.png");
    //painter.drawPicture(0,0,analysis);
    //flowGraph.scroll(600,600,flowGraph.rect(), &exposed);
    ui->graphLabel->setPixmap(flowGraph);

}

void UserInterface::showStatistics(vector<NodeStat> stats, CyclomaticComplexity cc)
{
    ui->statistics->setStyleSheet("background-color: white;"
                            "background-repeat: none;"
                            "background-position: top center;"
                            "background-origin: padding;"
                            "border-width: 4px");


    ui->statsText->clear();
    ui->statsText->insertPlainText(tr("Logic \t Frequency\n"));

    int complexity = cc.getCyclomaticComplexity();


    for (int i = 0; i < stats.size(); i++)
    {
        NodeStat current = stats.at(i);
        string freqStr;

        {   std::ostringstream ss;
            ss << current.getFrequency();
            freqStr = ss.str();
        }
        std:string toAdd = current.getName() + " \t " + freqStr + "\n";
        ui->statsText->insertPlainText(tr(toAdd.c_str()));

    }

    string compStr;

    {   std::ostringstream ss;
        ss << complexity;
        compStr = ss.str();
    }
    string toAdd = "\n McCabe Complexity:\t" + compStr;
    ui->statsText->insertPlainText(toAdd.c_str());

    toAdd = "\n\n Paths:\n";
    ui->statsText->insertPlainText(toAdd.c_str());

    toAdd = cc.printPaths();
    ui->statsText->insertPlainText(toAdd.c_str());


}

void UserInterface::showPieChart(vector<NodeStat> stats)
{
    delete pieChart;
    pieChart = new PieChartWidget(stats, this);
    ui->tabWidget->addTab(pieChart, tr("Pie Chart"));
}
