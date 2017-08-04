#!/bin/sh
socat TCP-LISTEN:10004,reuseaddr,fork EXEC:./bof_4&
