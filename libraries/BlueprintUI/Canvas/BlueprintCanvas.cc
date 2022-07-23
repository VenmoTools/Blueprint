//
// Created by venmosnake on 2022/7/22.
//

#include "BlueprintCanvas.hpp"
#include "Utils/Algorithm.hpp"

#include <QWheelEvent>

ui::BlueprintCanvas::BlueprintCanvas()
        : QGraphicsView(), style(std::make_unique<CanvasStyle>()) {
    style->applyStyle(this);
}

ui::BlueprintCanvas::BlueprintCanvas(QGraphicsScene *scene, QWidget *parent)
        : QGraphicsView(scene, parent), style(std::make_unique<CanvasStyle>()) {
    style->applyStyle(this);
}

void ui::BlueprintCanvas::initCanvas() {
    auto firstScene = createFirstScene();
    setScene(firstScene);
    QRectF rect = sceneRect();
    centerOn(rect.width() / 2.0, rect.height() / 2.0);
}

QGraphicsScene *ui::BlueprintCanvas::createFirstScene() {
    QGraphicsScene *firstScene{new QGraphicsScene{this}};
    firstScene->setItemIndexMethod(QGraphicsScene::NoIndex);
    firstScene->setSceneRect(QRectF{0, 0, 10, 10});
    return firstScene;
}

void ui::BlueprintCanvas::wheelEvent(QWheelEvent *event) {
    QGraphicsView::wheelEvent(event);
    qreal zoomFactor = 1.0 + event->angleDelta().y() * 0.0005;
    zoom(zoomFactor);
}

void ui::BlueprintCanvas::drawBackground(QPainter *painter, const QRectF &rect) {
    QGraphicsView::drawBackground(painter, rect);

    int lod = lodValueFromCurrentScale();

    painter->fillRect(rect, QBrush{QColor(38, 38, 38)});//todo:QColor(35, 35, 35)

    auto calcGridLimitPos = [](double max, int gridSize) -> int {
        return static_cast<int>(max) - (static_cast<int>(max) % gridSize);
    };

    int left = calcGridLimitPos(rect.left(), style->smallGridSize());
    int top = calcGridLimitPos(rect.top(), style->smallGridSize());

    if (style->needDrawGrid()) {
        if (lod <= style->lodThreshold()) {
            drawGridDetail(painter, rect, left, top, style->smallGridSize());
        }
        left = calcGridLimitPos(rect.left(), style->hugeGridSize());
        top = calcGridLimitPos(rect.top(), style->hugeGridSize());
        drawGridDetail(painter, rect, left, top, style->hugeGridSize(), true);
    }

    if (style->needDrawGridNum()) {
        drawGridRuler(painter, rect, left, top);
    }
}

void ui::BlueprintCanvas::drawGridRuler(QPainter *painter, const QRectF &rect, int left, int top) {
    auto currentViewScale = transform().m22();
    QFont f = style->gridNumFont();
    f.setPointSizeF(6.0 / std::min(currentViewScale, 1.0));
    painter->setFont(f);
    auto y = static_cast<qreal>(top);
    while (y < rect.bottom()) {
        y += style->hugeGridSize();
        if (y > top + 30) {
            painter->setPen(QPen{QColor(20, 20, 20).lighter(300)});
            painter->drawText(static_cast<int>(rect.left()), static_cast<int>(y - 1.0),
                              QString::number(static_cast<int>(y)));
        }
    }
    auto x = static_cast<qreal>(left);
    while (left < rect.right()) {
        x += style->hugeGridSize();
        if (x > left + 30) {
            painter->setPen(QPen{QColor(20, 20, 20).lighter(300), 1});
            painter->drawText(static_cast<int>(x),
                              static_cast<int>(rect.top() + painter->font().pointSizeF()),
                              QString::number(static_cast<int>(x)));
        }
    }
}

void ui::BlueprintCanvas::drawGridDetail(QPainter *painter, const QRectF &rect, int left, int top, int gridSize,
                                         bool thick) {
    QList<QLineF> horizontalLines{};
    auto y = static_cast<qreal>(top);
    while (y < rect.bottom()) {
        horizontalLines.emplace_back(QLineF{rect.left(), y, rect.right(), y});
        y += gridSize;
    }

    QList<QLineF> verticalLines{};
    auto x = static_cast<qreal>(left);
    while (x < rect.right()) {
        verticalLines.emplace_back(QLineF{x, rect.top(), x, rect.bottom()});
        x += gridSize;
    }
    if (thick) {
        painter->setPen(QPen{QColor(22, 22, 22), 0.5});
    }else{
        painter->setPen(QPen{QColor(53, 53, 53), 0.5});
    }
    painter->drawLines(horizontalLines);
    painter->drawLines(verticalLines);
}

int ui::BlueprintCanvas::lodValueFromScale(int lod, qreal scale) const {
    return static_cast<int>(std::round(lerp(lod, 1, getRangePct(minimumScale, maximumScale, scale))));
}

int ui::BlueprintCanvas::lodValueFromCurrentScale(int lod) {
    return lodValueFromScale(lod, transform().m22());
}

void ui::BlueprintCanvas::zoom(qreal factorScale) {
    factor = transform().m22();
    qreal futureFactor = factorScale * factor;

    if (futureFactor <= minimumScale) {
        factorScale = minimumScale / factor;
    }

    if (futureFactor >= maximumScale) {
        factorScale = (maximumScale - 0.1) / factor;
    }
    scale(factorScale, factorScale);
}
