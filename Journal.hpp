#ifndef JOURNAL_HPP
#define JOURNAL_HPP
#include"Journal.h"
#include"Material.h"

Journal::Journal(){};
void Journal::MySwap(Journal& th)noexcept
{
    std::swap(m_volume,th.m_volume);
    std::swap(m_issue,th.m_issue);
    std::swap(m_year,th.m_year);
    std::swap(m_subject,th.m_subject);
    std::swap(m_title,th.m_title);
    bool tmp{th.GetBorrowed()};
    SetBorrowed(tmp);
}
Journal::~Journal() = default;
Journal::Journal(const Journal& th)
{
    m_volume = th.m_volume;
    m_issue = th.m_issue;
    m_year = th.m_year;
    m_subject = th.m_subject;
    m_title = th.m_title;
    bool tmp {GetBorrowed()};
    SetBorrowed(tmp);

}
Journal::Journal(Journal&& th)
{
    MySwap(th);
}
Journal& Journal::operator= (const Journal& tmp)
{
    if(this != &tmp)
    {
        Journal tmp1{tmp};
        MySwap(tmp1);
    }
    return *this;
}
Journal& Journal::operator= (Journal&& th)
{
    if (this != &th)
    {
        MySwap(th);
    }
    return *this;
}
void Journal::SetTitle(int title)
{
    m_title = title;
}
void Journal::SetVolume(int vol)
{
    m_volume = vol;
}
void Journal::SetIssue(const std::string& issue)
{
    m_issue = issue;
}
void Journal::SetYear(int year)
{
    m_year = year;
}
void Journal::SetSubject(const std::string& subj)
{
    m_subject = subj;
}
int Journal::GetTitle()
{
    return m_title;
}
int Journal::GetVolume()
{
    return m_volume;
}
std::string Journal::GetIssue()
{
    return m_issue;
}
int Journal::GetYear()
{
    return m_year;
}
std::string Journal::GetSubject()
{
    return m_subject;
}
void Journal::Use() 
{
    std::cout << "looking at beautiful pictures  " ;
}
bool Journal::JIsBorrowed() const
{
    return GetBorrowed();
} 


#endif