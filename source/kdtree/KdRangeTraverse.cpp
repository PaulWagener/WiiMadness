/*
 * CG Madness - a Marble Madness clone
 * Copyright (C) 2007  Sven Reinck <sreinck@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "KdRangeTraverse.hpp"

#include "functions.hpp"

KdRangeTraverse::KdRangeTraverse(const KdTree& tree, const Vector3& min, const Vector3& max) :
	KdTraverse(tree, min),
	mMin(min),
	mMax(max)
{
	// empty
}

KdRangeTraverse::~KdRangeTraverse()
{
	// empty
}

int KdRangeTraverse::decide(int close, int far)
{
	const KdCell& cellClose = mTree.cell(close);
	const KdCell& cellFar = mTree.cell(far);

	Vector3 n = (cellFar.min - cellClose.min).norm();
	float d = max(n * cellClose.min, n * cellClose.max);

	if (n * mMax >= d)
	{
		mStack.push(far);
	}

	return close;
}
