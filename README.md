# Where's Waldo Project
This was a project for a computer vision course our group took. However, this project is incomplete because we decided to change projects.
Below is the write up of how far we got with this project.

# What We Tried to Accomplish:
We originally wanted to make a program that was capable of finding Waldo. Given a
“Where’s Waldo” image (aside from “World of Waldos”), we wanted to be able to identify
and locate Waldo. Waldo’s location would then be boxed on a copy of the input image
so it could be verified that the program managed to successfully locate Waldo.

# What We Did Accomplish:
Since this was our initial project, we were still familiarizing ourselves with opencv and
wanted to start small by getting a very basic working version of finding Waldo without
using any starter code. We managed to accomplish basic template matching that
successfully found Waldo. However, this approach only works on images that you
already have a template of Waldo for, so it would not work on new images.

The other ideas we had were using various techniques to isolate Waldo’s features and
using the help of a machine learning algorithm in order to identify Waldo. After going
through and zooming in on Waldo across several different images, we realized that
Waldo’s appearance was too inconsistent to isolate his features with any of the
techniques we were planning on using (such as colors, patterns, accessories, etc.).

Also, after looking through several hours of YouTube footage for other peoples’
approaches to finding Waldo, most of which used machine learning algorithms (although
there were others, such as SIFT), we didn’t find anything obviously promising based on
their results. Therefore we ended up deciding to move onto a different project.

# Results:
The current version of our Where’s Waldo project is able to produce the following results
using template matching (Waldo is boxed in black):

Example 1:

<img width="574" alt="Capture" src="https://user-images.githubusercontent.com/76569535/176113318-36a3ec05-ade3-429a-bfe8-20a9662586da.PNG">

It’s hard to tell without zooming in, but that is indeed Waldo boxed in the upper right
quadrant.

Example 2:

<img width="662" alt="Capture2" src="https://user-images.githubusercontent.com/76569535/176113406-e0105221-ef84-4e24-9a7c-962692b71604.PNG">

There is Waldo’s smiling face boxed on the left side in the middle.

# Lessons Learned:
● Investigate the problem first before making assumptions and investigating
potential approaches to the problem. This would have saved a lot of effort, since
some of our initial assumptions were wrong (and consequently the effort spent
investigating those approaches was wasted).

● Learned about some of the basic opencv methods available

● By using github as the tool to collaborate on our code, we learned more about
how github works.
