>> New Sample Repo
$ git init      // Creates the .git file

>> GIT_IGNORE
// https://help.github.com/articles/ignoring-files/
$ touch .gitignore

>> GIT_ATTRIBUTES
// https://git-scm.com/docs/gitattributes
$ touch .gitattributes
  // *._FILE_EXTENSION_ attr1 attr2 ...
  // FILE attr1 attr2 ...
  $ echo "* text=auto" >>.gitattributes
  $ rm .git/index     # Remove the index to force Git to
  $ git reset         # re-scan the working directory
  $ git status        # Show files that will be normalized
  $ git add -u
  $ git add .gitattributes
  $ git commit -m "Introduce end-of-line normalization"

>> Commit new changes (.gitignore/.gitattributes)
$ git add .gitignore .gitattributes
$ git commit -am "Initial Commit"
$ git log
commit 4c13afdcc7adaf5803718d0007405c92a1b2ea95
Author: yangc8128 <harpsbro2283@gmail.com>
Date:   Sun Jul 31 03:34:26 2016 -0700

    Initial Commit

>> Sample file
$ touch func.py
$ git add -A
$ git commit -am "Added an empty python file"
$ git log
  commit 61170bee472540ccb9c7bd0c725e4d678e323a03
  Author: yangc8128 <harpsbro2283@gmail.com>
  Date:   Sun Jul 31 03:44:24 2016 -0700

      Added an empty python file

  commit 4c13afdcc7adaf5803718d0007405c92a1b2ea95
  Author: yangc8128 <harpsbro2283@gmail.com>
  Date:   Sun Jul 31 03:34:26 2016 -0700

    Actual Initial Commit
    
>> Edit Sample file
$ vim func.py
$ git diff
  diff --git a/func.py b/func.py
  index e69de29..c8c4749 100644
  --- a/func.py
  +++ b/func.py
  @@ -0,0 +1,4 @@
  +def _max( a, b):
  +  if ( a > b ):
  +    return a;
  +  return b
  warning: LF will be replaced by CRLF in func.py.
  The file will have its original line endings in your working directory.

$ git add -A
$ git commit -am "Edit of func.py"
  [master warning: LF will be replaced by CRLF in func.py.
  The file will have its original line endings in your working directory.
  e458ea3] Edit of func.py
  warning: LF will be replaced by CRLF in func.py.
  The file will have its original line endings in your working directory.
   1 file changed, 4 insertions(+)

$ git log
  commit e458ea335a9ced9f4bc7bb9b109b0e980f17d5a7
  Author: yangc8128 <harpsbro2283@gmail.com>
  Date:   Fri Aug 12 17:17:39 2016 -0700

      Edit of func.py

  commit 61170bee472540ccb9c7bd0c725e4d678e323a03
  Author: yangc8128 <harpsbro2283@gmail.com>
  Date:   Sun Jul 31 03:44:24 2016 -0700

      Added an empty python file

  commit 4c13afdcc7adaf5803718d0007405c92a1b2ea95
  Author: yangc8128 <harpsbro2283@gmail.com>
  Date:   Sun Jul 31 03:34:26 2016 -0700

      Actual Initial Commit

=============================^Master^==========================================
>> New Branch
$ git branch beta
$ git branch
    beta
  * master
$ git checkout beta
  Switched to branch 'beta'
$ git branch
  * beta
    master

>> Modifying in branch
$ vim func.py
$ git add -A
  warning: LF will be replaced by CRLF in func.py.
  The file will have its original line endings in your working directory.

$ git commit -am "Initial beta commit"
  [beta warning: LF will be replaced by CRLF in func.py.
  The file will have its original line endings in your working directory.
  5ed2abc] Initial beta commit
  warning: LF will be replaced by CRLF in func.py.
  The file will have its original line endings in your working directory.
   1 file changed, 4 insertions(+), 1 deletion(-)

$ git log
  commit 5ed2abc4bbb15c0f6042f3aab84c30cf8e3703b3
  Author: yangc8128 <harpsbro2283@gmail.com>
  Date:   Fri Aug 12 17:48:06 2016 -0700

      Initial beta commit

  commit e458ea335a9ced9f4bc7bb9b109b0e980f17d5a7
  Author: yangc8128 <harpsbro2283@gmail.com>
  Date:   Fri Aug 12 17:17:39 2016 -0700

      Edit of func.py

  commit 61170bee472540ccb9c7bd0c725e4d678e323a03
  Author: yangc8128 <harpsbro2283@gmail.com>
  Date:   Sun Jul 31 03:44:24 2016 -0700

      Added an empty python file

  commit 4c13afdcc7adaf5803718d0007405c92a1b2ea95
  Author: yangc8128 <harpsbro2283@gmail.com>
  Date:   Sun Jul 31 03:34:26 2016 -0700

      Actual Initial Commit
=============================^Branch^==========================================
>> Merge Branch
$ git checkout master
$ git merge beta
  Updating e458ea3..5ed2abc
  Fast-forward
   func.py | 5 ++++-
   1 file changed, 4 insertions(+), 1 deletion(-)

$ git branch -d beta
  Deleted branch beta (was 5ed2abc).
=============================^Modify/Delete Branch^============================
