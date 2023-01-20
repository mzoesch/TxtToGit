import subprocess
import argparse


class SubprocessFailed(Exception):

    def __init__(self, msg: str) -> None:
        super().__init__(f'\
{msg}\
Fatal Error: Subprocess failed'
                         )


def main(*args, **kwargs) -> None:

    parser_args = kwargs['parser_args']
    clean: bool = parser_args.clean

    if clean:
        p: subprocess = subprocess.run(
            f'make clean', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=False
        )

        if p.returncode != 0:
            raise SubprocessFailed(p.stderr.decode('utf-8'))

        return

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
        type=bool,
        default=False,
        help='Clean the build directory (def.: False)'
    )

    main(parser_args=parser.parse_args())
