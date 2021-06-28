// Copyright 2011-2020, Molecular Matters GmbH <office@molecular-matters.com>
// See LICENSE.txt for licensing details (2-clause BSD License: https://opensource.org/licenses/BSD-2-Clause)

#pragma once

#include <string>

PSD_NAMESPACE_BEGIN

/// \ingroup Types
/// \class PascalString
/// \brief A struct storing photoshop's deefined pascal string
struct PascalString
{
public:
	uint8_t length;
	std::string content;
};

/// \ingroup Types
/// \class UnicodeString
/// \brief A struct storing photoshop's defined unicode string
struct UnicodeString
{
public:
	uint32_t length;
	std::wstring content;
};

PSD_NAMESPACE_END
