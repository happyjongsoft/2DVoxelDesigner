#ifndef SHAPEPOINTCURVE_H
#define SHAPEPOINTCURVE_H

#include "baseshape.h"
#include <QGraphicsItem>
#include <QPainter>
#include "movingarrow.h"
#include <QDebug>
#include <QTextStream>

class ShapePointCurve : public BaseShape, public QGraphicsItem {
public:
    ShapePointCurve(int, QColor, int);
    ~ShapePointCurve() override;

    void addPoint(QPoint);
    void setSelectable(bool) override;
    void addArrow(int) override;
    void removeArrows() override;
    void removeLast();
    void setScaleFactor(float) override;
    void updateShapeLine();
    bool setMoveType(QPointF) override;
    void setIsAddabble(bool f);
    void setPoints(QList<QPoint>);
    QList<QPoint> getPoints();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    virtual QRectF boundingRect() const override;
    virtual void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void redraw() override;
    void move(QPointF first, QPointF second) override;
    void save(QTextStream* stream) override;
    void open(QTextStream* stream) override;
    void setLineWidth(float) override;
    void setLineColor(QColor) override;

private:
    void setSelectionState(bool);

private:
    QGraphicsPathItem *m_mainPath;
    QList<MovingArrow*> _moving_points;
    QList<QPoint> m_points;
    bool m_bAddable;
};

#endif // SHAPEPOINTCURVE_H
