#!/bin/sh
socat TCP-LISTEN:10001,reuseaddr,fork EXEC:./bof_1&
