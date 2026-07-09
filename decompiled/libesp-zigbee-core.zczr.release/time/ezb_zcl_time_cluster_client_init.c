/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> time.o -> ezb_zcl_time_cluster_client_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_time_cluster_client_init(void)

{
  int iVar1;
  undefined1 auStack_24 [32];
  
  memcpy(auStack_24,&_LANCHOR0,0x14);
  iVar1 = zcl_cluster_template_add(auStack_24);
  if (iVar1 != 0) {
    __assert_func(0,0,0,0);
  }
  return;
}

