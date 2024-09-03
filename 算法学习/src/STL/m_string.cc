#include<iostream>
#include<string.h>
#include<iosfwd>
#include<assert.h>


#include<string>



namespace hansolo
{
class string
{
private:
    char *m_str;
    size_t m_size;
    size_t m_capacity;

public:

    //构造函数
    string(const char *str="")
    {
        m_size = strlen(str);
        m_capacity = m_size;
        m_str = new char[m_size + 1];
        memcpy(m_str,str,m_size+1);
    }

    //拷贝构造函数
    string(const string &str)
        : m_str{new char[str.m_capacity]}
        , m_size{str.m_size}
        , m_capacity{str.m_capacity}
    {
        memcpy(m_str, str.m_str, m_size + 1);
    }

    ~string()
    {
        if(m_str){
            delete[] m_str;
            m_str = nullptr;
            m_size = 0;
            m_capacity = 0;
        }
    }

    //重载赋值
    string & operator=(const string &str)
    {
        if(this!=&str){
            char *temp = new char[str.m_capacity + 1];
            memcpy(temp, str.m_str, str.m_size + 1);

            m_size = str.m_size;
            m_capacity = str.m_capacity;
        }
        return *this;
    }

    char &operator[](size_t pos){
        assert(pos < m_size);
        return m_str[pos];
    }
    const char &operator[](size_t pose) const
    {
        assert(pose < m_size);
        return m_str[pose];
    }

    friend std::ostream& operator<<(std::ostream &out, const string &s)
    {
        for (size_t i = 0; i < s.size();i++){
            out << s[i];
        }
        return out;
    }

    string& operator+=(char ch)
    {
        push_back(ch);
        return *this;
    }

    string &operator+=(const char *ch){
        append(ch);
        return *this;
    }

    //扩容
    void reverse(size_t n)
    {
        if(n>m_capacity){
            char *temp = new char[n + 1];
            memcpy(temp, m_str, m_size + 1);

            delete[] m_str;
            m_str = temp;
            m_capacity = n;
        }
    }
    void resize(size_t n,char ch='\0')
    {
        if(n<m_size){ //调整的大小小于原始大小
            m_size = n;
            m_str[m_size] = '\0';
        }
        else //调整的大小 大于原始大小
        {
            //先扩容
            reverse(n);
            //从末尾填充h
            for (size_t i = m_size; i < n;++i){
                m_str[i] = ch;
            }
            m_size = n;
            m_str[m_size] = '\0';
        }
    }

    void append(const char *str)
    {
        size_t len = strlen(str);
        if(len+m_size>m_capacity){
            reverse(m_size + len);
        }
        //尾部添加str
        memcpy(m_str+m_size, str, len + 1);
        m_size += len;
    }

    void push_back(char ch)
    {
        if(m_size==m_capacity){
            // 扩容两倍
            reverse(m_capacity == 0 ? 4 : m_capacity * 2);
        }
        m_str[m_size] = ch;
        m_size++;
        m_str[m_size] = '\0';
    }

    void pop_pack()
    {
        assert(m_size > 0);
        m_size--;
        m_str[m_size] = '\0';
    }

    void clear()
    {
        m_str[0] = '\0';
        m_size = 0;
    }

    void shrink_to_fit()
    {
        if(m_capacity>m_size+1){
            m_capacity = m_size + 1;
        }
    }

    const char *c_str()
    {
        return m_str;
    }

    size_t size() const
    {
        return m_size;
    }
    size_t length() const
    {
        return m_size;
    }

    size_t capacity() const
    {
        return m_capacity;
    }


public:
    typedef char *iterator;
    typedef const char *const_iterator;


    iterator begin()
    {
        return m_str;
    }

    iterator end()
    {
        return m_str + m_size;
    }

    const_iterator begin() const
    {
        return m_str;
    }

    const_iterator end() const
    {
        return m_str + m_size;
    }

};


}; // namespace hansolo

int main()
{
    // std::string ss;
    // ss.capacity();

    hansolo::string h_str{"ssssssssss"};

    hansolo::string h_str1 = h_str;
    std::cout << h_str.length() << '\n';

    h_str1.push_back('a');
    std::cout << h_str1 << '\n';
    h_str1.resize(17,'d');
    std::cout << h_str1 << '\n';

    h_str1.pop_pack();
    std::cout << h_str1 << '\n';
    for(const char  c : h_str1){
        std::cout << c << '\n';
    }
    h_str1 += 's';

    h_str1 += "hansolo";

    std::cout << h_str1 << '\n';
    return 0;
}
