//
// Created by Administrator on 2022/7/23.
//

#ifndef BLUEPRINTCORE_BLUEPRINTPIN_HPP
#define BLUEPRINTCORE_BLUEPRINTPIN_HPP

#include <QGraphicsWidget>


namespace ui {


    class BlueprintPin : public QGraphicsWidget {
    public:
        enum PinDirection {
            Input,
            Output,
        };
    private:
        PinDirection _direction;

    public:
        explicit BlueprintPin(PinDirection direction, QGraphicsItem *parent = nullptr,
                              Qt::WindowFlags wFlags = Qt::WindowFlags());

        bool isConnected();

        QPointF pinCenter();

        int pinSize();

        PinDirection direction();

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    };
}


#endif //BLUEPRINTCORE_BLUEPRINTPIN_HPP
