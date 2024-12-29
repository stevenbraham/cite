// for some reason, the slugify.hpp doenst work if included directly so this wrapper is needed
#include "../../external/cpp-slugify/slugify.hpp"

namespace Cite
{

    /**
     * Converts a string to a slug.
     */
    std::string toSlug(std::string text)
    {
        auto slug = slugify(text);

        // convert to lowercase and replace spaces with hyphens

        std::transform(slug.begin(), slug.end(), slug.begin(), [](unsigned char c)
                       { return std::tolower(c); });

        std::replace(slug.begin(), slug.end(), ' ', '-');

        return slug;
    }
}