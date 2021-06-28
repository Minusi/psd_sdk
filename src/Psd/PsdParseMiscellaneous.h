// Copyright 2011-2020, Molecular Matters GmbH <office@molecular-matters.com>
// See LICENSE.txt for licensing details (2-clause BSD License: https://opensource.org/licenses/BSD-2-Clause)

#pragma once

#include <string>
#include "PsdString.h"
#include "PsdSyncFileReader.h"

PSD_NAMESPACE_BEGIN

PascalString ParsePascalString(SyncFileReader& reader);

UnicodeString ParseUnicodeString(SyncFileReader& reader);


PSD_NAMESPACE_END
