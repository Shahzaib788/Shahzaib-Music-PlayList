#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {

   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit\n" << endl;


}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {

   if(option == 'a'){
   string Song_ID;
   string Song_Name;
   string Artist_Name;
   int Song_Length;
   PlaylistNode* temp;

   cout << "ADD SONG" << endl;
   cout << "Enter song's unique ID:" << endl;
   getline(cin, Song_ID);

   cout << "Enter song's name:" << endl;
   getline(cin, Song_Name);

   cout << "Enter artist's name:" << endl;
   getline(cin, Artist_Name);

   cout << "Enter song's length (in seconds):" << endl;
   cin >> Song_Length;
   cout << endl;
   cin.ignore();

   temp = new PlaylistNode(Song_ID, Song_Name, Artist_Name, Song_Length);
   if(headNode == nullptr){
      headNode = temp;
      }
   else{
      PlaylistNode* temp2 = headNode;

      while(temp2->GetNext() != nullptr){

         temp2 = temp2->GetNext();

      }
      temp2->InsertAfter(temp);
   }
   }
   else if(option == 'd'){
      int i = 1;
      string UserInput;
      PlaylistNode* temp = headNode;
      PlaylistNode* temp2 = headNode;

      cout << "REMOVE SONG\n";
      cout << "Enter song's unique ID:\n";
      getline(cin, UserInput);


      if(temp == nullptr){
         return headNode;
         }
      if(temp->GetID() == UserInput){
         headNode = headNode->GetNext();
         cout << "\""<< temp->GetSongName() << "\""  << " removed." << endl;
         cout << "\n";
         delete temp;
         return headNode;
         }

       while(temp != nullptr){
          if(temp->GetID() == UserInput){
             break;
             }
         ++i;
         temp = temp->GetNext();
          }

          for(int j = 1; j < i -1; ++j){
             temp2 = temp2->GetNext();
            }

         temp2->SetNext(temp->GetNext());
         cout << "\""<< temp->GetSongName() << "\""  << " removed." << endl;
         cout << "\n";
         delete temp;

      }
   else if(option == 'c'){
      int old_pos;
      int new_pos;
      PlaylistNode* o;
      PlaylistNode* x = headNode;
      int a = 0;

      cout << "CHANGE POSITION OF SONG" << endl;
      cout << "Enter song's current position:" << endl;
      cin >> old_pos;


      cout << "Enter new position for song:\n";
      cin >> new_pos;

      if(new_pos < 1){
         new_pos = 1;
         }

      if(old_pos == new_pos){
         return headNode;
         }

      if(old_pos < 1){
         return headNode;
         }

      if(old_pos == 1){ // case 1
         o = headNode;
         headNode = headNode-> GetNext();
         }
      else{
         for(int i = 1; i < old_pos - 1; ++i){
            x = x-> GetNext();
            }
         o = x->GetNext();
         x->SetNext(o->GetNext());
         }
      if(new_pos == 1){
          o->SetNext(headNode);
          headNode = o;
         }
      else{
          x = headNode;
         for(int q = 1; q < new_pos-1; ++q ){

            if(x == nullptr){
               return headNode;
               }

            x = x ->GetNext();

            }
         o->SetNext(x->GetNext());
         x->SetNext(o);
      }
      cout << "\""<< o->GetSongName() << "\""  << " moved to position " << new_pos << endl;
      cout << endl;
   }
   else if(option == 's'){
      PlaylistNode* temp = headNode;
      string User_Input;
      int i = 1;

      cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
      cout << "Enter artist's name:\n\n";
      getline(cin, User_Input);

       while(temp != nullptr){
         if(temp->GetArtistName() == User_Input){
            cout << i <<"." << endl;
             temp -> PrintPlaylistNode();
             cout << endl;
            }
            i++;
            temp = temp->GetNext();
            }


      }
   else if(option == 't'){
      PlaylistNode* temp = headNode;
      int t = 0;

      while(temp != nullptr){
         t = t + temp->GetSongLength();
            temp = temp->GetNext();
            }

      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\n";
      cout << "Total time: " << t << " seconds\n\n";

      }
   else if(option == 'o'){
      int i = 1;
      PlaylistNode* temp = headNode;
      cout << playlistTitle << " - OUTPUT FULL PLAYLIST\n";

      if(temp == nullptr){
         cout << "Playlist is empty\n";
         cout << "\n";
         return headNode;
         }

      while(temp != nullptr){
            cout << i << "." << endl;

            temp -> PrintPlaylistNode();
            cout << endl;
            i++;
            temp = temp->GetNext();
            }
         }



   return headNode;
}



int main() {
  PlaylistNode* headNode;
  string Playlist_Tite;
  char Letter = 'z';

  headNode = nullptr;

  cout << "Enter playlist's title:\n" << endl;
  getline(cin, Playlist_Tite);

   PrintMenu(Playlist_Tite);

  while(Letter != 'q'){
      cout << "Choose an option:\n";
      cin >> Letter;
      cin.ignore();
      if(Letter == 'a' ||Letter == 'd'|| Letter == 'c'|| Letter == 's'|| Letter == 't' || Letter == 'o'){
         headNode = ExecuteMenu(Letter, Playlist_Tite, headNode);
         PrintMenu(Playlist_Tite);
         }
}
 return 0;
}
