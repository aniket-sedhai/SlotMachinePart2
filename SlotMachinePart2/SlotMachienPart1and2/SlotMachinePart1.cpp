//
//  main.cpp
//  SlotMachine
//
//  Created by Aniket Sedhai on 7/4/24.
//

#include <iostream>
#include <vector>
#include <map>

int main(void) {
    std::vector<int> Left_Reel { 1, 1, 3, 4, 5, 2, 2, 3, 4, 2, 2, 5, 3, 5, 3, 4, 2, 1, 2, 5, 4, 3, 2 };
    
    std::vector<int> Center_Reel { 3, 1, 2, 2, 3, 5, 4, 4, 2, 2, 3, 2, 1, 5, 4, 3, 3, 2, 1, 5, 4, 1, 3, 5 };
    
    std::vector<int> Right_Reel { 2, 3, 5, 4, 4, 3, 1, 1, 2, 2, 3, 5, 4, 3, 2, 1, 2, 1, 5, 1, 3, 4, 1, 5, 2 };
    
    std::map<int, int> combination_payout = { {111, 2}, {222, 7}, {333, 10}, {331, 2}, {332, 2}, {334, 3}, {335, 4}, {444, 15}, {441, 5}, {442, 5}, {443, 2}, {445, 6}, {123, 2}, {551, 2}, {555, 70}};
    
    int num_of_spins = 0;
    int win_payout = 0;
    
    for (int left_spin: Left_Reel)
    {
        for (int center_spin: Center_Reel)
        {
            for (int right_spin: Right_Reel)
            {
                int combination_value = left_spin*100 + center_spin*10 + right_spin;
                win_payout += combination_payout[combination_value];
                ++num_of_spins;
            }
        }
    }
    
    std::cout << "Payout percentage for the above reels and combination: " << static_cast<double>(win_payout)/static_cast<double>(num_of_spins)*100 << "%" << std::endl;
    
    return 0;
}
