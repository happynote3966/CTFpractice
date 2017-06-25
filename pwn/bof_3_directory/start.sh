#!/bin/sh
socat TCP-LISTEN:10003,reuseaddr,fork EXEC:./bof_3&
