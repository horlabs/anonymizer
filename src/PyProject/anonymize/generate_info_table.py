import argparse
import re
import sys
from pathlib import Path

import numpy as np

from anonymize.logParser.info_all import parse_log


def main(resultsdir, format, failed_infos=False, show_static=False, file=sys.stdout):
    max_distance = 0.01
    dir = Path(resultsdir)
    if "$" not in format:
        format += "(:?$|/)"
    r = re.compile(format)

    logfiles = []

    for x in dir.iterdir():
        if r.match(x.name):
            if x.is_file():
                logfiles.append(x)
            else:
                assert (x.is_dir())
                logfiles.append(x.joinpath("logs", "info_all.log"))

    logfiles.sort()
    print(f"|{'Testcase':^13}|{'Total':^7}|{'Authors':^9}|{'#Failed':^9}|{'Failed':^9}|{'Success':^9}|", end="",
          file=file)
    print(f"{'Original mean':^15}|{'Anonymized mean':^17}|", file=file, end="" if failed_infos else "\n")
    if failed_infos:
        print(f"{'Failed mean':^13}|{'Failed median':^15}|{'Failed std':^12}|")
    print(
        f"| {'-' * 11} | :{'-' * 3}: | :{'-' * 5}: | :{'-' * 5}: | :{'-' * 5}: | :{'-' * 5}: | :{'-' * 11}: | :{'-' * 13}: |",
        file=file, end="" if failed_infos else "\n")
    if failed_infos:
        print(f" :{'-' * 9}: | :{'-' * 11}: | :{'-' * 8}: |")
    original_means = []
    anonymized_means = []
    failed_means = []
    failed_medians = []
    failed_stds = []
    total = 0
    finished_authors = 0
    failed_authors = 0

    for logfile in logfiles:
        details = parse_log(str(logfile), no_out=True, max_distance=max_distance)
        original_means.append(details.original_mean)
        anonymized_means.append(details.anonymized_mean)
        failed_means.append(details.fails_mean)
        failed_medians.append(details.fails_median)
        failed_stds.append(details.fails_std)
        total += details.total_authors
        finished_authors += details.finished_authors
        failed_authors += details.failed_authors
        if show_static:
            # plt.scatter(list(range(0,len(details.origs))), details.origs)
            # plt.axhline(y=0.01, xmin=0.0, xmax=1.0, color='r')
            # plt.xticks(list(range(0, len(details.origs) + 1, 20)))
            # plt.show()
            print(f"| {'stat':11.11} ", end="", file=file)
            print(
                f"| {details.total_authors:<5} | {details.finished_authors:<7} | {len([x for x in details.origs if x > 0.01]):<7} ",
                end="",
                file=file)
            failed_rate = len([x for x in details.origs if
                               x > max_distance]) / details.finished_authors * 100 if details.finished_authors > 0 else 0
            success_rate = (details.finished_authors - len([x for x in details.origs if
                                                            x > max_distance])) / details.finished_authors * 100 if details.finished_authors > 0 else 0
            print("| {0:^7} | {1:^7} ".format(f"{failed_rate:5.2f}%", f"{success_rate:5.2f}%"), end="", file=file)
            print("| {0:>13} | {1:>15} |".format(f"{details.original_mean:5.2f}%", f"{details.original_mean:5.2f}%"),
                  file=file, end=" " if failed_infos else "\n")
            if failed_infos:
                print(
                    "{0:>11} | {1:>13} | {2:>10} |".format(
                        f"{np.mean([x for x in details.origs if x > max_distance]) * 100:5.2f}%",
                        f"{np.median([x for x in details.origs if x > max_distance]) * 100:5.2f}%",
                        f"{np.std([x for x in details.origs if x > max_distance]) * 100:5.2f}%"))

        # plt.scatter(list(range(0, len(details.results))), details.results)
        # plt.axhline(y=0.01, xmin=0.0, xmax=1.0, color='r')
        # plt.xticks(list(range(0, len(details.results) + 1, 10)))
        # plt.show()
        print(f"| {r.search(str(logfile)).group(1):3.3}.._{r.search(str(logfile)).group(2):3.3}.. ", end="", file=file)
        print(f"| {details.total_authors:<5} | {details.finished_authors:<7} | {details.failed_authors:<7} ", end="",
              file=file)
        failed_rate = details.failed_authors / details.finished_authors * 100 if details.finished_authors > 0 else 0
        success_rate = (
                               details.finished_authors - details.failed_authors) / details.finished_authors * 100 if details.finished_authors > 0 else 0
        print("| {0:^7} | {1:^7} ".format(f"{failed_rate:5.2f}%", f"{success_rate:5.2f}%"), end="", file=file)
        print("| {0:>13} | {1:>15} |".format(f"{details.original_mean:5.2f}%", f"{details.anonymized_mean:5.2f}%"),
              file=file, end=" " if failed_infos else "\n")
        if failed_infos:
            print("{0:>11} | {1:>13} | {2:>10} |".format(f"{details.fails_mean:5.2f}%", f"{details.fails_median:5.2f}%",
                                                         f"{details.fails_std:5.2f}%"))

    print(f"|{' ':13}| {total:<5} | {finished_authors:>7} | {failed_authors:>7} ", end="", file=file)
    failed_rate = failed_authors / finished_authors * 100 if finished_authors > 0 else 0
    success_rate = (finished_authors - failed_authors) / finished_authors * 100 if finished_authors > 0 else 0
    print("| {0:^7} | {1:^7} ".format(f"{failed_rate:5.2f}%", f"{success_rate:5.2f}%"), end="", file=file)
    print("| {0:>13} | {1:>15} |".format(f"{np.mean(original_means):5.2f}%", f"{np.mean(anonymized_means):5.2f}%"),
          file=file, end=" " if failed_infos else "\n")
    if failed_infos:
        print(
            "{0:>11} | {1:>13} | {2:>10} |".format(f"{np.mean(failed_means):5.2f}%", f"{np.mean(failed_medians):5.2f}%",
                                                   f"{np.mean(failed_stds):5.2f}%"))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Parse important information from attack log")
    parser.add_argument(dest="RESULTSDIR", type=str,
                        help="Directory with the logfiles or results-directories as subdirs")
    parser.add_argument("-f", "--format", required=True, type=str, help="Regex for name format of logfiles/results dir")
    parser.add_argument("--failed", action="store_true", help="Show additional information for fails")
    parser.add_argument("-s", "--show-static", action="store_true",
                        help="Show static results before dynamic modifications")
    args = parser.parse_args()
    if not Path(args.RESULTSDIR).exists():
        print("Directory doesn't exists", file=sys.stderr)
        exit(1337)
    if not Path(args.RESULTSDIR).is_dir():
        print(f"{args.RESULTSDIR} is not a directory", file=sys.stderr)
        exit(1337)
    if args.format.count("(") != 2:
        print("Format needs exactly two groups for the problem ID", file=sys.stderr)
        exit(1337)
    main(args.RESULTSDIR, args.format, args.failed, args.show_static)
