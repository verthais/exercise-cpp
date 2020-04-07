#include <memory>
#include <iostream>

#include "gtest/gtest.h"

template<typename T>
struct Node {
    T value;
    std::unique_ptr<Node> next;

    Node(const T& v) : value(v), next{nullptr} {};

    void push(const T& v) {
        auto temp{std::make_unique<Node<T>>(v)};
        if(next) {
            temp->next = std::move(next);
            next = std::move(temp);
        } else {
            next = std::move(temp);
        }
    }

    std::string str() const {
        return std::to_string(value) + "-->" + ( next ? next->str() : "end" );
    }
};

template<typename T>
struct Root {
    std::unique_ptr<Node<T>> root;

    Root() noexcept : root{nullptr} {};
    Root(std::initializer_list<T> source)
    {
        for(auto e : source)
        {
            push(std::move(e));
        }
    }

    void push(const T&& v)  {
        auto temp{std::make_unique<Node<T>>(v)};
        if(root) {
            temp->next = std::move(root);
            root = std::move(temp);
        } else {
            root = std::move(temp);
        }
    }

    void reverse() noexcept {
        Root temp;
        while(root) {
            temp.push(std::move(root->value));
            root = std::move(root->next);
        }
        clean();
        root = std::move(temp.root);
    }

    void clean() noexcept {
        while(root) {
            root = std::move(root->next);
        }
    }

    void pop() noexcept {
        if(root) {
            root = std::move(root->next);
        }
    }

    std::string str() const {
        return (root ? root->str() : "empty");
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Root<T>& r) {
    out << r.str();
    return out;
}

TEST(linked_list, push)
{
    Root<int> root;
    root.push(5);
    root.push(4);
    root.push(3);
    root.push(2);
    root.push(1);

    EXPECT_EQ("1-->2-->3-->4-->5-->end", root.str());
}

TEST(linked_list, pop)
{
    Root<int> root{1,2,3,4,5};

    root.pop();
    root.pop();
    EXPECT_EQ("3-->2-->1-->end", root.str());
}

TEST(linked_list, reverse)
{
    Root<int> root{1,2,3};q
    root.reverse();
    EXPECT_EQ("1-->2-->3-->end", root.str());
}