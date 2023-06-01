#ifndef MATERIAL_H
#define MATERIAL_H
#include"Material.h"

bool Material::GetBorrowed() const
{
    return m_is_borrowed;
}
void Material::SetBorrowed(bool tmp)
{
    m_is_borrowed = tmp;
}

#endif //Material
