class FoodRatings {
public:
    unordered_map<string,string>food_cusine;
    unordered_map<string,set<pair<int,string>>> cusine_ratings_food;
    unordered_map<string,int>food_rating;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0;i<n;i++){
            string food = foods[i];
            string cusine = cuisines[i];
            int rating = ratings[i];
            cusine_ratings_food[cusine].insert({-rating,food});
            food_cusine[food] = cusine;
            food_rating[food] = rating; 
        }
    }
    
    void changeRating(string food, int newRating) {
        string cusine = food_cusine[food];
        int old_rating = food_rating[food];
        food_rating[food] = newRating;
        cusine_ratings_food[cusine].erase({-old_rating,food});
        cusine_ratings_food[cusine].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        return begin(cusine_ratings_food[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */