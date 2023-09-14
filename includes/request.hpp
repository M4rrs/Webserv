/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:37:14 by nnorazma          #+#    #+#             */
/*   Updated: 2023/09/14 19:21:47 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.hpp"
#include "responseGet.hpp"
#include "responsePost.hpp"
#include "responseDelete.hpp"
// #include "responseUnknown.hpp"

class Request {
	private:
		std::string _request;
		std::string _response;
		std::string _method;
		std::string _path;
		std::string _http;
		std::string _body;
		size_t _payloadSize;
		std::map< std::string, std::string > _header;


	public:
		Request( void );
		~Request( void );

		void clearResources( void );
		void parseRequest( void );
		std::string processRequest( std::string req );
		std::map< std::string, std::string > getHeader( void ) const;
		std::string getBody( void ) const;
		size_t getPayload( void ) const;
};