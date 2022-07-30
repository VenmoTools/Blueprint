//
// Created by Administrator on 2022/7/30.
//

#include <QPainter>


#include "NodeUI.hpp"
#include "BlueprintPainter/NodePainter.hpp"


ui::BlueprintNode::BlueprintNode(const QString &name, QGraphicsItem *parent, Qt::WindowFlags wFlags)
        : BlueprintNode(parent, wFlags) {
    header->setNodeName(name);
}

ui::BlueprintNode::BlueprintNode(QGraphicsItem *parent, Qt::WindowFlags wFlags)
        : QGraphicsWidget(parent, wFlags),
          nodeStyle(std::make_unique<NodeStyle>()),
          header(QPointer<NodeHeader>(new NodeHeader{"EmptyNode", this})),
          nodeLayout(new NodeLayout{}) {
    setFlags(QGraphicsWidget::ItemIsMovable | QGraphicsWidget::ItemIsFocusable
             | QGraphicsWidget::ItemIsSelectable | QGraphicsWidget::ItemSendsGeometryChanges);

    setCacheMode(QGraphicsWidget::DeviceCoordinateCache);
    setFocusPolicy(Qt::StrongFocus);
    setAcceptHoverEvents(true);
    setZValue(nodeStyle->zLayer());

    nodeLayout->addHeader(header);
    header->setPos(0, 1);

    setLayout(nodeLayout);
}

void ui::BlueprintNode::updateNodeShape() {
    prepareGeometryChange();
    nodeLayout->invalidate();
    QGraphicsWidget::updateGeometry();
    update();
}


void ui::BlueprintNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    NodePainter::defaultNode(this, painter, option, widget);

#ifdef GRAPHICS_DEBUG
    nodeLayout->drawDebug(painter);
    painter->setPen(QPen{Qt::black,0.755});
    painter->drawRect(header->geometry());
#endif

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
    nodeLayout->addPin(pin);
    updateNodeShape();
}

void ui::BlueprintNode::setGeometry(const QRectF &rect) {
    prepareGeometryChange();
    QGraphicsWidget::setGeometry(rect);
    setPos(rect.topLeft());
}


