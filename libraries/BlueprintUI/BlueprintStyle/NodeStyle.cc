//
// Created by Administrator on 2022/7/23.
//

#include "NodeStyle.hpp"


int ui::NodeStyle::zLayer() {
    return zValue;
}

QColor &ui::NodeStyle::nodeBackgroundColor() {
    return color;
}

ui::NodeStyle::NodeStyle() {
    color = color.lighter(100);
    color.setAlpha(150);
}

QColor &ui::NodeStyle::nodeBorderColor(bool isSelected) {
    return isSelected ? borderActive : borderNormal;
}

int ui::NodeStyle::borderRadius() const {
    return radius;
}
