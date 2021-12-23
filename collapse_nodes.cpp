#include <iostream>
#include <random>
#include <vector>
#include <iterator>
#include <map>
#include <exception>

using namespace std;

struct vec3{
    double x, y, z;
    bool operator==(const vec3& other) const {
        return (x == other.x) && (y == other.y) && (z == other.z);
    }
};

class remove_coincident_points {
    map<int, vec3> m_p; 

public:
    remove_coincident_points(const map<int,vec3> p)
    : m_p(p)
    {
        // sanitize input
        for(const auto point: m_p){
            if(point.first <1)   throw runtime_error("negative indices found");
        }

    }

    int count_coincident_points()  {
        vector<pair<int,int>> duplicates;

        for(const auto& outerpoint: m_p){
            for(const auto& innerpoint: m_p){
                if (outerpoint.first != innerpoint.first && innerpoint.second == outerpoint.second) {
                    duplicates.push_back(make_pair(outerpoint.first, innerpoint.first));
                }
            }
        }
        cout<<"found " << duplicates.size() << " duplicates\n";

        return duplicates.size();
    }

    bool remove_duplicates(){

        return false;
    }
};

auto create_3_points(){
    map<int, vec3> points; 
    points[1] = vec3{0, 0, 0};
    points[2] = vec3{1, 1, 1};
    points[3] = vec3{1, 1, 1};

    return points;
}

void test_remove_coincident_points(){

    auto points = create_3_points();
    remove_coincident_points points_remover(points);
    (points_remover.count_coincident_points() == 2)? cout <<"passed": cout << "failed";

}

int main(){
    test_remove_coincident_points();
}