#!/bin/bash
cut -d: -f7 /etc/passwd | sort | uniq
