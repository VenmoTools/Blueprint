//
// Created by Administrator on 2022/7/23.
//

#ifndef BLUEPRINTCORE_PINPAINTER_HPP
#define BLUEPRINTCORE_PINPAINTER_HPP

#include <QColor>
#include <QPen>

class QPainter;

class QStyleOptionGraphicsItem;

class QWidget;

namespace ui {

    class BlueprintPin;

    class PinPainter {
    public:
        static void
        drawExecPin(BlueprintPin *pin, QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget);
    };
}


#endif //BLUEPRINTCORE_PINPAINTER_HPP
