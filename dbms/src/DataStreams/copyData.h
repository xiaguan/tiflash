// Copyright 2022 PingCAP, Ltd.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <atomic>
#include <functional>


namespace DB
{

class IBlockInputStream;
class IBlockOutputStream;
class Block;

/** Copies data from the InputStream into the OutputStream
  * (for example, from the database to the console, etc.)
  */
void copyData(IBlockInputStream & from, IBlockOutputStream & to, std::atomic<bool> * is_cancelled = nullptr);

/// max_return_size == 0 mean read all data
std::vector<Block> readData(IBlockInputStream & from, size_t max_return_size, const std::function<bool()> & is_cancelled);

void copyData(IBlockInputStream & from, IBlockOutputStream & to, const std::function<bool()> & is_cancelled);

void copyData(IBlockInputStream & from, IBlockOutputStream & to, const std::function<bool()> & is_cancelled, const std::function<void(const Block & block)> & progress);

} // namespace DB
