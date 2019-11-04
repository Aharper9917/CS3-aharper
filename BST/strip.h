#include <algorithm>
#include <functional>
#include <locale>
#include <string>

std::string strip( const std::string &s ) {
    std::string result;
    result.reserve( s.length() );

    std::remove_copy_if( s.begin(),
                         s.end(),
                         std::back_inserter( result ),
                         std::not1( std::ptr_fun( isalnum ) ) );

    return result;
}