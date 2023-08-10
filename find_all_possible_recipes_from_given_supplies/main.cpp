#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        Solution(){}
        ~Solution(){}

    bool isRecipePossible(vector<string>& ingredients, vector<string>& supplies)
    {
        for(auto& ingredient : ingredients)
        {
            if(find(supplies.begin(), supplies.end(), ingredient) == supplies.end())
            {
                return false;
            }
        }
        return true;
    }

    vector<string> findAllRecipes(
        vector<string>& recipes,
        vector<vector<string>>& ingredients,
        vector<string>& supplies)
    {
        vector<string> output;
        bool newIngredientFound = true;

        while(newIngredientFound)
        {
            newIngredientFound = false;
            for(int recipePoz = 0; recipePoz < recipes.size(); recipePoz++)
            {
                if(isRecipePossible(ingredients.at(recipePoz), supplies))
                {
                    output.push_back(recipes.at(recipePoz));
                    supplies.push_back(recipes.at(recipePoz));
                    newIngredientFound = true;
                    recipes.erase(recipes.begin() + recipePoz);
                    ingredients.erase(ingredients.begin() + recipePoz--);
                }
            }
        }
        

        return output;
    }
};

int main()
{
    vector<string> recipes = {"bread"};
    vector<vector<string>> ingredients = {{"yeast","flour"}};
    vector<string> supplies = {"yeast"};
    Solution solution = Solution();

    vector<string> output = solution.findAllRecipes(recipes, ingredients, supplies);
    vector<string> expected = {};

    if (output == expected)
    {
        cout << "Correct output\n";
    } else 
    {
        cout << "Wrong output\n";
    }

    if(output.size() > 0)
    {
        for(auto& el : output)
            cout << el << "\n";
    } else {
        cout << "Empty output\n";
    }

    return 0;
}