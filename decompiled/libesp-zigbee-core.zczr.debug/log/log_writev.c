/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> log.o -> log_writev
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void log_writev(log_level_t level,char *tag,char *format,va_list args)

{
  int iVar1;
  char acStack_a0 [4];
  char log_string [128];
  
  memset(acStack_a0,0,0x80);
  iVar1 = snprintf(acStack_a0,0x80,"[%s] ");
  vsnprintf(acStack_a0 + iVar1,0x80 - iVar1,format,args);
  log_string[0x7b] = '\0';
  ezb_plat_log(level,&_LC3,acStack_a0);
  return;
}

