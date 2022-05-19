/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-baptiste.barbotin
** File description:
** response_code
*/

#ifndef RESPONSE_CODE_H_
    #define RESPONSE_CODE_H_

    #include <string.h>

    #define CODE_120 "120 Service ready in nnn minutes.\t\n\0"

    #define CODE_125 "125 Data connection already open; \
transfer starting.\t\n\0"

    #define CODE_150 "150 File status okay; about to open data \
connection.\t\n\0"

    #define CODE_200 "200 Command okay.\t\n\0"

    #define CODE_214 "214 Help message. Explains how to use the server or \
the meaning of a particular non-standard command. This reply is useful only \
to the human user.\t\n\0"

    #define CODE_220 "220 Service ready for new user.\t\n\0"

    #define CODE_221 "221 Service closing control connection.\t\n\0"

    #define CODE_226 "226 Closing data connection. Requested file action \
successful (for example, file transfer or file abort).\t\n\0"

    #define CODE_227 "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).\t\n\0"

    #define CODE_230 "230 User logged in, proceed.\t\n\0"

    #define CODE_250 "250 Requested file action okay, completed.\t\n\0"

    #define CODE_257_1 "257 \"\0"

    #define CODE_257_2 "\" created.\t\n\0"

    #define CODE_331 "331 User name okay, need password.\t\n\0"

    #define CODE_332 "332 Need account for login.\t\n\0"

    #define CODE_430 "430 Invalid username or password\t\n\0"

    #define CODE_501 "501 Syntax error in parameters or arguments.\t\n\0"

    #define CODE_502 "502 Command not implemented.\t\n\0"

    #define CODE_530 "530 Not logged in.\t\n\0"

    #define CODE_550 "550 Requested action not taken. File unavailable \
(e.g., file not found, no access).\t\n\0"

#endif /* !RESPONSE_CODE_H_ */
