// Copyright 2023 PingCAP, Ltd.
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

#include <Flash/Executor/QueryExecutor.h>

namespace DB
{
class IBlockInputStream;
using BlockInputStreamPtr = std::shared_ptr<IBlockInputStream>;

struct BlockIO;

class DataStreamExecutor : public QueryExecutor
{
public:
    explicit DataStreamExecutor(const BlockIO & block_io);

    String toString() const override;

    void cancel() override;

    int estimateNewThreadCount() override;

    RU collectRequestUnit() override;

protected:
    ExecutionResult execute(ResultHandler result_handler) override;

protected:
    BlockInputStreamPtr data_stream;
};
} // namespace DB
