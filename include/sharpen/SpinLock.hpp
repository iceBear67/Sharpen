#pragma once
#ifndef _SHARPEN_SPINLOCK_HPP
#define _SHARPEN_SPINLOCK_HPP

#include <atomic>

#include "Noncopyable.hpp"
#include "Nonmovable.hpp"

namespace sharpen
{

    class SpinLock:public sharpen::Noncopyable,public sharpen::Nonmovable
    {
    private:
        using Flag = std::atomic_bool;

        Flag flag_;
    public:
        SpinLock();

        //use by stl
        void lock();

        inline void Lock()
        {
            this->lock();
        }

        //use by stl
        void unlock() noexcept;

        void Unlock() noexcept
        {
            this->unlock();
        }

        ~SpinLock() = default;
    };

} 

#endif