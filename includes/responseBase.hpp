/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   responseBase.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:37:55 by nnorazma          #+#    #+#             */
/*   Updated: 2023/10/05 15:19:55 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "headers.hpp"

class ResponseBase {
	protected:
		std::string _response, _contentType, _path, _fileName;
		std::size_t _contentLength;
		int _statusCode;
		bool _isImg;
		std::map< std::string, std::string > _contentTypes;
		std::map< int, std::string > _statusCodes;
		ServerConfig _portinfo;

	public:
		ResponseBase( void );
		virtual ~ResponseBase( void );
		virtual void generateResponse( void ) = 0;

		void initStatusCodes( void );
		void initContentTypes( void );
		void setContentType ( std::string type );
		void setStatusCode ( int code );
		
		bool checkPermissions( std::string method );
		
		std::string getResponse( void );
		std::string generateResponseISE( void );
		std::map< std::string, std::string > getContentTypes( void ) const;
		std::map< int, std::string > getStatusCodes( void ) const;


};

std::string decodeEncoding( std::string &input );