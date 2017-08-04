#!/bin/sh
socat TCP-LISTEN:10006,reuseaddr,fork EXEC:./bof_6&
