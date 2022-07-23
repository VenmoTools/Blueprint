//
// Created by Administrator on 2022/7/23.
//

#include "NodePainter.hpp"

#include "Canvas/BlueprintNode.hpp"
#include "BlueprintStyle/NodeStyle.hpp"

#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsEffect>

void ui::NodePainter::defaultNode(ui::BlueprintNode *node, QPainter *painter, const QStyleOptionGraphicsItem *option,
                                  QWidget *widget) {
    QRectF frameRect{QPointF{0, 0}, node->geometry().size()};

    int radius = node->nodeStyle->borderRadius();

    painter->setBrush( node->nodeStyle->nodeBackgroundColor());
    painter->setPen(Qt::NoPen);
    QPen pen{Qt::black, 0.5};

    // 绘制节点圆角矩形
    frameRect.setWidth(frameRect.width() - pen.width() / 2.0);
    frameRect.setHeight(frameRect.height() - pen.width() / 2.0);
    frameRect.setX(pen.width() / 2.0);
    frameRect.setY(frameRect.y() + pen.width() / 2.0);
    painter->drawRoundedRect(frameRect, radius, radius);

    if (option->state & QStyle::State_Selected) {
        pen.setColor(QColor(215, 128, 26));
        pen.setStyle(Qt::SolidLine);
        pen.setWidth(static_cast<int>(pen.width() * 1.5));
    }

    // 绘制节点外层轮廓
    pen.setColor(node->nodeStyle->nodeBorderColor(node->isSelected()));
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(static_cast<int>(pen.width() * 1.5));
    painter->setPen(pen);
    painter->setBrush(QColor{0, 0, 0, 0});
    painter->drawRoundedRect(frameRect, radius, radius);
}
