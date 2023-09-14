#include <iostream>

#include "StrBlob.h"
#include "StrBlobPtr.h"

using namespace std;

vector<int> *createVector() {
    vector<int> *pv = new vector<int>();
    int i = 0;
    cin >> i;
    (*pv).push_back(i);
    return pv;
}

shared_ptr<vector<int>> createSharedVector() { return make_shared<vector<int>>(); }

void printVector(vector<int> *vp) {
    cout << "vp size: " << vp->size() << endl;

    for (auto i : *vp) {
        cout << i << endl;
    }
}

void deleteVector(vector<int> *vp) {
    delete vp;
    vp = nullptr;
}

int *b() {
    int *p = new int;
    return p;
}

void process(shared_ptr<int> p) { cout << *p << endl; }

int main() {
    StrBlob sb({"a", "b", "c"});
    StrBlob sb1 = {"aaa", "bbb", "ccc"};
    for (StrBlobPtr p = sb1.begin(); p != sb1.end(); p.incr()) {
        cout << p.deref() << endl;
    }

    cout << sb.size() << endl;
    cout << sb1.size() << endl;

    for (StrBlobPtr p = sb.begin(); p != sb.end(); p.incr()) {
        cout << p.deref() << endl;
    }

#if 0
    shared_ptr<int> p;
    shared_ptr<int> q(new int(42));
    // process(new int(100));
    process(q);

    auto p1 = new int();
    // process(p1); error
    process(shared_ptr<int>(p1));
    auto sp = make_shared<int>();
    process(sp);

    auto sp1 = make_shared<int>();
    auto sp2 = sp1.get();
    // delete sp2; error
#endif
    // int *q = new int(42), *r = new int(100);
    // r = q;
    // cout << *q << endl;
    // cout << *r << endl;
    // auto q1 = make_shared<int>(42), r1 = make_shared<int>(100);
    // r1 = q1;
    // cout << *q1 << endl;
    // cout << *r1 << endl;
    // int *p = b();
    // cin >> *p;
    // cout << *p << endl;
    {
#if 0
        vector<int> *vp = createVector();
        printVector(vp);
        deleteVector(vp);

        shared_ptr<vector<int>> sp = createSharedVector();
        sp->push_back(1);
        sp->push_back(2);
        printVector(sp.get());
#endif
    }
#if 0
    StrBlob b1;
    {
        StrBlob b2 = {"a", "b", "c"};
        cout << "b2 size: " << b2.size() << endl;
        b1 = b2;
        cout << "b1 size: " << b1.size() << endl;
        b2.push_back("d");
        cout << "b2 size: " << b2.size() << endl;

        StrBlob b3;
        b3 = std::move(b2);
        b3.pop_back();
        cout << "b3 size: " << b3.size() << endl;

        StrBlob b4({"e", "f"});
        StrBlob b5{"e", "f"};
    }

    vector<int> *pv = new vector<int>{1, 2, 3};
    for (auto i : *pv) {
        cout << i << endl;
    }

    delete pv;
    pv = nullptr;

    auto v = make_shared<vector<int>>();
    *v = {1, 2, 3};
    for (auto i : *v) {
        cout << i << endl;
    }

    const string *s = new string;
    const string *s1 = new const string;

    delete s;
    s = nullptr;
    delete s1;
    s1 = nullptr;
#endif
    return 0;
}