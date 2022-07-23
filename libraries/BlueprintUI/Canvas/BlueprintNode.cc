//
// Created by Administrator on 2022/7/23.
//

#include "BlueprintNode.hpp"

#include <QGraphicsLayoutItem>
#include <BlueprintPainter/NodePainter.hpp>
#include "BlueprintPin.hpp"


ui::NodeHeaderLayout::NodeHeaderLayout(QGraphicsLayoutItem *parent) : NodeHeaderLayout(Qt::Horizontal, parent) {

}

ui::NodeHeaderLayout::NodeHeaderLayout(Qt::Orientation orientation, QGraphicsLayoutItem *parent)
        : QGraphicsLinearLayout(orientation, parent) {
    setContentsMargins(0, 0, 0, 0);
    setSpacing(3);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

}

ui::NodePinLayout::NodePinLayout(QGraphicsLayoutItem *parent)
        : QGraphicsLinearLayout(Qt::Horizontal, parent),
          inputPins(new QGraphicsLinearLayout{Qt::Vertical}),
          outputPins(new QGraphicsLinearLayout{Qt::Vertical}) {

    setContentsMargins(0, 0, 0, 0);
    setSpacing(5);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);

    inputPins->setContentsMargins(0, 0, 0, 0);
    inputPins->setSpacing(10);
    inputPins->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);

    outputPins->setContentsMargins(0, 0, 0, 0);
    outputPins->setSpacing(10);
    outputPins->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);

    addItem(inputPins);
    addItem(outputPins);

    setAlignment(inputPins, Qt::AlignLeft);
    setAlignment(outputPins, Qt::AlignRight);

}

void ui::NodePinLayout::addInputPin(QGraphicsLayoutItem *item) {
    inputPins->addItem(item);
}

void ui::NodePinLayout::addOutputPin(QGraphicsLayoutItem *item) {
    outputPins->addItem(item);
}

void ui::NodePinLayout::setCollapsed(bool collapsed) {
    if (_collapsed == collapsed)return;

    _collapsed = collapsed;

    for (int i = 0; i < inputPins->count(); ++i) {
        QGraphicsLayoutItem *item = inputPins->itemAt(i);
        item->graphicsItem()->setVisible(!collapsed);
    }

    for (int i = 0; i < outputPins->count(); ++i) {
        QGraphicsLayoutItem *item = outputPins->itemAt(i);
        item->graphicsItem()->setVisible(!collapsed);
    }

}

bool ui::NodePinLayout::isCollapsed() {
    return _collapsed;
}

void ui::NodePinLayout::updateNodeShape() {
    QGraphicsLinearLayout::invalidate();

}

void ui::NodePinLayout::invalidatePinLayouts() {
    inputPins->invalidate();
    outputPins->invalidate();
    QGraphicsLinearLayout::invalidate();
}


ui::BlueprintNode::BlueprintNode(QGraphicsItem *parent, Qt::WindowFlags wFlags)
        : QGraphicsWidget(parent, wFlags), nodeStyle(std::make_unique<NodeStyle>()),
          pinLayout(new NodePinLayout{}),
          nodeLayout(new QGraphicsLinearLayout{Qt::Vertical}) {
    setFlags(QGraphicsWidget::ItemIsMovable | QGraphicsWidget::ItemIsFocusable
             | QGraphicsWidget::ItemIsSelectable | QGraphicsWidget::ItemSendsGeometryChanges);

    setCacheMode(QGraphicsWidget::DeviceCoordinateCache);
    setFocusPolicy(Qt::StrongFocus);
    setAcceptHoverEvents(true);
    setZValue(nodeStyle->zLayer());


    nodeLayout->setContentsMargins(5, 5, 5, 5);
    nodeLayout->setSpacing(5);

//    nodeLayout->addItem(headerLayout);
    nodeLayout->addItem(pinLayout);

    setLayout(nodeLayout);
}

void ui::BlueprintNode::updateNodeShape() {
    prepareGeometryChange();
    invalidateNodeLayouts();
    QGraphicsWidget::updateGeometry();
//    pinLayout->setPreferredWidth()
    update();
}

void ui::BlueprintNode::invalidateNodeLayouts() {
    pinLayout->invalidate();
    nodeLayout->invalidate();
}

void ui::BlueprintNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QGraphicsWidget::paint(painter, option, widget);
    NodePainter::defaultNode(this, painter, option, widget);
}

void ui::BlueprintNode::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mousePressEvent(event);
}

void ui::BlueprintNode::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mouseMoveEvent(event);
}

void ui::BlueprintNode::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mouseReleaseEvent(event);
}

void ui::BlueprintNode::hoverMoveEvent(QGraphicsSceneHoverEvent *event) {
    QGraphicsWidget::hoverMoveEvent(event);
}

void ui::BlueprintNode::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    QGraphicsWidget::hoverLeaveEvent(event);
}

void ui::BlueprintNode::addPin(ui::BlueprintPin *pin) {
    if (pin->direction() == BlueprintPin::Input) {
        pinLayout->addInputPin(pin);
    } else {
        pinLayout->addOutputPin(pin);
    }
}
