#include "PieChartWidget.h"

PieChartWidget::PieChartWidget(vector<NodeStat> s, QWidget *parent) : QWidget(parent)
{
    stats = s;
    vector<QColor> colors;
    colors.push_back(QColor(255, 0, 0));
    colors.push_back(QColor(0, 255, 255));
    colors.push_back(QColor(255, 255, 0));
    colors.push_back(QColor(0, 255, 0));
    colors.push_back(QColor(255, 0, 255));
    colors.push_back(QColor(0, 0, 255));

    colors.push_back(QColor(255, 128, 128));
    colors.push_back(QColor(128, 255, 255));
    colors.push_back(QColor(255, 255, 128));
    colors.push_back(QColor(128, 255, 128));
    colors.push_back(QColor(255, 128, 255));
    colors.push_back(QColor(128, 128, 255));

    QGridLayout* layout = new QGridLayout(this);
    layout->setHorizontalSpacing(5);


    chart = new PieChart(stats, colors, this);

    // The chart takes up four slots in the grid
    layout->addWidget(chart,0,0,2,2);

    for (int i = 0; i < stats.size(); i++)
    {
        legends[i] = new PieChartLegendItem(colors.at(i));
        layout->addWidget(legends[i], i + 2, 0);

        labels[i] = new QLabel(tr(stats.at(i).getName().c_str()));
        layout->addWidget(labels[i], i + 2, 1, Qt::AlignLeft);
    }
}

/*
void PieChartWidget::remake(vector<NodeStat> s)
{
    stats = s;
    delete chart;

    chart = new PieChart(stats, colors, this);

    // The chart takes up four slots in the grid
    layout->addWidget(chart,0,0,2,2);

    for (int i = 0; i < stats.size(); i++)
    {
        legends[i] = new PieChartLegendItem(colors.at(i), this);
        layout->addWidget(legends[i], i + 2, 0);

        labels[i] = new QLabel(tr(stats.at(i).getName().c_str()),this);
        layout->addWidget(labels[i], i + 2, 1, Qt::AlignLeft);
    }
}
*/

PieChartWidget::~PieChartWidget()
{
    delete chart;
    for(int i = 0; i < stats.size(); i++)
    {
        delete legends[i];
    }
}

QSize PieChartWidget::sizeHint() const
{
    return(QSize(400,600));
}



PieChartLegendItem::PieChartLegendItem(QColor c, QWidget *parent) : QWidget(parent)

{
    color = c;
    this->setMaximumSize(25,25);
}

PieChartLegendItem::~PieChartLegendItem()
{
}

QSize PieChartLegendItem::sizeHint() const
{
    return (QSize(25,25));

}

void PieChartLegendItem::paintEvent(QPaintEvent *)
{
    int side = qMin(width(), height());

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(color);

    painter.save();
    painter.drawRect(0, 0, side, side);
    painter.restore();

}
