//
// Created by venmosnake on 2022/7/22.
//

#ifndef BLUEPRINTCORE_CANVASSTYLE_HPP
#define BLUEPRINTCORE_CANVASSTYLE_HPP


#include <QObject>
#include <QFont>

class QGraphicsView;

namespace ui {
    class CanvasStyle : public QObject {
    Q_OBJECT
    protected:
        QFont gridFont;
        bool gridNum{true};
        int lod{3};
        int hugeGrid{100};
        int smallGrid{10};
    public:

        virtual void applyStyle(QGraphicsView *view);

    public:
        CanvasStyle();

        ~CanvasStyle() override;

        int smallGridSize() const;

        int hugeGridSize() const;

        bool needDrawGrid() const;

        int lodThreshold() const;

        bool needDrawGridNum() const;

        QFont gridNumFont();
    };
}


#endif //BLUEPRINTCORE_CANVASSTYLE_HPP
