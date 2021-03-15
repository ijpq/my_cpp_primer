/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/ 

#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include "strVec.h"
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
// #include "QueryResult.h"


/* this version of the query classes includes two
 * members not covered in the book:  
 *   cleanup_str: which removes punctuation and 
 *                converst all text to lowercase
 *   display_map: a debugging routine that will print the contents
 *                of the lookup mape
*/

class QueryResult; // declaration needed for return type in the query function


class TextQuery {
public:
	// using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const; 
    void display_map();        // debugging aid: print the map
private:
    std::shared_ptr<strVec> file; // input file
    // maps each word to the set of the lines in which that word appears
    std::map<std::string, 
	         std::shared_ptr<std::set<size_t>>> wm;  

	// canonicalizes text: removes punctuation and makes everything lower case
    static std::string cleanup_str(const std::string&);
};

class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	// typedef std::vector<std::string>::size_type line_no;
	typedef std::set<size_t>::const_iterator line_it;
	QueryResult(std::string s, 
	            std::shared_ptr<std::set<size_t>> p, 
	            std::shared_ptr<strVec> f):
		sought(s), lines(p), file(f) { }
	std::set<size_t>::size_type size() const  { return lines->size(); }
	line_it begin() const { return lines->cbegin(); }
	line_it end() const   { return lines->cend(); }
	std::shared_ptr<strVec> get_file() { return file; }
private:
	std::string sought;  // word this query represents
	std::shared_ptr<std::set<size_t>> lines; // lines it's on
	std::shared_ptr<strVec> file;  //input file
};

std::ostream &print(std::ostream&, const QueryResult&);
#endif
