#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include <memory>

namespace my
{
    class Song
    {
    public:
        Song() = default;
        Song(const std::string& name, int year, 
            const std::string& owner, size_t duration);
        Song(const Song &);
        Song(Song &&);
        ~Song() = default;

    public:
        Song &operator=(const Song &);
        Song &operator=(Song &&);
        void set_name(const std::string &);
        std::string get_name() const;
        void set_year(int);
        int get_year() const;
        void set_owner(const std::string &owner);
        std::string get_owner() const;
        void set_duration(size_t duration);
        size_t get_duration() const;
        friend std::ostream &operator<<(std::ostream &, const Song &);

    private:
        std::string _name = "name is undefined";
        int _year = 0;
        std::string _owner = "owner is undefined";
        size_t _duration = 0;
    };

    class Musician
    {
    public:
        Musician() = default;
        Musician(const std::string& name, const std::string& surname, 
            const std::string& country, int year);
        Musician(const std::string& name, int year);
        Musician(const Musician &) = delete;
        Musician(Musician &&) = delete;
        ~Musician() = default;

    public:
        Musician& operator=(const Musician&);
        Musician& operator=(Musician &&);
        void set_name(const std::string &name);
        std::string get_name() const;
        void set_surname(const std::string &surname);
        std::string get_surname() const;
        void set_country(const std::string &country);
        std::string get_country() const;
        void set_born_year(int year);
        int get_born_year() const;
        void set_songs(const std::vector<std::unique_ptr<my::Song>> &);
        const std::vector<std::unique_ptr<my::Song>> &get_songs() const;
        friend std::ostream &operator<<(std::ostream &, const Musician &);

    private:
        std::string _name = "name is undefined";
        std::string _surname = "surname is undefined";
        std::string _country = "country is undefined";
        int _born_year = 0;
        std::vector<std::unique_ptr<my::Song>> _songs;
    };

    class Storage
    {
    public:
        Storage() = default;
        Storage(const my::Storage&);
        Storage(my::Storage&&);
        ~Storage() = default;
    public:
        Storage& operator=(const my::Storage&);
        Storage& operator=(my::Storage&&);
        const my::Song& search_song(const std::string& name) const;
        const my::Musician& search_musician(const std::string& name) const;


    private:
        std::vector<my::Song> _songs;
        std::vector<my::Musician> _musicians;
    };

    Song NIL_song;
    Musician NIL_musician;
    Storage cloud;
    Storage favorite;
};

#endif // PLAYLIST_H