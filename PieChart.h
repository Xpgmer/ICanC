/*
    Qt widget that creates a pie chart without the legend.

 */

#ifndef PIECHART_H
#define PIECHART_H

#include <QWidget>
#include <QPainter>
#include <NodeStat.h>


class PieChart : public QWidget
{
    Q_OBJECT

public:
    PieChart(vector<NodeStat>, vector<QColor>, QWidget *parent = 0);
    QSize sizeHint() const;
    ~PieChart();
protected:
    void paintEvent(QPaintEvent *event);

private:
    // Contains all of the stats about the program
    vector<NodeStat> stats;
    // A vector that contains a lot of colors to use
    vector<QColor> colors;
};

#endif // PIECHART_H
