#!/bin/bash
# use testnet settings,  if you need mainnet,  use ~/.btcturquoisecore/btcturquoised.pid file instead
btcturquoise_pid=$(<~/.btcturquoisecore/testnet3/btcturquoised.pid)
sudo gdb -batch -ex "source debug.gdb" btcturquoised ${btcturquoise_pid}
