
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;


void check_rank(int rank1, int rank2);
bool straight_flush(string s);
//bool four_of_a_kind(string s);
int find_pair(string s);
int get_biggest_pair(string s);
int get_second_pair(string s);
int get_three_pair(string s);
int forth_number(string s);
int last_number(string s);
int get_single(string s);
int get_biggest_number(string s);
int get_second_number(string s);
int get_smallest(string s);
bool flush(string s);
bool straight(string s);
int high_card(string s);
int second_hand(string s);
int third_hand(string s);
int forth_hand(string s);
int last_hand(string s);


int main() {

  int rank1(0),value1;
  int rank2(0),value2;

  //std::ifstream f("/home/409/Code/PokerHands_in.txt");
  std::string input;
  char a[10000];
  char b[10000];
  int length;
  while (getline(cin, input) && (!input.empty()))
  //for (int h = 0; std::getline(f, input); ++h)
	{

      length = input.length();

  //cin.getline(input,sizeof(input));
  //data.append(input);
  //int length = length(input);

  //cout<<endl;


  // get Black string a
  for (int i = 0; i < length/2; i++)
  {

    if (input[i] == 'T' ) //58
    {
      a[i] = ':';
    }
    else if (input[i] == 'J') //59
    {
      a[i] = ';';
    }
    else if (input[i] == 'Q') //60
    {
      a[i] = '<';
    }
    else if (input[i] == 'K') //61
    {
      a[i] = '=';
    }
    else if (input[i] == 'A') //62
    {
      a[i] = '>';
    }
    else
    {
      a[i] = input[i];
    }

  }


  // get string b

  for (int i = length/2; i < length; i++)
  {
    int j = i - length/2;
    if (input[i+1] == 'T' )
    {
      b[j] = ':';
    }
    else if (input[i+1] == 'J')
    {
      b[j] = ';';
    }
    else if (input[i+1] == 'Q')
    {
      b[j] = '<';
    }
    else if (input[i+1] == 'K')
    {
      b[j] = '=';
    }
    else if (input[i+1] == 'A')
    {
      b[j] = '>';
    }
    else
    {
      b[j] = input[i+1];
    }

  }


  if (straight_flush(a) == true ) //check if a is straight_flush
  {
    rank1 = 0;
    //cout << "a is straight flush" << endl;
  }
  else if (find_pair(a) == 6) // a is four of a pair
  {
    rank1 = 1;
    //cout << "a is four of a pair" << endl;
  }
  else if (find_pair(a) == 4) // a is full house
  {
    rank1 = 2;
    //cout << "a is full house" << endl;
  }
  else if (flush(a) == true) // a is flush
  {
    rank1 = 3;
    //cout << "a is flush" << endl;
  }
  else if (straight(a) == true) // a is striaight
  {
    rank1 = 4;
    //cout << "a is striaight" << endl;
  }
  else if (find_pair(a) == 3) // a is three of a kind
  {
    rank1 = 5;
    //cout << "a is three of a kind" << endl;
  }
  else if (find_pair(a) == 2) // a is two pairs
  {
    rank1 = 6;
    //cout << "a is two pairs" << endl;
  }
  else if (find_pair(a) == 1) // a is pair
  {
    rank1 = 7;
    //cout << "a is pair" << endl;
  }
  else
  {
    rank1 = 8;
    //cout<<"a is high card" << endl;
  }




  if (straight_flush(b) == true ) //check if b is straight_flush
  {
    rank2 = 0;
    //cout << "b is straight flush" << endl;
  }
  else if (find_pair(b) == 6 ) // b is four of a pair
  {
    rank2 = 1;
    //cout << "b is four of a pair" << endl;
  }
  else if (find_pair(b) == 4) // b is full house
  {
    rank2 = 2;
    //cout << "b is full house" << endl;
  }
  else if (flush(b) == true) // b is flush
  {
    rank2 = 3;
    //cout << "b is flush" << endl;
  }
  else if (straight(b) == true) // b is striaight
  {
    rank2 = 4;
    //cout << "b is striaight" << endl;
  }
  else if (find_pair(b) == 3) // b is three of a kind
  {
    rank2 = 5;
    //cout << "b is three of a kind" << endl;
  }
  else if (find_pair(b) == 2) // b is two pairs
  {
    rank2 = 6;
    //cout << "b is two pairs" << endl;
  }
  else if (find_pair(b) == 1) // b is pair
  {
    rank2 = 7;
    //cout << "b is pair" << endl;
  }
  else
  {
    rank2 = 8;
    //cout<< "b is high card" <<endl;
  }


  check_rank(rank1, rank2);

  //both a and b are high card or straight or flush or straight flush
  if (((rank1 == 8)&&(rank2 == 8)) || ((rank1 == 4)&&(rank2 == 4)) || ((rank1 == 3)&&(rank2 == 3)) || ((rank1 == 0)&&(rank2 == 0)))
  {
    int a0,a1,a2,a3,a4;
    int b0,b1,b2,b3,b4;
    if (high_card(a) > high_card(b))
    {
      cout << "Black wins." << endl;
    }
    else if (high_card(a) < high_card(b))
    {
      cout << "White wins." << endl;
    }
    else
    {
      if (second_hand(a) > second_hand(b))
      {
        cout << "Black wins." << endl;
      }
      else if (second_hand(a) < second_hand(b))
      {
        cout << "White wins." << endl;
      }
      else
      {
        if (third_hand(a) > third_hand(b))
        {
          cout << "Black wins." << endl;
        }
        else if (third_hand(a) < third_hand(b))
        {
          cout << "White wins." << endl;
        }
        else
        {
          if (forth_hand(a) > forth_hand(b))
          {
            cout << "Black wins." << endl;
          }
          else if (forth_hand(a) < forth_hand(b))
          {
            cout << "White wins." << endl;
          }
          else
          {
            if (last_hand(a) > last_hand(b))
            {
              cout << "Black wins." << endl;
            }
            else if (last_hand(a) < last_hand(b))
            {
              cout << "White wins." << endl;
            }
            else
            {
              cout << "Tie." << endl;
            }
          }
        }
      }
    }
  }


  //both a and b are pairs
  if ((rank1 == 7)&&(rank2 == 7))
  {
    if (get_biggest_pair(a) > get_biggest_pair(b))
    {
      cout << "Black wins." << endl;
    }
    else if (get_biggest_pair(a) < get_biggest_pair(b))
    {
      cout << "White wins." << endl;
    }
    else
    {
      if (get_biggest_number(a) > get_biggest_number(b))
      {
        cout << "Black wins." << endl;
      }
      else if (get_biggest_number(a) < get_biggest_number(b))
      {
        cout << "White wins." << endl;
      }
      else
      {
        if (get_second_number(a) > get_second_number(b))
        {
          cout << "Black wins." << endl;
        }
        else if (get_second_number(a) < get_second_number(b))
        {
          cout << "White wins." << endl;
        }
        else
        {
          if (get_smallest(a) > get_smallest(b))
          {
            cout << "Black wins." << endl;
          }
          else if (get_smallest(a) < get_smallest(b))
          {
            cout << "White wins." << endl;
          }
          else
          {
            //cout<<get_smallest(a)<<endl;
            //cout<<get_smallest(b)<<endl;
            cout << "Tie." << endl;
          }
        }
      }
    }

  }


  //both a and b are two pairs
  if ((rank1 == 6)&&(rank2 == 6))
  {
    if (get_biggest_pair(a) > get_biggest_pair(b))
    {
      cout << "Black wins." << endl;
    }
    else if (get_biggest_pair(a) < get_biggest_pair(b))
    {
      cout << "White wins." << endl;
    }
    else
    {
      if (get_second_pair(a) > get_second_pair(b))
      {
        cout << "Black wins." << endl;
      }
      else if (get_second_pair(a) < get_second_pair(b))
      {
        cout << "White wins." << endl;
      }
      else
      {
        if (get_single(a) > get_single(b))
        {
          cout << "Black wins." << endl;
        }
        else if (get_single(a) < get_single(b))
        {
          cout << "White wins." << endl;
        }
        else
        {
          cout << "Tie." << endl;
        }
      }
    }
  }


  // both a and b are three of a kind or full house or four of a kind
  if (((rank1 == 5)&&(rank2 == 5)) || ((rank1 == 2)&&(rank2 == 2)) || ((rank1 == 1)&&(rank2 == 1)))
  {
    if (get_three_pair(a) > get_three_pair(b))
    {
      cout << "Black wins." << endl;
    }
    else if (get_three_pair(a) < get_three_pair(b))
    {
      cout << "White wins." << endl;
    }
    else
    {
      if (forth_number(a) > forth_number(b))
      {
        cout << "Black wins." << endl;
      }
      else if (forth_number(a) < forth_number(b))
      {
        cout << "White wins." << endl;
      }
      else
      {
        if (last_number(a) > last_number(b))
        {
          cout << "Black wins." << endl;
        }
        else if (last_number(a) < last_number(b))
        {
          cout << "White wins." << endl;
        }
        else
        {
          cout << "Tie." << endl;
        }
      }
    }
  }




}

  return 0;
}









void check_rank(int rank1, int rank2)
{
  if (rank1 < rank2)
  {
    //cout << rank1 << rank2 << endl;
    cout << "Black wins." << endl;
  }
  else if (rank1 > rank2)
  {
    //cout << rank1 << rank2 << endl;
    cout << "White wins." << endl;
  }


}


bool straight_flush(string s)
{

    if (high_card(s) == second_hand(s) +1)
    {
      if (second_hand(s) == third_hand(s) +1)
      {
        if (third_hand(s) == forth_hand(s) +1)
        {
          if (forth_hand(s) == last_hand(s) +1)
          {
            for (int i = 0; i < s.length()-3; i=i+3)
            {
              if (s[i+1] != s[i+4])
              {
                return false;
              }
            }
            return true;
          }
        }
      }
    }
    return false;
}


int find_pair(string s)
{
  int index = 0;
  for (int i = 0; i < s.length(); i=i+3)
  {
    for (int j = i+3; j < s.length(); j=j+3)
    {
      if (s[i] == s[j])
      {
        index++;
      }
    }
  }
  return index;
}

int get_biggest_pair(string s)
{
  int number = 0;
  int max = 0;
  for (int i = 0; i < s.length(); i=i+3)
  {
    for (int j = i+3; j < s.length(); j=j+3)
    {
      if (s[i] == s[j])
      {
        number = s[i];
        if (max < number)
        {
          max = number;
        }

      }
    }
  }
  return max;
}

int get_second_pair(string s)
{
  int max = get_biggest_pair(s);
  int second_pair = 0;
  for (int i = 0; i < s.length(); i=i+3)
  {
    for (int j = i+3; j < s.length(); j=j+3)
    {
      if ((s[i] == s[j]) && (s[i] < max))
      {
        second_pair = s[i];
      }
    }
  }
  return second_pair;
}

int get_three_pair(string s)
{
  int number = 0;
  for (int i = 0; i < s.length(); i=i+3)
  {
    int index = 0;
    for (int j = i+3; j < s.length(); j=j+3)
    {
      if (s[i] == s[j])
      {
        index++;
      }
      if (index == 2)
      {
        number = s[i];
      }
    }
  }
  return number;
}

int forth_number(string s)
{
  int number = get_three_pair(s);
  int max = 0;
  for (int i = 0; i < s.length(); i=i+3)
  {
    if ((max < s[i]) && (s[i] != number))
    {
      max = s[i];
    }
  }
  return max;
}

int last_number(string s)
{
  int n1 = get_three_pair(s);
  int n2 = forth_number(s);
  int max = 0;
  for (int i = 0; i < s.length(); i=i+3)
  {
    if ((max < s[i]) && (s[i] != n1) && (s[i] != n2))
    {
      max = s[i];
    }
  }
  return max;
}

int get_biggest_number(string s) // get the biggest number expect biggest pair
{
  int pair = get_biggest_pair(s);
  int max = 0;
  for (int i = 0; i < s.length(); i=i+3)
  {
      if ((s[i] != pair) && (max < s[i]))
      {
        max = s[i];
      }
  }
  return max;
}

int get_second_number(string s)
{
  int pair = get_biggest_pair(s);
  int max = get_biggest_number(s);

  int second_max = 0;
  int number = 0;
  for (int i = 0; i < s.length(); i=i+3)
  {
    for (int j = i+3; j < s.length(); j=j+3)
    {
      if ((s[i] != pair) && (s[i] != max))
      {
        number = s[i];
        if (second_max < number)
        {
          second_max = number;
        }
      }
    }
  }
  return second_max;
}

int get_single(string s)
{
  int n1 = get_biggest_pair(s);
  int n2 = get_second_pair(s);
  int single = 0;
  for (int i = 0; i < s.length(); i=i+3)
  {
    if ((s[i] != n1) && (s[i] != n2))
    {
      single = s[i];
    }
  }
  return single;
}


int get_smallest(string s)
{
  int pair = get_biggest_pair(s);
  int n1 = get_second_number(s);
  int n2 = get_biggest_number(s);
  int min = 0;
  for (int i = 0; i < s.length(); i=i+3)
  {
      if ((s[i] != pair) && (s[i] != n1) && (s[i] != n2))
      {
        min = s[i];
      }

  }
  return min;
  //cout<<"min"<<min<<endl;
}


bool flush(string s)
{
  for (int i = 1; i < s.length()-3; i=i+3)
  {
    if (s[i] != s[i+3])
    {
      return false;
    }
  }
  return true;
}

bool straight(string s)
{
    if (high_card(s) == second_hand(s) +1)
    {
      if (second_hand(s) == third_hand(s) +1)
      {
        if (third_hand(s) == forth_hand(s) +1)
        {
          if (forth_hand(s) == last_hand(s) +1)
          {
            return true;
          }
        }
      }
  }
  return false;
}

int high_card(string s)
{
  char max = 0;
  for (int i = 0; i < s.length(); i=i+3)
  {
    if (max < s[i])
    {
      max = s[i];
    }
  }

  return max;
}

int second_hand(string s)
{
  char max = high_card(s);
  char second_max = 0;
  for (int i = 0; i < s.length(); i=i+3)
  {
    if ((second_max < s[i]) && (s[i] != max))
    {
      second_max = s[i];
    }
  }
  return second_max;
}

int third_hand(string s)
{
  char max = high_card(s);
  char second_max = second_hand(s);
  char third_max = 0;
  for (int i = 0; i < s.length(); i=i+3)
  {
    if ((third_max < s[i]) && (s[i] != max) && (s[i] != second_max))
    {
      third_max = s[i];
    }
  }
  return third_max;
}
int forth_hand(string s)
{
  char max = high_card(s);
  char second_max = second_hand(s);
  char third_max = third_hand(s);
  char forth_max = 0;
  for (int i = 0; i < s.length(); i=i+3)
  {
    if ((forth_max < s[i]) && (s[i] != max) && (s[i] != second_max) && (s[i] != third_max))
    {
      forth_max = s[i];
    }
  }
  return forth_max;
}
int last_hand(string s)
{
  char min = 100;
  for (int i = 0; i < s.length(); i=i+3)
  {
    if (min > s[i])
    {
      min = s[i];
    }
  }

  return min;
}
