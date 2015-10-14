/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Morwenn
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef CPPSORT_DETAIL_FRONT_INSERTER5_H_
#define CPPSORT_DETAIL_FRONT_INSERTER5_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <utility>

namespace cppsort
{
namespace detail
{
    template<>
    struct front_inserter_n<5u>
    {
        template<typename RandomAccessIterator, typename Compare>
        auto operator()(RandomAccessIterator first, Compare compare) const
            -> void
        {
            using std::swap;

            if (compare(first[2u], first[0u])) {
                if (compare(first[3u], first[0u])) {
                    if (compare(first[4u], first[0u])) {
                        auto tmp = std::move(first[0u]);
                        first[0u] = std::move(first[1u]);
                        first[1u] = std::move(first[2u]);
                        first[2u] = std::move(first[3u]);
                        first[3u] = std::move(first[4u]);
                        first[4u] = std::move(tmp);
                    } else {
                        auto tmp = std::move(first[0u]);
                        first[0u] = std::move(first[1u]);
                        first[1u] = std::move(first[2u]);
                        first[2u] = std::move(first[3u]);
                        first[3u] = std::move(tmp);
                    }
                } else {
                    auto tmp = std::move(first[0u]);
                    first[0u] = std::move(first[1u]);
                    first[1u] = std::move(first[2u]);
                    first[2u] = std::move(tmp);
                }
            } else {
                if (compare(first[1u], first[0u])) {
                    swap(first[0u], first[1u]);
                }
            }
        }
    };
}}

#endif // CPPSORT_DETAIL_FRONT_INSERTER5_H_
