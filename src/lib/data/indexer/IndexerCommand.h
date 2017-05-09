#ifndef INDEXER_COMMAND_H
#define INDEXER_COMMAND_H

#include <set>
#include <string>

#include "utility/file/FilePath.h"

class IndexerCommand
{
public:
	IndexerCommand(const FilePath& sourceFilePath, const std::set<FilePath>& indexedPaths, const std::set<FilePath>& excludedPaths);
	virtual ~IndexerCommand();

	virtual std::string getKindString() const = 0;
	virtual size_t getByteSize() const;

	FilePath getSourceFilePath() const;
	std::set<FilePath> getIndexedPaths() const;
	std::set<FilePath> getExcludedPath() const;

	virtual bool preprocessorOnly() const = 0;
	virtual void setPreprocessorOnly(bool preprocessorOnly) = 0;

private:
	FilePath m_sourceFilePath;
	std::set<FilePath> m_indexedPaths;
	std::set<FilePath> m_excludedPaths;
};

#endif // INDEXER_COMMAND_H