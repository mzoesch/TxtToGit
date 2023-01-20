import subprocess
import argparse
import time


class InvalidInput(Exception):

    def __init__(self, msg: str) -> None:
        super().__init__(f'\
\r{msg}\n\
Fatal Error: Invalid commit message.'
                         )


class SubprocessFailed(Exception):

    def __init__(self, msg: str) -> None:
        super().__init__(f'\
\r{msg}\n\
Fatal Error: Subprocess failed'
                         )


def validate_input(*args, **kwargs) -> None:

    parser_args = kwargs['parser_args']

    year: int = parser_args.year
    message: str = parser_args.message
    message_string: str = parser_args.messageString
    first_day_of_week: int = parser_args.first_day_of_week
    space: int = parser_args.space
    align: int = parser_args.align
    use_monospace: int = parser_args.useMonospace

    if year < 1970:
        raise InvalidInput(
            f'Invalid year value. {year}'
        )

    if first_day_of_week < 0 or first_day_of_week > 6:
        raise InvalidInput(
            f'Invalid firstDayOfWeek value. {first_day_of_week}'
        )

    if space < 0:
        raise InvalidInput(
            f'Invalid space value. {space}'
        )

    if align not in [0, 1, 2]:
        raise InvalidInput(
            f'Invalid align value. {align}'
        )

    if use_monospace not in [0, 1]:
        raise InvalidInput(
            f'Invalid useMonospace value. {use_monospace}'
        )

    if message == '' and message_string == '':
        raise InvalidInput(
            f'No commit message specified.'
        )

    return True


def main(*args, **kwargs) -> None:

    parser_args = kwargs['parser_args']
    clean: int = parser_args.clean

    if clean == 1:

        print('Cleaning build directory . . .')

        p: subprocess = subprocess.run(
            f'make clean', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=False
        )

        if p.returncode != 0:
            raise SubprocessFailed(p.stderr.decode('utf-8'))

        return

    validate_input(parser_args=parser_args)

    year: int = parser_args.year
    message: str = parser_args.message
    message_string: str = parser_args.messageString
    first_day_of_week: int = parser_args.first_day_of_week
    space: int = parser_args.space
    align: int = parser_args.align
    use_monospace: int = parser_args.useMonospace

    chars: list[chr] = []
    spaces: list[int] = []

    if message != '':

        messages: list = message.split(',')

        for m in messages:

            if len(m) == 0 or len(m) > 3:
                raise InvalidInput(
                    f'Invalid message. {m}'
                )

            try:
                chars.append(m[0])
                spaces.append(int(m[1:]))

            except ValueError:
                raise InvalidInput(
                    f'Invalid message. {m}'
                )

            # TODO: Check if char is valid

            if spaces[-1] < 0:
                raise InvalidInput(
                    f'Invalid message. {m}'
                )

    with open('.flags', 'a') as f:
        f.seek(0)
        f.truncate()

        f.write(f'YEAR={year}\r')
        if message == '':
            f.write(f'MESSAGE={message_string}\r')
            f.write(f'SPACE_BETWEEN_CHARS={[-1]}\r')
        else:
            f.write(f'MESSAGE={chars}\r')
            f.write(f'SPACE_BETWEEN_CHARS={spaces}\r')
        f.write(f'FIRST_DAY_OF_WEEK={first_day_of_week}\r')
        f.write(f'SPACE={space}\r')
        f.write(f'ALIGN={align}\r')
        f.write(f'USE_MONOSPACE={use_monospace}\r')

    p: subprocess = subprocess.run(
        f'make', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=False
    )

    if p.returncode != 0:
        raise SubprocessFailed(p.stderr.decode('utf-8'))

    return


if __name__ == '__main__':

    parser = argparse.ArgumentParser()

    parser.add_argument(
        '-c',
        '--clean',
        type=int,
        default=0,
        help='Clean the build directory (def.: 0)'
    )

    parser.add_argument(
        '-y',
        '--year',
        type=int,
        default=time.localtime().tm_year,
        help='Year to gen for (def.: current year)'
    )

    parser.add_argument(
        '-m',
        '--message',
        type=str,
        default='',
        help='Commit message ("Char-Space in weeks, A2, b1, ...") (def.: empty)'
    )

    parser.add_argument(
        '--messageString',
        type=str,
        default='',
        help='Commit message as String (def.: empty)'
    )

    parser.add_argument(
        '--first_day_of_week',
        type=int,
        default=6,
        help='First day of the week (Mo: 0, ...) (def.: 6)'
    )

    parser.add_argument(
        '-s',
        '--space',
        type=int,
        default=1,
        help='Space between chars in weeks (def.: 1)'
    )

    parser.add_argument(
        '-a',
        '--align',
        type=int,
        default=0,
        help='Align text (0: left, 1: center, 2: right) (def.: 0)'
    )

    parser.add_argument(
        '--useMonospace',
        type=int,
        default=1,
        help='Note: This will only affect punctuations (def.: 1)'
    )

    main(parser_args=parser.parse_args())
