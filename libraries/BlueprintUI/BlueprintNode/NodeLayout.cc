//
// Created by Administrator on 2022/7/30.
//

#include "NodeLayout.hpp"

#include <QPainter>
#include <QPen>

#include "BlueprintPin/BlueprintPin.hpp"

ui::NodeLayout::NodeLayout(QGraphicsLayoutItem *parent)
        : QGraphicsLinearLayout(Qt::Vertical, parent),
          headerLayout(new QGraphicsLinearLayout{Qt::Horizontal}),
          bodyLayout(new QGraphicsLinearLayout{Qt::Horizontal}),
          leftPinLayout(new QGraphicsLinearLayout{Qt::Vertical}),
          rightPinLayout(new QGraphicsLinearLayout{Qt::Vertical}) {
    setup();
}

void ui::NodeLayout::setup() {
    setContentsMargins(5, 5, 5, 5);
    setSpacing(5);

    // -- setup header layout
    headerLayout->setContentsMargins(0, 0, 0, 0);
    headerLayout->setSpacing(3);
    headerLayout->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    // -- end


    // -- setup body layout
    bodyLayout->setContentsMargins(0, 0, 0, 0);
    bodyLayout->setSpacing(5);
    bodyLayout->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    // -- end

    // -- setup left pin layout
    leftPinLayout->setContentsMargins(0, 0, 0, 0);
    leftPinLayout->setSpacing(5);
    leftPinLayout->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    // -- end

    // -- setup left pin layout
    rightPinLayout->setContentsMargins(0, 0, 0, 0);
    rightPinLayout->setSpacing(5);
    rightPinLayout->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    // -- end

    bodyLayout->addItem(leftPinLayout);
    bodyLayout->addItem(rightPinLayout);
    bodyLayout->setAlignment(leftPinLayout, Qt::AlignLeft);
    bodyLayout->setAlignment(rightPinLayout, Qt::AlignRight);
//    bodyLayout->setPreferredWidth(preferredWidth());

    addItem(headerLayout);
    addItem(bodyLayout);
}

void ui::NodeLayout::drawDebug(QPainter *painter) {
    painter->setPen(QPen(Qt::green, 0.75));
    painter->drawRect(headerLayout->geometry());
    painter->setPen(QPen(Qt::red, 0.75));
    painter->drawRect(bodyLayout->geometry());
    painter->setPen(QPen(Qt::green, 0.75));
    painter->drawRect(leftPinLayout->geometry());
    painter->drawRect(rightPinLayout->geometry());
}

void ui::NodeLayout::addPin(ui::BlueprintPin *pin) {
    switch (pin->direction()) {
        case BlueprintPin::Input: {
            leftPinLayout->insertItem(-1, pin);
            setAlignment(pin, Qt::AlignLeft);
            leftPinLayout->invalidate();
            break;
        }
        case BlueprintPin::Output: {
            rightPinLayout->insertItem(-1, pin);
            rightPinLayout->setAlignment(pin, Qt::AlignRight);
            rightPinLayout->invalidate();
            break;
        }
    }
    pin->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void ui::NodeLayout::invalidate() {
    leftPinLayout->invalidate();
    rightPinLayout->invalidate();
    bodyLayout->invalidate();
    headerLayout->invalidate();
    QGraphicsLinearLayout::invalidate();
}

void ui::NodeLayout::addHeader(QGraphicsWidget *item) {
    headerLayout->addItem(item);
}

