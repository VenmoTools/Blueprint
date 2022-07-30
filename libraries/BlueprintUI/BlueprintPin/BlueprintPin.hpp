//
// Created by Administrator on 2022/7/23.
//

#ifndef BLUEPRINTCORE_BLUEPRINTPIN_HPP
#define BLUEPRINTCORE_BLUEPRINTPIN_HPP

#include <QGraphicsWidget>


namespace ui {

    class BlueprintNode;

    class BlueprintPin : public QGraphicsWidget {
    public:
        enum PinDirection {
            Input,
            Output,
        };
    private:
        QWeakPointer<BlueprintNode> node;
        PinDirection _direction;
        int _pinSize{6};

    public:
        explicit BlueprintPin(PinDirection direction, QWeakPointer<BlueprintNode> parentNode);

        bool isConnected();

        QPointF pinCenter();

        int pinSize();

        PinDirection direction();

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    };
}


#endif //BLUEPRINTCORE_BLUEPRINTPIN_HPP
