/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015-2020 Morwenn
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
#include <algorithm>
#include <forward_list>
#include <functional>
#include <iterator>
#include <list>
#include <random>
#include <vector>
#include <catch2/catch_test_macros.hpp>
#include <cpp-sort/sorters/default_sorter.h>
#include <cpp-sort/sort.h>
#include "../algorithm.h"
#include "../catch_rng_seed.h"

TEST_CASE( "default sorter tests with projections",
           "[default_sorter][projection]" )
{
    // Pseudo-random number engine
    std::mt19937_64 engine(Catch::rngSeed());

    // Wrapper to hide the integer
    struct wrapper { int value; };

    // Collection to sort
    std::vector<wrapper> vec(80);
    helpers::iota(std::begin(vec), std::end(vec), 0, &wrapper::value);
    std::shuffle(std::begin(vec), std::end(vec), engine);

    SECTION( "sort with random-access iterable" )
    {
        cppsort::sort(vec, &wrapper::value);
        CHECK( helpers::is_sorted(std::begin(vec), std::end(vec), std::less<>{}, &wrapper::value) );
    }

    SECTION( "sort with random-access iterable and compare" )
    {
        cppsort::sort(vec, std::greater<>{}, &wrapper::value);
        CHECK( helpers::is_sorted(std::begin(vec), std::end(vec), std::greater<>{}, &wrapper::value) );
    }

    SECTION( "sort with random-access iterators" )
    {
        cppsort::sort(std::begin(vec), std::end(vec), &wrapper::value);
        CHECK( helpers::is_sorted(std::begin(vec), std::end(vec), std::less<>{}, &wrapper::value) );
    }

    SECTION( "sort with random-access iterators and compare" )
    {
        cppsort::sort(std::begin(vec), std::end(vec), std::greater<>{}, &wrapper::value);
        CHECK( helpers::is_sorted(std::begin(vec), std::end(vec), std::greater<>{}, &wrapper::value) );
    }

    SECTION( "sort with bidirectional iterators" )
    {
        std::list<wrapper> li(std::begin(vec), std::end(vec));
        cppsort::sort(std::begin(li), std::end(li), &wrapper::value);
        CHECK( helpers::is_sorted(std::begin(li), std::end(li), std::less<>{}, &wrapper::value) );
    }

    SECTION( "sort with bidirectional iterators and compare" )
    {
        std::list<wrapper> li(std::begin(vec), std::end(vec));
        cppsort::sort(std::begin(li), std::end(li), std::greater<>{}, &wrapper::value);
        CHECK( helpers::is_sorted(std::begin(li), std::end(li), std::greater<>{}, &wrapper::value) );
    }

    SECTION( "sort with forward iterators" )
    {
        std::forward_list<wrapper> li(std::begin(vec), std::end(vec));
        cppsort::sort(std::begin(li), std::end(li), &wrapper::value);
        CHECK( helpers::is_sorted(std::begin(li), std::end(li), std::less<>{}, &wrapper::value) );
    }

    SECTION( "sort with forward iterators and compare" )
    {
        std::forward_list<wrapper> li(std::begin(vec), std::end(vec));
        cppsort::sort(std::begin(li), std::end(li), std::greater<>{}, &wrapper::value);
        CHECK( helpers::is_sorted(std::begin(li), std::end(li), std::greater<>{}, &wrapper::value) );
    }
}
