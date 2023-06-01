#ifndef DVD_HPP
#define DVD_HPP
#include"DVD.h"
#include<iostream>
#include"Material.h"

DVD::DVD() {}

DVD::~DVD() = default;

void DVD::DVDSwap(DVD& th)noexcept
{
    std::swap(m_director,th.m_director);
    std::swap(m_duration,th.m_duration);
    std::swap(m_year,th.m_year);
    std::swap(m_title,th.m_title);
    SetBorrowed(th.GetBorrowed());
}


DVD::DVD(const DVD& th) 
{
    m_director = th.m_director;
    m_duration = th.m_duration;
    m_title = th.m_title; 
    m_year = th.m_year;
    SetBorrowed(GetBorrowed());
}

DVD::DVD( DVD&& th)
{
   DVDSwap(th);
}
DVD& DVD::operator= (const DVD& th)
{
    if (this != &th)
    {
        DVD tmp{th};
        DVDSwap(tmp);
    }
    return *this;
}
DVD& DVD::operator= (DVD&& th)
{
    if (this != &th)
    {
        DVDSwap(th);
    }
    return *this;
}

void DVD::SetYear(int year)
{
    m_year = year;
}

void DVD::SetDuration(int dur)
{
    m_duration = dur;
}

void DVD::SetTitle(std::string title)
{
    m_title = title;
}

void DVD::SetDirector(std::string dir)
{
    m_director = dir;
}

void DVD::Use()
{
    std::cout << "You are watching, relax and enjoy";
}

bool DVD::IsBorrowed() const
{
    return GetBorrowed();
}

#endif //DVD_HPP