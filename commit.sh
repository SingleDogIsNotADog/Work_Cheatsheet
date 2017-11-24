#! /bin/bash

show_status() {
	if git status | grep 'nothing to commit'; then
		return 1
	else
		echo "Changed files: "
		git status -s -u
		return 0
	fi
}

if ! show_status; then
	return
fi

echo "Is it ok[y|n]: "
read is_ok
if [ "$is_ok" != "y" ]; then
	return
fi

git add *
git commit -m "commit"
git push origin master
