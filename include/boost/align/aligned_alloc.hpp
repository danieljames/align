/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_ALIGN_ALIGNED_ALLOC_HPP
#define BOOST_ALIGN_ALIGNED_ALLOC_HPP

#include <boost/config.hpp>

#if defined(BOOST_HAS_UNISTD_H)
#include <unistd.h>
#endif

#if defined(__APPLE__) || defined(__APPLE_CC__) || defined(macintosh)
#include <AvailabilityMacros.h>
#endif

#if defined(BOOST_MSVC)
#include <boost/align/detail/aligned_alloc_msvc.hpp>
#elif defined(__MINGW32__) && (__MSVCRT_VERSION__ >= 0x0700)
#include <boost/align/detail/aligned_alloc_msvc.hpp>
#elif MAC_OS_X_VERSION_MIN_REQUIRED >= 1060
#include <boost/align/detail/aligned_alloc_posix.hpp>
#elif defined(__ANDROID__)
#include <boost/align/detail/aligned_alloc_android.hpp>
#elif defined(__SunOS_5_11) || defined(__SunOS_5_12)
#include <boost/align/detail/aligned_alloc_posix.hpp>
#elif defined(sun) || defined(__sun)
#include <boost/align/detail/aligned_alloc_sunos.hpp>
#elif (_POSIX_C_SOURCE >= 200112L) || (_XOPEN_SOURCE >= 600)
#include <boost/align/detail/aligned_alloc_posix.hpp>
#else
#include <boost/align/detail/aligned_alloc.hpp>
#endif

namespace boost {
    namespace alignment {
        using detail::aligned_alloc;
        using detail::aligned_free;
    }

    using alignment::aligned_alloc;
    using alignment::aligned_free;
}

#endif