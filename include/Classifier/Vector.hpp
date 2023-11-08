#ifndef VECTOR_HPP
#define VECTOR_HPP
#include<vector>
#include<cassert>
#include<algorithm>
#include <sstream>
#include <string>

namespace Classifier{

    class Vector{
    private:
        std::vector<double> data;

    public:

        Vector(const Vector& rhs){
            data = std::vector<double>();
            data.reserve(rhs.data.size());
            for (const auto& x : rhs.data){
                data.emplace_back(x);
            }            
        }

        Vector(Vector&& rhs){
            data = std::move(rhs.data);
        }

        Vector& operator=(const Vector& rhs){
            data = std::vector<double>();
            data.reserve(rhs.data.size());
            for (const auto& x : rhs.data){
                data.emplace_back(x);
            }

            return *this;
        }

        Vector& operator=(Vector&& rhs){
            data = std::move(rhs.data);
            return *this;
        }

        template<class... Args>
        Vector(Args&&... args) : data({std::forward<Args>(args)...}){}

        const auto size() const{
            return data.size();
        }

        auto operator[](std::size_t index_i) const{
            return data[index_i];
        }

        auto& operator[](std::size_t index_i) {
            return data[index_i];
        }

        Vector operator-() const{
            Vector v(*this);
            std::for_each(v.data.begin(), v.data.end(), [](auto& x){x*=-1;});
            return v;
        } 

        std::string print() const {
            auto ss = std::stringstream();
            ss << "[";
            for (const auto& val : data){
                ss << val << ',';
            }
            ss << "]";
            return ss.str();
        }

        auto begin() {return data.begin();};
        auto end()   {return data.end();};

        auto begin()  const {return data.begin();};
        auto end()    const {return data.end();};
        auto cbegin() const {return data.cbegin();};
        auto cend()   const {return data.cend();};

    };

    double inline dot(const Vector& lhs, const Vector& rhs){
        assert(lhs.size()==rhs.size() && "Vectors don't have the same size");
        double dot = 0;
        for (std::size_t i = 0; i<lhs.size(); ++i){
            dot += lhs[i] * rhs[i];
        } 
        return dot;
    }

    Vector operator+(const Vector& lhs, const Vector& rhs){
        assert(lhs.size()==rhs.size() && "Vectors don't have the same size");
        Vector v(lhs);
        for (std::size_t i = 0; i<lhs.size(); ++i){
            v[i] += rhs[i];
        } 
        return v;
    }

    Vector operator-(const Vector& lhs, const Vector& rhs){
        assert(lhs.size()==rhs.size() && "Vectors don't have the same size");
        return lhs + (-rhs);
    }

    Vector operator*(const Vector& lhs, const double& rhs){
        Vector v(lhs);
        std::for_each(v.begin(), v.end(), [rhs](auto& x){x*=rhs;});
        return v;
    }

    Vector operator*(const double& lhs, const Vector& rhs){
        return rhs*lhs;
    }
}

#endif /* VECTOR_HPP */