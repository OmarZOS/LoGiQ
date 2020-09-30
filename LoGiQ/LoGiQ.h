#ifndef LOGIQ_H
#define LOGIQ_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include<time.h>



using namespace sf;

#define MAXSHOTS 6		//how many arrows for each player in a round
#define EjectSpeed 3.5f
#define Sizex 1080		//	Resolution Things.. u know..
#define	Sizey 720		//
#define TURNY 70		//distance 
#define ColorSet 13



class Game;		//Later Homie..
/*
namespace Music{
	enum ID{
		MenuTheme,
		MissionTheme,
	};
}

class MusicPlayer : private sf::NonCopyable
{
	Music	mMusic;
	std::map<Music::ID,std::string>	mFilenames;
	float	mVolume;
public:
	MusicPlayer();
	void play(Music::ID theme);
	void stop();
	void setPaused(bool paused);
	void setVolume(float volume);
};

*/

class TextNode{
		Font font;
	public:
		Text text;
		bool hidden=true;
	friend class Player;
		TextNode(std::string ="",Color = Color::White,int =30,Vector2f = Vector2f(0.f,0.f));
		~TextNode();
		void Render(RenderWindow& wendy);
		void setposition(float a,float b);
};


class Entity{
	public:
		Vector2f _position;
		Texture _Texture;
		Sprite _spricht;
		Entity();
		virtual ~Entity();

};

class Player : public Entity {
		

	public :
		TextNode* name;
		TextNode* score;
		friend class Round;
		void Render(RenderWindow &wendy);
		Player(int x);
		bool isOutRange();
		virtual ~Player();

};

class BackGround: public Entity{

	public:
		BackGround();
		~BackGround();
		void Render(RenderWindow &wendy);

};

class Arrow : public Entity{
	public : 
		Arrow(int =0,int =0);
		virtual ~Arrow();
		void Render(RenderWindow &wendy);
};

class Chart{
	public:
		ConvexShape trigon;
		Chart();
		~Chart();
		void Render(RenderWindow& wendy);
};

class Round{

		Player* player[4];
		Clock clk;
		CircleShape* beacon;
		int col[4]={0,0,0,0};
		Chart zone[4];
		int correct;	//stored to be used immediately by the the event handler
		int shots;		//each round, it is initialised with 
		int n=4;
		int count=4; // rounds till next kill..
		Arrow* Ari=NULL;
		int currentPlayer=0;
		float score[4]={0,0,0,0};
		Color playcol[4]={Color::Red,Color::Yellow,Color::Green,Color::Blue};
		bool grow=true;
		//Pre-defined set of colors, carefull when changing these, you'd have to create a respective .png Arrow
		Color cols[ColorSet]={Color(0,0,0),Color(255,255,255),Color(128,128,128),Color(255,102,178),
		Color(102,255,255),Color(255,128,0),Color(102,0,0),Color(102,102,0),Color(102,0,102),
		Color(25,51,0),Color(51,0,25),Color(102,51,0),Color(102,255,102)};//,Color(,,),Color(,,),
		// I used this to fill triangles
		
		bool alive[4]={true,true,true,true};
		bool dead=false; //state to be verified by the game after someone's loss..
		bool anim=false;//	I used this to animate the arrows
		int dir=0;
		
		Player* Ejectedplayer=NULL;
		bool Ejection=false;
		//Player* AnimatedPlayer=NULL;
		//bool vibrate=true;
		
	public:
		friend class Game;
		Round();
		~Round();
		void Render(RenderWindow& wendy);
		void ColorCharts();
		void DivertArrow();
		void InitShot();
		bool Treat(int answer,bool& play);
		void DepletedShots();
		void Kill_Player(int i);
		int minim();	//minimum player score
};

class Game
{
		RenderWindow mWindow;
		Round round;
		BackGround bground;
		float _speed=200.f;
		Time TimePerFrame= seconds(1.f/60.f);
		bool endgame=false;
		TextNode *hint,*instructs;
		Music bgmusic,Victory;
		SoundBuffer buff1,buff2,buff3;
		Sound corr,ejec,wrong;
		
	public:
		bool play=false;
		Game();
		void run();
		void processEvents();
		void handlePlayerInput(Keyboard::Key key) ;
		void update(Time deltaTime,bool& anim);
		void render();
		void InitRound();
		void KillCurrentPlayer();	//suicide called if clicked space when playing
};

#endif
