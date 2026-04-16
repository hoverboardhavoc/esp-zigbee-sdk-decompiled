/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> log.o -> log_hexdump
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: line */
/* WARNING: Unknown calling convention */

void log_hexdump(log_level_t level,char *tag,char *title,void *buf,uint32_t size)

{
  uint uVar1;
  char acStack_6c [4];
  char line [73];
  
  hexdump_get_startline(acStack_6c,0x48,title,(uint16_t)size);
  log_write(level,tag,"%s");
  for (uVar1 = 0; uVar1 < size; uVar1 = uVar1 & 0xffff) {
    uVar1 = hexdump_get_next_dataline(acStack_6c,0x48,(uint8_t *)buf,(uint16_t)size,(uint16_t)uVar1)
    ;
    log_write(level,tag,"%s");
  }
  hexdump_get_endline(acStack_6c,0x48);
  log_write(level,tag,"%s");
  return;
}

