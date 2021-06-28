// Copyright 2011-2020, Molecular Matters GmbH <office@molecular-matters.com>
// See LICENSE.txt for licensing details (2-clause BSD License: https://opensource.org/licenses/BSD-2-Clause)

#pragma once

#include "PsdEndianConversion.h"
#include "PsdSyncFileReader.h"
#include "PsdSyncFileWriter.h"
#include <string>


PSD_NAMESPACE_BEGIN

/// \ingroup Util
/// \namespace fileUtil
/// \brief Provides file reading utilities.
namespace fileUtil
{
	/// Reads built-in data types from a file.
	template <typename T>
	inline T ReadFromFile(SyncFileReader& reader);

	/// Read char string from a file.
	std::string ReadStringFromFile(SyncFileReader& reader, uint32_t count);

	/// Reads built-in data types from a file, assuming they are stored as big-endian data.
	/// The read value is automatically converted to the native endianness.
	template <typename T>
	inline T ReadFromFileBE(SyncFileReader& reader);

	/// Read char string from a file, assuming they are stored as big-endian data.
	std::string ReadStringFromFileBE(SyncFileReader& reader, uint32_t count);

	/// Writes built-in data types to a file.
	template <typename T>
	inline void WriteToFile(SyncFileWriter& writer, const T& data);

	/// Writes built-in data types to a file, assuming they are to be stored as big-endian data.
	/// The write value is automatically converted to the native endianness.
	template <typename T>
	inline void WriteToFileBE(SyncFileWriter& writer, const T& data);
}

#include "PsdSyncFileUtil.inl"

PSD_NAMESPACE_END
