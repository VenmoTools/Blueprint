//
// Created by venmosnake on 2022/7/22.
//

#ifndef BLUEPRINTCORE_BLUEPRINTCANVAS_HPP
#define BLUEPRINTCORE_BLUEPRINTCANVAS_HPP

#include <QGraphicsView>
#include "BlueprintStyle/CanvasStyle.hpp"

namespace ui {

    class BlueprintCanvas : public QGraphicsView {
    private:
        std::unique_ptr<CanvasStyle> style;
        //    self.pressed_item = None
        //     self.released_item = None
    private:
        float minimumScale{0.2};
        float maximumScale{3.0};
        qreal factor{1};
        QPoint mousePressPos{};
        QPoint mousePos{};
        QPoint mouseLastPos{};

        qreal mouseWheelZoomRate{0.0005};

    protected:
        void wheelEvent(QWheelEvent *event) override;

        void drawBackground(QPainter *painter, const QRectF &rect) override;

    protected:

        virtual QGraphicsScene *createFirstScene();

    protected:

        [[nodiscard]] int lodValueFromScale(int lod = 5, qreal scale = 1.0) const;

        int lodValueFromCurrentScale(int lod = 5);

        void zoom(qreal factorScale);

    public:
        BlueprintCanvas();

        explicit BlueprintCanvas(QGraphicsScene *scene, QWidget *parent = nullptr);

        virtual void initCanvas();

        static void
        drawGridDetail(QPainter *painter, const QRectF &rect, int left, int top, int gridSize, bool thick = false);

        void drawGridRuler(QPainter *painter, const QRectF &rect, int left, int top);
    };
}


#endif //BLUEPRINTCORE_BLUEPRINTCANVAS_HPP
