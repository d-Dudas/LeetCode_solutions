// Accepted!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// This time, instead of veryfing if a recipe is possible
// just take the list of a supplies and remove the items from there
// also from the ingredients - just think like all we have is not necessary anymore

class Solution {
    public:
        Solution(){}
        ~Solution(){}

    void removeSupplyFromIngredientList(
        string& supply,
        vector<string>& recipeIngredients)
    {
        auto recipeIngredients_it = find(recipeIngredients.begin(), recipeIngredients.end(), supply);
        if(recipeIngredients_it != recipeIngredients.end())
        {
            recipeIngredients.erase(recipeIngredients_it);
        }
    }

    void checkIfRecipePossible(
        vector<string>& recipes,
        vector<vector<string>>& ingredients,
        vector<string>& supplies,
        vector<string>& possibleRecipes,
        int& recipeIngredientsPoz)
    {
        if(ingredients[recipeIngredientsPoz].size() == 0)
        {
            possibleRecipes.push_back(recipes[recipeIngredientsPoz]);
            supplies.push_back(recipes[recipeIngredientsPoz]);
            recipes.erase(recipes.begin() + recipeIngredientsPoz);
            ingredients.erase(ingredients.begin() + recipeIngredientsPoz);
            recipeIngredientsPoz--;
        }
    }

    vector<string> findAllRecipes(
        vector<string>& recipes,
        vector<vector<string>>& ingredients,
        vector<string>& supplies)
    {

        vector<string> possibleRecipes;

        for(int supplyPoz = 0; supplyPoz < supplies.size(); supplyPoz++)
        {
            for(int recipeIngredientsPoz = 0; recipeIngredientsPoz < ingredients.size(); recipeIngredientsPoz++)
            {
                removeSupplyFromIngredientList(supplies[supplyPoz], ingredients[recipeIngredientsPoz]);
                checkIfRecipePossible(recipes, ingredients, supplies, possibleRecipes, recipeIngredientsPoz);
            }
        }

        return possibleRecipes;
    }
};

int main()
{
    vector<string> recipes = {"bread","sandwich","burger"};
    vector<vector<string>> ingredients = {{"yeast","flour"},{"bread","meat"},{"sandwich","meat","bread"}};
    vector<string> supplies = {"yeast","flour","meat"};
    Solution solution = Solution();

    vector<string> output = solution.findAllRecipes(recipes, ingredients, supplies);
    vector<string> expected = {"bread","sandwich","burger"};

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