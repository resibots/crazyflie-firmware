[33mcommit 3bbfb338c346e4a729b81914900f567a8289c9ee[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Fri Nov 8 16:47:54 2019 +0100

    Removed tracing test, finished simple TODOs

[33mcommit c6ed65b18ee90736cb631a1ee4e22a324dcaecf5[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Fri Nov 8 16:18:32 2019 +0100

    Final cleanup & comments

[33mcommit 10daa3bea1f351b8078a5a4658d8f8de9ea933dd[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Fri Nov 8 16:16:43 2019 +0100

    General cleanup & comments

[33mcommit 4c780e88b176ad99d3b5f7b9927e71037c07a372[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Fri Nov 8 15:31:21 2019 +0100

    Cleaner status declaration

[33mcommit 47f2b4450cec3328d811f870b4885c0ef1fdc213[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Fri Nov 8 14:39:42 2019 +0100

    Tracing packets done & tested!

[33mcommit 8ed7c4f80434a0bacf7c979e926cab2b6b454fc6[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Thu Nov 7 17:57:43 2019 +0100

    Created interface for tracing packets

[33mcommit cbe35b1c5231d9a3156410be7f9d109667b8f2d5[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Thu Nov 7 16:40:03 2019 +0100

    Behaviors cleanup & fixes

[33mcommit ae09c580ff2beb1dad85fd95920867631e80e120[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Thu Nov 7 15:55:10 2019 +0100

    Adjusted flight constants, protection forces, fixes & cleanup

[33mcommit 13e55d35e67d701b00b5affc2e35a547cc3d1da0[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Nov 6 18:04:11 2019 +0100

    base-to-drone bugfixes

[33mcommit b99a3a293288feaf7584b6a9f33efaf024145981[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Nov 6 17:39:01 2019 +0100

    Sending scans to base through relay

[33mcommit a440ca56d21301ddb80abda0031b0863e96373b5[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Nov 6 17:37:15 2019 +0100

    Now handles base-to-drone CRTP [big changes]

[33mcommit e75576d94a60278ff8cbd19fcacc114abcdb0883[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Nov 6 14:33:18 2019 +0100

    Compile option to disable status print

[33mcommit cd822e17606dcf9bae349ae8a6c34e14a1eeb5f6[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Nov 6 11:43:56 2019 +0100

    New status, drones now know who's CRTP connected

[33mcommit 27a126495b3fc93444494b50e16917011b5af8be[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Tue Nov 5 15:58:12 2019 +0100

    Can now send a CRTP packet from any drone (TODO keep track of connected drone)

[33mcommit 4cddbef11004c4aebffe778ce0c633a3aa2df774[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Mon Nov 4 17:25:01 2019 +0100

    Choosing final angle when scanning (NOT TESTED), new avoidance method (4 sensors, using the 2 at the front for left-right)

[33mcommit d8c2c83e2824f72c84b01c764f1614920443aa59[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Thu Oct 31 16:52:39 2019 +0100

    Drone can now scan the room! (90deg turn with multiranger)

[33mcommit 36a6f2a63508273994136121e7f7f489a4203d11[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Oct 30 18:56:16 2019 +0100

    CRTP can move any drone, (in)active state updates with NDrones

[33mcommit d5e5c21f1759008477e82c58b3753393f8e85eac[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Oct 30 15:17:41 2019 +0100

    Moved all tunnel code to a separate firmware folder

[33mcommit aba03299b06ecb22b32baba73129e3becdb5b90d[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Oct 30 15:06:52 2019 +0100

    Created tunnel_comm (separated ping & status)

[33mcommit 77f91eba2d7a752123b3cda9ccf6823247c5e4fe[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Oct 30 14:02:30 2019 +0100

    Cleaned relay submodule, removed tests & debug

[33mcommit 431fb2d86cae0c8d379f795d324b30cbec138b19[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Oct 30 11:43:53 2019 +0100

    [Working] Relay submodule done & tested! (keeping debugs for this commit)

[33mcommit 574846947abb296f5856ecfa08bd74c31b85490e[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Tue Oct 29 15:14:48 2019 +0100

    Now broadcasting status information + status in pings

[33mcommit c35bc32238419a071239712b840bba6f42496a1a[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Tue Oct 29 13:30:30 2019 +0100

    Relay test working, Auto refresh NDrones

[33mcommit 112c495e7b9aa4302255b79cb5cdc71711705386[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Mon Oct 28 17:17:59 2019 +0100

    Blinking blue LED when receiving P2P not for the drone's id, fixes

[33mcommit 7eb3ba2ef1a0d9e68625baf8b910d1f859bebadc[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Oct 23 14:34:58 2019 +0200

    Started align behavior

[33mcommit 52154e3cd102aac3c7542be4cadb04b3ed1cb489[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Oct 23 11:43:21 2019 +0200

    Merge branch 'tunnel_following'

[33mcommit e1b166c5f233d72a2f7f2dd536f54af5dd6be1cd[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Mon Oct 21 11:25:23 2019 +0200

    Relay submodule 'done' (not tested)

[33mcommit 4af7ed57d849ac95ea497626d8348dce65d2e8b6[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Fri Oct 18 18:13:15 2019 +0200

    Started implementing Relay protocol, main functions done

[33mcommit 446c2d5d197ccb6d1557f74e751fd0eae6fe05a3[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Fri Oct 18 18:12:04 2019 +0200

    Created Relay submodule

[33mcommit bf469909560c7e5cd33f874bd28951770d3034d8[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Fri Oct 18 15:13:39 2019 +0200

    Kalman refresh cooldown

[33mcommit ffa6510e7cc84166eddff2e8db44cecf1a2f5294[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Thu Oct 17 16:54:27 2019 +0200

    Saving all agents' RSSI last value

[33mcommit 26a0f400253efb22fe4f736232670b93d414fd52[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Thu Oct 17 15:54:47 2019 +0200

    Built RSSI Middle Behavior

[33mcommit bf9237d612976e2cb82a5a8bca5d5cdc8421a5e3[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Thu Oct 17 14:53:39 2019 +0200

    Cleaned Signal submodule

[33mcommit e88ee093addd902a48871fcb07e9ab6e14e0c88b[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Thu Oct 17 14:33:30 2019 +0200

    Base signal is now filtered

[33mcommit 53f9a7a186f38d2565c67a0ac32057ccaea3f112[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Thu Oct 17 14:12:03 2019 +0200

    Follower & Leader signals are now filtered

[33mcommit 2cd91c17e09d77f3d75a6fe0f019f3ffbed6994f[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Thu Oct 17 13:49:17 2019 +0200

    Global current movement in commander

[33mcommit 48ad4a6f3a202c3ded2004d97b66008039966657[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Thu Oct 17 13:15:17 2019 +0200

    New filtering submodule for follower, leader & base

[33mcommit 33bbbd24ee58a8aa44149e6a46434482124217c6[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Thu Oct 17 10:29:59 2019 +0200

    Height constraints

[33mcommit a857682f7d71473ed277134d3d3c3e49c65b9e5a[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Oct 16 17:42:54 2019 +0200

    Added proper CRTP commands, take off separated from canFly

[33mcommit 35f338ff14bc85371c3b8722efab31e66338efbe[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Oct 16 17:40:09 2019 +0200

    Defined drone states, leader&follower

[33mcommit a937ac686eecd8576f3c53b411a4d8547bc682bc[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Oct 16 15:46:45 2019 +0200

    Implemented Goto behavior

[33mcommit 5a3f44ae52d8efdf2d2260057eee8218187cdf40[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Oct 16 14:13:55 2019 +0200

    Left-right repulsion with 4 distance sensors

[33mcommit 71bc990af1c48207147d4e2149f5971dc85bc78a[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Oct 16 11:26:16 2019 +0200

    New 4-sensors avoiding method

[33mcommit 881cc0334fbe4b785c675cd5e4f807381af9510f[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Mon Oct 14 17:39:26 2019 +0200

    Basic yaw management for tunnel turns

[33mcommit 057b91d490e66509de09090540015ba514c784d4[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Mon Oct 14 14:06:00 2019 +0200

    Collisions disabled when taking off

[33mcommit 8345ca2b3e3bd2091e82a50b42a00451cab6009d[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Fri Oct 11 10:31:37 2019 +0200

    Now resetting kalman filter before taking off

[33mcommit ba7d4d2e32229ac6b4f3d98a6cc443fa3e9cb023[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Thu Oct 10 17:30:12 2019 +0200

    Built behavior & setpoint architecture, take off behavior now working

[33mcommit e3f7b07d639fb20bc0c954d6aa50cd86f11f70e9[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Thu Oct 10 15:05:04 2019 +0200

    Fixed force calculation for obstacle avoiding

[33mcommit 754738e066bc750d085fede19c699b0c3e7dd59f[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Thu Oct 10 11:25:49 2019 +0200

    tunnelCanFly gets broadcasted on CRTP change

[33mcommit c3e15cf2c8f395017ffe79969f4584d03fbf6b87[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Thu Oct 10 11:23:53 2019 +0200

    Better avoiding method, crtp teleop, better defines

[33mcommit 6f8c03e672840806c870af4470a0bbeeab2f4373[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Tue Oct 8 15:45:59 2019 +0200

    Red switch disables the motors until new CRTP CanFly

[33mcommit 0b05908a4d54157e02dd14c3d5b1947c1e4d3687[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Tue Oct 8 15:45:36 2019 +0200

    Basic left-right avoider functional

[33mcommit 647d455c03cd70fa34e99ab4165e0850edf16391[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Tue Oct 8 10:44:29 2019 +0200

    Created empty Behavior submodule

[33mcommit 9b0fbb0c323f64dba503ca069dc5141fc4409c3f[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Mon Oct 7 17:41:54 2019 +0200

    New CanFly oaram, enables the motors if true

[33mcommit 362706401d28d1ad1505cbe383ca52e6337e9054[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Mon Oct 7 17:24:26 2019 +0200

    Created Avoider submodule (example code for now)

[33mcommit 087f764b80ce6c6c59d815598df742707c8c7659[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Mon Oct 7 16:28:53 2019 +0200

    Created separate tunnel parameters submodule

[33mcommit 6d11f0ef143bf85ecee654322fcf5b59ff993e04[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Fri Oct 4 16:29:40 2019 +0200

    Header comments, increased TX power

[33mcommit d322847bbb7f1a9ca7fb802d25c964d211332fd4[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Fri Oct 4 15:50:34 2019 +0200

    Cleaned commander service (saparate file)

[33mcommit 9cf39ce63ddb04cc2a5948e4e96f76392ccdfd71[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Fri Oct 4 15:16:31 2019 +0200

    Cleaned ping service (separate files)

[33mcommit d66bca932b337203670af07590c2842537526ec4[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Fri Oct 4 10:21:50 2019 +0200

    Cleaner ping, rssis values and reports to PC

[33mcommit 7693199f4305238d510d77f9168c14857223e65c[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Oct 2 16:59:35 2019 +0200

    Basic propagating ping

[33mcommit 58925198ff37bcea070a3e6d90c8d51daa5d9503[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Tue Oct 1 17:25:50 2019 +0200

    Joined tunnel service with P2P communication, working!

[33mcommit c47d4db855b7803aafb3bd2a6fe80197c5156e78[m
Merge: f21f856 c78d985
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Tue Oct 1 13:28:14 2019 +0200

    Merge remote-tracking branch 'origin/p2p_communication' into cavemod

[33mcommit c78d9858fb088d2ba07444123c2d5281f60acacb[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Tue Oct 1 13:04:00 2019 +0200

    Created P2PPacket structure, now correctly setting packet size

[33mcommit fd1913d9d21400c4aa261728ad5d0c1fba4513de[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Thu Sep 19 17:51:31 2019 +0200

    STM32 Now receives P2P packets and stores them in appropriate P2PPacket port queues

[33mcommit f21f856a165f1d5b8dcf62b8e8cf9f54050d80e6[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Wed Sep 18 11:04:13 2019 +0200

    All tunnel code now in a module instead of a virtual deck (cleaner)

[33mcommit 790c02a14fb5e8142afa9e795b91a7023ba99ba7[m
Author: MadeInPierre <pielaclau@gmail.com>
Date:   Mon Sep 16 16:27:42 2019 +0200

    First tunnel centering behavior functional! Using a virtual deck driver

[33mcommit 941162db3ea5f39126eddf682421016f3ed7423c[m
Merge: a4bf399 d3bee1a
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Sep 10 10:24:27 2019 +0200

    Merge pull request #467 from NicksonYap/lh_fix_get_bs_pos
    
    get_bs_position - fix decode("utf-8")

[33mcommit a4bf3994b3eb002dda7334c82d7118e38c33ad86[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Tue Sep 10 09:03:22 2019 +0200

    Closes #469: Update lighthouse bitstream to V2

[33mcommit 6a3cf9f2a401823a6b971a56e4709be0a08f72d8[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Sep 9 15:38:59 2019 +0200

    #466 Refactoring

[33mcommit 6ebc99bf44151b552d729a9b11c4ebab574a7526[m
Merge: 5d835fd f9fe54a
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Sep 9 15:12:30 2019 +0200

    Merge pull request #466 from NicksonYap/led_rssi
    
    LED RSSI - turns white if disconnected (1 sec timeout)

[33mcommit d3bee1af329fccde05466acea1333a0edfb8985e[m
Author: NicksonYap <hi@nickson.me>
Date:   Mon Sep 9 06:44:55 2019 +0800

    get_bs_position - fix decode("utf-8")

[33mcommit f9fe54a69e960907536378293018b2ad07c83691[m
Author: Nickson <hi@nickson.me>
Date:   Fri Aug 23 10:07:09 2019 +0200

    LED Ring - RSSI Effect - turns white if disconnected

[33mcommit 7aa64ba6769e744f6d63fa6fa6eeed75dea8eba2[m
Author: Nickson <hi@nickson.me>
Date:   Fri Aug 23 10:06:35 2019 +0200

    #459 - params for radio link connectivity

[33mcommit 5d835fd142a7691080bd9d7e5b4f1b98a9a10408[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Sep 5 18:50:22 2019 +0200

    #464 Updated how IDs are written to the deck and added test that reads a version string from the deck to make sure it is responding.

[33mcommit ddfa840da21ccd136fc712b77d0bceeefc94feb4[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Aug 29 16:57:06 2019 +0200

    #464 Updated i2c address for active marker deck

[33mcommit 16683d9054fc54decef824419c3ee3487e7af8a3[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Aug 29 16:30:15 2019 +0200

    #464 Added initial version of the Active marker deck driver

[33mcommit b9c37ded68e57e35912a384ad84c85aa41223c61[m
Merge: fe5bb40 cc15a7a
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Aug 22 15:58:11 2019 +0200

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit fe5bb409ba7b1b4f904a536ef20c819bbffa9f61[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Aug 22 15:57:46 2019 +0200

    #458 Added kalman supervisor

[33mcommit cc15a7a92e81853b8ec8674eaa57429cf188d35e[m
Author: knmcguire <kimberly@bitcraze.io>
Date:   Thu Aug 22 14:39:42 2019 +0200

    #447 added alt attributes to images and fixed linking issues

[33mcommit 57028d7dd8aa8a4c3b916d6133a4b5f451049da3[m
Merge: 35176f1 2bbd654
Author: knmcguire <kimberly@bitcraze.io>
Date:   Thu Aug 22 14:22:04 2019 +0200

    Merge branch 'master' of https://github.com/bitcraze/crazyflie-firmware

[33mcommit 2bbd654fd73555bd57deabbf1b930d7bdf33c09f[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Aug 22 14:20:17 2019 +0200

    #457 Added same solution for params

[33mcommit 2a5981a166f91e560328e59be4152cb537f07eec[m
Merge: da8e0ad 4346a24
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Aug 22 13:57:33 2019 +0200

    Merge pull request #457 from collmot/fix/unit-tests-on-mac
    
    fix compilation of unit tests on macOS

[33mcommit 4346a24f000be5c26313d9ef6f9ae27cd918d77b[m
Author: Tamas Nepusz <ntamas@gmail.com>
Date:   Thu Aug 22 13:08:54 2019 +0200

    fix compilation of unit tests on macOS

[33mcommit 35176f1d8fc37ed2ddfd69ad5fde8db9aaa986ac[m
Author: knmcguire <kimberly@bitcraze.io>
Date:   Wed Aug 21 16:21:14 2019 +0200

    #447 updated image descriptions and checked links

[33mcommit da8e0ade373319eedc5b85fa6af79b416cb928ae[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Aug 21 11:26:40 2019 +0200

    #447 Updated urls and removed wrap tags

[33mcommit 62e0bf75626dd22a512694ae96dae44d04d09b2c[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Aug 20 15:00:29 2019 +0200

    #290 Refactored and fixed automatic mode scanning

[33mcommit 424477849c79b37bd9e07426b8eb65bb24603f87[m
Author: knmcguire <kimberly@bitcraze.io>
Date:   Wed Aug 14 14:50:52 2019 +0200

    #447 fixed links for deployment (still need to fix overview pages)

[33mcommit e5a775bffa5ce8cae302d9347230fe8f65485f1a[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Aug 13 18:19:28 2019 +0200

    #447 More updates of images and internal links

[33mcommit 0a5b06b09834219a9f71e6933b7a48c69355957a[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Aug 13 18:02:40 2019 +0200

    #447 Updated internal links and images

[33mcommit 05152a70db00c6ee181dc0bbdf8d8fca9e6208b5[m
Author: knmcguire <kimberly@bitcraze.io>
Date:   Tue Aug 13 13:53:16 2019 +0200

    #447 adding some extra doc pages on development

[33mcommit 3112896bdf49edba9caf5c702a5be9a5bfb38267[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Aug 13 10:19:30 2019 +0200

    #216 Converted line endings of existing files to UNIX style

[33mcommit 67e7f4d337fcd78f24b7c7fc1d07621354ef9ef2[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Aug 13 10:18:49 2019 +0200

    #216 Added .gitattributes file to make sure future commits use correct line endings

[33mcommit b2de256981a73485d78a53c5f3a02d79ca020f68[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Aug 12 17:23:33 2019 +0200

    #364 Wait for system to be fully started before running LED sequences

[33mcommit ea32e8cb1a04ac0c21a9c7c40c5e4e6433c37bc0[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Aug 12 16:28:28 2019 +0200

    Renamed variables. Closes #425

[33mcommit 821427e035d393b84bff27b1aac1a23bcaf3e7e6[m
Author: knmcguire <kimberly@bitcraze.io>
Date:   Mon Aug 12 16:15:40 2019 +0200

    #447 added ctrp docs from wiki to this repository

[33mcommit dfc621fa84f90a61dc46f51af6279a478e196be1[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Aug 12 14:49:25 2019 +0200

    Added support for %c in printf and fixed length bug for negative ints. Closes #432

[33mcommit c376b1058cb371c5e4f3a0780ad50b6a56146908[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Aug 7 14:34:49 2019 +0200

    #447 Added menu

[33mcommit 3220eadb63795e42f45c77be3f29d7bde076c210[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Aug 7 14:30:36 2019 +0200

    #447 Updated docs to new structure

[33mcommit b357e21a39c214b0ee1973d16510613da1c41c0a[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Aug 7 13:57:55 2019 +0200

    #448 Added counter for the number of motor tests that have been run. Replaces the test finished bit in motorPass

[33mcommit d6a0f228a2ca008dd62a20f464839170023e7bb4[m
Author: knmcguire <kimberly@bitcraze.io>
Date:   Tue Aug 6 12:50:40 2019 +0200

    [docs] fixed markdown typo in build instructions

[33mcommit b0b817143e34187ac6ab69744faccc7984d6fbb4[m
Author: knmcguire <kimberly@bitcraze.io>
Date:   Tue Aug 6 12:42:18 2019 +0200

    [docs] included some kind of logical structure for the documentation

[33mcommit ab082d5a4b904182f0f5f3fab3fbe97a603616d0[m
Author: knmcguire <kimberly@bitcraze.io>
Date:   Mon Aug 5 17:37:00 2019 +0200

    [docs] further simplifying for githubpages

[33mcommit cbaed207e28a287d727592349fa48e86e6ded1cd[m
Author: knmcguire <kimberly@bitcraze.io>
Date:   Mon Aug 5 15:31:29 2019 +0200

    [docs] converted wiki pages to markdown and made it compatible with githubpages

[33mcommit edc1ae504a64d025e2f9eab9f0cfc953c289e348[m
Merge: 04a4a58 1eb0cb1
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Aug 5 09:32:27 2019 +0200

    Merge pull request #449 from whoenig/bugfix-locSrv
    
    Fix issue in locSrv that can cause incorrect decoding of external

[33mcommit 04a4a5840022ad086e750a9aa04c7a6cfbfc6f1f[m
Merge: 0ae695a a37837f
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Aug 5 09:32:12 2019 +0200

    Merge pull request #450 from whoenig/bugfix-compressState
    
    Fix compressState acceleration values to be mm/s^2.

[33mcommit 0ae695ab84f4b528ad9965e6612bcd9142f3b687[m
Merge: 996b1fd aada41a
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Aug 5 09:30:55 2019 +0200

    Merge pull request #451 from whoenig/bugfix-yawAngleCtrl
    
    Add support to control the yaw angle (and not only rate).

[33mcommit aada41ad9730cae15be9e7713ab6a14237f4c0e9[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Fri Aug 2 09:42:02 2019 -0700

    Add support to control the yaw angle (and not only rate).
    
    Note that stabilizationModeYaw is in the firmware already, but
    was not used until now.

[33mcommit a37837feaa1f55105fbc1e0cea946e3d4736ecc6[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Fri Aug 2 09:38:57 2019 -0700

    Fix compressState acceleration values to be mm/s^2.

[33mcommit 1eb0cb1f2fda34401ef524247e9c69356cc54d86[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Fri Aug 2 09:27:40 2019 -0700

    Fix issue in locSrv that can cause incorrect decoding of external
    position or pose estimates.

[33mcommit 996b1fdcb60847d4cf0bbba238685b23e35204bf[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Jul 30 10:54:41 2019 +0200

    #448 Corrected motor test variances

[33mcommit 3603b76196282c4a837e32bff9a361a1285b33d7[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Jul 30 10:39:47 2019 +0200

    Added log variable for motor/propeller test results. Closes #448

[33mcommit 91ca40e7e1e81b4eebd0c631557f57885f68b934[m
Merge: 9ef2273 74022e5
Author: knmcguire <kimberly@bitcraze.io>
Date:   Thu Jul 25 17:47:11 2019 +0200

    Merge branch 'master' of https://github.com/bitcraze/crazyflie-firmware

[33mcommit 9ef2273e64d2e0a0287cfa84631589f477f2b568[m
Author: knmcguire <kimberly@bitcraze.io>
Date:   Thu Jul 25 17:47:02 2019 +0200

    #447 changed menu name to handle with the relative name bug

[33mcommit 74022e561470ce55e3a030de55f46ecd6e6713df[m
Author: knmcguire <kimberly@bitcraze.io>
Date:   Thu Jul 25 17:41:05 2019 +0200

    #447 update config file

[33mcommit bc07464eb899adbc760f1c53d8b6ed05c888195d[m
Author: knmcguire <kimberly@bitcraze.io>
Date:   Thu Jul 25 17:39:31 2019 +0200

    #447 moved .md pages

[33mcommit ad1401bf5d076e2a08830bcd93a15ea101d8c948[m
Author: knmcguire <kimberly@bitcraze.io>
Date:   Thu Jul 25 17:19:30 2019 +0200

    #447 update config.yml

[33mcommit 8874513adb4e4067d7e23b9d371d72962f34d54c[m
Author: knmcguire <kimberly@bitcraze.io>
Date:   Thu Jul 25 17:15:24 2019 +0200

    #447 update a file id

[33mcommit 0748912cbe4467a932e62096c24fe5f4a4923800[m
Author: knmcguire <kimberly@bitcraze.io>
Date:   Thu Jul 25 17:05:20 2019 +0200

    #446 changed config file jykell

[33mcommit e0bb9714088e48565c66e1bd4dffc2ba0ce0703c[m
Author: knmcguire <kimberly@bitcraze.io>
Date:   Thu Jul 25 16:56:07 2019 +0200

    #447 added an simple layout with index and several pages

[33mcommit 5e108e1992d50ca32e310e8ecce72fecc914730f[m
Author: knmcguire <kimberly@bitcraze.io>
Date:   Thu Jul 25 14:56:24 2019 +0200

    #447 added /doc folder and config files

[33mcommit 7a04c030c93524666c6df5b42f7150735d8b0d81[m
Merge: 87fbbfb af6642f
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Jul 24 10:16:11 2019 +0200

    Merge pull request #438 from whoenig/featureUSDdownload
    
    Support to read latest logging file from uSD card over radio

[33mcommit af6642f133fa3b8a89e5965db261220f5dc67517[m
Merge: 6e5cc31 87fbbfb
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Jul 24 10:12:32 2019 +0200

    Merge branch 'master' into featureUSDdownload

[33mcommit 87fbbfbc1979295e07ba6a052c1fe01589462856[m
Merge: d1fff16 a07e58f
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Jul 24 10:00:00 2019 +0200

    Merge pull request #445 from whoenig/feature_ekf_pose_update
    
    Implement full pose measurement in EKF.

[33mcommit a07e58f001701910a42c0698c8c59a970210e1b0[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Mon Jul 15 17:29:18 2019 -0700

    Implement full pose measurement in EKF.
    
    This adds two new messages to the crtp_localization_service to
    receive external pose information (compressed and not compressed)
    such as information obtained by a motion capture system. (Fixes
    issue #203).
    
    It also adds a full pose update in the EKF using a scalar update
    for both position and orientation errors. (Fixes issue #246).
    
    Tested with the Crazyswarm using a single Crazyflie and a VICON
    motion capture system.

[33mcommit 6e5cc31a5c53db38f0fa0bcd384a3d3bf2ba6973[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Mon Jul 15 17:13:35 2019 -0700

    uSD logging: Fix issue with empty log files.
    
    If logging is enabled/disabled at runtime, sometimes empty log
    files were created. This adds an additional check to only write
    a new file if logging is enabled.

[33mcommit d1fff167ce73647be9e93d2196a001e1d27816c5[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Tue Jul 2 19:05:20 2019 +0200

     #384: Add log var. to detect Lightouse comm sync

[33mcommit 0f71a82ae63a84442a224f7620797e5bda900d92[m
Merge: 2a67c32 6f52ad2
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Tue Jul 2 18:36:13 2019 +0200

    Merge pull request #441 from jungr-ait/master
    
    Fixes #418: compilation error due to isspace() in usddeck.c

[33mcommit 6f52ad2bf2f052182dcfbea166620f13fa81ba40[m
Author: rojung <roland.jung@aau.at>
Date:   Tue Jul 2 09:44:34 2019 +0200

    Fixes #418: compilation error due to isspace() in usddeck.c
    
    HINT: On Ubuntu 16.04 it resolves the error: array subscript has type
    'char' [-Werror=char-subscripts] as all warnings are treated as errors.

[33mcommit 2a67c32402200a23494be7701000f1edcfce00cd[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Mon Jul 1 11:41:16 2019 +0200

    Fixes #439: Add Lighthouse deck init parameter

[33mcommit 0d305b267404fe1499bc783ec26cca9225dea9cd[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Mon Jun 24 21:04:33 2019 -0700

    Support to read latest logging file from uSD card over radio
    
    This change adds a new memory type (USD), which maps to the last
    logging file on the microSD card. The file can be read over the
    radio if logging is disabled (i.e., usd.logging is set to 0).
    
    Tested with downloadUSDLogfile from crazyflie_tools with and
    without the uSD-card deck using a CF2.0.

[33mcommit fd18d164cb423344a4a75487831ac2e6c37a518a[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Jun 18 13:22:44 2019 +0200

    #406 Added initial yaw for the kalman estimator
    
    The initial yaw can be set through the kalman.initialYaw parameter. The initial yaw is used to initialize the estimator when the Crzyflie is not oriented in the positive X direction.
    
    Initial Yaw is set in radians where:
    0: facing positive X (default)
    PI / 2: facing positive Y
    PI: facing negative X
    3 * PI / 2: facing negative Y
    
    Note: initial yaw takes effect after the kalman filter is reset.

[33mcommit 00e0fcf022c4df63ef326dfa574227ca87f5835d[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed Jun 5 16:25:31 2019 +0200

    Closes #434: Increase CRTP RX port queue size
    
    Also add an assert on packet lost

[33mcommit b50683fca09a794f517b0b7a280aa8d7c52d38a5[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed Jun 5 15:52:32 2019 +0200

     #393: Restore sending data on USB dataIn
    
    Improves transfer rate

[33mcommit 6b2f91f25f3fb59abbf92fed6025451df876592b[m
Merge: 1becef7 7587ba2
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Jun 5 14:43:29 2019 +0200

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit 1becef7ca990a4c1a5d26ad4256b9e962d2b8ac4[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Jun 5 13:41:01 2019 +0200

    Improvements on USB communication, fixes #393

[33mcommit 7587ba2c8aa9c15763b55a9d3ef2488a85ece1de[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Jun 4 12:03:03 2019 +0200

    #433 Added memory sub system tester

[33mcommit 24de9899cfdf9c4cd3708f041675f2f808b78ec9[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed May 15 16:22:40 2019 +0200

    Fixes #431: Check full LH deck firmware at startup

[33mcommit dd611cea4b1c13463ac3384580c9756900fd70b2[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed May 15 15:50:32 2019 +0200

     #431: Mitigate LH deck startup bug by adding a force_flash flag

[33mcommit a3763b54e4a9f47885ee586e111563d7eee7f2c6[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed May 15 11:11:21 2019 +0200

    #430 Restored disable flag for lighthouse code

[33mcommit 090e19e44bb8fba7eb2409c9113c91b5535e67aa[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Tue May 14 09:06:12 2019 +0200

     #430: Add outlier detector for frame width

[33mcommit dd604c5693f147a252a334becdcab137bfa8a2b8[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Mon May 13 10:57:54 2019 +0200

     #430: Fix test for pulseProcessor

[33mcommit 1ac61ab00b4859891c89d2ca1254162913e2e8e1[m
Merge: 16a38f7 a7f5dfe
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Mon May 13 08:44:54 2019 +0200

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit 16a38f72d2c429b5dd82b39f7cbeeac6675c7f66[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Mon May 13 08:44:51 2019 +0200

     #430: Fix test for pulseProcessor

[33mcommit a7f5dfecd61078c69d37541bc6078c3b604292d4[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri May 10 16:57:12 2019 +0200

    #430 Corrected logging of sensor 2

[33mcommit f92f7e1bf50eb0b833a92d01687b86beede02044[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Fri May 10 16:27:17 2019 +0200

     #430: Receive and use LH BS calibration
    
    Also change the way the angle is calulated to use the measured frame
    length instead of fixed number.

[33mcommit 28c33c1549bc864994183a2b19b72f4998395c76[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri May 3 10:05:18 2019 +0200

    Corrected log variables for the lighthouse. Closes #429

[33mcommit f1011f1f97f2decc61e3f35473c2e62438cf0e70[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Fri May 3 09:41:14 2019 +0200

    Fix clearing of USB fifo empty interrupt and clear queues on disconnect (#393)

[33mcommit ede7efef7c3ea0c18947b73b5ef5c595cf2fa8d9[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Fri May 3 09:39:57 2019 +0200

    Set radio link to disconnected after 1000ms, will clear logblocks (#428)

[33mcommit dbb8feb595a96c127d3283dfbb7e8a3e3483a2f9[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri May 3 09:31:20 2019 +0200

    #427 Corrected order in struct for LH geometry data and set it to packed

[33mcommit 237199732a3d9c565835de31d923315acbf49915[m
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Thu May 2 17:15:24 2019 +0200

    #423 Added DMA Tx functions to UART1 & UART2.
    
    The DMA functions will free up CPU time as it will not wait in a
    spin-loop. The DMA stream for UART1 conflicts with CF-RZR SPI2 so this
    can not be used together, thus the UART1 DMA functionality has to be
    enabled with ENABLE_UART1_DMA. The functionality has been tested with
    uart1test.c and uart2test.c.

[33mcommit 3b25f15e250cf8771d03cca91512f5c2ae85c494[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Apr 30 16:19:28 2019 +0200

    Added memory mapping for lighthouse base station geometry. Closes #427

[33mcommit 8e6e1dd22f2262d1d22dc468175cc67d46427ba8[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Mon Apr 29 14:50:37 2019 +0200

     #384: Add code to flash lighthouse  deck SPI mem
    
    Code used in production only

[33mcommit ebf447ee94f524ddf28cccdd7032ff4126f079cc[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Apr 12 17:16:27 2019 +0200

    #320 Separated kalman filter implementation from OS specific code such as queues.

[33mcommit b683c9641873af76335677f10bd12267bb2492ea[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Apr 10 14:12:57 2019 +0200

    Correction for build problem introduced in #377

[33mcommit 7d9ef1b411afde888793af14d5a3c1924202da3d[m
Merge: 1cdfbca 7bb627d
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Fri Apr 5 10:18:38 2019 +0200

    Merge pull request #421 from whoenig/feature_update_math3d
    
    Update math3d library to the latest version.

[33mcommit 7bb627d5fe24949a0739fc7db8f3f33e027a7bb8[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Thu Apr 4 16:24:13 2019 -0700

    Update math3d library to the latest version.
    
    94f08dd from https://github.com/jpreiss/cmath3d
    
    This includes some more consistent naming as well as avoiding
    some unnecessary double promotion.

[33mcommit 1cdfbcae5c20fc12cf1806f78279c6f75b053044[m
Merge: 37e98de a1790c6
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Thu Apr 4 09:33:07 2019 +0200

    Merge pull request #420 from whoenig/feature_compressedState
    
    Add logging variables for compressed state and setpoint.

[33mcommit 37e98decaf5ed34663ebdc659a45affc4c8cba58[m
Merge: 0583fa6 210cbd0
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Thu Apr 4 09:20:30 2019 +0200

    Merge pull request #419 from whoenig/feature_segger_rtt
    
    Add support for DEBUG_PRINT using SEGGER RTT

[33mcommit a1790c6c50346f6ec163bd9dc1e6525aade55f4d[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Wed Apr 3 13:46:52 2019 -0700

    Add logging variables for compressed state and setpoint.
    
    This will allow to create a log block that can capture position,
    orientation (and if desired vel/acc) in a single, time-syncronized
    block. That is important for accurate pose reporting (e.g., for
    roadrunner, or for CFs that are not controlled with external
    mocap).
    
    The compressed setpoint allows to capture both estimated and
    desired pose, which is important to compute metrics such as
    tracking errors.

[33mcommit 210cbd0829f14e9cbc5413e6396e4b530607393d[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Mon Apr 1 16:19:20 2019 -0700

    Add support for DEBUG_PRINT using SEGGER RTT
    
    Segger Real Time Transfer (RTT) is a high-speed protocol that can
    be used with JLink debug probes. It allows to exchange data much
    faster than radio or uart by using shared memory and SWO. It can
    be used for debugging (printing inside interrupt routines works fine)
    or sensor data collection (as long as the CF is connected via debug
    cable).
    
    Tested with JLink EDU Mini and CF2.0.

[33mcommit 0583fa65062c17a1276038d3f1492c15ff030b36[m
Merge: 7492b6e 0f85a4b
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Mar 28 08:40:37 2019 +0100

    Merge pull request #414 from whoenig/feature_synchronousLogging
    
    uSD card: Add synchronous logging mode.

[33mcommit 7492b6e7af68e2ab0083e45578933f1c6461f393[m
Merge: f2a8172 ee72a3f
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Mar 28 08:25:01 2019 +0100

    Merge pull request #415 from whoenig/bugfix_issue409
    
    Fixes a bug for extPos msg introduced in PR408.

[33mcommit f2a8172fb3d40a6726e35453485d5991d84925f2[m
Merge: acb978f 59ff7ca
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Mar 28 08:24:09 2019 +0100

    Merge pull request #416 from whoenig/bugfix_gitignore
    
    Add __pycache__ to .gitignore

[33mcommit acb978f8b33308f04020aaf6a8b938c23a30429a[m
Merge: d76981f db78646
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Mar 28 08:23:02 2019 +0100

    Merge pull request #417 from whoenig/bugfix_issue407
    
    Planner: Add check to avoid division by 0 for goTo commands.

[33mcommit d76981ff53036850ec6f0fc39c0d37a2780f6012[m
Merge: 76251a2 262fff1
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Mar 28 08:18:57 2019 +0100

    Merge pull request #413 from whoenig/feature_printCalib
    
    Add status messages in stabilizer for sensor calibration

[33mcommit db7864651adf0062e4005435e9451d0b0d0180ef[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Wed Mar 27 18:30:04 2019 -0700

    Planner: Add check to avoid division by 0 for goTo commands.

[33mcommit 59ff7ca796527398862a8ed5a04d69c5535eca51[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Mon Mar 25 17:33:11 2019 -0700

    Add __pycache__ to .gitignore
    
    This cleans git status for python scripts such as the ones used in
    tools/usdlog for example.

[33mcommit ee72a3f62db91429c3a4489bd8b03a4a0a9c4c06[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Mon Mar 25 16:15:08 2019 -0700

    Fixes a bug for extPos msg introduced in PR408.
    
    This fixes issue #409. Tested with CF 2.0 and crazyflie_ros.

[33mcommit 0f85a4b7bcf1988c08404e45e88609de232fe462[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Mon Mar 25 14:17:56 2019 -0700

    uSD card: Add synchronous logging mode.
    
    The synchronous logging mode can log variables synchronously in the
    stabilizer loop. This helps to analyze flight crashes etc. where
    the order and consistency between variables is crucial. The older
    (asynchronous mode) is retained, although the config file format
    changed slightly.
    
    Tested on a CF 2.0 (both synchronous and asynchronous modes using
    the config.txt that is part of this repository.)

[33mcommit 262fff1031dd85d3b40eb8bc4d446359a5d30d92[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Mon Mar 25 13:30:18 2019 -0700

    Add status messages in stabilizer for sensor calibration
    
    This helps debug cases where the CF is not taking off, because
    the sensors were not (yet) successfully calibrated without the need
    of analyzing the blinking pattern of the LEDs.

[33mcommit 76251a214d24e06ff8dfff6476d8dc2b69857369[m
Merge: c06980d e040b94
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Mon Mar 25 11:24:48 2019 +0100

    Merge pull request #410 from whoenig/fix_readme1804
    
    Update readme for Ubuntu 18.04

[33mcommit c06980ddda97c9a8d8af97b8bb7a8f58ccd8e90c[m
Merge: 481c412 db64172
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Mon Mar 25 11:23:24 2019 +0100

    Merge pull request #411 from whoenig/feature_devTypeQuery
    
    Add getDeviceTypeName to platform service.

[33mcommit 481c412c63fa8dfd14da227cb03e40b1e0e5ac70[m
Merge: b2f01ff 8113352
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Mon Mar 25 11:07:45 2019 +0100

    Merge pull request #412 from whoenig/feature_usdComments
    
    uSD: Allow comments in config.txt

[33mcommit 81133521123384016ff00ee0cbe6d62a103a2cdb[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Sat Mar 23 16:16:07 2019 -0700

    uSD: Allow comments in config.txt
    
    This change allows comments (#) and whitespace in config.txt
    used for logging data on a uSD card. This will be in particular
    useful as we add more features to config.txt in the future.

[33mcommit db6417289a1a5c001236dfc1caf165cf0300c359[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Fri Mar 22 15:46:30 2019 -0700

    Add getDeviceTypeName to platform service.
    
    This will allow us to change the client behavior based on the device type.
    Tested with CF 2.0, CF 2.1, RR 1.0 using crazyflie_tools/version.

[33mcommit e040b94fcc2ffb9a698b3e7150ad97351088ba22[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Fri Mar 22 12:50:47 2019 -0700

    Update readme for Ubuntu 18.04

[33mcommit b2f01ff74838f105aad618b280d988067946beaa[m
Merge: 0d4e6e2 acd9444
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Tue Mar 19 15:15:52 2019 +0100

    Merge pull request #408 from whoenig/featureSimplifyLocSrv
    
    Simplify logic for external position information.

[33mcommit 0d4e6e2dd09344bb5e437ae8744a252f6c09dc1e[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Mar 19 08:55:13 2019 +0100

    #403 Removed double includes

[33mcommit acd9444468f856ad0b23d25ccd334418159e814d[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Mon Mar 18 16:22:20 2019 -0700

    Simplify logic for external position information.
    
    Tested with the Crazyswarm using a VICON Mocap.

[33mcommit 624dcfb1a385e300a5f0bcf10d595479dc6b500d[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Mar 15 17:05:40 2019 +0100

    #403 Corrected function name

[33mcommit f1dc4c61d6c405cb8a7c7b73d7d87aa663ebf7ed[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Mar 15 16:20:03 2019 +0100

    #403 Added functions to the estimator to push sensor data into it. This breaks the wide spread dependency on the kalman filter.

[33mcommit 39682bb9a9b50c189ede65335019351e0625309c[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Mar 15 15:20:57 2019 +0100

    #397 Added build of the lighthouse deck driver to the travis build

[33mcommit 435c49a13cadc2d6f4cc2f2374a168aaa9457c81[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Mar 15 15:06:59 2019 +0100

    #405 Added missing arguments and added defines to travis build to make sure the code is built

[33mcommit 07b75945d39737dd71bb6d4c968a5d4222211d8f[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Fri Mar 15 08:39:34 2019 +0100

     #401: Detect BS mode and order them correctly

[33mcommit 741a7860aa1934fc74af679ba793187d4016c116[m
Merge: bd400b4 1a45a51
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Mon Mar 11 14:19:45 2019 +0100

    Merge pull request #404 from guglie/outlier-filter-fix
    
    Fixed typo in TDoA outlier filter function

[33mcommit 1a45a51510f0f8f848806ac9277c513491585321[m
Author: Guglielmo <gdguglie@gmail.com>
Date:   Mon Mar 11 13:57:04 2019 +0100

    fix typo in outlierFilter.h

[33mcommit bd400b4e2be3b5cd29071c5b5dea909b1b82fc98[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Mar 11 13:56:42 2019 +0100

    Set initial position of the kalman filter to (0.0, 0.0, 0.0). Closes #402

[33mcommit 0cc513a218422a203635c345d119a842f0cd5745[m
Author: Guglielmo <gdguglie@gmail.com>
Date:   Mon Mar 11 11:09:30 2019 +0100

    Fixed typo in TDoA outlier filter function

[33mcommit 967ab7d04d63f92e358438dae1e0e910d962cdff[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Thu Mar 7 15:43:29 2019 +0100

    Closes #401: Add script to get LH Basestation pose
    
    Also update ligghouse deck orientation: Crazyflie positive X is VR
    negative Z.

[33mcommit 9aea697cc1609ac3e84485eed9969b9e17d03912[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Mon Mar 4 17:44:53 2019 +0100

     #397: Implement version comparison and disable LH driver by default

[33mcommit 467742c674e8abebd4bdcd1924ad5658fe31c9cd[m
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Mon Feb 25 11:35:27 2019 +0100

    Fixed build error #397

[33mcommit 3f51823df67d02a0f734b91fc3a6564d994449f7[m
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Mon Feb 25 11:19:00 2019 +0100

    Cleaned up the lightouse bootloader driver a bit. #397

[33mcommit d8fcb17d6bd9fd3a496628e5801b52a53505baee[m
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Fri Feb 22 15:43:54 2019 +0100

    Draft lighthouse bootloader driver working. #397
    
    I2C interface updated as well which resulted in a lot of changed files.

[33mcommit e998ddc96bd946eca936527fec6767063875ba14[m
Merge: 35df4d7 551fe2c
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Tue Feb 19 07:44:51 2019 +0100

    Merge pull request #395 from kant/patch-1
    
    Fixed typos on string #138 & 143

[33mcommit 551fe2c03d874c6c3629f354b541c7fdb61b605e[m
Author: Darío Hereñú <magallania@gmail.com>
Date:   Mon Feb 18 17:08:27 2019 -0300

    Fixed typos on string #138 & 143
    
    * plus minor formatting proposals

[33mcommit 35df4d727111621af902d7029f76b39b406c17e8[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Feb 14 15:26:19 2019 +0100

    #379 Minor updates of documentation for CF 2.X

[33mcommit 1762deae7f251701cf996960b0ef037b3a7f6ac9[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Feb 11 15:33:21 2019 +0100

    Improved logging during initialization to show the installed decks as well as which estimator and controller that is active by name. Closes #390

[33mcommit c78082d44a1f568b9e001e602dd9609e64b65408[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Feb 11 14:13:19 2019 +0100

    Updated version printing to work with new release tools. Closes #377
    
    The version is now displayed differently for production builds to make it clearer that it is an official build.

[33mcommit d8d92d1ac7dafe6921912666efbea0c696890b0b[m
Merge: 3c1d0fe a1d5aac
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Thu Jan 31 14:35:22 2019 +0100

    Merge branch 'master' of https://github.com/bitcraze/crazyflie-firmware.git

[33mcommit 3c1d0fe1b16f495842c03ebd8f68059359d6fb5c[m
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Thu Jan 31 14:35:06 2019 +0100

    Added UART2 RX functions and a uart deck test. Closes #388
    
    Also found out that adding a deck driver with DECK_FORCE does not
    work if the deck driver doesn't implement init while it is acctualy
    ok to only implement test, so added this.

[33mcommit a1d5aac6f3e6f3691a270c81c5df9521a896c8c5[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Jan 23 21:45:09 2019 +0100

    Added Jenkins file for release builds

[33mcommit a17451bc70b780da2d4b27914d0f14de7bfc5d62[m
Merge: 90ea0cd 11553fc
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Thu Jan 17 21:09:59 2019 +0100

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit 90ea0cd6f30246f9ccea8f85c3ce9078628c7d19[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Thu Jan 17 21:09:17 2019 +0100

    LH4: Add isInit to prevent driver from being initialized twice

[33mcommit 11553fc58bf3ac45848e9255b04fbb6fecf9e7c6[m
Merge: 7b0041f 73bd5f8
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Wed Jan 16 11:14:38 2019 +0100

    Merge pull request #386 from CloudyPadmal/amg8833
    
    feat: AMG8833 Thermal Camera

[33mcommit 7b0041f2edb7218c64575c883105c701b03ed83b[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Tue Jan 15 13:29:27 2019 +0100

     #387: Change default radio datarate to 2M

[33mcommit 73bd5f8ee8343c453db589b7516c63b2ee42c9eb[m
Author: CloudyPadmal <blog.padmal@gmail.com>
Date:   Mon Jan 14 12:17:39 2019 +0530

    feat: AMG8833 Thermal Camera
    
    indentation fixes

[33mcommit f63020a5767aa748a9b39f909ebe69eb2e2b91f6[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed Dec 19 15:09:26 2018 +0100

     #384: Update LH positions

[33mcommit 50310682542fdfcffd785e2089bf2c14ff60afcf[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Dec 19 14:55:20 2018 +0100

    #384 Check data before feeding it to the estimator

[33mcommit b3b4589c704c341e18e5f8c5dfd9a17133c54bdc[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Tue Dec 18 17:57:05 2018 +0100

     #384: Update Lighthouse driver vid/pid/name

[33mcommit a203d748e139b82854059423e04bed7b0992ebd8[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Dec 12 14:36:57 2018 +0100

    #379 Updated release scripts to build all platforms

[33mcommit 963d2319bed987e02e0455dae4f18d3b6540ee8c[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed Dec 12 13:19:20 2018 +0100

    Closes #384: Add pulse width log to lighthouse deck driver

[33mcommit e27a305dc396387e0a7a91205169ffc8795bf069[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Dec 12 13:15:40 2018 +0100

    #384 Updated pulse length of Lighthouse tester deck

[33mcommit ca8b33b0ee86d4f0154572af1dc215be48712ff9[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Dec 12 10:40:56 2018 +0100

    #384 Added deck driver for lighthouse tester deck

[33mcommit d58760e7446ccdd59dd4c6481d3c04c67396cbd8[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Dec 5 16:22:26 2018 +0100

    #382 Use data from all sensors when estimating position

[33mcommit a9883018ad1ed99287f73c1dcfbc55c927761331[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Dec 5 15:52:50 2018 +0100

    #382 Break loop as soon as possible when looking for sync sequence

[33mcommit 27b6f16769db480fb0dd46d7438855ff0be4cc85[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed Dec 5 15:29:52 2018 +0100

     #382: Relax frame length tolerance to fit reality

[33mcommit 9bd15c4ee895e20f1ba63aac7702c446b8e5a5fe[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed Dec 5 15:29:16 2018 +0100

     #382: Fix lock-up after synchronization

[33mcommit 4fc3ce08871e664106bcaa96f71f8ac457b10263[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Dec 5 09:53:59 2018 +0100

    #382 Added stats to the lighthouse driver

[33mcommit d4e45bc8b059da51421d7fc9f6a4d8bb5dec12b9[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Dec 4 14:42:47 2018 +0100

    #382 Re-worked the lighthouse sensor processing to support multiple sensors

[33mcommit 2c637704ece0c568037e501066356c4204b57df2[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Tue Dec 4 14:05:14 2018 +0100

    #382: Fix isSinc to detect when there is missmatch between sync0 & 1

[33mcommit 7723d8366c66ba0fbf1ebabce31270b08fb7ba39[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Tue Dec 4 11:05:41 2018 +0100

    #382: Fix and unit test isSync LH1 sync pulse detection function

[33mcommit 761658ee4aa73deffb06271845d1a40c726d8be2[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Dec 4 09:54:11 2018 +0100

    #382 Reset pulse history when pulse buffer is full

[33mcommit d6bb1dd521bae4b31b1de6657696ddd69f8c0512[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Mon Dec 3 15:25:28 2018 +0100

     #382:  Update baudrate for link to the deck

[33mcommit e0a0e2fbb906904f3cd649ec4af505ce46f8b30f[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Mon Dec 3 12:36:36 2018 +0100

     #382: Use synchronisation to classify pulses

[33mcommit 43b6c25db2ee8fff84d97f4ffef1b5c1f2a63e3d[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 28 17:20:16 2018 +0100

    #382 Refactoring to reduce warnings in unit tests

[33mcommit d321158fe5d45ca2d9f457fa692c2f6c3cf0c93d[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 28 16:43:28 2018 +0100

    #382 Refactoring

[33mcommit de933eaf96ff73cbe1ae93334022761512142d98[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 28 15:02:29 2018 +0100

    #382 Added test support header file.

[33mcommit 94ac1a8b0885147fda85aed6e0f88690f1655fbc[m
Merge: a4b8e74 95f491a
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Tue Nov 27 09:55:50 2018 +0100

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit a4b8e74dc9c9615e4280c95cebd097eab1939548[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Tue Nov 27 09:55:46 2018 +0100

     #382: Use new LH sync function to synchronize LHv1 receiver

[33mcommit 95f491a57767d4d52e6d453f60c50cf50fbe41af[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sat Nov 24 08:17:41 2018 +0100

    #379 Added missing clean in travis file

[33mcommit 56c623ca288b23d28261ab74bd8c8edabf173c0a[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sat Nov 24 07:53:31 2018 +0100

    #379 Updated gitignore for tag binaries

[33mcommit 59b6b85d6684f362e3a38e18c2f0f531af62d973[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Nov 23 18:01:34 2018 +0100

    #379 Added missing file and updated tests

[33mcommit 3d23111261d79104061d6538eaa6dcad2a8014f9[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Nov 23 17:31:39 2018 +0100

    #379 Added support for the Tag platform and the Roadrunner device. Refactoring of platform startup code.

[33mcommit b0b6e60a11994169d3f067be9aa1338f5eb033fa[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed Nov 21 17:49:18 2018 +0100

     #382: Lighthouse: Implement Sync0 calculation from multiple sensors

[33mcommit fc0b5635ea4e619c1600d66f0fbfe5c6f26f8a5d[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed Nov 21 16:12:33 2018 +0100

     #382: Implement synchronizing function for Lighthouse V1

[33mcommit 5cec953f3ce3f81ae5dc28dab2cd1ef57111be7c[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 14 19:27:12 2018 +0100

    #379 Corrected unit test

[33mcommit 7fb1ecbd46198d300cdd3f5238c4a7b86d4a70ba[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 14 19:17:04 2018 +0100

    #379 Refactoring

[33mcommit cf868ac2ed9c8ae4af4c8add7cfedf219e6bd5fd[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 14 17:59:27 2018 +0100

    #379 Do not include forced sensors file if it already is part of the platform

[33mcommit 765c05de0bd68700ea6cfa361af8180c72489fc1[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 14 17:45:13 2018 +0100

    #379 Added missing files

[33mcommit 6d895b9052414924b50f0b7f58ae7f96a60439b8[m
Merge: 17e275b 3ff9ffc
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 14 17:30:54 2018 +0100

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit 17e275b76128be067cbfb46548d93b846d6a1024[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 14 15:15:55 2018 +0100

    #379 Dynamically selecting sensors based on device type

[33mcommit 3ff9ffc534b1d45fe340b9b93b509cd5f34015df[m
Merge: 893d50e be5b983
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Nov 14 17:10:30 2018 +0100

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit 893d50ecbb7f0258300c1a2d8e865e5ffa27bc35[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Nov 14 17:09:38 2018 +0100

    Do not fail multiranger test on multiple calls (closes #381)

[33mcommit be5b983971d0188344ec721c4100d04b09ad08b7[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed Nov 14 11:42:33 2018 +0100

     #379: Add platform support to Makefile and remove CF1 support

[33mcommit 62dc452edafb6e9cd4a7dc43940e52473710c150[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Nov 13 16:53:30 2018 +0100

    #379 Removed P_NAME, unused

[33mcommit 8224e284b0e8f3bd6012e080413172f330e20f8e[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Nov 13 16:25:45 2018 +0100

    #379 Added dynamic configurations
    
    Identifying the device type based on the device type string and choosing the correct configuration.

[33mcommit 70c2225383de7d54295322194f8edc7a0f9a7093[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 7 17:19:48 2018 +0100

    #379 Added driver to read platform string on a STM32 platform

[33mcommit e80624829031d1c5943a7a293f7a0f3870e7602c[m
Merge: 59e1998 c96998d
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Wed Nov 7 14:27:59 2018 +0100

    Merge pull request #373 from CloudyPadmal/pca9555
    
    feat: pca9555 library

[33mcommit 59e1998d2c41a6fdb4faa7b8d41b24d873a37a7b[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 7 10:58:09 2018 +0100

    Removed sections from the binary file. Closes #378
    
    The following sections were removed:
    .bss - variables initialized to zero when booting
    .nzds - variables not initialized at all when booting
    ._usrstack - link time check that we are not running out of RAM

[33mcommit 47ee696b2d3c433801c96cca85ea7eabe6871449[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed Oct 17 15:27:32 2018 +0200

     #376: Fix includes for zrangerV2

[33mcommit f889d84315a4703d692cca9c19525932bb65b3bb[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed Oct 17 14:33:00 2018 +0200

    Closes #376:  Setup zranger2 to use kalman filter by default
    
    Also call zranger2 from the sensor files.

[33mcommit c70c3f285b8d8da0b9427ae2620c505030d6ecfc[m
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Wed Oct 17 10:27:29 2018 +0200

    Fixed missing file in commit. #374

[33mcommit 06d306bbc43a36e615c368adf73c9f73cac3ae5f[m
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Tue Oct 16 17:05:00 2018 +0200

    Renamed multiranger variables from OA. #374

[33mcommit 52ecf3a0cfde0bf3335e0dbd6b27ce4cc4fd477b[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Oct 16 15:40:29 2018 +0200

    #375 Improved outlier filter for TDoA
    
    The call to the outlier filter has been moved to the kalman filter.
    The outlier filter is based on the estimated distance from the current estimated position to the candidate sample.
    A number of counters are used to keep track of how many samples that are within certain error levels.
    The counters in turn are used to determine which error level to accept and if a sample should be passed on to the kalman filter or not.

[33mcommit 76dcf214925305091bffb8848a5936f27089d1fb[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Tue Oct 16 13:41:06 2018 +0200

    Closes #374: Implement range module that centralizes ranging measurement

[33mcommit c96998d7caee99c8a12f45eab967272aac7c6f0f[m
Author: CloudyPadmal <blog.padmal@gmail.com>
Date:   Wed Sep 26 22:50:50 2018 +0530

    feat: pca9555 library
    
    indentations

[33mcommit 857c1e64ec91eaa5b0e2799447dffcb75343ea27[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed Sep 26 11:23:10 2018 +0200

    Add driver for Lighthouse receiver prototype

[33mcommit f3b06f802ec96b980cda2101533984e6f8833a0f[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed Sep 26 11:21:13 2018 +0200

    Closes #372: Increase number of tasks handled by sysload from 16 to 32

[33mcommit 21ab8c0ea17fd84b9697b411cc654f1c96373271[m
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Thu Sep 20 08:50:56 2018 +0200

    Fixed build error with SENSORS=bosch. #370

[33mcommit 252bdb173cac59be859b06c19796eee22a406f90[m
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Wed Sep 19 15:31:45 2018 +0200

    Cleanup and final implementation of proptest code. Closes #370
    
    A initial implementation has been made and it works like this.
    - To run the propeller test the parameter health.runPropTest should be
    set to 1. This can be done using the cfclient or using the python lib
    parameter framework e.g. cf.param.set_value('health.runPropTest', '1').
    Setting it again will run another new test.
    - The test will then run by spinning each propeller after another to
    check the vibration. If a propeller is found to be over the limit (set
    in config.h as PROPELLER_BALANCE_TEST_THRESHOLD) the failed propeller
    will make three short beeps and a sound so it can be identified.
    - In the console in the cfclient information of the test will be printed
    and also if any propeller failed.
    - After a test has run it might be wise to restart the CF2.

[33mcommit 511d1b9700fbc7a8bee1b7f1909f74e878aa4f3a[m
Merge: 443edd8 3d73ba3
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Fri Sep 7 15:16:57 2018 +0200

    Merge branch 'master' into proptest

[33mcommit 443edd84c8b8ff0c7654f224b3dca98d7c3b579e[m
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Fri Sep 7 15:16:12 2018 +0200

    Updated BMI088 drivers. Added draft battery test.

[33mcommit 3d73ba300681d980b7a14373e51cac2ab8ec912e[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Sep 5 16:35:21 2018 +0200

    #320 Handle divide by zero in the kalman filter

[33mcommit 68f94f5bda1a1ee1581bc76d50adbf397bce2f58[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Mon Sep 3 15:51:08 2018 +0200

     #337:  Fix ID to log from memory in log protocol V2
    
    This fixes a bug where it was not possible to log a variable with ID 255

[33mcommit c9c4691b55ad12bf434bf3f03e3f562037dddf92[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Mon Sep 3 15:48:49 2018 +0200

    Closes #367: Handle overrun condition in deck Uart1 driver

[33mcommit f412229a6d435fe4f5e8e515fffab5cc8e213db0[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Aug 31 16:03:27 2018 +0200

    #366 Removed debug printing

[33mcommit deec04c16eb9ad4ae3177abb7755936f6735ea57[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Aug 29 15:47:41 2018 +0200

    #366 Added mapping for available ids, active anchors and anchor positions.

[33mcommit 81ef1e054d31d2d10205df0d15094f049f613ab5[m
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Fri Aug 24 15:39:25 2018 +0200

    Added and fixed proptest for BMI088.

[33mcommit 499f0184c9de64397b444e3eec8db51cf859b753[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Thu Aug 23 16:21:23 2018 +0200

    Closes #228: Fix syslink PM bit swap

[33mcommit 114e7205cbdf350ef9a08b2e67d83415d3312ca5[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Thu Aug 23 15:40:26 2018 +0200

    Closes #224: Fix uSec timer not stopping in DGB mode

[33mcommit cf95ae931ecc64a3c5b3478d474bd5c0c0b64398[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Thu Aug 23 15:00:06 2018 +0200

    Closes #304: Fix zRanger reading loop rate

[33mcommit d1b37e00ea28a5b181648a2f79dfd1c03d25edd7[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Thu Aug 23 14:14:52 2018 +0200

    Closes #342: Fix crash when pushing ext pos measurement and EKF disabled

[33mcommit 84b57df8983d22c7d4fe10f96de67bb514e417b6[m
Merge: 0a98b1b f83f068
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Thu Aug 23 13:54:09 2018 +0200

    Merge branch 'master' into proptest

[33mcommit f83f068db8d618a5f908f156367652963c6c4fad[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Aug 22 14:37:02 2018 +0200

    Added TDoA3 to the list of positioning algorithms. Closes #363
    
    Note: This effects compile flags to enable TDoA3

[33mcommit 798702a17614a4d0570efa58ac51d6456bf4b4d8[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Aug 21 16:38:48 2018 +0200

    Moved LPS algorithm storage from locoDeck driver to algorithms. Closes #362

[33mcommit af396121bcd114bc159415dd2cb331cdbe4fcd54[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Tue Aug 21 09:13:06 2018 +0200

    Closes #361: Remove kalman lock of Z postion > 0

[33mcommit 6dcdcb6f420d188d59f0f0aadec11c053a989f69[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Aug 20 14:24:31 2018 +0200

    #359 Styling

[33mcommit d06ad5a5954ed77f7d3c928a9fcd82760b1b61ad[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Aug 20 13:20:26 2018 +0200

    #359 Tdoa Storage unit tests finished

[33mcommit 2a57d136b23e2d39070b1b7608b28afc86d61b60[m
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Fri Aug 17 15:08:23 2018 +0200

    Fixed build error due to lacking dataReady. Closes #360

[33mcommit 637617b6120f162d02da4bb7a778ae12d4352933[m
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Fri Aug 17 12:59:01 2018 +0200

    Added SPI driver for BMI088. Also stabilizer is synced to senor data.
    
    Implemend a new SPI driver for the BMI088 for the RZR baord. For this I
    also made the stabiliser task sync to the sensor data so the latency is
    minimized.

[33mcommit a6d13ad16a98acbf0ece84af9871491c1d11435b[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Aug 16 17:20:08 2018 +0200

    #359 Added some unit tests for tdoaStorage

[33mcommit 31433d3f461b96a94fd627d9354cdf49a985186c[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Aug 16 13:18:44 2018 +0200

    #359 Refactoring of the clock correction engine to work with the mocking framework

[33mcommit 362263f093dfaa49ad899d90e2753cecc71dbf36[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Aug 16 12:38:59 2018 +0200

    #359 Fixed unit tests that were broken in refactoring

[33mcommit 35e3a35552fb3f63af26aff33d59f00c4f44e43b[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Aug 16 11:17:52 2018 +0200

    #359 Refactoring
    
    Broke last dependency from tdoa in utils

[33mcommit 4e22766df8a67cf1f2a802531f25657bddac337c[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Aug 15 16:05:10 2018 +0200

    #359 Refactoring
    
    Removing static memory (state) in utils

[33mcommit 9e4e5aa5c152cae421e85f0f192a077b387e1069[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Aug 15 11:50:04 2018 +0200

    #359 Refactoring.
    
    Extended anchor context to contain the current time to get rid of dependencies to FreeRTOS in utils

[33mcommit 047b5c669a25ed34e4ad6a218c2994fe7f1e181a[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Aug 14 15:46:33 2018 +0200

    #344 Removed module-test since it was not finished

[33mcommit 0a97123f090ec47dda9790c70a5184b43828ec35[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Aug 14 15:44:00 2018 +0200

    #359 Refactoring. Extracted TDoA engine storage and moved TDoA files to utils.

[33mcommit cb90243429aefbcbe4483b7fdf4075780e596599[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Aug 14 14:15:51 2018 +0200

    Added a changing offset when picking anchor candidate to use for TDoA calculation. Closes #358

[33mcommit 3c689af9cb18a3aa9a9efce87ac29a696b649b85[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Aug 14 13:43:57 2018 +0200

    Use logic in clock correction module. Closes #357

[33mcommit 6e30b5150730f51a212bdb544350476a0262541f[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Aug 8 15:54:42 2018 +0200

    Changed to latest version of lib DW1000. Closes #356

[33mcommit f612e27e18ea06c4e3cea820c2723b6b3bec15cb[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Aug 8 13:55:24 2018 +0200

    Added check of TDoA protocol version in TDoA2 implementation. Closes #322

[33mcommit 0add37b6c05d24986fa994c53e77c1706070c1e8[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Aug 7 16:04:42 2018 +0200

    Use latest version of libdw1000, closes #354

[33mcommit eba8dd1269d551d6d316245b082dfbd5ae990313[m
Merge: efbd2d0 1116d1f
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Tue Aug 7 11:19:41 2018 +0200

    Merge pull request #337 from USC-ACTLab/issue313
    
    Allow more than 256 logging vars/parameters

[33mcommit 1116d1f0b51d2d651349406edc432327811a813d[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Tue Aug 7 11:07:38 2018 +0200

     #313: Bump CRTP protocol version to 4
    
    This indicates that a client can use the new log messages to list up
    to 16K variables

[33mcommit efbd2d096a29278da321773b5884d83409b880dc[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Aug 7 11:04:20 2018 +0200

    Completed read only params to indicate if deck drivers are initialized or not. Closes #237

[33mcommit 8a9b53573251f5454db7936a9ba25a3ff0971837[m
Merge: f637f7d 779cca9
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Tue Aug 7 10:14:50 2018 +0200

    Merge pull request #328 from acecilia/master_mod
    
    Clock correction tests

[33mcommit f637f7dc3b38d882b2a3d5e3f915512eb1d68632[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Aug 6 16:20:15 2018 +0200

    Fixed define of PM_BAT_CRITICAL_LOW_TIMEOUT. Closes #231

[33mcommit 98a2bf91038ba6962dea7590bdabad8d662e16ae[m
Merge: 5d3d3a4 d8fa530
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Mon Aug 6 15:08:13 2018 +0200

    Merge pull request #346 from NicksonYap/master
    
    Useful stuff for your consideration :)

[33mcommit 5d3d3a43cf99bd97dfd789924305906c962ce0bd[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Aug 3 15:51:09 2018 +0200

    Removed unused defines of MIN and MAX. Closes #352

[33mcommit 1d909257727fc8072a3692a581a772a3f7c80f15[m
Merge: f6c0e73 57b0ea1
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Fri Aug 3 15:45:55 2018 +0200

    Merge pull request #353 from USC-ACTLab/issue352
    
    Remove max,min,isnan macros in favor of built-ins

[33mcommit 57b0ea1e7a8888f2c1bbed3999b5e1f2d4eee8e0[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Thu Aug 2 12:44:58 2018 -0700

    Remove max,min,isnan macros in favor of built-ins
    
    This change removes the max,min and isnan macros
    in num.h. The min, max macros are replaced by
    fminf and fmaxf, avoiding side-effects that can
    be caused by macros.
    
    isnan is replaced by the compiler-provided
    macro (part of math.h).
    
    This fixes issue #352.

[33mcommit f6c0e737cfd061b72efcb125af7d545e06597807[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Thu Aug 2 15:53:44 2018 +0200

     #338: Fix yawrate sign in commander_generic packets

[33mcommit 3e881b6cce0677d43cc050e32b0da9164b4d4af0[m
Merge: b943ff8 f31693b
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Tue Jul 31 15:20:16 2018 +0200

    Merge pull request #338 from USC-ACTLab/issue335
    
    Manual flight: same yaw rate for PID and Mellinger

[33mcommit b943ff8eecb25901505f915270d845412d9358ed[m
Merge: d14a572 b95901f
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Fri Jul 27 13:49:01 2018 +0200

    Merge pull request #351 from USC-ACTLab/HLsmoothSetpoint
    
    HLCmd: Avoid setpoint discontinuities

[33mcommit b95901f0805952e3671659b26739ceafd23e75c5[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Thu Jul 26 10:41:26 2018 -0700

    HLCmd: Avoid setpoint discontinuities
    
    The previous HLCmd frequently planned from the current state
    rather than the current setpoint. This can cause jumps in the
    setpoint, and, in case of a swarm, inconsistent behavior such
    as different flight heights across the CFs.

[33mcommit d8fa530c2b6cbc3cf848fdfa9c21f1bf914fb17b[m
Merge: cfc7df0 d14a572
Author: Nickson Yap <hi@nickson.me>
Date:   Tue Jul 10 19:10:03 2018 +0800

    Merge remote-tracking branch 'bitcraze/master'

[33mcommit d14a57266f784011f7910ca10a85c186c7438d51[m
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Fri Jul 6 13:31:00 2018 +0200

    Added expansion port test.

[33mcommit 7c1ecdf060d917420394cb07e22d9c553c578d9b[m
Merge: 6308ff4 ac99881
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed Jul 4 16:36:45 2018 +0200

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit 6308ff47ff4d4691f9b7f6f991564244c76d7910[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed Jul 4 16:33:20 2018 +0200

    Closes #348: Fix TDoA3 2D position mode
    
    Implements a new measurement for the kalman filter:
    absolute height. This can be used for any real or
    virtual sensor that can sense the absolute height.

[33mcommit ac998816bd3a6f0b73221729c496f45230b6a4bf[m
Merge: ad62b75 e5c7bfa
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Wed Jul 4 15:00:45 2018 +0200

    Merge pull request #347 from bbingju/master
    
    Fixed wrong assertions

[33mcommit e5c7bfaee5584c85e9790d5e1d0f52410bf31b8b[m
Author: Phil ByungJu Hwang <phil@thisiseng.com>
Date:   Wed Jul 4 19:49:26 2018 +0900

    Fixed wrong assertions

[33mcommit cfc7df0eb250d455a0af146500ea431df567dbda[m
Author: Nickson Yap <hi@nickson.me>
Date:   Wed Jul 4 03:45:12 2018 +0800

    Allow changing LED Ring default effect in `config.mk`

[33mcommit e817d8c367ab45e031044d1a368a451bb89fed89[m
Author: Nickson Yap <hi@nickson.me>
Date:   Wed Jul 4 03:27:58 2018 +0800

    Add new LED Ring effect - 15: Radio RSSI

[33mcommit c34c03857564789d88afde422602aad56c66cb79[m
Author: Nickson Yap <hi@nickson.me>
Date:   Wed Jul 4 02:17:15 2018 +0800

    Allow turning off on-board LEDs in `config.mk`

[33mcommit 1cdd996edb37cb4082a2db41aa2108bc2ddac5e8[m
Merge: 99ccec5 ad62b75
Author: Nickson Yap <hi@nickson.me>
Date:   Tue Jul 3 21:16:32 2018 +0800

    Merge remote-tracking branch 'bitcraze/master'

[33mcommit 99ccec52fa6474f246ee333f194d202d4f7b39fb[m
Author: Nickson Yap <hi@nickson.me>
Date:   Tue Jul 3 20:57:35 2018 +0800

    Allow LED Ring deck to use more or less than 12 LEDs in `config.mk`

[33mcommit ad62b75b49d74aa4b3a486e5ed927709c5382e34[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Tue Jul 3 14:51:39 2018 +0200

     #269: Allow setting the low interference mode in config.mk

[33mcommit 6080c9ecc9151ea2bedd8c0edab70fa017a9cdbb[m
Author: Nickson Yap <hi@nickson.me>
Date:   Tue Jul 3 20:47:17 2018 +0800

    Allow disabling Loco Deck Low Interference Mode in `config.mk`

[33mcommit 2a59df5c2a463289fea78e56ce3e809263dfc238[m
Author: Nickson Yap <hi@nickson.me>
Date:   Tue Jul 3 20:41:40 2018 +0800

    Allow forcing multiple deck drivers in `config.mk`

[33mcommit 42536bda9d55d8071fc60e2143b1c696bb9316be[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Tue Jul 3 14:36:39 2018 +0200

    Revert " #345: Fix type issue in BMI088/BMP388 sensors"
    
    This reverts commit cfd7bd43e91cc4cfae2d45b0540ab2332003f851.

[33mcommit cfd7bd43e91cc4cfae2d45b0540ab2332003f851[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Tue Jul 3 14:32:25 2018 +0200

     #345: Fix type issue in BMI088/BMP388 sensors

[33mcommit 6af99907cbd4df83af4d90286da46189b8feba62[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Tue Jul 3 14:16:07 2018 +0200

     #345: Add sensors file for BMI088/BMP388 sensors

[33mcommit 2238a13099e241e572e27f90f981f0d8bb846799[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Tue Jul 3 14:15:31 2018 +0200

     #345: Add drivers for Bosch BMI088 and BMP388

[33mcommit 7d646a63983b314954d502f1667ec6194fa8cb35[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Mon Jul 2 17:06:11 2018 +0200

    Closes #343: Fix IGNORE_OW_DECKS compile flag implementation

[33mcommit 779cca9d0e27f42b03ed8d1ed3754ca87e31d5a2[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Wed Jun 27 17:01:07 2018 +0200

    Add logging for clock correction

[33mcommit 5d0f8d3fa7817b922b143e442aed9db4e0800d40[m
Merge: 0205a85 d5f7de0
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Mon Jun 25 08:54:40 2018 +0200

    Merge pull request #339 from USC-ACTLab/issue321
    
    Fix copy&paste error for attitute pid reset

[33mcommit d5f7de0daf3d8b3be5181ba7d56c95827d057151[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Fri Jun 22 18:53:08 2018 -0700

    Fix copy&paste error for attitute pid reset
    
    see issue #321.

[33mcommit f31693b6e787644a54db89cf81a9231efb5c8e60[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Fri Jun 22 18:47:25 2018 -0700

    Manual flight: same yaw rate for PID and Mellinger
    
    The PID and mellinger controllers had different behaviors (inverse
    yaw direction) in manual flight mode, see issue #335.  The root cause
    is that the legacy yaw input is actually inverse (with respect to
    the CF coordinate system). This change changes the sign accordingly
    before processing and fixes some other math issues related
    to yaw control.
    
    Tested with manual flight using PID and Mellinger controllers.

[33mcommit ec4355a8ef0adfc6d8f45b13db6112fd1a63d7d0[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Fri Jun 22 17:18:00 2018 -0700

    Allow more than 256 logging vars/parameters
    
    This addresses the firmware side of issue #313 by adding additional
    CRTP commands (called V2) that uses 16 instead of 8bits for indexing.
    
    This change keeps the old API the same, but caps the number of vars
    to 255 to allow older clients to keep working. Eventually, the old
    API should be removed.
    
    This change reduced the possible length of variables by 1 byte,
    which affected two variables whose name had to be shortened.
    
    Tested with crazyflie_cpp commit 3eb3203. Other clients will need
    similar changes to use more than the first 255 variables.

[33mcommit 0a98b1b5c3ba92b96cce61013583331f70626179[m
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Thu Jun 21 16:17:51 2018 +0200

    Fixed build warnings.

[33mcommit c9a2d005d7c7cda791f57a088697de2a23d2c45b[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Wed Jun 20 16:25:48 2018 +0200

    Updated tests: all passing

[33mcommit 143e0e0e14b10231020ece2f0b86dc0d216c130e[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Wed Jun 20 16:24:59 2018 +0200

    Reverted update implementation to old one, according to comments on https://github.com/bitcraze/crazyflie-firmware/pull/328#issuecomment-398339831

[33mcommit 2731055863521cb588376fd63aff44b69b8a3a6c[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Wed Jun 20 15:25:07 2018 +0200

    Make const the argument for the getClockCorrection function

[33mcommit 076f1158695d22e28e2ff6b99a83c0da76632e69[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Mar 17 13:54:14 2017 +0100

    Fixed build warnings.

[33mcommit c11c644af1e9f7cd1bc1049f80ea12b41577d89a[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Nov 4 16:46:31 2016 +0100

    Initial propeller test working. Needs callbration and cleanup.

[33mcommit f98634898757f45051f0d200660407b138385b29[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Nov 4 13:19:20 2016 +0100

    Added first shot of a propeller vibration test.

[33mcommit 0205a85b81cd9806caf6c41d19f8f4940c33a859[m
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Fri Jun 15 13:07:50 2018 +0200

    Increased CRTP-RX stack since a stack overflow was triggered.

[33mcommit 0f37f2b6fcfe8822f6550ca5e1603fbad9ddcf7f[m
Merge: 13a5165 cc964bc
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Fri Jun 15 07:15:03 2018 +0200

    Merge pull request #332 from FreddieOliveira/patch-1
    
    Update config.mk folder location in README.md

[33mcommit cc964bccc6deb0209f558482faa68536d6368320[m
Author: Frederico F. de Oliveira <FreddieOliveira@users.noreply.github.com>
Date:   Thu Jun 14 16:44:33 2018 -0300

    Update config.mk folder location in README.md

[33mcommit 13a5165ee65a5eb7314f9713cc4fa7da8f6a88ee[m
Merge: af95681 02fa05c
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Thu Jun 14 19:13:20 2018 +0200

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit af95681ae18edd41f168a513fcf284e7bc6cec73[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Thu Jun 14 19:12:18 2018 +0200

    Closes #331: Add battery level log variable

[33mcommit 67d7af447aeb48f8f301765fcdaa8d4464eff6d7[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Thu Jun 14 16:24:19 2018 +0200

    Moved tests for clockCorrection to the "utils" folder

[33mcommit 2bd22e4d2e8d1e371bcff30453d4dfac5123c6ed[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Wed Jun 13 21:00:06 2018 +0200

    Better documentation

[33mcommit 02fa05cba8a2aae40920f997960f76671848cb8e[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Jun 13 13:36:46 2018 +0200

    #330 Added compile flags for configuring TDoA 3
    
    LPS_2D_POSITION_HEIGHT - 2D positioning
    LPS_LONGER_RANGE - longer range, requires same compile flag in the anchors

[33mcommit 33b07ebec61cdba8a7e8a7fdf7d9bb4f03b54c89[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Jun 13 11:34:19 2018 +0200

    Bumped libdw1000 to latest version. Closes #327
    Note: this is breaking compatibility with the anchors since the clocks will be adjusted, packets may be discarded due to too large difference in clock rates. See bitcraze/lps-node-firmware #33

[33mcommit 4c1ac16ba1828c17c6fd1ad8d9445abfdf93703b[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Tue Jun 12 22:28:37 2018 +0200

    Closes #329: Implement ledring color fading effect

[33mcommit 54b1b7af2573a1fe7cc63909813c21bbdbe92453[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Tue Jun 12 17:58:40 2018 +0200

    Fix test

[33mcommit 9c8f4365d0b27fb4d465c57ce0cb75dfc16c5933[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Tue Jun 12 17:11:56 2018 +0200

    Put const all around

[33mcommit e53a36a937e79d0a8a99bb2415b3bad913ec3d00[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Tue Jun 12 17:08:19 2018 +0200

    Rollback faulty implementation of the clockCorrectionEngine

[33mcommit 51dc39f713f94c7b25906d467da4708ff50a9afc[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Tue Jun 12 16:48:18 2018 +0200

    Fix docs

[33mcommit 07613068bcc97ba196df667bff00e34415c3d613[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Tue Jun 12 16:45:05 2018 +0200

    Moved clockCorrection module to the "utils" folder

[33mcommit 2de29c243f713c940b6d8870a9818d87ae68ed2b[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Tue Jun 12 16:41:47 2018 +0200

    Improved existing tests
    Added tests for the clockCorrectionEngine

[33mcommit 8b3fd341c7e019d8137bd092fb0366ed0e1155b2[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Tue Jun 12 15:27:01 2018 +0200

    Added the mask for the timestamp truncation as a parameter to the engine, so the algorithm using it can specify the necessary mask

[33mcommit 756d1339473e94644720e83eb6bcdc4d3a1478e4[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Wed Jun 6 16:37:45 2018 +0200

    Finish clock tests

[33mcommit 10fa8a9b1d3c6ff733ed34812aa668964c77d1e3[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Wed Jun 6 02:03:20 2018 +0200

    Fixes
    Enabled compiler warnings for type conversions in debug

[33mcommit 7bd77e4d116e4e60bb9716832cdd1ade3ca3a06d[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Wed Jun 6 01:32:38 2018 +0200

    Fix for updating clockCorrection

[33mcommit bd0acb7e0451c946bf2dcc6b74dc64614a2af2ab[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Wed Jun 6 00:46:57 2018 +0200

    Added calculateClockCorrection tests

[33mcommit 755a6289bddc9899e911a072d5ada2507cd6886a[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Wed Jun 6 00:40:58 2018 +0200

    Added tests

[33mcommit 0597dd6f641b234630e93de56c82d1d5acdba218[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Wed Jun 6 00:16:12 2018 +0200

    Added comment

[33mcommit 792d5c9b00f478b3da7067c05d14d107767c38f2[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Wed Jun 6 00:15:18 2018 +0200

    Enabled double comparisons in unity

[33mcommit 4d409a61cc2ee64d7d9bde0b806c9d040374351b[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Wed Jun 6 00:12:32 2018 +0200

    Added clockCorrection files as separate module

[33mcommit 3d1defd9837e59cb24dffc1e65907613f008c7c0[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Mon Jun 4 08:29:06 2018 +0200

     #319: Remove 'entering/leaving' directory print when calling make

[33mcommit c139156c3a1288541f0267731c5c2041c03ce477[m
Merge: ccfb590 c4d8087
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed May 30 09:15:19 2018 +0200

    Merge pull request #326 from USC-ACTLab/uSDGenericLogs
    
    Generalize logging to uSD card

[33mcommit ccfb59064f8a7cbd13fb130fc16a98f45ab1f0e1[m
Merge: c112582 fbd0b56
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Wed May 30 08:20:29 2018 +0200

    Merge pull request #325 from USC-ACTLab/controllerDynamicClean
    
    Add option to switch controllers dynamically

[33mcommit c4d8087edd1533b6a7f6213032d6ba6b1af9376e[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Tue May 29 19:31:53 2018 -0700

    Generalize logging to uSD card
    
    * Support for any logging variables
    * Config file can now be written in a standard text editor
      and contains the list of variables to log (see
      tools/usdlog/config.txt for an example)
    * Support for other native datatypes (e.g., uint8_t)
      to avoid memory overhead
    * Example scripts are updated to reflect the
      (slightly) modified binary data format

[33mcommit fbd0b56d04a349a23bcd6e2ceb6399cca0226fb8[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Tue May 29 13:41:52 2018 -0700

    Add option to switch controllers dynamically
    
    * New parameter: "stabilizer.controller"
    * Default controller as before (PID)
    * It is now possible to switch at runtime to another
      controller (e.g., mellinger, for the Crazyswarm)

[33mcommit c112582ea8c9604df670dfd044460db1fc1c915a[m
Merge: 18104df 40279ad
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Mon May 28 12:42:51 2018 +0200

    Merge pull request #324 from USC-ACTLab/estimatorDynamic
    
     Add option to dynamically change estimator using "stabilizer.estimator" parameter

[33mcommit 40279ad06ff295437cdbb28e18f844db312667c3[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Fri May 25 09:38:41 2018 -0700

    Improve error handling for dynamic estimator chg.
    
    * Add bounds check in stateEstimatorInit
    * Update parameter after every switch to give
      user the ability to query the current estimator

[33mcommit 18104df81913d7f9359c4d5768123292864e24b2[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu May 24 07:18:48 2018 +0200

    #315 Corrected allowed clock drift
    
    Worst case is that one anchor is +MAX_CLOCK_DEVIATION_SPEC off while another is -MAX_CLOCK_DEVIATION_SPEC off. Total acceptable diff is thus 2 * MAX_CLOCK_DEVIATION_SPEC

[33mcommit 73264329a08dfb7d9cb5af7b90fb92d405ac73d0[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed May 23 21:50:20 2018 +0200

    #315 Added outlier removal on clock correction

[33mcommit 5f099e896a834dfaab7ce5f3c596d18f338c40fb[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed May 23 07:52:24 2018 +0200

    #315 Make sure TDoA data can handled the first seconds the system is running

[33mcommit 4095cd6afe4a29db199512f1116083eb192c0d0d[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed May 23 07:42:00 2018 +0200

    #315 Added sketch of a module-test that exercise the tdoa engine from pre-recorded data off-line

[33mcommit c419c0010708280da37e5153afc9c00387e1ae2b[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Tue May 22 10:39:37 2018 -0700

    Add option to dynamically change estimator using stabilizer.estimator parameter.

[33mcommit 37c9d35e9d7179fa906edc83ed963d68e7421f83[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue May 22 16:33:44 2018 +0200

    #315 Simplified the tdoa engine API

[33mcommit a5dd1d5a244bc0e547b5e74442b27e7b94f4bfbb[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue May 22 11:41:57 2018 +0200

    #315 Updated outlier filter
    
    Changed double to float
    Removed unused estimated position param

[33mcommit a50412212923509c45fe25a9ae92b9f10dd8c469[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue May 22 10:06:38 2018 +0200

    #315 Refactoring. Separated protocol, algorithm and stats into separate modules

[33mcommit 3f7cbc52fbc06aa023387d3fc06bc550bba5cf33[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue May 22 05:51:57 2018 +0200

    #315 Corrected pointers

[33mcommit f41cd719efe335faa52138f93974ad592de221da[m
Merge: 48c84d5 732b592
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu May 17 07:16:20 2018 +0200

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit 732b592d90f952e33cc915cfd1c29f3f9b9e8d05[m
Merge: 5946a49 a9f19b4
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Thu May 17 07:15:10 2018 +0200

    Merge pull request #319 from acecilia/remove_clean_from_compile
    
    Remove clean from compile

[33mcommit 48c84d5070c9d1d934b5f28979385877c0ebcfe4[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed May 16 16:21:09 2018 +0200

    #315 Only use packets that pass the clock correction sanity check for positioning

[33mcommit 3f924d9328dc71d8c7ad898b63381f3687ce1f7c[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed May 16 15:33:18 2018 +0200

    #315 Added basic sanity check of clock correction
    
    Added logging of tdoa data
    Increased storage for anchor data

[33mcommit 5946a4945646e4c150366f9e677c029702aa5aec[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue May 15 12:38:03 2018 +0200

    #315 Added support for LPP packets in TDoA 3

[33mcommit a9f19b4752ac0e9e721c0ccf43083b04d6a7e9cf[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Sat May 12 17:08:09 2018 +0200

    Avoid printing the comment

[33mcommit 3aba2d55bc17a89edc08d30d26422c5b73e33cf6[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri May 11 11:16:11 2018 +0200

    #315 Corrected logging of useful data rate

[33mcommit afa26ceffc6088bcdf1769bd88cdaa81d78c6283[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Thu May 10 18:55:25 2018 +0200

    Added comment

[33mcommit 74fae9971987402a1ce32343b99099df6a054752[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Thu May 10 15:35:13 2018 +0200

    Avoid build running the build targets in paralell when -j is more than 1

[33mcommit 630a8126959c58c51fffc52746a4f05afa114bbc[m
Author: Andrés Cecilia Luque <a.cecilia.luque@gmail.com>
Date:   Thu May 10 14:30:06 2018 +0200

    Remove clean_version from the compile target

[33mcommit 1a08af47bee58a241f735e72591a7e6fe7b89654[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu May 10 07:26:52 2018 +0200

    Increased memory in task dump. Closes #318

[33mcommit d08b4c680fed3bf4ea5769ef988d40a44f52135d[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed May 9 11:29:27 2018 +0200

    #315 Added dynamic number of anchors in TDoA 3, linear search data model

[33mcommit ecd0184487dcb812cc32a59849c358cbb441ccbf[m
Merge: a545b2e 3a99b6d
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Wed May 9 15:50:57 2018 +0200

    Merge branch 'master' of https://github.com/bitcraze/crazyflie-firmware.git

[33mcommit a545b2e0882f8dcf6c1dd1b96f9af5976694e468[m
Author: Tobias Antonsson <tobbeanton@gmail.com>
Date:   Wed May 9 15:49:35 2018 +0200

    Initial implementation of deck drivers for Flow v2 and Z-ranger v2.
    Closes #317

[33mcommit 3a99b6d81ac8cf76efc74214c992d424d1c4d886[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue May 8 11:18:38 2018 +0200

    #315 Added TDoA3 protocol on top of TDoA2 algorithms

[33mcommit 9173b9b70c5cf584aef43d9470b37b8c7855f50b[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon May 7 18:19:41 2018 +0200

    Corrected printf of long and long long args. Closes #314

[33mcommit b2e88934e28bdc414a216dc08c36c18f7d4f1836[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri May 4 14:56:44 2018 +0200

    #315 Reverted previous commit since it broke communication with the client

[33mcommit 7451a3d7c0460b9825d62de27cad31e88116b4b8[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri May 4 14:05:24 2018 +0200

    #315 More renaming of tdoa to tdoa2

[33mcommit 03aacab1da206d814fa67cf389466ebe01db96ca[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri May 4 13:56:13 2018 +0200

    #315 Refactoring: renamed TDoA files, functions and constants to clearly indicate that they implements TDoA 2 as a preparation for TDoA 3

[33mcommit 802c74a4ebda8385325412b36bb3cb45d6c3b5cd[m
Merge: 1f65d8d 3b1e724
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Fri Apr 20 08:20:30 2018 +0200

    Merge pull request #309 from USC-ACTLab/hlcmdTrajUpload
    
    HighLevelCmd:Broadcast support for startTrajectory

[33mcommit 1f65d8d4484064a1bcb2c79f83a158a761d8ac4f[m
Merge: e88c926 6ebac63
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Fri Apr 20 08:18:30 2018 +0200

    Merge pull request #310 from USC-ACTLab/locSrvExtPosPacked
    
    LocSrv: Add EXT_POS_PACKED CRTP packet

[33mcommit e88c92664909803fdf59193cc8cdf77bbeffa4ea[m
Merge: 71ebff0 585d85c
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Fri Apr 20 08:16:22 2018 +0200

    Merge pull request #308 from USC-ACTLab/hlcmdEvalShiftBug
    
    HighLevelCmd: Add missing shift for traj. eval

[33mcommit 71ebff0136488e4e74ebf71a0deee60ca6608ffa[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Apr 18 17:30:50 2018 +0200

    Added statistics to the CRTP module. Closes #312

[33mcommit ca2cc9beb07f7d58d80dcecedc1464d76f952fe6[m
Merge: 2107af2 93eaf9c
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Mon Apr 16 16:40:44 2018 +0200

    Merge pull request #311 from TimKam/patch-1
    
    README: Fix typos

[33mcommit 93eaf9cd69e24a1eebd7691cdcf453c447c9ea3b[m
Author: Timotheus Kampik <timotheus.kampik@gmail.com>
Date:   Sun Apr 15 12:54:59 2018 +0200

    Fix typos

[33mcommit 6ebac637e3ec2be855bc517735992bccd60cc64b[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Fri Apr 6 17:40:28 2018 -0700

    LocSrv: Add EXT_POS_PACKED CRTP packet
    
    The packed version enables to use very efficient broadcasts in a mocap system
    to support a large quantity of CFs. This CRTP packet can carry position
    information for up to 4 CFs (in a space of -16...16m due to compression).
    
    Tested with a modified Crazyswarm package and 2 CFs in a VICON Mocap space.
    
    Note that this can support twice as many CFs per packet as the original
    Crazyswarm packet, because no orientations are transmitted. This
    should allow us to use about 30 CFs per radio (not tested).

[33mcommit 3b1e724a6a6539abe94be33c818745ab54b6cda5[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Fri Apr 6 17:17:15 2018 -0700

    HighLevelCmd:Broadcast support for startTrajectory
    
    The previous design of startTrajectory required to pass in information
    about the memory layout. When using multiple quadrotors with different
    trajectories, this design does not allow to start trajectories at the same
    time using a broadcast.
    
    The updated API design now has a defineTrajectory method where the
    memory layout can be defined for a trajectoryId. StartTrajectory
    just requires the trajectoryId. CFs can now be configured individually
    with their trajectories, and trajectory execution can be started
    simulatanously using broadcasts.
    
    Verified with 2 CFs and a modified Crazyswarm package using a figure8
    trajectory.

[33mcommit 585d85c1ce6362322c8c111b73425bfdc46b1a6a[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Fri Apr 6 17:11:52 2018 -0700

    HighLevelCmd: Add missing shift for traj. eval
    
    The evaluation function in the high-level commander ignored the trajectory shift
    after a trajectory was completed, resulting in a jump in the setpoint.

[33mcommit 2107af214aaad49e13a59bb6c7f8411555b8415b[m
Merge: e9e84fd 8b51f61
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Fri Apr 6 08:51:45 2018 +0200

    Merge pull request #303 from USC-ACTLab/high-level-traj
    
    High-level commander: trajectory upload and exec.

[33mcommit 8b51f6164365e629c423c84b4f92fe660ee19af3[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Sat Mar 24 20:34:22 2018 -0700

    High-level commander: trajectory upload and exec.
    
    This adds the possibility to upload polynomial trajectories using the existing memory interface.
    Trajectories can be executed with the high-level commander.
    Tested with crazyflie_ros (test_high_level.py).
    See issue #293.

[33mcommit e9e84fd92eafb62789c402fb228c1fe30c0d7b6b[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Thu Mar 22 13:31:30 2018 +0100

    #302: Fix log config typo in Multiranger driver

[33mcommit bbf485ae9d78d84f2ae12b47b3418e3985328d56[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed Mar 21 18:03:36 2018 +0100

    #302: Add Multiranger deck driver using VL53L1

[33mcommit 11c39c2e7a2a6f8c7f895681a5525b8aa5fc27d5[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed Mar 21 18:02:51 2018 +0100

    #302: Add VL53L1 driver

[33mcommit b9a871f5866fd82376c1f3c77b3349b8c595d130[m
Merge: e5e0d9b af442fb
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Fri Mar 16 07:04:26 2018 -0700

    Merge pull request #299 from USC-ACTLab/high-level-commander-ch
    
    Add High-Level Commander, see #293

[33mcommit e5e0d9b080cd0da18133a8212806f251d6d832e8[m
Merge: ce41fb0 b85a79c
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Thu Mar 15 09:46:41 2018 -0700

    Merge pull request #300 from USC-ACTLab/kalman-init
    
    Add parameters to initialize the kalman filter pos

[33mcommit ce41fb0501bb6c78d8c58c04ad9e70f800b845dc[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Mar 9 08:45:47 2018 +0100

    Clarified cloning of sub repos in the readme

[33mcommit b85a79ca3f5d48d5d1c6807d8c0330b6ec3809ea[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Wed Mar 7 13:17:01 2018 -0800

    Add parameters to initialize the kalman filter pos
    
    The kalman filter can be initialized better by first setting kalman.initial{X,Y,Z}, followed by setting kalman.resetEstimation to 1.
    
    Tested with publish_external_position_vicon.py in crazyflie_ros (high-level-setpoints branch).

[33mcommit af442fbd6e90ff18f775cdae123e06e984106e67[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Wed Mar 7 13:08:40 2018 -0800

    Add High-Level Commander, see #293
    
    The initial high-level commander supports takeoff, landing, stop, and goTo. Each CF can be part of one of 8 groups, and commands can be broadcasted for specific groups, only.
    Tested in a mocap system with kalman estimator and mellinger controller using crazyflie_ros (high-level-setpoints branch; test_high_level.py).

[33mcommit 5383d70b21143747ab2d6af7e004e5006795dd43[m
Merge: bca69b2 1974711
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Sun Feb 25 20:09:46 2018 +0100

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit bca69b29aaa9aee35d1b787642834e8a964ff7d1[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Sun Feb 25 20:09:27 2018 +0100

    Closes #298: Add LPS TDoA synchronization log variable
    
    Requires the preprocessor variable LPS_TDOA_SYNCHRONIZATION_VARIABLEto
    be declared.

[33mcommit 197471127f0d64fd22a89677fbff7da855e87da0[m
Merge: 8a6d392 af0f447
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Tue Feb 20 23:39:30 2018 -0800

    Merge pull request #296 from Mitteau/master
    
    Define two communication channels devoted to GNSS (GPS) communications.

[33mcommit 8a6d392005b30b09286bf28de80d2157b7f53749[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Fri Feb 16 14:57:37 2018 +0100

    Closes #297: Add generic commander position setpoint

[33mcommit af0f447c61595f5b358ab6fac94e84c1bc18d39d[m
Author: Jean-Claude Mitteau <perso@jcmitteau.net>
Date:   Mon Feb 12 16:41:28 2018 +0100

    Define two communication channels devoted to GNSS (GPS) communications.
    
     Sur la branche master
     Votre branche est à jour avec 'origin/master'.
    
     Modifications qui seront validées :
    	modifié :         src/modules/interface/crtp_localization_service.h

[33mcommit ead57a108068cdc28c1aaefdfea1ef86f5a2e935[m
Merge: 63b6b49 e583c7d
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Mon Feb 12 02:25:08 2018 -0800

    Merge pull request #294 from USC-ACTLab/bugfixMakeFlash
    
    Improved debugger support

[33mcommit 63b6b497034a28cc24d035ce549ab51cb8282f80[m
Merge: 06e8f8f f658fec
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Mon Feb 12 02:24:32 2018 -0800

    Merge pull request #295 from USC-ACTLab/bugfixLogging
    
    Fix HardFault in Logging

[33mcommit f658fece0797b36e28b34650801adb566c7f0ec6[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Fri Feb 9 13:17:46 2018 -0800

    Fix HardFault in Logging
    
    The logging subsystem could trigger a hard fault caused by unaligned assignment "variable = *(float *)ops->variable;".
    This issue can be reproduced with the crazyswarm_master firmware when connecting to the cfclient.
    
    The fix uses lowlevel memcpy to a local (aligned) variable before assignment.

[33mcommit e583c7d51fb5f8e664a1832fe7a159f2f82ac063[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Fri Feb 9 11:27:06 2018 -0800

    Improved debugger support
    
    This change fixes a number of issues:
     * when using "make flash" it now flashes at the correct address, depending on CLOAD
     * A new command "make flash_verify" can be used to just verify the current firmware
     * "make flash" and "make flash_verify" now use the same (bin)-file as the cloader script
     * Included a template for the use of J-Link debuggers
    
    Tested with ST-Link/V2 and J-Link EDU Mini using openocd 0.10.0

[33mcommit 06e8f8f6e9eb0413dcc23fafb0c23659d964c0c6[m
Merge: fe08418 5948793
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Thu Feb 1 01:19:37 2018 +0100

    Merge pull request #288 from USC-ACTLab/mellinger_improvements
    
    ctrlMellinger: Handling of commander timeout

[33mcommit fe0841860d7c699862d7ad70c1db235aaa0de308[m
Merge: 843146e b50e0b0
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Thu Feb 1 01:17:52 2018 +0100

    Merge pull request #289 from sdalu/static
    
    Use static functions

[33mcommit b50e0b055d5518b167d8944eea77535ca5eeee85[m
Author: Stephane D'Alu <sdalu@sdalu.com>
Date:   Tue Jan 30 14:39:51 2018 +0100

    make functions static

[33mcommit 843146ea56eeb495ed5733218cb74ef35ac3ab3e[m
Merge: 26a78f8 dab030b
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Mon Jan 29 14:44:36 2018 +0100

    Merge pull request #287 from USC-ACTLab/bugfix-log-and-param-check
    
    Fix error checking for log/param var lengths

[33mcommit 26a78f87b4b1ba671041936311b5b02898a2b54b[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Jan 29 11:28:04 2018 +0100

    #256 Corrected missing curly braces

[33mcommit 594879317d14d60db132db39cc9420a57703793f[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Fri Jan 26 11:40:05 2018 -0800

    ctrlMellinger: Handling of commander timeout
    
    In case the commander didn't receive an update for COMMANDER_WDT_TIMEOUT_STABILIZE, it tries the level the CF.
    This change adds the required combination of setpoint modes to handle this case gracefully.
    
    Tested with: manual joystick flight and trajectory following using crazyflie_ros

[33mcommit dab030b2b83e6b3e1e1ec54726f548bfe6c50783[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Fri Jan 26 10:45:30 2018 -0800

    Fix error checking for log/param var lengths
    
    This change fixes undefined runtime behavior in case a developer used variable names for logging that are too long:
    1.) The existing checks for both params and logging at startup were incorrect, because they did not look at both group and variable name.
    2.) There was no check in logging CMD_GET_ITEM, potentially causing undefined runtime behavior. This change implements the same check as in the parameter framework.
    
    The issue will be detected at startup in all cases. If the debug mode for logging or parameters is enabled, the first variable that violates the condition will be printed.

[33mcommit c604f2ef32ce68d86ebda3ae140adc00340a2df7[m
Merge: 0e5e42e 2a87f5a
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Fri Jan 26 04:39:57 2018 -0800

    Merge pull request #284 from USC-ACTLab/controller_mellinger
    
    Add a nonlinear trajectory tracking controller.

[33mcommit 0e5e42e94dccce59eda1822151c4381d720c3077[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Jan 23 08:39:36 2018 +0100

    #256 Added unit test to illustrate rounding errors when printing doubles

[33mcommit c6a582548258b467a51c18e5f6148e1ead7126be[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sat Jan 20 18:28:29 2018 +0100

    #256 Added support for printing 64 bit types

[33mcommit f327f26c970f1482a2ab333ff671742b02768f38[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sat Jan 20 10:39:03 2018 +0100

    #256 Added support for width when printing hex and updated print of serial number

[33mcommit 6ee723ad11449e61835d224a4467391630b2e632[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Jan 22 16:19:03 2018 +0100

    Removed CF1 from module file

[33mcommit 2a87f5ac84242ac9956d2828a30928bea327d079[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Fri Jan 19 13:46:42 2018 -0800

    Add a nonlinear trajectory tracking controller.
    
    To test, follow these steps:
    1. compile the firmware with ESTIMATOR set to "kalman" and CONTROLLER set to "mellinger".
    2. roslaunch crazyflie_demo external_position_vicon.launch uri:=radio://0/100/2M/E7E7E7E728
    3. In "crazyflie_ros/crazyflie_demo/scripts": python execute_trajectory.py figure8withTakeoffAndLanding.csv
    
    The controller can also be used with manual flight

[33mcommit 0ce5b7af482c9c57cc57df0be635b4ccb0c91e4a[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Wed Jan 17 15:05:36 2018 +0100

    Fixes #280: Fix auto-mode LPS scann after a mode was found

[33mcommit 4a845c9d4970a05789dea87c10e8d8d094c5330b[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sun Jan 7 21:47:59 2018 +0100

    Refactoring. Closes #277

[33mcommit 6a59b986e2d9bb818727390784b506c399be2f07[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Jan 5 14:14:30 2018 +0100

    #277 Added simple TDoA outlier filter that removes any samples where the measured TDoA distance is longer than the distance between the anchors.

[33mcommit ab8036a84ce3091a53fe6e9f00f0ed68a7029b2d[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Jan 2 16:18:23 2018 +0100

    #251 Refactoring

[33mcommit bebeb1a69140196f44d1b796e8076ea4e0b353aa[m
Merge: 085913e e6a3e26
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Fri Dec 22 08:43:33 2017 +0100

    Merge pull request #276 from USC-ACTLab/bugfix-units
    
    add comments including the units used in datatypes

[33mcommit e6a3e268752522a27990caf9fa3b664dad87b00b[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Thu Dec 21 18:23:38 2017 -0800

    add comments including the units used in datatypes

[33mcommit 085913ea6df0f421f61a564bd0fa4fc48fce4074[m
Merge: 28f4266 72a9ffa
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Dec 21 15:50:37 2017 +0100

    Merge pull request #275 from jpreiss/full_state_command_packet
    
    commander packet for full-state control

[33mcommit 72a9ffaa19303b696d45255b19eb5a33721f5c9f[m
Author: James Preiss <japreiss@usc.edu>
Date:   Mon Dec 18 21:05:37 2017 -0800

    commander packet for full-state control

[33mcommit 28f42665cc458c2688dc6e88e8dc32569974de72[m
Merge: 133814d 0ad0181
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Dec 20 08:39:34 2017 +0100

    Merge pull request #274 from USC-ACTLab/bugfix-complementary
    
    add support for attitute quaternion state estimation in complementary…

[33mcommit 0ad01817081a12bd3e10ff6e48f2ded53ef8a951[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Tue Dec 19 18:12:49 2017 -0800

    add support for attitute quaternion state estimation in complementary filter

[33mcommit 133814d71194fc8849140d83c74a18472db2a064[m
Merge: 317a25c ac9d59e
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Thu Dec 14 08:19:03 2017 +0100

    Merge pull request #273 from fbobrow/patch-1
    
    Removed extra empty line (line 62)

[33mcommit ac9d59e0743fa04294d14628a9a9aa07bfd2057a[m
Author: Fabio Bobrow <33038597+fbobrow@users.noreply.github.com>
Date:   Wed Dec 13 19:34:18 2017 -0200

    Removed extra empty line (line 62)

[33mcommit 317a25c11ed2706bbaf5b5aebd6519b0ffb019e8[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Dec 13 16:28:25 2017 +0100

    Closes #272: Remove debug prints

[33mcommit b2573818175b4dd275b30afa7bc1415898de3100[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Dec 13 16:02:02 2017 +0100

    #272: Implement, and set by default, automatic lps algoritm discovery

[33mcommit 2eec06681639c5e3e2b8785444dbd183cff17b18[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Dec 13 15:59:48 2017 +0100

    #272: Fix makefile to always compile TDoA

[33mcommit a4dc79f53af771788c8fc67275b07b29ccc7a3a1[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Dec 13 14:01:48 2017 +0100

    #272: Fix tests and algorithms initialization when switching mode

[33mcommit 678713ed363cc97c927a598c3e78478937411619[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Dec 13 13:25:36 2017 +0100

    #272: Implement runtime loco positioning algorithm switch

[33mcommit 9942f72d1a591ffd0e6242c5d449d544b7ee26ba[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Dec 8 16:44:28 2017 +0100

    #251 Increase the size of the space limiter in the Kalman estimator to +-100 meters

[33mcommit 1d3978dfb03286d151db2326cb29253e6f23ac24[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Dec 6 17:15:39 2017 +0100

    #251: Implement timeout for sending LPP packets

[33mcommit 06ea431801430b174f313958f39cef6c05fe2871[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Dec 6 16:46:46 2017 +0100

    #251 Updated unity and cmock to latest versions

[33mcommit d5600899428a1bad7d14ee8c08500695fb93b469[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Dec 6 16:28:45 2017 +0100

    #251 refactoring

[33mcommit 6afd4e940268903e9aff5bcb3ab94c4b20e473fe[m
Merge: 0f302b9 b22133b
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Dec 6 15:16:13 2017 +0100

    Merge branch 'tdoa2' of github.com:bitcraze/crazyflie-firmware into tdoa2

[33mcommit 0f302b9c45bcb99d9f6db6f2283f6030fa929ae9[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Dec 6 15:13:40 2017 +0100

    #241: Check that both anchors have valid position to push measurement

[33mcommit b22133bcef23e3de6861e52b1016709c964d6d6f[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Dec 6 14:48:46 2017 +0100

    #251 Added unit test for incoming LPP packets

[33mcommit 826ec466c03b5e85b9f72aede2f2be02cd4aa183[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Dec 6 14:24:43 2017 +0100

    #251: Test and fix TDoA2 LPP send

[33mcommit 79d634e986fd40bde9dbd17ebaa4f98aed944af3[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Dec 6 13:41:59 2017 +0100

    #251 Updated payload length of UWB packets to 128 bytes

[33mcommit e7976cae24d24df724de8cfefe32b0c83c9c418a[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Dec 6 13:40:46 2017 +0100

    #251: Add LPP payload position in lpsTdoaTag.h

[33mcommit 142a1fd5896822344f8421d3f7b0638f968acba9[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Dec 6 12:58:29 2017 +0100

    #251 Changed default number of anchors to 8

[33mcommit 48f91b89e4a9852e674d84624ba94c4a14b78f3d[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Dec 5 20:29:07 2017 +0100

    #251: Fix test un-needed repeats

[33mcommit 18cdacfee6dc20d152e932df06b33095acccd33e[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Dec 5 20:10:59 2017 +0100

    #251: Remove debug print and fix tests

[33mcommit be8bbc5bf7059ab74146640ed4ef91e0097e9e85[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Dec 5 18:01:42 2017 +0100

    #251: Implement TDoA2 service packet upload
    
    We can now configure the anchor position while in TDoA2 mode

[33mcommit d67c29ba00aaf3b0f71333f87b4d0f9a1b929a02[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Dec 4 18:23:50 2017 +0100

    #251 Added missing header

[33mcommit 0a45dadc37dc281e3f86385ed20eb4772a4529c8[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Dec 4 18:15:30 2017 +0100

    #251 Added LPP packet handling

[33mcommit 1e05b9e2f8f27587ca0dfd1fe0bbfd17173866ba[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Dec 1 16:39:44 2017 +0100

    #251, Added code that was lost in merge

[33mcommit ee52d1d7d7898783f241971ddeaf259abdac29e9[m
Merge: cd9805c 4feaac4
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Fri Dec 1 14:22:22 2017 +0100

    Merge branch 'tdoa2' of github.com:bitcraze/crazyflie-firmware into tdoa2

[33mcommit cd9805ceea43332c359d036a4c898f3c0f118d93[m
Merge: 3d58b02 c55ed40
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Fri Dec 1 14:22:10 2017 +0100

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware into tdoa2

[33mcommit 4feaac424e5f74b99c3e256b9d60ee25d068a13a[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Dec 1 11:22:13 2017 +0100

    #251 Refactoring

[33mcommit 3d58b02968a24ec1d1a0ce2873f15215700cddcf[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Fri Dec 1 10:03:23 2017 +0100

    #251: Fix number of TDoA2 anchors to 8
    
    This fixes a packet decoding bug

[33mcommit 5ed9a007f91031e2897f3df0649ff441ed3066af[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Nov 30 15:15:57 2017 +0100

    #251 Added statistics to TDoA

[33mcommit c55ed40b05b370e73ae85c957636aac78c87f20a[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Nov 30 13:51:46 2017 +0100

    Added low interference radio mode to platform. Closes #269
    
    There is a need to be able to set the output power mode of the NRF51
    radio as it interferes with the UWB radio. A syslink message to do this
    has been added and also the cabability of setting this as a requested
    property of a deck.

[33mcommit 33cba3e61457b369026471d555342515a4cb6d8a[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Nov 30 13:38:03 2017 +0100

    #251 Minor corrections

[33mcommit a626925d4b0739d2515100e049445cd0b385f8cb[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Nov 16 16:46:50 2017 +0100

    #237 Added init parameters for Loco deck and ySD card deck

[33mcommit 736efb8a9c0b8e69afef9144fc86542512b6a9de[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Nov 16 13:57:04 2017 +0100

    #266 Add loggable variable with Loco Positioning system mode

[33mcommit 761ab120ce7cdeae445e50b256f59a8921c4e703[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Nov 13 17:32:32 2017 +0100

    Populate anchor status member in TDoA mode. Closes #265

[33mcommit 9e174110961c33be913b723bba5ce5bc427ed1db[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Nov 13 16:42:42 2017 +0100

    #264 Added example to show how to compile for TDoA

[33mcommit e51e195cfe8f86cfafc6ca11f1bec7180690945f[m
Merge: 31f7167 3e408ae
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Fri Nov 10 11:22:51 2017 +0100

    Merge pull request #263 from fredg02/dev_deck_param
    
    Add deck parameter for BigQuad, Flow, OA and LED ring deck (#237)

[33mcommit 3e408ae54e1ec4914d32ea012183ac39171f099a[m
Author: Fred G <fredg02@hotmail.com>
Date:   Fri Nov 10 01:59:59 2017 +0100

    Add missing include "param.h"

[33mcommit f7cb6cb212b6fa06ce325fd384987c16c3fbe644[m
Author: Fred G <fredg02@hotmail.com>
Date:   Thu Nov 9 02:14:46 2017 +0100

    Add deck parameter for BigQuad, Flow, OA and LED ring deck (#237)

[33mcommit 31f7167dca3e4d67c15ac484366b69e93f774cf8[m
Merge: b8a9e14 fee178e
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Thu Nov 9 10:59:25 2017 +0100

    Merge pull request #260 from fredg02/master
    
    Add buzzer deck init parameter (#237)

[33mcommit fee178ee33a348a16ba9d0f571c19006bd022da1[m
Author: Fred G <fredg02@hotmail.com>
Date:   Thu Nov 9 01:35:38 2017 +0100

    Rename isInit variable to be in line with other deck drivers

[33mcommit 8e62281e91623b0998ae0002de1d2dd91d3a2bc2[m
Author: Fred G <fredg02@hotmail.com>
Date:   Thu Nov 9 01:18:29 2017 +0100

    Add curly brackets

[33mcommit b8a9e14bc1d3b433d91a8718351c5bd50f87511c[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 8 10:01:04 2017 +0100

    Make variables in zranger.c static to hide from global scope. Closes #262

[33mcommit 626d98c9f7cb2d7b7a63407b911454acb6d3d5dc[m
Author: Fred G <fredg02@hotmail.com>
Date:   Tue Nov 7 02:37:15 2017 +0100

    Add buzzer deck init parameter (#237)

[33mcommit 90e27ac670fa5ed4e0aabb91c8d8dd240d355600[m
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Tue Oct 24 16:00:03 2017 +0200

    Create CONTRIBUTING.md

[33mcommit f4d21213d7ce37d7ed7338fad0f9a94a96cec191[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Oct 5 15:25:13 2017 +0200

    Fix VL53L0x driver init freeze when the sensor is not detected (#255)

[33mcommit e2c3b9ad9d6e6d0bc4320d0e03dc5ede33a54800[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Oct 5 15:22:36 2017 +0200

    Cleanup OA deck debug console print (#254)

[33mcommit 99aa78da5b510c14ace558f4b7d0b0a6c18513b7[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Oct 5 15:22:06 2017 +0200

    Remove debug printf in I2C gpio driver (#253)

[33mcommit cbb06cf32846f2028d37430b96f00891d1dfc46a[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Oct 5 14:25:29 2017 +0200

    Add OA deck driver (#254)

[33mcommit be53c5ad4d61bf03752cce997037fb8807f8f349[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Oct 4 15:47:15 2017 +0200

    ZRanger: Fix zrangerGetRange function name in sensors_bosch (#253)

[33mcommit 045d5945f89c076fa5eebbc29d9ede1ea3a3e054[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Oct 4 15:30:00 2017 +0200

    VL53L0x: Fix build issues and sanitize includes (#253)

[33mcommit e23e415fbcbeec949274864815b3ac9e8c8d73f3[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Oct 4 15:02:08 2017 +0200

    VL53L0x: Implement automatic I2C address change when init sensor (#253)

[33mcommit ae78057001a8ea79879ad60d7f38f688637a2fac[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Oct 4 14:17:55 2017 +0200

    Fixed compile warning in PCA95x4 driver (#253)

[33mcommit 43641b8774445fca3695853ae3b553dd6648c0a4[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Oct 4 14:16:39 2017 +0200

    Broke out VL53L0x code and created stand alone driver (253)

[33mcommit 2837643154cca7d0ba13f8015590f94fdade3498[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Tue Oct 3 15:23:07 2017 +0200

    Added support for PCA95X4 I2C GPIO expander (#253)

[33mcommit 0e886c2c3176e98dcff0dab8f9dfee6c488a15bd[m
Merge: bfbb9d5 7117eca
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Sep 6 07:45:25 2017 +0200

    Merge pull request #252 from theseankelly/vscodeignore
    
    Adding vscode directory to gitignore

[33mcommit 7117ecaef187ca3ce5f69660047fc4208b69d0f4[m
Author: Sean Kelly <theseankelly@outlook.com>
Date:   Tue Sep 5 13:40:23 2017 -0700

    Adding vscode directory to gitignore

[33mcommit 7cf8ebeffa55eaeb2f904c61f79357f3ea8247ea[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Aug 31 17:23:05 2017 +0200

    #251 Added more logging
    
    Added logging of anchor to anchor distances as reported by the anchors

[33mcommit e2390f508098e32d2c9311be68d352c671975ee9[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Aug 31 17:18:24 2017 +0200

    #251 Only calculate clock correction for packets with consecutive timestamps
    
    Note: I did not manage to unit test this

[33mcommit c5adebcae1dace94bab4484e227f30d5fb94ea5f[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Aug 31 14:15:03 2017 +0200

    #251 Added logging of clock compensation

[33mcommit 1a4fcdce6597085dbe64f348e0dc899173f5f988[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Aug 31 13:44:32 2017 +0200

    #251 Added handling of missing packets
    
    Sequence numbers and validity of timestamps are checked

[33mcommit 3ad6bf4a425b534c1e864485258cac6bc353b03a[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Aug 30 19:00:38 2017 +0200

    #251 Refactoring

[33mcommit adfa114b84828544188651c39d535b685c551b72[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Aug 30 17:51:05 2017 +0200

    #251 Cleaned up logging.
    
    Only store diffs for between adjacent anchors to make the logged data easy to understand. Since the anchors round robin this will be the most common case.

[33mcommit 515ca96300fb7de6c885440cf1b90604c313d386[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Aug 30 17:30:57 2017 +0200

    #251 Corrected / improved unit tests to include antenna delay in anchor-to-anchor distances

[33mcommit 55d1958b88fed9f7e76b5291d6342b4a1d749f90[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Aug 28 16:48:07 2017 +0200

    #251 First iteration of the new TDoA protocol
    
    Difference in distance and basic anchor clock drift implemented. More or less the same functionality as the previous implementations.
    It might work for flight but has only been unit tested so far.
    Sequence numbers not used yet.

[33mcommit bfbb9d5ba09cc1578b95decf8105fa3baa4a742d[m
Merge: ff1d771 ee6c2e2
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Aug 28 15:28:15 2017 +0200

    Merge pull request #250 from theseankelly/syslinkinisr
    
    Move syslink packet parsing into ISR

[33mcommit ee6c2e27ec59bfdcbf6eba7b763bf2552871a0df[m
Author: Sean Kelly <theseankelly@outlook.com>
Date:   Fri Aug 18 07:15:19 2017 -0700

    Move syslink packet parsing into ISR
    
    Handle the parsing of syslink packets in ISR and post complete packets
    to a queue. Client syslink blocks on this queue and is only woken when a
    full packet is available.
    
    This eliminates a context switch on every character received and
    possibly allows for lowering of the syslink task priority without
    risking dropped/corrupt packets.

[33mcommit ff1d7719f8f165b8a064dc0eee90a4484de47309[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Aug 18 12:34:25 2017 +0200

    Fixed tumble detection not working for all setpoints. #248

[33mcommit 7ae809eeb5b48b5d84649c713accd2d7bf3df338[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Aug 17 16:57:53 2017 +0200

    #249 Removed Crazyflie 1.0 compatibility

[33mcommit a092d7f72b34b2570a9ae2df87d5e480c9ac7b61[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Aug 17 15:45:25 2017 +0200

    Fixed RAM overflow for CF1 by removing unused accel bias. #248

[33mcommit 9b8de8275052ab2818a284d9b3e1cb1ca8ff0176[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Aug 17 15:17:51 2017 +0200

    Eanbled crash/tubled detection. Closes #248
    
    I the sitaw module the crash/tumbled detection was enabled in case the
    kalman estimator is used. Currently it is automatically used for the
    flow and the LPS decks. It checks if the attitude angle is above 60 deg
    for a period of time. If so shuts of motors until it comes back below 60
    deg again.

[33mcommit 56c6915e52f425363c6a7e1a9c79187aa4a4f6cc[m
Merge: 3a4996d 7c0d0e3
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Mon Aug 14 14:13:37 2017 +0200

    Merge pull request #247 from WoNd3RBoY/loco-pin-switch
    
    LOCO deck alternative pins for IRQ and RESET

[33mcommit 3a4996d628ee301624f266baf8b513bac17d5f27[m
Merge: eeebf6e 8a34de3
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Aug 14 14:11:37 2017 +0200

    Merge pull request #245 from jpreiss/pca9685
    
    driver for PCA9685 16-channel I2C PWM chip

[33mcommit 7c0d0e30f56a4d6674d6c7fff3ddcda1f7c23fe5[m
Author: Simon <simon.hohler@gmail.com>
Date:   Fri Aug 11 12:35:14 2017 +0200

    Loco deck has an option for alternative pins for IRQ and RESET. This is the implementation that changes to the alternative pins set in the config.mk

[33mcommit 5090faef31303f48c681217ec311ddf302c9caf8[m
Author: Simon <simon.hohler@gmail.com>
Date:   Fri Aug 11 12:22:54 2017 +0200

    Loco deck has an option for alternative pins for IRQ and RESET. This is the implementation that changes to the alternative pins set in the config.mk

[33mcommit eeebf6ef1003ef56e46565ef9ca306f2ec091183[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Aug 10 11:29:08 2017 +0200

    Removed possibility to re-init motor driver. Fixes #240

[33mcommit 8a34de39e9cb7e47702bdd69b6ef03379e9d7951[m
Author: James Preiss <japreiss@usc.edu>
Date:   Mon Aug 7 15:16:19 2017 -0700

    move queue push struct from static to local for thread safety

[33mcommit 48a757ab5deae48cda6131cf3da36c7d57414326[m
Author: James Preiss <japreiss@usc.edu>
Date:   Tue Aug 1 20:01:44 2017 -0700

    pca9685 i2c pwm support - some features missing, but can drive ESCs

[33mcommit dc3de5771fa2e1f66729b95570431089bcd465dd[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Jul 18 14:22:01 2017 +0200

     #243: Calculate LPS TWR-TDMA slot from radio addr

[33mcommit ce4d10557cf82cf7c52ea140c52879f19f94949a[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Jul 17 18:56:35 2017 +0200

     #242: LPS: Merge back optional TDMA in TWR alg.
    
    The compile flag option are kept identical. TDMA now works with
    anchor-provided anchor position.

[33mcommit 1f0ade9374ab4fb5156aa5582a6ae4627e46ff23[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Jul 5 14:43:17 2017 +0200

     #239: Flowdeck: Reduce the flow measurement delay

[33mcommit 557dc37f7c8f215e10360f8a0b53372c94d7be3b[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Jul 4 15:15:34 2017 +0200

     #239: Fixed flow behaviour when body is rotating
    
    Thanks @mgreiff for the implementation

[33mcommit 2e2fb1f5ffa1092f8af5e5e7047effc47c228386[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Sat Jul 1 11:43:54 2017 +0200

     #237: Add zranger deck init parameter

[33mcommit ab6d531c7ca70571720a50676cbc881fa2f91abc[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Jun 28 21:32:10 2017 +0200

    #234 Added support for sharing the deck SPI bus.
    
    Added spiBeginTransaction and spiEndTransaction to lock the bus so it
    can be shared. The deck drivers uSD, Loco and Flow were all updated and
    can now be used simultainiously.

[33mcommit dc08cfa10c3cb321efd112d0b688f471f2b7444a[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Jun 28 15:03:22 2017 +0200

     #236: Rename estimator to keep backward compatiblity

[33mcommit d563befa550dc83309cc970540c0eff36840f502[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Jun 27 18:29:19 2017 +0200

     #236: Fix kalman using os tick instead of stabilizer tick
    
    We need to find out why this is necessary.

[33mcommit 283df04e431dff7fa5ede4237d7ff592af9eaffd[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Jun 27 15:15:21 2017 +0200

    #236 Fixed comp.filter not reading sensors at 1khz rate.

[33mcommit 369d321ba0039549e396bc24bb3b1ae059077f02[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Jun 27 14:44:43 2017 +0200

    #236 Fixed vl53 pushing kalman data when using complementary filter.

[33mcommit 67fc9bdb3dfecff62c0f6e8b2628a9310ece5ee2[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Jun 26 16:52:06 2017 +0200

     #234: Add some ki to Z PID position loop

[33mcommit b5c16d1de798dfe4c8ebf7ef30ec33cd2c8258e1[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Jun 26 16:15:49 2017 +0200

     #234: Kalman: Re-enable RPY zero reversion when not flying

[33mcommit aedb00e7c9ff519c4038dff376189794627e7735[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Jun 26 16:14:54 2017 +0200

     #234 #236: Fix flow driver to wait for sys start

[33mcommit b318c089c806e153110b18e40adafb520aa51260[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Jun 22 17:28:21 2017 +0200

    #236 Correction for TDMA build

[33mcommit bef457ba84cbf0500e415695dc3168ceda671b42[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Jun 22 17:18:32 2017 +0200

    #236 Modifications to compile for Crazyflie 1.0

[33mcommit 3df0d3987cb311693a82abce3fde71299c3ba146[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Jun 22 16:16:28 2017 +0200

    #236 Dynamic switching between estimators based on installed deck

[33mcommit 134d8436fcf6063c87e26a0d8a4c1afc356e3bf4[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Jun 21 17:41:27 2017 +0200

    #236 added support for deck drivers to request a specific state estimator implementation

[33mcommit 97cd28a32816cb2ee00d31f3d9d76ecff81e0db4[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Jun 20 15:15:37 2017 +0200

     #234: Add generic state log variables for xyz

[33mcommit 5df1cf433d2f13dcb76aae3fcc5a6213034aa487[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Jun 15 12:10:35 2017 +0200

     #234: Update flow deck driver vid/pid

[33mcommit 8554cc7a9ac48d4bda6b1ba5b91a3476a3d4249c[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Jun 15 11:10:18 2017 +0200

     #234: Improve flow performance

[33mcommit eae6093d6a0415d7e5bf4f157c975dd5c4dcd0a3[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Jun 14 14:38:09 2017 +0200

     #234: Add hover commander packet

[33mcommit 69d5c424026b229ae8aa86e022c183879873cd52[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Jun 14 14:04:41 2017 +0200

     #234: Add license header to flow deck driver

[33mcommit 843e7cae0d23ce66f9c033801d589e51b3effa86[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Jun 14 14:02:49 2017 +0200

     #234: Flowdeck: Fix unused variable

[33mcommit 3698f099fc1c5adc21b4e1ed1fec7d9c33fdaf80[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Jun 13 16:10:54 2017 +0200

     #234: Add body-velocity PID control mode

[33mcommit df3b5a562aadd9b499030ae482db29d283d7ae7e[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Jun 13 16:09:43 2017 +0200

     #234: Update deck SPI log speed to bellow 2MHz
    
    Required for flow deck and does not affect other decks (the low
    speed is used only at startup by the Loco positioning deck)

[33mcommit eb8f0a6a60a12fb32ddfae6470662dc6c19f14ef[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Fri May 26 17:43:59 2017 +0200

     #234: Implement initial support for flow deck
    
     - Flow deck driver
     - Push flow data to the kalman filter
     - Implement flow support in the kalman filter
     - Push zRanger data to the kalman filter by default (the flow deck
       contains a vl53l0x sensor cabled the same way as in the zRanger)

[33mcommit df11f2550b819a92b56a760f34ae78a65cc3a1f1[m
Merge: 042d439 a0f539f
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue May 23 11:06:51 2017 +0200

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit 042d439b2d9f7b4e859360b85a76b5157f27c69d[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue May 23 11:04:32 2017 +0200

    Closes #232: Add altiture-hold commander packet

[33mcommit a0f539fbadf84ce6d501b1f0ecfcd4107a6acb95[m
Merge: ace55eb 043d0ef
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon May 22 13:33:12 2017 +0200

    Merge pull request #229 from jsschell/master
    
    move missed header files & bugfixes in sensors_bosch.c.

[33mcommit ace55eb6939a612e3e924c14c966e6cae830cfff[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu May 18 13:35:23 2017 +0200

    Close #212: Make LPS number of anchor configurable

[33mcommit 245275658e0c850bcdbef685d1f39bcebb5e227d[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu May 18 13:24:28 2017 +0200

    Closes #230: Number TWR anchors from 0

[33mcommit 043d0efbb0909ec6965ea9c49a0b3bc4205fe80d[m
Author: Jan Soeren Schell <jansoeren.schell@bosch-sensortec.com>
Date:   Thu May 18 11:34:41 2017 +0200

    move missed header files & bugfixes in sensors_bosch.c

[33mcommit cc4eafb5bde2cef25eb73dd5f28eca4fb7011bd6[m
Merge: b6593d0 1e9c08c
Author: Jan Sören Schell <JanSoeren.Schell@bosch-sensortec.com>
Date:   Thu May 18 11:25:27 2017 +0200

    Merge pull request #1 from bitcraze/master
    
    merge from bitcraze

[33mcommit 1e9c08c0ffc942dd0999f8b8dbbecfdfec2a84c7[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue May 16 16:00:34 2017 +0200

     #226: Add emergency stop CRTP packets
    
    See https://wiki.bitcraze.io/doc:crazyflie:crtp:localization#generic_localization

[33mcommit c0a0e427e572446f36790bbe494a821a95ac7b2a[m
Merge: 88725ac f5bd726
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue May 16 14:14:35 2017 +0200

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit 88725acf758de857a9aa94c93713ef1b341274ab[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue May 16 14:13:05 2017 +0200

     #226: Implement low level EmergencyStop

[33mcommit f5bd7268674df2ab785d1eb6bb26dd194225164e[m
Merge: 0492753 b6593d0
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon May 15 15:23:33 2017 +0200

    Merge pull request #225 from jsschell/master
    
    µSD-Card logging of sensor data & BOSCH driver update

[33mcommit b6593d05b87e2cf600f38a7e80b2cab6f218f733[m
Author: Jan Soeren Schell <jansoeren.schell@bosch-sensortec.com>
Date:   Mon May 15 14:20:19 2017 +0200

    amend

[33mcommit b62d278867f479813195285afe7a1a626973e668[m
Author: Jan Soeren Schell <jansoeren.schell@bosch-sensortec.com>
Date:   Mon May 15 14:05:44 2017 +0200

    bosch drivers in separate folder & additional indentation fixes

[33mcommit c3a38bf074cd2a0a6acb3e900bebc739ca8e8446[m
Author: Jan Soeren Schell <jansoeren.schell@bosch-sensortec.com>
Date:   Fri May 12 16:11:46 2017 +0200

    switched identation style from K&R to GNU

[33mcommit 0e68056824e58abab2d5809467610b47a8c99c8e[m
Author: Jan Soeren Schell <jansoeren.schell@bosch-sensortec.com>
Date:   Fri May 12 15:52:54 2017 +0200

    added example script for decoding & processing binary log data

[33mcommit 0b00a0bddc9e8089c1ce445c00dfa37cb7f627b4[m
Author: Jan Soeren Schell <jansoeren.schell@bosch-sensortec.com>
Date:   Fri May 12 12:48:00 2017 +0200

    correct line endings...

[33mcommit ee1623fe7e2f93b14bd633619a92e325c1fb9120[m
Author: Jan Soeren Schell <jansoeren.schell@bosch-sensortec.com>
Date:   Fri May 12 12:43:39 2017 +0200

    Revert "added debug messages to µSD-Deck & minor bugfixes"
    
    This reverts commit cf2bccac6039524d86b27ec5788f89b5d1c2c926.

[33mcommit cf2bccac6039524d86b27ec5788f89b5d1c2c926[m
Author: Jan Soeren Schell <jansoeren.schell@bosch-sensortec.com>
Date:   Fri May 12 12:37:33 2017 +0200

    added debug messages to µSD-Deck & minor bugfixes

[33mcommit 48b6028dc4041c322f86caf046349adb86b96f5e[m
Author: Jan Soeren Schell <jansoeren.schell@bosch-sensortec.com>
Date:   Thu May 11 11:59:33 2017 +0200

    params working

[33mcommit e8280462ccf6a786dfd808e420d73d8b07341d54[m
Author: Jan Soeren Schell <jansoeren.schell@bosch-sensortec.com>
Date:   Wed May 10 16:30:44 2017 +0200

    amend

[33mcommit c43a3d6350fca764e5d23a20daecf561f8227e37[m
Author: Jan Soeren Schell <jansoeren.schell@bosch-sensortec.com>
Date:   Wed May 10 16:20:54 2017 +0200

    amend

[33mcommit 90102628133a033c322e8a7b4cf0c0607e3f0a80[m
Merge: 81248f3 1f7aa2a
Author: Jan Soeren Schell <jansoeren.schell@bosch-sensortec.com>
Date:   Wed May 10 16:17:24 2017 +0200

    Merge branch 'master' of https://github.com/jsschell/crazyflie-firmware.git

[33mcommit 81248f384d090a091b68e0fc1e007c473d29678a[m
Author: Jan Soeren Schell <jansoeren.schell@bosch-sensortec.com>
Date:   Wed May 10 16:16:48 2017 +0200

    add possibility to change used gyro and accel while cf is operating

[33mcommit 1f7aa2ab627ac9517ea7124e1d5e398952f07f74[m
Author: Jan Sören Schell <JanSoeren.Schell@bosch-sensortec.com>
Date:   Wed May 10 13:27:14 2017 +0200

    Delete bmi160_filter.h
    
    only used for internal evaluation

[33mcommit d37dec5886966aeac2b16233d684ea8cde5b19f9[m
Author: Jan Soeren Schell <jansoeren.schell@bosch-sensortec.com>
Date:   Tue May 9 17:01:01 2017 +0200

    makefile

[33mcommit d423a80408e2dd492b18231f22bb783e2d46d710[m
Author: Jan Soeren Schell <jansoeren.schell@bosch-sensortec.com>
Date:   Tue May 9 16:58:17 2017 +0200

    BOSCH driver update & other improvements
    
    * updated drivers
    * bias buffer allocated from heap; freed after calibration
      -> increased heap to 40k
      - calibration reset and reallocation is possible
    * reorganized code (mostly DRY)

[33mcommit e28e8b3ba230605c73ba60ac08c9c17f86ea9791[m
Author: Jan Soeren Schell <jansoeren.schell@bosch-sensortec.com>
Date:   Tue May 9 16:41:35 2017 +0200

    µSD-Card logging of sensor data
    
    Data can be logged with up to 1kHz. in tests this worked good with a
    buffer of 100 elements. The buffer is allocated from heap, thus the task
    doesn't require a big stack.
    
    HOWTO:
    1. create config file with python module in tools/usdlog
    2. place config on µSD-Card
    3. make firmware with 'CFLAGS += -DDECK_FORCE=bcUSD'
    4. fly around with your crazyflie
    5. decode binary log with python module

[33mcommit 049275339db7f29eb40f93dbb5a4536d0041632c[m
Merge: 9748228 bdbefea
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Apr 27 16:26:25 2017 +0200

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit 9748228c39272cb560f3c79ada94cf4a14d7a8ad[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Apr 27 16:26:13 2017 +0200

    Closes #223: Remove legacy pitctrl files

[33mcommit bdbefea43cfd087a175a9c208a28b6c4d08a2699[m
Merge: c4148a0 c544e71
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Apr 24 16:39:51 2017 +0200

    Merge pull request #221 from jsschell/patch-2
    
    Update sensors_bosch.c

[33mcommit c544e7105759ff4b454e292c5a1132cd092f316d[m
Author: jsschell <JanSoeren.Schell@bosch-sensortec.com>
Date:   Fri Apr 21 12:07:26 2017 +0200

    Update sensors_bosch.c
    
    critical bugfix: uninitialized variable could cause unexpected behaviour (SensorTask could run with higher frequency)

[33mcommit c4148a09528ef8e9743af25bad2e5a869819aedb[m
Merge: b55d0ec 51f7427
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Apr 21 10:37:26 2017 +0200

    Merge branch 'master' of https://github.com/bitcraze/crazyflie-firmware.git

[33mcommit b55d0ecb501bf6d9b1507dcf87cfa68c3c5fecfc[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Apr 21 10:37:07 2017 +0200

    #211 Fixed vl53 deck driver hijacking i2c buss.
    
    The vl53 deck driver used interrupt polling and a periodic timer to read
    out sensor data. The periodic timer was running faster then the vl53
    sensor could provide values leaving the driver in a constant polling
    state. This had the consequence that the mem subsystem, having a lower
    priority, never got to read the eeprom on the same i2c buss. A
    relaxation delay was added to fix this. Also the sensor reading was
    changed from every 100ms to as fast as possible.

[33mcommit 51f742764cfa113ad8dbac71cea785e520470f82[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Apr 20 17:23:35 2017 +0200

    Closes #219: Increase the max amount of log block for CF2

[33mcommit 7f03c13ce98066001ba9a932c9af72f2f99c60ca[m
Merge: 297adc4 6584f5a
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Wed Apr 19 04:23:59 2017 -0700

    Merge pull request #218 from jsschell/patch-1
    
    LOG bugfix

[33mcommit 6584f5a5abb62b6fd1160f3026c3d2cd47c8a270[m
Author: jsschell <JanSoeren.Schell@bosch-sensortec.com>
Date:   Tue Apr 18 15:18:58 2017 +0200

    LOG bugfix
    
    logGetVarId("range", "range") returns the id of group start. Better call the log entry something else :)

[33mcommit 297adc4e1e35cc6da512c35e8e6a0f6cc539dd25[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Apr 12 17:18:53 2017 +0200

    #211 Fixed altitude hold broken by prev commit.

[33mcommit ffc5be7c6ac4fe0b963166782ba352a830248aed[m
Merge: ffefd74 890c135
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Wed Apr 12 02:24:21 2017 -0700

    Merge pull request #215 from JGSuw/uart1_h_crlf_fix
    
    converted uart1.h to unix style line endings

[33mcommit 890c135255313617e8a66ad8be5a71376773677c[m
Author: Joseph Sullivan <jgs6156@uw.edu>
Date:   Tue Apr 11 11:43:58 2017 -0700

    converted uart1.h to unix style line endings, consistent with the rest of the project

[33mcommit ffefd74d9b9a2d761ce5f57966f3d81692e4760d[m
Merge: 5048114 bae491c
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Tue Apr 11 07:26:51 2017 -0700

    Merge pull request #213 from theseankelly/rc_commander
    
    Implementation of a CPPM-like passthrough CRTP packet type

[33mcommit bae491cb8e2e74f2f349689d257f409d3f089db6[m
Author: Sean Kelly <theseankelly@outlook.com>
Date:   Mon Jan 30 19:10:34 2017 -0800

    Implementation of a CPPM-like passthrough CRTP packet type
    
    Values are represented as a set of channels which range from 1000 to
    2000 similar to how classic CPPM functions. Defaults to RPYT and has
    room for 10 additional optional auxiliary channels. Aux channel 0 is
    reserved for selecting between rate and level flight modes.
    
    Also added code to reset the pitch/roll attitude PIDs if the pitch/roll
    setpoints are set to type velocity. This prevents error from
    accumulating, which can cause unstable behavior if level mode is
    re-engaged during flight

[33mcommit 50481144836a70b6b2f96c360bb886b456192762[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Mar 30 17:17:34 2017 +0200

    #211: Add zDistance commander packet to fly at absolute height

[33mcommit b8a5b88d8daa8a862769c3eb063a36b30f381451[m
Merge: 2ba3465 054d608
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Mar 29 16:09:58 2017 +0200

    Merge branch 'master' of https://github.com/bitcraze/crazyflie-firmware.git

[33mcommit 2ba34658a4b388ae38f9bfb3fb09b707b9eb6bf5[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Mar 29 16:09:44 2017 +0200

    #211 Added inital support for z-ranger in complementary filter

[33mcommit 054d6081e5ce00eff0eaca06ac8b7513b5fc0c81[m
Merge: d864ca0 f38f495
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Mar 22 12:25:45 2017 +0100

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit d864ca0703a783e7a4c80bf12cfc68d46b7cdd3d[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Mar 22 12:25:13 2017 +0100

    Closes #210: LPS: Enable DW1000 Smart Power

[33mcommit f38f495d19d838086e2ad157742c93fd7313672c[m
Merge: ba4fc1d f0444f1
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Tue Mar 21 02:33:17 2017 -0700

    Merge pull request #208 from opsound/master
    
    Fix building with LTO=1

[33mcommit f0444f1c17b67e422d12e911f5720cc2c7b02e02[m
Author: Alex Mastro <opsound@gmail.com>
Date:   Sat Mar 18 18:13:38 2017 -0700

    Fix building with LTO=1
    
    Fixes #207

[33mcommit ba4fc1da39bccbc7b4f3f0db375f8b3fbc8d854c[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Fri Mar 3 14:55:30 2017 +0100

    #202 Updated deck data for ZRanger

[33mcommit ec188ea3325fad5a997b244608e5eab2665ea5b0[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Fri Feb 24 15:46:15 2017 +0100

    #199: Fix bug where anchor position received where not used

[33mcommit b018879d71aaf813293de26613aac1f98ec8b29c[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Fri Feb 17 14:03:18 2017 +0100

    Closes #199: Use anchor position received from LPS

[33mcommit aa892ae9fe486a2e037027b4a2b2fc009262a553[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Feb 16 17:56:00 2017 +0100

    #197 Do not try to send lppShortPacket if the Loco deck has not been initialized
    
    This prevents a crash if no Loco deck is installed and a user tries to send data from the client to an anchor.

[33mcommit 8f416d563f8e826a092e628ee6d7abea6aa21dce[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Feb 16 15:10:30 2017 +0100

    Fix build for CF1 after implementation of #197

[33mcommit 0556cbdbc6edd8921e292f5e17dfc3c5d108a33a[m
Merge: 1d312d4 c5789a3
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Feb 15 17:38:58 2017 +0100

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit 1d312d420d40605dc9c917b8c7a44179c887a383[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Feb 15 17:38:42 2017 +0100

    #197: Add unit test for LPS LPP tunneling

[33mcommit c5789a3d9b492b2c6f182f587053b079df438006[m
Merge: 48f979e 24f3d17
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Feb 15 16:30:26 2017 +0100

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit 48f979e36880cb6d3eafcd45805ecd5bfc9a6b96[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Feb 15 16:30:11 2017 +0100

    #198 Extracted memory sub system into separate files for CF1 and CF2

[33mcommit 24f3d1760ee84f5b48af43ca498153bfcabb9508[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Feb 15 16:28:46 2017 +0100

    Closes #197: Implement LPS LPP short packet CRTP tunneling

[33mcommit 87b60b20bec65d8e68b08f8a12ddb53ba699ba27[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Feb 15 15:39:31 2017 +0100

    Added Loco Anchor Position memory subsystem. Closes #198
    
    Anchor positions can now be transferred to a client using the memory sub system. The old Param way of setting anchor positions still in place for backwards compatibility.

[33mcommit 65dd816fa596621166cfeed83ad8db83697bdb6e[m
Merge: e735f32 f429d1e
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Feb 15 15:35:45 2017 +0100

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit f429d1eef9deb6be472d5b56ed0387e7a217d787[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Feb 9 16:12:15 2017 +0100

    Added mock file to pass TWR tests. #196

[33mcommit e735f32369237c3a81ee4338d72bcb0b6e24b42c[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Feb 9 15:09:59 2017 +0100

    #198 Refactoring of memory sub system

[33mcommit a48d25124c87c465088f7301a1ecf2be98229afb[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Feb 9 15:27:08 2017 +0100

    Added crtp localization service.
    
    The current external positining service has been renamed to localization
    service to handle a brauder range of requests/data. A new channel 1 has
    been allocated to handle generic data where the firs byte defines this.
    The first type implemented is the RANGE_STRAM_FLOAT which sends a stream
    of ranges in floats together with the achor ID. The stream is enabled by
    setting the parameter locSrv.enRangeStreamFP32 to 1 and when a Loco Deck
    is connected.
    
    Closes #196

[33mcommit 638ec13e9675ca60f10bda28486889412e0d0f75[m
Merge: 3a09283 f29fa90
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Tue Jan 31 11:33:52 2017 +0100

    Merge pull request #194 from theseankelly/pid_perf_fix
    
    Disable the PID output constraint for the attitude PIDs (rate/angle) …

[33mcommit f29fa905b04d31af983c57c64a82b0a7e10d24c6[m
Author: Sean Kelly <theseankelly@outlook.com>
Date:   Sun Jan 29 17:15:28 2017 -0800

    Disable the PID output constraint for the attitude PIDs (rate/angle) and correct
    how the integral limit is computed/enforced
    Fixes #185

[33mcommit 3a09283f225be7872becea623516b1ae673ee351[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Jan 26 15:36:29 2017 +0100

    #113: Move commander_generic into CRTP port 7
    
    This is to make it easier to keep backward compatibility.
    The new commander generic packet is set to port 7 channel 0,
    this was previously unused so it can be used by TX-only clients

[33mcommit 2e8ec16b80ddaf89b1ad14bc737e5b6e5b988be4[m
Merge: d79e2cf 77d0421
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Jan 26 15:02:44 2017 +0100

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit d79e2cf6cbcbd6d5e4e9790e3f46304188098364[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Jan 26 14:59:46 2017 +0100

    #113: Add new generic commander packet
    
    The generic commander packet contains type and data of the
    setpoint. The type selects a decoder function that is used to
    decode the data into a setpoint. The two first type implemented
    are:
     - Stop: stops the motors, falls if in the air
     - velocity_world: Sets CF velocity in the world coordinate

[33mcommit 77d04219f98a90594a4471720b7d08a73729be79[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Jan 25 17:19:07 2017 +0100

    #193 Only expose log data and parameters for the anchors that are actually used. Based on the LOCODECK_NR_OF_ANCHORS define.

[33mcommit d4fcbe2ec00570f765b93ff60633b7b00d975635[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Jan 25 16:32:30 2017 +0100

    Fix CF1 RAM overflow

[33mcommit c03d543e3ddc34b27a3082188b68f20f30b4b9f7[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Jan 25 15:03:53 2017 +0100

     #113: Started reorganizing commander architecture
    
    The commander is now accepting setpoint structure with a priority
    information: the function that pushes a setpoint with the highest
    priority will set the actual setpoint.
    
    Moved current Roll Pitch Yaw Thrust CRTP setpoint to its own file in
    preparation for the new 'type' CRTP setpoint.

[33mcommit 183c1dd87f61f68ab9353d5fa5f579c920d194fe[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Jan 24 13:23:19 2017 +0100

    #192: Fix log/param TOC hash calculation
    
    Closes #192. The new hash is calculated on the actual
    TOC data.

[33mcommit ff06aab1d367a62138ea9930636ce42abfedd198[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Jan 13 13:54:21 2017 +0100

    #167 More corrections to test

[33mcommit b88f1fd11ebd58e9aad1e7158ed5dec1ba8bd3b8[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Jan 13 13:13:44 2017 +0100

    #167 Corrected unit test

[33mcommit 00dea647db843dcebc0d07032245fb0319a194dd[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Jan 13 12:58:59 2017 +0100

    Removed unused member “timeBetweenMeasurements” from tdoaMeasurement_t. Closes #167

[33mcommit 0bcffe846718e27d1c1d0760493e6571d90a55b4[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Jan 12 18:12:53 2017 +0100

    #190 Keep covariance matrix symmetric

[33mcommit c0837c33241b1e8acb6257d3c09cbe289ededed5[m
Merge: 2b0958d 9f3d65e
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Jan 12 14:04:12 2017 +0100

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit 2b0958d46c02aebaba1480545c8d4b4b58a5d549[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Jan 12 14:01:30 2017 +0100

    #190 Add optional decoupling of XY from the EKF
    
    Helps flying manually with a ranging sensor for only Z. Can
    be enabled by adding in config.mk:
    
    ESTIMATOR=kalman
    CFLAGS += -DUPDATE_KALMAN_WITH_RANGING -DKALMAN_DECOUPLE_XY

[33mcommit 9f3d65e42f37071cf4cabe15a1daa971adfbb113[m
Merge: ab3bf70 eb7a953
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Thu Jan 5 16:09:24 2017 +0100

    Merge pull request #180 from estromb/EKFfix2
    
    Fix sign error on y-component of velocity update. Also change related…

[33mcommit ab3bf707fafb6aa18effcbf4d3c742a4b4acddc3[m
Merge: 650a47b 7a20c40
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Thu Jan 5 16:00:10 2017 +0100

    Merge pull request #189 from theseankelly/osdbreak
    
    Fixing the build when the OSD library is enabled

[33mcommit 7a20c406c185b4c0a6bea0d33e98e7864adb15ee[m
Author: Sean Kelly <theseankelly@outlook.com>
Date:   Wed Jan 4 20:01:07 2017 -0800

    Fixing the build when the OSD library is enabled
    in the bigquad deck code. msp.o needs to be
    added to the Makefile.

[33mcommit 650a47b9b30da407e54440d03cbd997860f94a26[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Jan 4 15:51:36 2017 +0100

    #177 Corrected compilation error

[33mcommit 0d4ba39cff7fb287be36e2b5b02b87530aa7a22f[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Jan 4 15:18:38 2017 +0100

    Corrected channel for the Loco Positioning Deck radio. Closes #188
    
    Also updated the libdw1000 submodule to use the latest commit instead of the latest of the branch. No difference in code but cleaner.

[33mcommit 97402dfd70bf2a5f77f5107fdcd4bbfccc277d42[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Jan 4 11:20:52 2017 +0100

    Updated bmi160 driver and adjusted sensor orientation for v2 bosch
    board. Improvements to #177

[33mcommit 27bc518d67c601a7263680eaef4a35568214406e[m
Merge: c4a9226 04d2b6f
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Sat Dec 31 12:41:54 2016 +0100

    Merge pull request #184 from theseankelly/buildwarn
    
    Fixing a handful of compile warnings found on the latest arm-none-eabi-gcc

[33mcommit 04d2b6f74b58f956222ca375b265a013dae9bcc0[m
Author: Sean Kelly <theseankelly@outlook.com>
Date:   Thu Dec 29 21:53:21 2016 -0800

    Fixing a handful of compile warnings found on the latest arm-none-eabi-gcc

[33mcommit c4a922649c4c99eedfb9c9bdcfb9101ca741ad4a[m
Merge: b7c7a65 95e2e8b
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Tue Dec 27 12:04:21 2016 +0100

    Merge pull request #183 from lkumar93/branch/update_readme
    
    Add instructions for compiling on Ubuntu 16.04

[33mcommit 95e2e8bc9802610b77e90d88a58ab7edff6bbed9[m
Author: Lakshman Kumar <lkumar93@umd.edu>
Date:   Fri Dec 23 22:07:55 2016 -0500

    Add instructions for compiling on Ubuntu 16.04

[33mcommit b7c7a65331b01508a6a014feab2f6d0e4b4dc461[m
Merge: f3ba4c0 05ac1c5
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Wed Dec 21 12:06:48 2016 +0100

    Merge pull request #181 from mikehamer/paper_comments_update
    
    Paper has been published, update links

[33mcommit f3ba4c0cf13b882501fa59d92a56f828841d3cfd[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Dec 20 20:58:57 2016 +0100

    VL53: Removed angle of aperture compensation
    
    This has virtually no effect on altitude estimation since
    the angle of aperture is negligible.
    
    Remove one acosf that was causing the bug #182. Effectively
    closes #182.

[33mcommit 05ac1c551bc19f4d4038965a39204230592228be[m
Author: Mike Hamer <mike@mikehamer.info>
Date:   Mon Dec 19 12:58:43 2016 +0100

    Paper has been published, update links
    
    Signed-off-by: Mike Hamer <mike@mikehamer.info>

[33mcommit eb7a953e0a96ec06b5933b2f35c3201e87a6b639[m
Author: Erik Stromberg <estromb@kth.se>
Date:   Mon Dec 19 11:23:46 2016 +0100

    Fix sign error on y-component of velocity update. Also change related comments accordingly

[33mcommit 72146a6a46e319f3af38eab6c64dcdd504466ba9[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Dec 14 11:58:53 2016 +0100

    #179 Clean up of UARTs
    
    * Renamed and moved uart.c/.h files to part_cf1 since they are only used on CF1
    * Added include to to debug.h to include the proper UART file for each platform
    * Added DEBUG_PRINT_ON_UART to the travis file to make sure it is built on each commit

[33mcommit 740ac14535a54c85e4fc025f47624f5bea196514[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Dec 7 20:29:44 2016 +0100

    Disable default anchor position enabled by mistake

[33mcommit 4ef4f68cbd2ee2f85fc2a37ba946d4b0050b5842[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Dec 7 16:09:11 2016 +0100

    Zero matrices in EKF to ensure proper reset
    
    This seems to be making the EKF reset more reliable.
    Related to bitcraze/crazyflie-lib-python#25

[33mcommit 040c1f2c6697f3d9de4fe398b74a917bc466ec21[m
Merge: 31af038 191a0bf
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Dec 6 09:35:42 2016 +0100

    Merge pull request #178 from theseankelly/osd
    
    Great and many thanks! Now I have to get a OSD to try it out, any recommendations :-)?

[33mcommit 191a0bffcb7d14473316945ce922d0874697245f[m
Author: Sean Kelly <theseankelly@outlook.com>
Date:   Sun Oct 9 20:46:05 2016 -0700

    Library that implements the MSP protocol (used for OSDs and data loggers)

[33mcommit 31af038625763b14927fcbcf90c3aff9deaeee7b[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Dec 2 17:51:28 2016 +0100

    #176 Added task dump CPU usage utility
    
    Added dump of CPU and stack usage of all tasks in the system. Trigger by setting the “system.taskDump” parameter to a non zero value. Output in the console.

[33mcommit 082298c6dcde8b3578e87b99a630dc8b03a33e14[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Dec 5 15:54:41 2016 +0100

    Fixes travis build issue for SENSORS setup as well as closing #177.

[33mcommit 8438a1a74ef1568cbbdd39bc4b3f55e6ce0cd561[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Dec 5 15:25:51 2016 +0100

    Fixed double_promotion compiler errors for Bosch files.
    
    Bosch sensor board is now working but setting of BMI160 defaults to 2G
    mode. This needs fixing.
    
    To activare bosch sensors define "SENSORS = bosch" in config.mk

[33mcommit 55645329fdc89afd2b6d104a98e50b9d8fea0365[m
Merge: eb3cac7 bf19e6e
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Dec 5 15:19:09 2016 +0100

    Merge branch 'master' of https://github.com/bitcraze/crazyflie-firmware

[33mcommit bf19e6e3ff1a62a80bc1953b8c5634fede44a2e9[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Sat Dec 3 16:13:34 2016 +0100

    Add argument variable to cload command in Makefile
    
    Allows to add argument after the flash sub-command
    of the CLOAD script.

[33mcommit eb3cac785c5074cc23314a780b4640d39f86c87f[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Dec 2 13:53:30 2016 +0100

    BMI160 settings is still a problem.

[33mcommit 0138771e28baa155bf49d9db07745e6f0dc56c28[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Dec 2 12:34:39 2016 +0100

    Updated to new BMI160 driver but accelerometer scaling is now off and
    needs to be fixed.

[33mcommit b375eff39120f755725b8cc04b5fab8a873031eb[m
Merge: ce8aee6 a7bfdec
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Dec 2 11:11:36 2016 +0100

    Merge branch 'PSVL-prevent_double_promotion'

[33mcommit a7bfdece539f35528269f2a5aeebf0d72bada0a7[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Dec 2 11:04:15 2016 +0100

    Added configuration for TDMA to travis build

[33mcommit aef06593af868cd53c372d2e8b9fbb44ac6ff00e[m
Merge: 943a4c2 ce8aee6
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Dec 2 10:44:30 2016 +0100

    Merge branch 'master' of https://github.com/bitcraze/crazyflie-firmware.git

[33mcommit e1d023b465809a7d65e2c319811ddfb01e02708b[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Thu Dec 1 12:05:08 2016 -0800

    Fix double promotion for CF1 build target.

[33mcommit ce8aee63fd4f44f9f31434ba843e3f6267940f07[m
Merge: 72e4ed0 b954bf0
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Thu Dec 1 18:55:18 2016 +0100

    Merge pull request #174 from mgreiff/EKF-ranging
    
    Add measurement update with elevation laser ranging in the EKF

[33mcommit b954bf0b5ce2bfd3774c6a467f88dd7be803ff60[m
Author: mgreiff <marcusgreiff.93@hotmail.com>
Date:   Thu Dec 1 17:13:28 2016 +0100

    Final fix to guarantee safety when not using EKF

[33mcommit d69fb2f1ccf29b2361efe1e4b7535b78648a5d24[m
Author: mgreiff <marcusgreiff.93@hotmail.com>
Date:   Thu Dec 1 15:44:18 2016 +0100

    Made implementation safe in event o not using the Kalman filter at all

[33mcommit ed8e4a2d71174836a54a5ca16a5ed4207148565b[m
Author: mgreiff <marcusgreiff.93@hotmail.com>
Date:   Thu Dec 1 12:53:57 2016 +0100

    Final functional implementation of the TOF ranging
    
    A measurement noise model has been added, allowing for smooth transition of
    elevation measurements when moving from the feasible mesurement
    region (<1.5 m) to the region where only MOCCAP/LPS is active.
    
    The implementation has been tested with TDOA and the scalar update EKF

[33mcommit 10ac7b85231eb7ff1c7f8974bb7bfbce38652dc7[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Wed Nov 30 10:32:40 2016 -0800

    libdw1000: Update submodule.

[33mcommit 943a4c2412cc034ef1f899e1f9769fe8f9c5a78d[m
Merge: a53dcae 72e4ed0
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Nov 30 11:21:30 2016 +0100

    Merge branch 'master' of https://github.com/bitcraze/crazyflie-firmware.git

[33mcommit 533e1d05ab878576ff716447141cefda47d21674[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Tue Nov 29 11:24:13 2016 -0800

    lpsTwrTdmaTag: Add a warning if the number of slots or slot is not defined.

[33mcommit ae65a539fecf09e42216b25c75c37b5d598ff0c4[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Tue Nov 29 11:23:40 2016 -0800

    libdw1000: Update libdw1000's hash.

[33mcommit 798ef936e061c80521242ad807458e46cf48fefd[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Tue Nov 29 11:20:46 2016 -0800

    Fix double-promotion issues.

[33mcommit 2119645937cc3dd43e138235a79d5227db1c8399[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Tue Nov 29 11:19:06 2016 -0800

    Makefile: Add warning for double-promotion to prevent promoting floats to doubles and no longer using the floating-point unit.

[33mcommit 832eeddfd1b668ceb1c165b7dd3b6813e68b2af0[m
Author: mgreiff <marcusgreiff.93@hotmail.com>
Date:   Tue Nov 29 14:12:18 2016 +0100

    Revised implementation, included angle of aperture and tested rigorously

[33mcommit 72e4ed0ba00dead33c4f3c7de6909ba49c73e328[m
Merge: 39831c3 df4abcf
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Nov 29 10:32:22 2016 +0100

    Merge branch 'estromb-EKF_fix'

[33mcommit df4abcf963dd02dfa42d605da74b4db0a8e39ee9[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Nov 29 10:31:31 2016 +0100

    #162 Remove static from float local variables

[33mcommit 36eedfbe19b50c8520c67f2ed72b27b07a2c9a00[m
Merge: 39831c3 32a0ed5
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Nov 29 10:25:33 2016 +0100

    Merge branch 'EKF_fix' of https://github.com/estromb/crazyflie-firmware into estromb-EKF_fix

[33mcommit 405077d281b5ce8838eecf473d8a3d20cbf9c714[m
Author: mgreiff <marcusgreiff.93@hotmail.com>
Date:   Mon Nov 28 22:55:53 2016 +0100

    Changed default setting to not update the EKF with the ranging measurements

[33mcommit 0e281a30f7e8b1da9793b2eaf792efbc0d71165d[m
Author: mgreiff <marcusgreiff.93@hotmail.com>
Date:   Mon Nov 28 22:40:55 2016 +0100

    Add measurement update with elevation laser ranging in the EKF

[33mcommit 39831c3b844577c080c0b576b40bdbc5308348da[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Mon Nov 28 22:21:08 2016 +0100

    Fix altitude-hold by adding estimated Z velocity

[33mcommit 1952d2cb40af6b154be99d760c7855977c8f9446[m
Merge: 175f595 6c4c96f
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Mon Nov 28 21:56:01 2016 +0100

    Merge pull request #172 from PSVL/althold_fix
    
    Allow velocity only modes and remove const modifier to setpoint in th…

[33mcommit 6c4c96f126a9f10c4ae22de32be85141323ba14b[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Fri Nov 18 10:44:54 2016 -0800

    Allow velocity only modes and remove const modifier to setpoint in the pid controller.

[33mcommit 175f595ba1ad69141a7c1b70b80aa418757d5617[m
Author: Arnaud Taffanel <arnaud@bitcraze.io>
Date:   Mon Nov 28 19:20:04 2016 +0100

    Run the bootloader client as a Python module
    
    Closes #171.

[33mcommit a53dcae9043d6a88045c6d616cf93d6748fd34ed[m
Merge: 523e72c 7a3910e
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Nov 28 15:12:28 2016 +0100

    Merge branch 'master' of https://github.com/bitcraze/crazyflie-firmware.git

[33mcommit 523e72ce4d5b5d85c0487af692c86b66b4afb70d[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Nov 25 12:56:10 2016 +0100

    Updated makefile with SENSORS config (cf1, cf2 or bosch) to select
    sensor setup. Disabled -Werror for debug build.

[33mcommit 7a3910e5af5aa07f5cbed3f61cb6aeece09c41a5[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Nov 25 10:08:08 2016 +0100

    #166 Added detection of missing packets between anchors in tdoa
    
    Updated std dev for the kalman estimator and size of acceptance box

[33mcommit 22fb7d7ad5a83cdad8612480fb985a577e150c53[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Nov 25 07:29:29 2016 +0100

    #166 Added packet counters for logging of statistics in tdoa

[33mcommit 8a4477b3fb07ebcb5b201136aeeac146e39d5054[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Nov 25 07:07:35 2016 +0100

    #166 Updated unit tests for tdoa
    
    Now using more realistic times for the messages. Grouped messages in frames as transmitted by the anchors.

[33mcommit 4f0594f3c51489a904e742e7574f884ac8d11640[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Nov 24 15:57:28 2016 +0100

    #167 Improve EKF distance difference update
    
    Remove extra process noise added when feeding distance
    difference and remove variance calculation, update
    directly with stdDev instead.

[33mcommit d61484994ce31de0d8f477c118872ff8bfc13a79[m
Merge: ba6fa4d c012b67
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Nov 24 13:52:04 2016 +0100

    Merge branch 'PSVL-pid_update'

[33mcommit c012b6755e0893219cfff809a7e19e17198ad865[m
Merge: ba6fa4d da5152d
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Nov 24 13:46:08 2016 +0100

    Merge branch 'pid_update' of git://github.com/PSVL/crazyflie-firmware into PSVL-pid_update

[33mcommit f865ba4f2a07f234d869ad8fe7493dbbeb974a3e[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Nov 24 11:57:16 2016 +0100

    Updated and adapted to newer BMI160 driver.

[33mcommit ba6fa4d44ad754894a2c6abea85890e7be426a5d[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Nov 24 11:07:33 2016 +0100

    #165 Refactoring of lpsTdoaTag.c

[33mcommit f8d9c2c82753c98a8bf30b818acf1bb869958e34[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 23 18:51:13 2016 +0100

    #165 TDOA using previous message as reference instead of always using anchor 0

[33mcommit 5136590d456bcd17ff0b09d246febb9adeb757f4[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Nov 23 17:15:50 2016 +0100

    Initial flight with bosch sensor deck and new sensor architecture.

[33mcommit 143aebc279ffaeca2ae5fe46af93d931e02b43f0[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 23 14:38:40 2016 +0100

    #163 Corrections to remove unused variables due to build configuration

[33mcommit 6ecbff017254bd8101b141969203a05d710ae622[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 23 14:19:06 2016 +0100

    #163 Changed API for tdoa kalman estimator.
    
    Now uses difference in distance instead of absolute times.

[33mcommit 23197b286a1d15f99aafec0b64f7304fd171ae34[m
Merge: 6f650f9 574d43d
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Nov 22 14:31:28 2016 +0100

    Merge branch 'master' of https://github.com/bitcraze/crazyflie-firmware.git

[33mcommit 6f650f99b7cd6f8bb961bc0610454904dd4880a6[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Nov 22 14:31:08 2016 +0100

    Changes Micro-SD deck PID to not confligt with GT-GPS. Now PID=8. Closes
    #164

[33mcommit 32a0ed50bb6c7002984feacd776ce7cc841becd2[m
Author: Erik Stromberg <estromb@kth.se>
Date:   Mon Nov 21 09:53:02 2016 +0100

    Apply same overwrite fix to else-clause as well

[33mcommit da5152d138ecd91cdb91a2989d3d934a3ccfe3ac[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Fri Nov 18 17:07:14 2016 -0800

    commander: Revert changes thrust changes.

[33mcommit 987dfc880e3dca832b28962db623508c0f83a852[m
Author: Erik Stromberg <estromb@kth.se>
Date:   Fri Nov 18 15:02:05 2016 +0100

    Change variables pertaining to state update in predict to static

[33mcommit e4b3e0462bfd23512aaed921eb27905d50ccaadd[m
Author: Erik Stromberg <estromb@kth.se>
Date:   Fri Nov 18 14:24:59 2016 +0100

    Add tmp variables for state in prediction update in order not to overwrite previous time step while updating

[33mcommit 574d43dd6ab999c11a8035b2403859ada9861af9[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Nov 18 10:44:42 2016 +0100

    More unit testing of TDOA and Kalman estimator
    
    Also added full reset of inner state of the lpsTdoaTag module between tests. Ironed out a bug.

[33mcommit a92a1fb13c18d1183895b0f97b26ea3c691ef35e[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Nov 18 08:34:24 2016 +0100

    Added unit test for basic call to Kalman filter from TDOA code

[33mcommit eaca6703f275e1e08af67822adfc49eef880d10a[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Nov 17 21:27:22 2016 +0100

    Refactoring of tdoa unit test

[33mcommit c3eee25ff95bea4f44d2aa056059d1fba9bfdf1e[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Nov 17 21:09:40 2016 +0100

    Updated unit tests (rake) to be called from make.
    
    The reason is that make manages the build configuration (defines and so on) and we want to reuse them in the unit tests. When rake is called from make, all defines (actually compiler flags) are passed on to rake to be used when building the unit tests.
    Also added a light weight “annotation” that allows unit test files to be excluded based on defines.

[33mcommit 157fb23dee91c2c5dc28ff7275a6014411c96b2a[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 16 17:17:06 2016 +0100

    Refactoring of TDOA code. Updated variable names

[33mcommit 001d3515541160eb9b0603f7c336f47f3c87cdc8[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 16 12:02:20 2016 +0100

    Removed CMSIS files from src/lib/CMSIS that are not used any more as we have SMSIS in vendor

[33mcommit 8dc02b7988896b12644e8f6cf2ce16bd6cd3da7f[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 16 11:15:33 2016 +0100

    Corrected rake file to support calls to rake without target

[33mcommit 75c8bc861df85ec9a0791aa7800a83bf26a3511c[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Nov 15 13:27:48 2016 +0100

    LPS TWR: Add statistics on ranging success

[33mcommit 58aa5620c6939556345badd7627e060201fb725d[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Nov 15 08:06:00 2016 +0100

    Added support for more compiler flags to unit test rake file

[33mcommit a497507b2f461a32e05f0877a6e413dd3c72883a[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Nov 15 08:04:32 2016 +0100

    Re-enabled unit test for lpsTwrTag.c. Added workaround for problems with arm_math.h mocking. Need further work.

[33mcommit c90273259659bf961166f649c8f56235c57cad52[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Nov 14 23:07:54 2016 +0100

    Renamed unit test for LpsTwrTag temporarily to make build pass on travis until issue with arm_math.h mocks has been resolved

[33mcommit 5e6833f4300e1e7bd5fce6013a4507601de0719a[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Nov 14 22:22:41 2016 +0100

    Support for passing build flags (defines) to unit tests from command line. Unit tests now runs with the same defines as the build of the production code in travis builds.

[33mcommit 4dd3d2ccbd186ad7b0e2922044e3ebd4f09358f3[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Nov 14 16:22:46 2016 +0100

    Touch up on styling of TDoA code and tests. Prepared for testing the call to the Kalman estimator by adding the mock, still requires some changes to the rake file to be testable though.

[33mcommit f61c3c2da2acc97f543a54b4bef7d31084477c8f[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Fri Nov 11 14:58:33 2016 -0800

    commander: Don't set thrust when no modes are active.

[33mcommit 1319a8c75a96fe4d80cca68c8458cbfdee2bb7f0[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Fri Nov 11 11:01:40 2016 -0800

    commander: Change commander packet to be a float instead. Rework ordering of when thrust command is sent.

[33mcommit 8c97090409454cf0f0844fcc56368961f668c643[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Fri Nov 11 10:52:38 2016 -0800

    attitude_pid_controller: Add roll, pitch, and yaw rate limits to the pid controller.

[33mcommit d2b0c53fa78e543e9db525a8291754aec99e9a69[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Fri Nov 11 10:45:38 2016 -0800

    position_controller: Set proper caps on the velocity pid and add xy & z velocity max as a parameter.

[33mcommit 9c578e158b2c69530207434e60a3b7284087df27[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Fri Nov 11 10:42:22 2016 -0800

    num: Add an isnan macro.

[33mcommit 16f68453c63e83f7676b7b99d1ab56e473ae32ad[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Fri Nov 11 09:07:43 2016 -0800

    pid: Tweak when integration is capped. Remove errorMax and use outputLimit instead.

[33mcommit 8ba1ea1585cbfc1e907871983d9605dfe67c8678[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Nov 11 17:22:14 2016 +0100

    TDOA: Added pushing of TDOA data into kalman filter. Not tested yet.

[33mcommit a9a7ac0b24e153bd44be4b3c78bc9e0817d37f78[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Thu Nov 10 16:23:21 2016 +0100

    Fixed TDoA testcase for missing packages

[33mcommit 1a23e6bfffcea2316c2ebcddc5b78c6ecb1cc45b[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Nov 10 16:12:53 2016 +0100

    Checking for insane distance difference values.

[33mcommit a31b1e3c8a7ead1f6348e6d2bf5c7c3aac616223[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Nov 9 16:09:58 2016 +0100

    Corrections to TDoA

[33mcommit 00e17b7bc4c046bd014f41080e58ecc1610aaaf5[m
Merge: a4b4c61 3694af4
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Nov 9 13:58:33 2016 +0100

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit a4b4c61bf6ce00f47bfe1c63a80c7aa38d6787ba[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Nov 9 13:13:53 2016 +0100

    Lopo TDoA: Add timestamp wrapping handling

[33mcommit 3694af45b705117026d833e94cc32c9ea28d8d53[m
Merge: 843bd05 03cf9ff
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Wed Nov 9 10:21:39 2016 +0100

    Merge pull request #159 from lkumar93/master
    
    Log additional variables and fix a bug

[33mcommit 843bd05edb1f81826faa20b653481afed53b2805[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Nov 4 11:20:15 2016 +0100

    Added logging of TDOA data

[33mcommit 7ea472ab348f9b04455a53ad8a0c76366436e712[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Nov 3 17:17:17 2016 +0100

    Implementation of TDOA

[33mcommit 03cf9ff9db45ab3640e23fed351e532c8658d2b5[m
Author: Lakshman Kumar K N <lkumar93@umd.edu>
Date:   Thu Nov 3 08:53:51 2016 -0400

    Create a log group for sensfusion6 variables

[33mcommit 3db3a68e142ddb81e1c719546fcabfcd273413fb[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Nov 3 11:11:00 2016 +0100

    LPS: Add example for static anchor postions

[33mcommit c1da0aee34acefdc9ca22cfb129a88c184d33ef8[m
Author: Lakshman Kumar K N <lkumar93@umd.edu>
Date:   Wed Nov 2 21:48:37 2016 -0400

    Correct a bug in param group naming

[33mcommit 39ed6746a417e31dc581e2f742407f2c3ce02253[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Nov 2 14:37:36 2016 +0100

    LPS Deck: Fixed TWR TDMA

[33mcommit 985fd5863468675a5952745e905ada77e5f78f90[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Oct 31 16:42:14 2016 +0100

    Added empty files to start development of TDOA functionality for the Loco Position deck

[33mcommit ed401e108e080a69bba9d574cfc4ed18d37f9eef[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Oct 28 19:08:28 2016 +0200

    Introduced address type for LPS packets

[33mcommit 8aedb256de5b14a77506948ee8b8d883181050f8[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Oct 28 17:02:10 2016 +0200

    Refactoring of lpsTwr code

[33mcommit c9b01b022016c63ce7faa29802d4838d8ade7e3d[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Oct 28 14:49:47 2016 +0200

    Refactoring of unittest

[33mcommit 7bc39efdad74343b8d37cd72970c6c22fe2e4370[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Oct 28 14:13:17 2016 +0200

    Build tdma on travis

[33mcommit a884506ca7059147ce4fde799e29445bd3fc96d5[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Oct 28 13:36:07 2016 +0200

    Added unit test for full ranging sequence in lpsTwrTag

[33mcommit 1cea696768838efe9ad33d59151416af1b6b51c5[m
Merge: eb6a1c8 4633a15
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Fri Oct 28 10:32:49 2016 +0200

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit eb6a1c8cc27a95c67d9df75338efc6c540a56886[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Fri Oct 28 10:32:12 2016 +0200

    Fix TDMA after interface change
    
    Also add back missing anchors

[33mcommit 4633a15552182131590126c55570bf658d2d988e[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Oct 28 09:02:43 2016 +0200

    Corrected initialisation of the txPacket in lpsTwrTag.c

[33mcommit 162cbf662295452314ea3d09078a0587f31f82ac[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Oct 27 18:42:05 2016 +0200

    Corrections for kalman implementation after data move

[33mcommit eebe15c62e1904b573aa56d65738fb77b938bc9d[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Oct 27 17:10:22 2016 +0200

    Moved data from lpsTwrTag.c locodeck.c

[33mcommit e4ca13952135f699ae81fba5b783b568bc0135d9[m
Merge: 517c583 422c5a9
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Oct 27 13:58:20 2016 +0200

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit 517c583e482c064620815ba56bd37c0385d81e23[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Oct 27 13:47:39 2016 +0200

    Add back TDMA two way ranging
    
    Allows to fly more than 1 Crazyflie with ranging.
    
    To enable TDMA add to tools/make/config.mk:
    LPS_TDMA_ENABLE=1
    
    Then to fly two copter add:
    CFLAGS += -DTDMA_NSLOTS_BITS=1 -DTDMA_SLOT=0  # first
    CFLAGS += -DTDMA_NSLOTS_BITS=1 -DTDMA_SLOT=1  # second
    
    The system will run with 2^TDMA_NSLOTS_BITS slots. So to fly
    between 3 and 4 Crazyflie set TDMA_NSLOTS_BITS=2, up to 8 set
    TDMA_NSLOTS_BITS=3, etc .....
    Each time slot is 4ms long so adding more slot will slow down
    the ranging rate.

[33mcommit 422c5a98b87d1cae26970e3eb1c81f4c79d493f4[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Oct 27 11:42:04 2016 +0200

    Added more unit tests

[33mcommit c551954123448b2f32a74fa5d735f40f907d5802[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Oct 26 20:39:10 2016 +0200

    Upgraded test scripts to take list of tests to run. If no tests are supplied all tests are run.

[33mcommit ca21c53e694ba4c24bc82c46ed7713a792fb35ed[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Oct 26 20:22:55 2016 +0200

    Added more unit tests for lpsTwrTag.c

[33mcommit 4581097950a6f89bc83c440ac335c191c2dda7ff[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Oct 26 17:01:35 2016 +0200

    Added simple unit test for LpsTwrTag.c

[33mcommit c7f1d08c32e32b7f5bc110f106572c7163047bab[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Oct 26 13:39:29 2016 +0200

    Separated LPS ranging algorithm in own file
    
    This commit also disables TDMA. Has to be added back in another
    commit.

[33mcommit 876a78db204bcbad445852557896b342cf08d9e5[m
Merge: 6db17a2 98095dc
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Oct 25 12:41:58 2016 +0200

    Merge branch 'PSVL-filter_everything'

[33mcommit 98095dc8bca20a37a9784def17ebc0909a240cd1[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Oct 25 12:37:24 2016 +0200

    Make the controller LPF filter configurable
    
    Disable LPF for attitude and rate loop as its benefits is
    not clear. Keep is enabled for position loop where enhancement
    was observed in altitude stability.

[33mcommit 1ba6626a77c2e842efc6e06377b9e05be8078523[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Oct 25 10:40:33 2016 +0200

    Revert "pid: Remove lpf filter on D until it seems worth it."
    
    This reverts commit 5bd3f139833c29af70de0cecb34b379596f3171a.

[33mcommit 35df63618f3018e1c1e6eb03008174bbb84a4d34[m
Merge: 6db17a2 5bd3f13
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Oct 25 10:37:42 2016 +0200

    Merge branch 'filter_everything' of git://github.com/PSVL/crazyflie-firmware into PSVL-filter_everything

[33mcommit 6db17a25793aa315912d6ef4eeb515f31e6c2d48[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Oct 24 15:26:42 2016 +0200

    Updated cmock and unity

[33mcommit 5bd3f139833c29af70de0cecb34b379596f3171a[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Thu Oct 20 15:12:35 2016 -0700

    pid: Remove lpf filter on D until it seems worth it.

[33mcommit 634a27c26588dc7691b1b82660dcba4764163cfd[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Oct 20 17:02:05 2016 +0200

    Removed SD card logging functionality used while developing SD card code.

[33mcommit 49d4c1da03a2b79f9683435d1c4822daf03a5dbf[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Oct 20 16:27:24 2016 +0200

    Refactoring, renamed functions in fatfs

[33mcommit fc98aa27bf8a087b827ffbe6b6bb92c80c1ee56f[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Oct 20 16:22:26 2016 +0200

    Added FatFS diskio function tests. Configured usddeck usedGpio and
    usedPerif.

[33mcommit 7df100ab1ca2eff168a74179bd504f2e33970f78[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Oct 20 15:50:28 2016 +0200

    Renamed ops to context in fatfs

[33mcommit e5035bec6b6f5a011c0644d074e66ac522309be9[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Oct 20 15:25:51 2016 +0200

    Refactoring of fatfs_sd.c

[33mcommit bb7d4f87cb7094fbd2b4514c64a61a6d3a95b5cd[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Oct 20 13:48:57 2016 +0200

    Moved FatFS files to more logical folders.

[33mcommit 1936e3de65757cf4c1d917a6dfef858ad7e74ddf[m
Merge: 93f1e37 c46bee8
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Oct 20 12:20:40 2016 +0200

    Merge branch 'sdcard-logging'
    
    # Conflicts:
    #	Makefile

[33mcommit 13fea77798bf908e4ae709d0cb41a4537eeb0b53[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Wed Oct 19 16:42:09 2016 -0700

    controller_pid: Initialize and reset pids for the velocity controller.

[33mcommit c3c72d7414aca1c907f16acb9c7a1fc627c35500[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Wed Oct 19 16:41:26 2016 -0700

    position_controller_pid: Add a velocity PID controller that takes it's input from the position PID and outputs to the roll and pitch PIDs.

[33mcommit 2ca9c681e0b9f98f8e1729120caad98d042b418d[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Wed Oct 19 16:39:19 2016 -0700

    num: Add an absolute value macro.

[33mcommit fcf4629c1174d9dca65ea7c53674ffe474e773ab[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Wed Oct 19 16:37:11 2016 -0700

    pid: Add an error max term and a bool to cap the intergral term.

[33mcommit c46bee8598ab49a01a5756227ea0e36cea46928e[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Oct 20 01:15:52 2016 +0200

    Added timer and moved instance data to uSD card deck driver

[33mcommit 55d08a9be86ab5bdeb2ae2047519f701c2ddb097[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Wed Oct 19 15:37:03 2016 -0700

    attitude_pid_controller: Increase attitude and attitude rate cutoff frequencies to 15 Hz and 30 Hz respectively.

[33mcommit d6648be5c24cf278842671fa5cf2fdc0fbc433d1[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Wed Oct 19 15:36:14 2016 -0700

    sensors_cf2: Reduce gyro cutoff freq to 80 Hz.

[33mcommit 1bd282c429e89de4e5f341f91b3ab66eb69d26b9[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Oct 19 15:57:28 2016 +0200

    Removed logging used during development

[33mcommit 6d618c21e8ceb0eef45714eff1489b3687f7269d[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Oct 19 15:48:26 2016 +0200

    Make sure it compiles for CF1

[33mcommit b0509f824dae66ca2549a817f9c1bbbe2b7f2cc0[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Oct 19 14:00:18 2016 +0200

    Fixed FatFS CMD0 which caused SD-card init to fail. Removed tm_* files
    from FATFS.

[33mcommit 02ecf5a18f2a076c9595e756deaad9558ea8425b[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Oct 19 13:13:05 2016 +0200

    Ported FATFS low lever driver to use deck_spi driver.

[33mcommit 3003b952bd687db442718029cb4a8fd07f2f6c83[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Mon Oct 17 16:52:14 2016 -0700

    attitude_pid_controller: Set the attitude cutoff freq to 10 Hz and the attitude rate cutoff freq to 20 Hz.

[33mcommit 29c8816b626108dbb0a672529d36039ef9a2b1eb[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Mon Oct 17 16:48:01 2016 -0700

    controller_pid: Move attitude and position rates to stabilizer types. Add rate logging.

[33mcommit 90f7b84c20b36510074bf7c6f0bef8c9d8928642[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Mon Oct 17 16:47:03 2016 -0700

    position_controller_pid: Apply a LPF with a cutoff of 3 Hz to the position D term. Add some more logging.

[33mcommit ff15bbe9a4d30e6335d02528c26fa37d33097df2[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Mon Oct 17 16:38:04 2016 -0700

    estimator_kalman: Add the quaternions as log values for displaying the orientation.

[33mcommit 9a9e9006e4a15a78d038fce48e1d101a7dbcb4e4[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Mon Oct 17 16:37:12 2016 -0700

    pid: Add a low pass filter for the D term.

[33mcommit a3b26c208c12e47fa4a8ef2a25f2eb576379b71b[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Mon Oct 17 16:31:01 2016 -0700

    sensors_cf2: Add a low pass filter for the gyro with a cutoff frequency of 100 Hz.

[33mcommit e83e7da0560b1741ceec94dda1c1efdf29fa6f64[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Mon Oct 17 16:16:05 2016 -0700

    filter: Add cutoff frequency setting and reset function for the 2 pole low pass filter.

[33mcommit 93f1e376450e65a58eca5bb4af12ac85ae7b91d1[m
Merge: 2cd2ab8 0c0ad76
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Mon Oct 17 13:57:44 2016 +0200

    Merge pull request #157 from aswild/master
    
    README: Add build instructions for Windows

[33mcommit 0c0ad764e77a0cec4489f1e7e81999a0e120aa26[m
Author: Allen Wild <aswild@users.noreply.github.com>
Date:   Sat Oct 15 14:22:08 2016 -0400

    README: Add build instructions for Windows

[33mcommit 2cd2ab8f9bd60d06eac4091e48b278551b29dfc2[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Oct 13 10:38:38 2016 +0200

    Put vl53l0x deck driver VID:PID to zero to not interfere with test deck
    board.

[33mcommit b64ba70a4f0800ca3e22f5e5dc77e927de23aeba[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Oct 12 09:30:29 2016 +0200

    Added usdDeck queue check and lowered priority of the usdTask to avoid
    watchdog kicking in sometimes.

[33mcommit e891d9c48801ae27a2fa936146d98be4f2fb54fe[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Oct 11 22:42:22 2016 +0200

    Fixed compiler warnings which becomes error in CLOAD build.

[33mcommit 343aa630dd86e0094400a026f9e83e5c06c883cb[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Oct 11 21:24:12 2016 +0200

    Added fatfs_sd.c and fatfs_sd.h which previously where forgotten.

[33mcommit 69b8d9394df464580395da291559c93a504b579d[m
Merge: 0840732 6493a3e
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Oct 11 14:53:22 2016 +0200

    Merge pull request #150 from USC-ACTLab/devBroadcasting
    
    Broadcast support

[33mcommit 08407321b66e5c6009328f51931c14b6655e856d[m
Merge: 71bbf60 049776e
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Oct 11 14:48:19 2016 +0200

    Merge pull request #156 from PSVL/master.vl53l0x_driver
    
    VL53L0X Time of Flight Sensor Driver

[33mcommit 049776eb77bf31688f31d30486418df2d18dafd4[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Mon Oct 10 11:57:35 2016 -0700

    i2cdev_f405: Cleanup handling of no mem addresses.

[33mcommit f5355d9418fddb5ac13d3e93321a04bbee24ed59[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Mon Oct 10 11:54:09 2016 -0700

    sensors_cf2: Revert to master.

[33mcommit bff2cde5ed3626aa42c090f09e38c12c0c6e2e5d[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Mon Oct 10 11:52:11 2016 -0700

    vl53l0x: Use deck driver scheme for starting driver. Log data to 'range'.

[33mcommit b18053e40f2bd4a4184a1e51fd9ce5cb07e25948[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Mon Oct 10 11:51:11 2016 -0700

    sensors_cf2: Remove vl53l0x items from file.

[33mcommit 7bf29d042894faf201d4bfe513573eb751e7be4a[m
Merge: 5113718 71bbf60
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Thu Oct 6 13:42:39 2016 -0700

    Merge branch 'master' into master.vl53l0x_driver

[33mcommit 71bbf601f82a3aee53cc96d2a530a4b8c70c1696[m
Merge: 14451ff 1b07418
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Thu Sep 29 16:42:30 2016 +0200

    Merge pull request #153 from mikehamer/full_kinematics
    
    Added full kinematics for the not flying case

[33mcommit 1b0741869ed68130045ed8f707c78943f6ac9a94[m
Author: Mike Hamer <mike@mikehamer.info>
Date:   Thu Sep 29 12:03:54 2016 +0200

    Added full kinematics for the not flying case
    
    This improves the state estimate for cases where the quad is being carried, or in free fall. The quad's position is no longer constrained to being on the ground when the props aren't spinning, and body velocities are no longer constrained to zero.
    
    Signed-off-by: Mike Hamer <mike@mikehamer.info>

[33mcommit 14451ff68a23f74b569f0f1a38d4394b24c2649b[m
Merge: 43d9edb fdaa4e4
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Sep 28 15:28:53 2016 +0200

    Merge branch 'PSVL-master.accel_config_changes' with aditional changed

[33mcommit fdaa4e4213dd9f392a386617a195d7baa706572e[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Sep 28 15:28:11 2016 +0200

    Updated comments for setting sensor sample rate. Changed acc dlpf to
    always be active and @41Hz. Added Ki to pidZ in position controller.

[33mcommit e462565c9227cd463e894dad8f68813ccf910354[m
Merge: 43d9edb 6b24168
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Sep 28 14:20:01 2016 +0200

    Merge branch 'master.accel_config_changes' of https://github.com/PSVL/crazyflie-firmware into PSVL-master.accel_config_changes

[33mcommit 259502b756d82b8ea282bab44f4da8a84bcc03c2[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Sep 28 13:57:03 2016 +0200

    Added missing usddeck.h file.

[33mcommit b6b4b5a52fa16a8a869c4581761cade78d602327[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Sep 28 11:59:09 2016 +0200

    Added right green LED blinking when writing to uSD card.

[33mcommit b7a781210275358a8b61019b089150c2018d3015[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Sep 28 11:41:49 2016 +0200

    Basic binary uSD logging working.

[33mcommit d28d2451d215e2375d80518660a658ad3a535948[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Sep 27 19:13:52 2016 +0200

    Added FatFS lib and configured it.

[33mcommit 6b24168a08b7959c9290b970d53b6d1f5fb1ac3a[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Mon Sep 26 10:42:53 2016 -0700

    sensors_cf2: Apply a 30hz 2pole low pass to the accel data.

[33mcommit 248b67033085f8668d8c5c756b61fe4878f624a8[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Mon Sep 26 10:42:21 2016 -0700

    filter: Add a 2 pole low pass filter.

[33mcommit 43d9edb7771696ef9775daa57fecd57fe22cd33f[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Mon Sep 26 12:52:48 2016 +0200

    Updated libdw1000

[33mcommit 6493a3e2930ff0f8e3408af16e4a7eeed4679cde[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Thu Apr 28 16:04:53 2016 -0700

    support for broadcasting

[33mcommit aee7404aab4ad28eeac54702d7cf2e35e92415bc[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Thu Sep 22 16:34:36 2016 -0700

    sensors_cf2: Increase accel range to 16g, increase update rate to 1kHz, and set DLPF to 42Hz.

[33mcommit 7ba1a2fbbe5ad2aadbca5229d033cfc617b5f371[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Sep 22 11:39:39 2016 +0200

    Yet another missing file from the merge.

[33mcommit b21795fff2c711ca1056437badfc7f27127640e6[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Sep 22 11:27:52 2016 +0200

    Added missing header file ext_position.c

[33mcommit 6de93c8c4f7fb9495fc4532c5805c6096f216f7a[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Sep 22 11:16:15 2016 +0200

    Files where not added in merge. Adding files

[33mcommit a19680b8fc7fca550f89a15fc02a32c1c729a306[m
Merge: da09442 1424bf8
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Sep 22 11:12:37 2016 +0200

    Merge branch 'master' of https://github.com/bitcraze/crazyflie-firmware.git

[33mcommit da0944237a6cc73e99cc73e658aa21a0ad6645c0[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Sep 22 10:24:30 2016 +0200

    Fixed failing LPS25H self test due to reading temp register wrong when
    moving avg filter is activated. Closes #149

[33mcommit 1424bf8a9dc12952a3efc77c720d428107bce151[m
Merge: 3ca3d35 b5ca42c
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Wed Sep 21 23:39:38 2016 -0700

    Merge pull request #147 from stephanbro/master.crtp_position_update
    
    Master.crtp position update

[33mcommit b5ca42c30d32ff6fce216e948822d4cfec013345[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Wed Sep 21 10:57:47 2016 -0700

    libdw1000: Point submodule back to master.

[33mcommit 0e2af452c87bec552dfccb2eaa6ad8ce82856eed[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Wed Sep 21 10:57:25 2016 -0700

    Makefile: Remove unnecessary define.

[33mcommit b93481fffb572f19fd2b07fe87ab214301b4aad6[m
Merge: 2746b6c 3ca3d35
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Wed Sep 21 10:55:55 2016 -0700

    Merge branch 'master' into master.crtp_position_update

[33mcommit 2746b6c4ad648f99463a45c79a9fc3bb88cdc0c1[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Wed Sep 21 10:55:35 2016 -0700

    ext_position: Move handling of external position information to it's own file.

[33mcommit 51137183decddb4d1694df8181e524f486c27986[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Tue Sep 20 13:47:51 2016 -0700

    sensors_cf2: Basic init of the vl53l0x sensor and periodic ranging updates.

[33mcommit 7bdf7c8b1bbf1c81f4d90b477821e0cb0a5c9d5b[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Tue Sep 20 13:46:21 2016 -0700

    i2cdev: I2CDEV_NO_MEM_ADDR has a conflict with the vl53l0x driver which talks to that register value.

[33mcommit 6201a5ec1788f758d1b3172d822d68769617d136[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Tue Sep 20 13:45:27 2016 -0700

    Makefile: Add vl53l0x object to the linker

[33mcommit 7d7a2626e561c2f48886a1add2ccdab32a8e9e36[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Tue Sep 20 13:44:53 2016 -0700

    vl53l0x: Initial commit for vl53l0x time of flight sensor deck.

[33mcommit 3ca3d3513e9e5258e451ced3b419d57165aeea1b[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Sep 20 11:37:52 2016 +0200

    Fix of LPS25H temperature reading when moving avg filter is activated.
    
    Reading of LPS25H temp register must be done in separate read as the
    register auto increment pointer wraps around in the pressure registers
    when FIFO mode is enabled. As described in AN4450 5.1 from ST. Closes
    #149

[33mcommit 0e842f2e5aa71dc9b21cd8d19d2fe5921e3663cd[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Sep 19 21:54:14 2016 +0200

    Removed SENSORS_task ifdef which failed kalman build.

[33mcommit 3aab01f4288257bbdbac7862b4bf8e94279d844b[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Fri Sep 16 17:43:11 2016 -0700

    gitignore: Ignore exuberant ctags output.

[33mcommit 1f5c625ed6894497ba41891f083af2b862fead5e[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Fri Sep 16 17:25:19 2016 -0700

    Makefile: Add missing sensor task define.

[33mcommit 3d884e304784bd004c5b20537b32d42808a35bb5[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Fri Sep 16 15:19:02 2016 -0700

    eskylink: Change to port name to CRTP_PORT_SETPOINT.

[33mcommit a4d42e88ddb16810625cb28bf3d65b382cd446ff[m
Merge: 7e8bebe 376a1de
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Fri Sep 16 14:48:54 2016 -0700

    Merge branch 'master' into master.crtp_position_update

[33mcommit 7e8bebe1919e8cfe9c14ed27663bc1ac7ebfafe9[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Fri Sep 16 14:46:37 2016 -0700

    stabilzer: Get the position information before the state estimation.

[33mcommit 1b012a9c45875907ac8e0bf2d903bb95d8bb0eac[m
Merge: d25d891 3053d00
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Fri Sep 16 14:45:17 2016 -0700

    Merge branch 'master.crtp_position_update' of github.com:stephanbro/crazyflie-firmware into master.crtp_position_update

[33mcommit 3053d0057aaaf8ebe173e4e5c01c18d26e5f3a17[m
Author: Casey Carlin <casey.carlin@us.panasonic.com>
Date:   Fri Sep 16 14:20:38 2016 -0700

    commander: Make position variable more generic.

[33mcommit 5824230172266445fe71031e0bdccfa46558f0cf[m
Author: Casey Carlin <casey.carlin@us.panasonic.com>
Date:   Fri Sep 16 14:19:07 2016 -0700

    commander: Log position info and send it to the EKF.

[33mcommit 376a1de0dbadf300411c25a04c6f15341259ea43[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Sep 16 14:47:38 2016 +0200

    Fixed CF1 build because of missing file sonsors_stock.c

[33mcommit d38113b8ac58f9191b0fc956036c5fcad4c15045[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Sep 16 14:44:26 2016 +0200

    Sensors task moved to HAL and made as common interface to get sensor
    data.

[33mcommit b9b1571d3163c4e130dc97a237e9e3183c5027d7[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Sep 16 11:21:35 2016 +0200

    Added gyro bias callibration that does it when platform is stable as in
    imu_cf2.c

[33mcommit b02c237318f35428c3b96804b6c71d04b4e361c2[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Sep 16 08:31:07 2016 +0200

    Finaly fixed MPU9250 slave reading of both Mag and Baro. Enabled Baro
    moving avg filter of size 4 to improve signal.

[33mcommit d25d891db09682e209d125e8a6607e77ec51eb94[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Thu Sep 15 09:53:49 2016 -0700

    Merge branch 'master' into master.crtp_position_update

[33mcommit 1ad1d96597b83c077c4df97222c76cf8617c16cc[m
Merge: 40a5529 25243ed
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Sep 15 09:54:40 2016 +0200

    Merge pull request #145 from stephanbro/master.baro_driver_slave
    
    [WIP] Baro driver slave configuration

[33mcommit ce7d92967476fba7071718b1021ab3b1b055c2b9[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Wed Sep 14 14:58:11 2016 -0700

    commander: Remove velocity items from the packet.

[33mcommit 25243ed73b03133a0cbab444e59b8835b6150ca7[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Wed Sep 14 09:40:01 2016 -0700

    sensors_task: Changes from @tobbeanton to do the self tests before setting the MPU6500 as the I2C master.

[33mcommit 03e5ae5868bd05174c922284b9d60a94d275ff5e[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Wed Sep 14 09:29:00 2016 -0700

    stabilizer: Get position update from commander.

[33mcommit 4e76cd82912702e1a9c69b2e87207eede6e359ec[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Wed Sep 14 09:28:31 2016 -0700

    commander: Register callback for the position port and add helper for state information.

[33mcommit c1526d6975a3a4711b3a03ebb427060d034552c0[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Wed Sep 14 09:27:27 2016 -0700

    crtp: Add position port and rename existing commander port.

[33mcommit 451fb7a487c534471c8ec2fa3aeca235293c46d4[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Tue Sep 13 11:50:57 2016 -0700

    sensors_task: Configure baro as slave 1. Having the mag and baro enabled seems to not work though...

[33mcommit 40a55295e324364ea5196132426f92b99ba485b7[m
Merge: 83c188a 5d809f7
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Sep 12 12:26:30 2016 +0200

    Merge pull request #144 from stephanbro/master.mag_driver_fixes
    
    Master.mag driver fixes

[33mcommit 5d809f7652c0417bba8fb0a4f0cfcd53ca9f2dd9[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Fri Sep 9 10:07:04 2016 -0700

    sensors_task: Configure ak8963 through the mpu6500 master/slave configuration.

[33mcommit a1c55583c1156b52867682ec96c05a1c719b5cbb[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Fri Sep 9 10:01:50 2016 -0700

    estimator_kalman: Read the mag and baro even if not used so their log values are updated.

[33mcommit a5ee0fc92051ad1e3a488e0a12562a4c0c0b1b19[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Fri Sep 9 09:58:59 2016 -0700

    imu_cf2: Check if mag data is ready before updating.

[33mcommit e42a9b9f3bb586660ef052cf0f71bbd8323841bc[m
Author: Stephan Brown <stephan.brown.07@gmail.com>
Date:   Fri Sep 9 09:56:07 2016 -0700

    ak8963: Rename register definition.

[33mcommit 83c188aa9f5192346cbf3287791cbe6b6cab7faa[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Sep 8 13:48:05 2016 +0200

    Made CF2 PID tuning a bit less aggressive and a fallback with old PID
    settings for kalman estimator.

[33mcommit 5f34c6f4f389eaa037eb7d834b33035cfabb4b57[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Sep 8 10:57:39 2016 +0200

    Made @theseankelly PID settings default which improves flight
    performace. Closes #143

[33mcommit adb8ca53277e9094867c5bdd7a9d0ec202857e8e[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Sep 8 10:45:12 2016 +0200

    Increased gyro variance threshold to easier pass calibration. Closes
    #141

[33mcommit c3365c1ce594fd14dffd7491b5e61b2ed4bd9f27[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Sep 7 16:54:26 2016 +0200

    Made I2C transfer function pritty.
    Added assert info to hard fault
    Fixed I2C communication issue with expansion test board.

[33mcommit 976b99cfd9651824d95c70340a64146db3b797c5[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Sep 7 16:36:08 2016 +0200

    Fail build on warnings

[33mcommit ea069e5e84fbac1347a38261eaacdabcd03f2725[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Sep 7 16:20:57 2016 +0200

    Added compile of the kalman filter to the travis build. Cleaned up warnings.

[33mcommit 167f077130c7d7ba44497d012105dbe859d56751[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Sep 7 16:05:10 2016 +0200

    Added "make" tool for the toolbelt. Replaces the "compile" and "clean" tools

[33mcommit f4eb610a8245e3957cc67e2aad7325f577d1edc8[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Fri Sep 2 14:02:43 2016 +0200

    Add TDMA ranging for multi Crazyflie operation
    
    Also add ranging outliers rejection.
    
    To fly two copter the following can be added in the config.mk file.
    For the first Crazyflie:
    CFLAGS+= -DDWM1000_ENABLE_TDMA -DDWM1000_TDMA_SLOTS_BITS=1 -DDWM1000_TDMA_SLOT=0
    And for the second Crazyflie:
    CFLAGS+= -DDWM1000_ENABLE_TDMA -DDWM1000_TDMA_SLOTS_BITS=1 -DDWM1000_TDMA_SLOT=1

[33mcommit 68bc4ed5cc2b43624f515b8bb958e20a573126a6[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Aug 31 14:46:32 2016 +0200

    Removed CPAL lib and fixed compile issue for CF1.

[33mcommit a2020ceb2fcf1c77c553c8849d4b2f533bc44079[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Aug 30 22:06:50 2016 +0200

    Renamed i2c driver prefix to i2cdrv. Commented functions and removed
    unused code. Reorganized functions.

[33mcommit 8ac11153b284e388ed04075e75adb646d31eae84[m
Merge: 3b32591 bf1e398
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Aug 26 23:23:43 2016 +0200

    Merge branch 'rzr_i2c' into merge_i2c

[33mcommit 3b3259164a6750e19b023a6d3362231806690233[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Aug 26 23:19:35 2016 +0200

    CMSIS

[33mcommit bf1e398fb0c0c44e2dfc9abefe7b7c204b23aff8[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Aug 26 22:44:27 2016 +0200

    ifdef:ed som I2Cdrv debug code and some minor cleanup.

[33mcommit 0de6ebdb7182c460fa19a762807e01b588fccb52[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Aug 26 22:25:06 2016 +0200

    Finally got I2C communication working. Issue was setting start condition
    in TxE which needed to be moved to BTF.
    
    Cleaned up debug code in STLib and other files.

[33mcommit 804ac9966723b5174938e21932f2a93760870cf7[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Aug 24 15:57:23 2016 +0200

    Added eeprom write/read test. Fixed I2C bug. Enabled eeprom
    startup-tests again.

[33mcommit 86f2d82e71b5777bbb0de1fae865f26a6dbe737d[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Aug 24 13:27:46 2016 +0200

    Refactoring the i2c driver to be cleaner. Working with one bus. Next is
    two.

[33mcommit 3b31a124231db3a259b20e10e5761b754c37fd97[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Aug 22 14:49:17 2016 +0200

    I2C basic driver with DMA is working for I2C3. Started implementing for
    I2C1 as well.

[33mcommit e44338c40131d08d3ba0c12cfa5a66cd5dcfd36a[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Aug 12 11:47:56 2016 +0200

    I2C working better

[33mcommit 610e85f00b48dd4f65b8429c69bfa79e2578b21d[m
Merge: bbcc449 1cf75fb
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Mon Aug 8 08:35:46 2016 +0200

    Merge pull request #139 from theseankelly/dev_telem
    
    Creating two variables for VBat an ExtVBat in mV

[33mcommit 1cf75fb6a4b19e5568c4dd20d65db71224f54ed4[m
Author: Sean Kelly <theseankelly@outlook.com>
Date:   Tue Jun 21 08:26:59 2016 -0700

    Creating two variables for VBat an ExtVBat in mV

[33mcommit bbcc449bb78de27f5102d3cc26d5eea05f838985[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Aug 3 11:57:37 2016 +0200

    Moved logging of sensors back to stabiliser.c. Closes #138

[33mcommit 3338d6cf6a18e378635eaf9c6b7fdb47ef113969[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Jul 28 19:25:38 2016 +0200

    Fix position set commander for ROS compatiblity

[33mcommit bfd4840d678eeceb287389268f5a49548788f67a[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Jul 25 22:02:28 2016 +0200

    Fixed positionSet commander X orientation

[33mcommit ede4f2a205d855798a2b50324999e3710b3d3423[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Jul 25 18:03:49 2016 +0200

    Inverted setpoint order in hacked x/y/z commander
    
    Related to #113

[33mcommit 02c32854d569fdd8e68edf34b3ba825acfbce9d8[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Jul 25 15:32:28 2016 +0200

    Disable kalman filter from default
    
    Make a config.mk file with the following line to enable the kalman filter:
    SENSORS            ?= task
    ESTIMATOR          ?= kalman

[33mcommit 9472f4537f16d5b299c8866ca3bee842f39e021e[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Jul 25 15:27:21 2016 +0200

    Added TOA input from the loco deck driver to the kalman filter

[33mcommit 03550d5d83011bff237ff67a4b398804e55b2e05[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Jul 25 15:25:41 2016 +0200

    Fixed PID position controller to work with the kalman filter estimate

[33mcommit fc88c6a7b7a1ccea8399df155b6132a0f474147c[m
Author: Mike Hamer <mike@mikehamer.info>
Date:   Fri Jul 8 16:19:04 2016 +0200

    Kalman Filter
    
    The Kalman filter still needs a lot of tuning (process and measurement noises).
    
    In addition, there are many TODOs, see estimator_kalman.c for more details.
    
    Of particular note are the following issues, which should be investigated
    
    1. When sitting on the ground (quadIsFlying == false), the accelerometer gives information about the attitude of the quad, which could be incorperated into the estimate. Currently the attitude is initialized as zero, and the quad needs to be started flat.
    2. Extensive testing is needed, sometimes the estimate or covariance matrix goes haywire
    3. See all the TODOs in estimator_kalman.c!
    
    Signed-off-by: Mike Hamer <mike@mikehamer.info>

[33mcommit faa7096018bc015b19ac6f004b1a28e44f8b5103[m
Author: Mike Hamer <mike@mikehamer.info>
Date:   Tue Jun 28 15:44:50 2016 +0200

    Stop motors on config assert
    
    This stops the Crazyflie flying off uncontrolably. This is useful for debugging, but might not be desired in production firmware.
    
    Signed-off-by: Mike Hamer <mike@mikehamer.info>

[33mcommit 97a54d2f7456ee8107cc262f51447f251d052df7[m
Author: Mike Hamer <mike@mikehamer.info>
Date:   Tue Jun 28 15:41:17 2016 +0200

    Sensors read by interrupt-driven task
    
    This commit introduces an interrupt-driven task to handle IMU reads using DMA.
    
    The task configures the IMU's master mode to handle barometer and magnetometer access.
    
    The task waits on an IMU Data Ready interrupt on EXTI13 before initializing a DMA read (via CPAL) of the IMU's registers.
    
    Since the IMU handles barometer and magnetometer access, all sensors can be read in a single DMA transaction. This eliminates I2C contention problems, since only one transaction occurs on the bus (rather than separately reading from 3 sensors on one bus).
    
    This significantly improves performance of the sensors. sensors_stock.c takes 700us to read the gyro and accelerometer data (most of the time spent waiting), and thus severely limits the rate of the stabilizer task. This was never an issue since the stock stabilizer is computationally light, but becomes important once more advanced onboard estimators or controllers are added to the mix.
    
    IMPORTANT NOTE: As of this commit, the magnetometer only updates once, and its values stay constant in the IMU registers. I don't know why, but I also don't know anyone who uses a magnetometer for indoor flight... so this is a low priority for me to fix. I have disabled the magnetometer for the time being.
    
    Signed-off-by: Mike Hamer <mike@mikehamer.info>

[33mcommit 7207b02722dc86d8201dae75c10a564c33d9f60e[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Jul 25 13:06:08 2016 +0200

    Added quick and dirty position set mode to the commander
    
    This is waiting for a proper implementation of #113. The position setpoint
    is mapped to:
    x: Roll
    y: -1*Pitch
    z: Thrust/1000
    Yaw: Yaw!
    
    The mode is activated by the paramter flightmode.posSetMode. A Z
    setpoint of 0 turns off the motors and since the Z setpoint is mapped on the
    uint16 thrust the maximal altitude is limited to about 65m.

[33mcommit 1bda3f884841f2440c2a78f4eab90fedda56646d[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Sun Jul 24 10:19:01 2016 +0200

    I2C hangs after random number of reads with DMA with a start-stop on
    bus. Trying different things...

[33mcommit d4c7e59bfc55d767046f8fe28dbbb4edb7b906f0[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Jul 13 11:51:36 2016 +0200

    Rewritten I2C driver almost working.

[33mcommit ead100c447e578d91baff5acc11135038b23d92d[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Jul 8 10:01:32 2016 +0200

    Attempt at new i2c driver. Not working yet.

[33mcommit f7e2635cf8a1ffa61131c96336ab9f6a4f70e60c[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Jul 6 13:57:49 2016 +0200

    Added RZR mosfet code to enable power to BL motor drivers.

[33mcommit bb86590a5039dbac8c1beffaa58f73977b015eee[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Jul 5 22:58:31 2016 +0200

    Updated DW1000 lib

[33mcommit 32136623b41622f27798ddb05359c0b93e3d42d4[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Jul 4 14:26:02 2016 +0200

    Fixed rate mode. Closes #133
    
    The rate mode activation in commander was broken with the new
    architecture. This commit implement it back.

[33mcommit 307b17f612dafe83c00440a547cff1a90ebfe123[m
Merge: b8e8f98 9a5efb1
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Jul 4 09:20:38 2016 +0200

    Merge pull request #132 from TU-KL-Crazyflie/patch-1
    
    Thanks for the contribution!
    Update motors_def_cf2.c

[33mcommit 9a5efb18d43c0e91598f7a344442586231d3e7b6[m
Author: TU-KL-Crazyflie <philipp.springer@gmail.com>
Date:   Fri Jul 1 13:40:26 2016 +0200

    Update motors_def_cf2.c
    
    First of all the comment in line 402 claims to use Timer 3 Channel 1 for MOSI on PA7. However PA7 only has acces to Timer 3 Channel 2!
    Either the comment needs to be changed, or an other timer should be used. Since CPPM is unlikely wanted to be used when someone changes the motormapping to PA7, I propose to use timer 14 channel 1 in the motordefinition.
    
    Furthermore the default motor mapping of the Bigquad Deck as described in lines 437 to 440 was wrong and should be replaced with my changes.

[33mcommit e4535999d76813e7246b82a032fe544fa23dc6dd[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Jun 13 12:59:16 2016 +0200

    Initial RZR commit.

[33mcommit b8e8f98c89aa3676d08ff411a9968a73e305da5f[m
Merge: 3885afc c8a372f
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Thu Jun 30 15:17:04 2016 +0200

    Merge pull request #131 from mikehamer/deck_spi_dma
    
    Convert deck_spi to use DMA

[33mcommit c8a372f18fc2c72bad33394e24d09737c62e3db2[m
Author: Mike Hamer <mike@mikehamer.info>
Date:   Wed Jun 29 13:14:27 2016 +0200

    Convert deck_spi to use DMA
    
    Signed-off-by: Mike Hamer <mike@mikehamer.info>

[33mcommit 3885afc03d2dd9e6b37d755b8fcad856aea2565c[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Jun 29 10:59:50 2016 +0200

    Fixed compile flag to be able to use the ARM DSP lib
    
    related to #129

[33mcommit 2f55d075213e1e724e00a0c2b19fb29fb5ea1d81[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Jun 28 20:33:54 2016 +0200

    Added ARM's CMSIS-DSP lib to the CF2 build
    
    The lib is added with an other Makefile that generates a .a file. This is to be
    able to compile the DSP lib with -O2 optimisation flag even when the
    firmware is compiled in debug mode (-O0 optimisation).
    
    make clean is not cleaning the lib. To clean all the lib files run
    make mrproper
    
    Also changed the CMSIS header file to the new version. Since we only use
    these headers form CMSIS it does not seems to cause any problems.
    
    Closes #129

[33mcommit 3c2080d11b8e3daa28451c9237f02cc9ae09fff4[m
Merge: 81c6437 92a4a1a
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Wed Jun 22 16:25:28 2016 +0200

    Merge pull request #124 from mikehamer/update_exti
    
    Enables all EXTI handlers to use callbacks

[33mcommit 92a4a1ab7c9f00ed4ad82fdc528ef49b4f334c5a[m
Author: Mike Hamer <mike@mikehamer.info>
Date:   Mon Jun 20 14:42:39 2016 +0200

    EXTI needs to be initialized on CF1
    
    This fixes an omission of the last commit.
    
    Signed-off-by: Mike Hamer <mike@mikehamer.info>

[33mcommit 81c643740b0c855cb2591124c8eec39b9bd196c5[m
Merge: f993b1c c36dd0d
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Mon Jun 20 22:52:31 2016 +0200

    Merge pull request #123 from mikehamer/bugfix_i2c
    
    Fixed I2C delay bug

[33mcommit f993b1c297beaf9bfed2baae928c0e458d77f985[m
Merge: 6297515 882bc96
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Mon Jun 20 22:44:47 2016 +0200

    Merge pull request #126 from mikehamer/bugfix_syslink
    
    Fixed semaphore logic in uart_syslink.c

[33mcommit 6297515252d953dbf48bf95932a40c0d11fe323e[m
Merge: 21b7c66 cb07ba6
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Mon Jun 20 22:41:16 2016 +0200

    Merge pull request #122 from mikehamer/bugfix_ctrp
    
    Fixed crtpRxTask bug on nopLink

[33mcommit 882bc96bd229376ca914224c7065801f3f0ba185[m
Author: Mike Hamer <mike@mikehamer.info>
Date:   Thu Jun 16 14:41:06 2016 +0200

    Fixed semaphore logic in syslink?
    
    This (should?) fix two issues:
    
    1. Sometimes the queues and semaphores weren't initialized before the first interrupt was triggered, and the interrupt tried to push data to a null queue. This occured once on a warm restart, I'm not sure if it affects cold boots.
    
    2. The semaphore logic seemed incorrect (eg. uartslkSendDataIsrBlocking wouldn't have blocked). I have now made this explicit using two semaphores. It might be overkill, I think there is only one task that calls these functions. But it should solve the problem.
    
    Signed-off-by: Mike Hamer <mike@mikehamer.info>

[33mcommit 7aa7aede4cda13a5bd1639e70ce759219b019344[m
Author: Mike Hamer <mike@mikehamer.info>
Date:   Mon Jun 20 14:42:39 2016 +0200

    Update EXTI for CF1 compatibility
    
    Signed-off-by: Mike Hamer <mike@mikehamer.info>

[33mcommit 21b7c665db6ed9a1cf78ccf77768e4fb9a9fa5f0[m
Merge: 6051b3a f364475
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Fri Jun 17 12:58:21 2016 +0200

    Merge pull request #121 from mikehamer/bugfix_syslink
    
    Fixed syslink unhandled overrun bug

[33mcommit c2c513783bf35ee37b105b033133de23b781d287[m
Author: Mike Hamer <mike@mikehamer.info>
Date:   Wed Jun 15 17:19:07 2016 +0200

    Enables all EXTI handlers to use callbacks
    
    This commit centrally enables all EXTI interrupts on the NVIC. Note that the individual EXTI line interrupts still need to be enabled for interrupts to be generated.
    
    This fixes issues related to EXTI9_5 and EXTI15_10 handlers being initialized and defined multiple times.
    
    This affects, primarily, the IMU interrupt (EXTI13) and interrupts on some of the deck pins (eg. dw1000 on EXTI11). The solution was therefore made global, and existing interrupts updated to use callbacks, rather than the handlers directly.
    
    Signed-off-by: Mike Hamer <mike@mikehamer.info>

[33mcommit c36dd0d443b67110a5227d79782c1d090a4d6fe7[m
Author: Mike Hamer <mike@mikehamer.info>
Date:   Wed Jun 15 17:02:55 2016 +0200

    Renamed "RuffLoopDelay" to "RoughLoopDelay"
    
    Signed-off-by: Mike Hamer <mike@mikehamer.info>

[33mcommit 93203d820616a139c8331ef75d803b50173de1d6[m
Author: Mike Hamer <mike@mikehamer.info>
Date:   Wed Jun 15 17:00:02 2016 +0200

    Fixed I2C delay bug
    
    This delay bug was two-fold:
    
    1. Wrong loop delay
     - The loop delay was (I assume) set for the CF1, and not updated for the CF2. The CF2 runs these loops ~3.5x faster, so the delays were much shorter than expected. I'm not sure if this was a problem, but things seem to be more robust after this change.
     - The new loop speeds were timed using the DWT->CYCCNT to count clock cycles.
    
    2. Overflow caused hangs
     - For some reason, it occasionally occurred that the delay variable would (due to it being a uint32_t and being decremented) underflow, wrapping to the maximum value.
     - The loop was changed to increment the value and terminate on all values greater than the target, rather than only on 0.
    
    Signed-off-by: Mike Hamer <mike@mikehamer.info>

[33mcommit cb07ba6ce97852a7b4362a9d52f3197a98c214ae[m
Author: Mike Hamer <mike@mikehamer.info>
Date:   Wed Jun 15 15:44:23 2016 +0200

    Fixed crtpRxTask bug on nopLink
    
    This commit fixes a bug, whereby the crtpRxTask would loop infinitely (and without delay) if a communication link had not been established (ie, link == nopLink).
    
    Signed-off-by: Mike Hamer <mike@mikehamer.info>

[33mcommit 1bc21fff08192d16018574e68071c4d27d2b657b[m
Author: Mike Hamer <mike@mikehamer.info>
Date:   Wed Jun 15 15:41:13 2016 +0200

    Fixed crtpRxTask TODO
    
    This commit fixes a TODO in the crtpRxTask.
    
    In this task, packets are pushed to the communication port's length-1 queue. If this queue is full, the current functionality is to leave the old packet and discard the new one, however a TODO suggested replacing the old packet with the new one.
    
    Since the queue is length 1, we use the FreeRTOS command xQueueOverwrite to do just this (replace the old packet with the new, or enqueue the new if the queue is empty).
    
    Signed-off-by: Mike Hamer <mike@mikehamer.info>

[33mcommit f364475e44d0c6bb1486c7e0e0fe8e0ff71dfa8a[m
Author: Mike Hamer <mike@mikehamer.info>
Date:   Wed Jun 15 15:30:31 2016 +0200

    Fixed syslink unhandled overrun interrupt
    
    This commit fixes a bug, whereby an overrun of the syslink UART buffer was not handled in the interrupt routine, causing constant retriggering and reentry, stalling the system.
    
    Overruns are caused when high CPU/interrupt load causes the syslink UART data buffer to not be processed fast enough.
    
    This bug was fixed by:
     1. handling unhandled conditions in the ISR, and
     2. reordering/simplifying instructions in the ISR to reduce latency before data read.
    
    As it is currently implemented, every received byte causes the CPU to be interrupted, and the byte to be sent to the syslink for processing (this is due to a variable packet size and hence unknown transaction length).
    
    A nicer implementation would be to fix the packet length at its maximum (32 bytes), and use DMA for the entire RX transaction. This would entirely avert the problem of an overrun causing packet loss. I assert (without evidence) that the time required to interrupt the CPU every byte, is less than the overhead due to fixing the packet size at its maximum length.
    
    Signed-off-by: Mike Hamer <mike@mikehamer.info>

[33mcommit 6051b3a79b4d29e6dc3aa1b25d0a6887c198f60e[m
Merge: e8683d0 a81d716
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Wed Jun 15 08:08:38 2016 +0200

    Merge pull request #120 from whoenig/bugLogSize
    
    correct maximum payload for logging size

[33mcommit a81d716801907bd5e7462b071db24baa16557255[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Tue Jun 14 18:59:28 2016 -0700

    correct maximum payload for logging size

[33mcommit e8683d01173f7673528fd133fdf2b4daeb567b21[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Jun 9 17:50:51 2016 +0200

    Added temp and pressure log parameters again that were lost when the code was reorganized

[33mcommit c2a88215d5dd1853f505f4c89162eaf6839d9f4a[m
Merge: a0628ec 663e7f8
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Wed Jun 1 12:29:08 2016 +0200

    Merge pull request #118 from mikehamer/fix_I2C_bugs
    
    Fixed I2C contention & timeout bugs

[33mcommit 663e7f82f96827249c6a726b456f06af4e2bc482[m
Author: Mike Hamer <mike@mikehamer.info>
Date:   Wed Jun 1 10:31:36 2016 +0200

    Fixed I2C contention & timeout bugs
    
    This pull request fixes two related bugs, which resulted in high CPU load from a high-priority task causing I2C timeouts, which led to tasks spinning endlessly in the (now removed) read/write spin-locks, which finally resulted in an assertFail on reenabling a FreeRTOS timer. This issue was exacerbated by the recent size increase in gyro bias calibration (more calculations from a high priority task), particularly if a radio connection is also established during the calibration routine.
    
    The bugs fixed by this pull request are:
    
    1. Improper semaphore usage.
     * Previously the I2C semaphores were initialised as unlocked (the subsequent xSemaphoreTake in the initialization was forgotten), and as such that they could be taken, before first being given.
     * This caused the (intended-to-be-blocking) xSemaphoreTakes to always pass immediately, which is the reason for the spin-locks (since the code did not wait for the completion interrupts).
     * This commit changes from the deprecated vSemaphoreCreateBinary (which creates the semaphore in an unlocked state, and would require a subsequent xSemaphoreTake) to the more current xSemaphoreCreateBinary (which creates the semaphore in the locked state).
    
    2. I2C Timeouts
     * The calls to CPAL_I2C_Read and CPAL_I2C_Write contain a spin-lock to detect timeout.
     * If a context switch occurs during this function (ie. if the task is interrupted by a higher priority task), then I2C will timeout.
     * This pull request disables context switching for the duration of these calls.
    
    Signed-off-by: Mike Hamer <mike@mikehamer.info>

[33mcommit a0628ec2c171c0cac18bdf5306101c697ebae590[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Sat May 28 15:35:50 2016 +0200

    Added new experimental attitude PID settings to CF2
    
    Added experimental PID settings that results in a faster and tighter
    control of the CF2 attitude. Rate PID found by @theseankelly, see post on
    the forum: https://forum.bitcraze.io/viewtopic.php?f=6&t=1978
    
    To enable the new settings att the folowing to config.mk
    CFLAGS+=-DEXPERIMENTAL_ATTITUDE_PID

[33mcommit 9c0aa2df6418944091d95313ff07b97bd25d27bb[m
Merge: 68a0b9a 44ecf47
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Fri May 27 09:50:32 2016 +0200

    Merge pull request #116 from whoenig/bugfix_cmdspell
    
    fix small spelling issues in commander

[33mcommit 44ecf4703a6e14829eddc72f1a2b6a4a4c396d1b[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Thu May 26 21:51:32 2016 -0700

    fix small spelling issues in commander

[33mcommit 68a0b9a9dee0e9f0c6cc548b39034b7e5d7b9883[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue May 24 23:00:21 2016 +0200

    Improved gyro bias calculation
    
    Improved gyro bias calculation by increasing the number of bias
    mean sample from 128 to 1024 and changing the bias from integer
    to floating point
    
    We might still need some temperature compensation of the bias.
    This change makes the initial bias calculation much better but
    the bias seems to diverge quickly after a minute or two.

[33mcommit 3d32f2ee862947419750cd7c2f7b44c35d9ac4db[m
Merge: a3cfecf ef88c0d
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Mon May 23 09:12:08 2016 +0200

    Merge pull request #114 from whoenig/warmBootSupport
    
    Allow custom arguments for the cload script.

[33mcommit a3cfecf67b46329c20f7e0f1231a99d0ad694b3c[m
Merge: 6a6b368 cadd553
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Mon May 23 09:04:36 2016 +0200

    Merge pull request #115 from theseankelly/param_tilt
    
    Adding a parameter to make tilt compensation configurable.

[33mcommit cadd553a5b55d3efe17a3ae7a4b2e1cc93d62680[m
Author: Sean Kelly <theseankelly@outlook.com>
Date:   Sun May 22 16:04:56 2016 -0700

    Adding a parameter to make tilt compensation configurable.
    This closes #106

[33mcommit ef88c0db0db288e76cda9e48a3f462882ad2494f[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Fri May 20 16:57:13 2016 -0700

    Allow custom arguments for the cload script.
    
    This allows to reflash the Crazyflie without the need to put it manually in bootloader mode.

[33mcommit 6a6b3681f1ac14947cc152c8674593ab6cf142b2[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu May 19 09:37:24 2016 +0200

    Fixed AltHold mode, closes #112

[33mcommit 9485b728ae09a4bc3f3dffef8b5634ce2016f46e[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu May 12 11:17:59 2016 +0200

    Make PM in bigquad driver optional
    
    We cannot use the PM features and the LPS deck at the same time
    so PM is now optional

[33mcommit e57c9414a01212339ddc235b01ae39f33b3ac351[m
Merge: 0812137 4154503
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon May 2 18:29:56 2016 +0200

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware
    
    Conflicts:
    	src/modules/src/estimator_complementary.c
    	src/modules/src/sensors_stock.c

[33mcommit 08121370a8424c62b87e64f96d0a6ea7a7e27fae[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon May 2 18:20:08 2016 +0200

    #110 Added poshol parameter to commander to hold x/y position
    
    This is working similarly to the altitude hold: when poshold is set as true
    the Crazyflie will try to hold its current x/y position
    
    Closes #110

[33mcommit 4d467a365d584f91fd6e8f59db1430b7cad12ebd[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon May 2 18:18:40 2016 +0200

    #110 Fixed 3D position controller

[33mcommit db55d3bacae1d627e5357b01bac85d20b28c2c76[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon May 2 18:18:08 2016 +0200

    #110 Added params to externally set the Crazyflie position
    
    This is experimental and intended to test integrated controller

[33mcommit 4154503a0a63ccc036cb9df013d124908a02de9d[m
Merge: 234b5cc b8a98e5
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Mon May 2 09:25:38 2016 +0200

    Merge pull request #111 from fredg02/patch-1
    
    Add biq quad deck CFLAGS example

[33mcommit b8a98e538da6750f0ee446bca65f42dbaa7b1de8[m
Author: Fred G <fredg02@hotmail.com>
Date:   Mon May 2 00:04:01 2016 +0200

    Add biq quad deck CFLAGS example

[33mcommit 234b5cc1747052fb55207476ee46a9b17d3c2ce2[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Apr 28 15:02:09 2016 +0200

    #102 Refactoring, cleanup

[33mcommit e0764136480ae3606f8a7fe2e10b84c55fef6657[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Apr 27 16:32:19 2016 +0200

    #102: Sensors: acquire pressure sensor only 100 times per seconds

[33mcommit d54d9292a191c545eacd99a7a287fdd5abcfbfa9[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Apr 27 16:25:19 2016 +0200

    #102 Use a tick in the stabiliser to reduce the rate for sub tasks instead of the system tick

[33mcommit e3ac9f33982b7846722451ac2f640316213c2b0b[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Apr 26 19:46:54 2016 +0200

     #102 Fixed CF1 build by reducing heap size

[33mcommit 5523902de0eb361c912a66832d443dcd38eb654b[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Apr 26 19:36:59 2016 +0200

     #102 Cleaned-up stabilizer file

[33mcommit ad18804f14033c1c37e3ff15990b8d7a9e56afb8[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Apr 26 16:15:18 2016 +0200

     #102 Re-enabled X/+ mode and carefree mode

[33mcommit 8ba8d09a05936392d54abcbc78cd05b6812c2ea3[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Apr 26 13:35:24 2016 +0200

     #102 Moved situation awareness out of stabilizer

[33mcommit 2b230ee9dfe171fee565fe27018bb6483c68b471[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Apr 21 19:57:37 2016 +0200

     #110 Implement PID position controller
    
    The new controller is still handling altitude hold. The X and Y parts
    are not tested yet

[33mcommit 6477a3132cbe6a08d0d0eab96e11a0b2089ec6a4[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Apr 19 16:21:34 2016 +0200

     #102 Refactored high level stablizer

[33mcommit da05beba21ba6561510bff6cd33409bd0fff66a5[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Apr 18 13:58:41 2016 +0200

    Fixed CPPM channel decoding. Closes #109.

[33mcommit b4ad8cb48bdf250e6df01a89409c412014d0d3da[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Thu Apr 14 09:44:06 2016 +0200

    Adjusted watchdog timeout to handle larger span for LSI clock (Closes #105)

[33mcommit 15c84f32c1b6b8a85ad2474a37705911b07c297c[m
Merge: 353bc2b b72b4e0
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Thu Mar 31 08:28:03 2016 +0200

    Merge pull request #108 from whoenig/gdb-support
    
    Add gdb target for make

[33mcommit b72b4e08d81707dd7d3ebf93465f7beae9700321[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Wed Mar 30 12:24:37 2016 -0700

    Add gdb target for make

[33mcommit 353bc2b22b735496407fa95429495e03f50cbec4[m
Merge: b63c552 93cfdc1
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Tue Mar 29 11:37:11 2016 +0200

    Merge pull request #107 from jpreiss/master
    
    revive microsecond timer

[33mcommit 93cfdc13173af4f0da9af41da7cd1f9d5d99e0a2[m
Author: James Preiss <japreiss@usc.edu>
Date:   Wed Mar 23 20:04:45 2016 -0700

    revive microsecond timer

[33mcommit b63c552355522389aa8e665bd2c83d1668cf4ca7[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sat Mar 19 16:21:06 2016 +0100

    #80 Fixed compilation warnings for CF2

[33mcommit 2908434580de97743c16c73367f0ba5ad45b18f3[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sat Mar 19 08:58:47 2016 +0100

    #80 Fixed all compilation warnings for CF1

[33mcommit 2515e59bc876be0ae160c90f7f9c23a735b66962[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sat Mar 19 08:17:42 2016 +0100

    Set altitude hold to off in the commander on "drop to ground". Closes #99

[33mcommit b85fc00f94aed7f83e4c34dafcadbccf57d96847[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sat Mar 19 08:15:05 2016 +0100

    #102 Moved altitude hold functionality from commander to altitude hold module

[33mcommit 3d50bc95cda760ff4c95d29b68790c653dd0b63c[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Mar 18 16:47:30 2016 +0100

    #102 Removed comment

[33mcommit 4674de0afaaab5f04180c5324e6fddabc0827db3[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Mar 18 15:04:29 2016 +0100

    #102 Refactoring: moved alt hold into separate file

[33mcommit 2ef311db38c110d8aab58434c5fee8bd25e670bb[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Mar 17 17:04:46 2016 +0100

    #102 Moved velocity estimate into position estimator

[33mcommit 8668a3bad34d62bae3f275e1719deb60099fe433[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Mar 17 16:31:19 2016 +0100

    #102 Refactoring
    
    Extracted code into position estimator, position controller and attitude controller

[33mcommit d8c654b383e4c1cbd1c766926553c9b97a874dd4[m
Merge: 89d9e06 a823cdc
Author: Marcus Eliasson <marcus@bitcraze.io>
Date:   Thu Mar 17 10:11:28 2016 +0100

    Merge pull request #103 from whoenig/jlink
    
    Makefile: add OPENOCD_CMD variable for improved support of other open…

[33mcommit 89d9e06b3aee92c54c6f2d727b6bf55215eb65fc[m
Merge: 66aff47 af72b4c
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Thu Mar 17 09:59:10 2016 +0100

    Merge pull request #104 from cstanke/ecs3_cf2_sound
    
    Added a snippet from Richard Wagner 'Ride of the Valkyries'

[33mcommit af72b4c1ceb85bfd03a02e7affb9bbd962b8b3b0[m
Author: cstanke <github001@cstanke.com>
Date:   Wed Mar 16 20:44:28 2016 -0400

    Added a snippet from Richard Wagner 'Ride of the Valkyries'

[33mcommit a823cdc0e2c9896b2a2c2b82a24b3ea598059056[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Wed Mar 16 16:55:01 2016 -0700

    Makefile: add OPENOCD_CMD variable for improved support of other openocd interfaces (such as J-Link).

[33mcommit 66aff47e83fbb7705b669bf9b4eb239d78469f1d[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Mar 16 16:17:53 2016 +0100

    #97 Added unit test framework and a few tests

[33mcommit d177bdef9b3ea350836939b949495494d739bd15[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Mar 16 13:57:21 2016 +0100

    Started adding types for stabilizer #102

[33mcommit 547888e42efd6178709d6733d71609e5c9f0e08f[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sat Mar 12 09:36:12 2016 +0100

    Added thrust compensation when tilted. Closes #100

[33mcommit 4175d7a0683a7f5f30282788eae8a07b7c50ef5a[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sat Mar 12 09:19:54 2016 +0100

    #98 Reworked estimation of Z position and regulation for altitude hold

[33mcommit a681ff6437c6c540f80606f783339f78b9b9a5d7[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sat Mar 12 08:59:43 2016 +0100

    #98 Added calibration of normal acceleration in Z to reduce error when integrating velocity

[33mcommit 60dfbfcffa5cafe1eb78102c634117af3ea5f028[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Mar 10 16:46:07 2016 +0100

    #98 Refactoring (mainly), moved altitude hold to separate file.
    
    Also made adjustment to how vSpeed is calculated

[33mcommit 3fb2649977dfc524706f7cc1829e4ff2dfd403a5[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Mar 10 13:59:38 2016 +0100

    #98 Refactoring. Moved functions to num.c

[33mcommit 315838721040b4779a9918e94e29198790c87262[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Mar 10 13:31:33 2016 +0100

    #98 Refactoring. Renamed fp16 to num, will add more numerically related functions here.

[33mcommit b601013b2c8bc8582eaeb718545d1900cf8c86f4[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Mar 10 11:26:01 2016 +0100

    #92 Always extract information from git as opposed to the build system. The params sent to the client contains the git hash regardless of if it is a release or local build.

[33mcommit bfab2077d0975aa54db8f880493440c47af74264[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Mar 9 21:05:52 2016 +0100

    #96 Moved source files into src

[33mcommit cdb5f18c5664c4fec53ea65c13c79bf8c8123e59[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Mar 9 20:14:06 2016 +0100

    Added information on git submodules to the readme

[33mcommit 7aa0ca0907c24b9183a8c3d0eff73661ddd37208[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Mon Mar 7 15:58:29 2016 +0100

    Added loggable variables for desired roll/pitch/yaw from ground.

[33mcommit 6f4c9c6bd64e0656d135d11349823b320b3bd848[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Mon Mar 7 15:47:01 2016 +0100

    Modified UART2 interface to support setting baudrate at init

[33mcommit dbaaa914a54bf31a6bf155b26b09c472dc684086[m
Merge: 348f9b4 8220de0
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Feb 24 15:36:55 2016 +0100

    Merge branch 'bigquad'

[33mcommit 8220de016ba7ca869e51a4a0c6002ddbf4a5c72d[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Feb 24 14:54:43 2016 +0100

    Added compile flag for enabling BigQuad deck firmware

[33mcommit 15d3f5a86eab01daf0713619e0cab1ac9ce71b73[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Feb 23 22:30:50 2016 +0100

    Updated VID for bigquad and gtgps decks.

[33mcommit 348f9b4eefcc0b6c2949af4a7daa3b06d83e7f0a[m
Merge: 7aca342 4f4cc30
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Fri Feb 19 09:25:25 2016 +0100

    Merge pull request #93 from whoenig/bugfix2
    
    set correct vid/pid for DWM1000 deck

[33mcommit 4f4cc30a136a6da00db3023cb807b3e8e2a310ef[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Thu Feb 18 12:57:56 2016 -0800

    set correct vid/pid for DWM1000 deck

[33mcommit 7aca3423e2aa148ee3c22cef4482c18854ab0d45[m
Merge: 71d6ea9 6d58bf6
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Fri Feb 12 14:59:00 2016 +0100

    Merge pull request #91 from ograff/PR80
    
    Fix Eskylink compilation option

[33mcommit 6d58bf68b7b1bbdb8d4676495b07ba5f631a1680[m
Author: Oliver Graff <oliver.e.graff@gmail.com>
Date:   Fri Feb 12 05:49:35 2016 -0500

    Fix Eskylink compilation option
    
    Added Eskylink.o to list of files to be compiled, included errno.h in
    eskylink.c

[33mcommit 71d6ea9ecd7f7f92d1ea522fd197ac0e32f6780c[m
Merge: e482cd8 da8c450
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Feb 11 19:08:32 2016 +0100

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit e482cd8dfa21f97d518f29edbf0d7bc9e3fac41b[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Feb 11 19:08:02 2016 +0100

    dwm1000: Edited anchor list

[33mcommit da8c450704883831688eebd30ae2c545f1870031[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Feb 10 14:20:55 2016 +0100

    #2 Updated make file for new .o files

[33mcommit fac277574024bd3a2c7944215e8729d7392767d4[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Feb 10 13:08:05 2016 +0100

    Bump libdw1000 to latest version. Closes #90

[33mcommit 3294255b3d7310b07e5d5e24564cfdd190fc06d9[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Feb 8 19:16:32 2016 +0100

    Fix build for CF1 and fix make target to display gcc defines

[33mcommit 3bab8190f2a8b19c660e4f3ed1dc512f132b51e6[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Feb 8 18:53:52 2016 +0100

    Console: Limit the problem when printing from interrupt
    
    This commits adds a consolePutcharFromISR frunction that only prints in
    the local buffer. This limits the amount of data that can be printed from an
    interrupt but it also prevents the firmware to crash as described in #89

[33mcommit 7f42bbb147639d16c0957e86242141dd1a636bb4[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Feb 8 18:13:23 2016 +0100

    Add script to check if the submodules have been correctly initialized

[33mcommit fd22217833d588f2d74428435c538d888682c3f0[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Feb 8 18:08:18 2016 +0100

    Add compiled header to .gitignore

[33mcommit e474ec470d5c4565f3f9cad1aafbb176720d372d[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Feb 8 18:07:08 2016 +0100

    Removed copied libdw and add it as git submodule

[33mcommit 2af32359d79d19c56f42723c90ff2c81725599af[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Feb 8 17:25:08 2016 +0100

    Add DWM1000 LPS deck driver

[33mcommit a29c105fc9ccc72860572ce5f303657778f4d0af[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Feb 8 17:24:22 2016 +0100

    Add libdw open-source DW1000 driver

[33mcommit cc419f5d29c55d01251395d662c30dba5ad0f2db[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Feb 8 17:12:38 2016 +0100

    Add beginning of deck SPI API
    
    Follows the Arduino API. Will need the beginTransaction and
    endTransaction functions in order to support more than one deck.

[33mcommit 1bf24007bfa4673b3d688e7fe1ef9b5ca646e709[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Feb 4 20:47:15 2016 +0100

    Updated startup and calibration sounds

[33mcommit 72def0c9aa8af1ca2357d771ea5beda70aed7f7b[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Feb 4 20:34:28 2016 +0100

    Corrected bugs in sound module
    
    BPM now actually means Beats Per Minute
    Playing full length of last note in sequences

[33mcommit f8bd7e949e86f05f6dd7b477beb6c37c4d710868[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Feb 4 17:25:04 2016 +0100

    Refactoring of the sound implementation

[33mcommit b062e0c8bb29865aa8a2e04e91c231b4017e8333[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Feb 4 17:12:33 2016 +0100

    Updated calibrated sound to be different from startup

[33mcommit 7c8c6b04a0108e345cae870454b85d7ca95d1303[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Feb 4 16:44:33 2016 +0100

    Removed unused file

[33mcommit 17516664c6037d8310cc64eff99a1599e2fcf7c9[m
Merge: 2cad61d e9b0426
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Thu Feb 4 09:03:03 2016 +0100

    Merge pull request #86 from lgenzelis/patch-1
    
    Added dependences for Ubuntu

[33mcommit e9b0426fa124b960d6ec2cdd82f9f74eddbc63b3[m
Author: lgenzelis <lucas.genzelis@gmail.com>
Date:   Wed Feb 3 15:45:27 2016 -0300

    Added dependences for Ubuntu

[33mcommit 2cad61d5f1a4f836db2398e441e542a905dd0fe5[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Feb 3 10:36:30 2016 +0100

    Closes #85 Manual merge of pull request
    
    Make the LED-ring deck white spin effect really white, not green
    Added missing newlines to debug logs

[33mcommit c235f42bad8b1495bc1721fe0b9b401d752067d4[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Mon Feb 1 16:25:33 2016 +0100

    Added license file

[33mcommit da32709852290a762a356e61aa86134d3b525000[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Jan 19 15:48:43 2016 +0100

    Allow deck with corrupted (blank) memory in DEBUG build.

[33mcommit a691387f311fef83a629d7f1bcfb1b02191888ff[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Jan 11 17:41:03 2016 +0100

    Crazyflie2: Fix frequent start failure when deck is install
    
    Increase priority for communication between the CPUs and increased size
    of the receive queue on the STM.

[33mcommit a83a2fc250cb7b49e72f69a7ee3c39807ab7cf66[m
Merge: 429af07 b4b7a36
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Sun Dec 20 19:55:36 2015 +0100

    Merge branch 'master' into bigquad

[33mcommit b4b7a369d1f45fa617644b1f3875d931eba65241[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Sun Dec 20 19:54:31 2015 +0100

    Option for disabling auto initialization of found decks

[33mcommit 429af0711acb274b779ed2d6c5367471599a3106[m
Merge: 7c9c537 953df3b
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Fri Dec 18 17:00:54 2015 +0100

    Merge branch 'master' into bigquad

[33mcommit 953df3b32c1ebec6fc306128759741ae3fa85fd1[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Fri Dec 18 17:00:01 2015 +0100

    Removed quotes from debug printout for testrig

[33mcommit 7c9c537efbf1ecc5f4e1d72d89892910066d94e3[m
Merge: b8a857e 3a9470b
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Dec 17 15:40:45 2015 +0100

    Merge branch 'bigquad' of
    https://github.com/bitcraze/crazyflie-firmware.git into bigquad

[33mcommit b8a857e855450de98404a4bc4d6bdc05c56d3de1[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Dec 17 15:34:34 2015 +0100

    Rebase which fixes CF1 DEBUG=1 build.
    Fixed missing INPUT_PULLDOWN after rebase.

[33mcommit 8621f28d3b938e59af5514f07b4f6383bec354c8[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Dec 15 18:28:37 2015 +0100

    Added bigquad test param.
    Removed CPPM and BQ VID:PID defines.

[33mcommit f101ea0b1cf3b6c765f18a67acaaf1ebe682fa41[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Dec 10 21:36:06 2015 +0100

    Improved testing of bigquad deck.

[33mcommit f67cf4d9e1e4be2dd78a8531e375681be363b7dc[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Dec 9 15:23:53 2015 +0100

    Initial implementation of bigquad tests.
    
    A bigquadtest.c added to test the deck.
    Addded deck_test.c which contains test utilities.
    Added missing cppmdeck.c.

[33mcommit 549901a04471e6b548667d256ae7c2aaf4450202[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Dec 4 19:41:42 2015 +0100

    Fixes after rebase from master.

[33mcommit 6970db4e16ec3c5de17799d35ac324000b96ae30[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Dec 2 19:00:49 2015 +0100

    Fixed BQ current reading pin and multiplier.

[33mcommit bd1936489086a02e8fff46bc35c15844be889ff6[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Nov 24 14:02:33 2015 +0100

    Added battery current log variable.

[33mcommit 7c429c7ca1a2faa45faf2a786ef67a22bebd4aaf[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Nov 24 13:59:53 2015 +0100

    Added current measurement to PM and bigquad.

[33mcommit 9972152bb84c3c563b82b94d095156d2cb9e649d[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Nov 24 13:32:17 2015 +0100

    Added external battery measurement to PM. Changed ADC to 12bit by
    default.

[33mcommit 91744de74ead1f14bf7badcf0e5c67530fda5947[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Nov 17 19:37:54 2015 +0100

    Fixed build for CF1. Moved extrx init to bigquad deck.

[33mcommit 10226a6520b57886331e9c6cb6cf65f242d1d7f7[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Sat Nov 14 16:13:50 2015 +0100

    Renamed sppm to the more common cppm (combined ppm).

[33mcommit bfde13d897b3bd8e369e794d9caf670857ec66e5[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Sat Nov 14 15:40:04 2015 +0100

    Refactored commander cach and removed commader watchdog.

[33mcommit 59f28fdfce550500cfa9b38ae29c802d0d9d82e2[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Sat Nov 14 11:24:41 2015 +0100

    ExtRx static channel mapping added. Commander input mux added for extrx
    and crtp.

[33mcommit 93fbe1e808b17ba838a8e890e39eed11318fa78b[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Oct 28 14:03:47 2015 +0100

    Splitted sppm into a sppm driver and extrx module.
    
    System is not starting and this commit is done to pull in fixes from
    master branch.

[33mcommit ed19658dd06f491f5f7090e8ae20776afde4137e[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Oct 13 14:41:30 2015 +0200

    Initial implemented of simple sppm driver. Can read sppm on PA7/TIM14
    but needs more work.

[33mcommit e0d5b1816b70a15e4301596ee02e6444a6b5112b[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Thu Dec 17 14:26:50 2015 +0100

    Fixed Crazyflie 1.0 build

[33mcommit 37ed673d2e576415eb5d88099bb0101616890c81[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Thu Dec 17 14:21:14 2015 +0100

    Starting USB before CRTP. Closes #84.

[33mcommit 3a9470b3f91bafe5fb676ed359ab3773bb632df3[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Dec 15 18:28:37 2015 +0100

    Added bigquad test param.
    Removed CPPM and BQ VID:PID defines.

[33mcommit 8e1356783148af994408e4c0c80e975f1bdb467c[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Dec 10 21:36:06 2015 +0100

    Improved testing of bigquad deck.

[33mcommit 9ceb597ebe1ed0740ed483950a73f8651fbcbb78[m
Merge: c29c75b 9665026
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Thu Dec 10 11:11:28 2015 +0100

    Merge pull request #83 from ograff/log_motor_ratio
    
    Log motor PWM ratios after voltage compensation

[33mcommit c29c75b466049bea3fd7a144f2ded4a778ea6bdd[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Dec 10 11:09:16 2015 +0100

    Move ledseq to flash
    
    Saves about 272Bytes of RAM for CF1

[33mcommit 700e230bceaa46c3d7c9bd86e301862c40857871[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Thu Dec 10 10:44:12 2015 +0100

    Fixed VID/PID for decks and added buzzer factory test

[33mcommit f9f1919da62e3628a85628c1aa22a2184c46a3a2[m
Merge: 61f3d87 5c42358
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Thu Dec 10 08:46:58 2015 +0100

    Merge pull request #82 from ograff/rename_deck_contants
    
    Update name from deck_contants.h to deck_constants.h

[33mcommit 96650266f88d82d577bd5b366e2e6bf10edf0f12[m
Author: Oliver Graff <oliver.e.graff@gmail.com>
Date:   Wed Dec 9 21:28:42 2015 -0800

    Log motor PWM ratios after voltage compensation
    
    Update motors.c to log PWM ratios after voltage compensation. Fix #77

[33mcommit 5c423585426f384a15b83bfce3c68d3af758431a[m
Author: Oliver Graff <oliver.e.graff@gmail.com>
Date:   Wed Dec 9 20:08:33 2015 -0800

    Update name from deck_contants.h to deck_constants.h
    
    Change name for deck_contants.h, update file that includes it
    
    Fix #76

[33mcommit 3c4bdee3e011d37be9e4a9719d624e184abb41f9[m
Merge: 7513edb 73a3ece
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Dec 9 15:24:19 2015 +0100

    Merge branch 'bigquad' of https://github.com/bitcraze/crazyflie-firmware.git into bigquad

[33mcommit 7513edbb6d8ee2b52bb452aae90caeeb28e8da0e[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Dec 9 15:23:53 2015 +0100

    Initial implementation of bigquad tests.
    
    A bigquadtest.c added to test the deck.
    Addded deck_test.c which contains test utilities.
    Added missing cppmdeck.c.

[33mcommit 61f3d878233d19e667eae0ac69499ef6200a0fee[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Dec 9 08:51:14 2015 +0100

    Fixed versionTemplate.py for shallow git clone
    
    When built from Travis the repos is cloned shallow (it pulls the 50
    last commits). If the latest tag falls bellow the 50 last commit
    the git describe was failing.

[33mcommit 73a3ece9f964c17cdcf0a1aa0645bfbad31db180[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Dec 9 08:46:59 2015 +0100

    Fixed versionTemplate.py for shallow git clone
    
    When built from Travis the repos is cloned shallow (it pulls the 50
    last commits). If the latest tag falls bellow the 50 last commit
    the git describe was failing.

[33mcommit d34055a1cf21d5513a76e779ecbc65911b8f5714[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Dec 4 19:41:42 2015 +0100

    Fixes after rebase from master.

[33mcommit 190e477580a20b31e7b9605e7695c5666561d861[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Dec 2 19:00:49 2015 +0100

    Fixed BQ current reading pin and multiplier.

[33mcommit 89fa644ac483b14556108c309eb81c77f0867a58[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Nov 24 14:02:33 2015 +0100

    Added battery current log variable.

[33mcommit 99d77518d86ee039768f222b419280d56aa5ef42[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Nov 24 13:59:53 2015 +0100

    Added current measurement to PM and bigquad.

[33mcommit 44710cb39b21ef8077ca01bcbc875e2bba3eb218[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Nov 24 13:32:17 2015 +0100

    Added external battery measurement to PM. Changed ADC to 12bit by
    default.

[33mcommit cfc0881ce82ac8fe744ad56d8ab221c25714118c[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Nov 17 19:37:54 2015 +0100

    Fixed build for CF1. Moved extrx init to bigquad deck.

[33mcommit 79f7f9cd8326821944109cf895ffa22d12440af6[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Sat Nov 14 16:13:50 2015 +0100

    Renamed sppm to the more common cppm (combined ppm).

[33mcommit 283521da3ed6fad4a02709f878ecabce3de662b8[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Sat Nov 14 15:40:04 2015 +0100

    Refactored commander cach and removed commader watchdog.

[33mcommit 3704ef37b23a0ccb33116c9c0209074b5ab34a43[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Sat Nov 14 11:24:41 2015 +0100

    ExtRx static channel mapping added. Commander input mux added for extrx
    and crtp.

[33mcommit 9a79672ab1cc77f953c8d7d5aa2ec64e6013c30b[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Oct 28 14:03:47 2015 +0100

    Splitted sppm into a sppm driver and extrx module.
    
    System is not starting and this commit is done to pull in fixes from
    master branch.

[33mcommit a361292f435d61aadce7f80c87a525ff54d443fc[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Oct 13 14:41:30 2015 +0200

    Initial implemented of simple sppm driver. Can read sppm on PA7/TIM14
    but needs more work.

[33mcommit f8f50ce8d86481ccd67e302bc84934b5ae7ed6ee[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Dec 2 14:03:08 2015 +0100

    Parsing NMEA messages GPGSA and GPGGA

[33mcommit 4823fac0edf6721f278d8c638bdc5a588c7d4db5[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Mon Nov 30 17:14:05 2015 +0100

    Update for GL Titan-2 outputting NMEA on console

[33mcommit f66d93ec1135388adb0e69c6856bf77622deb8fd[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Thu Nov 26 17:34:30 2015 +0100

    Moved deck objectfile to correct place

[33mcommit 6630b3aabcc1b88617cd7a69a0a698a8426cc427[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Nov 26 09:16:19 2015 +0100

    Fix queue monitoring and trace for FreeRTOS 8

[33mcommit 2ead4bf59b77ce36e6d07580af81f4c4f3a6bbb5[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Nov 25 17:33:54 2015 +0100

    Fix warning when creating task.
    
    Related to FreeRTOS 8

[33mcommit 93619a201b95700d2de2922df8b15703875c8753[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Nov 25 17:26:14 2015 +0100

    Fix interrupt priority, fixes USB
    
    Interrupt priority are now documented in nvicconf.h
    
    Most are standardised in LOW, MID and HIGH priority.

[33mcommit 3820974eb85f672a9ab7bb244fc1a3062a4d60e6[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Nov 25 14:47:04 2015 +0100

    Updated FreeRTOS to v8.2.3
    
    This update revealed miss-configuration of the NVIC interrupt group
    by the USB driver. It is fixed to the point that the system starts
    though the USB is now broken.

[33mcommit 9acebbf5bbc650d7dfa09570298f8d7def25fbd6[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Nov 25 17:26:44 2015 +0100

    Cleaned up sound interface and inserted system sounds

[33mcommit c4f1ea504ebb37d4cea4d17c9fa6337a86f72068[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Nov 25 13:38:25 2015 +0100

    Removed warning from missing include

[33mcommit 5540737545ecb93dde02d7e286daac6d46025b2e[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Nov 25 13:34:09 2015 +0100

    Fixed CF1 broken build

[33mcommit ddc7ba060bbc1fc7461242ae0ff3ad1e2b543f1a[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Nov 25 13:04:57 2015 +0100

    Refactored buzzer/sound

[33mcommit c079b508e446dc3c134f458dbbe5f2716bfae33b[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Nov 17 10:38:53 2015 +0100

    Increased back the Syslink task priority
    
    This has caused random crash before, see #69.
    Now that we have added watchdog and debug code it is
    time to try to trigger the bug again.

[33mcommit 848a76e43113673d36974f8b4f51dfbf487c1cb2[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Nov 12 17:49:14 2015 +0100

    Enable FreeRTOS debug support to OpenOCD
    
    Related to #69
    
    This show threads when debugging with gdb. To test:
    
    $ make openocd
    
    In a new terminal:
    
    $ arm-none-eabi-gdb cf2.elf
    (gdb) target remote localhost:3333
    Remote debugging using localhost:3333
    0x00000000 in ?? ()
    (gdb) c
    Continuing.
    WARNING! The target is already running. All changes GDB did to registers will be discarded! Waiting for target to halt.
    ^C
    Program received signal SIGINT, Interrupt.
    [Switching to Thread 536875088]
    0x080072de in vPortEnterCritical () at lib/FreeRTOS/portable/GCC/ARM_CM4F/port.c:290
    290	{
    (gdb) info threads
    [New Thread 536884680]
    [New Thread 536876168]
    [New Thread 536881784]
    [New Thread 536879304]
    [New Thread 536880024]
    [New Thread 536887600]
      Id   Target Id         Frame
      7    Thread 536887600 (STABILIZE) 0x00000000 in ?? ()
      6    Thread 536880024 (CRTP-RX) 0x080065f8 in xQueueGenericReceive (xQueue=0x20002628 <ucHeap+6936>, pvBuffer=0x64, xTicksToWait=0, xJustPeeking=536880608)
        at lib/FreeRTOS/queue.c:1146
      5    Thread 536879304 (CRTP-TX) 0x0800634c in xQueueGenericSend (xQueue=0x20006bc8 <slp>, pvItemToQueue=0x64, xTicksToWait=0, xCopyPosition=536879896)
        at lib/FreeRTOS/queue.c:683
      4    Thread 536881784 (PWRMGNT) 0x00000000 in ?? ()
      3    Thread 536876168 (Tmr Svc) 0x08006bec in prvProcessTimerOrBlockTask (xNextExpireTime=0, xListWasEmpty=536876816) at lib/FreeRTOS/timers.c:412
      2    Thread 536884680 (SYSLINK) 0x00000000 in ?? ()
    * 1    Thread 536875088 (IDLE :  : Running) 0x080072de in vPortEnterCritical () at lib/FreeRTOS/portable/GCC/ARM_CM4F/port.c:290

[33mcommit 08a8a6b61d6155409084b6febe617551600c83a9[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Nov 10 15:33:29 2015 +0100

    Added real time queue trace with ITM SWO
    
    Also added a mode in which the ITM trace does not overflow at the
    cost of slowing down the program.
    
    Related to #69

[33mcommit d514fc8b959f408050b5772c2b4484caa3935cf0[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sun Nov 1 14:57:10 2015 +0100

    #69 Removed unused queue

[33mcommit f31fdf2200654bf5b3d1c13be0badbce46035fe6[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sat Oct 31 19:20:07 2015 +0100

    #69 Corrected peak value in queue monitor

[33mcommit ea0580e6856ed9a3feed40d4499a7f3788e04d9c[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sat Oct 31 18:17:27 2015 +0100

    #69 Improved queue monitor
    
    Added config to reset counters after display and only display queues over flow queues.

[33mcommit 1d5e0b8be72e92e3cdc8f2c33b467bef33da19b5[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sat Oct 31 16:55:33 2015 +0100

    #69 Use compile options from config.mk
    
    Corrected bug in make file that ignored options in config.mk file.

[33mcommit 16819a296ee060a7a5508ae1a8c29533431d58d2[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sat Oct 31 16:13:53 2015 +0100

    #69 Added queue monitor
    
    Added possibility to monitor queues in runtime. To use the functionality, define DEBUG_QUEUE_MONITOR.
    Queues of interest must be added to the queue monitor with the DEBUG_QUEUE_MONITOR_REGISTER macro.
    
    The following data is recorded and output to the console every 10 seconds:
    * nr of items added to the queue
    * the peak number of items waiting in the queue
    * nr of times that items could not be added to the queue

[33mcommit 76bfe95639df966f651182cacb055edc323a7884[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Oct 29 15:14:46 2015 +0100

    #69 Release semaphore in error callbacks
    
    The semaphore has previously not been released in the error callback. After an error condition the semaphore could be taken and the next call to ic2 read/write would lock the calling task.
    Also added a timeout callback, and release the semaphore there as well.

[33mcommit c4f937f9a510bbd3161f5a751acf956aa747f3b8[m
Merge: ef83b92 db840bd
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Oct 29 14:51:40 2015 +0100

    Merge branch 'master' of github.com:bitcraze/crazyflie-firmware

[33mcommit ef83b9268d3726a096d29d4828a9bdf0931d936f[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Oct 29 14:50:08 2015 +0100

    Revert "Fixed freeze when connecting USB"
    
    This reverts commit 51e565d6388bd503c20e3069540e11e189ca4328.

[33mcommit db840bd81948bdcbd3356b8ceb599a3c0f38fdc3[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Oct 29 10:51:26 2015 +0100

    #69 Refactoring
    
    Moved duplicated code into functions to make it more DRY

[33mcommit 51e565d6388bd503c20e3069540e11e189ca4328[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Oct 29 09:31:23 2015 +0100

    Closes #72: Fixed freeze when connecting USB
    
    When connecting with USB there is a 1 second pause caused by the
    client (see bitcraze/crazyflie-clients/python#213). During this
    pause no packets are transfered and this resulted in an interrup
    storm of the 'tx fifo empty' interrupt. It freezes the Copter and
    became visible when we enabled the watchdog (see #71).
    
    This commit is not a real fix but more a workaround. It makes sure
    there is always at least one packet to transfer to the PC for every
    USB frame. This is done in the SOF interrupt, a NULL CRTP packet is
    sent if nothing else has to be sent. This way the interrupt storm
    is avoided.

[33mcommit da8eaf47a4ef99e2509313253675d4a158bf1d57[m
Merge: 77fb0a2 e2cfd19
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Tue Oct 27 09:02:53 2015 +0100

    Merge pull request #79 from erwincoumans/master
    
    fix to compile using older compiler, fixes Issue #78

[33mcommit 77fb0a2fa47eaf145d5642d0fa99676256a6e3c3[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Oct 27 07:03:16 2015 +0100

    #69 Added builds to travis where "all" compile flags are turned on. This will reduce the risk of corrupting code that is normally not built during refactoring.

[33mcommit e2cfd1935b3dce65ba617759c4bf4e722d76c476[m
Author: Erwin Coumans <erwin.coumans@gmail.com>
Date:   Mon Oct 26 21:57:32 2015 -0700

    fix to compile using older compiler, fixes Issue 78
    https://github.com/bitcraze/crazyflie-firmware/issues/78

[33mcommit 297cd602c9046eed2096796ee0176d95190bf4ea[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sun Oct 25 10:16:42 2015 +0100

    #69 Clean up. removed unused imports

[33mcommit 2ffcd782b06b3c3143e7bcd6efa4dabf88f7360f[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sun Oct 25 08:41:23 2015 +0100

    #69 Added debug print to assert

[33mcommit 226cbbe45d690d0db8763b6731c87b8628e98837[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sun Oct 25 08:35:45 2015 +0100

    #69 Refactoring - clean up of task defines

[33mcommit fb8bdbe0ebfe2b2a074705cc720c2d3389c85af4[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Oct 13 13:44:27 2015 +0200

    Fixed build on Ubuntu arm-none-eabi-gcc

[33mcommit 56d2fc0bcb25d3d0604fb1d636669870b31540fd[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Oct 12 22:49:14 2015 +0200

    Implemented rudimentary SWO FreeRTOS task trace
    
    Works in DEBUG build:
    $ make DEBUG=1
    $ make cload
    $ make trace
    <ctrl-c>
    $ tools/trace/decodeItm.py trace.out
    ITM 1 0x4c535953        # Task: SYSL
    ITM 1 0x454c4449        # Task: IDLE
    ITM 1 0x454c4449        # Task: IDLE
    ITM 1 0x42415453        # Task: STAB
    ITM 1 0x454c4449        # Task: IDLE
    ITM 1 0x454c4449        # Task: IDLE
    ITM 1 0x42415453        # Task: STAB
    ...

[33mcommit 824e18830825f09cb4eb51f94571a0df403220fe[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Sat Oct 10 18:20:08 2015 +0200

    Moved print-version info at the end of the build

[33mcommit d5eb851c07b04153a9b6411a8a04d928cc645330[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sun Oct 4 17:26:56 2015 +0200

    Use build information from the build tools if available. Closes #74

[33mcommit 59a166ba41728dba94f465a9c9e81524c056aba7[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Sat Oct 3 02:27:59 2015 +0200

    Moved scripts into tools directory

[33mcommit ab9324e0579101187664a1ef1a62c7e07505a498[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Oct 2 17:15:50 2015 +0200

    #73 Added missing include

[33mcommit 1c20a241481fb59bb27bebd0c22823f3722ca203[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri Oct 2 16:54:09 2015 +0200

    #73 Added debug print to indicate that no assert data was found. Intention is to remove ambiguities whether information was lost when transfered to the client or if the reset was not triggered by an assert

[33mcommit a1ac8edd0090f8a835e05f33d3a357e3b344ed41[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Oct 1 18:00:06 2015 +0200

    Store assert data in RAM and log to console after the watch dog resets the system.
    Created a new section (.nzds) in the memory map, that is not zeroed by the system at startup. The assert data is stored in this section and read at startup, if the system detects that the we are recovering from a watch dog reset.
    Closes #73

[33mcommit f4d99576c8cf1ac776075be6c29b039ffe147019[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Thu Oct 1 13:34:01 2015 +0200

    Added support for morse when flashing the LED to indicate that the CF if calibrates. Added compile time flag to enable it.
    Also added config.mk.example that can be used as a template to easily create a personal build configuration.
    
    The mores code is manually merged from Pullrequest #54 by ian-ross
    Closes #54

[33mcommit aa189d67f447ff84bb5df8e44672b2709b541f84[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Sep 30 22:45:52 2015 +0200

    Fixed miscalculation of log and param crc
    
    closes #20

[33mcommit ea16ab8b561b29dd1cf71cae9f2025a8ae366dfa[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Sep 30 22:25:40 2015 +0200

    Added parameter to set the asl reference
    
    This parameter is intended to be set according to an external
    altimeter in the same room.

[33mcommit d14c8902a991a0e7c5f95f562137f03848f35f44[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Sep 30 21:56:42 2015 +0200

    Increase syslink queue to reduce corruption probability
    
    Related to bug #69

[33mcommit 55cfe57b0a49cd2d53d5a2a4e4c26c51bd1c9363[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Sep 30 21:42:19 2015 +0200

    Corrected YAW rate control drift
    
    Yaw control is now always using the angle PID control loop and rate
    control is simulated by moving the angle setpoint. The setpoint is
    reset to the current yaw angle when the thrust is 0 (ie. same logic
    as for reseting all PIDs)

[33mcommit 61e23e51d7d340392b147586ceb4673ada3570da[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Sep 28 10:09:07 2015 +0200

    Revert "Fixed syslink priority issue causing corrupt syslink packages."
    
    This reverts commit c3f66f060189a40dbd5dd65efe381045ed099256.
    
    This causes freeze related to i2c. See bug #69.

[33mcommit 68bbd9e864b62869119e6bc8601b48607b4119f1[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Sep 28 10:04:13 2015 +0200

    Disabled watchdog when compiled in Debug mode
    
    Related to #71

[33mcommit 063abc8cd1a21c72c1cffb258a7a9e93a2b6ac26[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Tue Sep 22 15:27:03 2015 +0200

    Added watchdog Closes #71

[33mcommit e0fae53076928730755de6bab6e5a42b5f73e3c4[m
Merge: ee490f2 47716e0
Author: Kristoffer Richardsson <kristoffer@richardsson.org>
Date:   Mon Sep 21 13:04:30 2015 +0200

    Merge pull request #70 from khant14/patch-1
    
    Update README.md

[33mcommit 47716e006bb461ca2c9a090d13492a09317ff0b5[m
Author: Aung Khant <khant14@gmail.com>
Date:   Sat Sep 19 18:24:54 2015 -0500

    Update README.md

[33mcommit ee490f2b95295a9a615384443cea24e0b5ed0d25[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Sep 9 10:44:45 2015 +0200

    Updated build tool configuration to version 1.0, and renamed build script

[33mcommit 6db320a1d3d6fc930d077fd8e09b5274fe06f256[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Sep 2 16:53:07 2015 +0200

    Made double spinner the default LED-ring effect.

[33mcommit 9a73e8a69634950a5b7d731998d7b786dae58d3a[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Sep 2 14:26:14 2015 +0200

    Lowered amount of deck system prints when DEBUG isn't defined.

[33mcommit c3f66f060189a40dbd5dd65efe381045ed099256[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Sep 2 14:25:20 2015 +0200

    Fixed syslink priority issue causing corrupt syslink packages.

[33mcommit 180cb7520564a1530fcfd8ecd4f10709acada374[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Aug 26 11:37:11 2015 +0200

    Added travis build status icon to readme

[33mcommit 5247a38a20468a9e3da6ac257e05280bc9038a3b[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Wed Aug 26 11:33:40 2015 +0200

    Added build support for travis and internal build tools

[33mcommit 18713ac0b4f462ae8dc57656eca0213ae71149fa[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Aug 26 11:10:19 2015 +0200

    Fix CF1 build

[33mcommit 58b66332261c11118cd434fb2a2a1ae414be2182[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Aug 25 17:34:45 2015 +0200

    Deck: Change used pins and periph defines
    
    Used pin defines could have been confused with the digital API
    constants

[33mcommit 0d8058d170b61e5ca8fead934d7d6b82750a53f8[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Aug 24 19:36:41 2015 +0200

    Deck: Added driver-conflict detection

[33mcommit 66cbc7a32f2980f773b260887d4b996b2c458e80[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Aug 24 19:04:15 2015 +0200

    Implemented modular Deck driver subsystem
    
    The deck drivers are now placed in deck/drivers/src and they are
    declare inside the driver file itself, for example:
    
    ```
    static const DeckDriver ledring12_deck = {
      .vid = 0xBC,
      .pid = 0x01,
      .name = "bcLedRing",
    
      .usedPeriph = DECK_TIMER3,
      .usedGpio = DECK_IO_2 | DECK_IO_3,
    
      .init = ledring12Init,
    };
    
    DECK_DRIVER(ledring12_deck);
    ```

[33mcommit 97048739620377a2331ec865a47ee5281f6a8d30[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Aug 24 12:09:12 2015 +0200

    Removed ws2812 driver from CF1. It is conflicting (TIM1) with usec_time
    and rarely used.

[33mcommit 961d0b51f97121270017424db336b71d1fe82387[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Aug 13 21:23:09 2015 +0200

    Buzzer driver added. Virtual ledring mem added. Renamed neopixelring to
    ledring12. Added ws2812 driver for CF1.

[33mcommit 70cb52ffda4233e0baf77e07468ba15cccb3e707[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu May 7 22:39:09 2015 +0200

    Virtual LED ring mem with RGB565 working.

[33mcommit b48788142a3dd9774c9a663deb524a264a605a41[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Thu May 7 22:36:38 2015 +0200

    Fixed param size of buzzer freq

[33mcommit c7d4bb801783cd07c4e6ee530400e4dab778daed[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed May 6 14:40:44 2015 +0200

    Initial imp. if virtual led mem.

[33mcommit d6fe4ef41d908f6c9df201f55508aa6a1e60fb1f[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Mon Mar 16 17:28:14 2015 +0100

    Added initial code for buzzer

[33mcommit db20e5254445474315606a10192d27f33d991fb2[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Aug 12 18:24:09 2015 +0200

    Added parameters to configure rate/angle mode.

[33mcommit 9ff50aed4d5eaa2307e83f3f106087c9dfc21fc7[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Aug 12 17:02:23 2015 +0200

    Made console and crtp init earlier so that DEBUG_PRINT can be used
    earlier (it is buffered though until link is opened). Added console
    output for config block init.

[33mcommit 7cc43495522b55036631c8bc66b0033375f83816[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Aug 12 16:59:12 2015 +0200

    Added Yaw flight modes Carefree, Plus, X. Added possibility to reset
    carefree heading. Thanks to capriele for the base code.

[33mcommit 446c1e7a14c980b9eb9cab47911aa7495157689d[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Aug 12 14:16:46 2015 +0200

    Fixed CF1 configblock flash address.

[33mcommit 74c31f1c4163c93b1ba41bcd99c1f4c4c6ba4942[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Aug 11 16:44:46 2015 +0200

    Added clarification comments to log variables. Closes #50.

[33mcommit e830f594ab814e6df035be4e6f3f571b34b56027[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Aug 11 14:53:51 2015 +0200

    Adjusted motor mapping for Big-quad-deck proto-v2.

[33mcommit 626a688a610ae4bc56773b6b585be3fa17388ba1[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Aug 7 11:05:39 2015 +0200

    Cleaned up the motor definitions by putting them i separate .c files.
    Added brushless config for motor connectors.

[33mcommit 526a8b776eda48522196e2d04cd1145b88aad5b6[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Aug 5 19:24:59 2015 +0200

    Removed BAT compensated thrust for brushless setup. Fixed motorsDeInit
    which reset all pins.

[33mcommit d167028a51f32e6cb42d5f79afa4819571a2d913[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Aug 5 14:28:11 2015 +0200

    Added initial BigQuad support.

[33mcommit d748b7548d46b60229ae9ef04a70ed17ebfce480[m
Merge: 69a5e95 a11a58a
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Aug 11 15:22:20 2015 +0200

    Merge branch 'master' of https://github.com/bitcraze/crazyflie-firmware.git

[33mcommit a11a58a61fe9f8166f7e8af74bdfa056063c871a[m
Merge: 5ce44cc 8035cd9
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Aug 11 15:06:33 2015 +0200

    Merge pull request #68 from fredgrat/sitaw_autotakeoff
    
    Adding automatic take-off function based on the sitaw framework

[33mcommit 8035cd9784c4c66459f14177db1b520b9fcebb89[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Sun Aug 9 23:09:47 2015 +0200

    Adding automatic take-off function based on the sitaw framework

[33mcommit 69a5e95827cafbb70984782c3786e64a612295c9[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Aug 5 10:06:05 2015 +0200

    Removed constant in the battery compensated thrust so that 0 thrust
    outputs 0 PWM.

[33mcommit 5ce44cc2c6314679cb4f3611ba409cc1619bb3bb[m
Merge: 94ddac3 6861c34
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Aug 5 09:24:22 2015 +0200

    Merge pull request #66 from cbiffle/maxsonar-units
    
    maxsonar: fix apparent unit errors.

[33mcommit 94ddac33cc661d7100060bba1a5509b7c4f0a027[m
Merge: e1d0c98 f7be08a
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Aug 5 08:25:41 2015 +0200

    Merge pull request #67 from Hoverbear/patch-1
    
    Add dependencies to README.

[33mcommit f7be08a58c1a499f2fce3d076fb31bbd764e93d6[m
Author: Andrew Hobden <andrew@hoverbear.org>
Date:   Tue Aug 4 16:39:17 2015 -0700

    Add dependencies to README.
    
    Also clean up headers.

[33mcommit 6861c348ccccb1697b4e78c1e70dcf69fb4df289[m
Author: Cliff L. Biffle <code@cliffle.com>
Date:   Tue Aug 4 08:04:41 2015 -0700

    maxsonar: fix apparent unit errors.
    
    The MB1040 accuracy function was taking a measurement in millimeters,
    multiplying it by 25.4, and comparing it with inches.  This appears to
    have been a simple inversion of the desired math, which I've fixed.
    
    I've also switched it to single-precision arithmetic; this escaped my
    notice in my earlier batch of fixes because it's not compiled by
    default.

[33mcommit e1d0c986527ca39a35cc0a65b3f20080f1ebc706[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Aug 4 11:07:28 2015 +0200

    Activated startup sound during motor test.

[33mcommit 801989d2086826bb57aabbbce5d59b339523b76b[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Aug 3 18:21:24 2015 +0200

    Merged CF1 and CF2 motor drivers, motors_f103.c and motors_f405.c, into
    one file motors.c. Also merged motor sound from motors_f103.c.

[33mcommit 75e80044ab63edf4e984fb3b30c2eeb996d918b1[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Aug 3 13:31:04 2015 +0200

    Dynamic motor mapping for CF2 now working. Not building for CF1.

[33mcommit ca117aa8b94cb58e553f1eb7067306c90c0d69f5[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Jul 31 09:37:36 2015 +0200

    Making motor drive more dynamic.

[33mcommit b8e63ae7c205c77a2225b4cc9b416285c5b156f9[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Aug 4 10:58:08 2015 +0200

    Fixed CF1 build.
    Switched to newlib-nano due to data section overrun.
    Added errno.h include to nrf24link.c.

[33mcommit 8dae57645163d9e4328ee6b91a664574162f59ac[m
Merge: bc7d5fa 403767d
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Aug 3 17:29:02 2015 +0200

    Merge pull request #65 from cbiffle/assorted-fpu-fixes
    
    Assorted FPU fixes

[33mcommit bc7d5fa12e9aa6d8ff6176ea68bed978b0fccced[m
Merge: 92666b5 878e375
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Aug 3 17:23:22 2015 +0200

    Merge pull request #64 from cbiffle/radiolink-init-ordering
    
    radiolink: create queue before starting syslink.

[33mcommit 92666b5e745ebc054666daaef54987ac125ffdc1[m
Merge: 2b0d83f 26fc1b6
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Aug 3 17:21:26 2015 +0200

    Merge pull request #62 from cbiffle/logfix
    
    Avoid smashing the stack when generating log packets

[33mcommit 2b0d83fb16ca1204c3eeac9125a9e5ac8285ff4c[m
Merge: b7154ae 1796c66
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Aug 3 17:17:36 2015 +0200

    Merge pull request #60 from fredgrat/deck_analog_fix
    
    Setting sampling time to minimum for 10-bit conversion

[33mcommit 403767d0d0334187878c4080558c5af4e934a8c0[m
Author: Cliff L. Biffle <code@cliffle.com>
Date:   Sat Aug 1 20:23:30 2015 -0700

    Enable fno-math-errno
    
    C standard library math routines are defined as setting errno in certain
    cases.  For applications like this firmware, this is bad, for two
    reasons:
    
    1. It means that certain hardware floating point operations,
       particularly VSQRT, must be wrapped with functions that check flags
       and set errno.  This can easily reduce their performance by 5-10x.
    
    2. It introduces greater reliance on errno, which (particularly in
       FreeRTOS) is difficult to link in a thread-safe manner.  The default
       configuration, and indeed the one used by this firmware, has all
       threads writing to a *shared* errno variable!
    
    However, this firmware isn't *checking* errno, so we don't have to put
    up with all this.  This commit tells the compiler that we're not
    expecting errno side effects from math functions, freeing it to directly
    use hardware instructions like VSQRT.
    
    As a result, we can resolve the TODOs around errno linkage and remove
    the declaration of the shared errno variable.

[33mcommit f13460d821bb066b875e15b1ac0a16820d7b906e[m
Author: Cliff L. Biffle <code@cliffle.com>
Date:   Sat Aug 1 10:49:41 2015 -0700

    Avoid double-precision operations.
    
    The hardware FPU is enabled for the CF2, but it only supports
    single-precision operations.  Double-precision operations have crept
    into the firmware in three ways:
    
    1. Use of unqualified floating-point constants, e.g. "3.5" instead of
       "3.5f".  The most insidious case of this is the definition of M_PI in
       math.h.  I've qualified all constants but one, in M2T, which had a
       net negative impact by confusing the optimizer.
    
    2. Use of the double-precision versions of standard library functions.
       In C, using "sin" over "sinf" implies promoting to double, performing
       the operation, and then converting back.  I've switched all math
       routines to the float variants.
    
    3. Passing floats as arguments to varargs functions, like printf.  This
       is basically unavoidable in C (fixed in C++), so I haven't fixed it.
    
    This commit reduces code size by 8% (GCC 4.8.3), by selecting simpler
    library routines and enabling greater use of hardware floating point.
    It will likely have a proportionally larger impact on performance
    (specifically time spent in idle), but I haven't evaluated it precisely.
    
    There is still work to be done; in particular, the current compilation
    settings are preventing use of the VSQRT instruction.

[33mcommit a5201f6de1b5ac5fd3aa3be77eb137593d3f0736[m
Author: Cliff L. Biffle <code@cliffle.com>
Date:   Sun Aug 2 09:21:06 2015 -0700

    M2T, F2T: parenthesize macro argument in expression.
    
    The current macros will give the wrong results for cases like
    
        M2T(BASE_DELAY + SETTLE)
    
    because of operator precedence errors.
    
    There are currently no such cases in the codebase, but they could easily
    be introduced during maintenance.

[33mcommit 878e3755919dd39f9fcac2be4c02df8691ead4a8[m
Author: Cliff L. Biffle <code@cliffle.com>
Date:   Sun Aug 2 15:11:00 2015 -0700

    radiolink: create queue before starting syslink.
    
    If the STM32 reboots while a connection is active, the nRF will usually
    have data waiting on the UART as soon as syslink is ready to process it.
    Because the priority of the syslink task is higher than the task calling
    radiolinkInit (namely, the system task), syslink will immediately
    preempt.
    
    Net effect: it tries to stuff a packet into the crtpPacketDelivery queue
    and FreeRTOS asserts.
    
    Here I've ensured that the shared queue is created before the client
    task starts up, and added an assert to catch the (unlikely) case where
    allocating the queue fails.  This makes finding the culprit
    significantly easier, since the alternative is to trigger an assert
    somewhere deep within FreeRTOS.
    
    STM32 reboots with an RF connection active are now robust.
    
    Note that this is a mitigation measure; there may be more bugs like
    this.

[33mcommit 26fc1b6074ba8cf78797bb51fa740f2e188ad1c2[m
Author: Cliff L. Biffle <code@cliffle.com>
Date:   Sat Aug 1 09:55:49 2015 -0700

    log: don't send huge packets.
    
    Before this commit, the log subsystem would blindly follow the
    instructions it received from the client, even if it meant generating a
    packet that was over CRTP_MAX_DATA_SIZE in length.  The errant packet
    would wind up killing off either the radiolink task (before the previous
    commit) or the worker task (as of the previous commit).
    
    Either way, it kills telemetry and turns on the failure lights.  Control
    authority (one-way) is retained.
    
    As of this commit, log packets will be truncated at the last item that
    fits completely into the buffer.  This confuses the Python client's
    plotter implementation, but leaves flight telemetry and control
    authority intact.  As soon as the log configuration is changed to remove
    the excess data, service is restored.
    
    Aside:
    
    This is a classic buffer overrun, and because the packet is
    stack-allocated, it's also a stack smash.
    
    The case where the packet was allowed to escape into radiolink is
    particularly interesting, because it implies that logRunBlock is
    permitted to return using the smashed stack into a corrupt worker task
    loop.  This is likely exploitable.

[33mcommit 392ca8401ad55e53fc7ed792a084affc372d89c1[m
Author: Cliff L. Biffle <code@cliffle.com>
Date:   Sat Aug 1 09:52:16 2015 -0700

    CRTP: defensive asserts in crtpSend*.
    
    These asserts are going to be performed in radiolink, but at that point
    the packet has passed through a queue, making it somewhat difficult to
    identify the source of the corrupt packet.
    
    Here I've replicated the asserts at the crtpSend* functions, which are
    the primary ways that packets enter that queue.  It is now easy to
    identify the origin of corrupt packets by setting a breakpoint at
    'assertFail'.
    
    This does *not* provide fault isolation: an assert in a low-priority
    task may still starve higher-priority tasks because of contention over
    shared resources.  This is a larger problem that stems from the
    firmware's current use of timeouts (portMAX_DELAY) and the
    implementation of the worker task.
    
    But this is a start.

[33mcommit 1796c66ea465f021824c5fcd49021354dc421634[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Fri Jul 31 10:04:56 2015 +0200

    Setting sampling time to minimum for 10-bit conversion

[33mcommit b7154ae924505f2d24cca38ee8f9cd231abb03bb[m
Merge: 9ef96f5 eaad126
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Jul 28 15:16:49 2015 +0200

    Merge branch 'fredgrat-sitaw'

[33mcommit eaad12680295580bc2282145963c73bf8920eede[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Jul 28 15:15:18 2015 +0200

    Made situation awareness framework compile and work for CF1 as well.

[33mcommit 5918990501933cce45be4feb9bd1ada746bb2ff7[m
Merge: 9ef96f5 954ec12
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Jul 28 13:34:06 2015 +0200

    Merge branch 'sitaw' of https://github.com/fredgrat/crazyflie-firmware into fredgrat-sitaw

[33mcommit 954ec127c982fa1d39deca3c27064c57798bea88[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Tue Jul 28 12:43:24 2015 +0200

    Using fabs() function from math.h in sitaw.c

[33mcommit 9ef96f57ae689bf9595b9d02535ff0a1064fd848[m
Merge: e5a57c9 ee5f711
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Jul 28 09:40:37 2015 +0200

    Merge branch 'fredgrat-proximity'

[33mcommit ee5f71116a89e018716311501ee1246ba35a7552[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Jul 28 09:40:06 2015 +0200

    Fixed so that proximity builds for CF1.

[33mcommit beb66a762698043d007129067c47945c2e8b6892[m
Merge: e5a57c9 796c1c7
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Jul 28 09:09:42 2015 +0200

    Merge branch 'proximity' of https://github.com/fredgrat/crazyflie-firmware into fredgrat-proximity

[33mcommit 796c1c7c6282021fd6efa44aadf88d651e452094[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Mon Jul 27 23:14:38 2015 +0200

    Moving MAXSONAR_ENABLED and PROXIMITY_ENABLED from config.h to respective header files

[33mcommit 8cb58c788b562b70bc9a7d32a2fa554b49858d31[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Mon Jul 27 22:54:56 2015 +0200

    Minor comment fix in sitaw.c

[33mcommit 25570a39d6c312cc89d3359536dd2151208f4524[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Mon Jul 27 22:07:40 2015 +0200

    Minor cleanup in stabilizer.c

[33mcommit 1be0db64463194295736c99b892db3a95c5a14e7[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Mon Jul 27 22:07:11 2015 +0200

    Improving documentation in trigger.c

[33mcommit 8e225588f25da7a6285db1028425bb8554baeea7[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Mon Jul 27 21:55:28 2015 +0200

    Improved comments in commanderSetAltHoldMode()

[33mcommit 74919c12fb9afc0f719343a34357ed9b73147361[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Mon Jul 27 21:41:28 2015 +0200

    Minor cleanups and documentation fixes in trigger.[hc]

[33mcommit 7dfeee5dcacbe43c4e7322c11ae9a12a1f7c1cad[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Mon Jul 27 21:38:59 2015 +0200

    Improved sitaw.[hc] API, documentation fixes, added Tumbled detection. Created two CallOut functions in stabilizer.c

[33mcommit e5a57c98326e8e110f3bfd3eb3215e91db7cd403[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Jul 27 15:35:17 2015 +0200

    FPU units is now enabled. Sleep when idle saves 20mA is also enabled.

[33mcommit deba3b5e62819b7c94b89e64c2617e9545e6f4b0[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Sun Jul 26 21:28:55 2015 +0200

    Using 'Free Fall' and 'At Rest' detection with altHold Mode

[33mcommit 52962015f00d1c0efe73bfa7efc5ca8775792ace[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Sun Jul 26 13:25:57 2015 +0200

    Adding situation awareness framework. Currently detects Free Fall and At Rest situations

[33mcommit 24fb4dae91e912ad1421b082340c67f82d32f5da[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Sat Jul 18 21:04:37 2015 +0200

    First patch for Free-Fall detection

[33mcommit 2d91abbf0a329d9b446e64e91a3a4a7ae6ea9f4d[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Fri Jul 24 14:56:19 2015 +0200

    Include cleanups

[33mcommit df601ac880f4b51eb0343cfb389c57d813c3ff91[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Fri Jul 24 14:40:09 2015 +0200

    Tweaking the proximity sampling for the LV-MaxSensor-EZ1 (MB1040)

[33mcommit 90d17f30f1755376dd01ac38cf0ed3fa8c589467[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Fri Jul 24 13:35:52 2015 +0200

    * Adding median calculations to proximity.[hc]
    * Moving driver/module specific configurations to respective .h files for proximity.[hc] and maxsonar.[hc]
    * Only enable log groups when needed for proximity.[hc] and maxsonar.[hc]. Enable by configuration setting in .h file. Disabled by default.

[33mcommit ff839cf817233fecb79336a810f8cb20facf5c35[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Thu Jul 23 21:08:41 2015 +0200

    Renaming MaxBotix driver from mb to maxsonar, with naming convention cleanups

[33mcommit 7ca62e59bc4cdf0648ce5b9e4b7cf61edf90dccd[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Thu Jul 23 20:32:56 2015 +0200

    Moving driver specific configurations into driver header files

[33mcommit 383b5e11e96deeb4ba680fa09815c46c2899fc56[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Jul 23 13:42:52 2015 +0200

    Fixed USB disconnect by using USB suspend callback. Moved callback
    functions in usbd_usr.c to usb.c to have the logic at one place. Closes
    Bug #56.

[33mcommit 8e83be3e1f2b26ee328ba8acb8fba8150605a5b8[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Thu Jul 23 11:50:33 2015 +0200

    Comments on powering of MaxBotix sensor added

[33mcommit e36000df8cefed8f7ba42ed569143eb66d84e340[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Thu Jul 23 01:26:40 2015 +0200

    Removing obsolete include in stabilizer.c

[33mcommit 775383b3413cc15638b198009edc0399208fec9b[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Thu Jul 23 01:24:42 2015 +0200

    Removing obsolete include from mb.c

[33mcommit 1f54276d045c600ee2514a617fb4a9417c7e499d[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Thu Jul 23 01:20:11 2015 +0200

    Minor updates to comments in config.h

[33mcommit 48aaf239204ba3b9f7906a82f9e84053aa7a40dd[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Thu Jul 23 01:11:07 2015 +0200

    Adding API for accessing proximity distance, distance average and distance accuracy. Additionally, some minor cleanups.

[33mcommit 1e7074ee36da18814927f54d6ea2713b51fef6b9[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Thu Jul 23 00:29:10 2015 +0200

    Initial commit for the proximity measurement subsystem. The intention is for this subsystem to provide a common API for
    proximity sensors. The proximity subsystem runs in a separate task, currently running at 10Hz but this is configurable.
    
    Initially the MaxBotix Sonar Range Finder is supported, and the driver is included in mb.[hc].
    
    The proximity subsystem reports distance measurements as well as accuracies of measurements (as reported by drivers).
    The current limitation is that only a single proximity sensor is supported at any given time. Currently, that is the
    MaxBotix driver.
    
    The proximity system includes a simple function for calculating the average of samples in a sliding window. The sliding
    window is configurable for number of samples in window.
    
    Distance measurements are made available to cfclient by both the MaxBotix driver as well as by the proximity subsystem.
    The latter also makes the average distance measurement available to the cfclient.
    
    This commit disables the proximity system by default (at compile time). Enable by uncommenting the following defines
    in config.h: PROXIMITY_ENABLE and MB_ENABLE

[33mcommit 69efb42743bad3c3dc2c76d38633a4b7e861a45a[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Tue Jul 21 11:37:31 2015 +0200

    Initial commit of driver for MaxBotix sonar range finder

[33mcommit fde7786189cd6dd81a9d5a4173455d776313486b[m
Merge: e1d0b3d 02dd0d4
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Jul 22 14:55:06 2015 +0200

    Merge branch 'master' of https://github.com/bitcraze/crazyflie-firmware
    
    Conflicts:
    	scripts/versionTemplate.py

[33mcommit e1d0b3d6b3a22b96f585b3fc8f63473ca7f0b913[m
Merge: 4c839af 38f0114
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Jul 22 14:15:16 2015 +0200

    Merge pull request #57 from fredgrat/deck_analog
    
    Deck analog API

[33mcommit 4c839af7e8e07ea89f04ab82012646e02f29732a[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Jul 22 14:11:13 2015 +0200

    Added make commands to readme.

[33mcommit b3ad3c84fbe9e5d583cc4d99dc28c46ebc74d6eb[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Jul 22 13:30:41 2015 +0200

    Adjusted make clean to clean both cf1 and cf2 files.
    Fixed param.c warning.

[33mcommit 38f01148d4aaf969b6af3b96c79142ef1d533fbd[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Wed Jul 22 00:47:22 2015 +0200

    Minor cleanup in deck_analog.h

[33mcommit 21ffdd99687fd40bdb3de6557995566368a60ffb[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Wed Jul 22 00:35:00 2015 +0200

    510db7f

[33mcommit cbb0bd1457d87e1070d8b262beb86a5ae0426a59[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Tue Jul 21 23:41:48 2015 +0200

    Moving digital_analog.c from ADC1 to ADC2

[33mcommit 19d31e1aecca25268fa884b821e1114bdc1ba6f9[m
Author: Fredrik Gratte <fredrik.gratte@gmail.com>
Date:   Tue Jul 21 11:03:28 2015 +0200

    Adding deck_analog API

[33mcommit 4c23129818975ef01ecbbc10d682a365cf056380[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Jul 21 15:44:17 2015 +0200

    Removed debug printouts from mem read to the console.

[33mcommit e2c673da4a3879b29524782b614030733b20397b[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Mon Jul 20 10:41:44 2015 +0200

    Added pin list to deck digital api

[33mcommit b3d749d07ee0c3c8ea5090a2ddecb29e9613154e[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Tue Jun 2 13:44:13 2015 +0200

    Started digital io api

[33mcommit 2e7f2754db59aab6365abf81bb4f5878fd464685[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Fri Jul 17 16:40:35 2015 +0200

    Added firmware version crtp packet
    
    Incremented protocol version to 2

[33mcommit 06289a4ddb02316b7acc36b91dcf38cc2854cf26[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Jun 22 16:56:16 2015 +0200

    Made brushless setup a bit easier by organising defines. Disabeling
    LED-ring when brushless deck setup is defined as they use the same
    timer.

[33mcommit 7cc5cc81168fe39c8d09e328868070d281d25eec[m
Merge: 6657878 212fa42
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Jun 22 15:11:03 2015 +0200

    Merge branch 'brushless' into bigmerge

[33mcommit 6657878aa6f9ce68f7189603f3a5143909257271[m
Merge: 5b00595 d224759
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Jun 22 15:10:37 2015 +0200

    Merge remote-tracking branch 'origin/crazyflie2' into bigmerge

[33mcommit 5b0059559053aaa0e42bef1ce6d483b2300fb0b2[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Jun 18 17:55:38 2015 +0200

    Added protocol versioning and set version 1
    
     - The source port (port 15, channel 1) now anwswer
       "Bitcraze Crazyflie", this allows to check that the Crazyflie
       is running protocol >= 1
     - A version channel is added to the platform port. Port 0xD channel
       1. The first data byte is the requested version. 0 is protocol.
       the version (an int) is appended and answered

[33mcommit fa21ffa034ad5103b1b19a6d187b81746bde38d9[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Wed Jun 17 15:01:44 2015 +0200

    Param: Implemented set param by name command

[33mcommit 212fa421178e072120bb671a6dae2b6ca45849c7[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Jun 11 14:26:37 2015 +0200

    Initial brushless driver for deck board. Tested and works but needs
    cleanup and configuration possibility.

[33mcommit d22475929652f1c5d760e4912af537a10e5f0822[m
Merge: 6e1290b 7b82012
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri May 29 17:32:18 2015 +0200

    Merge branch 'crazyflie2' of https://github.com/bitcraze/crazyflie-firmware into crazyflie2

[33mcommit 6e1290bea92649cc0b9a4d650f0b0f1c9d90013e[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri May 29 17:31:58 2015 +0200

    Added simple spin loop uart drivers for UART1 and UART2 on deck port. Enable by defining ENABLE_UART1 and ENABLE_UART2.

[33mcommit 65d1e0dc6493868287d03c6568fc447c8294c4f5[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Fri May 15 03:38:38 2015 +0200

    Implemented voltage-compensated thrust

[33mcommit 7b82012944a90ca45a17ebe81c34adc4620dc747[m
Author: Kristoffer Richardsson <kristoffer@bitcraze.io>
Date:   Fri May 1 09:46:17 2015 +0200

    Added gravity light effect to LED ring

[33mcommit e7c4a66d44574d16ce6a63cdbbd3886c2a91fb06[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Apr 20 15:10:17 2015 +0200

    Added blue siren effect for LED-ring deck.

[33mcommit d7e00c150504acae3d25fca73aef292dff57e3b5[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Mar 31 16:26:37 2015 +0200

    Made Makefile a bit cleaner.

[33mcommit dcbedd3d725e1262cf283c6412deaf24ec8b9bae[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Mar 18 11:49:02 2015 +0100

    Updated Makefile with cf1 and cf2 target names.

[33mcommit bc2e081ff9c6ff81882d1380a775568a4ae0b84a[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Mar 6 10:37:01 2015 +0100

    CF1 and CF2 are now both building and flying. Lots of cleaning up to do though.

[33mcommit e7dfd2819f9d0898fb54273244e603631dcf4abc[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Feb 18 09:23:57 2015 +0100

    All common blocks now compiling.

[33mcommit d85fb1424d89ce8b8f7afc997b9d3ddacd86c772[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri Feb 13 14:58:34 2015 +0100

    Merge from master.

[33mcommit d8c3d8f6effc8cd5117648105f3146d0be1f3ee9[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Mar 25 11:31:25 2015 +0100

    Fixed bug that if thrustlock is on (no zero thrust recevied) but a
    thrust greater then MAX_THRUST is recevied this will go though. Also
    changed MIN_THRUST from 10000 to 1000.

[33mcommit a3ecf78d2e0e70e45c8a77f4d3d068b875ab8bf4[m
Merge: 7fea21a 8694d20
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Mar 25 10:25:06 2015 +0100

    Merge pull request #45 from tomfelker/crazyflie2
    
    Fix for spinning out of control when yawing hard

[33mcommit 8694d2080342e6ef437db21778a354f4226c25c7[m
Author: Tom Felker <tomfelker@gmail.com>
Date:   Wed Mar 25 07:10:18 2015 +0100

    Fix pidUpdate() being called 3x more often than necessary in controllerCorrectRatePID().
    
    TRUNCATE_SINT16() was a preprocessor macro that evaluates its input three times in the common case.  Where it was used, the input is a call to pidUpdate() with updateError true, so in addition to the performance impact, there are unintended side effects.  Specifically, the integral would wind up 3x more then intended, and the derivative constant would have no effect at all, other than to potentially break the TRUNCATE_SINT16() logic.  Luckily the three PID loops affected by this did not use the derivative constant.
    
    I've replaced the macro with an inline function, removed an unused version of the macro, and divided the integral and integral windup terms of the three affected PID loops by 3 to compensate.  The resulting behavior should be unchanged.

[33mcommit 7c1fec91b1ee7c8aba28aababf53d30f5b49c6b7[m
Author: Tom Felker <tomfelker@gmail.com>
Date:   Wed Mar 25 06:07:53 2015 +0100

    Fix issue where Crazyflie spins uncontrollably if you bump it so it yaws left while it's hovering.
    
    The problem was, the int16_t yawOutput value computed in controllerCorrectRatePID() will be negated in stabilizerTask().  However if it saturates to -32768, the +32768 can't fit in an int16_t, so it will roll over back to -32768, causing it to spiral out of control. The fix is to not allow that value.
    
    However, there's another issue: TRUNCATE_SINT16() is a macro, and will evaluate its second argument three times, thus calling pidUpdate() three times as often as necessary.  This only affects CPU load, and may require modifying the PID constants to fix, so that will be in a later snapshot.

[33mcommit c0abdf03c148d3394b9da40c32f28468b6f5c600[m
Author: Tom Felker <tomfelker@gmail.com>
Date:   Sun Mar 22 01:09:46 2015 +0100

    Add version.c to .gitignore to avoid accidental commits.

[33mcommit c4a50909b87743174900ceb220d8cb5c59509e83[m
Merge: a5288dc 7fea21a
Author: Tom Felker <tomfelker@gmail.com>
Date:   Sun Mar 22 00:47:50 2015 +0100

    Merge branch 'crazyflie2' of git://github.com/bitcraze/crazyflie-firmware into crazyflie2

[33mcommit 7fea21ad276ce04497a85ca8ef5ecfd49ebdcfd1[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Mar 19 14:45:43 2015 +0100

    Added configblock upgrade functionality from older versions.

[33mcommit a5288dc6bea196adf555982b599d87570886020b[m
Author: Tom Felker <tomfelker@gmail.com>
Date:   Thu Mar 19 06:20:57 2015 +0100

    fix implicit declaration warning

[33mcommit 336e075111990bf11542cabcfa593085aabb3c4a[m
Merge: 055b6c4 19eb4dd
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Mar 18 12:02:38 2015 +0100

    Merge branch 'crazyflie2' of https://github.com/bitcraze/crazyflie-firmware into crazyflie2

[33mcommit 055b6c49e36a3d571faf5748d7a66d9cc2dae5a0[m
Merge: 621ad61 ec6e6fc
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Mar 18 11:55:17 2015 +0100

    Merge branch 'master' into bigmerge
    
    Conflicts:
    	Makefile
    	README.md
    	drivers/src/i2cdev.c
    	drivers/src/nvic.c
    	modules/interface/mem.h
    	modules/src/comm.c
    	modules/src/mem.c

[33mcommit 19eb4dd6bbf18dd1a7f80881603a1fadd2bd9837[m
Merge: 621ad61 ae76ec3
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Mar 18 11:36:06 2015 +0100

    Merge pull request #43 from whoenig/crazyflie2
    
    Add option to set device address.

[33mcommit ae76ec34283e435b08c69a968ba009fc0ab262a6[m
Author: Wolfgang Hoenig <whoenig@usc.edu>
Date:   Mon Mar 9 23:45:24 2015 -0700

    Add option to set device address.
    
    * Update eeprom configurationblock to include 5 additional bytes for the device address
    * communicate the device address to NRF51 via syslink interface (requires updated nrf firmware)
    
    In order to use the updated version of the configurationblock, a newer version of the UI is required.
    Tested with CF2.0, in combination with an updated NRF51 firmware and UI on Ubuntu 14.04.

[33mcommit 621ad615b987aeef7f2fe0f4a6433eb140f99317[m
Merge: d05705c 0c23d05
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Feb 12 08:04:53 2015 +0100

    Merge branch 'crazyflie2' of https://github.com/bitcraze/crazyflie-firmware into crazyflie2

[33mcommit d05705c4a63d2b62225dbf744274e8128217be85[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Feb 12 08:04:30 2015 +0100

    Merged,adapted and tested brushless (PWM) driver from Crazyflie Nano (1.0).

[33mcommit 0c23d0527f0fa7c029f12e05b736daa2fac0d9d3[m
Merge: 275b2f1 df13f85
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Feb 3 13:48:00 2015 +0100

    Merge pull request #28 from dbrgn/dfu-py2
    
    Run dfu-convert.py with Python 2

[33mcommit 275b2f19fec4a5fddab0baefab858aad1dbbce67[m
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Mon Feb 2 12:00:19 2015 +0100

    Syslink-radiolink: Refactor and fix flowcontrol bug
    
    Refactored syslink and radiolink to remove all radio-specific code
    from syslink.c and to apply correctly the flow control to the radio
    data packets (a radio data packet can be sent only if a radio data
    packet is received, this ensure to not fill-up the nrf51 buffers)

[33mcommit 9dfcfc1357e47d6f2ece7d05cf3f96f44945e042[m
Merge: a21fee8 2ba65d4
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Mon Feb 2 12:05:40 2015 +0100

    Merge branch 'nordmoen-rssi' into crazyflie2

[33mcommit 2ba65d491adfef52a5286a2f55f48278a67e633b[m
Author: Jørgen Nordmoen <Jorgen.Nordmoen@ffi.no>
Date:   Mon Feb 2 08:37:14 2015 +0100

    Changed RSSI sample type from uint32_t to uint8_t
    
    Because the RSSI sample is limited to roughly [0, 100] in value using a
    uint8_t saves quite a bit of bandwidth when logging.

[33mcommit 85059168fffba6f6f836eb554e599a1570a252d2[m
Author: Jørgen Nordmoen <Jorgen.Nordmoen@ffi.no>
Date:   Fri Jan 30 15:47:11 2015 +0100

    This commit adds support for logging RSSI samples
    
    After updating the firmware on the radio this commit adds support for
    those messages to the STM32. The only things this commit does is add a
    new constant to match what is sent from the radio and logging of those
    samples.

[33mcommit a21fee8ae81d76131169bdc62e7246b4c0ebad44[m
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Tue Jan 27 09:53:49 2015 +0100

    Lock thrust until one command with thrust=0 is recived
    
    Related to bug #30. Fixes fly-away when the joystick thrust is locked
    to 100% when connecting.

[33mcommit 56250b5ded22a25e8dc46eda95aa85bccd8e53b1[m
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Mon Jan 26 16:03:46 2015 +0100

    Added release checklist

[33mcommit 74ea79ff35c399e811caf11505c3f8cd8e18958c[m
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Mon Jan 26 15:01:39 2015 +0100

    Handling of build from tarball. Fixes #38

[33mcommit 02dd0d49962cf6e04539b91b52fee53327baf039[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Dec 15 14:02:22 2014 +0100

    Fixed version python script not working with tags.

[33mcommit ec6e6fca667fbad457bc38732d5b7b24d8f31037[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Mon Jan 19 10:25:44 2015 +0100

    Added memory module

[33mcommit be811b222b9698acda2c56dd9fd9dcd4da4b2afc[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Mon Jan 19 10:25:05 2015 +0100

    Added memory port for Crazyflie 2.0 compatibility

[33mcommit 525a065e6a72875cd610a83e62ab56111d2dd01c[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Mon Jan 19 10:22:41 2015 +0100

    Added support for new cfloader script

[33mcommit 29624e7f6e3bd955d925fabd8a9bbec38b3fb63c[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Jan 13 15:34:38 2015 +0100

    Added selftest parameter.

[33mcommit cb86e518bdfdf23049fd53916d0ef884fd376a2f[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Jan 7 15:39:04 2015 +0100

    Added green/red boat effect

[33mcommit e5fd62b16862c2e8d2777cc60fdf5bcd6eccd13f[m
Merge: c3eafb2 aa4d1e7
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Jan 7 15:18:38 2015 +0100

    Merge pull request #35 from cstanke/crazyflie2
    
    Add reset and change LED array (closes #34)

[33mcommit c3eafb20b882885a8d2cb7a4866ba3f2c3a3b872[m
Merge: 1ab92e5 99d19c2
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Jan 7 15:17:48 2015 +0100

    Merge pull request #29 from dbrgn/bat_charge_effect
    
    Added battery charge effect for neopixelring

[33mcommit 81af8005c5eaaeaa3d0aec93133e10111aa603b4[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Dec 30 22:18:54 2014 +0100

    Added missing interrupt routine for i2c2. Fixes #27

[33mcommit aa4d1e7cfe92d5c19500f11e10648341333865fd[m
Author: cstanke <github001@cstanke.com>
Date:   Sun Dec 28 17:08:45 2014 -0800

    Reset the LEDs to off after switching from another LED effect to avoid color artifacts. Also includes fix for issue #34.

[33mcommit 99d19c2e7b70361fe76cf510d4358a5e839c2b02[m
Author: Danilo Bargen <mail@dbrgn.ch>
Date:   Sun Dec 21 20:25:45 2014 +0100

    Added battery charge effect for neopixelring

[33mcommit df13f85007966aa43c867aebb7476a02d9ea0a28[m
Author: Danilo Bargen <mail@dbrgn.ch>
Date:   Thu Dec 18 23:54:48 2014 +0100

    Run dfu-convert.py with Python 2

[33mcommit 1bf9fa102e9eafba0f8d6b52eec6ce72601f3d65[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Thu Dec 18 17:06:58 2014 +0100

    Changed default debugger to STLink V2.

[33mcommit 1ab92e55c44b4584cf688b79a249babc3bccce20[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Dec 15 14:02:22 2014 +0100

    Fixed version python script not working with tags.

[33mcommit 3557f852c6c539ad43a3bce332febd0ca57d3770[m
Merge: 957db30 0ed5d42
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Dec 15 13:42:29 2014 +0100

    Merge branch 'crazyflie2' of https://github.com/bitcraze/crazyflie-firmware into crazyflie2

[33mcommit 0ed5d42ad70babc84398ae70c8c0a1604b2c3835[m
Author: Arnaud Taffanel <arnaud@bitcraze.se>
Date:   Thu Dec 11 11:19:06 2014 -0800

    Added Makefile targets to generate and flash DFU file

[33mcommit 957db309c8c3131cbf6fc665fa43ef927133b099[m
Merge: 0e79c17 f589b65
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Dec 11 15:17:46 2014 +0100

    Merge branch 'crazyflie2' of https://github.com/bitcraze/crazyflie-firmware into crazyflie2

[33mcommit 0e79c176ce15221af4adb78d1837e6b4129755b0[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Dec 11 15:14:41 2014 +0100

    Adjusted gyro (98Hz)  and acc (4Hz) LPF to handle unbalanced propellers better.

[33mcommit d3e9526f0125c835edadcf60fa59fd591be0f39e[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Dec 8 15:26:45 2014 +0100

    Added short Crazyflie 2.0 description

[33mcommit f589b65259418ecb53319a1f25479c96bf8aaeb8[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Dec 8 15:21:13 2014 +0100

    Adjusted headline sizes.

[33mcommit 58298fe5df96f5040b7cf87db28bb0bd8e65b9f5[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Dec 8 15:19:06 2014 +0100

    Adjusted headline sizes.

[33mcommit ee4c0ebe8fe360450b767329cf08a720d1dce773[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Dec 8 14:59:58 2014 +0100

    Initial commit of Crazyflie 2.0 code. Lot's of things to be done but the base is there.

[33mcommit 05f2a3b3a726a8fb91ebda0a11528b1869727e7a[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Dec 1 13:33:09 2014 +0100

    Added gitignore and removed old HG files.

[33mcommit 67d628ca5d4f12d0b2a3dcaed43a60d19e967118[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Dec 1 13:20:27 2014 +0100

    Removed startup sound being build by default. Define ACTIVATE_STARTUP_MELODY in config.h to activate it.

[33mcommit 6d7f1648b589e02eca81edf33eaa14824f8535a1[m
Author: Oxydation <mathias.nigsch@gmail.com>
Date:   Fri Aug 1 22:08:38 2014 +0200

    Added sound engine and startup sound melody

[33mcommit 55d057839c2f70a2274b17704c27093f018fbd9c[m
Author: Oxydation <mathias.nigsch@gmail.com>
Date:   Fri Aug 1 22:12:11 2014 +0200

    Added changes from "jodell"-fork to improve maneuverability,
    Added sensitivity control with CH5 knob on ET6I (from dfff180),
    Readjusted max values

[33mcommit ead7f60b5ce139bef8e064672628bab288848597[m
Merge: 7a248a6 7f925c8
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Jun 24 09:14:41 2014 +0200

    Merge pull request #22 from jsgf/master
    
    eskylink: fix cut'n'paste error

[33mcommit 7f925c88b269414bbabbb68aaf427f3b5902cd9c[m
Author: Jeremy Fitzhardinge <jeremy@goop.org>
Date:   Wed Apr 23 12:40:12 2014 -0700

    eskylink: fix cut'n'paste error
    
    It looks like "pitch" was meant to be tested after extracting the pitch,
    rather than "roll" which is uninitialized at that point.

[33mcommit 7a248a661695eb9b912013936492d6c2cff98d8d[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Apr 17 13:42:04 2014 +0200

    Added fast charging capability for wall adapters

[33mcommit 57765521091594570b1984b4d1ce2af132b8921f[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Tue Apr 1 11:10:24 2014 +0200

    Added experimental brushless driver

[33mcommit 1b0262c3fc3ad628b5ad90a2b194e1095cf0738f[m
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Mon Apr 14 15:11:38 2014 +0200

    Added LOG API to read variable from within the coper

[33mcommit 6cef76ca6b297682cf6345869ce7d3f0e5c8553f[m
Author: Arnaud Taffanel <arnaud@taffanel.org>
Date:   Fri Apr 11 14:37:17 2014 +0200

    Fixed version template to work with more than 1 git branch

[33mcommit bbae9a9a585896a8a1c2eeddd3b94247b1cde3bb[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Mar 5 13:52:42 2014 +0100

    Fixed make cload by updating references to crazyflie-clients-python

[33mcommit 4b362e529aca02ea60f177a1442fa4643fccfab9[m
Author: Alexander Holler <holler@ahsoftware.de>
Date:   Wed Nov 27 00:42:37 2013 +0100

    Make the version-scripts git-aware
    
    Some people prefer to use git (easy possible by using git-hg) therefor
    make the version-scripts git-aware.
    
    To not change the view of the version string(s), the version when using
    git still looks the same as if mercury is used (and not like a
    standard git-version).

[33mcommit 2db5cbc00f8c2c91077bc08a16d32acebaf7ee89[m
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Wed Mar 5 13:36:31 2014 +0100

    Fixed I2C2 initialization

[33mcommit cc84d42e91e371390183a26e433829cb97e36170[m
Merge: 367b49d f6e79bf
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Fri Feb 21 15:45:18 2014 +0100

    Merged fixes from 2014.01

[33mcommit f6e79bf4c5f93fcca33eb94df2cfdd8f8f80f1be[m
Author: Arnaud Taffanel <unknown>
Date:   Mon Feb 3 13:21:36 2014 +0100

    Added tag 2014.01.0 for changeset 54fa51cb6ea0

[33mcommit 98a8d83a8855888ce29c0a37483596c931b4b819[m
Author: Arnaud Taffanel <unknown>
Date:   Wed Jan 29 12:36:49 2014 +0100

    log: create_block returns EEXIST if a log block already exists

[33mcommit 72954726c1ed94e4f0a91fbb462fe4c741a1efbd[m
Author: Arnaud Taffanel <unknown>
Date:   Mon Jan 27 15:59:08 2014 +0100

    Added tag 2014.01-rc1 for changeset f826511b6a16

[33mcommit 367b49d423d9bf7cabb180c95b3377e3e32b509b[m
Author: Arnaud Taffanel <unknown>
Date:   Wed Jan 22 16:59:06 2014 +0100

    sensorfusion6: Fixed euler angle calculation asin() crash
    
    Clamping gx in [-1, 1] to prevent asin() from crashing the copter

[33mcommit 7df37cf7d76494e22f0e3e515c49d1df0b905777[m
Author: Arnaud Taffanel <unknown>
Date:   Wed Jan 22 16:36:29 2014 +0100

    sensorfusion6: Fixed roll/pitch/yaw calculation
    
    Follows equation found on http://www.chrobotics.com/library/understanding-quaternions

[33mcommit 35392134728bcf1c55ce2ea44628f650bfdf158c[m
Author: Arnaud Taffanel <unknown>
Date:   Tue Jan 14 13:59:47 2014 +0100

    Stabilizer: Added acceleration vector magnitude log variable
    
    Can be used for stuff like free-fall detection. Value sent is the square of the
    magnitude (sqrt is cheaper on the pc side).

[33mcommit e0402b5054291b5a4ee1a48bf62a944f9f3520e8[m
Merge: 1848415 487ac8a
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Thu Dec 19 08:51:28 2013 +0100

    Merged in krasin/crazyflie-firmware/usecTimestamp3 (pull request #13)
    
    Implement usecTimestamp. Initialize TIM1 at startup for that.

[33mcommit 184841541ba3e6c6974d62799f71c3fc519916fb[m
Author: tobbeanton <unknown>
Date:   Wed Dec 18 16:02:26 2013 +0100

    Added magnetometer to logging. Did some cleanup.

[33mcommit 6e654020a254dd3316eea55af39e2a65b21fc741[m
Author: Alexander Holler <holler@ahsoftware.de>
Date:   Tue Dec 17 12:00:25 2013 +0100

    Add some previously unknown linker sections (e.g. from DWARF 3)
    ---
     scripts/sections_FLASH.ld | 17 ++++++++++++++---
     1 file changed, 14 insertions(+), 3 deletions(-)

[33mcommit b33b7fcb5c80f95555356eea841ad4cdee7feafa[m
Author: Alexander Holler <holler@ahsoftware.de>
Date:   Tue Dec 17 12:00:25 2013 +0100

    Add linker section to get an error for undefined sections
    This helps to identify problems in the linker phase.
    ---
     scripts/sections_FLASH.ld | 5 +++++
     1 file changed, 5 insertions(+)

[33mcommit 5bb4d9b93e523c376000d373f31c4ba1edc03e12[m
Author: Alexander Holler <holler@ahsoftware.de>
Date:   Tue Dec 17 12:00:25 2013 +0100

    Don't link with the standard library
    The standard library isn't needed and using it results in a memory overflow
    (e.g. the linker section bss will become larger than the available RAM).
    
    This fixes a problem with newer versions of gcc/newlibc.
    ---
     Makefile | 2 +-
     1 file changed, 1 insertion(+), 1 deletion(-)

[33mcommit 7b692e2302f7ba2857a34e4611937e4c00dc9bd5[m
Author: Alexander Holler <holler@ahsoftware.de>
Date:   Tue Dec 17 12:00:25 2013 +0100

    Add simple abort() function
    Newer versions of newlibc always use unwind functions which do need an
    implementation of abort(). So in order to link without standard libraries
    (-nostdlib) we have to provide abort().
    ---
     Makefile          |  2 +-
     utils/src/abort.c | 14 ++++++++++++++
     2 files changed, 15 insertions(+), 1 deletion(-)
     create mode 100644 utils/src/abort.c

[33mcommit cd2f3188818b14843b8367a5d0035a9b9758716c[m
Author: Alexander Holler <holler@ahsoftware.de>
Date:   Tue Dec 17 12:00:25 2013 +0100

    Use CFLAGS in LDFLAGS
    This makes the Makefile a bit shorter and less complicated.
    ---
     Makefile | 8 ++------
     1 file changed, 2 insertions(+), 6 deletions(-)

[33mcommit b798aa292cd00ab2d3cc9fdc9b5e708926cf03d6[m
Author: tobbeanton <unknown>
Date:   Mon Oct 28 16:50:41 2013 +0100

    Added tag 2013.11-beta1 for changeset 0a52a3d2d354

[33mcommit d13e6782b992b94cd6e076f34de411f438502013[m
Author: tobbeanton <unknown>
Date:   Mon Oct 28 16:48:54 2013 +0100

    Reverted to blocking radio packets to not loose any console messages. Better solution fot this is needed.

[33mcommit ac93c2d541e505e9b62b764e4bb9c9a7f168fba9[m
Author: tobbeanton <unknown>
Date:   Tue Oct 22 09:58:09 2013 +0200

    Fixed hanging of 6-DOF version due to not having barometer.

[33mcommit 5e312ebac93fe0441732ac7820edea188d241692[m
Merge: 66be6e7 e538f37
Author: tobbeanton <unknown>
Date:   Mon Oct 21 21:13:43 2013 +0200

    Merge

[33mcommit e538f379422e380687811b8baaecce79ac441818[m
Author: tobbeanton <unknown>
Date:   Mon Oct 21 21:11:42 2013 +0200

    Updated Z acceleration function to calculate with all three axis. Fixed log packet time stamp.

[33mcommit 66be6e7455aec1f668840081317e5f3571f8d591[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Mon Oct 21 19:10:34 2013 +0200

    Fixed timestamp. Closes #18.

[33mcommit b1aad6bed2ac7f7207c097b150c71a96bbc2544d[m
Author: tobbeanton <unknown>
Date:   Mon Oct 21 14:41:37 2013 +0200

    Added imu_types.h file.

[33mcommit 0cdbc5c0574e4e48c606073c0e43dc4c3b71ad02[m
Merge: f99dc7e 440634d
Author: tobbeanton <unknown>
Date:   Mon Oct 21 14:41:04 2013 +0200

    Merged hover mode from omwdunkley branch and did initial adaptation.

[33mcommit f99dc7e487dfdc4501f4896504eddecdef566422[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Thu Sep 26 10:05:59 2013 +0200

    Added back PYTHON2 variable

[33mcommit 0e692fe0ea06faa54453ccfb757af6e47e245b64[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Sep 25 20:10:26 2013 +0200

    Changed path for cload bootloading via radio from Makefile

[33mcommit f62ffd2bff4a759fd81b4e25ced73508b4768cba[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Sep 25 16:21:51 2013 +0200

    Added modified flag to parameters

[33mcommit 6bd07fc4445affeba348f7fbfe00ad0d94aa5d13[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Sep 25 15:45:53 2013 +0200

    Fixed typo.

[33mcommit a17b84a8468826ccbfb8b3140878990024847b69[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Wed Sep 25 10:47:26 2013 +0200

    Added logging and parameters to check status. Closes #11.

[33mcommit f2423db618f72840ea1500dd2aaee2ab71baee18[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Thu Sep 19 15:21:32 2013 +0200

    Fixed macros for easy DEBUG_PRINT redirection to UART.

[33mcommit c373a9af2fc31241bfed981e6d04b47c4fe34e0f[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Thu Sep 19 14:30:18 2013 +0200

    Stop logging and flush CRTP queues after 2s of link inactivity. Radiolink-layer queue is now also no-blocking.

[33mcommit 440634d9f7260b8ed2b2f1bd82a6f98f64460514[m
Author: omwdunkley <omwdunkley@gmail.com>
Date:   Tue Sep 10 20:47:33 2013 +0200

    thrust now turns off in hover mode if flie disconnects

[33mcommit e7a108ec7d6663704cfb08f9b55bb0ca268cabde[m
Author: omwdunkley <omwdunkley@gmail.com>
Date:   Thu Aug 29 02:30:52 2013 +0200

    fixed formatting of readme

[33mcommit 78d70e32b621e0acbcc8ab5d1189f9f23499553c[m
Merge: f898f52 3d51f21
Author: omwdunkley <omwdunkley@googlemail.com>
Date:   Thu Aug 29 02:20:52 2013 +0200

    Merged in BarometerChanges (pull request #1)
    
    Hover Mode

[33mcommit 3d51f2119c00085de2551d03a64087a31b3856ec[m
Author: omwdunkley <omwdunkley@gmail.com>
Date:   Thu Aug 29 02:17:06 2013 +0200

    updated readme again

[33mcommit 7e825caeef9fc300e9367e905c3ce6c9c5f661f5[m
Author: omwdunkley <omwdunkley@gmail.com>
Date:   Thu Aug 29 02:12:02 2013 +0200

    updated readme

[33mcommit a5646d6b94172b94ab5fddc049e45b7410c5473c[m
Author: omwdunkley <omwdunkley@gmail.com>
Date:   Thu Aug 29 01:22:44 2013 +0200

    fixed bug where I tried to send a float as a uint_16

[33mcommit c6b1c6d56ce343f7d46f8dba17d300042ff44d2e[m
Author: omwdunkley <omwdunkley@gmail.com>
Date:   Wed Aug 28 03:05:46 2013 +0200

    forgot to subtract gravity from vertical acceleration

[33mcommit 3f4bf50fb3926a336292441b238133486dc41ac2[m
Author: omwdunkley <omwdunkley@gmail.com>
Date:   Wed Aug 28 03:00:01 2013 +0200

    added initial hover support

[33mcommit 487ac8a769848a24c14bb286c0b63b18232c570e[m
Author: Ivan Krasin <imkrasin@gmail.com>
Date:   Sun Aug 4 06:44:24 2013 +0000

    Implement usecTimestamp. Initialize TIM1 at startup for that.

[33mcommit f898f52673fdfab2f2804c8e5d621e01def9557d[m
Merge: 7c848bf 4d21004
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Jul 29 13:37:23 2013 +0200

    Merged in krasin/crazyflie-firmware (pull request #9). Fix url to open x-IMU algorithm

[33mcommit 7c848bf717d32bf2615ca7163e23579795f76c75[m
Merge: 9cbf01f 46528fe
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Mon Jul 29 13:33:28 2013 +0200

    Merged in danmark/crazyflie-firmware/danmark/stabilizerc-edited-online-with-bitbucket-1374051798193 (pull request #8)
    
    Gyro logging

[33mcommit 4d210047e8efe13b94f2b7cdc4401c9cf65ea69f[m
Author: Ivan Krasin <imkrasin@gmail.com>
Date:   Wed Jul 24 23:04:57 2013 +0000

    Fix url to open x-IMU algorithm

[33mcommit 46528fea5e438b84304db050adc477c1c739009d[m
Author: danmark <viktor.fogelberg@gmail.com>
Date:   Wed Jul 17 09:05:50 2013 +0000

    According to pull reqest #5 accelerometer logging should be enabeled.
    I figured gyro logging should be too.
    
    N.B! the code is not tested! my cf is not working at the moment..

[33mcommit 9cbf01ff724d947adc4a6213a47585d95ce97850[m
Author: errantsignal <unknown>
Date:   Tue Jul 2 00:05:01 2013 +0200

    Added support for Link-Time Optimization; compile with LTO=1 to use (do a clean first).

[33mcommit 59504f8bfc95df954f3fd0ff961b5639ff94c87f[m
Merge: df67090 ae1616f
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Sun Jun 9 11:22:44 2013 +0200

    Merged in erget/crazyflie-firmware/accelerometerLogging (pull request #5)
    
    Expose accelerometer values for logging in the PC client

[33mcommit df67090077e9cbadd337b7b2d10505a486881f87[m
Author: Tobias Antonsson <unknown>
Date:   Wed Jun 5 09:05:49 2013 +0200

    Renamed motor defines from front, right... to M1, M2... as it doesn't assume anything about the orientation.
    Adapted code to coding standard.

[33mcommit e3ddb2c0b29d24557d9a571cb2881c79228a3a8a[m
Author: Ivan Krasin <imkrasin@gmail.com>
Date:   Mon Jun 3 06:06:04 2013 +0000

    Do not run M2T on MOTORS_TEST_ON_TIME and MOTORS_TEST_DELAY_TIME_MS twice; add _MS suffix to these constants names; use a const array and a loop instead of 4 copy-paste regions

[33mcommit 20981994c63691ff956f356c6ae6373ecfab33bc[m
Author: Tobias Antonsson <unknown>
Date:   Fri May 24 16:12:19 2013 +0200

    Only some small semantic changes to make it more similar to the other code.

[33mcommit e541be5b185cf7773824734df1891d8a9823f528[m
Merge: bc7ea02 97cebff
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri May 24 16:04:01 2013 +0200

    Merged in sheymann/crazyflie-firmware-1/sheymann/bug-solved-for-negative-numbers-starts-w-1369307451022 (pull request #3)
    
    DEBUG_PRINT() enhancement for float values

[33mcommit 97cebff13561eb97f6fb241222c35828ed8af791[m
Author: Sascha Heymann <sascha.heymann@gmail.com>
Date:   Thu May 23 11:10:01 2013 +0000

    -Bug solved for negative numbers starts with zero e.g. -0.123
    -Bug solved for numbers starts with zero after the dot e.g. 0.00123
    -Add float precision adjustable e.g. %.3f = 0.123

[33mcommit ae1616fd75a15073c28927b460267c6caeb8863b[m
Author: erget <unknown>
Date:   Wed May 22 20:20:59 2013 +0200

    Expose accelerometer values for logging

[33mcommit 74c190877dbfac63c428b604d3b6feaa5e51c7a8[m
Author: erget <unknown>
Date:   Sun May 19 12:54:25 2013 +0200

    Starting 'accelerometerLogging' branch

[33mcommit bc7ea023f0d207c6bfb5771064b5e5fc27bcfda0[m
Merge: 7774cd8 ab7c3c4
Author: Tobias Antonsson <tobias@bitcraze.se>
Date:   Fri May 17 09:13:11 2013 +0200

    Merged in sheymann/crazyflie-firmware-1/sheymann/imuc-wurde-online-mit-bitbucket-gendert-1368759634640 (pull request #1)
    
    imu.c wurde online mit Bitbucket geändert

[33mcommit ab7c3c47b0bbcfe576f27e244e79c62743b0ae76[m
Author: Sascha Heymann <sascha.heymann@gmail.com>
Date:   Fri May 17 02:59:42 2013 +0000

    imu.c wurde online mit Bitbucket geändert

[33mcommit 7774cd835ceecf28dcbb2133112fd88d0aa9370c[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Fri May 10 10:57:21 2013 +0200

    Change default build to DEBUG=0 and CLOAD=1

[33mcommit 09f6edc7cb83f1d5e74d80126353f6e4f9fa0d6a[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Sun Apr 28 02:37:19 2013 +0200

    Added tag 2013.4 for changeset ba1d111112ad

[33mcommit b7903474620abd95236983a2bdf7fcc4af3133ed[m
Author: Arnaud Taffanel <unknown>
Date:   Sun Apr 28 02:23:03 2013 +0200

    Added RO params containing firmware revision hash

[33mcommit e969d5135043352d88d9130b46866f0a7b393e72[m
Author: Tobias Antonsson <unknown>
Date:   Sat Apr 20 21:06:20 2013 +0200

    Fixed bug with yaw not resetting into new position. Caused by that the rate PIDs where not reset.

[33mcommit 4ed7d21d746e6270d1d105accb82054ff2c75a21[m
Author: Tobias Antonsson <unknown>
Date:   Sat Apr 20 20:54:01 2013 +0200

    MPU6050 DLPF at 98Hz was too low which caused instablility in a windy environment. Increased to 188Hz with better result. Also changed range from 1000 to 2000 deg/s to avoid saturation.

[33mcommit f2e93397bca7d2a8db0dfb16a24cb5f479aaed64[m
Author: Tobias Antonsson <unknown>
Date:   Thu Apr 18 15:31:26 2013 +0200

    Tuned mpu6050 DLPF to handle unbalanced propellers better, now 98Hz. Also added parameters for accelerometer imu LPF and sensorfusion ki and kp.

[33mcommit 3a7d1f13e8becc4884d77972fa349b8c36a07785[m
Author: Tobias Antonsson <unknown>
Date:   Wed Apr 3 22:11:30 2013 +0200

    Added tag Production-V2 for changeset 5f65b66e004d

[33mcommit f90e014df7b5634cf492b24b247a370f81da1fb8[m
Author: Tobias Antonsson <unknown>
Date:   Wed Apr 3 22:11:05 2013 +0200

    Increased HMC5883L self test limits. Yet again corrected roll, pitch, yaw order in commander as we now will use new production firmware and wont have any compatibility issues.

[33mcommit 66cef7489688a7cd6e88b6b47335c1991c70b820[m
Author: Tobias Antonsson <unknown>
Date:   Tue Apr 2 21:42:49 2013 +0200

    Reverted roll, pitch, yaw correction as it breaks compatibility with to many clients right now.

[33mcommit 71c163424ce77c644fa3456fb6bbf2244772016d[m
Merge: 5354a23 a811fe3
Author: Tobias Antonsson <unknown>
Date:   Tue Apr 2 20:18:28 2013 +0200

    Fixed UART CRTP layer. Corrected roll, pitch, yaw order in commander and eskylink.

[33mcommit 5354a233d2a0859ea450c160e63edf7f4f4af2d2[m
Author: Arnaud Taffanel <unknown>
Date:   Mon Apr 1 13:34:18 2013 +0200

    Esky: Fixed axis mapping. Starts to fly.

[33mcommit a811fe388c70abd693d4e14e0ee72fea2c064fa6[m
Author: Tobias Antonsson <unknown>
Date:   Mon Apr 1 11:29:28 2013 +0200

    Corrected roll, pitch, yaw order in Commander.

[33mcommit 6299f9ccee0ae5d35462abf7a401280fa8b311d5[m
Author: Arnaud Taffanel <unknown>
Date:   Mon Apr 1 10:24:23 2013 +0200

    Ported and updated UART CRTP link
    
    The uart CRTP link can be activated at build time by adding
    "CFLAGS += -DUSE_UART_CRTP" to config.mk
    
    Not tested but builds and pass the self test.

[33mcommit beb141b08d4a6fba2fe620757d753bb957ca8e38[m
Author: Arnaud Taffanel <unknown>
Date:   Sun Mar 31 15:46:31 2013 +0200

    Moved uart.c in the hal folder.

[33mcommit 07e977f4c7dd83638bc8cdcb02e30c457c01707b[m
Author: tobias <unknown>
Date:   Mon Mar 25 21:33:44 2013 +0100

    Removed tag V1.0

[33mcommit 972ec2229cd899df56b449f0774eb51bb424df4d[m
Author: tobias <unknown>
Date:   Mon Mar 25 21:33:36 2013 +0100

    Added tag Production-V1 for changeset 6f4ae9da82b6

[33mcommit a01ebbfc8077e54169d9351ad100acd8bee66ab4[m
Author: Tobias Antonsson <unknown>
Date:   Sun Mar 24 21:52:07 2013 +0100

    Moved tag V1.0 to changeset 6f4ae9da82b6 (from changeset fbf175d7827b)

[33mcommit 965a3430842d37930675324ac919dfc412d2d361[m
Author: Tobias Antonsson <unknown>
Date:   Sun Mar 24 21:51:29 2013 +0100

    Added radio address to radio initialisation.

[33mcommit 8b28ee120cceff863edc2ef168bb756d6ba7ff3e[m
Author: Tobias Antonsson <unknown>
Date:   Sun Mar 24 21:45:27 2013 +0100

    Added tag V1.0 for changeset fbf175d7827b

[33mcommit cf10c992c5c1493216a1ad415d0962bb1b17cdd8[m
Author: Tobias Antonsson <unknown>
Date:   Sat Mar 23 17:32:29 2013 +0100

    Implemented MS5611 self test to test sane values. Changed gain setting to 440 for self test on HMC5883L.

[33mcommit be82b072784c8cfdb70d29a0fef7724d483cb42d[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Sat Mar 23 16:04:19 2013 +0100

    Added regulation parameters

[33mcommit 6ab2bbe078f5682021112b3ae6d0503a9c2be876[m
Author: Marcus Eliasson <marcus@bitcraze.se>
Date:   Sat Mar 23 14:28:51 2013 +0100

    Added battery/motor/thrust logging

[33mcommit 2534372d5c7e7deb3206b9228eaf2a75a9e86873[m
Author: Tobias Antonsson <unknown>
Date:   Sat Mar 23 12:28:21 2013 +0100

    HMC5883L self test now only runs when comminication is present.

[33mcommit 9dc095b0c427941f2b0ad9be697f915f6bdecc38[m
Author: Tobias Antonsson <unknown>
Date:   Fri Mar 22 17:01:46 2013 +0100

    Refactored MPU6050 self test. Added HMC5883L self test.

[33mcommit 3ab8efce873dc29133ff5829bd84b0c5e3541700[m
Author: Arnaud Taffanel <unknown>
Date:   Tue Mar 19 19:18:55 2013 +0100

    Disabled and removed legacy modules multilog and pidctrl
    
    Multilog is replaced by log
    Pidctrl is replacable by param, should be implemented before deleting the files.
    Disabling these tasks should save almost 1K of heap ram...

[33mcommit 60d617ad01437b4133b473c46424bfacf5d0f6cf[m
Author: Arnaud Taffanel <unknown>
Date:   Sun Mar 17 21:15:12 2013 +0100

    Makefile: Makes UART disable by default and switch to heap_4.c malloc

[33mcommit f46267ab25d172b84e790712c23d5374b5c6aeb2[m
Author: Arnaud Taffanel <unknown>
Date:   Sun Mar 17 21:08:50 2013 +0100

    Cleanup and fixed log block handling
    
    This mainly corects a bug that did not free correctly log block when the reset
    function is called.

[33mcommit 24a55bd15a0aaf950ac34ecfd66a2d5fadf0b552[m
Author: Arnaud Taffanel <unknown>
Date:   Sat Mar 16 23:33:27 2013 +0100

    Fixed crash related to Log when out of memory
    
    When the copter got out of memory and a log-block was created it hanged. This
    patch fixes it by checking if the timer object created for each log block has
    been successfully created.
    
    Also added a mutex that ensure that a log block is not modified/deleted
    while it is used.

[33mcommit 695956442e0278ac82de76d397e21a3b7ec07f0a[m
Author: Arnaud Taffanel <unknown>
Date:   Sat Mar 16 23:28:10 2013 +0100

    Some change to make Eclipse happy(er), openocd rtos conf and added .hgignore

[33mcommit fb36423eace9abebca5f63f2388da01d1f710129[m
Author: Arnaud Taffanel <unknown>
Date:   Sun Mar 3 21:06:21 2013 +0100

    Updated FreeRTOS to V7.4.0

[33mcommit d6c5a673d6b6843f2effcf2386698f058ffa6c29[m
Author: Arnaud Taffanel <unknown>
Date:   Fri Feb 8 01:12:53 2013 +0100

    Early implementation of the Esky receiver link driver
    
    Axis are not well mapped but the pairing and channel hopping works.
    Define make variable USE_ESKYLINK=1 to compile with esky radio support.

[33mcommit 988b498605bb6c0772dcc861400ef6f7d30a0287[m
Author: Arnaud Taffanel <unknown>
Date:   Sun Feb 3 14:57:55 2013 +0100

    Makes versionTemplate.py python3 compatible

[33mcommit 680b7c4507e3636fdf679e7e34cf6b97071794bc[m
Author: Arnaud Taffanel <unknown>
Date:   Fri Feb 1 01:57:21 2013 +0100

    Fixed compile bug on Linux: set executable flag to scripts/print_revision.sh

[33mcommit 02a2b6d48800334ed455144d9061226418fab7b7[m
Author: Tobias Antonsson <unknown>
Date:   Thu Jan 31 23:08:14 2013 +0100

    Move from private repository
