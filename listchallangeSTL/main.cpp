#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song
{
        friend std::ostream &operator<<(std::ostream &os,const Song &s);
        std::string name;
        std::string artist;
        int rating;
public:
        Song()=default;
        Song(std::string name, std::string artist,int rating):name{name},artist{artist},rating{rating}
        {}
        std::string get_name()const 
        {
            return name;
        }
        std::string get_artist()const
        {
            return artist;
            
        }
        int get_rating()const
        {
            return rating;
        }
        bool operator<(const Song &rhs)const
        {
            return this->name <rhs.name;
        }
        bool operator==(const Song &rhs)const
        {
            return this->name == rhs.name;
        }
            
};

std::ostream &operator<<(std::ostream &os,const Song &s)
{
    os<<std::setw(20)<<std::left<<s.name
      <<std::setw(20)<<std::left<<s.artist
      <<std::setw(20)<<std::left<<s.rating;
      return os;
}

void display_menu()
{
    std::cout<<"\nF - Play First Song" <<std::endl;
    std::cout<<"N - Play Next Song" <<std::endl;
    std::cout<<"P - Play Previous Song" <<std::endl;
    std::cout<<"A - Add and Play a new Song at current location" <<std::endl;
    std::cout<<"L- List the current playlist" <<std::endl;
    std::cout<<"==============================================================" <<std::endl;
    std::cout<<"Enter a selection(Q to Quit): " <<std::endl;
}
void play_current_song(const Song &song)
{
    std::cout<<"Playing "<<std::endl;
    std::cout<<song<<std::endl;
    
}
void display_playlist(std::list<Song> &playlist,const Song &current_song)
{
    for(const Song &song:playlist)
    {
        std::cout<<song<<std::endl;
    }
    
    std::cout<<"Current Song: "<<std::endl;
    std::cout<<current_song<<std::endl;
}

int main(int argc, char **argv)
{
	std::list<Song> playlist{
        {"God's Plan","Drake", 5},
        {"Never Be The Same","Camila Cabello", 5},
        {"Play For Me","The Weekend and K.Laar", 4},
        {"The Middle","Zedd,Maren Morris & Grey",5},
        {"Wait","Marone 5",4},
        {"Whatever It Takes","Imagine Dragons", 3}
    };
    
    std::list<Song>::iterator current_Song = playlist.begin();
    display_playlist(playlist,*current_Song);
    char choice;
    
    bool isplaying = true;
    while(isplaying)
    {
        display_menu();
        std::cin>> choice;
        choice = std::toupper(choice);
        switch(choice)
        {
            case 'F':
            {
                std::list<Song>::iterator First_Song = playlist.begin();
                play_current_song(*First_Song);
            }
            
            break;
            case 'N':
            current_Song++;
                if(current_Song == playlist.end())
                    current_Song=playlist.begin();
                    
                play_current_song(*current_Song);
            break;
            case 'P':
            
            if(current_Song == playlist.begin())
                    current_Song=playlist.end();  
            current_Song--;                  
            play_current_song(*current_Song);
            break;
            case 'A':
            {
                std::string name;
                std::string artist;
                int rating;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"Enter the song name: ";
                getline(std::cin,name);
                
                std::cout<<"Enter the artist name: ";
                getline(std::cin,artist);
                std::cout<<"Enter the rating : ";
                std::cin>>rating;
                playlist.insert(current_Song,Song{name,artist,rating});
                current_Song--;
                play_current_song(*current_Song);
            }
            break;
            case 'L':
                std::cout<<std::endl;
                display_playlist(playlist,*current_Song);
            break;
            case 'Q':
                isplaying = false;
            break;
            default:
            std::cout<<"Invalid choice";
            break;
            
        }
    }
    std::cout<<"thanks for listening"<<std::endl;
	return 0;
}
