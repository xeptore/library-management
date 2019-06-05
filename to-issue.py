#!/usr/bin/python3

issue_parts = input("Github issue title:").split()
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
print(result)

