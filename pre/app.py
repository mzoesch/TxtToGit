import chars as chrs
import time
import argparse
import datetime
import copy
import subprocess


class Log:

    def __init__(self) -> None:

        with open('log.txt', 'w') as f:
            f.seek(0)
            f.truncate()

        self.time = time.perf_counter()

    def write(self, obj: object, stdout=False) -> None:
        with open('log.txt', 'a') as f:
            f.write(
                f'{self.time:.4f}s  in:\r{obj.__str__()}\r\n'
            )

        if stdout:
            print(obj.__str__())


class UnknownChar(Exception):

    def __init__(self, l: Log, char: chr) -> None:

        self.msg = f'\
Unkwown char: {char}\n\
Valid chars:\n{", ".join(chrs.VALID_CHARS.keys())}\n\
Fatal error: Failed at char: {char}.'

        l.write(self)
        super().__init__(self.msg)


class NotEnoughDays(Exception):

    def __init__(self, l: Log, char: chr, days_delta) -> None:
        self.commitable_days, self.days_in_the_year = days_delta

        self.msg = f'\
Not enough days to display the message.\n\
You can try to reduce the space between chars or change the year.\n\
Days needed to display: {self.commit_days} > Days that can be used: {self.days_in_the_year}.\n\
Fatal error: Failed at char: {char}.'

        l.write(self)
        super().__init__(self.msg)


class DaysUnequal(Exception):

    def __init__(self, l: Log, len_commitable_days: int,
                 len_relevant_days_of_year: int) -> None:
        self.msg = f'\
Days unequal.\n\
Days needed to display: {len_commitable_days} != Days that can be used: {len_relevant_days_of_year}.\n\
Unexpected error: Failed at analysing.'

        l.write(self.msg)
        super().__init__(self.msg)


class Commit:

    def __init__(self, l: Log, day: datetime.datetime, set_day: bool) -> None:
        self.day: datetime.datetime = day
        self.set_day = set_day
        self.l = l

    def __str__(self) -> str:
        return f'{self.set_day}'

    def commit(self) -> None:

        class CommitError(Exception):

            def __init__(self, l: Log, day: datetime.datetime, flag: chr, subprocess_stdout: bytes) -> None:

                self.msg = f'\
\rFailed to {"add" if flag == "a" else "commit"} file at {day}.\n\
Unexpected error: Failed at commiting.\n\
ERR: {subprocess_stdout.decode("utf-8")}'

                l.write(self.msg)
                super().__init__(self.msg)

        if not self.set_day:
            self.l.write(f'{self.day} : ok : not commiting', stdout=True)
            return

        with open('characters.txt', 'w') as f:
            f.seek(0)
            f.truncate()
            f.write(f'{self.day}')

        p: subprocess = subprocess.run(
            [
                'git',
                'add',
                'characters.txt'
            ],
            check=False,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE
        )

        if p.returncode != 0:
            raise CommitError(self.l, self.day, 'a', p.stderr)
        self.l.write(p.stdout.decode('utf-8'), stdout=False)

        p: subprocess = subprocess.run(
            f'git commit -m "{self.day}" --date "{self.day}"',
            check=False,
            shell=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE
        )

        if p.returncode != 0:
            raise CommitError(self.l, self.day, 'c', p.stderr)
        self.l.write(p.stdout.decode('utf-8'), stdout=False)

        self.l.write(f'{self.day} : ok : commiting', stdout=True)


class Overview:

    def __init__(self, days: list[Commit]) -> None:
        self.days = days

    def __str__(self) -> str:

        line1 = [
            self.days[i+0].set_day
            for i in range(0, len(self.days)-1, 7)
        ]
        line1 = [
            1 if day else 0
            for day in line1
        ]

        line2 = [
            self.days[i+1].set_day
            for i in range(0,  len(self.days)-1, 7)
        ]
        line2 = [
            1 if day else 0
            for day in line2
        ]

        line3 = [
            self.days[i+2].set_day
            for i in range(0,  len(self.days)-1, 7)
        ]
        line3 = [
            1 if day else 0
            for day in line3
        ]

        line4 = [
            self.days[i+3].set_day
            for i in range(0,  len(self.days)-1, 7)
        ]
        line4 = [
            1 if day else 0
            for day in line4
        ]

        line5 = [
            self.days[i+4].set_day
            for i in range(0,  len(self.days)-1, 7)
        ]
        line5 = [
            1 if day else 0
            for day in line5
        ]

        line6 = [
            self.days[i+5].set_day
            for i in range(0, len(self.days)-1, 7)
        ]
        line6 = [
            1 if day else 0
            for day in line6
        ]

        line7 = [
            self.days[i+6].set_day
            for i in range(0, len(self.days)-1, 7)
        ]
        line7 = [
            1 if day else 0
            for day in line7
        ]

        return f'\n\
{line1}\n\
{line2}\n\
{line3}\n\
{line4}\n\
{line5}\n\
{line6}\n\
{line7}'


class Character:

    @staticmethod
    def __layerd_list(c: chr) -> list[int]:

        if c == 'A':
            return chrs.VALID_CHARS['A']
        elif c == 'B':
            return chrs.VALID_CHARS['B']
        elif c == 'C':
            return chrs.VALID_CHARS['C']
        elif c == 'D':
            return chrs.VALID_CHARS['D']
        elif c == 'E':
            return chrs.VALID_CHARS['E']
        elif c == 'F':
            return chrs.VALID_CHARS['F']
        elif c == 'G':
            return chrs.VALID_CHARS['G']
        elif c == 'H':
            return chrs.VALID_CHARS['H']
        elif c == 'I':
            return chrs.VALID_CHARS['I']
        elif c == 'J':
            return chrs.VALID_CHARS['J']
        elif c == 'K':
            return chrs.VALID_CHARS['K']
        elif c == 'L':
            return chrs.VALID_CHARS['L']
        elif c == 'M':
            return chrs.VALID_CHARS['M']
        elif c == 'N':
            return chrs.VALID_CHARS['N']
        elif c == 'O':
            return chrs.VALID_CHARS['O']
        elif c == 'P':
            return chrs.VALID_CHARS['P']
        elif c == 'Q':
            return chrs.VALID_CHARS['Q']
        elif c == 'R':
            return chrs.VALID_CHARS['R']
        elif c == 'S':
            return chrs.VALID_CHARS['S']
        elif c == 'T':
            return chrs.VALID_CHARS['T']
        elif c == 'U':
            return chrs.VALID_CHARS['U']
        elif c == 'V':
            return chrs.VALID_CHARS['V']
        elif c == 'W':
            return chrs.VALID_CHARS['W']
        elif c == 'X':
            return chrs.VALID_CHARS['X']
        elif c == 'Y':
            return chrs.VALID_CHARS['Y']
        elif c == 'Z':
            return chrs.VALID_CHARS['Z']
        elif c == ' ':
            return chrs.VALID_CHARS[' ']
        elif c == '!':
            return chrs.VALID_CHARS['!']
        elif c == '?':
            return chrs.VALID_CHARS['?']
        elif c == '.':
            return chrs.VALID_CHARS['.']
        elif c == ',':
            return chrs.VALID_CHARS[',']
        elif c == '-':
            return chrs.VALID_CHARS['-']
        elif c == '_':
            return chrs.VALID_CHARS['_']
        elif c == ':':
            return chrs.VALID_CHARS[':']
        elif c == ';':
            return chrs.VALID_CHARS[';']
        elif c == '(':
            return chrs.VALID_CHARS['(']
        elif c == ')':
            return chrs.VALID_CHARS[')']
        elif c == '[':
            return chrs.VALID_CHARS['[']
        elif c == ']':
            return chrs.VALID_CHARS[']']
        elif c == '{':
            return chrs.VALID_CHARS['{']
        elif c == '}':
            return chrs.VALID_CHARS['}']
        elif c == '>':
            return chrs.VALID_CHARS['>']
        elif c == '<':
            return chrs.VALID_CHARS['<']
        elif c == '@':
            return chrs.VALID_CHARS['@']

        return [-1]

    def __init__(self, l: Log, c: chr) -> None:
        self.c: chr = c

        if self.__layerd_list(c=self.c) == [-1]:
            raise UnknownChar(l, f'Invalid character: {self.c}')
        self.__layerd_list_view: list[int] = self.__layerd_list(c=self.c)

        self.chronological_order: list[int] = [
            0, 5, 10, 15, 20, 25, 30,
            1, 6, 11, 16, 21, 26, 31,
            2, 7, 12, 17, 22, 27, 32,
            3, 8, 13, 18, 23, 28, 33,
            4, 9, 14, 19, 24, 29, 34,
        ]
        self._chronological_order_list_view: list[int] = [
            i
            for i in self.chronological_order_yield_view()
        ]

    def chronological_order_yield_view(self) -> int:
        for i in self.chronological_order:
            yield self.__layerd_list_view[i]

    @ property
    def chronological_order_list_view(self) -> list[int]:
        return self._chronological_order_list_view


def remove_insufficient_weeks(days: list, fdotw: int) -> list:

    while ...:

        if days[0].weekday() == fdotw:
            break
        days.remove(days[0])

    while ...:

        if days[-1].weekday() == (fdotw + 6) % 7:
            break
        days.remove(days[-1])

    return days


def main(*args, **kwargs) -> None:

    parser_args = kwargs['parser_args']
    l: Log = Log()

    year: int = parser_args.year
    fdotw: int = parser_args.fdotw
    space: int = parser_args.space
    msg: str = parser_args.msg
    HEIGTH, LENGTH = 7, 5

    first_day_of_year = datetime.datetime(year=year, month=1, day=1)
    last_day_of_year = datetime.datetime(year=year, month=12, day=31)
    all_days_of_year = [
        first_day_of_year + datetime.timedelta(days=i)
        for i in range(
            (last_day_of_year - first_day_of_year).days + 1
        )
    ]
    relevant_days_of_year = remove_insufficient_weeks(
        days=copy.deepcopy(all_days_of_year),  # Inefficient, change later
        fdotw=fdotw,
    )

    try:

        msg_characters: list[Character] = [
            Character(l=l, c=c)
            for c in msg
        ]

    except UnknownChar as e:

        print(e)
        return

    commitable_days: list[int] = []

    for char in msg_characters:

        commitable_days.extend(  # Space between chars
            [
                '0'
                for _ in range(HEIGTH * space)
            ]
        ) if commitable_days != [] else ...

        if len(commitable_days) + len(char.chronological_order_list_view) > \
                len(relevant_days_of_year):

            raise NotEnoughDays(
                l=l,
                char=char.c,
                days_delta=(
                    len(commitable_days) +
                    len(char.chronological_order_list_view),
                    len(relevant_days_of_year)
                )
            )
            return

        for c in char.chronological_order_yield_view():
            commitable_days.append(c)

    # Fill up the rest of the year
    if len(commitable_days) < len(relevant_days_of_year):

        commitable_days.extend(
            [
                '0'
                for _ in range(
                    len(relevant_days_of_year) - len(commitable_days)
                )
            ]
        )

    commit_days: Commit = []

    if len(commitable_days) != len(relevant_days_of_year):

        raise DaysUnequal(
            l=l,
            len_commitable_days=len(commitable_days),
            len_relevant_days_of_year=len(relevant_days_of_year)
        )
        return

    for i in range(len(commitable_days)):
        commit_days.append(  # Sort with date
            Commit(l, relevant_days_of_year[i], commitable_days[i] == '1')
        )

    print(f'{Overview(days=commit_days)}\n')
    print('Commit? (y/n)')
    if input() != 'y':
        return

    for commit_day in commit_days:

        commit_day.commit()

    return


if __name__ == '__main__':

    parser = argparse.ArgumentParser()

    parser.add_argument(
        '-y',
        '--year',
        type=int,
        default=time.localtime().tm_year,
        help='Year to gen for (def.: current year)'
    )
    parser.add_argument(
        '--fdotw',
        type=int,
        default=6,
        help='First day of the week (Mo: 0, ... ) (def.: 6)'
    )
    parser.add_argument(
        '-s',
        '--space',
        type=int,
        default=1,
        help='Space between chars in weeks (def.: 1)'
    )
    parser.add_argument(
        '-m',
        '--msg',
        type=str,
        default='',
        help='Message to display (def.: empty)'
    )

    main(parser_args=parser.parse_args())
