#pragma once

#include <limits>

namespace ssao_render{
    const float inf_ = std::numeric_limits<float>::infinity();

    struct interval{
        public:
            static const interval interval_empty_;
            static const interval interval_universe_;

            float min_, max_;
            interval(float min, float max) : min_(min), max_(max) {}
            interval(const interval &a, const interval &b)
            {
                min_ = a.min_ <= b.min_ ? a.min_ : b.min_;
                max_ = a.max_ >= b.max_ ? a.max_ : b.max_;
            }

            float size() const { return max_ - min_; }
            bool contains(float x) const { return min_ <= x && x <= max_; }
            bool surrounds(float x) const { return min_ < x && x < max_; }
            float clamp(float x) const 
            {
                if (x < min_) { return min_; }
                if (x > max_) { return max_; }
                return x;
            }
    };

    const interval interval::interval_empty_{+inf_, -inf_};
    const interval interval::interval_universe_{-inf_, +inf_};
}
