//
// Created by Administrator on 2022/7/23.
//

#include "PinPainter.hpp"

#include "Canvas/BlueprintPin.hpp"
#include <QPainter>
#include <QStyleOptionGraphicsItem>


void ui::PinPainter::drawExecPin(ui::BlueprintPin *pin, QPainter *painter, const QStyleOptionGraphicsItem *option,
                                 QWidget *widget) {
//    QRectF frame{QPointF(0, 0), pin->geometry().size()};

    if (pin->isConnected()) {
        painter->setBrush(Qt::white);
    } else {
        painter->setBrush(Qt::NoBrush);
    }

    painter->setPen(QPen{QColor(255, 255, 255, 200), 0.5, Qt::SolidLine});

    auto pinCenter = pin->pinCenter();

    qreal xOffset;
    if (pin->direction() == BlueprintPin::Input) {
        xOffset = pinCenter.x() - pin->pinSize();
    } else {
        xOffset = pinCenter.x() - pin->pinSize() * 0.8;
    }
    qreal pinSize{static_cast<qreal>(pin->pinSize())};


    QList<QPointF> draw{
            QPointF{2, 0},
            QPointF{2 + pinSize / 2.0, 0},
            QPointF{2.0 + pinSize, pinSize / 2.0},
            QPointF{2 + pinSize / 2.0, pinSize},
            QPointF{2, pinSize},
    };

    QPolygonF arrow{draw};
    painter->drawPolygon(arrow.translated(xOffset, 1));
}
