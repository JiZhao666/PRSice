// This file is part of PRSice-2, copyright (C) 2016-2019
// Shing Wan Choi, Paul F. O’Reilly
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.


#ifndef PRSICE_INC_STORAGE_HPP_
#define PRSICE_INC_STORAGE_HPP_
#include <cstdint>
#include <memory>
#include <string>
// From http://stackoverflow.com/a/12927952/1441789

struct PRS
{
    double prs;
    size_t num_snp;
    PRS() : prs(0.0), num_snp(0) {}
};

struct Sample_ID
{
    std::string FID;
    std::string IID;
    std::string pheno;
    bool founder;
    Sample_ID(const std::string& F, const std::string& I, const std::string& P,
              const bool& Founder)
        : FID(F), IID(I), pheno(P), founder(Founder)
    {
    }
    Sample_ID() : FID(""), IID(""), pheno(""), founder(false) {}
};

struct MAF_Store
{
    double maf;
    size_t index;
    int category;
};
// Passkey idiom, allow safer access to
// the raw pointer info in SNP
template <typename T>
class Passkey
{
private:
    friend T;
    Passkey() {}
    Passkey(const Passkey&) {}
    Passkey& operator=(const Passkey&) = delete;
};

template <typename e>
struct enumeration_traits;

struct enumeration_trait_indexing
{
    static constexpr bool does_index = true;
};

template <typename e>
constexpr typename std::enable_if<enumeration_traits<e>::does_index,
                                  typename std::underlying_type<e>::type>::type
operator+(e val)
{
    return static_cast<typename std::underlying_type<e>::type>(val);
}

template <typename e>
typename std::enable_if<enumeration_traits<e>::does_index, e&>::type
operator++(e& val)
{
    return val = static_cast<e>(+val + 1);
}
// END

enum class BIM
{
    CHR,
    RS,
    CM,
    BP,
    A1,
    A2
};
enum class BASE_INDEX
{
    CHR,
    REF,
    ALT,
    STAT,
    RS,
    BP,
    SE,
    P,
    INFO,
    MAF,
    MAF_CASE,
    MAX
};
enum class FAM
{
    FID,
    IID,
    FATHER,
    MOTHER,
    SEX,
    PHENOTYPE
};
enum class GTF
{
    CHR,
    SOURCE,
    FEATURE,
    START,
    END,
    SCORE,
    STRAND,
    FRAME,
    ATTRIBUTE
};

enum class BED
{
    CHR,
    START,
    END,
    NAME,
    SCORE,
    STRAND
};
enum class MODEL
{
    ADDITIVE,
    DOMINANT,
    RECESSIVE,
    HETEROZYGOUS
};

enum class MISSING_SCORE
{
    MEAN_IMPUTE,
    SET_ZERO,
    CENTER
};

enum class SCORING
{
    AVERAGE,
    STANDARDIZE,
    SUM
};
template <>
struct enumeration_traits<BASE_INDEX> : enumeration_trait_indexing
{
};
template <>
struct enumeration_traits<GTF> : enumeration_trait_indexing
{
};
template <>
struct enumeration_traits<MODEL> : enumeration_trait_indexing
{
};
template <>
struct enumeration_traits<FAM> : enumeration_trait_indexing
{
};
template <>
struct enumeration_traits<BIM> : enumeration_trait_indexing
{
};
template <>
struct enumeration_traits<BED> : enumeration_trait_indexing
{
};
#endif /* PRSICE_INC_STORAGE_HPP_ */
