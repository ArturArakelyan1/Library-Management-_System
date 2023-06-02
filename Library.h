#ifndef LIBRARY_H
#define LIBRARY_H
#include"Material.h"
#include"Journal.h"
#include"Book.h"
#include"DVD.h"
#include<iostream>
#include<vector>

class Library {
    public:
        Library();
        ~Library();
        Library(const Library&);
        Library(Library&&);
        Library& operator= (const Library&);
        Library& operator= (Library&&);
        void LibSwap(Library&);
        void SetBookCount(int);
        void SetDVDCount(int);
        void SetJournalCount(int);
        int GetBookCount();
        int GetDVDCount();
        int GetJournalCount();
        void AddBook(Book&);
        void AddDVD(DVD&);
        void AddJournal(Journal&);
        void RmBook(Book&);
        void RmDVD(DVD&);
        void RmJournal(Journal&);
        bool IsInLibrary(Material*);
        void Take(Material*);   
    private:
        bool RmMaterial(Material& obj);
        int m_book_count = 0;
        int m_dvd_count = 0;
        int m_journal_count = 0;
        std::vector<Material*> m_materials;
};
        #include"Library.hpp"
#endif 