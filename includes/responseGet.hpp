/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   responseGet.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:06:00 by nnorazma          #+#    #+#             */
/*   Updated: 2023/09/18 15:42:07 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "headers.hpp"
#include "responseBase.hpp"

class ResponseGet : public ResponseBase {
	private:
		ResponseGet( void );
		std::ifstream _file;
		ServerConfig _portinfo;

	public:

		ResponseGet( std::string filePath, ServerConfig portinfo );
		~ResponseGet( void );

		void checkPath( void );
		void setStatusCodeGet( void );
		void generateResponse( void );
};