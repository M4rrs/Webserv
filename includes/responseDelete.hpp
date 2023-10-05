/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   responseDelete.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:06:00 by nnorazma          #+#    #+#             */
/*   Updated: 2023/10/02 18:57:26 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "headers.hpp"
#include "responseBase.hpp"

class ResponseDelete : public ResponseBase {
	private:
		ResponseDelete( void );

		std::ifstream _file;
		std::string _filePath;

	public:
		ResponseDelete( std::string filePath, ServerConfig portinfo );
		~ResponseDelete( void );

		void clearResources( void );
		bool validateResource( const std::string &name );
		void deleteData( void );
		void setStatusCodeDelete( int status, bool isUpload );
		void generateResponse( void );
};