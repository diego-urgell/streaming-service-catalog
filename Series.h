/**
 * This class represents a Series object, and it keeps a vector of Episode objects.
 */
class Series : public CatalogElement {
private:
    vector<Episode*> episodes;
    int numEpisodes;
    string name;

public:

    Series() {
        numEpisodes = 0;
        name = "";
    }

    Series(string name){
        this -> numEpisodes = 0;
        this -> name = name;
    }

    string getName(){
        return this -> name;
    }

    /**
     * This method adds a new episode to the list of episodes of a series
     * @param video_id int- the id of the video
     * @param video_length int- the length of the video
     * @param name string- name of the video
     * @param season int- season of the episode
     * @param genre string- the genre of the episode.
     */
    void addEpisode(int video_id, int video_length, string name, int season, string genre) {
        Episode * e = new Episode(video_id, video_length, name, season, genre, ++numEpisodes);
        episodes.push_back(e);
    }

    /**
     * This method returns the total length of a series by adding the length of each individual episode
     * @return
     */
    int getLength() {
        int total;
        for(Episode* e: episodes){
            total += e ->getLength();
        }
        return total;
    }

    int getVidCount(){
        return this -> numEpisodes;
    }

    /**
     * Used to display all the episodes in a season in an ordered way.
     */
    void displayElement() {
        cout << "Series Name: " << name << endl;
        for(Episode * e : episodes){
            e -> displayEpisode();
            cout << endl;
        }
    }

    void displaySeries(){
        this -> displayElement();
    }

    /**
     * To display the episodes of a series with a given rating
     * @param rating int
     */
    void displayElement(int rating){
        cout << "Series Name: " << name << endl;
        for(Episode * e: episodes){
            if (e -> getRating() == rating){
                e -> displayEpisode();
            }
        }
    }

    /**
     * To display the elements of a series given a genre
     * @param genre string
     */
    void displayElement(string genre){
        cout << "Series Name: " << name << endl;
        for(Episode * e: episodes){
            if (e -> getGenre().compare(genre) == 0){
                e -> displayEpisode();
            }
        }
    }

    /**
     * Add a new rating to the video of an episode of the series
     * @param rating int
     * @param name string
     * @return True boolean if the operation was succesful
     */
    bool rateVideo(int rating, string name){
        for(Episode * e: episodes){
            if (e -> getName().compare(name) == 0){
                e ->rateVideo(rating);
                return true;
            }
        }
    }
};