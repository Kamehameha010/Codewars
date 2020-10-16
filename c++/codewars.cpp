
#include <iostream>
#include <string>
#include <exception>
#include <iterator>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstring>
#include <set>
#include <valarray>
//#include <compare>
bool solution(std::string const &, std::string const &);
int square_sum(const std::vector<int> &);
void miniMaxSum(std::vector<long>);
int count_sheep(std::vector<bool>);
bool betterThanAverage(std::vector<int>, int);
std::string DNAStrand(const std::string &);
auto letter = [](auto a) {
    switch (a)
    {
    case 'A':
        return 'T';
    case 'T':
        return 'A';
    case 'C':
        return 'G';
    case 'G':
        return 'C';
    }
    return '-';
};
std::vector<int> deleteNth(std::vector<int>, int);
int score(const std::vector<int> &);
bool isValidWalk(std::vector<char>);
std::vector<int> tribonacci(std::vector<int>, int);
//std::vector<int> race(int v1, int v2, int g);
std::string revRot(const std::string &, unsigned int);
std::vector<char> uniqueInOrder(const std::string &);
template <typename T>
std::vector<T> uniqueInOrder(const std::vector<T> &);
std::string uint32_to_ip(uint32_t ip);

int32_t main()
{
    std::cout << square_sum({0, 3, 4, 5}) << std::endl;
    miniMaxSum({396285104, 573261094, 759641832, 819230764, 364801279});
    std::cout << "\n"
              << count_sheep({true, true, true, false})
              << "\n";
    std::cout << betterThanAverage({47, 25}, 60) << std::endl;
    std::cout << DNAStrand("ATTA") << std::endl;

    std::cout << isValidWalk({'n', 's', 'n', 'n'}) << std::endl;
    tribonacci(std::vector<int>{1, 2, 3}, 0);
    revRot("123456779", 3);
    std::cout << "\n";
    for (auto &i : uniqueInOrder(std::vector<int32_t>{1, 1, 2, 3, 4}))
    {
        std::cout << "n " << i << "\n";
    }

    uint32_t num = 2154959208;
    std::string chainBits{};
    std::cout << "\n";
    while (num > 0)
    {
        
        chainBits +=std::to_string( num% 2);
        num /= 2;
    }
    std::reverse(std::begin(chainBits), std::end(chainBits));
   
    std::cout <<chainBits <<"\n"  ;
    std::cout << "\n";

    return 0;
}
bool solution(std::string const &str, std::string const &ending)
{
    return str.size() < ending.size() ? false : (str.substr(str.size() - ending.size()).compare(ending) == 0 ? true : false);
}
int square_sum(const std::vector<int> &numbers)
{
    return [numbers, sum = 0]() mutable {
        for (auto &i : numbers)
            sum += std::pow(i, 2);
        return sum;
    }();
}

void miniMaxSum(std::vector<long> arr)
{
    std::sort(arr.begin(), arr.end());
    int num1{};
    long long num2{};
    std::cout << num1 << " " << std::accumulate(arr.begin(), arr.end(), 0) << "\n";
    int32_t total = 0;
    long int test = 2093989309789;
    std::cout << test << "\n";
}

int count_sheep(std::vector<bool> arr)
{
    return [arr, count = 0]() mutable {
        for (int i : arr)
            i ? count++ : 0;
        return count;
    }();
}

bool betterThanAverage(std::vector<int> classPoints, int yourPoints)
{
    long points{std::accumulate(classPoints.begin(), classPoints.end(), 0)};

    return (points / classPoints.size()) > yourPoints;
}

std::string DNAStrand(const std::string &dna)
{
    std::string res;
    for (auto &i : dna)
        res += letter(i);
    return res;
}

bool isValidWalk(std::vector<char> walk)
{
    if (walk.size() > 10 and walk.size() < 10)
        return false;
    int sum = 0;
    for (auto &i : walk)
    {
        sum += i == 'n' or i == 'w' ? 1 : -1;
    }
    std::cout << "suma direccion " << sum << "\n";
    return sum == 0;
}
std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    //if(n == 0) return std::vector<int>{};
    if (size_t t = sizeof signature; t > n)
    {
        signature.resize(n);
        return signature;
    }

    for (size_t i = signature.size(); i < n; i++)
    {
        signature.push_back(signature[i - 3] + signature[i - 2] + signature[i - 1]);
    }
    return signature;
}

std::string revRot(const std::string &strng, unsigned int sz)
{
    if ((sz <= 0) || sz > strng.length())
        return "";

    std::string t{strng};
    t.resize(sz * (strng.length() / sz));
    for (int i = 0; i < t.length(); i += sz)
    {
        std::string val{t.substr(i, sz)};

        int32_t sum = 0;

        std::for_each(val.begin(), val.end(), [&](auto n) {
            sum += static_cast<int32_t>(std::pow(n - 48, 2));
        });

        if (sum % 2 == 0)
            std::reverse(std::begin(val), std::end(val));
        else
            std::rotate(val.begin(), val.begin() + 1, val.end());

        t.erase(i, sz);
        t.insert(i, val);
    }
    return t;
}

std::vector<char> uniqueInOrder(const std::string &iterable)
{
    //unique_copy
    if (sizeof(iterable) == 0)
    {
        return std::vector<char>{};
    }
    std::vector<char> res{iterable.front()};
    for (auto &i : iterable)
    {
        if (i != res.back())
        {
            res.emplace_back(i);
        }
    }
    return res;
}

template <typename T>
std::vector<T> uniqueInOrder(const std::vector<T> &iterable)
{
    if (sizeof(iterable) == 0)
    {
        return std::vector<T>{};
    }
    std::vector<T> res{iterable.begin(), iterable.end()};
    for (int32_t i = 1; i < res.size(); ++i)
    {
        if (res[i - 1] == res[i])
        {
            res.erase(res.begin() + i);
        }
    }
    return res;
}

std::string uint32_to_ip(uint32_t ip)
{
    
    return "";
}

