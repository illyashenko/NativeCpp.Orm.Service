#pragma once
template <typename proptype, typename propowner> 
class property
{
protected:
    typedef proptype(propowner::* getter)();
    typedef void (propowner::* setter)(proptype);
    propowner* m_owner;
    getter m_getter;
    setter m_setter;
public:
    // �������� ���������� ����. ��������� �������� ��� ������.
    operator proptype()
    {
        // ����� ����� ���� �������� "m_owner" � "m_getter" �� NULL
        return (m_owner->*m_getter)();
    }
    // �������� ������������. ��������� �������� ��� ������.
    void operator =(proptype data)
    {
        // ����� ����� ���� �������� "m_owner" � "m_setter" �� NULL
        (m_owner->*m_setter)(data);
    }
    // ����������� �� ���������.
    property() :
        m_owner(nullptr)
    {
    }
    //����������� �������������.
    property(propowner* const owner, getter getmethod, setter setmethod) :
        m_owner(owner),
        m_getter(getmethod),
        m_setter(setmethod)
    {
    }
    // �������������
    void init(propowner* const owner, getter getmethod, setter setmethod)
    {
        m_owner = owner;
        m_getter = getmethod;
        m_setter = setmethod;
    }
};