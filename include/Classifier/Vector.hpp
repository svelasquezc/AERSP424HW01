#include<vector>
#include<cassert>

namespace Classifier{

    class Vector{
    private:
        std::vector<double> data;

    public:
        template<class... Args>
        Vector(Args... args){
            data = {args...};
        }

        const auto size() const{
            return data.size();
        }

        const auto operator[](std::size_t index_i) const{
            return data[index_i];
        }
        
    };

    double inline dot(const Vector& lhs, const Vector& rhs){
        assert(lhs.size()==rhs.size() && "Vectors don't have the same size");
        double dot = 0;
        for (std::size_t i = 0; i<lhs.size(); ++i){
            dot += lhs[i] * rhs[i];
        } 
        return dot;
    }

}