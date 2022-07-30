//
// Created by Administrator on 2022/7/30.
//

#ifndef BLUEPRINTCORE_NODEUI_H
#define BLUEPRINTCORE_NODEUI_H


#include <QGraphicsWidget>
#include "BlueprintStyle/NodeStyle.hpp"
#include "NodeLayout.hpp"
#include "NodeHeader.hpp"

namespace ui {

    class BlueprintNode : public QGraphicsWidget {
    private:
        std::unique_ptr<NodeStyle> nodeStyle;

        NodeLayout* nodeLayout;
        QPointer<NodeHeader> header;


        friend class NodePainter;

    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

        void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

        void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;

        void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

    public:
        explicit BlueprintNode(QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = Qt::WindowFlags());

        explicit BlueprintNode(const QString &name, QGraphicsItem *parent = nullptr,
                               Qt::WindowFlags wFlags = Qt::WindowFlags());

        void updateNodeShape();

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

        void setGeometry(const QRectF &rect) override;

        void addPin(BlueprintPin *pin);

    };

}

#endif //BLUEPRINTCORE_NODEUI_H
