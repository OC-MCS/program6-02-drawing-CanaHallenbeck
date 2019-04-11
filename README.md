# program6-02-drawing-CanaHallenbeck
program6-02-drawing-CanaHallenbeck created by GitHub Classroom   

From your comments: I’m fairly certain I wasn’t supposed to pass settings manager by reference as much as I did in 	since that counts as changing main and feels a bit duct-tape-y(?)   
Not sure where you're passing the mgr by reference, other than the one place.   

I spent a really, really long time struggling with the binary file’s read / write function – it kept 	doing weird stuff when I wrote file.open(“filename”, ios:: in | ios:: out | ios:: binary)   
Don't spend that long on something like this w/o getting help. When you open with both in/out flags, then it does change the behavior: if the file doesn't exist when you try the open, it won't fail, because you said you were going to do output to it. Also, when you write data to the file, this will cause it to *not* replace data like you want it to. To get behavior we want, you *have* to open it read-only when you're loading, then open it write-only when you're saving.   
Grade: 50/50 - good job! Let me know if you have questions on the above.   
