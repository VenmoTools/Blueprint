//
// Created by Administrator on 2022/7/26.
//

#ifndef BLUEPRINTCORE_QGRAPHICSINPUTFEILD_HPP
#define BLUEPRINTCORE_QGRAPHICSINPUTFEILD_HPP

#include <QGraphicsTextItem>


namespace ui {
    class QGraphicsInputField : public QGraphicsTextItem {

    public:

        enum EditingState {
            Cancel,
            Editing,
            Finished,
        };

    private:
        QString beforeEditionTextData{};

        bool _isMouseLocked{false};

    public:
        explicit QGraphicsInputField(QGraphicsItem *parent = nullptr);

        explicit QGraphicsInputField(const QString &text, QGraphicsItem *parent = nullptr);

        void setGeometry(const QRectF &rect);

    Q_SIGNALS:

        void onEditingState(EditingState state);

    protected:
        void keyPressEvent(QKeyEvent *event) override;

        void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

        void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

        void focusInEvent(QFocusEvent *event) override;

        void focusOutEvent(QFocusEvent *event) override;
    };
}


#endif //BLUEPRINTCORE_QGRAPHICSINPUTFEILD_HPP
