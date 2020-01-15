class Solution {
public:
    vector<int> constructRectangle(int area) {
        for(int mid = sqrt(area); mid>0; mid--)
            if (area%mid == 0)
                return {area/mid, mid};
        return {};
    }
};