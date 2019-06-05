#!/usr/bin/python3

import subprocess

issue_parts = input("Github issue title: ").split()
issue_name = issue_parts[:-1]
issue_id = issue_parts[len(issue_parts) - 1]
if issue_id[0] == "#":
    issue_id = issue_id[1:]
    issue_name = issue_parts[:-1]

if not str.isdigit(issue_id):
    issue_id = ""
    issue_name = issue_parts


concated_parts = "-".join(issue_name)

result = f"{issue_id}-{concated_parts}".lower().strip('-# ')

print(f"creating branch '{result}'...")
subprocess.run(["git", "checkout", "-b", result], capture_output=True)
print("branch created and switched to it.")

print("pushing to remote origin...")
subprocess.run(["git", "push", "-u", "origin", result], capture_output=True)
print("pushed to remote origin.")
