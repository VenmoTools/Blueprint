//
// Created by Administrator on 2022/7/23.
//

#include "BlueprintPin.hpp"

#include <BlueprintPainter/PinPainter.hpp>

ui::BlueprintPin::BlueprintPin(PinDirection direction, QGraphicsItem *parent, Qt::WindowFlags wFlags) : QGraphicsWidget(
        parent, wFlags), _direction(direction) {
    setGraphicsItem(this);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    setAcceptHoverEvents(true);
    setZValue(1);

}

void ui::BlueprintPin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QGraphicsWidget::paint(painter, option, widget);
    PinPainter::drawExecPin(this, painter, option, widget);
}

bool ui::BlueprintPin::isConnected() {
    return false;
}

QPointF ui::BlueprintPin::pinCenter() {
    auto frame = QRectF(QPointF(0, 0), geometry().size());
    auto pinX = static_cast<qreal>( pinSize());
    auto pinY = frame.height() / 2;

    return {pinX, pinY};
}

int ui::BlueprintPin::pinSize() {
    return 6;
}

ui::BlueprintPin::PinDirection ui::BlueprintPin::direction() {
    return _direction;
}
