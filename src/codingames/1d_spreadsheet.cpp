#include <iostream>
#include <exception> // invalid_argument 
#include <string>    // string, stoi
#include <algorithm> // any_of
#include <tuple>
#include <vector>    // vector

#include "gtest/gtest.h"

using namespace std;

bool is_ref(const string& s)
{
    return s.front() == '$';
}

int refToIdx(const string& s)
{
    string value = s.substr(1, s.size() - 1);
    return stoi(value);
}

int action(const string& opt, int rhs, int lhs)
{
    if(opt == "VALUE"){
        return rhs;
    }
    if(opt == "ADD"){
        return (rhs + lhs);
    }
    if(opt == "SUB"){
        return (rhs - lhs);
    }
    if(opt == "MULT"){
        return (rhs * lhs);
    }

    throw invalid_argument(opt + " is not know operation, expected: VALUE, ADD, SUB, MULT");
}

struct cell {
    cell(const string& o, const string& a1, const string& a2)
        : opt{o}, s1{a1}, s2{a2} {};
    
    const bool isSolved() const { return solved; }
    
    string s1;
    string s2;
    string opt;
    int value;
    bool solved{false};

};

ostream& operator<<(ostream& os, const cell& p)
{
    os << p.opt << " " << p.s1 << " " << p.s2;
    return os;
}

bool isSolved(const vector<cell>& d)
{
    if(any_of(d.begin(), d.end(), [](const auto& p){ return p.solved == false; }))
        return false;
    return true;
}

void solve(vector<cell>& d)
{
    while(!isSolved(d))
    {
        for(cell& p : d) {
            if(p.isSolved()) continue;

            int value1, value2;

            if(is_ref(p.s1)) {
                int idx = refToIdx(p.s1);
                if(!d[idx].isSolved()) continue; // we can't solve it yet
                value1 = d[idx].value;
            } else {
               value1 = stoi(p.s1); 
            }

            if(is_ref(p.s2)) {
                int idx = refToIdx(p.s2);
                if(!d[idx].isSolved()) continue; // we can't solve it yet
                value2 = d[idx].value;
            } else if (p.s2 == "_") {
                // pass
            } else { value2= stoi(p.s2); }

            p.value = action(p.opt, value1, value2);
            p.solved = true;
        }
    }
}

TEST(one_dim_ss, simple)
{
    vector<cell> data;
    vector<int> expected = { 3, 7 };
    vector<tuple<string,string,string>> input {
        { "VALUE", "3" , "_" },
        { "ADD"  , "$0", "4" }
    };
    

    for (auto [opt, s1, s2] : input) {
        data.emplace_back(opt, s1, s2);
    }

    solve(data);
    for(size_t idx{}; idx < expected.size(); ++idx) {
      EXPECT_EQ(data[idx].value, expected[idx]);
    }
}


TEST(one_dim_ss, recursion)
{
    vector<cell> data;
    vector<int> expected { 20, 120, 121 };
    vector<tuple<string,string,string>> input {
        { "VALUE", "20", "_"},
        { "ADD", "$0", "100"},
        { "ADD", "$1", "1"},
    };

    for (auto [opt, s1, s2] : input) {
        data.emplace_back(opt, s1, s2);
    }

    solve(data);
    for(size_t idx{}; idx < expected.size(); ++idx) {
      EXPECT_EQ(data[idx].value, expected[idx]);
    }
}

TEST(one_dim_ss, sub)
{
    vector<cell> data;
    vector<int> expected { 20, 19 };
    vector<tuple<string,string,string>> input {
        { "VALUE", "20", "_"},
        { "SUB", "$0", "1"},
    };

    for (auto [opt, s1, s2] : input) {
        data.emplace_back(opt, s1, s2);
    }

    solve(data);
    for(size_t idx{}; idx < expected.size(); ++idx) {
      EXPECT_EQ(data[idx].value, expected[idx]);
    }
}

TEST(one_dim_ss, mult)
{
    vector<cell> data;
    vector<int> expected { 20, 120 };
    vector<tuple<string,string,string>> input {
        { "VALUE", "20", "_"},
        { "MULT", "$0", "6"},
    };

    for (auto [opt, s1, s2] : input) {
        data.emplace_back(opt, s1, s2);
    }

    solve(data);
    for(size_t idx{}; idx < expected.size(); ++idx) {
      EXPECT_EQ(data[idx].value, expected[idx]);
    }
}

