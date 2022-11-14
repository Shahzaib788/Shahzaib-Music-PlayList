#include <iostream>
#include "PlaylistNode.h"

PlaylistNode::PlaylistNode(){
   uniqueID = "none";
   songName = "none";
   artistName = "none";
   songLength = 0;
   nextNodePtr = nullptr;
   }

PlaylistNode::PlaylistNode(string SongID, string Tune, string ArtistN, int Length, PlaylistNode* nodeLoc){
   uniqueID = SongID;
   songName = Tune;
   artistName = ArtistN;
   songLength = Length;
   nextNodePtr = nodeLoc;
   }

void PlaylistNode::InsertAfter(PlaylistNode* nodeLoc){
   PlaylistNode* tmpNext;

   tmpNext = nextNodePtr;
   nextNodePtr = nodeLoc;
   nodeLoc->nextNodePtr = tmpNext;

   }

void PlaylistNode::SetNext(PlaylistNode* nodeLoc){

   nextNodePtr = nodeLoc;

   }

string PlaylistNode::PlaylistNode::GetID(){

   return uniqueID;

   }

string PlaylistNode::GetSongName(){

   return songName;

   }

string PlaylistNode::GetArtistName(){

   return artistName;

   }

int PlaylistNode::GetSongLength(){

   return songLength;

   }

PlaylistNode* PlaylistNode::GetNext(){

   return this->nextNodePtr;

   }

void PlaylistNode::PrintPlaylistNode(){

   cout << "Unique ID: " << this->uniqueID << endl;
   cout << "Song Name: " << this->songName << endl;
   cout << "Artist Name: " << this->artistName << endl;
   cout << "Song Length (in seconds): " << this->songLength << endl;

   }
