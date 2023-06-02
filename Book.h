#ifndef BOOK
#define BOOK
#include "Material.h"
#include<iostream>

class Book : public Material {
    public:
        Book();
        ~Book();
        Book(const Book& );
        Book(Book&&)noexcept;
        Book& operator=(const Book&);
        Book& operator=(Book&&);
        void SetTitle(int title);
        void SetAuthor(const std::string& name);
        void SetYear(int year);
        void SetGener(const std::string& gener);
        void SetNumber(int number);
        std::string GetTitle();
        std::string GetAuther();
        int GetYear();
        std::string GetGener();
        int GetPageNumber();
        void Use() override;
        bool IsBorrowed()const; 

    private:
        void MySwap(Book&)noexcept;
        int m_publish_year = 0;
        int m_number_of_pages = 0;
        std::string m_title {""};
        std::string m_author {""};
        std::string m_gener {""};
};

#include"Book.hpp"
#endif //Book