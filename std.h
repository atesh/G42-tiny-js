#ifndef MOSYNC_STRING
#define MOSYNC_STRING

#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <afxtempl.h>
#include <math.h>
//#include <MAUtil/String.h>
//#include <MAUtil/util.h>
//#include <conprint.h>

namespace std
{
	class string
	{
	private:
		CString data;

	public:
		typedef size_t size_type;

	public:
		enum {
			npos = -1
		};

	public:
		string() : data("") { }
		string(const char ch) { char buf[2]; buf[0] = ch; buf[1] = '\0'; data = buf; }
		string(const char* str) : data(str) {}
		string(const string& other) : data(other.data) {}

		string( const string& str, size_t pos, size_t n = npos) 
		{
			_ASSERT(0);
		}

		string& operator=(const string& other);

		string& operator+=(const string& other);

		char operator[](int index) const { return data[index]; }

		bool operator==(const string& other) const { return data == other.data; }

		bool operator!=(const string& other) const { return data != other.data; }
		bool operator<(const string& other) const { return data < other.data; }
		bool operator>(const string& other) const { return data > other.data; }
		bool operator<=(const string& other) const { return data <= other.data; }
		bool operator>=(const string& other) const { return data >= other.data; }

		string append(const string& other) { data += other.data; return *this;}
		string append(int nCount, char ch ) { data += CString(ch, nCount); return *this;}

		void clear() { data.Empty(); }

		const char* string::c_str() const  { return (LPCTSTR) data; }

		size_t find(const string& findMe, size_type startIndex = 0) const
		{
			return data.Find( findMe.data, startIndex );
			//return data.find(findMe.c_str(), startIndex);
		}
		size_t rfind( const string& findMe) const
		{
			int nPos = 0, nNewPos = 0;

			do {
				nPos = nNewPos;
				nNewPos = data.Find( findMe.data, nPos );
			} while (nNewPos > 0);
			return nPos;
		}
		char* begin()
		{
			return data.GetBuffer();
		}
		char* end()
		{
			return data.GetBuffer() + data.GetLength();
		}
		int find_first_not_of(char *p)
		{
			const char* pData = c_str();
			int i;
			for (i=0; pData[i]; i++)
			{
				bool match = false;
				for (int j=0; p[j]; j++)
					if (pData[i] == p[j])
					{
						match = true;
						break;
					}
				if (!match)
					break;
			}
			return i;
		}
		int find_last_not_of(char *p)
		{
			const char* pData = c_str();
			int l = data.GetLength();
			int i;
			for (i=l-1; i>0; i++)
			{
				bool match = false;
				for (int j=0; p[j]; j++)
					if (pData[i] == p[j])
					{
						match = true;
						break;
					}
				if (!match)
					break;
			}
			return i;
		}

		size_t length() const { return data.GetLength(); }
		size_t size() const { return data.GetLength(); }

		string substr(int startIndex, int length = npos) const
		{
			//return data.substr(startIndex, length).c_str();
			return string(data.Mid(startIndex, length));

		}
		bool empty() const
		{
			return data.IsEmpty(); 
		}

		char at(int nPos)
		{
			// range check
			return data[nPos];
		}
		void resize(int a)
		{
			_ASSERT(0);
		}
	};

	const string operator+(const string& me, const string& other);
	const string operator+(const string& me, const char ch);
	const string operator+(const string& me, int n);

	class ostringstream
	{
		friend ostringstream& operator<<(ostringstream& os, const string& s);

	private:
		string buffer;

	public:
		ostringstream() : buffer("") {}

		const char* str() const
		{
			return buffer.c_str();
		}
	};

	ostringstream& operator<<(ostringstream& os, const string& s);
}

namespace std
{
	template <typename T> class vector
	{
	private:
		CArray<T> data;

	public:
		typedef size_t size_type;
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef T* reverse_iterator;

	public:
		vector()
		{
		}

		vector( const vector<T>& other)
		{
			data.Copy( other.data );
		}
		vector(int nLength, T val)
		{
			data.SetSize(nLength);
			for (int i=0; i<nLength; i++) data[i] = val;
		}
		size_type size() const { return data.GetSize(); }
		void clear() { data.RemoveAll(); }
		T& back() { return data[size() - 1]; }
		const T& back() const { return data[data.size() - 1]; }
		void push_back(const T& element) { data.Add(element); }
		void pop_back() { data.RemoveAt(size()-1); }
		T& operator[](size_type index) { return data[index]; }
		const T& operator[](size_type index) const { return data[index]; }
		iterator begin() { return &data[0]; }
		iterator end() { return &data[0] + size(); }

		const_iterator begin() const { return &data[0]; }
		const_iterator end() const { return &data[0] + size(); }

		bool empty() { return data.IsEmpty() ? true : false; }
		T& front() { return data[0]; }
		void swap(vector<T>& sw)
		{
			vector<T> tmp;
			tmp.data.Copy( sw.data );  // TMP <- SW
			sw.data.Copy( data );		// SW <- this
			data.Copy( tmp.data );			// this <- TMP
		}
		reverse_iterator rbegin()
		{
			_ASSERT(0);
			return 0;
		}
		reverse_iterator rend()
		{
			_ASSERT(0);
			return 0;
		}
		void insert( iterator at, const T& itm)
		{
			_ASSERT(0);
			//data.InsertAt( at, *itm );
		}
		void erase(iterator it)
		{
			_ASSERT(0);
		}
	};

	template <typename T> class set
	{
	public:
		typedef T* iterator;
		void insert(const T&t)
		{
			_ASSERT(0);
		}
		int size()
		{
			_ASSERT(0);
			return 0;
		}
		iterator begin()
		{
			_ASSERT(0);
			return 0;
		}
		iterator end()
		{
			_ASSERT(0);
			return 0;
		}
	};
	
	template <class iterator, class T>
	iterator find (iterator begin, iterator end, const T& x)
	{
		_ASSERT(0);
		return end;
	}

	template <class iterator>
	void sort( iterator begin, iterator end)
	{
		_ASSERT(0);
	}

	template <class iterator, class T>
	iterator lower_bound (iterator begin, iterator end, const T& v)
	{
		_ASSERT(0);
		return end;
	}

	template <class iterator, class T, class FCompare>
	iterator lower_bound (iterator begin, iterator end, const T& v, FCompare f)
	{
		_ASSERT(0);
		return end;
	}

	template<class T>
	class auto_ptr
	{
	public:
		T* p;
		auto_ptr(T* n)
		{
			p = n;
		}
		~auto_ptr()
		{
			if (p)
				delete p;
		}
		T* operator->() const
		{
			return p;
		}
		T* release()
		{
			T* tmp = p;
			p = NULL;
			return tmp;
		}
	};

	template <class iterator, class Func>
	void transform( iterator begin, iterator end, iterator x, Func* f )
	{
		_ASSERT(0);
	}

	template <class T1, class T2>
	bool typeidequal( const T1& p1, const T2& p2 )
	{
		_ASSERT(0);
		return false;
	}
}
#endif