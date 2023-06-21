#include <bits/stdc++.h>
using namespace std;

template<class T>
class mono{
    private:
        stack<pair<T, T>> s1, s2;
    public:
        mono() {};
        bool empty() {
            return s1.empty() && s2.empty();
        }
        void push(T val) {
            T min_val = s1.empty() ? val : min(s1.top().second, val);
            s1.push({val, min_val});
        }
        T pop() {
            if(s2.empty()) {
                while(!s1.empty()) {
                    T val = s1.top().first;
                    s1.pop();
                    T min_val = s2.empty()  ? val
                        : min(s2.top().second, val);
                    s2.push({val, min_val});
                }
            }
            auto e = s2.top();
            s2.pop();
            return e.first;
        }
        T get() {
            T val;
            if (s1.empty() || s2.empty())
                val = s1.empty() ? s2.top().second : s1.top().second;
            else
                val = min(s1.top().second, s2.top().second);
            return val;
        }
};

int main() {
    srand(time(nullptr));
    mono<int> mi;
    for(int i = 0; i < 10; i++) {
        int n = 10 + rand() % 100;
        printf("Inserting %d\n", n);
        mi.push(n);
        int min_e = mi.get();
        printf("Current min %d\n", min_e);
    }
    mono<float> mf;
    for(int i = 0; i < 10; i++) {
        float n = 10 + rand() % 100;
        printf("Inserting %f\n", n);
        mf.push(n * 1.f);
        float min_e = mf.get();
        printf("Current min %f\n", min_e);
    }
    return 0;
}
