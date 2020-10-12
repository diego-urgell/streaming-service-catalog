#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

#include "Video.h"
#include "CatalogElement.h"
#include "Movie.h"
#include "Episode.h"
#include "Series.h"
#include "Catalog.h"
#include "StreamingSystem.h"

int main() {
    StreamingSystem menu;
    menu.runMenu();
}