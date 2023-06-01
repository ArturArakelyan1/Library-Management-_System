#ifndef DVD_H
#define DVD_H
#include"Material.h"
#include<iostream>

class DVD : public Material {
    public:
        DVD();
        ~DVD();
        DVD(const DVD&);
        DVD( DVD&&);
        DVD& operator= (const DVD&);
        DVD& operator= (DVD&&);
        void DVDSwap(DVD&)noexcept;
        void SetYear(int);
        void SetDuration(int);
        void SetTitle(std::string);
        void SetDirector(std::string);
        void Use() override;
        bool IsBorrowed() const;
    private:
        int m_year = 0;
        int m_duration = 0;
        std::string m_title {""};
        std::string m_director {""};
};

#include"DVD.hpp"

#endif//DVD