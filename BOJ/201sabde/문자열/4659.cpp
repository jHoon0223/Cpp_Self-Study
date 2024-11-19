#include <iostream>
#include <string>

using namespace std;

char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

// case1
bool check_include_vowel(string s) {
  for(int i = 0; i < s.size(); i++) {
    for(int j = 0; j < 5; j++) {
      bool found = s[i] == vowels[j];
      if (found) {
        return true;
      }
    }
  }

  return false;
}

// case2
bool check_conti_three_letters(string s) {
  int v_count = 0; // the number of consecutive vowels
  int c_count = 0; // the number of consecutive consonants

  for(int i = 0; i < s.size(); i++) {
    bool exist = false;
    for(int j = 0; j < 5; j++) {
      exist = (s[i] == vowels[j]);
      if(exist) {
        v_count += 1;
        c_count = 0;
        break;
      } 
    }

    // not exist vowel
    if(!exist) {
      v_count = 0;
      c_count += 1;
    }

    // terminate condition
    if(v_count >= 3 || c_count >= 3) {
      return false;
    }
  }

  return true;
}

// case3
bool check_conti_two_letters(string s) {
  char prev_letter = s[0];

  for(int i = 1; i < s.size(); i++) {

    // terminate condition
    if(prev_letter == s[i] && prev_letter != 'e' && prev_letter != 'o') {
      return false;
    }

    prev_letter = s[i];
  }

  return true;
}

void print_result(bool total_condition, string s) {
  if (total_condition) cout << "<" << s << "> is acceptable.\n";
  else cout << "<" << s << "> is not acceptable.\n";
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    string s;

    while(true) {
        cin >> s;
        
        if(s.compare("end") == 0) break;

        bool case1 = check_include_vowel(s);  
        bool case2 = check_conti_three_letters(s);  
        bool case3 = check_conti_two_letters(s);

        bool total_cond = case1 && case2 && case3;
        print_result(total_cond, s);
    }

  return 0;
}
