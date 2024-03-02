import re
from pathlib import Path
from shutil import copy
from typing import List, Dict

import yaml

import Configuration as config
from evasion.EvasionAlgorithm import EvasionAlgorithm

ch = 1

threshold_sel: float = [1.0, 800][ch]  # <<< Choose
learn_method: str = ["RF", "RNN"][ch]  # <<< Choose
feature_method: str = ["Usenix", "CCS18"][ch]  # <<< Choose
expected_no_batches = 17  # only relevant if in batch mode
expected_no_problems = 8
evasion_algorithm: EvasionAlgorithm = EvasionAlgorithm.MCTS_Classic  # <<< Choose

output_dir: Path = Path(f"/code-imitator/dataset_advex_{learn_method}")
if not output_dir.exists():
    output_dir.mkdir(exist_ok=True)

dataset_path: Path = Path(config.datasetpath)
attack_dir: Path = Path(config.attackdirConfig)
attack_dir: Path = Path("/code-imitator/results/second")
not_attacked: Dict[str, List[str]] = {}
for p in attack_dir.iterdir():
    if re.match(f"^blackbox_[0-9_]+_{feature_method}_{learn_method}_{threshold_sel}_False_{evasion_algorithm.name}$",
                p.name):
        problem: str = p.name.split(feature_method)[0][len("blackbox_"):-1]
        advex_cnt = 0
        for author_dir in dataset_path.iterdir():
            author = author_dir.name
            out_author_dir = output_dir.joinpath(author)
            out_original = out_author_dir.joinpath(f"{problem}_{author}.c")
            out_adv_ex = out_author_dir.joinpath(f"{problem}_{author}_advex.c")
            if not out_author_dir.exists():
                out_author_dir.mkdir(exist_ok=True)

            if not p.joinpath(author).exists():
                if problem not in not_attacked.keys():
                    not_attacked[problem] = []
                filename = f"{problem}_{author}.c"
                not_attacked[problem].append(filename[:-2])
                copy(dataset_path.joinpath(author, filename), out_adv_ex)
                copy(dataset_path.joinpath(author, filename), out_original)
                continue
            for f in p.joinpath(author).iterdir():
                if not f.is_file():
                    continue
                if not f.suffix == ".c":
                    continue
                if f.name.endswith("_original.c"):
                    continue
                assert f.stat().st_size > 0, f"AdvEx {f} has no content"
                copy(f, out_adv_ex)
                copy(dataset_path.joinpath(author, f.name), out_original)
                advex_cnt += 1
        print(f"Found {advex_cnt} advex for problem {problem} ({len(not_attacked[problem])} not attacked)")
yaml.dump(not_attacked, open(output_dir.joinpath("not_attacked.yaml"), "w"))
print(dataset_path)
print(yaml.dump(not_attacked))
