/*
    A Qt widget that contains a pie chart and all of the legend information
    This also contains a sub class, PieChartLegendItem, that draws the squares
    inside of the legend
 */

#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include <QWidget>
#include <vector>
#include <NodeStat.h>
#include <PieChart.h>
#include <string.h>
#include <QPen>
#include <QPainter>
#include <QLabel>
#include <QGridLayout>


// Helper class to manage the colored squares for the legend
class PieChartLegendItem : public QWidget
{
   Q_OBJECT
public:
    explicit PieChartLegendItem(QColor c, QWidget *parent = 0);
    QSize sizeHint() const;
    ~PieChartLegendItem();
protected:
    void paintEvent(QPaintEvent *);
private:
    // Color of the square
    QColor color;
 };


class PieChartWidget : public QWidget
{
 Q_OBJECT



public:
    explicit PieChartWidget(vector<NodeStat> s, QWidget *parent = 0);
    // void remake(vector<NodeStat> s);
    QSize sizeHint() const;
    ~PieChartWidget();
private:
    // Contains all of the stats from the input program.
    vector<NodeStat> stats;
    // List of colors to use in the chart
    vector<QColor> colors;
    PieChart* chart;

    enum {NumSections = 10};
    // All of the labels (ie, the names of the decision types)
    QLabel* labels [NumSections];
    // All of the legend items.
    PieChartLegendItem* legends[NumSections];

};




#endif // PIECHARTWIDGET_H
