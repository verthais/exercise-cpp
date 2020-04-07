#include "gtest/gtest.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <ostream>
#include <sstream>

using namespace std;
 
struct Room {
    int size;
    int light;
    int m_x{}, m_y{};
    std::vector<std::vector<int>> grid;
    
    Room(int s, int l) : size(s), light(l), grid(size, std::vector<int>(size))
    { }
    
    void push(const std::string& row) {
        for(const auto& c : row) {
            if(c != ' ') {
                push(c);
            }
        }
    }
    
    void push(char c) {
        if(c == 'X') {
            grid[m_x][m_y] += 0;
        } else if (c == 'C') {
            grid[m_x][m_y] = light;
            spread(m_x,m_y,light,1);
        }
        
        ++m_x;
        if(m_x >= size) {
            ++m_y;
            m_x=0;
        }
    }
    
    void spread(int x, int y, int l, int d) {
        if ( l - d == 0 ) return;
        
        for(int px = x - d; px < x + d + 1; ++px) {
            shed(px, y-d, l-d);
            shed(px, y+d, l-d);
        }
        
        for(int py = y - d; py < y + d + 1; ++py) {
            shed(x-d, py, l-d);
            shed(x+d, py, l-d);
        }
    
        shed_f(x-d, y-d, l-d);
        shed_f(x+d, y+d, l-d);
        shed_f(x-d, y+d, l-d);
        shed_f(x+d, y-d, l-d);
    
        spread(x,y,l,d+1);
    }
    void shed_f(int x, int y, int l) {
        if(x>= 0
        && y >=0
        && x < size
        && y < size) {
            grid[x][y] = l;    
        }
    }    
    void shed(int x, int y, int l) {
        if(x>= 0
        && y >=0
        && x < size
        && y < size) {
            grid[x][y] += l;    
        }
    }
    
    int count() const {
        int result{};
        for(int x{}; x<size; ++x) {
            for(int y{}; y<size; ++y) {
                if(grid[x][y] == 0) {
                    ++result;
                }
            }
        }
        return result;
    }
    
    std::string str() {
        std::stringstream out;
        for(int x{}; x<size; ++x) {
            for(int y{}; y<size; ++y) {
                out << grid[x][y];
            }
            out << endl;
        }
        return out.str();
    }
};

TEST(lumen, simple)
{
    std::vector<std::string> grid {
        "X X X X X",
        "X C X X X",
        "X X X X X",
        "X X X X X",
        "X X X X X"
    };

    Room room{5,3};

    for(const auto& row : grid)
    {
        room.push(row);
    }

    EXPECT_EQ(room.count(), 9);
}

TEST(lumen, four_candels)
{
    std::vector<std::string> grid {
        "C X X X C",
        "X X X X X",
        "X X X X X",
        "X X X X X",
        "C X X X C"
    };

    Room room{5, 3};

    for(const auto& row : grid)
    {
        room.push(row);
    }

    EXPECT_EQ(room.count(), 0);
}

TEST(lumen, multiple_light_sources)
{
    std::vector<std::string> grid {
        "X X X C X C X X X X X X X X X X X X X X",
        "X C X X X C X X X X C X X X X C X X X X",
        "X X X X X X X X X X X X X C C X X X X X",
        "X X X X X X X X X X X X X X X X X X X X",
        "X X X X X X X X X X X X X X X X X X X C",
        "X X X X X X X X C X X X X X X X C X X X",
        "X X X X X C X X X X X X X X C X X X X C",
        "X X X X X X C X X C C C X X X X X X X X",
        "X C X X X X X X X X C X X X C X X X X X",
        "X X X X C X X C X X X X X X X X X C X X",
        "X X X X X X X X X C X C X X X X X X X X",
        "X X X X X X X X X X X X X X X X X X X X",
        "X X X X X X C X X X X X X X X X X C X X",
        "X X X X X X X X X X X X X X X X X X X X",
        "X X X X X X X X X C C X X X X C X X X X",
        "X X X X X X X X X X X X C C C X X X X X",
        "X X X X X X X X C X X X X X X X C C X X",
        "X X X C X X X X X X X X X X X X X C X X",
        "X X X X X C X X X X X X X X X C X X X X",
        "X C X C X X X X X X X X X X X X X X X X"
    };

    Room room{20, 3};

    for(const auto& row : grid)
    {
        room.push(row);
    }

    EXPECT_EQ(room.count(), 34);
}