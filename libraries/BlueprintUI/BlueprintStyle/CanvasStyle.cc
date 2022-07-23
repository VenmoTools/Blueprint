//
// Created by venmosnake on 2022/7/22.
//

#include "CanvasStyle.hpp"
#include <QGraphicsView>
#include <QPainter>


ui::CanvasStyle::CanvasStyle() : QObject(), gridFont(QFont{"YaHei"}) {
}


int ui::CanvasStyle::smallGridSize() const {
    return smallGrid;
}

bool ui::CanvasStyle::needDrawGrid() const {
    return true;
}

int ui::CanvasStyle::lodThreshold() const {
    return lod;
}

int ui::CanvasStyle::hugeGridSize() const {
    return hugeGrid;
}

bool ui::CanvasStyle::needDrawGridNum() const {
    return gridNum;
}

QFont ui::CanvasStyle::gridNumFont() {
    return gridFont;
}

void ui::CanvasStyle::applyStyle(QGraphicsView *view) {
    view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    view->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    view->setAcceptDrops(true);
    view->setAttribute(Qt::WA_AlwaysShowToolTips);
    view->setResizeAnchor(QGraphicsView::AnchorUnderMouse);

    view->setFocusPolicy(Qt::StrongFocus);
    view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

ui::CanvasStyle::~CanvasStyle() = default;
