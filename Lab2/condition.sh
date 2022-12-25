#! /bin/bash
pass=abc123
read -sp "Enter your password:" inp
echo
    if [  $pass == $inp ]
        then
                 echo welcome
        else
                 echo incorrect password
    fi
