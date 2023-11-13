class Solution {
public:


   bool isVowel(char ch){

    return (ch=='A'||ch=='E' || ch=='I'||ch=='O'||ch=='U' || ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');




   }




    string sortVowels(string s) {
        

       priority_queue<char,vector<char>,greater<char>>pq;

       int m=s.size();

       for(int i=0;i<m;i++){


           if(isVowel(s[i])){
               pq.push(s[i]);
           }



       }
      string res="";

      for(int i=0;i<m;i++){

            if(isVowel(s[i])){
 
                 res+=pq.top();
                 pq.pop();


            }else{

                  res+=s[i];


            }




      }
 





       return res;

    }
};