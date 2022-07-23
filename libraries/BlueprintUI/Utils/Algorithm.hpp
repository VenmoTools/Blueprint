//
// Created by venmosnake on 2022/7/22.
//

#ifndef BLUEPRINTCORE_ALGORITHM_HPP
#define BLUEPRINTCORE_ALGORITHM_HPP

inline qreal lerp(int start, int end, qreal alpha) {
    return static_cast<qreal>(start) + (alpha * static_cast<qreal>(end - start));
}

inline float getRangePct(float minVal, float maxVal, float val) {
    return (val - minVal) / (maxVal - val);
}

#endif //BLUEPRINTCORE_ALGORITHM_HPP
