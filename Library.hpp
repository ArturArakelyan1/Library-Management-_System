#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include"Library.h"
#include"Material.h"
#include"Journal.h"
#include"Book.h"
#include"DVD.h"
#include<iostream>
#include<vector>

Library::Library() = default;

Library::~Library() = default;
Library::Library(const Library& th)
{
    m_book_count = th.m_book_count;
    m_dvd_count = th.m_dvd_count;
    m_journal_count = th.m_journal_count;
    m_materials = th.m_materials;
}

Library::Library(Library&& th)
{
    LibSwap(th);
}

Library& Library::operator=(const Library& th)
{ 
  if (this != &th)
  {
    Library tmp{th};
    LibSwap(tmp);
  }
    return *this;
}

Library& Library::operator=(Library&& th)
{
    if (this != &th)
    {
        LibSwap(th);
    }
  return *this;
}

void Library::LibSwap(Library& th)
{
    std::swap(m_book_count,th.m_book_count);
    std::swap(m_dvd_count,th.m_dvd_count);
    std::swap(m_journal_count,th.m_journal_count);
    std::swap(m_materials,th.m_materials);   
}

void Library::SetBookCount(int bcout)
{
    m_book_count = bcout;
}

void Library::SetDVDCount(int dcout)
{
    m_dvd_count = dcout;
}

void Library::SetJournalCount(int jcout)
{
    m_journal_count = jcout;
}

int Library::GetBookCount()
{
    return m_book_count ;
}

int Library::GetDVDCount()
{
    return m_dvd_count;
}

int Library::GetJournalCount()
{
    return m_journal_count;
}

void Library::AddBook(Book& th)
{
    m_materials.push_back(&th);
    m_book_count++;
}

void Library::AddDVD(DVD& dv) 
{
    m_materials.push_back(&dv);
    m_dvd_count++;
}

void Library::AddJournal(Journal& jh)
{
    m_materials.push_back(&jh);
    m_journal_count++;
}

bool Library::RmMaterial(Material& th)
{
for(auto it = m_materials.begin(); it != m_materials.end(); ++it) {
        if(*it == &th) 
        {
            m_materials.erase(it);
            return true;
        }
    }
    return false;
}

void Library::RmBook(Book& bh)
{
   if (RmMaterial(bh))
   {
        std::cout << "The book removal was successfully done";     
        m_book_count--;
        return;
   }
   std::cout << "The book is not in the library "; 
}

void Library::RmDVD(DVD& dvd)
{
   if (RmMaterial(dvd))
   {
        std::cout << "The DVD removal was successfully done";     
        m_dvd_count--;
        return;
   }
   std::cout << "The DVD is not in the library "; 
}

void Library::RmJournal(Journal& jornl)
{
   if (RmMaterial(jornl))
   {
        std::cout << "The Journal removal was successfully done";     
        m_journal_count--;
        return;
   }
   std::cout << "The Journal is not in the library "; 
}

bool Library::IsInLibrary(Material * ptr)
{
   for(auto it = m_materials.begin(); it != m_materials.end(); ++it) 
   {
        if(*it == ptr) 
        {
            return ptr->GetBorrowed();
        }
    }
    return false;
}

void Library::Take(Material* ptr)
{
    if (IsInLibrary(ptr))
    {
        ptr->SetBorrowed(true);
        return;
    }
    std::cout << "It is available at the moment";
}


#endif //Library
