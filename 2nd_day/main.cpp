#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    vector<string> final_res;

    ifstream file("input.txt");

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string words;
        vector<string> result;
         bool game_flag = true;

        // Split the line by ':'
        while (getline(ss, words, ':')) {
            result.emplace_back(words);
        }
        
        // Ensure we have at least two parts
        if (result.size() > 1) {
            string right_side = result[1];
            cout << right_side << endl;

            stringstream second_ss(right_side);
            string sub_words;

            // Split the right side by ','
            while (getline(second_ss, sub_words, ';')) {
                stringstream third_ss(sub_words);
                string wo;
                int blue=0,red=0,green=0, val=0;
                // Split the sub-words by ';'
                while (getline(third_ss, wo, ',')) {
                    final_res.emplace_back(wo);
                    
                    
                    // Output the final results
                    for (const string& word : final_res) {
                        int i=3;
                        val= (int)word[1] -48 ;
                        if((int)word[2]>47 && (int)word[2]<58){
                            val = val*10 + ((int)word[2] -48);
                            i++;

                        }
                        

                        switch(word[i]) {
                            case 'b':
                                blue = val;
                                break;
                            case 'r':
                                red = val;
                                break;
                            case 'g':
                                green = val;
                                break;
                            default:
                                break;
                        }
                    


                    }
                    
                }
                cout<< "total_ blue: "<< blue<<" total_green: "<< green<<" total_red "<< red <<endl;
                if(red>12 || green>13 || blue>14){
                    game_flag = false;
                }    
                final_res.clear();
            }


            if(game_flag){
                cout  <<result[0] << " is valid."<<endl;
                
            }
        
            result.clear();

            
            

                 
        }
        


    
    }
    file.close();
    return 0;
}
