#include <iostream>
#include <memory>
#include <string>

#include "playlist.hpp"

namespace my
{
    // implementation of Song class

    Song::Song(const std::string &name, int year,
               const std::string &owner, size_t duration)
        : _name{name}, _year{year}, _owner{owner}, _duration{duration}
    {
    }

    Song::Song(const Song &oth)
        : _name{oth._name}, _year{oth._year},
          _owner{oth._owner}, _duration{oth._duration}
    {
    }

    Song::Song(Song&& oth)
        : _name{oth._name}, _year{oth._year},
          _owner{oth._owner}, _duration{oth._duration}
    {
    }

    Song& Song::operator=(const Song& rhs)
    {
        _name = rhs._name;
        _year = rhs._year;
        _owner = rhs._owner;
        _duration = rhs._duration;
        return *this;
    }

    Song& Song::operator=(Song&& rhs)
    {
        _name = rhs._name;
        _year = rhs._year;
        _owner = rhs._owner;
        _duration = rhs._duration;
        return *this;
    }

    void Song::set_name(const std::string& name)
    {
        _name = name;
    }

    std::string Song::get_name() const
    {
        return _name;
    }

    void Song::set_year(int year)
    {
        _year = year;
    }

    int Song::get_year() const
    {
        return _year;
    }

    void Song::set_owner(const std::string& owner)
    {
        _owner = owner;
    }

    std::string Song::get_owner() const
    {
        return _owner;
    }

    void Song::set_duration(size_t duration)
    {
        _duration = duration;
    }

    size_t Song::get_duration() const
    {
        return _duration;
    }

    std::ostream& operator<<(std::ostream& os, const Song& song)
    {
        os << song._name << " " << song._year << " "
            << song._owner << " " << song._duration << " seconds" << std::endl;
        return os;
    }

    // implementation of Musician class

    Musician::Musician(const std::string& name, const std::string& surname,
                const std::string& country, int year)
        : _name{name}, _surname{surname}, _country{country}, _born_year{year}
    {
    }

    Musician::Musician(const std::string& name, int year)
        : _name{name}, _born_year{year}
    {
    }

    Musician::Musician(const Musician& oth)
        : _name{oth._name}, _surname{oth._surname}, 
        _country{oth._country}, _born_year{oth._born_year}
    {
    }

    Musician::Musician(Musician&& oth)
        : _name{oth._name}, _surname{oth._surname}, 
        _country{oth._country}, _born_year{oth._born_year}
    {
    }

    Musician& Musician::operator=(const Musician& rhs)
    {
        _name = rhs._name;
        _surname = rhs._surname;
        _country = rhs._country;
        _born_year = rhs._born_year;
        return *this;
    }

    Musician& Musician::operator=(Musician&& rhs)
    {
        _name = rhs._name;
        _surname = rhs._surname;
        _country = rhs._country;
        _born_year = rhs._born_year;
        return *this;
    }

    void Musician::set_name(const std::string& name)
    {
        _name = name;
    }

    std::string Musician::get_name() const
    {
        return _name;
    }

    void Musician::set_surname(const std::string& surname)
    {
        _surname = surname;
    }

    std::string Musician::get_surname() const
    {
        return _surname;
    }

    void Musician::set_country(const std::string& country)
    {
        _country = country;
    }

    std::string Musician::get_country() const
    {
        return _country;
    }

    void Musician::set_born_year(int year)
    {
        _born_year = year;
    }

    int Musician::get_born_year() const
    {
        return _born_year;
    }

    std::ostream& operator<<(std::ostream& os, const Musician& musician)
    {
        os << musician._name << " " << musician._surname << " "
            << musician._country << " " << musician._born_year << std::endl;
        return os;
    }

    const std::vector<std::unique_ptr<my::Song>>& Musician::get_songs() const
    {
        return _songs;
    }

    // implementation of Storage class

    Storage::Storage(const Storage& oth)
        : _songs{oth._songs}, _musicians{oth._musicians}
    {
    }

    Storage::Storage(Storage&& oth)
        : _songs{oth._songs}, _musicians{oth._musicians}
    {
    }

    Storage& Storage::operator=(const Storage& rhs)
    {
        _songs = rhs._songs;
        _musicians = rhs._musicians;
    }

    Storage& Storage::operator=(Storage&& rhs)
    {
        _songs = rhs._songs;
        _musicians = rhs._musicians;
    }

    const Song& Storage::search_song(const std::string& name) const
    {
        for(int i{}; i < _songs.size(); ++i)
        {
            if(_songs[i].get_name() == name)
            {
                return _songs[i];
            }
        }
        return NIL_song;
    }

    const Musician& Storage::search_musician(const std::string& name) const
    {
        for(int i{}; i < _musicians.size(); ++i)
        {
            if(_musicians[i].get_name() == name)
            {
                return _musicians[i];
            }
        }
        return NIL_musician;
    }

};