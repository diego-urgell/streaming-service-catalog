/**
 * This class contains a catalog of elements of a streaming service. It is the user interface (although it is not graphical).
 */
class StreamingSystem {

private:
    Catalog catalog;
    const int EXIT = 14;

    /**
     * Method used to display the menu with the different actions that the user is able to perform with the application.
     */
    void displayOptions() {
        cout << "\n\n";
        cout << "Please choose an option to continue" << endl;
        cout << "1. Create a movie" << endl;
        cout << "2. Create a series" << endl;
        cout << "3. Add episodes to a series" << endl;
        cout << "4. Display all elements" << endl;
        cout << "5. Display all movies" << endl;
        cout << "6. Display all series" << endl;
        cout << "7. Display episodes of series" << endl;
        cout << "8. Filter videos by rating" << endl;
        cout << "9. Filter videos by genre" << endl;
        cout << "10. Rate a video" << endl;
        cout << "11. Delete a movie or series" << endl;
        cout << "12. Load saved catalog" << endl;
        cout << "13. Save the current catalog" << endl;
        cout << EXIT <<  ". Exit" << endl;
    }

    /**
     * Auxiliary method that calls the method to be executed depending on the action that the user selected.
     * @param action - int representing the integer from the menu that the user selected.
     */
    void performAction(int action) {
        switch(action) {
            case 1:
                createMovie();
                break;
            case 2:
                createSeries();
                break;
            case 3:
                addEpisodeToSeries();
                break;
            case 4:
                catalog.displayElements();
                break;
            case 5:
                catalog.displayMovies();
                break;
            case 6:
                catalog.displaySeries();
                break;
            case 7:
                dispEpisodesOfSeries();
                break;
            case 8:
                filterVideosByRating();
                break;
            case 9:
                filterVideosByGenre();
                break;
            case 10:
                rateVideo();
                break;
            case 11:
                deleteElement();
                break;
            case 12:
                break;
            case 13:
                break;
            default:
                break;
        }
    }

    /**
     * Method used to ask the user to select an option from a menu.
     * @return the number of the option the user selected
     */
    int selectOption() {
        int option;
        string tmp;
        do {
            cout << "Select an option: ";
            cin >> option;
            getline(cin, tmp);
        } while (option < 1 || option > EXIT);

        return option;
    }

    /**
     * Method used to create a new movie by providing the necessary information.
     */
    void createMovie(){
        cout << "Please type the following information" << endl;
        string title, genre, tmp;
        int length, n;
        cout << "Title: ";
        getline(cin, title);
        cout << "Length: ";
        cin >> length;
        getline(cin, tmp);
        cout << "Genre: ";
        getline(cin, genre);
        n = this -> catalog.nextIndex();
        Movie * m = new Movie(n, title, length, genre);
        catalog.addCatalogElement(m);
        cout << "The movie was successfully added" << endl;
    }

    /**
     * Method used to create a series. First, the information of the series is specified. Then, the number of initial chapters
     * is set and the information for each individual chapter is provided.
     */
    void createSeries(){
        string name, tmp, genre;
        int initEp, length, season, n;
        Series * s;
        Episode * e;
        cout << "Please type the following information" << endl;
        cout << "Name of the series: ";
        getline(cin, name);
        s = new Series(name);

        cout << "How many initial episodes will you store? ";
        cin >> initEp;
        getline(cin, tmp);
        cout << "\n";
        for(int i = 0; i < initEp; i++ ){
            cout << "Name of the episode " << i + 1<<": ";
            getline(cin, name);
            cout << "Genre: ";
            getline(cin, genre);
            cout << "Length: ";
            cin >> length;
            cout << "Season: " ;
            cin >> season;
            getline(cin, tmp);
            n = catalog.nextIndex();
            s->addEpisode(n, length, name, season, genre);
            cout << "\n";
        }
        catalog.addCatalogElement(s);
        cout << "The series was succesfully added" << endl;
    }

    /**
     * Method to add an episode to a series, by specifying first the name of the series and then providing the
     * information for chapter to be added.
     */
    void addEpisodeToSeries(){
        string name, genre, tmp;
        int n, season, length;
        cout << "Please type the following information" << endl;
        cout << "Name of the series: " << endl;
        getline(cin, name);

        // Validating the name
        int index = catalog.findElement(name);
        if (index == -1){
            cout << "There's not an element with that title" << endl;
            return;
        }

        // Creating the episode
        cout << "Name of the chapter: ";
        getline(cin, name);
        cout << "Genre: ";
        getline(cin, genre);
        cout << "Length: ";
        cin >> length;
        cout << "Season: " ;
        cin >> season;
        getline(cin, tmp);
        n = catalog.nextIndex();
        catalog.addEpisodeToSeries(index, n, length, name, season, genre);
        cout << "The episode was successfully added" << endl;
    }

    /**
     * Used to display all the episodes that belong to the same series.
     */
    void dispEpisodesOfSeries(){
        string name;
        cout << "Please type the following information";
        cout << "Name of the series: ";
        getline(cin, name);
        catalog.displaySpecificElement(name);
    }

    /**
     * Used to display only the videos which have a particular rating, specified by the user.
     */
    void filterVideosByRating(){
        int rating;
        string tmp;
        cout << "Desired rating: ";
        cin >> rating;
        getline(cin, tmp);
        catalog.dispByRating(rating);
    }

    /**
     * Used to display all the videos of a particular genre, given an input from the user.
     */
    void filterVideosByGenre(){
        string tmp, genre;
        cout << "Desired rating: ";
        getline(cin, genre);
        catalog.dispByGenre(genre);
    }

    /**
     * This method manages the addition of a new rating to the general rating of a video, which can be either a
     * movie or an episode from a series.
     */
    void rateVideo(){
        string name, tmp;
        int rating;
        cout << "Name of the video: ";
        getline(cin, name);
        cout << "Rating: ";
        cin >> rating;
        getline(cin, tmp);

        if(catalog.rateVideo(name, rating)) cout << "The video was succesfully rated" << endl;
        else cout << "There is not a video with that tittle" << endl;
    }

    /**
     * This method deletes a series or movie from the catalog given its name, It can't delete individual episodes from a
     * series.
     */
    void deleteElement(){
        string name;
        cout << "Name of the series or movie: " ;
        getline(cin, name);
        catalog.deleteCatalogElement(name);
    }

public:

    /**
     * In the constructor, a new Catalog object is created, to store the catalog elements.
     */
    StreamingSystem(){
        this -> catalog = Catalog();
    }

    /**
     * This method displays the menu of available actions, waits for the user to select one of them, and then calls
     * a method that execute the appropriate action.
     */
    void runMenu() {
        int option;
        do {
            displayOptions();
            option = selectOption();
            cout << "\n\n";
            performAction(option);
        } while (option != EXIT);
    }
};