//
// Created by Administrator on 2022/7/23.
//

#ifndef BLUEPRINTCORE_BLUEPRINTNODE_HPP
#define BLUEPRINTCORE_BLUEPRINTNODE_HPP

#include <QGraphicsWidget>
#include <QGraphicsLinearLayout>

#include "BlueprintStyle/NodeStyle.hpp"


namespace ui {
    class BlueprintPin;

    class NodeHeaderLayout : public QGraphicsLinearLayout {
    public:
        explicit NodeHeaderLayout(QGraphicsLayoutItem *parent = nullptr);

        explicit NodeHeaderLayout(Qt::Orientation orientation, QGraphicsLayoutItem *parent = nullptr);

    };

    class NodePinLayout : public QGraphicsLinearLayout {
    protected:
        QGraphicsLinearLayout *inputPins;
        QGraphicsLinearLayout *outputPins;

        bool _collapsed{};

    protected:
        virtual void updateNodeShape();

        void invalidatePinLayouts();

    public:
        explicit NodePinLayout(QGraphicsLayoutItem *parent = nullptr);

        void addInputPin(QGraphicsLayoutItem *item);

        void addOutputPin(QGraphicsLayoutItem *item);

        void setCollapsed(bool collapsed);

        bool isCollapsed();
    };


    class BlueprintNode : public QGraphicsWidget {
    private:
        std::unique_ptr<NodeStyle> nodeStyle;
        NodePinLayout *pinLayout;

        QGraphicsLinearLayout *nodeLayout;

        friend class NodePainter;

    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

        void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

        void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;

        void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

    public:
        explicit BlueprintNode(QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = Qt::WindowFlags());

        void updateNodeShape();

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

        void invalidateNodeLayouts();

        void addPin(BlueprintPin *pin);

    };

}

#endif //BLUEPRINTCORE_BLUEPRINTNODE_HPP
