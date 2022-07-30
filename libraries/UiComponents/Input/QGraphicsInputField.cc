//
// Created by Administrator on 2022/7/26.
//

#include "QGraphicsInputField.hpp"

#include <QGraphicsWidget>
#include <QTextCursor>

ui::QGraphicsInputField::QGraphicsInputField(QGraphicsItem *parent)
        : QGraphicsTextItem(parent) {
    setFlags(QGraphicsWidget::ItemSendsGeometryChanges | QGraphicsWidget::ItemIsSelectable);
}

ui::QGraphicsInputField::QGraphicsInputField(const QString &text, QGraphicsItem *parent)
        : QGraphicsTextItem(text, parent) {
    setFlags(QGraphicsWidget::ItemSendsGeometryChanges | QGraphicsWidget::ItemIsSelectable);
    setFlag(QGraphicsWidget::ItemIsFocusable, true);
}

void ui::QGraphicsInputField::keyPressEvent(QKeyEvent *event) {
    int key = event->key();

    // 编辑时按esc退出编辑恢复编辑前的内容
    if (key == Qt::Key_Escape) {
        setPlainText(beforeEditionTextData);
        clearFocus();
        QGraphicsTextItem::keyPressEvent(event);
        return;
    }

    if (Qt::Key_Return == key || Qt::Key_Enter == key) {
        if (toPlainText().isEmpty()) {
            setPlainText(beforeEditionTextData);
            event->ignore();
            emit onEditingState(EditingState::Finished);
            clearFocus();
        } else {
            event->ignore();
            clearFocus();
        }
        return;
    }
    QGraphicsTextItem::keyPressEvent(event);
}

void ui::QGraphicsInputField::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (_isMouseLocked) {
        QGraphicsTextItem::mousePressEvent(event);
    } else {
        clearFocus();
    }
}

void ui::QGraphicsInputField::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (_isMouseLocked) {
        QGraphicsTextItem::mouseReleaseEvent(event);
    } else {
        // notify node to release?
        clearFocus();
    }
}

void ui::QGraphicsInputField::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsTextItem::mouseDoubleClickEvent(event);
    setFlag(QGraphicsWidget::ItemIsFocusable, true);
    emit onEditingState(EditingState::Editing);
    setFocus();
}

void ui::QGraphicsInputField::focusInEvent(QFocusEvent *event) {
    //todo: disable shortcuts
    setTextInteractionFlags(Qt::TextEditorInteraction);
    _isMouseLocked = true;
    beforeEditionTextData = toPlainText();
    QGraphicsTextItem::focusInEvent(event);
}

void ui::QGraphicsInputField::focusOutEvent(QFocusEvent *event) {
    //todo: enable shortcuts
    QTextCursor cursor = textCursor();
    cursor.clearSelection();
    setTextCursor(cursor);
    QGraphicsTextItem::focusOutEvent(event);

    setTextInteractionFlags(Qt::NoTextInteraction);
    setFlag(QGraphicsWidget::ItemIsFocusable, false);
    _isMouseLocked = false;
    if (toPlainText().isEmpty()) {
        setPlainText(beforeEditionTextData);
        emit onEditingState(EditingState::Cancel);
    } else {
        emit onEditingState(EditingState::Finished);
    }
}

void ui::QGraphicsInputField::setGeometry(const QRectF &rect) {
    prepareGeometryChange();
    setPos(rect.topLeft());
}

void ui::QGraphicsInputField::onEditingState(ui::QGraphicsInputField::EditingState state) {

}
