#!/bin/bash
cut -d: -f1,5 /etc/passwd | tr ':' '\t'
