#include "StrBlob.h"

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(make_shared<vector<std::string>>(il)) {}

StrBlob& StrBlob::operator=(const StrBlob& rhs) {
    if (this == &rhs) return *this;
    std::lock_guard<std::mutex> lock(mut);
    data = make_shared<vector<std::string>>(*rhs.data);
    return *this;
}

StrBlob::StrBlob(StrBlob&& rhs) noexcept : data(std::move(rhs.data)) {}

StrBlob& StrBlob::operator=(StrBlob&& rhs) noexcept {
    if (this == &rhs) return *this;
    std::lock_guard<std::mutex> lock(mut);
    data = std::move(rhs.data);
    return *this;
}

void StrBlob::check(size_type i, const string& msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}

string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

const string& StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

const string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    std::lock_guard<std::mutex> lock(mut);
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

void StrBlob::push_back(const string& t) {
    std::lock_guard<std::mutex> lock(mut);
    check(0, "push_back on empty StrBlob");
    data->push_back(t);
}