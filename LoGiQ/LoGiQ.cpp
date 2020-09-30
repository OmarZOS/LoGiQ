#include"LoGiQ.h"





//----------TextNode------------------------------------

TextNode::TextNode (std::string s,Color col,int size,Vector2f position){
	if(!font.loadFromFile("OpenSans-Regular.ttf"))
	{
	}
	text.setString(s);
	text.setFillColor(col);
	text.setFont(font);
	text.setCharacterSize(size);
	text.setPosition(position);
}
		TextNode::~TextNode(){}
void TextNode::Render(RenderWindow& wendy){
	if(!hidden)
	wendy.draw(text);
}

void TextNode::setposition(float a,float b){
	text.setPosition(a,b);
}


//----------ENTITY---------------------------------------
Entity::Entity(): _position(0.f,0.f) {}
 Entity::~Entity() {}
//----------PLAYER---------------------------------------

Player::Player(int x) : Entity() {
	

switch(x){
	case 0 :_Texture.loadFromFile("red.png");
			name=new TextNode("Red",Color::Red,20,_position);
			score=new TextNode("0",Color::Red,20,_position);

			break;
	case 1 :_Texture.loadFromFile("yellow.png");
			name=new TextNode("Yellow",Color::Yellow,20,_position);
			score=new TextNode("0",Color::Yellow,20,_position);
			break;
	case 2 :_Texture.loadFromFile("green.png");
			name=new TextNode("Green",Color::Green,20,_position);
			score=new TextNode("0",Color::Green,20,_position);

			break;
	case 3 :_Texture.loadFromFile("blue.png");
			name=new TextNode("Blue",Color::Blue,20,_position);
			score=new TextNode("0",Color::Blue,20,_position);

			break;
}
	
	name->hidden=false;
	score->hidden=false;
	
_spricht.setOrigin(Vector2f(340/2.f,425/2.f));
	
	_spricht.setTexture(_Texture);
	if(x<2)
		_spricht.setScale(-0.1f,0.1f);
	else
		_spricht.setScale(0.1f,0.1f);
		
	_spricht.setPosition(_position);
}
void Player::Render(RenderWindow &wendy){
	wendy.draw(_spricht);
	if(name!=NULL)
		name->Render(wendy);
	if(score!=NULL)
		score->Render(wendy);
}

bool Player::isOutRange(){
	return _spricht.getPosition().x>Sizex||_spricht.getPosition().x<0||_spricht.getPosition().y>Sizey||_spricht.getPosition().y<0;
}


 Player::~Player() {}

//----------BACKGROUND---------------------------------------

BackGround::BackGround(){
if (!_Texture.loadFromFile("Back2.jpg"))
	{
			// Handle loading error
	}
	_spricht.setScale(Vector2f(2.f,1.5f));
	_spricht.setTexture(_Texture);
	_spricht.setPosition(_position);
}
void BackGround::Render(RenderWindow &wendy){
	wendy.draw(_spricht);
}

BackGround::~BackGround(){}

//----------ARROW-------------------------------------------

Arrow::Arrow(int a,int b) : Entity() {
	
	switch(b){
		case 0 :_Texture.loadFromFile("Ari1.png");
				break;
		case 1 :_Texture.loadFromFile("Ari2.png");
				break;
		case 2 :_Texture.loadFromFile("Ari3.png");
				break;
		case 3 :_Texture.loadFromFile("Ari4.png");
				break;
		case 4 :_Texture.loadFromFile("Ari5.png");
				break;
		case 5 :_Texture.loadFromFile("Ari6.png");
				break;
		case 6 :_Texture.loadFromFile("Ari7.png");
				break;
		case 7 :_Texture.loadFromFile("Ari8.png");
				break;
		case 8 :_Texture.loadFromFile("Ari9.png");
				break;
		case 9 :_Texture.loadFromFile("Ari10.png");
				break;
		case 10:_Texture.loadFromFile("Ari11.png");
				break;
		case 11:_Texture.loadFromFile("Ari12.png");
				break;
		case 12:_Texture.loadFromFile("Ari13.png");
				break;
				
		default : std::cout<<"Error: not supported Colorset number\n"	;
			//I should have handled something here 		
	}
	
	_position.x=Sizex/2;
	_position.y=Sizey/2;
	_spricht.setScale(0.05f,0.05f);
	_spricht.setOrigin(338/2.f,256/2.f);
	_spricht.setRotation(-90.f+a*90.f);   //
	_spricht.setTexture(_Texture);
	_spricht.setPosition(_position);
}

void Arrow::Render(RenderWindow &wendy){
	wendy.draw(_spricht);
}

Arrow::~Arrow() {}
//--------CHART-------------------------------------------------

Chart::Chart(){
	trigon.setPointCount(3);
}
Chart::~Chart(){}

void Chart::Render(RenderWindow& wendy){
	wendy.draw(trigon);
}


//---------ROUND----------------------------------------------

Round::Round(){

	for(int i=0;i<4;i++)
		player[i]=new Player(i);
		
		
		
//positionning Players..
	player[0]->_spricht.setPosition(Sizex/2.f,Sizey/4.f+TURNY);
	player[0]->name->setposition(Sizex/2.f-25,Sizey/4.f+TURNY-50);
	player[0]->score->setposition(Sizex/2,Sizey/4.f+TURNY-65);

	player[1]->_spricht.setPosition(Sizex*3.f/4.f-TURNY,Sizey/2.f);
	player[1]->name->setposition(Sizex*3.f/4.f-TURNY-35,Sizey/2.f-50);
	player[1]->score->setposition(Sizex*3.f/4.f-TURNY-35,Sizey/2.f-65);

	player[2]->_spricht.setPosition(Sizex/2.f,Sizey*3.f/4.f-TURNY);
	player[2]->name->setposition(Sizex/2.f-30,Sizey*3.f/4.f-TURNY-45);
	player[2]->score->setposition(Sizex/2.f,Sizey*3.f/4.f-TURNY-60);

	player[3]->_spricht.setPosition(Sizex/4.f+TURNY,Sizey/2.f);
	player[3]->name->setposition(Sizex/4.f+TURNY-20,Sizey/2.f-50);
	player[3]->score->setposition(Sizex/4.f+TURNY-20,Sizey/2.f-65);

	
	//for(int i=0;i<4;i++)
	//	zone[i].trigon.setPoint(0,Vector2f(Sizex/2,Sizey/2));
	zone[0].trigon.setPoint(0,Vector2f(Sizex/2,Sizey/2-TURNY));
	zone[1].trigon.setPoint(0,Vector2f(Sizex/2+TURNY,Sizey/2));
	zone[2].trigon.setPoint(0,Vector2f(Sizex/2,Sizey/2+TURNY));
	zone[3].trigon.setPoint(0,Vector2f(Sizex/2-TURNY,Sizey/2));
/*
	zone[0].trigon.setPoint(0,Vector2f(0.f,Sizey/4));
	zone[1].trigon.setPoint(0,Vector2f(-Sizex/4,0.f));
	zone[2].trigon.setPoint(0,Vector2f(Sizex/2,Sizey/2+TURNY));
	zone[3].trigon.setPoint(0,Vector2f(Sizex/2-TURNY,Sizey/2));

*/
	//setting borders
	
	zone[0].trigon.setPoint(1,Vector2f(Sizex/4.f,Sizey/4.f));
	zone[0].trigon.setPoint(2,Vector2f(Sizex*3.f/4.f,Sizey/4.f));
	zone[1].trigon.setPoint(1,Vector2f(Sizex*3.f/4.f,Sizey/4.f));
	zone[1].trigon.setPoint(2,Vector2f(Sizex*3.f/4.f,Sizey*3.f/4.f));
	zone[2].trigon.setPoint(1,Vector2f(Sizex*3.f/4.f,Sizey*3.f/4.f));
	zone[2].trigon.setPoint(2,Vector2f(Sizex/4.f,Sizey*3.f/4.f));
	zone[3].trigon.setPoint(1,Vector2f(Sizex/4.f,Sizey*3.f/4.f));
	zone[3].trigon.setPoint(2,Vector2f(Sizex/4.f,Sizey/4.f));


	


	
	// setting Origins..
	zone[0].trigon.setOrigin(Sizex/2.f,Sizey/4.f-TURNY);
	zone[1].trigon.setOrigin(Sizex/4.f+TURNY,Sizey/2.f);	
	zone[2].trigon.setOrigin(Sizex/2.f,Sizey/4.f+TURNY);
	zone[3].trigon.setOrigin(Sizex/4.f-TURNY,Sizey/2.f);
/*
	*/	
	zone[0].trigon.setPosition(Sizex/2.f,Sizey/4.f-TURNY);
	zone[1].trigon.setPosition(Sizex/4.f+TURNY,Sizey/2.f);
	zone[2].trigon.setPosition(Sizex/2.f,Sizey/4.f+TURNY);
	zone[3].trigon.setPosition(Sizex/4.f-TURNY,Sizey/2.f);



//AnimatedPlayer=player[0];

	
	//First player's beacon
	beacon = new CircleShape(TURNY);
	beacon->setOrigin(Vector2f(TURNY,TURNY));
	beacon->setPosition(Vector2f(Sizex/2.f,Sizey/2.f));
	beacon->setFillColor(playcol[currentPlayer]);
	//beacon->setRadius(TURNY);
	
	ColorCharts();	//first coloration
	
}

Round::~Round(){}

void Round::Render(RenderWindow& wendy){
	if(beacon!=NULL)
		wendy.draw(*beacon);
	for(int i=0;i<4;i++){
		zone[i].Render(wendy);
		if(alive[i])
			player[i]->Render(wendy);
	}
	if(Ari!=NULL)
		Ari->Render(wendy);
	if(Ejectedplayer!=NULL)
		Ejectedplayer->Render(wendy);
}

void Round::InitShot(){
	shots=MAXSHOTS;
	DivertArrow();
}

void Round::ColorCharts(){
	for(int i=0;i<4;i++){
		col[i]=rand()%ColorSet;
		for(int j=0;j<i;j++)
		{
			if(col[i]==col[j])
			{
				i--;
				break;
			}
		}
	}
	
	//Now for the player's turn //beacon..
	beacon->setFillColor(playcol[currentPlayer]);

	//Here you should set colors for each round of the game..
	
	for(int i=0;i<4;i++)
		zone[i].trigon.setFillColor(cols[col[i]]);
}

void Round::DivertArrow(){
	clk.restart();
	shots--;
	int dir=rand()%4;	//choose a direction.. 0 up .. 1 right...etc..
	int mr_randy=rand()%4;	//random constraint and divert
	
	correct=(dir+mr_randy)%4;		//To be honest, I never thought it would be this simple
	Ari=new Arrow(dir,col[mr_randy]);
	anim=true;
}

bool Round::Treat(int answer,bool& play){	//if the arrows are depleted.. we should set play at false..
	
	int tmp=correct; // problems heppened during tests..
	Ari->~Arrow();
	Ari=NULL;
	if(shots>=0)//if there are any shots left..
		DivertArrow();
	else{
		play=false;// pause current game for the moment..
		//here you should display what has happened
		
		DepletedShots();
	}
	
	score[currentPlayer]+=(answer==tmp)?1/clk.getElapsedTime().asSeconds():0;
	
	player[currentPlayer]->score->text.setString((std::to_string)(score[currentPlayer]));
	//The time to answer counts here too..
	//Later for the sound it will be changed..
	return (answer==tmp);
}

void Round::DepletedShots(){
	count--;
	++currentPlayer%=4;
		if(count<=0)
			Kill_Player(minim());
	while(!alive[(currentPlayer)])
		++currentPlayer%=4;
	
	//AnimatedPlayer=Player[currentPlayer];
	ColorCharts();
}
void Round::Kill_Player(int i){
	count=--n;
	dead=true;	//there's a dead body to be noticed by the game..
	Ejectedplayer=player[i];
	Ejection=true;
	
	alive[i]=false;	// player[i] is the dead guy.. not to be given shots again..
	if(Ari!=NULL){
		Ari->~Arrow();
		Ari=NULL;	
	}
	
	while(!alive[currentPlayer])	//if there had been a suicide.. 
		++currentPlayer%=4;
//	AnimatedPlayer=Player[currentPlayer];
	
}
int Round::minim(){
	float x;
	int ind,i;
	for(int i=0;i<4;i++){	// I had to pass by this to get the
		if(alive[i])
			x=score[i];
			ind=i;
			break;
		}
	for(int i=0;i<4;i++)
		if(x>score[i]&&alive[i]){
			x=score[i];
			ind =i;
		}
	return ind;
}

//-------GAME----------------------------------------------

Game::Game() : mWindow(VideoMode(Sizex, Sizey), "LoGiQ") {

	hint = new TextNode("[Space]:Start/Suicide, use arrow keys to answer\ndepending on the displayed arrow color, follow if it has the upper color\nInvert if it has the same color as the color in the down side,\n tilt right or left if it has the same color as the side chart",Color::Red,30,Vector2f(5.f,5.f));
	instructs=new TextNode("[H]:Hints\t[R]:Restart\t[Escape]:Exit",Color::White,30,Vector2f(5.f,5.f));
	instructs->hidden=false;
	
	if(!bgmusic.openFromFile("Background_Music.ogg")){
	}
	if(!Victory.openFromFile("Victory.ogg")){
	}
	if(!buff1.loadFromFile("Correct.ogg")){}
	if(!buff2.loadFromFile("Wrong.ogg")){}
	if(!buff3.loadFromFile("Ejection.ogg")){}
	corr.setBuffer(buff1);
	wrong.setBuffer(buff2);
	ejec.setBuffer(buff3);
	corr.setVolume(50);
	wrong.setVolume(50);
	ejec.setVolume(100);

	
	Victory.setVolume(50);
	bgmusic.setVolume(50);
	bgmusic.play();
	bgmusic.setLoop(true);
	
}
void Game::run()
{
	Clock clock;
	Time timeSinceLastUpdate = Time::Zero;
	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame){
			
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			
			update(TimePerFrame,round.anim);
			
			
		}
		render();
	}
}

void Game::processEvents()
{
	Event event;
	while (mWindow.pollEvent(event))
	{
		if(endgame){
			Victory.play();
			endgame=false;
		}
			
			switch (event.type){
				case Event::Closed:
						mWindow.close();
						break;
				case Event::KeyPressed:
						handlePlayerInput(event.key.code);
						break;

				
				default :; //something else;
			}
	}
}

void Game::handlePlayerInput(Keyboard::Key key) {


	if(Keyboard::H == key){ 
		instructs->hidden=(instructs->hidden)?false:true;
		hint->hidden=(hint->hidden)?false:true;
	}
	if(Keyboard::Escape == key){ 
		mWindow.close();
	}
	
	
	if(play){	

		switch (key){
			case Keyboard::Space :
				KillCurrentPlayer();
				ejec.play();
				round.ColorCharts();
				if(round.n<2){
					endgame=true;
				}
					break; 
			case Keyboard::Up :
				(round.Treat(0,play))?corr.play():wrong.play();
					break;
			case Keyboard::Right :
			(round.Treat(1,play))?corr.play():wrong.play();
					break;
			case Keyboard::Down :
			(round.Treat(2,play))?corr.play():wrong.play();
					break;
			case Keyboard::Left :
			(round.Treat(3,play))?corr.play():wrong.play();
					break;
			case Keyboard::H :
				instructs->hidden!=instructs->hidden;
				hint->hidden!=hint->hidden;
			default :;
		}
		if(round.dead){
			play=false;
			ejec.play();
			round.dead=false;	//fulfilling some unfinished tasks.. U know..
			round.ColorCharts();
				if(round.n<2){
					endgame=true;
			}
		}
		
		
	}
	else{		// The player has chosen to surrender.. how sad could that be..
		if(key==Keyboard::Space)			
			InitRound();
	}

}

void Game::update(Time deltaTime,bool& anim)
{
	if(anim){
		if(round.Ari!=NULL){
		//float k=(spawn)?0.5:-0.5;
		round.Ari->_spricht.setScale(round.Ari->_spricht.getScale()+ Vector2f(1.f,1.f)*0.5f*deltaTime.asSeconds());
		if(round.Ari->_spricht.getScale().y>0.5f)
			anim=false;
		}
		else
			anim=false;
	}
	if(round.Ejection){
		if(round.Ejectedplayer!=NULL){
				round.Ejectedplayer->_spricht.setPosition(round.Ejectedplayer->_spricht.getPosition()-(Vector2f(Sizex/2.f,Sizey/2.f)-round.Ejectedplayer->_spricht.getPosition())*EjectSpeed*deltaTime.asSeconds());
					round.Ejectedplayer->_spricht.setRotation(round.Ejectedplayer->_spricht.getRotation()+deltaTime.asSeconds()*EjectSpeed*300.f);
		
			if(round.Ejectedplayer->isOutRange()){
				round.Ejection=false;
				round.Ejectedplayer=NULL;
			}
			
		}
		else{
			round.Ejection=false;	
		}
	}

	
	//animating zones now..
		round.zone[0].trigon.setScale(round.zone[0].trigon.getScale()+Vector2f(0.05f,0.05f)*(((round.grow)?1:-1)*deltaTime.asSeconds()));
		round.zone[1].trigon.setScale(round.zone[1].trigon.getScale()+Vector2f(0.05f,0.05f)*(((round.grow)?1:-1)*deltaTime.asSeconds()));
		round.zone[2].trigon.setScale(round.zone[2].trigon.getScale()+Vector2f(0.05f,0.05f)*(((round.grow)?1:-1)*deltaTime.asSeconds()));	
		round.zone[3].trigon.setScale(round.zone[3].trigon.getScale()+Vector2f(0.05f,0.05f)*(((round.grow)?1:-1)*deltaTime.asSeconds()));	
	
	if(round.zone[0].trigon.getScale().x>1.025f)
		round.grow=false;
	if(round.zone[0].trigon.getScale().x<0.975f)
		round.grow=true;
	
}
void Game::render(){	//Here is where all the visual magic starts..
	mWindow.clear();
	bground.Render(mWindow);	
	round.Render(mWindow);
	if(hint!=NULL)
		hint->Render(mWindow);
	if(instructs!=NULL)
		instructs->Render(mWindow);
	mWindow.display();
}

void Game::KillCurrentPlayer(){
	//Somebody's gonna die right here right now..
	play=false;
	round.Kill_Player(round.currentPlayer);	
	round.dead=false;// No worries, he was executed properly..
	
	
	//ColorCharts();
}

void Game::InitRound(){
	play = true;
	round.InitShot();
}
