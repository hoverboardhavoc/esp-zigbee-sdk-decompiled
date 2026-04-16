/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> log.o -> write_nchar
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void write_nchar(char *buf,char c,uint16_t count)

{
  undefined2 in_register_00002032;
  uint uVar1;
  
  uVar1 = CONCAT22(in_register_00002032,count);
  while (uVar1 != 0) {
    *buf = c;
    buf = buf + 1;
    uVar1 = uVar1 - 1 & 0xffff;
  }
  return;
}

