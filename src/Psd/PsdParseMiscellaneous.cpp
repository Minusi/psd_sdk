// Copyright 2011-2020, Molecular Matters GmbH <office@molecular-matters.com>
// See LICENSE.txt for licensing details (2-clause BSD License: https://opensource.org/licenses/BSD-2-Clause)

#include "PsdPch.h"
#include "PsdParseMiscellaneous.h"
#include "PsdSyncFileUtil.h"

PSD_NAMESPACE_BEGIN

PascalString ParsePascalString(SyncFileReader& reader)
{
	PascalString string{};
	string.length = fileUtil::ReadFromFileBE<uint8_t>(reader);
	string.content = fileUtil::ReadStringFromFileBE(reader, string.length);

	return string;
}

UnicodeString ParseUnicodeString(SyncFileReader& reader)
{
	UnicodeString string{};
	string.length = fileUtil::ReadFromFileBE<uint32_t>(reader);
	string.content.resize(string.length, 0);
	reader.ReadLE<2>(&string.content[0], string.length > 0 ? string.length * 2u : 2u);

	return string;
}

PSD_NAMESPACE_END