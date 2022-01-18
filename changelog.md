# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

## [0.1.2] - 2022-01-15
### Added
- The `changelog.md` of the project starts in this version, but it will contains retroactive info from the first versions.
- The `README.md` of the project it's created and started in this version.
- Created the folder `msil`, that contains examples of working `managed code`.

### Changed
- The `test` project, that will contains the tests for the code of the project, now it's configured as a `SHARED` library in order to make
the whole project compile.

### Fixed
- No fixes.

### Removed
- No content removed.


## [0.1.1] - 2022-01-15
### Added
- Added a testing directory in order to be used with `Microsoft Cpp Unit Test Framework`.
The intention it's to publish the testing results and the code coverage on the GitHub repository thanks to the GitHub actions.

### Changed
- `src` folder now contains it's own `CMake` script to build the source code of the library.

### Fixed
- No fixes.

### Removed
- No content removed.


## [0.1.0] - 2022-01-15
### Added
- Designed the basic skeleton of the project directories.
- CMake is implemented as a builder manager.

### Changed
- No changes.

### Fixed
- No fixes.

### Removed
- No content removed.