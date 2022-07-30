//
// Created by Administrator on 2022/7/30.
//

#include <QFontMetrics>
#include "NodeHeader.hpp"


ui::NodeHeader::NodeHeader(const QString &name, QGraphicsItem *parent) :
        QGraphicsWidget(parent),
        _label(QPointer<QGraphicsInputField>{new QGraphicsInputField{name, this}}),
        _hovered(false),
        _font("JetbrainsMono") { //todo:
    setAcceptHoverEvents(true);
    setFlag(QGraphicsWidget::ItemSendsGeometryChanges);
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);


    _label->setAcceptHoverEvents(true);
    _label->setDefaultTextColor(Qt::white);
    _font.setPointSize(6);
    _label->setFont(_font);
    setGraphicsItem(_label);

    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}

ui::NodeHeader::~NodeHeader() {
    if (!_label.isNull()) {
        delete _label;
    }
}

QFont ui::NodeHeader::font() {
    return _label->font();
}

QString ui::NodeHeader::nodeName() {
    return _label->toPlainText();
}

void ui::NodeHeader::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    QGraphicsItem::hoverEnterEvent(event);
    _hovered = true;
    update();
}

void ui::NodeHeader::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    QGraphicsWidget::hoverLeaveEvent(event);
    _hovered = false;
    update();
}

QSizeF ui::NodeHeader::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const {
    QFontMetrics metrics{_label->font()};
    qreal width = metrics.averageCharWidth(); // todo: replace
    qreal height = _label->boundingRect().height() + 5.0;
    return {width, height};
}

void ui::NodeHeader::setGeometry(const QRectF &rect) {
    prepareGeometryChange();
    QGraphicsWidget::setGeometry(rect);
    setPos(rect.topLeft());
    _label->setGeometry(rect);
}

void ui::NodeHeader::setNodeName(const QString &name) {
    _label->setPlainText(name);
}