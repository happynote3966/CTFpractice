#!/bin/sh
socat TCP-LISTEN:10005,reuseaddr,fork EXEC:./bof_5&
