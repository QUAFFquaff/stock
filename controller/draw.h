#ifndef DRAW_H
#define DRAW_H

#include <QAction>



class Draw
{
public:
    Draw();
    ~Draw();
    void drawPlot();
    void drawPlot(QWidget *customWidget);
};

#endif // DRAW_H
