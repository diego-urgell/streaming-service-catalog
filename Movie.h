/**
 * This class represents a Movie, which is associated with a single video. It is a subclass of the CatalogElement
 * abstract class. It implements all of the pure virtual methods from the super class.
 */
class Movie: public CatalogElement{
private:
    Video *v;

public:

    Movie(){}

    Movie(int id, string name, int length, string genre){
        this -> v = new Video(id, name, length, genre);
    }

    int getVidCount(){
        return 1;
    }

    int getLength(){
        return v ->getLength();
    }

    int getId(){
        return v->getId();
    }

    int getRating(){
        return v->getRating();
    }

    void addRating(int rating){
        v-> addRating(rating);
    }

    string getName(){
        return v -> getName();
    }

    string getGenre(){
        return v -> getGenre();
    }

    /**
     * Method used to display the information of the associated video.
     */
    void displayElement(){
        v -> displayVideo();
        cout << endl;
    }

    /**
     * Method used to display the information of the movie, without any conditions.
     */
    void displayMovie(){
        this -> displayElement();
    }

    /**
     * Method used to display the information of the movie, only if it has a particular rating.
     * @param rating int
     */
    void displayElement(int rating){
        if (v -> getRating() == rating) {
            this -> displayElement();
        }
    }

    /**
     * Method used to display the information of the movie, only if it is of a particular genre.
     * @param genre int
     */
    void displayElement(string genre){
        if (v -> getGenre().compare(genre) == 0){
            this ->displayElement();
        }
    }

    /**
     * Method used to add a rating to the movie, given the name of the video and the rating.
     * @param rating int
     * @param name string
     * @return bool indicating if the video of the movie has that particular name.
     */
    bool rateVideo(int rating, string name){
        if(v -> getName().compare(name) == 0) {
            v->addRating(rating);
            return true;
        }
    }

};