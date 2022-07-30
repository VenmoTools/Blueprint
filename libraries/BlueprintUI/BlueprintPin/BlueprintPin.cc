//
// Created by Administrator on 2022/7/23.
//

#include "BlueprintPin.hpp"

#include "BlueprintNode/NodeUI.hpp"

#include "BlueprintPainter/PinPainter.hpp"


ui::BlueprintPin::BlueprintPin(ui::BlueprintPin::PinDirection direction, QWeakPointer<BlueprintNode> parentNode)
        : QGraphicsWidget(), _direction(direction), node(std::move(parentNode)) {
    setGraphicsItem(this);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    setAcceptHoverEvents(true);
    setZValue(1);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
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
    return _pinSize;
}

ui::BlueprintPin::PinDirection ui::BlueprintPin::direction() {
    return _direction;
}

