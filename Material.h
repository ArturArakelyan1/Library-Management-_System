#ifndef MATERIAL
#define MATERIAL
#include<iostream>
#include<utility>


class Material {
    public:
        virtual void Use() = 0;
        void SetBorrowed(bool is_borrowed);
        bool GetBorrowed()const;
    private:
        bool m_is_borrowed {false};

};
#include"Material.hpp"

#endif //MATERIAL