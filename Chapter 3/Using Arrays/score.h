
Class GameEntry;

class Score {
public:
	Score(int maxEnt = 10);
	~Score();

	void add(const GameEntry& e);
	GameEntry remove(int i) throw(indexOutOfBounds);

private:
	int maxEntries;
	int numEntries;
	GameEntry* entries;
}