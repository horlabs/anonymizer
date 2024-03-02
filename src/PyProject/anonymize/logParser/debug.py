import argparse
import json
import re
import sys
from collections import namedtuple
from pathlib import Path

log_line_re = re.compile("^([0-9]{4}-[0-9]{1,2}-[0-9]{1,2}) ([0-9:,]+) - (DEBUG|INFO) - (.*)$")
LogLineParts = namedtuple("LogLineParts", ["date", "time", "level", "message"])
transformer_line_re = re.compile(
    "([0-9]+),([0-9]+):`([a-zA-Z0-9_-]+) ([a-zA-Z0-9_/. -]+) ((?:-[a-zA-Z0-9_=\"-]+ +)*)-- \.{3}` successfull with ([0-9.]+) \(([0-9]+)\) \[.*\]")
TransformerLineParts = namedtuple("TransformerLineParts",
                                  ["round", "index", "transformer", "file", "arguments", "result", "author"])
best_instance_line_re = re.compile(
    "~~> Best Instance: ([0-9]+),([0-9]+):`([a-zA-Z0-9_-]+) ([a-zA-Z0-9_/. -]+) ((?:-[a-zA-Z0-9_=\"-]+ +)*)-- \.{3}` successfull with ([0-9.]+) \(([0-9]+)\) \[.*\]")

file_re = re.compile(
    "([0-9]+_[0-9]+)_([a-zA-Z0-9.-]+)(?:_raw_|_raw_format_){0,1}[0-9]*(?:_before|_after_transf_|_final_){0,1}\.cpp$")


def parse_log(log_file, verbose=False, no_out=False):
    with open(log_file, "r") as f:
        content_lines = [x.strip() for x in f.readlines()]
        f.seek(0)
        content_bytes = f.read()

    rounds = {}
    current_round = []

    loaded_transformers = None

    for line in content_lines:
        if line == "":
            continue
        if not log_line_re.match(line):
            continue

        log_line_parts = LogLineParts(*log_line_re.search(line).groups())
        # if log_line_parts.level == "DEBUG":
        #    print(log_line_parts)
        if transformer_line_re.match(log_line_parts.message):
            transformer_line_parts = TransformerLineParts(*transformer_line_re.search(log_line_parts.message).groups())
            current_round.append(transformer_line_parts)
        elif best_instance_line_re.match(log_line_parts.message):
            best_instance_line_parts = TransformerLineParts(
                *best_instance_line_re.search(log_line_parts.message).groups())
            problem, author = file_re.search(Path(best_instance_line_parts.file).name).groups()
            # print(problem, author)
            rounds[int(best_instance_line_parts.round)] = {"problem_id": problem,
                                                           "author": author,
                                                           "transformers": current_round,
                                                           "best_instance": best_instance_line_parts}
            current_round = []
        elif log_line_parts.message.startswith("Loaded transformers:"):
            loaded_transformers = json.loads(log_line_parts.message[len("Loaded transformers:"):].replace("'", '"'))
            # print(transformers)
        else:
            # print(log_line_parts.message)
            pass

    return rounds, loaded_transformers


def show_simple_stats(logfile, verbose=False):
    rounds, loaded_transformers = parse_log(logfile, verbose)
    transformer_count = {}
    best_transformers = []

    for idx in rounds:
        transformer_lines = rounds[idx]["transformers"]
        for transformer in transformer_lines:
            # print(transformer)
            if transformer.transformer not in transformer_count.keys():
                transformer_count[transformer.transformer] = 0
            transformer_count[transformer.transformer] += 1

        best_instance = rounds[idx]["best_instance"]

        if len(best_transformers) == 0:
            best_transformers.append(best_instance)
        # todo: make attack to output best of round
        #  getting best for attack here
        if ((best_transformers[-1].transformer != best_instance.transformer \
             or best_transformers[-1].arguments != best_instance.arguments \
             or best_transformers[-1].author != best_instance.author) \
            and float(best_transformers[-1].result) == float(best_instance.result)) \
                or float(best_transformers[-1].result) > float(best_instance.result):
            best_transformers.append(best_instance)

    print("transformers used to result:")
    for transformer in best_transformers:
        print(f"\t{transformer.transformer}")
    print()

    print(f"| {'Transformer':^35} | #successfull |")
    print(f"| {'-' * 35} | :{'-' * 10}: |")
    for transformer in sorted(transformer_count, key=lambda x: transformer_count[x], reverse=True):
        print(f"| {transformer:<35} | {transformer_count[transformer]:^12} |")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Parse important information for attacked authors")
    parser.add_argument(dest="LOGFILE", type=str, help="Logfile to parse")
    parser.add_argument("-v", "--verbose", action="store_true", help="Show more information")
    args = parser.parse_args()
    if not Path(args.LOGFILE).exists():
        print("File doesn't exists", file=sys.stderr)
        exit(1337)
    show_simple_stats(args.LOGFILE, args.verbose)
