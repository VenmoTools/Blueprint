//
// Created by Administrator on 2022/7/23.
//

#ifndef BLUEPRINTCORE_NODEPAINTER_HPP
#define BLUEPRINTCORE_NODEPAINTER_HPP

class QPainter;

class QStyleOptionGraphicsItem;

class QWidget;

namespace ui {
    class BlueprintNode;

    class NodePainter {

    public:

        static void
        defaultNode(BlueprintNode *node, QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    };
}


#endif //BLUEPRINTCORE_NODEPAINTER_HPP
