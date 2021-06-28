// Copyright 2011-2020, Molecular Matters GmbH <office@molecular-matters.com>
// See LICENSE.txt for licensing details (2-clause BSD License: https://opensource.org/licenses/BSD-2-Clause)

#include "PsdPch.h"
#include "PsdSyncFileUtil.h"


PSD_NAMESPACE_BEGIN

namespace fileUtil
{
	// ---------------------------------------------------------------------------------------------------------------------
	// ---------------------------------------------------------------------------------------------------------------------
	std::string ReadStringFromFile(SyncFileReader& reader, uint32_t count)
	{
		std::string buffer(count, '\0');
		reader.Read(&buffer[0], count);
		return buffer;
	}


	// ---------------------------------------------------------------------------------------------------------------------
	// ---------------------------------------------------------------------------------------------------------------------
	std::string ReadStringFromFileBE(SyncFileReader& reader, uint32_t count)
	{
		return ReadStringFromFile(reader, count);
	}

}

PSD_NAMESPACE_END