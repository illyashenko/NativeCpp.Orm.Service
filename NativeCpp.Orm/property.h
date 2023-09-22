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
    // Оператор приведения типа. Реализует свойство для чтения.
    operator proptype()
    {
        // Здесь может быть проверка "m_owner" и "m_getter" на NULL
        return (m_owner->*m_getter)();
    }
    // Оператор присваивания. Реализует свойство для записи.
    void operator =(proptype data)
    {
        // Здесь может быть проверка "m_owner" и "m_setter" на NULL
        (m_owner->*m_setter)(data);
    }
    // Конструктор по умолчанию.
    property() :
        m_owner(nullptr)
    {
    }
    //Конструктор инициализации.
    property(propowner* const owner, getter getmethod, setter setmethod) :
        m_owner(owner),
        m_getter(getmethod),
        m_setter(setmethod)
    {
    }
    // Инициализация
    void init(propowner* const owner, getter getmethod, setter setmethod)
    {
        m_owner = owner;
        m_getter = getmethod;
        m_setter = setmethod;
    }
};