# Modified Semantic Versioning
[MAJOR].[MINOR MAJOR].[MINOR][suffix]

MAJOR is breaking change FOR PLAYER, i.e. saves must be restarted
MINOR MAJOR is orchestrated release (human defined grouping of features) + can get a nickname
MINOR is semver feature/semver MINOR; fixes simply increment the suffix
suffix is alphabetical, starting at 'a' for the first fix, 'aa' after 'z', etc.

MAJOR, MINOR, and suffix can be calculated from git history; MINOR MAJOR is human defined (set the git tag manually)

# Branching
on dev, the suffix 'dev' is used for MINOR MAJOR and MINOR + suffix update normally.
on release of the MINOR MAJOR version in question, MINOR + suffix reset to 0a and all history since the previous MINOR MAJOR version is squashed into main
on main at a given time, MINOR MAJOR is the latest release

useful command:
`git describe --tags --long --match 'v[0–9]*'` can provide the last tag concatenated with number of commits since last tag

