/**
 * This class stores the information from an individual chapter of a series.
 */
class Episode {
private:
    int season;
    int epNumber;
    Video* v; // Each episode must be associated with a video.

public:
    Episode(){}

    Episode(int video_id, int video_length, string name, int season, string genre, int epNumber){
        this -> season = season;
        this -> v  = new Video(video_id, name, video_length, genre);
        this -> epNumber = epNumber;
    }

    string getName(){
        return v ->getName();
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

    string getGenre(){
        return v -> getGenre();
    }

    /**
     * Method used to display the information of the episode.
     */
    void displayEpisode(){
        cout << "#Episode: " << epNumber << "  Season: " << season << "  ";
        v ->displayVideo();
    }

    /**
     * Method used to rate the video associated with the episode.
     * @param rating int
     */
    void rateVideo(int rating){
        v -> addRating(rating);
    }

};