#pragma
#include <initializer_list>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

using namespace std;
class StrBlobPtr;

class StrBlob {
   public:
    friend class StrBlobPtr;

    StrBlobPtr begin();
    StrBlobPtr end();

    typedef std::vector<std::string>::size_type size_type;

    StrBlob();

    StrBlob(std::initializer_list<std::string> il);

    StrBlob& operator=(const StrBlob& rhs);

    StrBlob(StrBlob&& rhs) noexcept;

    StrBlob& operator=(StrBlob&& rhs) noexcept;

    size_type size() const { return data->size(); }

    bool empty() const { return data->empty(); }

    void push_back(const std::string& t);

    void pop_back();

    std::string& front();

    const std::string& front() const;

    std::string& back();

    const std::string& back() const;

   private:
    std::shared_ptr<std::vector<std::string>> data;

    std::mutex mut;

    void check(size_type i, const std::string& msg) const;
};