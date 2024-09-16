#!/usr/bin/env python3
from lib import processa

def main():
    line = input().split(" ")
    vet = [int(x) for x in line]
    processa(vet)

if __name__ == "__main__":
    main()
