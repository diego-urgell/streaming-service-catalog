/**
 * This class is a Catalog of CatalogElements, which can be either a movie or a series. This class brings together both
 * type of elements, and it implements actions such as adding a new series or movie, deleting an element, display all the
 * elements or apply conditions, rate videos, or get the ID of the next element to be added to the catalog.
 */
class Catalog {
private:
    vector<CatalogElement*> elements; // This vector contains all the movies and series
    int nextVidIndex;
    int catalogElementsCount;

public:
    Catalog() {
        nextVidIndex = 1;
        catalogElementsCount = 0;
    }

    /**
     * This method adds a new element to the catalog, and increases the total count of elements.
     * @param e The CatalogElement object to be added.
     */
    void addCatalogElement(CatalogElement* e) {
        elements.push_back(e);
        catalogElementsCount++;
    }

    /**
     * This method adds a new video to an episode given its index in the vector.
     * @param index int - the index of the series in the vector
     * @param video_id int - the ID of the videdo to be added
     * @param video_length int - the length of the video
     * @param name string - the name of the episode
     * @param season int - the season of the episode
     * @param genre string - the genre
     */
    void addEpisodeToSeries(int index, int video_id, int video_length, string name, int season, string genre){
        elements[index] -> addEpisode(video_id, video_length, name, season, genre);
    }

    /**
     * This method returns the index of an element given its name. It can be either a movie or a series. It performs a
     * sequential search until the element is found.
     * @param name string with the name of the element
     * @return int with the index of the element
     */
    int findElement(string name){
        int index = 0;
        bool flag = false;
        for(CatalogElement * e: elements){
            if (e ->getName().compare(name) == 0) {
                flag = true;
                break;
            }
            index++;
        }
        if (!flag){
            return -1;
        }
        return index;
    }

    /**
     * Delete a catalog element given its name
     * @param name The name of the element
     */
    void deleteCatalogElement(const string name) {
        int index = findElement(name);
        if (index == -1){
            cout << "There's not an element with that title" << endl;
            return;
        }
        int elimVids = elements[index]->getVidCount();
        elements.erase(elements.begin() + index);
        nextVidIndex -= elimVids;
        catalogElementsCount--;
    }

    /**
     * This method gives the next available index to be assigned to a new video.
     * @return int with the index
     */
    int nextIndex(){
        return this -> nextVidIndex++;
    }

    /**
     * This method displays all the elements in the catalog, regardless of their kind.
     */
    void displayElements() {
        for(CatalogElement * e: elements){
            e -> displayElement();
            cout << endl;
        }
    }

    /**
     * This method displays only the movies in the catalog.
     */
    void displayMovies(){
        for(CatalogElement * e: elements){
            e -> displayMovie(); //For series, the method doesn't do anything because it is not implemented
            cout << endl;
        }
    }

    /**
     * To display only the series in the catalog.
     */
    void displaySeries(){
        for(CatalogElement * e: elements){
            e -> displaySeries();
            cout << endl;
        }
    }

    /**
     * To display the information of a specific title given its name
     * @param name string
     */
    void displaySpecificElement(string name){
        int index = findElement(name);
        if (index == -1){
            cout << "There's not an element with that title" << endl;
            return;
        }
        elements[index]->displayElement();
    }

    /**
     * Display only the elements that have a certain average rating.
     * @param rating int
     */
    void dispByRating(int rating){
        for(CatalogElement * e: elements){
            e ->displayElement(rating);
        }
        cout << endl;
    }

    /**
     * Display the videos that have a particular genre.
     * @param genre
     */
    void dispByGenre(string genre){
        for(CatalogElement * e: elements){
            e ->displayElement(genre);
        }
        cout << endl;
    }

    /**
     * To add a rating to a new video given its name and the rating to be added.
     * @param name string
     * @param rating int
     * @return
     */
    bool rateVideo(string name, int rating){
        for(CatalogElement * e: elements){
            if(e -> rateVideo(rating, name)) {
                return true;
                break;
            }
        }
        return false;
    }

    /**
     * Overriding the << operator to print the total elements in catalog.
     */
    friend ostream& operator <<(ostream& os, const Catalog * c) {
        os << "Total elements in catalog: " << c->nextVidIndex-1;
        return os;
    }
};