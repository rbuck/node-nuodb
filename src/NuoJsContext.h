#ifndef NUOJS_CONTEXT_H
#define NUOJS_CONTEXT_H

#include <vector>

#include "NuoJsAddon.h"
#include "NuoJsOptions.h"
#include "NuoJsParams.h"
#include "NuoJsValue.h"
#include "NuoDB.h"

namespace NuoJs
{
class Context
{
public:
    Context();

    Context(const Context& c);

    ~Context();

    Params getParams() const;
    void setParams(const Params& params);

    RowMode getRowMode() const;
    void setRowMode(RowMode rowMode);

    NuoDB::Connection* getConnection() const;
    void setConnection(NuoDB::Connection* c);

    bool isConnectionOpen() const;
    void setIsConnectionOpen(bool b);

    NuoDB::PreparedStatement* getStatement() const;
    void setStatement(NuoDB::PreparedStatement* s);

    bool isStatementOpen() const;
    void setIsStatementOpen(bool b);

    NuoDB::ResultSet* getResultSet() const;
    void setResultSet(NuoDB::ResultSet* r);

    bool isResultSetOpen() const;
    void setIsResultSetOpen(bool b);

    size_t getFetchSize() const;
    void setFetchSize(size_t size);

    size_t getRowsFetched() const;

    void pushRow(std::vector<SqlValue> row);
    std::vector<SqlValue> popRow();

private:
    Params params;

    RowMode rowMode;

    NuoDB::Connection* connection;
    bool connectionIsOpen;

    NuoDB::PreparedStatement* statement;
    bool statementIsOpen;

    NuoDB::ResultSet* result;
    bool resultIsOpen;

    std::vector<std::vector<SqlValue> > rows;
    size_t fetchSize;
};
} // namespace NuoJs

#endif