#!/bin/sh
socat TCP-LISTEN:10002,reuseaddr,fork EXEC:./bof_2&
