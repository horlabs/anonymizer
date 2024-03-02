import argparse
import re
import sys
from collections import namedtuple
from pathlib import Path

import numpy as np

Details = namedtuple("Details",
                     ["total_authors", "finished_authors", "failed_authors", "original_mean", "anonymized_mean",
                      "fails_mean", "fails_median", "fails_std", "origs", "results", "author_names"])


def parse_log(log_file, verbose=False, no_out=False, max_distance=0.01) -> Details:
    with open(log_file, "r") as f:
        content = f.readlines()
        f.seek(0)
        content_bytes = f.read()

    processed_author_names = []
    fails = 0
    failed_authors = {}
    results = []
    originals = []
    best = 0.0
    original = 0.0
    name = ""
    total_str = re.search('Remaining: *([0-9]+)|$', content_bytes).group(1)
    total_authors = (int(total_str) + 1) if total_str is not None and total_str.isnumeric() else 0
    errors = 0
    exception = False
    for line in content:
        if line == "\n" and not exception:
            if best == 0.0:
                errors += 1
                total_authors -= 1
                continue
            if best > max_distance:
                if verbose:
                    print(name)
                    print(f"{original * 100:06.3f}% => {best * 100:0.03f}%")
                failed_authors[name] = best
                fails += 1
            results.append(best)
            originals.append(original)
            processed_author_names.append(name)
            best = 0.0
            original = 0.0
            name = ""
            continue

        if line == "\n" and exception:
            exception = False
            continue

        # if "Exception: " in line:
        #     exception = True
        #     continue

        if name == "" and "Start-" in line:
            name = line.strip().split("Start-")[-1]
            name = name.split("-")[-2]

        for match in re.findall(r"Distance reduced from ([0-9]\.[0-9]+) to ([0-9]\.[0-9]+)$", line,
                                re.RegexFlag.MULTILINE):
            if best > float(match[1]) or best == 0.0:
                best = float(match[1])
            original = float(match[0])

    if best > max_distance:
        if verbose:
            print(name)
            print(f"{float(original) * 100:06.3f}% => {float(best) * 100:0.03f}%")
        failed_authors[name] = best
        fails += 1
        results.append(best)
        originals.append(original)
        processed_author_names.append(name)

    original_mean = np.mean(originals) * 100 if len(originals) > 0 else 0
    anonymized_mean = np.mean(results) * 100 if len(results) > 0 else 0
    fails_mean = np.mean([x for x in results if x > max_distance]) * 100 if len(
        [x for x in results if x > max_distance]) > 0 else 0
    fails_median = np.median([x for x in results if x > max_distance]) * 100 if len(
        [x for x in results if x > max_distance]) > 0 else 0
    fails_std = np.std([x for x in results if x > max_distance]) * 100 if len(
        [x for x in results if x > max_distance]) > 0 else 0
    details = Details(total_authors, len(originals), fails, original_mean, anonymized_mean, fails_mean, fails_median,
                      fails_std, originals, results, processed_author_names)
    if not no_out:
        print(f"authors: {len(originals)}")
        print(f"{fails} authors failed:")
        for k, v in failed_authors.items():
            print(f"\t{k:20s} => {v * 100:06.3f}%")
        print(f"\t\"recoverable\": {len([x for x in results if x > max_distance and x <= (max_distance + 0.02)])}")
        print(f"\tfails mean:   {fails_mean:0.4f}%")
        print(f"\tfails median: {fails_median:0.4f}%")
        print(f"\tfails std:    {fails_std:0.4f}")
        print(f"original mean:   {original_mean:0.4f}%")
        print(f"original median: {np.median(originals) * 100:0.4f}%")
        print(f"results mean:    {anonymized_mean:0.4f}%")
        print(f"results median:  {np.median(results):0.4f}%")

    return details


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Parse important information from attack log")
    parser.add_argument(dest="LOGFILE", type=str, help="Logfile to parse")
    parser.add_argument("-v", "--verbose", action="store_true", help="Show more information")
    args = parser.parse_args()
    if not Path(args.LOGFILE).exists():
        print("File doesn't exists", file=sys.stderr)
        exit(1337)
    parse_log(args.LOGFILE, args.verbose)
