/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> log.o -> log_hexdump
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void log_hexdump(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined1 auStack_6c [76];
  
  hexdump_get_startline(auStack_6c,0x48,param_4 & 0xffff);
  log_write(param_1,param_2,&_LC3,auStack_6c);
  for (uVar1 = 0; uVar1 < param_4; uVar1 = uVar1 & 0xffff) {
    uVar1 = hexdump_get_next_dataline(auStack_6c,0x48,param_3,param_4 & 0xffff,uVar1);
    log_write(param_1,param_2,&_LC3,auStack_6c);
  }
  hexdump_get_endline(auStack_6c,0x48);
  log_write(param_1,param_2,&_LC3,auStack_6c);
  return;
}

