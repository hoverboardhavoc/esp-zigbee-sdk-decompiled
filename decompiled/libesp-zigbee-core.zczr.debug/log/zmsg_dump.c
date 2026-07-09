/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> log.o -> zmsg_dump
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_dump(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 auStack_20 [4];
  undefined4 uStack_1c;
  short sStack_18;
  undefined2 uStack_12;
  
  uVar1 = zmsg_get_length(param_3);
  uStack_12 = (undefined2)uVar1;
  log_write(param_1,param_2,"zmsg@%p len:%d",param_3,uVar1);
  zmsg_get_first_chunk(param_3,0,&uStack_12,auStack_20);
  while (sStack_18 != 0) {
    log_hexdump(param_1,param_2,"chunk",uStack_1c);
    zmsg_get_next_chunk(&uStack_12,auStack_20);
  }
  return;
}

