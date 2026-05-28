#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        //My OG Shit Solution, it works but this would cause you to get kicked out
        // string res;
        // int thousands = num/1000;
        // for(int i = 0; i < thousands; i++){
        //     res += nums[1000];
        // }
        // num -= thousands * 1000;
        // int hundos = (num / 100);
        // num -= hundos * 100;
        // int tens = num / 10;
        // num -= tens * 10;
        // int singles = num;
        
        
        // if(hundos == 4){
        //     res += "CD";
        // }
        // else if (hundos == 9){
        //     res += "CM";
        // }
        // else{
        //     if(hundos >= 5){
        //         res += "D";
        //         hundos -= 5;
        // }
        // for(int i = 0; i < hundos; i++){
        //     res += nums[100];
        // }
        // }

        // if(tens == 4){
        //     res += "XL";
        // }
        // else if (tens == 9){
        //     res += "XC";
        // }
        // else{
        //     if(tens >= 5){
        //         res += "L";
        //         tens -= 5;
        //     }
        // for(int i = 0; i < tens; i++){
        //     res += nums[10];
        // }
        // }

        //         if(singles == 4){
        //     res += "IV";
        // }
        // else if (singles == 9){
        //     res += "IX";
        // }
        // else{
        //     if(singles >= 5){
        //         res += "V";
        //         singles -= 5;
        //     }
        // for(int i = 0; i < singles; i++){
        //     res += nums[1];
        // }
        // }
        // return res;

        const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string res = "";

        for(int i = 0; i < 13; i++){
            while(num >= values[i]) {
                res += symbols[i];
                num -= values[i];
            }
        }
        return res;
    }
};
// @lc code=end

