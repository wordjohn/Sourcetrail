#ifndef SOURCE_GROUP_SETTINGS_JAVA_H
#define SOURCE_GROUP_SETTINGS_JAVA_H

#include <memory>
#include <vector>

#include "settings/SourceGroupSettings.h"

class SourceGroupSettingsJava
	: public SourceGroupSettings
{
public:
	SourceGroupSettingsJava(const std::string& id, SourceGroupType type, const ProjectSettings* projectSettings);
	virtual ~SourceGroupSettingsJava();

	virtual bool equals(std::shared_ptr<SourceGroupSettings> other) const;

	virtual std::vector<std::string> getAvailableLanguageStandards() const;

	std::vector<FilePath> getClasspaths() const;
	std::vector<FilePath> getAbsoluteClasspaths() const;
	void setClasspaths(const std::vector<FilePath>& classpaths);

	FilePath getMavenProjectFilePath() const;
	FilePath getAbsoluteMavenProjectFilePath() const;
	void setMavenProjectFilePath(const FilePath& path);

	FilePath getMavenDependenciesDirectory() const;
	FilePath getAbsoluteMavenDependenciesDirectory() const;
	void setMavenDependenciesDirectory(const FilePath& path);

	bool getShouldIndexMavenTests() const;
	void setShouldIndexMavenTests(bool value);

private:
	virtual std::vector<std::string> getDefaultSourceExtensions() const;
	virtual std::string getDefaultStandard() const;

	std::vector<FilePath> m_classpaths;
	FilePath m_mavenProjectFilePath;
	FilePath m_mavenDependenciesDirectory;
	bool m_shouldIndexMavenTests;
};

#endif // SOURCE_GROUP_SETTINGS_JAVA_H