#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QMainWindow>
#include <vector>
#include "NodeStat.h"
#include "PieChartWidget.h"
#include <CyclomaticComplexity.h>
QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPlainTextEdit;
QT_END_NAMESPACE

namespace Ui {
    class UserInterface;
}

class UserInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserInterface(QWidget *parent = 0);
    ~UserInterface();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::UserInterface *ui;
    void loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    void showStatistics(vector<NodeStat> stats, CyclomaticComplexity cc);
    void showPieChart(vector<NodeStat> stats);
    QString curFile;
    PieChartWidget* pieChart;

private slots:
    void on_generate_clicked();
    void on_Format_clicked();
    void on_actionInstructions_triggered();
    void on_actionPaste_triggered();
    void on_actionCopy_triggered();
    void on_actionAbout_triggered();
    void on_actionClose_triggered();
    void on_actionOpen_triggered();
    void on_actionNew_triggered();
    bool on_actionSave_As_triggered();
    bool on_actionSave_triggered();
    void about();
    void instructions();
    void showGraph();

    bool maybeSave();
};

#endif // USERINTERFACE_H
