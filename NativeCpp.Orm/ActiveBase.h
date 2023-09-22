#pragma once

template <typename T>
class ActiveBase
{
private:
	T m_value;
public:
	_declspec(property(get = get, put = set)) T Value;

	T get() {
		return m_value;
	}

	void set(T value) {
		m_value = value;
	}

	ActiveBase() {
	}
};

