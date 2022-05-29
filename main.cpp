#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "playlist.hpp"

int main()
{
    my::Song song_1{"Ov sirun sirun", 1900, "national", 1800};
    my::Musician musician_1{"Sting", 1970};
    std::cout << song_1;
    std::cout << musician_1;
}