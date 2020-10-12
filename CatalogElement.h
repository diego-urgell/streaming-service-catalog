/**
 * An abstract class whose function is to use polymorphism to store both movies and series in a single vector. Almost all of
 * the methods are pure virtual, because they must be implemented differently both in the Movie and Series classes. The ones that
 * are not pure virtual only require an implementation in one of the classes.
 */
class CatalogElement {
public:
    virtual void displayElement() = 0;
    virtual void displayElement(int rating) = 0;
    virtual void displayElement(string genre) = 0;
    virtual string getName() = 0;
    virtual int getVidCount() = 0;
    virtual bool rateVideo(int rating, string name) = 0;
    virtual void displayMovie() {}
    virtual void displaySeries() {}
    virtual void addEpisode(int video_id, int video_length, string name, int season, string genre){}

};
