#include "PieChart.h"
#include <vector>
#include <QtGui>

PieChart::PieChart( vector<NodeStat> s, vector<QColor> c, QWidget *parent) : QWidget(parent)
{
    stats = s;
    setWindowTitle(tr("Pie Chart"));
    colors = c;
}

QSize PieChart::sizeHint() const
{
    return (QSize(200,200));
}

PieChart::~PieChart()
{

}

void PieChart::paintEvent(QPaintEvent *)
{
    // We need the chart to be a circle that fits within the widget, so
    // we take the smallest size to define the bounding rectangle.
    int side = qMin(width(), height());

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //Translation and scaling centers the chart and puts us in a coordinate frame from -100 to 100
    painter.translate(width()/2, height()/2);
    painter.scale(side/200.0, side/200.0);


    int startAngle=0;
    int pieLength;


    for (int i = 0; i < stats.size(); i++)
    {
        NodeStat currentNode = stats.at(i);

        // The 16 is necessary because of how drawPie measures angles
        pieLength = currentNode.getFrequency() * 16 * 360;

        painter.save();
        painter.setBrush(colors.at(i));
        painter.drawPie(-100, -100, 200, 200, startAngle, pieLength);
        painter.restore();
        startAngle += pieLength;
    }


}
