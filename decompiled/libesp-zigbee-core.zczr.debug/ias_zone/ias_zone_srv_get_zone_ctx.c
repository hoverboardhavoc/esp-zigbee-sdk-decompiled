/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_srv_get_zone_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ias_zone_srv_get_zone_ctx(void)

{
  int iVar1;
  
  iVar1 = ias_zone_srv_get_attr_desc(0xeff0);
  if (iVar1 != 0) {
    return *(undefined4 *)(iVar1 + 8);
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x68,
                "ias_zone_srv_get_zone_ctx","attr_desc");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

