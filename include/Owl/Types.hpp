/**
 * @brief Defines some useful types thought enumerations
 * 
 * @file Types.hpp
 * @author Pyzyryab 
 * @version 0.1.0
 * @date 2022-01-23
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <ostream>
#include <vector>

namespace Owl {
	namespace Http {
		/**
		 * The supported HTTP request methods by the framework.
		 */
		enum class HttpMethod { GET, POST, PUT, DELETE, PATCH };

		/// Gets the elements of the HttpMethod enum class as a collection in a form of vector<HttpMethod>
		std::vector<HttpMethod> get_methods {
			HttpMethod::GET, HttpMethod::POST, HttpMethod::PUT, HttpMethod::DELETE, HttpMethod::PATCH
		};

		/// Overload the output stream operator for the HttpMethod enum type
		inline std::ostream& operator<<(std::ostream& Str, HttpMethod httpMethod) {
			switch (httpMethod) {
				case HttpMethod::GET: return Str << "GET"; break;
				case HttpMethod::POST: return Str << "POST"; break;
				case HttpMethod::PUT: return Str << "PUT"; break;
				case HttpMethod::DELETE: return Str << "DELETE"; break;
				case HttpMethod::PATCH: return Str << "PATCH"; break;
				default: return Str << "Unitialized attribute or corrupted data."; break;
			};
		}
	}
}