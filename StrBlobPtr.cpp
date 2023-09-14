#include "StrBlobPtr.h"

#include "StrBlob.h"

StrBlobPtr::StrBlobPtr(StrBlob& a, size_t sz) : wptr(a.data), curr(sz) {}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string& msg) const {
    auto ret = wptr.lock();
    if (!ret) throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size()) throw std::out_of_range(msg);

    return ret;
}

std::string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");

    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;

    return *this;
}

bool StrBlobPtr::operator!=(const StrBlobPtr& rhs) const { return curr != rhs.curr; }

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }

StrBlobPtr StrBlob::end() {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}