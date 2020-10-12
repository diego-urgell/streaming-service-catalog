/**
 * This class represents the basic unit in the system, a Video. Every element is related to at least one video.
 */
class Video {
protected:
    int length, id, rating, numberOfVotes;
    string name, genre;


public:

    Video(){}

    Video(int id, string name, int length, string genre){
        this -> id = id;
        this -> name = name;
        this-> genre = genre;
        this -> rating = 0;
        this -> numberOfVotes = 0;
        this -> length = length;
    }

    int getLength() {
        return this -> length;
    }

    int getId(){
        return this -> id;
    }

    int getRating(){
        return this -> rating;
    }

    /**
     * This method adds a rating to the video and calculates the new average. This is possible by keeping the amount of
     * reviews as an attribute and executing a weighted average when adding a new one.
     * @param rating int with the rating
     * @return
     */
    int addRating(int rating){
        double sum = (double) (this -> rating * numberOfVotes + rating);
        this -> rating = round(sum/((double) ++numberOfVotes));
    }

    string getName(){
        return this -> name;
    }

    string getGenre(){
        return this -> genre;
    }

    /**
     * To display the information of the video.
     */
    void displayVideo(){
        cout << "ID: " << id << "  Name: " << name << "  Length: " << length << "  Genre: " << genre << "  Rating: " << rating;
    }

    friend ostream& operator <<(ostream& os, const Video* v) {
        os << v -> id <<  " " << v -> name  << " " << v -> genre << " " << v -> length << " " << v -> rating;
        return os;
    }
};