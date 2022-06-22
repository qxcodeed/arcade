#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import sys
from os.path import join, isfile
import subprocess

prefix = ""
if len(sys.argv) > 0:
    prefix = sys.argv[1]

cwd = os.getcwd()
hooks = sorted(d for d in os.listdir("base") if os.path.isdir(join("base", d)))
for hook in hooks:

    if not hook.startswith(prefix):
        continue
    base_path = join("base", hook)
    make_path = join(base_path, "Makefile")
    print(hook)
    if isfile(make_path):
        os.chdir(base_path)
        subprocess.run("make")
        os.chdir(cwd)
    else:
        os.chdir(base_path)
        subprocess.run(["tk", "run", "-p", "."])
        os.chdir(cwd)