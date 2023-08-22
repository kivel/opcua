/*************************************************************************\
* Copyright (c) 2018-2020 ITER Organization.
* This module is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution.
\*************************************************************************/

/*
 *  Author: Ralph Lange <ralph.lange@gmx.de>
 *
 *  based on code by Michael Davidsaver <mdavidsaver@ospreydcs.com>
 */

#ifndef DEVOPCUA_LINKPARSER_H
#define DEVOPCUA_LINKPARSER_H

#include <list>

#include <dbCommon.h>

#include "devOpcua.h"
#include "RecordConnector.h"

namespace DevOpcua {

static const char defaultElementDelimiter = '.';
static const std::string defaultLinkDelimiters = "'; \t";

bool getYesNo(const char c);

/**
 * @brief Split configuration string along delimiters into a list<string>.
 *
 * Delimiters at the beginning or end of the string or multiple delimiters in a row
 * generate empty list elements.
 *
 * @param str  string to split
 * @param delim  token delimiter
 *
 * @return  tokens in order of appearance as list<string>
 */
std::list<std::string> splitString(const std::string &str,
                                   const char delim = defaultElementDelimiter);

/**
 * @brief Tokenize string based on set of delimiters.
 *
 * Allows for string literals enclosed in `'` to account for strings containing delimiters.
 * Delimiters at the beginning and end are ignored, multiple subsequent delimiters are treated as single delimiter.
 *
 * @param str  string to split
 * @param delim  token delimiter
 *
 * @return  tokens in order of appearance as vector<string>
 */
std::vector<std::string> tokenize(const std::string &str,
                                  const std::string &delim = defaultLinkDelimiters);


std::unique_ptr<linkInfo> parseLink(dbCommon *prec, const DBEntry &ent);

} // namespace DevOpcua

#endif // DEVOPCUA_LINKPARSER_H
