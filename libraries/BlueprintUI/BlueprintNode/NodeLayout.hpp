//
// Created by Administrator on 2022/7/30.
//

#ifndef BLUEPRINTCORE_NODELAYOUT_HPP
#define BLUEPRINTCORE_NODELAYOUT_HPP


#include <QGraphicsLinearLayout>

namespace ui {
    class BlueprintPin;

    /**
 *
 * +--------------------------------+
 * | +----------------------------+ |
 * | |        Node Header         | |
 * | +----------------------------+ |
 * |                                |
 * | +----------------------------+ |
 * | |        Node Body           | |
 * | | +-------+        +-------+ | |
 * | | |  Pin  |        |  Pin  | | |
 * | | +-------+        +-------+ | |
 * | +----------------------------+ |
 * +--------------------------------+
 */
    class NodeLayout : public QGraphicsLinearLayout {
    public:
        explicit NodeLayout(QGraphicsLayoutItem *parent = nullptr);

        void drawDebug(QPainter *painter);

        void addPin(BlueprintPin *pin);

    private:
        void setup();

    public:
        void invalidate() override;

        void addHeader(QGraphicsWidget *item);

    private:

        QGraphicsLinearLayout *headerLayout;
        QGraphicsLinearLayout *bodyLayout;

        QGraphicsLinearLayout *leftPinLayout;
        QGraphicsLinearLayout *rightPinLayout;
    };


}

#endif //BLUEPRINTCORE_NODELAYOUT_HPP
