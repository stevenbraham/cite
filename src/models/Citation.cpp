#include "Citation.h"

namespace Cite::Models
{
    // Getters
    const std::string &Citation::getName() const
    {
        return name;
    }

    const std::string &Citation::getTitle() const
    {
        return title;
    }

    const std::vector<std::string> &Citation::getAuthors() const
    {
        return authors;
    }

    int Citation::getYear() const
    {
        return year;
    }

    const std::string &Citation::getPublisher() const
    {
        return publisher;
    }

    const std::string &Citation::getPlaceOfPublication() const
    {
        return place_of_publication;
    }

    CitationType Citation::getType() const
    {
        return type;
    }

    const std::optional<std::string> &Citation::getPages() const
    {
        return pages;
    }

    const std::optional<std::string> &Citation::getJournalName() const
    {
        return journal_name;
    }

    const std::optional<std::string> &Citation::getVolume() const
    {
        return volume;
    }

    const std::optional<std::string> &Citation::getIssue() const
    {
        return issue;
    }

    const std::vector<std::string> &Citation::getEditorNames() const
    {
        return editor_names;
    }

    const std::optional<std::string> &Citation::getDissertationType() const
    {
        return dissertation_type;
    }

    // Setters
    void Citation::setName(const std::string &value)
    {
        name = value;
    }

    void Citation::setTitle(const std::string &value)
    {
        title = value;
    }

    void Citation::setAuthors(const std::vector<std::string> &value)
    {
        authors = value;
    }

    void Citation::setYear(int value)
    {
        year = value;
    }

    void Citation::setPublisher(const std::string &value)
    {
        publisher = value;
    }

    void Citation::setPlaceOfPublication(const std::string &value)
    {
        place_of_publication = value;
    }

    void Citation::setType(CitationType value)
    {
        type = value;
    }

    void Citation::setPages(const std::optional<std::string> &value)
    {
        pages = value;
    }

    void Citation::setJournalName(const std::optional<std::string> &value)
    {
        journal_name = value;
    }

    void Citation::setVolume(const std::optional<std::string> &value)
    {
        volume = value;
    }

    void Citation::setIssue(const std::optional<std::string> &value)
    {
        issue = value;
    }

    void Citation::setEditorNames(const std::vector<std::string> &value)
    {
        editor_names = value;
    }

    void Citation::setDissertationType(const std::optional<std::string> &value)
    {
        dissertation_type = value;
    }
}