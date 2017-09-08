# AutonoMoose Logbook 2017

## Background

AutonoMoose was started by Reilly, Joel and I in mid 2016. Both Reilly and Joel have aged out and are currently studying at The University of Tasmania. 

## The Phantom Project

As I write more and more code, I have realised that I am re-using a lot of my own code in many different projects. Almost all of my robots have used one of two types of motor controller, so why not just write a Class that is designed for ease of re-usability? The Phantom Project is a lightweight library of classes that eases the development process of robots and other electro-mechanical projects. The library includes everything from motor control and sensor interfacing, to more abstract functionality like task scheduling and software watchdog timers. The whole project is designed that once I get the time, I'll be able to port the library to other platforms like the popular Raspberry Pi family.

The project is open-source under the GPL-2.0 license and can be viewed on it's GitHub page (linked below).

(github.com/AutonoMooseTech/Phantom)[https://github.com/AutonoMooseTech/Phantom]

## Robot Design
Last year, something the team kept tripping up on was time management. Parts were ordered way too late and software development was left until the robots were finished. This year things are very different. Being on my own has posed some challenges, but I have made a few improvements to meet deadlines with better punctuality.

### Using CAD as an Investment
Having a finished CAD model of the robot completed before parts are even sourced gives the ability to virtually test-fit hardware which is a huge advantage when it comes to checking tollances. Last year I used a program called Rhinocerous to do most of the designing of the robots, but this year I have just recently switched to AutoCAD's Inventor as it is a much better when it comes to setting constraints and doing simulated stress tests on parts. Because I have my own 3D printer at home, it is very easy to rapidly prototype many of the parts on the robot and I have learnt a lot about different techniques of making 3D printed parts stronger.

### Part Sourcing
This year, the core parts for both robots were order weeks before even the RCJ season traditionally starts so that parts could be tested well before fitting on the robot. With many of the components that make up the AutonoMoose robots being sources from places like China and the USA, shipping times are extreemly long and it is not un-common for a part to take twice as long as advertised to arrive.


### Unit Testing Everything!
Unit testing is a process used primarily in software development where the project is split up into the smallest testable parts and individually tested. I have worked hard this year to apply this same methodology to the soccer robots. Once a part arrives in the mail, I setup a unit test for it and put it through its paces testing for any defects. Of the 8 motor controllers I had ordered, one of the had the driver chip put on backwards which I probably wouldn't had discovered if It weren't for the fact for unit tests.