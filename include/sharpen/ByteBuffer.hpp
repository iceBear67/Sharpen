#pragma once
#ifndef _SHARPEN_BYTEBUFFER_HPP
#define _SHARPEN_BYTEBUFFER_HPP

#include <vector>

#include "Noncopyable.hpp"
#include "TypeDef.hpp"

namespace sharpen
{
    class ByteBuffer:public sharpen::Noncopyable
    {
        using Vector = std::vector<sharpen::Char>;

        using Self = ByteBuffer;
    protected:
        Vector vector_;

        sharpen::Size mark_;

    private:
        void CheckAndMoveMark();

    public:
        explicit ByteBuffer(sharpen::Size size);

        explicit ByteBuffer(Vector &&vector) noexcept;

        ByteBuffer(const sharpen::Char *p,sharpen::Size size);

        ByteBuffer(Self &&other) noexcept;

        virtual ~ByteBuffer() noexcept = default;

        Self &operator=(Self &&other) noexcept;

        //use by stl
        void swap(Self &other) noexcept;

        inline void Swap(Self &other) noexcept
        {
            this->swap(other);
        }

        void PushBack(Char val);

        sharpen::Size GetSize() const;

        void PopBack();

        Char Front() const;

        Char &Front();

        Char Back() const;

        Char &Back();

        Char &Get(sharpen::Size index);

        Char Get(sharpen::Size index) const;

        Char *Data();

        const Char* Data() const;

        inline Char &operator[](sharpen::Size index)
        {
            return this->Get(index);
        }

        inline Char operator[](sharpen::Size index) const
        {
            return this->Get(index);
        }

        void Reserve(sharpen::Size size);

        void Expand(sharpen::Size size);

        void Shrink();

        void Append(const sharpen::Char *p,sharpen::Size size);

        void Append(const Self &other);

        void Erase(sharpen::Size pos);

        void Erase(sharpen::Size begin,sharpen::Size end);

        void Mark(sharpen::Size pos);

        sharpen::Size Remaining() const;

        sharpen::Size GetMark() const;
    };
    
} 

#endif