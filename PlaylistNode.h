#ifndef PLAYLISTNODEH
#define PLAYLISTNODEH

#include <string>
using namespace std;

class PlaylistNode {
   public:

      PlaylistNode();

      PlaylistNode(string SongID, string Tune, string ArtistN, int Length, PlaylistNode* nodeLoc = nullptr);

      void InsertAfter(PlaylistNode* nodeLoc);

      void SetNext(PlaylistNode* nodeLoc); // Ask Quang

      string GetID();

      string GetSongName();

      string GetArtistName();

      int GetSongLength();

      PlaylistNode* GetNext();

      void PrintPlaylistNode();

   private:
      string uniqueID; // - Initialized to "none" in default constructor
      string songName; // - Initialized to "none" in default constructor
      string artistName; // - Initialized to "none" in default constructor
      int songLength; // - Initialized to 0 in default constructor
      PlaylistNode* nextNodePtr; // - Initialized to 0 in default constructor
   };

#endif
