# Text To Git

## Support for ASCII (0x20 to 0x7E)

## Help:

### usage: <br />

app.py<br />
[-h] [-c CLEAN] [-y YEAR] [--firstDayOfWeek FIRSTDAYOFWEEK] [-m USEMONOSPACE] [-s DEFAULTSPACE] [-a ALIGN] [-msg MESSAGE] [-msgStr MESSAGESTRING] <br />
[-cAE CLEANAFTEREXECUTION] [-min MINNUMBEROFCOMMITSATONEDAY] [-max MAXNUMBEROFCOMMITSATONEDAY] [-mCDR MAKECOMMITSINDIFFERENTREPO]
[-nDR NAMEOFDIFFERENTREPO] [-iER IGNOREEXISTINGGITREPO] <br/>

### optional arguments: <br />

-h, --help show this help message and exit <br />
-c CLEAN, --clean CLEAN Clean build dirs (def.: 0). <br />
-y YEAR, --year YEAR Year to gen for (def.: current year). <br />
--firstDayOfWeek FIRSTDAYOFWEEK First day of week (So.: 0, Mo.: 1, ...) (def.: 0). <br />
-m USEMONOSPACE, --useMonospace USEMONOSPACE Use monospace (def.: 1). <br />
-s DEFAULTSPACE, --defaultSpace DEFAULTSPACE Default space int weeks (def.: 1). <br />
-a ALIGN, --align ALIGN Align text (0: left, 1: center, 2: right) (def.: 0). <br />
-msg MESSAGE, --message MESSAGE Message in commits (e.g. "Char SpaceInWeeks, A2, b1, ...") (def.: empty). <br />
-msgStr MESSAGESTRING, --messageString MESSAGESTRING Message in commits; uses default Space for all characters (e.g. "ab") (def.: empty). <br />
-cAE CLEANAFTEREXECUTION, --cleanAfterExecution CLEANAFTEREXECUTION Clean build dirs after execution (def.: 1). <br />
-min MINNUMBEROFCOMMITSATONEDAY, --minNumberOfCommitsAtOneDay MINNUMBEROFCOMMITSATONEDAY Min number of commits at one day that is commitable (def.: 1). <br />
-max MAXNUMBEROFCOMMITSATONEDAY, --maxNumberOfCommitsAtOneDay MAXNUMBEROFCOMMITSATONEDAY Max number of commits at one day that is commitable (def.: 5). <br />
-mCDR MAKECOMMITSINDIFFERENTREPO, --makeCommitsInDifferentRepo MAKECOMMITSINDIFFERENTREPO Make commits in different repo (def.: 1). <br />
-nDR NAMEOFDIFFERENTREPO, --nameOfDifferentRepo NAMEOFDIFFERENTREPO Name of different repo (def.: myTextOnGitHub). <br />
-iER IGNOREEXISTINGGITREPO, --ignoreExistingGitRepo IGNOREEXISTINGGITREPO Ignore existing git repo (def.: 0). <br />
