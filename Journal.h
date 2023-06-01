#ifndef JOURNAL_H
#define JOURNAL_H
#include<iostream>
#include "Material.h"

class Journal : public Material {
    public:
        Journal();
        ~Journal();
        Journal(const Journal&);
        Journal (Journal&&);
        Journal& operator= (const Journal&);
        Journal& operator=(Journal&&);
        void MySwap(Journal&)noexcept;
        void SetTitle(int);
        void SetVolume(int);
        void SetIssue(const std::string&);
        void SetYear(int);
        void SetSubject(const std::string&);
        int GetTitle();
        int GetVolume();
        std::string GetIssue();
        int GetYear();
        std::string GetSubject();
        void Use() override;
        bool JIsBorrowed() const; 

    private:
       int  m_title = 0;
       int m_volume = 0;
       int m_year = 0;
       std::string m_issue {""};
       std::string m_subject {""};
};
#include"Journal.hpp"
#endif //journal 