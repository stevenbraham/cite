#pragma once
#include <string>
#include <optional>
#include <vector>
#include "CitationTypes.h"

namespace Cite::Models
{
    /**
     * Represents a citation.
     */
    class Citation
    {
    private:
        /**
         * Short name of the citation used for referencing.
         * For example, a book citation might have the name "smith2020" if it was published in 2020 by an author named Smith.
         */
        std::string name;

        /**
         * Title of book, article, phd dissertation etc.
         */
        std::string title;

        /**
         * Author(s) of the citation.
         */
        std::vector<std::string> authors;

        /**
         * Year of publication.
         */
        int year;

        /**
         * Publisher of the citation. In case of a dissertation, this is the university.
         */
        std::string publisher;

        std::string place_of_publication;
        CitationType type;

        /**
         * (Optional) Pages of the citation.
         */
        std::optional<std::string> pages;

        // optional citation specific fields

        /**
         * (Optional) Name of the journal. Only applicable for journal citations.
         */
        std::optional<std::string> journal_name;
        /**
         * (Optional) Volume of the journal. Only applicable for journal citations.
         */
        std::optional<std::string> volume;
        /**
         * (Optional) Issue of the journal. Only applicable for journal citations.
         */
        std::optional<std::string> issue;

        /**
         * (Optional) Name of the editor. Only applicable for edited book citations.
         */
        std::vector<std::string> editor_names;

        /**
         * (Optional) Name of the editor. Only applicable for PhD thesis citations.
         */
        std::optional<std::string> dissertation_type;

    public:
        // Getters and Setters

        // Getters
        const std::string &getName() const;
        const std::string &getTitle() const;
        const std::vector<std::string> &getAuthors() const;
        int getYear() const;
        const std::string &getPublisher() const;
        const std::string &getPlaceOfPublication() const;
        CitationType getType() const;
        const std::optional<std::string> &getPages() const;
        const std::optional<std::string> &getJournalName() const;
        const std::optional<std::string> &getVolume() const;
        const std::optional<std::string> &getIssue() const;
        const std::vector<std::string> &getEditorNames() const;
        const std::optional<std::string> &getDissertationType() const;

        // Setters
        void setName(const std::string &value);
        void setTitle(const std::string &value);
        void setAuthors(const std::vector<std::string> &value);
        void setYear(int value);
        void setPublisher(const std::string &value);
        void setPlaceOfPublication(const std::string &value);
        void setType(CitationType value);
        void setPages(const std::optional<std::string> &value);
        void setJournalName(const std::optional<std::string> &value);
        void setVolume(const std::optional<std::string> &value);
        void setIssue(const std::optional<std::string> &value);
        void setEditorNames(const std::vector<std::string> &value);
        void setDissertationType(const std::optional<std::string> &value);
    };
}