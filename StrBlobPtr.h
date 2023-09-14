#pragma
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
class StrBlob;

class StrBlobPtr {
   public:
    StrBlobPtr() : curr(0) {}

    StrBlobPtr(StrBlob& a, size_t sz = 0);

    std::string& deref() const;

    StrBlobPtr& incr();

    bool operator!=(const StrBlobPtr& rhs) const;

   private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;

    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};