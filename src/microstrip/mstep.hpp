/***************************************************************************
                               mstep.hpp
                             ------------------
    begin                : Thu Oct 25 2018
    copyright            : (C) 2018 by Thomas Lepoix
    email                : thomas.lepoix@protonmail.ch
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#pragma once

#include "element.hpp"

//******************************************************************************
class Mstep final : public Element {
private :
	static std::string const m_descriptor;
	long double const m_w1;
	long double const m_w2;
	std::string m_net1;
	std::string m_net2;

	// first : element, second : element's port
	std::pair<std::shared_ptr<Element>, int> adjacent1;
	std::pair<std::shared_ptr<Element>, int> adjacent2;
public :
	Mstep(std::string const _label,
			std::string const _type,
			bool const _active,
			bool const _mirrorx,
			short const _r,
			std::string const _subst,
			long double const _w1,
			long double const _w2);
	~Mstep()=default;
	std::string getDescriptor() const override;
	long double getW1() const override;
	long double getW2() const override;
	std::string getNet1() const override;
	std::string getNet2() const override;
	void getEdge(int const _net, long double& edge, short& dir) const override;
	int getOemsNcorelines() const override;
	int getOemsMeshCore(int const _n, OemsLine& line) const override;
	int setAdjacent(int const _port, std::shared_ptr<Element> const& element, int const adjacent_port) override;
	int setNet1(std::string const _net1) override;
	int setNet2(std::string const _net2) override;
};
