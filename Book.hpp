#ifndef BOOK_H 
#define BOOK_H
#include"Book.h"
#include"Material.h"
#include<iostream>
#include<utility>

Book::Book(){};

Book::~Book() = default;
void Book::MySwap(Book& th)noexcept
{
    std::swap(m_author,th.m_author);
    std::swap(m_gener,th.m_gener);
    std::swap(m_number_of_pages,th.m_number_of_pages);
    std::swap(m_publish_year,th.m_publish_year);
    std::swap(m_title,th.m_title);
    SetBorrowed(th.GetBorrowed());
}

Book::Book(const Book& other)
{
    m_author = other.m_author;
    m_gener = other.m_gener;
    m_number_of_pages = other.m_number_of_pages;
    m_publish_year = other.m_publish_year;
    m_title = other.m_title; 
    SetBorrowed(other.GetBorrowed());
};
Book::Book(Book&& other)noexcept
{
   MySwap(other);
}

Book&  Book::operator=(const Book& other)
{
    if(this != &other)
    {
        Book tmp{other};
        MySwap(tmp);
    }
    return *this;
}
Book& Book::operator=(Book&& th)
{
    if(this != &th)
    {
      MySwap(th);
    }
    return *this;
}

 void Book::SetTitle(int title)
 {
    m_title = title;
 }

 void Book::SetAuthor(const std::string& name)
 {
    m_author = name;
 }
 void Book::SetYear(int year)
 {
    m_publish_year = year;
 }

 void Book::SetGener(const std::string& gener)
 {
    m_gener = gener;
 }

 void Book::SetNumber(int number)
 {
   m_number_of_pages = number; 
 }

 std::string Book::GetTitle()
 {
   return m_title;
 }

 std::string Book::GetAuther()
 {
    return m_author;
 }

 int Book::GetYear()
 {
    return m_publish_year;
 }

 std::string Book::GetGener()
 {
    return m_gener;
 }

 int Book::GetPageNumber()
 {
    return m_number_of_pages;
 }

 void Book::Use()
 {
    std::cout << "Read";
 }

 bool Book::IsBorrowed()const 
 {
   return GetBorrowed();
 } 

#endif //Book