class GameEntry {

public:
	GameEntry(const string& n = "", int s = 0);
	~GameEntry();
	string getName() const;
	int getScore() const;

private:
	string name;
	int score;
}