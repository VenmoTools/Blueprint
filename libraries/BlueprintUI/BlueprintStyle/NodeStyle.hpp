//
// Created by Administrator on 2022/7/23.
//

#ifndef BLUEPRINTCORE_NODESTYLE_HPP
#define BLUEPRINTCORE_NODESTYLE_HPP

#include <QColor>

namespace ui {
    class NodeStyle {

    private:
        int zValue{1000000};
        QColor color{30, 31, 30};
        QColor borderNormal{16, 17, 16};
        QColor borderActive{242, 177, 0};
        int radius{5};
    public:

        NodeStyle();

        int zLayer();

        int borderRadius() const;

        QColor &nodeBackgroundColor();

        QColor &nodeBorderColor(bool isSelected);

    };
}


#endif //BLUEPRINTCORE_NODESTYLE_HPP
