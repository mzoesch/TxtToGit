# Type python<3> app.py -h for help

import argparse
import time
import subprocess


class SubprocessFailed(Exception):

    def __init__(self, msg: str) -> None:
        super().__init__(f'\
\r{msg}\n\
Fatal Error: Subprocess failed.'
                         )

        return


def clean_build_dirs() -> None:

    p: subprocess = subprocess.run(
        f'make clean',
        shell=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        check=False,
    )

    if p.returncode != 0:
        print(p.stdout.decode('utf-8'), end='')
        print(p.stderr.decode('utf-8'))

        raise SubprocessFailed(
            f'{p.stderr.decode("utf-8")}\nWhile cleaning build dirs.'
        )
        return

    p.subprocess = subprocess.run(
        f'rm -rf .flags',
        shell=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        check=False,
    )

    print(p.stdout.decode('utf-8'), end='')
    print(p.stderr.decode('utf-8'))

    if p.returncode != 0:
        raise SubprocessFailed(
            f'{p.stderr.decode("utf-8")}\nWhile cleaning .flags.'
        )
        return

    return


def build_bin() -> None:

    p: subprocess = subprocess.Popen(
        f'make',
        shell=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )

    for c in iter(lambda: p.stdout.read(1), b''):
        print(c.decode('utf-8'), end='')

    return


def run_bin(part: int) -> None:

    cntn: str = '0'
    abort: str = '-1'
    cmmt: str = '1'

    if part == 1:

        with open('.tmp.txt', 'w') as f:
            f.write(cntn)

        p: subprocess = subprocess.Popen(
            f'./obj/output',
            shell=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )

        for c in iter(lambda: p.stdout.read(1), b''):
            t: str = c.decode('utf-8')
            if (t == '$'):
                run_bin(2)
            else:
                print(t, end='')

            continue

        for c in iter(lambda: p.stderr.read(1), b''):
            print(c.decode('utf-8'), end='')
            continue

        return

    if part == 2:

        ipt: str = input('Commit to git (y/n): ')
        if (ipt == 'y'):
            with open('.tmp.txt', 'w') as f:
                f.write(cmmt)
            return

        with open('.tmp.txt', 'w') as f:
            f.write(abort)
        return

    return


def validate_args(parser_args: argparse.Namespace) -> None:

    year: int = parser_args.year
    first_day_of_week: int = parser_args.firstDayOfWeek
    use_monospace: int = parser_args.useMonospace
    default_space: int = parser_args.defaultSpace
    align: int = parser_args.align
    message: str = parser_args.message
    message_string: str = parser_args.messageString
    cleanAfterExecution: int = parser_args.cleanAfterExecution
    minNumberOfCommitsAtOneDay: int = parser_args.minNumberOfCommitsAtOneDay
    maxNumberOfCommitsAtOneDay: int = parser_args.maxNumberOfCommitsAtOneDay
    makeCommitsInDifferentRepo: int = parser_args.makeCommitsInDifferentRepo
    nameOfDifferentRepo: str = parser_args.nameOfDifferentRepo
    ignoreExistingGitRepo: int = parser_args.ignoreExistingGitRepo

    if year < 1970:
        raise ValueError('Year must be >= 1970.')
    if first_day_of_week < 0 or first_day_of_week > 6:
        raise ValueError('FirstDayOfWeek must be in range [0, 6].')
    if use_monospace not in [0, 1]:
        raise ValueError('UseMonospace must in range [0, 1].')
    if default_space < 1:
        raise ValueError('DefaultSpace must be >= 1.')
    if align not in [0, 1, 2]:
        raise ValueError('Align must be in range [0, 2].')
    if message_string != '' and message != '':
        raise ValueError('Message and messageString are mutually exclusive.')
    if cleanAfterExecution not in [0, 1]:
        raise ValueError('CleanAfterExecution must in range [0, 1].')
    if minNumberOfCommitsAtOneDay < 0:
        raise ValueError('minNumberOfCommitsAtOneDay must be >= 0.')
    if maxNumberOfCommitsAtOneDay < 1:
        raise ValueError('maxNumberOfCommitsAtOneDay must be >= 1.')
    if minNumberOfCommitsAtOneDay > maxNumberOfCommitsAtOneDay:
        raise ValueError(
            'minNumberOfCommitsAtOneDay must be <= maxNumberOfCommitsAtOneDay.'
        )
    if makeCommitsInDifferentRepo not in [0, 1]:
        raise ValueError('makeCommitsInDifferentRepo must in range [0, 1].')
    if makeCommitsInDifferentRepo == 1 and nameOfDifferentRepo == '':
        raise ValueError(
            'nameOfDifferentRepo must be set if makeCommitsInDifferentRepo is set to 1.'
        )
    if ignoreExistingGitRepo not in [0, 1]:
        raise ValueError('ignoreExistingGitRepo must in range [0, 1].')

    string: str = ''
    spacesBetweenChars: list[int] = []

    if message_string != '':
        for _ in message_string:

            # TODO: if char is a whitespace or punctuation

            spacesBetweenChars.append(default_space)

        string = message_string

    else:

        message = message.split(',')
        for char in message:

            if len(char) == 0 or len(char) > 3:
                raise ValueError(
                    f'Message must be in format "Char SpaceInWeeks, Char SpaceInWeeks, ..."'
                )

            try:
                string += char[0]
                spacesBetweenChars.append(int(char[1:]))

            except ValueError as e:
                raise ValueError(
                    f'{e}\rMessage must be in format "Char SpaceInWeeks, Char SpaceInWeeks, ..."'
                )

            # TODO: char validation
            # TODO: if char is a whitespace or punctuation

            if spacesBetweenChars[-1] < 0:
                raise ValueError('SpaceInWeeks must be >= 0.')

    return {
        'year': year,
        'firstDayOfWeek': first_day_of_week,
        'useMonospace': use_monospace,
        'align': align,
        'message': string,
        'spacesBetweenChars': spacesBetweenChars,
        'cleanAfterExecution': cleanAfterExecution,
        'minNumberOfCommitsAtOneDay': minNumberOfCommitsAtOneDay,
        'maxNumberOfCommitsAtOneDay': maxNumberOfCommitsAtOneDay,
        'makeCommitsInDifferentRepo': makeCommitsInDifferentRepo,
        'nameOfDifferentRepo': nameOfDifferentRepo,
        'ignoreExistingGitRepo': ignoreExistingGitRepo
    }


def write_to_file(file_path: str, content: dict = None) -> None:

    if content is None:
        return

    keys: list[str] = list(content.keys())
    values: list[str] = list(content.values())

    with open(file_path, 'w') as f:
        for i in range(len(keys)):
            f.write(f'{keys[i]}={values[i]}\n')

    return


def main(*args, **kwargs) -> None:

    parser_args = kwargs['parser_args']
    clean: int = parser_args.clean
    cleanAfterExecution: int = parser_args.cleanAfterExecution

    if clean == 1:
        return clean_build_dirs()

    write_to_file(
        '.flags', content=validate_args(
            parser_args=parser_args
        )
    )

    build_bin()

    run_bin(1)

    if cleanAfterExecution == 1:
        return clean_build_dirs()

    return


if __name__ == '__main__':

    parser = argparse.ArgumentParser()

    parser.add_argument(  # --clean
        '-c',
        '--clean',
        type=int,
        default=0,
        help='Clean build dirs (def.: 0).',
    )

    parser.add_argument(  # --year
        '-y',
        '--year',
        type=int,
        default=time.localtime().tm_year,
        help='Year to gen for (def.: current year).',
    )

    parser.add_argument(  # --firstDayOfWeek
        '--firstDayOfWeek',
        type=int,
        default=0,
        help='First day of week (So.: 0, Mo.: 1, ...) (def.: 0).',
    )

    parser.add_argument(  # --useMonospace
        '-m',
        '--useMonospace',
        type=int,
        default=1,
        help='Use monospace (def.: 1).',
    )

    parser.add_argument(  # --defaultSpace
        '-s',
        '--defaultSpace',
        type=int,
        default=1,
        help='Default space in weeks (def.: 1).',
    )

    parser.add_argument(  # --align
        '-a',
        '--align',
        type=int,
        default=0,
        help='Align text (0: left, 1: center, 2: right) (def.: 0).',
    )

    parser.add_argument(  # --message
        '-msg',
        '--message',
        type=str,
        default='',
        help='Message in commits (e.g. "Char SpaceInWeeks, A2, b1, ...") (def.: empty).',
    )

    parser.add_argument(  # --messageString
        '-msgStr',
        '--messageString',
        type=str,
        default='',
        help='Message in commits; uses default Space for all characters (e.g. "ab") (def.: empty).',
    )

    parser.add_argument(  # --cleanAfterExecution
        '-cAE',
        '--cleanAfterExecution',
        type=int,
        default=1,
        help='Clean build dirs after execution (def.: 1).',
    )

    parser.add_argument(  # --minNumberOfCommitsAtOneDay
        '-min',
        '--minNumberOfCommitsAtOneDay',
        type=int,
        default=1,
        help='Min number of commits at one day that is commitable (def.: 1).',
    )

    parser.add_argument(  # --maxNumberOfCommitsAtOneDay
        '-max',
        '--maxNumberOfCommitsAtOneDay',
        type=int,
        default=5,
        help='Max number of commits at one day that is commitable (def.: 5).',
    )

    parser.add_argument(  # --makeCommitsInDifferentRepo
        '-mCDR',
        '--makeCommitsInDifferentRepo',
        type=int,
        default=1,
        help='Make commits in different repo (def.: 1).',
    )

    parser.add_argument(  # --nameOfDifferentRepo
        '-nDR',
        '--nameOfDifferentRepo',
        type=str,
        default='myTextOnGitHub',
        help='Name of different repo (def.: myTextOnGitHub).',
    )

    parser.add_argument(  # --ignoreExistingGitRepo
        '-iER',
        '--ignoreExistingGitRepo',
        type=int,
        default=0,
        help='Ignore existing git repo (def.: 0).',
    )

    main(parser_args=parser.parse_args())
