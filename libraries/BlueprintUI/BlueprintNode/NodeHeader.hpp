//
// Created by Administrator on 2022/7/30.
//

#ifndef BLUEPRINTCORE_NODEHEADER_HPP
#define BLUEPRINTCORE_NODEHEADER_HPP


#include <QGraphicsWidget>
#include "Input/QGraphicsInputField.hpp"

namespace ui{
    class NodeHeader : public QGraphicsWidget {
    private:
        QPointer<QGraphicsInputField> _label;
        QFont _font;
        bool _hovered;

    public:
        ~NodeHeader() override;

    public:
        explicit NodeHeader(const QString &name, QGraphicsItem *parent = nullptr);

        QFont font();

        QString nodeName();

        void setNodeName(const QString &name);


    protected:
        void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

        void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

        [[nodiscard]] QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint) const override;

    public:
        void setGeometry(const QRectF &rect) override;
    };

}


#endif //BLUEPRINTCORE_NODEHEADER_HPP
